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
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head)
            return NULL;
        ListNode *oddHead = head->next;
        ListNode *ptr1 = head, *ptr2 = head->next, *prev;
        bool even = true;
        while (ptr2)
        {
            even = !even;
            ptr1->next = ptr2->next;
            prev = ptr1;
            ptr1 = ptr2;
            ptr2 = ptr2->next;
        }
        if (even)
            ptr1->next = oddHead;
        else
            prev->next = oddHead;
        return head;
    }
};
int main()
{
    return 0;
}
