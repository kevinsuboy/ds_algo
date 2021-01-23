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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next){}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int l = 0;
        ListNode *ptr = head;
        while (ptr)
        {
            l++;
            ptr = ptr->next;
        }
        l -= n;
        if (l == 0)
            return head->next;
        ptr = head;
        while (l > 1)
        {
            l--;
            ptr = ptr->next;
        }
        if (ptr->next)
            ptr->next = ptr->next->next;
        return head;
    }
};

int main()
{
    return 0;
}
