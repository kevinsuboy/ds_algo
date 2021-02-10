#include <iostream>
#include <stack>
#include <vector>
#include <set>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/
class Node
{
public:
    int val;
    Node *next;

    Node() {}

    Node(int _val)
    {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node *_next)
    {
        val = _val;
        next = _next;
    }
};
class Solution
{
public:
    Node *insert(Node *head, int insertVal)
    {
        if (!head)
        {
            head = new Node(insertVal);
            head->next = head;
        }
        if (head == head->next)
        {
            head->next = new Node(insertVal);
            head->next->next = head;
            return head;
        }
        Node *res = head, *nxt;
        while (!(head->val <= insertVal &&
            insertVal <= head->next->val) &&
            head->next != res)
        {
            head = head->next;
        }
        if (!(head->val <= insertVal &&
            insertVal <= head->next->val))
        { // made a full circle, didn't find between
            while (!(head->val >= head->next->val))
            {
                head = head->next;
            }
        }
        cout << "head: " << head->val << " next: " << head->next->val << endl;
        nxt = head->next;
        head->next = new Node(insertVal);
        head->next->next = nxt;
        return res;
    }
};
int main()
{
    return 0;
}
