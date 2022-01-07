question :https://leetcode.com/problems/two-sum/

brute force: takes O(N*N) time as 2 for loops
optimised : if we can search (target-currentelement) in O(1) then we can complete in O(N) time 
we can achieve this by using hastable(unordered map) which takes O(1) for(search,insert)
  
  
  note: here we are finding before inserting so the searching for same number problem can be reduced
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      // code starts here
      
      int n=nums.size();
      unordered_map<int,int>mp;
       vector<int>v;
      int current;
      for(int i=0;i<n;i++)
      {
        current=nums[i];
        if(mp.find(target-current)!=mp.end())
        {
          v.push_back(mp[target-current]);
          v.push_back(i);
          return v;
        }
        mp[current]=i;
      }
      
      return {};
      
      
      
      
        
    }
};
