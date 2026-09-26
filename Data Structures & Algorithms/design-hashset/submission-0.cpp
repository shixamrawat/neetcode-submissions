class MyHashSet {
private:
    struct Node{
        int key;
        Node* next;
        Node(int key){
            this->key=key;
            this->next=nullptr;
        }
    };
    vector<Node*>set;
    int hash(int key){
        return key%set.size();
    }

public:
    MyHashSet() {
        set.resize(10000);
        for(auto& bucket:set){
            bucket=new Node(0);
        }
    }
    
    void add(int key) {
        Node* curr=set[hash(key)];
        while(curr->next){
            if(curr->next->key==key)return;
            curr=curr->next;
        }
        curr->next=new Node(key);
    }
    
    void remove(int key) {
        Node* curr=set[hash(key)];
        while(curr->next){
            if(curr->next->key==key){
                Node*temp=curr->next;
                curr->next=temp->next;
                delete temp;
                return;
            };
            curr=curr->next;
        }
    }
    
    bool contains(int key) {
        Node* curr=set[hash(key)];
        while(curr->next){
            if(curr->next->key==key)return true;
            curr=curr->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */