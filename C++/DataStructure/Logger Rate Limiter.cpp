/*
Design a logger system that receive stream of messages along with its timestamps, each message should be printed if and only if it is not printed in the last 10 seconds.

Given a message and a timestamp (in seconds granularity), return true if the message should be printed in the given timestamp, otherwise returns false.

It is possible that several messages arrive roughly at the same time.
*/

class Logger {
    unordered_map<string,int>MessageDictionary;
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if ( this->MessageDictionary.count(message) == 0)
        {
            this->MessageDictionary.insert(make_pair(message,timestamp));
            return true;
        }
        int MonitorOldTimeStamp = this->MessageDictionary[message];
        if ( timestamp - MonitorOldTimeStamp >= 10 )
        {
            this->MessageDictionary[message] = timestamp;
            return true;
        }
        else
            return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
