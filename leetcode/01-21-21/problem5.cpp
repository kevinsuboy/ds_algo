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
    ListNode *removeElements(ListNode *head, int val)
    {
        if (!head)
            return NULL;
        ListNode *origHead = head, *prev = head;
        while (head)
        {
            if (head->val == val)
                prev->next = head->next;
            else
                prev = head;
            head = head->next;
        }
        while (origHead && origHead->val == val)
            origHead = origHead->next;
        return origHead;
    }
};
int main(){
    return 0;
}

