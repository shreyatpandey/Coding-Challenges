/*
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
*/


void reverse_words(char *input_string,int start_index,int final_index)
{
    char temp;
    while(start_index < final_index)
    {
        temp = input_string[start_index];
        input_string[start_index] = input_string[final_index];
        input_string[final_index] = temp;
        start_index += 1;
        final_index -= 1;
    }
}



char * reverseWords(char * s)
{
    int length_index = 0;
    int i =0;
    while(s[i] != '\0')
    {
        if(s[i] == ' ')
        {
            reverse_words(s,length_index,i-1);
            length_index = i + 1;
        }
        i++;
            
    }
    reverse_words(s,length_index,i-1);
    
    return s;

}

