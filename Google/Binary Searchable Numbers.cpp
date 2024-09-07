/*
There is nothing Binary Search in this
*/
int findGuaranteedBinSearch (vector<int>& nums) {
    int n = nums.size();

    // Propagate larger elements to right
    vector<int> larger = nums;
    for (int i = 1; i < n; ++i) {
        if (larger[i] < larger[i-1]) {
            larger[i] = larger[i-1];
        }
    }

    // Propagate smaller elements to left
    vector<int> smaller = nums;
    for (int i = n-2; i >= 0; --i) {
        if (smaller[i] > smaller[i+1]) {
            smaller[i] = smaller[i+1];
        }
    }

    // Check number of elements which are in correct position.
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (larger[i] == smaller[i]) {
            ++count;
        }
    }

    return count;
}


int main() {
    vector<int> nums = {1, 3, 2, 5, 8, 7};
    cout << findGuaranteedBinSearch (nums)<<endl;
    nums = {2, 1, 3, 5, 4, 6};
    cout<<findGuaranteedBinSearch (nums) <<endl;
    nums = {1, 3, 2};
    cout<<findGuaranteedBinSearch (nums) <<endl;
    nums = {3,2,1};
    cout<<findGuaranteedBinSearch (nums) <<endl;

    return 0;
}
 

