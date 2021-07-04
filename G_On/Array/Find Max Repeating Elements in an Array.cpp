//Input = [1, 2, 2, 2, 0, 2, 0, 2, 3, 8, 0, 9, 2, 3]
//Output:- 2
//Input = {4, 1, 7, 2, 7, 5, 9, 8, 6, 1, 7, 2, 4, 7}
//Output:- 7
int MaxRepeatingElements(vector<int>&Input)
{
 int Size = Input.size();
 int MaxCount = 0;
 int MaxNumber = 0;
 for(int i=0;i<Size;i++)
 {
  int Index = Input[i]%Size;
   Input[Index] = Input[Index] + Size;
 }
 for (int i = 0; i <Size ; i++) 
 {
         if(Input[i]/Size>MaxCount)
            {
                MaxCount = Input[i]/Size;
                MaxNumber = i;
            }
    }
 return MaxCount ; //quesiton can be twisted to return MaxIndex or MaxCount 
  
}
