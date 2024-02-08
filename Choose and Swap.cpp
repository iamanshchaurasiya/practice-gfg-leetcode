//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
     string chooseandswap(string a){
        vector<int>freq(26,0);
        for(int i=0;i<a.size();i++) freq[a[i]-'a']++;
        char first='0',second='0';
        int i=0;
        for(;i<a.size();i++){
            freq[a[i]-'a']=0;
            for(char c='a';c<a[i];c++){
                if(freq[c-'a']>0){
                    second=c;
                    break;
                }
            }
            if(second!='0'){
                first=a[i];
                break;
            }
        }
        if(first=='0') return a;
        for(int i=0;i<a.size();i++){
            if(a[i]==first) a[i]=second;
            else if(a[i]==second) a[i]=first;
        }
        return a;
    }
};

//{ Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}

// } Driver Code Ends