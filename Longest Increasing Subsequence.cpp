//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
   
    int longestSubsequence(int n, int a[])
    {
     
       vector<int>dp(n+2,INT_MAX);
       dp[0]=INT_MIN;
       for(int i=0;i<n;i++){
           int idx=upper_bound(dp.begin(),dp.end(),a[i])-dp.begin();
           if(dp[idx-1]<a[i] && dp[idx+1]>a[i])
           dp[idx]=a[i];
       }
       for(int i=n;i>=0;i--){
           if(dp[i]!=INT_MAX) return i;
       }
       
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends