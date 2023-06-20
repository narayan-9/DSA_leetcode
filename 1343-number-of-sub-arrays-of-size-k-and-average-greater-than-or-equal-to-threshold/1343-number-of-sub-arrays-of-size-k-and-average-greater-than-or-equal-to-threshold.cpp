class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n=arr.size();
        int sum=0;
        for(int i=0;i<k;i++)sum+=arr[i];
        int ans=0;
if((sum/k)>=threshold)ans++;
        int i=k;
        while(i<n){
           
            sum=sum+arr[i];
        sum=sum-arr[i-k];
        if((sum/k)>=threshold)ans++;
        i++;
        }
        return ans;
    }
};