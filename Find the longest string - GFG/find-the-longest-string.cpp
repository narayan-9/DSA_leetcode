//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:

struct Node{
    Node* arr[26];
    bool flag=false;
};

class Trie{
    private: Node* root;
    public:
    
    Trie(){
        root=new Node();
    }
    
    void insert(string &word){
        int n=word.size();
        Node* curr=root;
        for(int i=0;i<n;i++){
            if(curr->arr[word[i]-'a']==NULL){
                Node* curr2=new Node();
                curr->arr[word[i]-'a']=curr2;
            }
            
            curr=curr->arr[word[i]-'a'];
        }
        curr->flag=true;
    }
    bool search(string &word){
        
        int n=word.size();
        Node* curr=root;
        for(int i=0;i<n;i++){
            if(curr->arr[word[i]-'a']==NULL) return false;
            curr=curr->arr[word[i]-'a'];
        }
     if(curr->flag==true) return true;
        return false;
    }
    
};
    string longestString(vector<string> &words)
    {
        // code here
        sort(words.begin(),words.end());
        Trie tr;
        string ans="";
        for(auto &it:words){
            tr.insert(it);
        }
        for(auto &it:words){
            int m=it.size();
            string temp="";
            bool f=true;
            for(int i=0;i<m;i++){
                temp.push_back(it[i]);
                if(tr.search(temp)==false){
                    f=false;
                    break;
                }
            }
           if(f) if(ans.size()<m)ans=it;
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends