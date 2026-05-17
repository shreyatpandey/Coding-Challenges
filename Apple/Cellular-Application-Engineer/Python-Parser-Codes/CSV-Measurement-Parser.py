"""
CSV Measurement Parser for Cellular RF Testing
Parses CSV files containing LTE/5G measurement data with validation and analysis.
"""

import csv
from typing import List, Dict, Tuple, Optional
from dataclasses import dataclass
from datetime import datetime


@dataclass
class MeasurementRecord:
    """Represents a single measurement record from CSV."""
    timestamp: str
    device_id: str
    rsrp_dbm: float
    rsrq_db: float
    sinr_db: float
    cqi: int
    band: int
    frequency_mhz: float
    throughput_mbps: Optional[float] = None
    retransmissions: int = 0
    
    def __str__(self):
        return f"Device: {self.device_id}, RSRP: {self.rsrp_dbm} dBm, SINR: {self.sinr_db} dB"


class CSVMeasurementParser:
    """
    Parser for cellular measurement CSV files.
    
    Expected CSV format:
    Timestamp, Device_ID, RSRP_dBm, RSRQ_dB, SINR_dB, CQI, Band, Frequency_MHz, Throughput_Mbps, Retransmissions
    
    Example:
        2024-05-06 10:30:45, DEV_001, -95, -10, 20, 10, 7, 2145.0, 45.5, 0
        2024-05-06 10:30:46, DEV_001, -92, -8, 22, 11, 7, 2145.0, 48.2, 0
    """
    
    # Measurement thresholds for LTE
    RSRP_RANGES = {
        'excellent': (-85, 0),
        'good': (-95, -85),
        'acceptable': (-105, -95),
        'poor': (-120, -105),
        'critical': (-140, -120)
    }
    
    RSRQ_RANGES = {
        'excellent': (-3, 0),
        'good': (-6, -3),
        'acceptable': (-10, -6),
        'poor': (-19.5, -10)
    }
    
    SINR_RANGES = {
        'excellent': (20, 30),
        'good': (10, 20),
        'acceptable': (0, 10),
        'poor': (-20, 0)
    }
    
    def __init__(self, csv_filepath: str):
        """
        Initialize parser with CSV file path.
        
        Args:
            csv_filepath (str): Path to CSV file
        """
        self.filepath = csv_filepath
        self.measurements: List[MeasurementRecord] = []
        self.errors: List[Tuple[int, str]] = []  # (line_number, error_message)
    
    def parse(self) -> List[MeasurementRecord]:
        """
        Parse CSV file and return list of MeasurementRecord objects.
        
        Returns:
            List[MeasurementRecord]: Successfully parsed measurements
        
        Raises:
            FileNotFoundError: If CSV file doesn't exist
            ValueError: If CSV format is invalid
        """
        self.measurements = []
        self.errors = []
        
        try:
            with open(self.filepath, 'r') as csvfile:
                reader = csv.DictReader(csvfile)
                
                if reader.fieldnames is None:
                    raise ValueError("CSV file is empty or invalid")
                
                for line_num, row in enumerate(reader, start=2):  # Start at 2 (header is line 1)
                    try:
                        record = self._parse_row(row)
                        self.measurements.append(record)
                    except ValueError as e:
                        self.errors.append((line_num, str(e)))
            
            if not self.measurements and self.errors:
                print(f"Warning: No valid records parsed. Errors found on lines: {[err[0] for err in self.errors]}")
            
            return self.measurements
        
        except FileNotFoundError:
            raise FileNotFoundError(f"CSV file not found: {self.filepath}")
    
    def _parse_row(self, row: Dict[str, str]) -> MeasurementRecord:
        """
        Parse a single CSV row and return MeasurementRecord.
        
        Args:
            row (Dict): CSV row as dictionary
        
        Returns:
            MeasurementRecord: Parsed measurement
        
        Raises:
            ValueError: If row data is invalid
        """
        try:
            # Extract and validate each field
            timestamp = row.get('Timestamp', '').strip()
            device_id = row.get('Device_ID', '').strip()
            
            # Parse numeric fields with error handling
            rsrp_dbm = self._parse_float(row.get('RSRP_dBm'), 'RSRP')
            rsrq_db = self._parse_float(row.get('RSRQ_dB'), 'RSRQ')
            sinr_db = self._parse_float(row.get('SINR_dB'), 'SINR')
            cqi = self._parse_int(row.get('CQI'), 'CQI')
            band = self._parse_int(row.get('Band'), 'Band')
            frequency_mhz = self._parse_float(row.get('Frequency_MHz'), 'Frequency')
            throughput_mbps = self._parse_float(row.get('Throughput_Mbps', None), 'Throughput', optional=True)
            retransmissions = self._parse_int(row.get('Retransmissions', '0'), 'Retransmissions', optional=True)
            
            # Validation
            if not timestamp:
                raise ValueError("Timestamp is missing")
            if not device_id:
                raise ValueError("Device_ID is missing")
            if not (-140 <= rsrp_dbm <= -44):
                raise ValueError(f"RSRP {rsrp_dbm} dBm outside valid range (-140 to -44)")
            if not (-19.5 <= rsrq_db <= -3):
                raise ValueError(f"RSRQ {rsrq_db} dB outside valid range (-19.5 to -3)")
            if cqi < 0 or cqi > 15:
                raise ValueError(f"CQI {cqi} outside valid range (0-15)")
            
            return MeasurementRecord(
                timestamp=timestamp,
                device_id=device_id,
                rsrp_dbm=rsrp_dbm,
                rsrq_db=rsrq_db,
                sinr_db=sinr_db,
                cqi=cqi,
                band=band,
                frequency_mhz=frequency_mhz,
                throughput_mbps=throughput_mbps,
                retransmissions=retransmissions
            )
        
        except ValueError as e:
            raise ValueError(f"Invalid data: {str(e)}")
    
    def _parse_float(self, value: Optional[str], field_name: str, optional: bool = False) -> Optional[float]:
        """Parse string to float with error handling."""
        if value is None or value.strip() == '':
            if optional:
                return None
            raise ValueError(f"{field_name} is missing")
        
        try:
            return float(value.strip())
        except ValueError:
            raise ValueError(f"{field_name} is not a valid number: {value}")
    
    def _parse_int(self, value: Optional[str], field_name: str, optional: bool = False) -> Optional[int]:
        """Parse string to int with error handling."""
        if value is None or value.strip() == '':
            if optional:
                return 0
            raise ValueError(f"{field_name} is missing")
        
        try:
            return int(value.strip())
        except ValueError:
            raise ValueError(f"{field_name} is not a valid integer: {value}")
    
    def filter_by_device(self, device_id: str) -> List[MeasurementRecord]:
        """
        Filter measurements by device ID.
        
        Args:
            device_id (str): Device ID to filter
        
        Returns:
            List[MeasurementRecord]: Filtered measurements
        """
        return [m for m in self.measurements if m.device_id == device_id]
    
    def filter_by_signal_quality(self, quality: str) -> List[MeasurementRecord]:
        """
        Filter measurements by signal quality category.
        
        Args:
            quality (str): One of 'excellent', 'good', 'acceptable', 'poor', 'critical'
        
        Returns:
            List[MeasurementRecord]: Measurements matching quality level
        """
        if quality not in self.RSRP_RANGES:
            raise ValueError(f"Invalid quality: {quality}")
        
        min_rsrp, max_rsrp = self.RSRP_RANGES[quality]
        return [m for m in self.measurements if min_rsrp <= m.rsrp_dbm <= max_rsrp]
    
    def get_measurement_statistics(self) -> Dict:
        """
        Calculate statistics for all measurements.
        
        Returns:
            Dict: Statistics including min, max, average values
        """
        if not self.measurements:
            return {'error': 'No measurements to analyze'}
        
        rsrp_values = [m.rsrp_dbm for m in self.measurements]
        rsrq_values = [m.rsrq_db for m in self.measurements]
        sinr_values = [m.sinr_db for m in self.measurements]
        throughput_values = [m.throughput_mbps for m in self.measurements if m.throughput_mbps]
        
        return {
            'total_records': len(self.measurements),
            'rsrp': {
                'min': min(rsrp_values),
                'max': max(rsrp_values),
                'avg': sum(rsrp_values) / len(rsrp_values)
            },
            'rsrq': {
                'min': min(rsrq_values),
                'max': max(rsrq_values),
                'avg': sum(rsrq_values) / len(rsrq_values)
            },
            'sinr': {
                'min': min(sinr_values),
                'max': max(sinr_values),
                'avg': sum(sinr_values) / len(sinr_values)
            },
            'throughput': {
                'min': min(throughput_values) if throughput_values else 0,
                'max': max(throughput_values) if throughput_values else 0,
                'avg': sum(throughput_values) / len(throughput_values) if throughput_values else 0
            }
        }
    
    def get_signal_quality_distribution(self) -> Dict[str, int]:
        """
        Get distribution of signal quality across all measurements.
        
        Returns:
            Dict: Count of measurements in each quality category
        """
        distribution = {quality: 0 for quality in self.RSRP_RANGES.keys()}
        
        for measurement in self.measurements:
            for quality, (min_rsrp, max_rsrp) in self.RSRP_RANGES.items():
                if min_rsrp <= measurement.rsrp_dbm <= max_rsrp:
                    distribution[quality] += 1
                    break
        
        return distribution
    
    def find_poor_measurements(self, rsrp_threshold: float = -105, sinr_threshold: float = 0) -> List[MeasurementRecord]:
        """
        Find measurements below specified thresholds (poor signal quality).
        
        Args:
            rsrp_threshold (float): RSRP threshold in dBm
            sinr_threshold (float): SINR threshold in dB
        
        Returns:
            List[MeasurementRecord]: Measurements below thresholds
        """
        return [m for m in self.measurements 
                if m.rsrp_dbm < rsrp_threshold or m.sinr_db < sinr_threshold]
    
    def get_handover_candidates(self, device_id: str) -> List[MeasurementRecord]:
        """
        Find measurements where handover might be needed (poor RSRP).
        
        Args:
            device_id (str): Device to analyze
        
        Returns:
            List[MeasurementRecord]: Measurements with poor signal requiring handover
        """
        device_measurements = self.filter_by_device(device_id)
        # Handover typically triggered when RSRP drops below -120 dBm
        return [m for m in device_measurements if m.rsrp_dbm < -120]
    
    def generate_report(self, output_file: Optional[str] = None) -> str:
        """
        Generate a comprehensive measurement report.
        
        Args:
            output_file (str, optional): File to write report to
        
        Returns:
            str: Report content
        """
        report = []
        report.append("=" * 80)
        report.append("CELLULAR MEASUREMENT ANALYSIS REPORT")
        report.append("=" * 80)
        report.append(f"\nFile: {self.filepath}")
        report.append(f"Parse Timestamp: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}")
        report.append(f"Total Records Parsed: {len(self.measurements)}")
        report.append(f"Parsing Errors: {len(self.errors)}")
        
        # Statistics
        stats = self.get_measurement_statistics()
        if 'error' not in stats:
            report.append("\n--- SIGNAL STRENGTH STATISTICS ---")
            report.append(f"RSRP: Min={stats['rsrp']['min']:.1f} dBm, Max={stats['rsrp']['max']:.1f} dBm, Avg={stats['rsrp']['avg']:.1f} dBm")
            report.append(f"RSRQ: Min={stats['rsrq']['min']:.1f} dB, Max={stats['rsrq']['max']:.1f} dB, Avg={stats['rsrq']['avg']:.1f} dB")
            report.append(f"SINR: Min={stats['sinr']['min']:.1f} dB, Max={stats['sinr']['max']:.1f} dB, Avg={stats['sinr']['avg']:.1f} dB")
            report.append(f"Throughput: Min={stats['throughput']['min']:.2f} Mbps, Max={stats['throughput']['max']:.2f} Mbps, Avg={stats['throughput']['avg']:.2f} Mbps")
        
        # Signal quality distribution
        distribution = self.get_signal_quality_distribution()
        report.append("\n--- SIGNAL QUALITY DISTRIBUTION ---")
        for quality, count in distribution.items():
            percentage = (count / len(self.measurements)) * 100 if self.measurements else 0
            report.append(f"{quality.capitalize()}: {count} ({percentage:.1f}%)")
        
        # Poor measurements
        poor = self.find_poor_measurements()
        report.append(f"\n--- POOR SIGNAL CONDITIONS ---")
        report.append(f"Measurements below -105 dBm RSRP or 0 dB SINR: {len(poor)}")
        
        # Errors
        if self.errors:
            report.append("\n--- PARSING ERRORS ---")
            for line_num, error in self.errors[:10]:  # Show first 10 errors
                report.append(f"Line {line_num}: {error}")
            if len(self.errors) > 10:
                report.append(f"... and {len(self.errors) - 10} more errors")
        
        report.append("\n" + "=" * 80)
        
        report_text = "\n".join(report)
        
        # Write to file if specified
        if output_file:
            with open(output_file, 'w') as f:
                f.write(report_text)
            print(f"Report written to: {output_file}")
        
        return report_text


