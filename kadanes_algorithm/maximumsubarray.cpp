https://leetcode.com/problems/maximum-subarray/

optimised solution :O(N)time and O(1) space
 int max_sofar=arr[0];
    int currentsum=arr[0];
        int n=arr.size();
    for(int i=1;i<n;i++)
    {
         
        currentsum=max(currentsum+arr[i],arr[i]);
       
        if(max_sofar<currentsum)  max_sofar=currentsum;
        
       
        
    }
    return max_sofar;
        
    }


        int max_upto=INT_MIN;
        int currentmaxi=0;
        
        for(int i=0;i<nums.size();i++)
        {
            currentmaxi+=nums[i];
            if(max_upto<currentmaxi)
            {
                max_upto=currentmaxi;
            }
            if(currentmaxi<0)
            {
                currentmaxi=0;
            }
        }
        
        return max_upto;

divide and conquer approach

class Solution {
  int maxsum(vector<int>& arr,int l,int r)
  {
      if(l>r)
      {
          return INT_MIN;
      }
      int mid=l+(r-l)/2;
      
      int left_max=maxsum(arr,l,mid-1);
      int right_max=maxsum(arr,mid+1,r);
      int lm=0,rm=0;
      for(int i=mid-1,sum=0;i>=l;i--)
      {
          sum=sum+arr[i];
          lm=max(lm,sum);
      }
       for(int i=mid+1,sum=0;i<=r;i++)
      {
          sum=sum+arr[i];
          rm=max(rm,sum);
      }
      
      return max(max(left_max,right_max),arr[mid]+lm+rm);
     
  }
public:
    int maxSubArray(vector<int>& arr) {
        
        int n=arr.size()-1;
        return maxsum(arr,0,n);
    }
};
