//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int n, vector<int> &bills) {
        // code here
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            if(bills[i]==5){
                mp[5]++;
                
            }
            else {
                if(bills[i]==10){
                    if(mp[5]<=0){
                        return false;
                    }
                    mp[5]--;
                    mp[10]++;
                }
                if(bills[i]==20){
                    mp[20]++;
                   if(mp[10]>=1&&mp[5]>=1){
                       mp[10]--;
                       mp[5]--;
                       continue;
                   }
                   else if(mp[5]>=3){
                       mp[5]=mp[5]-3;
                       continue;
                   }
                   return false;
                   
                }
                
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends