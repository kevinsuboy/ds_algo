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
    ListNode *detectCycle(ListNode *head)
    {
        if (!head || !head->next)
            return NULL;
        ListNode *t = head->next, *h = head->next->next;
        while (t != h)
        {
            if (!t || !h || !h->next)
                return NULL;
            t = t->next;
            h = h->next->next;
        }
        t = head;
        while (t != h)
        {
            t = t->next;
            h = h->next;
        }
        return t;
    }
};

int main(){
    return 0;
}

