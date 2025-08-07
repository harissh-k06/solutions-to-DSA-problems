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

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node* , Node*> map;
        Node* temp = head;
        Node* prev = nullptr ;
        Node* newHead = nullptr;
        while (temp){
            Node* newNode = new Node(temp->val);
            if (!prev) {
                newHead = newNode;
            }else{
                prev->next = newNode;
            }
            prev = newNode;
            map[temp] = newNode;
            temp = temp->next;
        }
        temp = head;
        Node* temp_copy = newHead;
        while (temp){
            temp_copy->random = map[temp->random];
            temp_copy = temp_copy->next;
            temp=temp->next;
        }
        return newHead;
    }
};