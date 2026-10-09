class Node{
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k,int v){
        key=k;
        val=v;
        prev=nullptr;
        next=nullptr;
    }
};

class LRUCache {
private:
    int cap;
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    unordered_map<int,Node* >cache;

    void remove(Node* node){
        Node* behind=node->prev;
        Node* ahead=node->next;
        behind->next=ahead;
        ahead->prev=behind;
    }

    void insert(Node* node){
        Node* ahead=head->next;
        head->next=node;
        node->prev=head;
        node->next=ahead;
        ahead->prev=node;
    }
public:
    LRUCache(int capacity) {
        cap=capacity;
        cache.clear();
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(cache.find(key)!=cache.end()){
            Node* node=cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            Node* node=cache[key];
            remove(node);
            insert(node);
            node->val=value;
            return;
        }
        Node* newNode=new Node(key,value);
        insert(newNode);
        cache[key]=newNode;
        if(cap<cache.size()){
            Node* temp=tail->prev;
            cache.erase(temp->key);
            remove(temp);
            delete temp;
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */