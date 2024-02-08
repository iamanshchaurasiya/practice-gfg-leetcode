//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// Sollution by Ansh Raj
// email: theanshchaurasiya@gmail.com


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        unordered_map<int, int> freq;
        int pairsCount = 0;
        
        // Store the frequency of each element in the array
        for (int i = 0; i < n; i++) {
            freq[arr[i]]++;
        }
        
        // Iterate through the array to find pairs
        for (int i = 0; i < n; i++) {
            int complement = k - arr[i];
            // Check if the complement exists in the map
            if (freq.find(complement) != freq.end()) {
                // Increment the count by the frequency of the complement
                pairsCount += freq[complement];
            }
            // If the element is the complement itself, decrement the count
            if (complement == arr[i]) {
                pairsCount--;
            }
        }
        
        // Each pair is counted twice, so divide by 2 to get the actual count
        return pairsCount / 2;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}
// } Driver Code Ends

// Sollution by Ansh Raj
// email: theanshchaurasiya@gmail.com
