#include <iostream>
#include <stack>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return NULL;
        unordered_map<Node *, Node *> hash; // <orig, copied>
        Node *res = new Node(head->val), *origHead = head, *ptr;
        ptr = res;
        hash[head] = ptr;
        while (head->next)
        { // create chain and hash
            ptr->next = new Node(head->next->val);
            hash[head->next] = ptr->next;
            head = head->next;
            ptr = ptr->next;
        }
        head = origHead;
        ptr = res;
        while (head)
        { // copy rand
            if (head->random)
            {
                ptr->random = hash[head->random];
            }
            head = head->next;
            ptr = ptr->next;
        }
        return res;
    }
};
int main()
{
    return 0;
}
