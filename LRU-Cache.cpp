class LRUCache {
public:
    class node{
        public:
        int k;
        int v;
        node *prev;
        node *next;
        node(int kk,int vv){
            k=kk;
            v=vv;
        }
    };
    
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);
    
    
    int cap;
    unordered_map<int,node*> m;
    
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void insertNode(node* newNode){
        node* temp=head->next;
        newNode->next=temp;
        newNode->prev=head;
        head->next=newNode;
        temp->prev=newNode;
    }
    
    void deleteNode(node* delNode){
        node* delPrev=delNode->prev;
        node* delNext=delNode->next;
        delPrev->next=delNext;
        delNext->prev=delPrev;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end()){
            node* resNode=m[key];
            int res=resNode->v;
            m.erase(key);
            deleteNode(resNode);
            insertNode(resNode);
            m[key]=head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            node* exitingNode = m[key];
            m.erase(key);
            deleteNode(exitingNode);
        }
        if(m.size() == cap){
            m.erase(tail->prev->k);
            deleteNode(tail-> prev);
        }
        insertNode(new node(key,value));
        m[key]=head->next;
    }
};
