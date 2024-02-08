//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// Sollution by Ansh Raj
// email: theanshchaurasiya@gmail.com

// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        // Initialize variables
        int start = 0, end = 0;
        int minLength = INT_MAX;
        int sum = 0;
        
        // Iterate through the array
        while (end < n) {
            // Include elements in the current subarray until sum >= x
            while (sum <= x && end < n) {
                sum += arr[end++];
            }
            
            // Update minLength if the current subarray is smaller
            while (sum > x && start < n) {
                minLength = min(minLength, end - start);
                sum -= arr[start++];
            }
        }
        
        // If minLength is still INT_MAX, no subarray found
        if (minLength == INT_MAX)
            return 0;
        
        return minLength;
    }
};


//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends


// Sollution by Ansh Raj
// email: theanshchaurasiya@gmail.com
