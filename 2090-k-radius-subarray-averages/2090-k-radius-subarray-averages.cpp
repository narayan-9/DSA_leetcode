class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
    //     int n=nums.size();
    //     vector<int> ans(n,-1);
    //     vector<long long int > prefix(n,0),suffix(n,0);
    //     prefix[0]=nums[0];
    //     suffix[n-1]=nums[n-1];
    //     for(int i=1;i<n;i++){
    //         prefix[i]=prefix[i-1]+1LL*nums[i];
    //         suffix[n-i-1]=suffix[n-i]+1LL*nums[n-i-1];
    //     }
        
    //     // for(int i=0;i<k;i++)ans[i]=0;
    //     //        cout<<"ok"<<endl;
    //     for(int i=k;i+k<n;i++){
    // ans[i]=(prefix[i]-prefix[i-k]+1LL*nums[i-k]+suffix[i]-suffix[i+k]+1LL*nums[i+k]-1LL*nums[i])/(2*k+1);
    //         }
           
    //     return ans;




    // o(1) space
  int n=nums.size();
        vector<int> ans(n,-1);
        long long sum=0;
        int ind=0;
        for(int i=0;i<n;i++)
        {
            sum=sum+nums[i];
            if(i-ind+1 > 2*k + 1 )
            {
                sum=sum-nums[ind];
                ind++;
            }
            if(i-ind+1 == 2*k + 1)
            {
                ans[ind+k]=sum/(i-ind+1);
            }
        }
        return ans;


    }
};