class Solution {
public:
     vector<vector<int>> result;

     void f(vector<int> &c, int idx, int t, vector<int> &v){

         if(t==0){
             result.push_back(v);
             return;
         }
         if(idx==c.size()) return ;
         if(c[idx]<=t){
             //we can pick
             v.push_back(c[idx]);
             f(c,idx+1,t-c[idx],v);
             v.pop_back();
         }
         int j=idx+1;
         while(j< c.size() and c[j]==c[j-1])j++;
         f(c,j,t,v);
     }    
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
         vector<int> v;
         sort(c.begin(),c.end());
         f(c,0,target,v);
         return result;
    }
};