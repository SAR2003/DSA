https://leetcode.com/problems/longest-increasing-subsequence/


timecomplexity:O(N*N) // N recursion call and in each one we have for loop so it take bigo(n*n);
  spacecomplexity:O(N) without recursion stack
class Solution {
    
    
   int  lis(vector<int>& nums,int i,vector<int>&dp)
   {
       if(dp[i]!=-1)
       {
           return dp[i];
       }
      int ans=1;
       for(int j=0;j<i;j++)
       {
           if(nums[i]>nums[j])
           {
               ans=max(ans,lis(nums,j,dp)+1);
           }
       }
       return dp[i]=ans;
   }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
          vector<int>dp(n,-1);
        for(int i=0;i<n;i++)
        {
            ans=max(ans,lis(nums,i,dp));
        }
        return ans;
        
    }
};

patience sorting :https://www.cs.princeton.edu/courses/archive/spring13/cos423/lectures/LongestIncreasingSubsequence.pdf
optimised time complexity:O(N*logN)
  using greedy and binarysearch
  
  class Solution {
    
    
  
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
         int j;
       vector<int>v;
        v.push_back(nums[0]);
        
        for(int i=1;i<n;i++)
        {
            if(nums[i]>v.back())
            {
                v.push_back(nums[i]);
            }
            else
            {
              auto it=lower_bound(v.begin(),v.end(),nums[i]);
                if(it!=v.end())
                {
                    v[it-v.begin()]=nums[i];
                }
            }
            j=v.size();
            
            ans=max(ans,j);
            
        }
        return ans;
    }
};
