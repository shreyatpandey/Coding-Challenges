public class Solution {
    public int FirstUniqChar(string s) {
        int[]freqChar = new int[26];

        for(int i=0;i<s.Length;i++)
        {
            freqChar[s[i]-'a']++;
        }
        for(int i=0;i<s.Length;i++)
        {
            if(freqChar[s[i]-'a'] == 1)
            {
                return i;
            }
        }
        return -1;

    }
}
