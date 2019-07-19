Class Solution
{
public:
int shortestsubstring(string s)
{
    set<char>occurence;
    for(int i=0;i<s.length();i++)
    {
        occurence.insert(s[i]);
    }
    int distinct_character_length = occurence.size();
    map<char,int>count_character;
    int string_character_count = 0;
    int helper = 0;
    int shortest_length = INT_MAX;
    for(int j=0;j<s.length();j++)
    {
        count_character[s[j]]++;
        if(count_character[s[j]] == 1)
        {
            string_character_count += 1;
        }
        if(string_character_count == distinct_character_length)
        {
            while(count_character[s[helper]]>1)
            {
                if(count_character[s[helper]] > 1)
                    count_character[s[helper]]--;
                helper += 1;
            }
            int window_size = j - helper + 1; 
            if (shortest_length > window_size) 
            { 
                shortest_length = window_size;
            } 
           
    }
}
    return shortest_length;
    
}
};
