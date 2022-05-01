// C++ implementation to find the
// longest subarray consisting of
// only two values with difference K
#include <bits/stdc++.h>
using namespace std;
 
// Function to return the length
// of the longest sub-array
int longestSubarray(int arr[], int n,
                int k)
{
    int i, j, Max = 1;
 
    // Initialize set
    set<int> s;
 
 for (i = 0; i < n - 1; i++) {
        // Store 1st element of
        // sub-array into set
     s.insert(arr[i]); 
    for (j = i + 1; j < n; j++) {
            // Check absolute difference
            // between two elements
         if (abs(arr[i] - arr[j]) == 0
                || abs(arr[i] - arr[j]) == k) {
 
                // If the new element is not
                // present in the set
                if (!s.count(arr[j])) {
 
                    // If the set contains
                    // two elements
                    if (s.size() == 2)
                        break;
 
                    // Otherwise
                    else
                        s.insert(arr[j]);
                }
            }
            else
                break;
        }
 
        if (s.size() == 2) {
 
            // Update the maximum
            // length
            Max = max(Max, j - i);
 
            // Remove the set
            // elements
            s.clear();
        }
        else
            s.clear();
    }
 
    return Max;
}
 
// Driver Code
int main()
{
    int arr[] = { 0,1,2,1,3,5};
 
    int N = sizeof(arr)
            / sizeof(arr[0]);
    int K = 1;
 
    int length = longestSubarray(
        arr, N, K);
 
    if (length == 1)
        cout << -1;
    else
        cout << length;
 
    return 0;
}
