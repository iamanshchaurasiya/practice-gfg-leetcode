//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    string smallestWindow(string s, string p) {
        unordered_map<char, int> freqP;
        for (char c : p) {
            freqP[c]++;
        }
        
        int start = 0, end = 0;
        int counter = 0;
        int minLen = INT_MAX;
        int minStart = 0;
        
        while (end < s.length()) {
            if (freqP[s[end]] > 0) {
                counter++;
            }
            freqP[s[end]]--;
            
            while (counter == p.length()) {
                if (end - start + 1 < minLen) {
                    minLen = end - start + 1;
                    minStart = start;
                }
                
                freqP[s[start]]++;
                if (freqP[s[start]] > 0) {
                    counter--;
                }
                start++;
            }
            
            end++;
        }
        
        return minLen == INT_MAX ? "-1" : s.substr(minStart, minLen);
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends