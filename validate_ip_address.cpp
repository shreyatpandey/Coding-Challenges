class Solution {
public:
    string validIPAddress(string IP) {
      size_t pos1 = IP.find('.');
        size_t pos2 = IP.find(':');
        if(pos1 == string::npos && pos2 == string::npos) return "Neither";
        if(pos1 != string::npos && pos2 != string::npos) return "Neither";
        if(pos1 != string::npos) {
            if(IP.back() == '.') return "Neither"; else IP.append(1, '.');
            string ip; size_t pos = 0;
            for(int i=1; i<=4; i++) {
                pos1 = IP.find('.', pos);
                if(pos1 == string::npos) return "Neither";
                ip = IP.substr(pos, pos1-pos);
                if(ip.empty() || (ip.size()>1 && ip[0]=='0') || ip.size()>3) return "Neither";
                for(auto c : ip) {if(!isdigit(c)) return "Neither";}
                if(stoi(ip)>255) return "Neither";
                pos = pos1 + 1;
            }
            if(pos != IP.size()) return "Neither";
            return "IPv4";
        }
        if(pos2 != string::npos) {
            if(IP.back() == ':') return "Neither"; else IP.append(1, ':');
            string ip; size_t pos = 0;
            for(int i=1; i<=8; i++) {
                pos1 = IP.find(':', pos);
                if(pos1 == string::npos) return "Neither";
                ip = IP.substr(pos, pos1-pos);
                if(ip.empty() || ip.size()>4) return "Neither";
                for(auto c : ip) {
                    if( !(isdigit(c) || ((c-'a')>=0 && (c-'a')<=5) || ((c-'A')>=0 && (c-'A')<=5)) ) 
                        return "Neither";
                }
                pos = pos1 + 1;
            }
            if(pos != IP.size()) 
                return "Neither";
            return "IPv6";
        }
        return "Neither";
    }
     
};
