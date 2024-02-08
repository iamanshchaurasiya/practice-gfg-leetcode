//{ Driver Code Starts
#include<iostream>

using namespace std;


// Sollution by Ansh Raj
// email: theanshchaurasiya@gmail.com

// } Driver Code Ends
//User function template for C++
class Solution{
public:
    long long maxProduct(vector<int> arr, int n) {
        // Initialize variables to store max product ending at current index
        long long maxEndingHere = arr[0];
        long long minEndingHere = arr[0];
        long long maxProductSoFar = arr[0];

        for (int i = 1; i < n; i++) {
            // If the current element is negative, swap maxEndingHere and minEndingHere
            if (arr[i] < 0)
                swap(maxEndingHere, minEndingHere);

            // Update maxEndingHere and minEndingHere for the current index
            maxEndingHere = max((long long)arr[i], maxEndingHere * arr[i]);
            minEndingHere = min((long long)arr[i], minEndingHere * arr[i]);

            // Update maxProductSoFar if maxEndingHere is greater
            if (maxEndingHere > maxProductSoFar)
                maxProductSoFar = maxEndingHere;
        }
        return maxProductSoFar;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends