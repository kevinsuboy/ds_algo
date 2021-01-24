#include <iostream>
#include <stack>
#include <vector>
#include <set>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int c0 = 0;
        int v2;
        ListNode *l1Head = l1;
        while (l1 || l2)
        {
            if (l2)
                v2 = l2->val;
            else
                v2 = 0;
            l1->val += v2 + c0;
            c0 = l1->val / 10;
            l1->val %= 10;
            if (!l1->next && (c0 != 0 || (l2 && l2->next)))
                l1->next = new ListNode();
            l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        return l1Head;
    }
};
int main()
{
    return 0;
}
