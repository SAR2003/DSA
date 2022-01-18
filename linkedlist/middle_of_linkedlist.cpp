problem :https://leetcode.com/problems/middle-of-the-linked-list/

naive approach: find the total number of nodes(n) and find the middle of node by traversing to the middle.
  
        ListNode *p=head;

        while(p)
        {
            p=p->next;
            ct++;
        }
        
        ct=ct/2;
        int t=0;
        while(t!=ct)
        {
            head=head->next;
            t++;
        }
        return head;

optimised approach:using slow fast pointer

 ListNode *slow=head;
         ListNode *fast=head;
        while(fast&&fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
        
time complexity:o(N)
  space complexity:O(1)

  
