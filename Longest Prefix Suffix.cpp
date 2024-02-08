
// Sollution by Ansh Raj
// email: theanshchaurasiya@gmail.com

//{ Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function template for C++

class Solution{
public:		
    int lps(string s) {
        int n = s.length();
        vector<int> lps(n, 0);
        
        int len = 0; // Length of the previous longest prefix suffix
        
        int i = 1;
        while (i < n) {
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            } else { // (s[i] != s[len])
                if (len != 0) {
                    len = lps[len - 1];
                } else { // if len == 0
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
        return lps[n - 1];
    }
};


//{ Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}

// } Driver Code Ends

// Sollution by Ansh Raj
// email: theanshchaurasiya@gmail.com