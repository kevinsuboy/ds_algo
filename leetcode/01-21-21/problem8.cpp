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
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        int cnt = n - m;
        int idx = 0;
        ListNode *ptr = head, *first = head, *second = NULL;
        while (ptr)
        {
            idx++;
            if (idx + 1 == m)
            {
                first = ptr;
            }
            if (idx == n)
            {
                second = ptr->next;
                break;
            }
            ptr = ptr->next;
        }
        if (m > 1)
            first->next = reverseList(first->next, second, cnt);
        else
        {
            return reverseList(first, second, cnt);
        }
        return head;
    }

private:
    ListNode *reverseList(ListNode *head, ListNode *tail, int &cnt)
    {
        if (cnt == 0)
            return head;
        ListNode *curr = head;
        cnt--;
        head = reverseList(head->next, tail, cnt);
        curr->next->next = curr;
        curr->next = tail;
        return head;
    }
};
int main()
{
    return 0;
}
