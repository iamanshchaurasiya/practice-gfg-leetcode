//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// Sollution by Ansh Raj
// email: theanshchaurasiya@gmail.com


// } Driver Code Ends
class Solution{
    public:
    // Function to merge two sorted arrays and count inversions.
    long long merge(long long arr[], long long temp[], long long left, long long mid, long long right) {
        long long inv_count = 0;
        long long i = left; // Index for left subarray
        long long j = mid; // Index for right subarray
        long long k = left; // Index for merged array
        
        while ((i <= mid - 1) && (j <= right)) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                inv_count += (mid - i);
            }
        }
        
        while (i <= mid - 1)
            temp[k++] = arr[i++];
        
        while (j <= right)
            temp[k++] = arr[j++];
        
        for (i = left; i <= right; i++)
            arr[i] = temp[i];
        
        return inv_count;
    }

    // Function to merge sort and count inversions.
    long long mergeSort(long long arr[], long long temp[], long long left, long long right) {
        long long inv_count = 0;
        if (right > left) {
            long long mid = (left + right) / 2;
            inv_count += mergeSort(arr, temp, left, mid);
            inv_count += mergeSort(arr, temp, mid + 1, right);
            inv_count += merge(arr, temp, left, mid + 1, right);
        }
        return inv_count;
    }

    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        long long temp[N];
        return mergeSort(arr, temp, 0, N - 1);
    }
};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends


// Sollution by Ansh Raj
// email: theanshchaurasiya@gmail.com

