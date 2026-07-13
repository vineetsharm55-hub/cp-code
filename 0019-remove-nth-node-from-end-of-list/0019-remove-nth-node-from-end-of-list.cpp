class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* temp = new ListNode(0);
        temp->next = head;

        ListNode* first = temp;
        ListNode* last = temp;

        for (int i = 0; i <= n; i++) {
            first = first->next;
        }

        while (first != NULL) {
            first = first->next;
            last = last->next;
        }

        ListNode* del = last->next;
        last->next = last->next->next;
        delete del;

        return temp->next;
    }
};