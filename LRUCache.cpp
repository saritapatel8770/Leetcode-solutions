class LRUCache {
public:
    //doubly linked list
    class Node{
        public:
        int key,val;
        Node* next;
        Node* prev;
        
        Node(int key,int val){
            this->key=key;
            this->val=val;
        }
    };
    
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    
    int csize;
    unordered_map<int,Node*>mp;
    
    void addNode(Node* node){
        Node* temp=head->next;
        node->next=temp;
        head->next=node;
        node->prev=head;
        temp->prev=node;
    }
    
    void deleteNode(Node* node){
        Node* temp=node->prev;
        Node* temp1=node->next;
        temp->next=temp1;
        temp1->prev=temp;
    }
    
    
    LRUCache(int capacity) {
        csize=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node* temp=mp[key];
            int ans=temp->val;
            mp.erase(key);
            deleteNode(temp);
            addNode(temp);
            mp[key]=head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* temp=mp[key];
            mp.erase(key);
            deleteNode(temp);
        }
        if(mp.size()==csize){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key,value));
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
