//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    
    // DEHA THA 
    
    
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& m, int n) 
    {
        // code here 
        stack<int> st;
        for(int i=0;i<n;i++)st.push(i);
        
        while(st.empty()==false){
            if(st.size()==1||st.size()==0) break;
            else {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                //  if(m[a][b]==1&&m[b][a]==1) continue;
                 if(m[a][b]==1)st.push(b);
                else if(m[b][a]==1)st.push(a);
            }
        }
        if(st.size()==0) return -1;
        for(int i=0;i<n;i++){
            if(m[st.top()][i]==1) return -1;
            else if(m[i][st.top()]==0&&i!=st.top()) return -1;
            
            
        }
        return st.top();
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends