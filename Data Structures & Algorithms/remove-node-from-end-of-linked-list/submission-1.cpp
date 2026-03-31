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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* temp = head;
        int quant_nodes = 0;

        while(temp != nullptr){
            quant_nodes++;
            temp = temp->next;
        }
        if(quant_nodes == 1){
            head = nullptr;
            return head;
        }


        int target = quant_nodes - n;
        // cout<<quant_nodes<<endl;
        temp = head;
        int curr_ind = 0;
        if(curr_ind == target){
            head = head->next;
        }
        while(temp != nullptr){
            cout<<curr_ind<<endl;
            if(curr_ind+1 == target){
                temp->next = temp->next->next;
                break;
            }
            else{
                curr_ind++;
                temp = temp->next;
            }

        }
        
        return head;
    }
};
