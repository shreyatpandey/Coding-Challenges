class Solution {
    private:
        int expand_around_center(string s, int left,int right)
        {
            int left_most = left;
            int right_most =  right;
            while(left_most>=0 && right_most<s.length() && s.at(left_most) == s.at(right_most) )
            {
                left_most --;
                right_most ++;
            }
            cout<<"left_most:"<<left_most<<endl;
            cout<<"right_most:"<<right_most<<endl;
            return right_most - left_most - 1;
        }
public:
    string longestPalindrome(string s) {
        if (s.empty() ||  (s.length() == 0))
            return "";
        if (s.length() < 2)
            return s;
       
        int start_position = 0; 
        int end_position = 0;
        for(size_t i=0;i<s.length();i++)
        {
             cout<<"substring_1:"<<s.substr(i,i)<<endl; //behavior of this is absurd, for (0,0) it is empty and (1,1) only one character and for (2,2) it is ba 
            int length_1 = expand_around_center(s,i,i);
            cout<<"substring_2:"<<s.substr(i,i+1)<<endl;
            int length_2 = expand_around_center(s,i,i+1);
            int length_max = max(length_1,length_2); //we want max palindromic substring
            if(length_max >= end_position)
            {
                start_position = i - (length_max - 1)/2;
                end_position =  length_max;
            }
        }
        cout<<"substring:"<<s.substr(start_position,end_position)<<endl;
        return s.substr(start_position,end_position);
    } 
    
};
