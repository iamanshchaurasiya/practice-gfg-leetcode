//{ Driver Code Starts
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// Sollution by Ansh Raj
// email: theanshchaurasiya@gmail.com


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        // Sort the array
        sort(A, A + n);
        
        // Fix the first element as A[i]
        for (int i = 0; i < n - 2; i++) {
            // Initialize two pointers, one at element after A[i] and
            // another at the last element
            int left = i + 1, right = n - 1;
            
            // Move pointers toward each other to find the pair
            // whose sum is equal to X - A[i]
            while (left < right) {
                int sum = A[i] + A[left] + A[right];
                if (sum == X) {
                    // Triplet found
                    return true;
                } else if (sum < X) {
                    // Move left pointer to increase the sum
                    left++;
                } else {
                    // Move right pointer to decrease the sum
                    right--;
                }
            }
        }
        // No triplet found
        return false;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}


// Sollution by Ansh Raj
// email: theanshchaurasiya@gmail.com

// } Driver Code Ends