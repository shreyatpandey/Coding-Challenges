int length_string(char *input)
{
    int length_count = 0;
    while(input[length_count] != '\0')
    {
        length_count += 1;
    }
    return length_count;
}


int strStr(char * haystack, char * needle)
{
    int lenh = length_string(haystack), lenn = length_string(needle);
        if(lenn == 0) 
            return 0;
        int *next = malloc(lenn * sizeof(int *));
        getNext(needle,next);
        printf("final next: %d\n",next);
        for(int i=0;i<lenn;i++)
        {
            printf("Value : %d\n",next[i]);
        }
        int i = 0, j = 0, index = -1;
        while(i<lenh && j<lenn) /* O(m+n) */
        {
            if(j==-1||haystack[i]==needle[j])
            {
                i++;
                j++;
                if(j == lenn) 
                {
                    index = i-lenn; /*since we have to return index, i - length_of_needle*/
                    break;
                }
            
            }
            else if( haystack[i] != needle[j] )
            {
                //printf("next[j]: %d\n",next[j]);
                j = next[j];
                //printf("j : %d\n",j);
                //printf("next[j] main condition: %d\n", next[j]);
            }
        
        }
        return index;

}
    
    void getNext(char *p,int *next)
    {
        int len = length_string(p);
        int i = 0, k = -1;
        next[0] = -1; // why do we assign next[0] as -1 
        //printf("p[k] in getNext: %s\n",p[k]);
        while(i < len-1 )
        {
            printf("Each character char *p[i]: %c\n",p[i]);
            if(k==-1||p[k]==p[i])
            {
                k++;
                i++;
                //printf("k and i: %d , %d\n",k,i);
                next[i] = k;
                
                //printf("char *p[k] : %c\n",p[k]);
                //printf("next[i]: %d\n",next[i]);
            }
            else
            {
                //printf("next[k]: %d\n",next[k]);
                k = next[k];
               // printf("next[k]: %d\n",next[k]);
            }
        
        }
        
    }



