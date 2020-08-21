class Solution {
        private:
            int numberofintervals = 0;

    public:
    int leastInterval(vector<char>& tasks, int n) 
    {
       vector<int>frequencycharacter(26,0);
        for(auto x:tasks)
        {
            frequencycharacter[x-'A']++;
        }
        sort(frequencycharacter.begin(),frequencycharacter.end());
        while (frequencycharacter[25] > 0) 
        {
            int i = 0;
            while (i <= n) 
            {
                if (frequencycharacter[25] == 0)
                    break;
                if (i < 26 && frequencycharacter[25 - i] > 0)
                {

                    frequencycharacter[25 - i]--;
                }
                numberofintervals++;
                i++;
            }
            sort(frequencycharacter.begin(),frequencycharacter.end());
        }
        return numberofintervals;
        
    }
};
