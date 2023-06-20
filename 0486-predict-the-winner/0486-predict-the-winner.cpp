class Solution {
public:

vector<vector<vector<int>>> dp;
int recur(int i,int j,vector<int>& nums,int turn){
    if(i>j) return 0;
    int leftaken=0,righttaken=0;
    if(dp[i][j][turn]!=-1) return dp[i][j][turn];
    if(turn==1){
   leftaken=nums[i]+recur(i+1,j,nums,1-turn);
   righttaken=nums[j]+recur(i,j-1,nums,1-turn);
        return dp[i][j][turn]=max(leftaken,righttaken);
    }
else {
    leftaken=recur(i+1,j,nums,1-turn);
    righttaken=recur(i,j-1,nums,1-turn);
    return dp[i][j][turn]=min(leftaken,righttaken);
}
    
}
    bool PredictTheWinner(vector<int>& nums) {
        
            int n=nums.size(),sum=0;
            dp.resize(n+1,vector<vector<int>>(n+1,vector<int>(2,-1)));
            for(int i=0;i<n;i++){
                sum+=nums[i];
            }
           int sum1= recur(0,n-1,nums,1);
        if(sum1>=(sum-sum1))return true;
        return false;










    }
};





//  vector<vector<int>> dp; 
// int pickstones(vector<int>&piles,int i,int j,int sum,int total){
// if(j-i==1){
//     return max(piles[i],piles[j]);
// }
// if(dp[i][j]!=-1) return dp[i][j];
//     int left=piles[i]+min(pickstones(piles,i+1,j-1,sum+piles[i],total),pickstones(piles,i+2,j,sum+piles[i],total));
//     int right=piles[j]+min(pickstones(piles,i+1,j-1,sum+piles[j],total),pickstones(piles,i,j-2,sum+piles[j],total));
//     return dp[i][j]=max(left,right);
// }

    




//     bool PredictTheWinner(vector<int>& nums) {
//           vector<int> piles(n);
//         for(int i=0;i<n;i++)piles[i]=arr[i];
//           int total=0;
//         // int n=piles.size();
//         for(int i=0;i<n;i++)total+=piles[i];
//         int sum=0;
//         dp.resize(n+1,vector<int>(n+1,-1));
//       return  pickstones(piles,0,n-1,sum,total);
        
//     }