https://leetcode.com/problems/subsets/
using recursion and backtacking
class Solution {
    int j=0;
    void recursion(vector<int>&nums,vector<int>&ans,vector<vector<int>>&v,int i ,int n)
    {
        if(i==n)
        {
            v[j++]=ans;
            return ;
        }
        
        ans.push_back(nums[i]);
        recursion(nums,ans,v,i+1,n);
        ans.pop_back();
        recursion(nums,ans,v,i+1,n);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<vector<int>>v(pow(2,n));
        vector<int>ans;
        int i=0;
        recursion(nums,ans,v,i,n);
        
        return v;
        
        
    }
};

same by recursion but using iterative also 
void recursion(vector<int>& nums,int i,vector<int>&ans,vector<vector<int>>&v)
  {
      v.push_back(ans);
      for(int j=i;j<nums.size();j++)
      {
          ans.push_back(nums[j]);
          recursion(nums,j+1,ans,v);
          ans.pop_back();
          
      }
  }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int>ans;
        vector<vector<int>>v;
       recursion(nums,0,ans,v);
        
        return v;
        
        
    }
};

using bit manipulation 
time complexity:O((2^n)*n)
  
  class Solution {
 
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>v(1<<n);
        int k=0;
        
        for(int i=0;i<(1<<n);i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                {
                    v[k].push_back(nums[j]);
                }
            }
            k++;
        }
        return v;
        
        
    }
};
 complete iterative 
 class Solution {
 
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>v={{}};
        
        for(int ele:nums)
        {
            int s=v.size();
            for(int i=0;i<s;i++)
            {
                v.push_back(v[i]);
                v.back().push_back(ele);
            }
        }
       
        return v;
        
        
    }
};
