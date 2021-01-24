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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next)
            return head;
        if (k == 0)
            return head;
        ListNode *origHead = head;
        int N = 0;
        while (head)
        {
            N++;
            head = head->next;
        }
        k = (N - k % N) % N;
        head = origHead;
        if (k == 0)
            return origHead;
        while (k > 1)
        {
            k--;
            head = head->next;
        }
        ListNode *res = head->next;
        head->next = NULL;
        head = res;
        while (head->next)
        {
            head = head->next;
        }
        head->next = origHead;
        return res;
    }
};
int main()
{
    return 0;
}
