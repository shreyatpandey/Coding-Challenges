/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
         // create a dictionary mapping original to copy
        map<Node*, Node*> nodes; // <orig, deep copy>

        // loop through nodes
        Node* tailOrig = head;
        //cout<<"tail:"<<tailOrig->val<<endl;
        Node* preHead = new Node(-1,nullptr,nullptr);
        Node* tailCopy = preHead;
        while (tailOrig)
        {
            // create a deep copy of the node. Leave random pointer as nullptr
            tailCopy->next = new Node(tailOrig->val, nullptr, nullptr);
            tailCopy = tailCopy->next;
            
            // add to dictionary
            //nodes[tailOrig] = tailCopy;
            nodes.emplace(tailOrig,tailCopy);
            tailOrig = tailOrig->next;
        }
        
        // loop through nodes again
        tailOrig = head;
        tailCopy = preHead->next;
        map<Node*,Node*>::iterator it;
        while (tailOrig)
        {
            // use dictionary to set the random pointers 
            tailCopy->random = nodes[tailOrig->random];
            /*if(nodes.find(tailOrig->random) != nodes.end())
            {nodes.emplace(tailOrig->random,tailCopy->random);}*/
            tailCopy = tailCopy->next;
            tailOrig = tailOrig->next;
        }
        
        // return head of deep copy
        Node* ans = preHead->next;
        delete preHead;
        return ans;
        
    }
};
