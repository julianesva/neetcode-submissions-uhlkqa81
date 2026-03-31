/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {

        ListNode* pointer1 = head;
        ListNode* pointer2 = head;

        while(pointer2->next && pointer2->next->next){
            pointer1 = pointer1->next;
            pointer2 = pointer2->next->next;
        }

        cout<<"Pointer1:"<<pointer1->val<<endl;

        ListNode* secondh = pointer1->next;
        pointer1->next = nullptr;

        ListNode* curr = secondh;
        ListNode* prev = nullptr;

        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ListNode* curr2 = head;
        ListNode* prevnxt = nullptr;
        while(prev){
            ListNode* nextnxt = curr2->next;
            curr2->next = prev;
            prevnxt = prev->next;
            prev->next = nextnxt;
            prev = prevnxt;
            curr2 = nextnxt;
        }
    }
};
