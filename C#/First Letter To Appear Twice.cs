// This question is extension of First Unique Character

// Solution - 1
// Slower
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

// Solution -2
// Much faster
public class Solution {
    public char RepeatedCharacter(string s) {
        int[] freqChar = new int[26];
        foreach(var Char in s)
        {
            if(freqChar[Char - 'a'] == 1)
            {
                return Char;
            }
            else
            {
                freqChar[Char - 'a']++;
            }
        }
        return 'a';
    }
}
