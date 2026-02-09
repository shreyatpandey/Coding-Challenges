#!/usr/bin/env python3
import argparse
import subprocess
import time
import os
import sys
import re
import signal

def run_responder(interface, ssid, channel, hw_mode):
    """
    Configures and starts a hostapd instance with FTM responder enabled.
    """
    conf_file = "ftm_responder.conf"
    
    # Basic hostapd configuration with ftm_responder=1
    config = f"""
interface={interface}
driver=nl80211
ssid={ssid}
hw_mode={hw_mode}
channel={channel}
ieee80211n=1
ieee80211ac=1
wmm_enabled=1
# Critical parameter for RTT/FTM
ftm_responder=1
# Optional: Location Configuration Information (LCI) can be added here
"""

    print(f"[*] Generating hostapd config: {conf_file}")
    with open(conf_file, "w") as f:
        f.write(config)

    print(f"[*] Starting FTM Responder on {interface} (SSID: {ssid}, Ch: {channel})...")
    print("[*] Press Ctrl+C to stop.")

    try:
        # Run hostapd and pipe output to stdout
        process = subprocess.Popen(
            ["hostapd", conf_file], 
            stdout=sys.stdout,
            stderr=sys.stderr
        )
        process.wait()
    except KeyboardInterrupt:
        print("\n[*] Stopping responder...")
        process.send_signal(signal.SIGINT)
        process.wait()
    except FileNotFoundError:
        print("[!] Error: 'hostapd' command not found. Please install hostapd.")
    finally:
        if os.path.exists(conf_file):
            os.remove(conf_file)

def run_initiator(interface, target_mac, frequency, bw):
    """
    Sends an FTM Range Request using the 'iw' command.
    """
    req_file = "ftm_request.conf"
    
    # Prepare the request configuration for 'iw'
    # Format: <BSSID> bw=<bandwidth> cf=<center_freq> [asap] [bursts_exp=<val>]
    # 5180 MHz = Channel 36
    config_line = f"{target_mac} bw={bw} cf={frequency} asap"
    
    with open(req_file, "w") as f:
        f.write(config_line)

    cmd = ["iw", "dev", interface, "measurement", "ftm_request", req_file]
    
    print(f"[*] Sending FTM Request to {target_mac} on {interface} (Freq: {frequency})...")
    print(f"[*] Command: {' '.join(cmd)}")
    
    try:
        result = subprocess.run(cmd, capture_output=True, text=True)
        
        if result.returncode != 0:
            print("[!] FTM Request Failed.")
            print(f"Error Output:\n{result.stderr}")
            return

        print("\n[+] Raw Output:")
        print(result.stdout)
        
        # Parse output for distance
        print("[*] Parsed Results:")
        parse_results(result.stdout)

    except FileNotFoundError:
        print("[!] Error: 'iw' command not found. Please install iw.")
    finally:
        if os.path.exists(req_file):
            os.remove(req_file)

def parse_results(output):
    """
    Simple parser for iw FTM output.
    Example line: Target: 00:00:00:00:00:00, status: 0, rtt: 1000 psec, distance: 15 cm
    """
    found = False
    for line in output.split('\n'):
        if "distance" in line:
            found = True
            # Regex to pull out rtt (psec) and distance (cm)
            rtt_match = re.search(r'rtt:\s*(\d+)\s*psec', line)
            dist_match = re.search(r'distance:\s*(-?\d+)\s*cm', line)
            
            rtt = rtt_match.group(1) if rtt_match else "N/A"
            dist = dist_match.group(1) if dist_match else "N/A"
            
            print(f"    -> RTT: {rtt} ps | Distance: {dist} cm")
            
    if not found:
        print("    -> No distance measurements found in output.")

def main():
    parser = argparse.ArgumentParser(description="Wi-Fi 802.11mc (RTT) Testing Script")
    subparsers = parser.add_subparsers(dest="mode", required=True, help="Mode of operation")

    # Responder Mode Arguments
    p_resp = subparsers.add_parser("responder", help="Act as the RTT Access Point (Responder)")
    p_resp.add_argument("-i", "--interface", required=True, help="Wireless interface (e.g., wlan0)")
    p_resp.add_argument("-s", "--ssid", default="Ask_Me_For_RTT", help="SSID for the AP")
    p_resp.add_argument("-c", "--channel", default=36, type=int, help="Channel (default: 36)")
    p_resp.add_argument("--hw_mode", default="a", help="Hardware mode (a/g/n, default: a)")

    # Initiator Mode Arguments
    p_init = subparsers.add_parser("initiator", help="Act as the RTT Station (Initiator)")
    p_init.add_argument("-i", "--interface", required=True, help="Wireless interface (e.g., wlan0)")
    p_init.add_argument("-t", "--target", required=True, help="Target Responder MAC Address (BSSID)")
    p_init.add_argument("-f", "--freq", default=5180, type=int, help="Center frequency in MHz (default: 5180 for Ch36)")
    p_init.add_argument("-b", "--bw", default=20, type=int, help="Bandwidth in MHz (default: 20)")

    args = parser.parse_args()

    # Root check is usually required for iw/hostapd
    if os.geteuid() != 0:
        print("[!] Warning: This script typically requires root/sudo privileges.")

    if args.mode == "responder":
        run_responder(args.interface, args.ssid, args.channel, args.hw_mode)
    elif args.mode == "initiator":
        run_initiator(args.interface, args.target, args.freq, args.bw)

if __name__ == "__main__":
    main()
