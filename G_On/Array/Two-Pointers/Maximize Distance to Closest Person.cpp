/*You are given an array representing a row of seats where seats[i] = 1 represents a person sitting in the ith seat, and seats[i] = 0 represents that the ith seat is empty (0-indexed).

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 

Return that maximum distance to the closest person.
*/
class Solution {
    private:
        int GetDistance(int Start,int End);
        int Size ;
public:
    int maxDistToClosest(vector<int>& seats) {
        int MaxDistance = 0;
        int StartIndex = 0;
        int PersonSeated = -1;
        Size = seats.size();
        for(int i =0;i<seats.size();i++)
        {
            if(seats[i] == 1)
            {
                MaxDistance = max(MaxDistance,GetDistance(PersonSeated,i));
                PersonSeated = i;                     
            }
        }
        MaxDistance = max(MaxDistance,GetDistance(PersonSeated,Size));
        
        /* Brute Force will not work
        for(int i=0;i<seats.size();i++)
        {
            if ( seats[i] == 1)
            {
                int Index = i;
                int j = Index;
                while(seats[Index] != 1)
                {
                    Max 
                }
            }
        }
        */
        
        return MaxDistance;
    }
};
int Solution::GetDistance(int Start,int End)
{
    if ( Start == -1 || End == Size)
    {
        return End - Start - 1;
    }
    else
    {
        return (End - Start)/2; //assuming the values does not contain INT_MAX
    }
    
}
