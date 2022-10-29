class MyLinkedList {
public:
    MyLinkedList() {
        head = tail = nullptr;
        size = 0;
    }
    
    ~MyLinkedList()
    {
        ListNode* tmp;
        while (head)
        {
            tmp = head;
            head = head->next;
            delete tmp;
        }
    }
    
    int get(int index) const {
        if (index >= size)
            return -1;
        
        ListNode* curr = head;
        while (index--)
            curr = curr->next;
        
        return curr->val;
    }
    
    void addAtHead(int val) {
        ListNode* tmp = new ListNode(val);
        tmp->next = head;
        head = tmp;
        
        tail = tail == nullptr ? head : tail;
        ++size;
    }
    
    void addAtTail(int val) {
        ListNode* tmp = new ListNode(val);
        
        if (tail == nullptr)
            tail = head = tmp;
        else
            tail->next = tmp, tail = tmp;
        
        ++size;
    }
    
    void addAtIndex(int index, int val) {
        if (index <= size)
        {
            if (index == 0)
                addAtHead(val);
            
            else if (index == size)
                addAtTail(val);
            
            else
            {
                ListNode* curr = head;
                while (--index >= 1)
                    curr = curr->next;
                
                ListNode *tmp = new ListNode(val), *nxt = curr->next;
                curr->next = tmp;
                tmp->next = nxt;
                
                ++size;
            }
                
        }
    }
    
    void deleteAtIndex(int index) {
        if (index < size)
        {
            ListNode* tmp;
            
            if (index == 0)
            {
                tmp = head;
                head = head->next;
                
                if (head == nullptr)
                    tail = nullptr;
            }
            
            else
            {
                ListNode* curr = head;
                while (--index)
                    curr = curr->next;
                
                tmp = curr->next;
                curr->next = curr->next->next;
                
                if (tail == tmp)
                   tail = curr; 
            }
            
            delete tmp;
            --size;
        }
    }
    
private:
    class ListNode
    {
    public:
        ListNode(const int& _val) :val(_val), next(nullptr) {}
            
        ListNode* next;
        int val;
    };
    
    int size;
    ListNode *head, *tail;
};
