#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int firstUniqueCharacter(char *Input)
{
    int frequencyMap[26] = {0};
    int strlength = strlen(Input);
    int i;
    for(i=0;i<strlength;i++)
    {
        frequencyMap[Input[i]-'a']++;
    }
    for(i=0;i<strlength;i++)
    {
        if(frequencyMap[Input[i]-'a'] == 1)
            return i;
    }
    return -1;
}
int main()
{
    char Input[256] = "aabbcdd";
    printf("%c\n",Input[firstUniqueCharacter(Input)]);
    char Input1[256] = "aabbcc";
    printf("%d\n",firstUniqueCharacter(Input1));
    return 0;
}
