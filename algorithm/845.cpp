class Solution {
public:
    int longestMountain(vector<int>& A) {
        int ans=0;
        int up_mountain=0,down_mountain=0;
        int length=0;
        if(A.size()==0) return ans;

          for(int i=0;i<A.size()-1;i++){
              if(down_mountain!=1&&A[i]<A[i+1]){
                  if(up_mountain==0){
                      up_mountain=1;
                      length=2;
                  }
                  else
                  length++;
              }
              if(up_mountain&&A[i]>A[i+1]){
                  down_mountain=1;
                  up_mountain=0;
              }
              if(A[i]==A[i+1]){
                up_mountain=0;
                down_mountain=0;
                length=0;
              }
              if(down_mountain&&A[i]>A[i+1]){
                  length++;
                  ans=(ans<length)?length:ans;
              }
              if(down_mountain&&A[i]<A[i+1]){
                  ans=(ans<length)?length:ans;
                  length=2;
                  down_mountain=0;
                  up_mountain=1;
              }
          }
          return ans;
    }
};