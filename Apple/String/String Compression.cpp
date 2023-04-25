// Run Length Encoding

class Solution {
public:
    int compress(vector<char>& chars) {
        int index = 0;
        for(int i=0;i<chars.size();i++)
        {
            char temp = chars[i];
            int j = i+1;
            int count = 1;
            while(j < chars.size() && chars[j] == temp)
            {
                count += 1;
                j ++;
            }
            chars[index++] = temp;
            if (count >1)
            {
                if(count>9)
                {   
                    string result = to_string(count);
                    for(int i=0;i<result.size();i++)
                    {
                        chars[index++] = result[i];
                    }
                }
                else
                {
                    chars[index++] = count + (int)'0';
                }
            }
            i = j - 1;
        }
        return index;
    }
};
