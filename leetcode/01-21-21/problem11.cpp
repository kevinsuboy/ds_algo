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
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution
{
public:
    Node *flatten(Node *head)
    {
        Node *nxt, *tail, *origHead = head;
        while (head)
        {
            tail = head;
            nxt = head->next;
            if (head->child)
            { //traverse left
                tail = preorder(head, head->child);
                if (nxt)
                {
                    nxt->prev = tail;
                    tail->next = nxt;
                }
                head->child = NULL;
            }
            head = nxt; //traverse right
        }
        return origHead;
    }

private:
    Node *preorder(Node *head, Node *child)
    {
        Node *nxt, *tail;
        head->next = child;
        child->prev = head;
        while (child)
        {
            tail = child;
            nxt = child->next;
            if (child->child)
            { //traverse left
                tail = preorder(child, child->child);
                if (nxt)
                {
                    nxt->prev = tail;
                    tail->next = nxt;
                }
                child->child = NULL;
            }
            child = nxt; //traverse right
        }
        return tail; //
    }
};
int main()
{
    return 0;
}
