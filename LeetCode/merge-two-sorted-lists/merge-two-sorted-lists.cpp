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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;
        // Start finalList to whichever list has the smallest value
        ListNode* finalList = list1->val < list2->val ? list1 : list2;

        //Set the other list to whichever is not finalList
        ListNode* otherList = (finalList == list1) ? list2 : list1;
        ListNode* iter = finalList;

        while (iter != nullptr && otherList != nullptr) {
            // Look ahead and keep moving on iter until we need to switch
            while (iter->next != nullptr && iter->next->val <= otherList->val) {
                iter = iter->next;
            }
            // If we exhausted iter, attach the rest of otherList
            if (iter->next == nullptr) {
                iter->next = otherList;
                return finalList;
            }

            // Keep tabs on next node in current list, then switch lists
            ListNode* temp = iter->next;
            iter->next = otherList;
            iter = temp;

            while (otherList->next != nullptr && otherList->next->val <= iter->val) {
                otherList = otherList->next;
            }

            // If we exhausted otherList, attach the rest of iter
            if (otherList->next == nullptr) {
                otherList->next = iter;
                return finalList;
            }

            // Keep tabs on next node in current list, then switch lists
            temp = otherList->next;
            otherList->next = iter;
            otherList = temp;
        }

        return finalList;
    }
};