/*Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. 
In other words, one of the first string's permutations is the substring of the second string.
Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").
*/

//Approach-1: TLE
bool check_equal_character(int *array_1,int *array_2);

bool checkInclusion(char * s1, char * s2)
{
    
    if(strlen(s1) > strlen(s2))
        return false;
    int frequency_character_s1[26] = {0};
    for(int i=0;i<strlen(s1);i++)
    {
        frequency_character_s1[s1[i] - 'a']++;
    }
    for(int i=0;i<=strlen(s2)-strlen(s1);i++)
    {
        int frequency_character_s2[26] = {0};
        for(int j=0;j<strlen(s1);j++)
        {
            frequency_character_s2[s2[i+j]-'a']++;
            
        }
        if (check_equal_character(&frequency_character_s1,&frequency_character_s2))
            return true;
        
    }
    return false;

}
bool check_equal_character(int *array_1,int *array_2)
{
    for(int i=0;i<26;i++)
    {
        if(array_1[i] != array_2[i])
            return false;
    }
    return true;
}

//Approach-2:
bool check_equal_character(int *array_1,int *array_2);

bool checkInclusion(char * s1, char * s2)
{
    
    if(strlen(s1) > strlen(s2))
        return false;
    int frequency_character_s1[26] = {0};
    int frequency_character_s2[26] = {0};
    for(int i=0;i<strlen(s1);i++)
    {
        frequency_character_s1[s1[i] - 'a']++;
        frequency_character_s2[s2[i]-'a']++;
    }
    for(int i=0;i<strlen(s2)-strlen(s1);i++)
    {
         if (check_equal_character(&frequency_character_s1,&frequency_character_s2))
            return true;
        frequency_character_s2[s2[i+strlen(s1)]-'a']++;
        frequency_character_s2[s2[i]-'a']--;
        
    }
    return check_equal_character(&frequency_character_s1,&frequency_character_s2);

}
bool check_equal_character(int *array_1,int *array_2)
{
    for(int i=0;i<26;i++)
    {
        if(array_1[i] != array_2[i])
            return false;
    }
    return true;
}

