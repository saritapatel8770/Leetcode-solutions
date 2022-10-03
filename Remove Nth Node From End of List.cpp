class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fst=head;ListNode* slw=head;
        if (n==0) return head;
        for(int i=0;i<n;i++){
            fst=fst->next;
        }
        if(fst == NULL ) return head->next;
        //cout << slw->val;
        while(fst->next != NULL){
            //cout <<"hello";
            slw=slw->next;
            fst=fst->next;
        }
        
        slw->next=(slw->next)->next ;
        
     return head;   
    }
};
