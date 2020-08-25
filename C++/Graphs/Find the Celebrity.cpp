/* The knows API is defined for you.
      bool knows(int a, int b); */
//Approach - 1
//TC: O(n) where n is number of persons
//SC: O(1)
class Solution {
    private:
        int i_NumberOfPeople ;
        int i_NumberOfCelebrity ;
        bool b_isCelebrity(int i) ;
public:
    int findCelebrity(int n) {
        i_NumberOfPeople = n ;
        for(int i = 0;i<n;i++)
        {
            if ( knows(i_NumberOfCelebrity,i) )
            {
                i_NumberOfCelebrity = i;
            }
        }
        if ( b_isCelebrity(i_NumberOfCelebrity) )
        {
            return i_NumberOfCelebrity ;
        }
        
        return -1;
    }
};

bool Solution :: b_isCelebrity ( int i)
{
    for ( int j=0;j<i_NumberOfPeople ; j++)
    {
        if ( i == j )
            continue;
        if ( knows(i,j) == true || knows(j,i) == false )
        {
            return false;
        }
    }
    return true;
    
}
