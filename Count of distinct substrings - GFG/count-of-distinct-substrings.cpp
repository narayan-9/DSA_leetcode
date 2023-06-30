//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int countDistinctSubstring(string s);

int main()
{
 int t,l,i,j;
 int temp;
    cin>>t;
 while(t--){
 string s;
  cin>>s;
  cout<<countDistinctSubstring(s)<<endl;

 }
}


// } Driver Code Ends


/*You are required to complete this method */
struct Node{
    Node* arr[26];
bool    flag=false;

void insert(char c,Node *curr){
    arr[c-'a']=curr;
}
bool search(char c){
    return arr[c-'a'];
}


};
int countDistinctSubstring(string s)
{
    //Your code here
    int n=s.size();
    Node *root=new Node();
    int count=0;
    for(int i=0;i<n;i++){
        Node *curr=root;
        for(int j=i;j<n;j++){
            if(curr->search(s[j])==false){
                count++;
                curr->insert(s[j],new Node());
            }
            curr=curr->arr[s[j]-'a'];
        }
        
    }
    return count+1;
}