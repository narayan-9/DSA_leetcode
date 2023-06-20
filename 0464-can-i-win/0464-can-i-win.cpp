// class Solution {
// public:
// // bahut kam tc aarahi hai isse 


// vector<vector<int>> dp;
// bool recur(int sum,int mask,int turn,int mxchsint,int destotal){
//     if(dp[mask][turn]!=-1) return dp[mask][turn];
//     if(turn==1){
//         if(sum>=destotal) return dp[mask][turn]=false;
//     bool flag=false;
//         for(int i=0;i<mxchsint;i++){
//             int cmask=1<<i;
//             if((mask&cmask)==0){
//                 flag=flag|recur(sum+i+1,mask|cmask,1-turn,mxchsint,destotal);
//                 if(flag) return dp[mask][turn]=flag;
//             }
//         }
//         return dp[mask][turn]=flag;
//     }
//     else {
// if(sum>=destotal) return dp[mask][turn]=true;
// bool flag=true;
// for(int i=0;i<mxchsint;i++){
//     int cmask=(1<<i);
//             if((mask&cmask)==0){
//                 flag=flag&recur(sum+i+1,mask|cmask,1-turn,mxchsint,destotal);
//                 if(!flag) return dp[mask][turn]=false;
//             }
//         }
//         if(flag==true) return dp[mask][turn]= true;
//         return dp[mask][turn]=false;
//     }
// }
//     bool canIWin(int mxchsint, int destotal) {
//         if(destotal<=mxchsint) return true;
//         if((mxchsint*(mxchsint+1)/2)<destotal) return false;
//         dp.resize(1<<mxchsint,vector<int>(2,-1));
//       return  recur(0,0,1,mxchsint,destotal);
//     }
// };



// The fun Part is, the variable 'player' is actually useless..
// The program runs faster without using this variable at all..
// You just need to make sure that if you want to win...., the player playing after you must lose..thats it


class Solution {
private:
    int m,t;
    vector<int> dp;
    bool game(int mask,int score){
        if(dp[mask]!=-1) return dp[mask];
        for(int i=0;i<m;i++)
        {
            int cmask = 1<<i;
            if( (mask&cmask) == 0 )
                    if(score+i+1 >= t or game((mask|cmask),score+i+1)==false ) return dp[mask]=1;
        }
        return dp[mask]=0;
    }
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        m=maxChoosableInteger;
        t=desiredTotal;
        if((m*(m+1))/2 < t) return false;
        dp.resize(1<<m,-1);
        return game(0,0);
    }
};
