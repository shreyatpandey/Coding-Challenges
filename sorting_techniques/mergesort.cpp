#include<bits/stdc++.h>
using namespace std;

void merge(int arr[],int low,int mid,int high)
{
   int n1,n2;
   n1 = mid - low + 1;
   cout<<"Value of n1:"<<n1<<endl;
   n2 = high - mid;
   cout<<"Value of n2:"<<n2<<endl;
   int i=0; int j=0;
   int *L1 = new int[n1];
   int *L2 = new int[n2];
   for(i=0;i<n1;i++)
{  
    L1[i] = arr[low+i];
    cout<<"L1 is continuing:"<<L1[i]<<endl;
  }
   for(j=0;j<n2;j++)
{
   L2[j] = arr[mid+j+1];
   cout<<"L2 is continuing:"<<L2[j]<<endl;
  }
   
   i=0; j=0; int k=low;
   while(i<n1 && j<n2)
   {
     if(L1[i]<= L2[j])
    {
       arr[k] = L1[i];
       k++;
       i++;
    }
    if(L2[j]<= L1[i])
    {
       arr[k] = L2[j];
       k++;
       j++;
    }
   }
  while(i<n1)
   {
     arr[k] = L1[i];
     k++;
     i++;
   }
  while(j<n2)
  {
    arr[k] = L2[j];
    k++; j++;
  }
delete(L1);
delete(L2);
}
void mergesort(int arr[],int low,int high)
{
  if(low<high)
  {
    int mid = (low+high)/2;
    cout<<"Mid value of array is:"<<arr[mid]<<endl;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);
   }

}





int main()
{
   int arr[] = {5,1,-2,10,-8,100,-10000,90,10};
   int size = sizeof(arr)/sizeof(arr[0]);
   mergesort(arr,0,size-1);
   cout<<"Sorted array is"<<endl;
   for(int i=0;i<size;i++)
    {cout<<arr[i]<<" ";
     }
   cout<<endl;


return 0;
}
