//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends


class Solution
{
    public:
    bool areIsomorphic(string str1, string str2)
    {
        if (str1.length() != str2.length())
            return false;

        int n = str1.length();
        unordered_map<char, char> map;
        bool marked[MAX_CHARS] = {false};

        for (int i = 0; i < n; i++) {
            if (map.find(str1[i]) != map.end()) {
                if (map[str1[i]] != str2[i])
                    return false;
            }
            else {
                if (marked[str2[i]] == true)
                    return false;

                map[str1[i]] = str2[i];
                marked[str2[i]] = true;
            }
        }

        return true;
    }
};


//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends