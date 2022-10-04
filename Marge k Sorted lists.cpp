class cmp
{
public:
    bool operator()(ListNode *a, ListNode *b)
    {
        return (a->val > b->val);
    }
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        if (lists.size() == 0)
            return NULL;

        ListNode *head = new ListNode(-1);
        ListNode *tail_ptr = head;

        //         make a min heap
        priority_queue<ListNode *, vector<ListNode *>, cmp> q;

        for (int i = 0; i < lists.size(); i++)
        {

            if (lists[i] != NULL)
                q.push(lists[i]);
        }

        while (q.size())
        {
            auto temp = q.top();
            q.pop();

            tail_ptr->next = temp;
            tail_ptr = temp;

            if (temp->next)
            {
                q.push(temp->next);
            }
        }
        return head->next;
    }
};