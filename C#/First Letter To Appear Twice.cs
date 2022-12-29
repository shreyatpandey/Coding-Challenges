// This problem differs from first unique character
// Taking an array would not be useful here

public class Solution {
    public char RepeatedCharacter(string s) {
        Dictionary<char,int>freqChar = new Dictionary<char,int>();
        char temp = 'a';
        foreach(var Char in s)
        {
            if (freqChar.ContainsKey(Char))
            {
                temp = Char;
                return temp;
            }
            freqChar.Add(Char,1);
        }
        return temp;
    }
}
