/*
Given an array of n elements containing elements from 0 to n-1, with any of these numbers appearing any number of times, 
find these repeating numbers in O(n) and using only constant memory space.
*/
//Here you have to return the elements which have appeared more than 2 
//Important thing to note is that the elements of an array range from 0 to N-1, this is the key to think in terms of arr[arr[i]] , tricks based on this
//Return the vector of repeating elements
//Source of Studey:- GeekforGeeks
vector<int>DuplicateElements(vector<int>&Input)
{
 vector<int>Result;
 int Size = Input.size();
 for(int i = 0;i<Size ; i++)
  {
    int Index = Input[i]%Size;
    Input[Index] += Size;
  }
  /* condition is to check which value occurs more than once*/
  for(int i=0;i<Size;i++)
  {
    if ( (Input[i]/n ) >= 2)
    {
      Result.emplace_back(Input[i]);
    }
  }
  return Result;
  
}
