class Solution
{
public:
	bool hasCycle(ListNode* head)
	{
		if(NULL == head) return false;
		ListNode* p = head;
		ListNode* q = head;
		while(true)
		{
			p = p->next;
			q = q->next;
			if(NULL != q) q = q->next;
			if(NULL == q || NULL == p) return false;
			else if(p == q) return true;
		}
	}
};
