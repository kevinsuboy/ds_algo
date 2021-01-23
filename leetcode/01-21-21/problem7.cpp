#include <iostream>
#include <stack>
#include <vector>
#include <set>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        if (!head)
            return true;
        ListNode *ptr = head, *oldHead;
        int n = 0;
        while (ptr)
        {
            n++;
            ptr = ptr->next;
        }
        if (n == 1)
            return true;
        ListNode *scnd;
        ptr = head;
        // reverse first half
        bool odd = n % 2 == 1;
        n /= 2;
        while (n > 1)
        {
            oldHead = head;
            head = ptr->next;
            ptr->next = ptr->next->next;
            head->next = oldHead;
            n--;
        }
        if (!odd)
        {
            scnd = ptr->next;
            ptr->next = NULL;
        }
        else
        {
            scnd = ptr->next->next;
            ptr->next = NULL;
        }
        ptr = head;
        while (scnd && ptr)
        {
            if (scnd->val != ptr->val)
                return false;
            scnd = scnd->next;
            ptr = ptr->next;
        }
        return true;
    }
};
int main(){
    return 0;
}

