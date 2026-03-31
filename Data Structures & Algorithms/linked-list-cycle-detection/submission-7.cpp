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
    bool hasCycle(ListNode* head) {
        if (head && !head->next) {
            return false;
        }

        ListNode* point1 = head;
        ListNode* point2 = head;

        while(point2 && point2->next){
            point1 = point1->next;
            point2 = point2->next->next;
            if(point1 == point2){
                return true;
            }
        }

        return false;
        
    }
};
