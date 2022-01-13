https://leetcode.com/problems/combination-sum/

unbounded knapsack variation and backtracking

class Solution {
    
   void recursion(vector<int>&candidates,int target,vector<vector<int>>&v,int n,vector<int>&ans)
   {
       if(target==0)
       {
           v.push_back(ans);
           return ;
       }
       
       
       if(n==0||target<0)
       {
           
           return;
       }
      
       
       if(candidates[n-1]<=target)
       {
           ans.push_back(candidates[n-1]);
           recursion(candidates,target-candidates[n-1],v,n,ans);
           ans.pop_back();
           
       }
       
           recursion(candidates,target,v,n-1,ans);
       
   }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
       vector<vector<int>>v;
        vector<int>ans;
        int n=candidates.size();
        recursion(candidates,target,v,n,ans);
        return v;
        
    }
};
