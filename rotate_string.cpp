class Solution {
public:
    bool rotateString(string A, string B) {
        if (A.length() == 0 && B.length() == 0)
            return true;
        int length_one = A.length();
        if(length_one == B.length() && length_one>0)
        {
            string concatenate = A + A;
            if ( concatenate.find(B) != string::npos)
            {
                return true;
            }
        }
        return false;
        
    }
};
