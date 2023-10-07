#include "Solution.hpp" // header in local directory

using namespace leetcode;
using namespace std;

// Better solution
ListNode* Solution::swapNodes(ListNode* head, int k) {
    ListNode *fast=head, *slow=head, *first;
    int i=1;
    
    while(i<k)
    {
        fast = fast->next;
        i++;
    }
    
    first = fast;
    
    while(fast->next != NULL)
    {
        fast=fast->next;
        slow=slow->next;
    }
    
    int temp = first->val;
    first->val = slow->val;
    slow->val = temp;
    
    return head;            
}

/* non optimal solution (bad solution)
ListNode* Solution::swapNodes(ListNode* head, int k) {
    int v1, v2, count = 1;
    ListNode* tmp = head;
    while(tmp != nullptr)
    {
        if(k == count)
            v1 = tmp->val;

        count++;
        tmp = tmp->next;
    }

    tmp = head;
    int size = count;
    count = 1;
    while(tmp != nullptr)
    {
        if((size - k) == count)
            v2 = tmp->val;

        count++;
        tmp = tmp->next;
    }

    count = 1;
    tmp = head;
    int v = v2;
    while(tmp != nullptr)
    {   
        if(k == count)
            tmp->val = v;
        else if((size - k) == count)
            tmp->val = v1;
            
        count++;
        tmp = tmp->next;
    }
    return head;        
}*/
