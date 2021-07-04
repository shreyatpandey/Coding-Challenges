// Give an array of n elements which contains elements from 0 to n-1, with any of these numbers appearing any number of times
// Find these repeating numbers in O(n) and using only constant memory space
/*Source = GeekForGeeks */
/*
traverse the list for i = 0 to n-1 elements {
    check for sign of A[abs(A[i])];
    if positive then
        make it negative by A[abs(A[i])] = -A[abs(A[i])];
    else
        this element(ith element of list) is a repetition
}
Arr = {1,2,3,1,3,6,6};
{1,-2,3,1,3,6,6}
{1,-2,-3,1,3,6,6}
{1,-2,-3,-1,3,6,6}
-2 is a repetition
*/
int findDuplicate(vector<int> arr) {
    int size = arr.size();
    for(int i = 0; i < size; i++) {
        if(arr[abs(arr[i])] >= 0) {
            arr[abs(arr[i])] = -arr[abs(arr[i])];
        } else {
            return abs(arr[i]);
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {1,2,3,1,3,6,6};
    cout << findDuplicate(arr) << endl;
}