# Example usage
if __name__ == "__main__":
    # Create sample CSV file for testing
    sample_csv = "/Users/shreyat108/Desktop/Coding-Challenges/Apple/Cellular-Application-Engineer/Python-Parser-Codes/sample_measurements.csv"
    
    # Create sample data
    sample_data = """Timestamp,Device_ID,RSRP_dBm,RSRQ_dB,SINR_dB,CQI,Band,Frequency_MHz,Throughput_Mbps,Retransmissions
2024-05-06 10:30:45,DEV_001,-95,-10,20,10,7,2145.0,45.5,0
2024-05-06 10:30:46,DEV_001,-92,-8,22,11,7,2145.0,48.2,0
2024-05-06 10:30:47,DEV_001,-98,-12,15,8,7,2145.0,38.1,1
2024-05-06 10:30:48,DEV_001,-105,-15,10,6,7,2145.0,28.5,2
2024-05-06 10:30:49,DEV_002,-85,-5,25,13,3,1805.0,85.3,0
2024-05-06 10:30:50,DEV_002,-88,-7,23,12,3,1805.0,78.9,0
2024-05-06 10:30:51,DEV_002,-110,-18,5,3,3,1805.0,12.4,5
2024-05-06 10:30:52,DEV_003,-75,-3,28,14,7,2145.0,95.6,0
2024-05-06 10:30:53,DEV_003,-120,-20,0,2,7,2145.0,5.2,8"""
    
    # Write sample CSV
    with open(sample_csv, 'w') as f:
        f.write(sample_data)
    
    print("Sample CSV created at:", sample_csv)
    print("\n" + "=" * 80)
    print("PARSING SAMPLE CSV FILE")
    print("=" * 80 + "\n")
    
    # Parse the CSV
    parser = CSVMeasurementParser(sample_csv)
    measurements = parser.parse()
    
    print(f"Successfully parsed {len(measurements)} measurements\n")
    
    # Display first few records
    print("--- FIRST 3 RECORDS ---")
    for i, m in enumerate(measurements[:3], 1):
        print(f"{i}. {m}")
    
    # Filter by device
    print(f"\n--- MEASUREMENTS FOR DEV_001 ---")
    dev001 = parser.filter_by_device("DEV_001")
    print(f"Found {len(dev001)} records for DEV_001")
    
    # Signal quality distribution
    print(f"\n--- SIGNAL QUALITY DISTRIBUTION ---")
    distribution = parser.get_signal_quality_distribution()
    for quality, count in distribution.items():
        print(f"{quality.capitalize()}: {count}")
    
    # Statistics
    print(f"\n--- MEASUREMENT STATISTICS ---")
    stats = parser.get_measurement_statistics()
    print(f"Total Records: {stats['total_records']}")
    print(f"RSRP: Avg={stats['rsrp']['avg']:.1f} dBm (Min: {stats['rsrp']['min']:.1f}, Max: {stats['rsrp']['max']:.1f})")
    print(f"SINR: Avg={stats['sinr']['avg']:.1f} dB (Min: {stats['sinr']['min']:.1f}, Max: {stats['sinr']['max']:.1f})")
    print(f"Throughput: Avg={stats['throughput']['avg']:.2f} Mbps")
    
    # Find poor measurements
    print(f"\n--- POOR SIGNAL CONDITIONS ---")
    poor = parser.find_poor_measurements()
    print(f"Measurements with RSRP < -105 dBm or SINR < 0 dB: {len(poor)}")
    for m in poor:
        print(f"  - {m.device_id}: RSRP={m.rsrp_dbm} dBm, SINR={m.sinr_db} dB")
    
    # Generate report
    print(f"\n--- GENERATING REPORT ---")
    report_file = "/Users/shreyat108/Desktop/Coding-Challenges/Apple/Cellular-Application-Engineer/Python-Parser-Codes/measurement_report.txt"
    report = parser.generate_report(report_file)
    print(report)
