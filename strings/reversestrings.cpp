https://leetcode.com/problems/reverse-string-ii/

two pointer approach
 string reverseStr(string s, int k) {
        
        int i=0;
        int n=s.size();
        int j=n-1;
      while(j-i+1>=2*k)
      {
          reverse(s.begin()+i,s.begin()+i+k);
          i=i+2*k;
      }
        if(j-i+1>k&&j-i+1<2*k)
        {
            reverse(s.begin()+i,s.begin()+i+k);
        }
        else 
        {
            reverse(s.begin()+i,s.end());
        }
        
        return s;
    }
    
one line for loop
string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += 2*k) reverse(s.begin()+i, min(s.begin()+i+k, s.end()));
        return s;
    }
    
