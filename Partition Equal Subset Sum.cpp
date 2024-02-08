//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int rec(int N, int arr[],int index,int target)
    {
        //Base case
        if(target < 0)
            return 0;
        if(target == 0)
            return 1;
        if(index == N) // indwex goes out of array and we did not get target as 0
            return 0;

            
        int incl = rec(N,arr,index+1,target-arr[index]);
        int excl = rec(N,arr,index+1,target);
        
        return incl or excl;
    }
    
    int mem(int N, int arr[],int index,int target, vector< vector<int> > &dp)
    {
        //Base case
        if(target == 0)
            return 1;
        if(target < 0)
            return 0;
        if(index == N) // indwex goes out of array and we did not get target as 0
            return 0;

        if(dp[index][target] != -1)
            return dp[index][target];
            
        //R.C
        int incl = mem(N,arr,index+1,target-arr[index],dp);
        int excl = mem(N,arr,index+1,target,dp);
        
        dp[index][target] = incl or excl;
        return dp[index][target];
    }
    
    int tab(int N, int arr[],int t)
    {
        vector< vector<int> > dp(N+1, vector<int>(t+1,0));
        
        //Base case
        for(int i=0; i<=N; i++)
            dp[i][0] = 1;
            
        for(int index=N-1; index>=0; index--)
        {
            for(int target=0; target<=t; target++)
            {
                int incl = 0;
                if(target-arr[index] >= 0)
                {
                    incl = dp[index+1][target-arr[index]];
                }
                
                int excl = dp[index+1][target];
                
                dp[index][target] = incl or excl;
            }
        }
            
        return dp[0][t];
    }
    
    int so(int N, int arr[],int t)
    {
        vector<int> next(t+1,0);
        vector<int> cur(t+1,0);
        
        cur[0]  = 1;
        next[0] = 1;
            
        for(int index=N-1; index>=0; index--)
        {
            for(int target=0; target<=t; target++)
            {
                int incl = 0;
                if(target-arr[index] >= 0)
                    incl = next[target-arr[index]];
                
                int excl = next[target];
                
                cur[target] = incl or excl;
            }
            next = cur;
        }
        return next[t];
    }
    
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0; i<N; i++)
            sum = sum + arr[i];
            
        if(sum & 1) //odd
            return 0;
        else
        {
            int target = sum/2;
            // return rec(N,arr,0,target);
            ///vector< vector<int> > dp(N+1, vector<int>(target+1,-1));
           // return mem(N,arr,0,target,dp);
           
           //return tab(N,arr,target);
           return so(N,arr,target);
        }
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends