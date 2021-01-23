#include <iostream>
#include <stack>
#include <vector>
#include <set>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (!head)
            return false;
        ListNode *t = head, *h = head->next;
        while (h && h->next && t)
        {
            if (t == h)
                return true;
            t = t->next;
            h = h->next->next;
        }
        return false;
    }
};
int main(){
    return 0;
}

