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
    
    /*
     * handle_carry: check wheter current node needs to carry and handle it.
     * @node: current node (must not nullptr)
     * return:
     *    true: carry
     *    false: not carry
     */
    bool handle_carry(ListNode* node){
        if (node->val >= 10){
            node->val -= 10;
            if (__builtin_expect(!!node->next, true))
                node->next->val += 1;
            else{
                node->next = new(struct ListNode);
                node->next->val = 1;
                node->next->next = nullptr;
            }
            return true;
        }
        return false;
    }
    /* 
     * addTwoNumbers: input two lists return their sum
     * @l1: list1
     * @l2: list2
     * return: Header of list sum.
     * 
     * description:
     *    This method will destroy input lists, because we directly add them 
     *    into original list.
     */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ptr1 = l1, *ptr2 = l2, *ptr, *rtn_val;
        while (ptr1 && ptr2) {
            ptr1->val += ptr2->val;
            handle_carry(ptr1);
            ptr2->val = ptr1->val;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        if (ptr1) {
            while (handle_carry(ptr1))
                ptr1 = ptr1->next;
            return l1;
        }
        else if(ptr2) {
            while(handle_carry(ptr2))
                ptr2 = ptr2->next;
            return l2;
        }
        return l1;
    }
};
