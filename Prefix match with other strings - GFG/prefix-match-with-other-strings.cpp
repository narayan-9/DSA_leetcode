//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:

struct Node{
    Node* arr[26];
    bool flag=false;
};
class Trie {
    private: Node *root;
public:
 
    Trie() {
     root=new Node();
    }
    
    void insert(string word) {
        int n=word.size();
      Node* curr= root;
        for(int i=0;i<n;i++){
                if(curr->arr[word[i]-'a']==NULL){
                   Node* curr2= new Node();
                     curr->arr[word[i]-'a']=curr2;
                     curr=curr2;
                }
                else{
                    curr=curr->arr[word[i]-'a'];
                }
        }
        curr->flag=true;
    }
    
    bool search(string word,int k) {
        int n=word.size();
        Node* curr=root;
        for(int i=0;i<n;i++){
                if(curr->arr[word[i]-'a']==NULL) return false;
                curr=curr->arr[word[i]-'a'];
                k--;
        }
        //  if(curr->flag==true) return true;
        if(k==0) return true;
        return false;
    }


};


    int klengthpref(string arr[], int n, int k, string str){    
         Trie tr;
        tr.insert(str);
        int count=0;
        for(int i=0;i<n;i++){
            if(tr.search(arr[i].substr(0,k),k))count++;
        }
        return count;
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
        string arr[n];
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>arr[i];
            
        }
        int k;
        cin>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout << ob.klengthpref(arr, n, k, str) << endl;
    }
    return 0; 
} 

// } Driver Code Ends