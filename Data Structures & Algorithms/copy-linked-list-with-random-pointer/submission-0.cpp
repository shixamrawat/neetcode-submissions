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
        if (head == nullptr) return nullptr;
        Node* temp=head;
        // add node in btw
        while(temp!=nullptr){
            Node* curr=new Node(temp->val);
            curr->next=temp->next;
            temp->next=curr;
            temp=curr->next;
        }
        // add random
        temp=head;
        Node* curr=head->next;
        while(temp!=nullptr){
            curr=temp->next;
            if(temp->random!=nullptr){
                curr->random=temp->random->next;
            }
            temp=curr->next;
        }
        // add next
        temp=head;
        Node* dummy=new Node(-1);
        curr=head->next;
        dummy->next=curr;

        while(temp!=nullptr){
            curr=temp->next;
            temp->next=curr->next;
            temp=temp->next;
            if(temp!=nullptr){
                curr->next=temp->next;
            }
        }

        return dummy->next;

    }
};