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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (!headA || !headB)
            return NULL;
        ListNode *pA = headA, *pB = headB;
        bool A_swapped = false, B_swapped = false;
        while (pA != pB)
        {
            if (pA == pB)
                return pA;
            if (pA->next)
                pA = pA->next;
            else
            {
                if (!A_swapped)
                {
                    A_swapped = true;
                    pA = headB;
                }
                else
                    return NULL;
            }
            if (pB->next)
                pB = pB->next;
            else
            {
                if (!B_swapped)
                {
                    B_swapped = true;
                    pB = headA;
                }
                else
                    return NULL;
            }
        }
        return pA;
        return NULL;
    }
};
int main(){
    return 0;
}

