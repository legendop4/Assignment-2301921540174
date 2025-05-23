# 23. Merge k Sorted Lists - Solution

## Problem Link
[23. Merge k Sorted Lists - LeetCode](https://leetcode.com/problems/merge-k-sorted-lists/)

## Solution Link
[My Submission](https://leetcode.com/problems/merge-k-sorted-lists/submissions/1642345619)

## Intuition
The problem requires merging k sorted linked lists into one sorted linked list. The key insights are:
1. Pairwise merging is more efficient than sequential merging
2. Divide and conquer approach reduces time complexity
3. Repeatedly merge pairs of lists until only one list remains

## Approach
1. **Base Case Handling**: Return null if input list is empty
2. **Pairwise Merging**:
   - Divide the k lists into pairs
   - Merge each pair using standard two-list merge
   - Replace the original lists with merged results
3. **Repeat Until Single List**:
   - Continue merging pairs until only one list remains
4. **Two-list Merge**:
   - Standard merge algorithm for two sorted linked lists
   - Compare node values and build merged list incrementally

## Solution Code
```cpp
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) {
            return nullptr;
        }
        
        while(lists.size() > 1) {
            vector<ListNode*> temp;
            for(int i = 0; i < lists.size(); i += 2) {
                ListNode* l1 = lists[i];
                ListNode* l2 = (i + 1 < lists.size()) ? lists[i + 1] : nullptr;
                temp.push_back(mergeLists(l1, l2));
            }
            lists = move(temp);
        }
        
        return lists[0];
    }

    ListNode* mergeLists(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* node = &dummy;
        
        while(l1 && l2) {
            if(l1->val > l2->val) {
                node->next = l2;
                l2 = l2->next;
            } else {
                node->next = l1;
                l1 = l1->next;
            }
            node = node->next;
        }
        
        node->next = l1 ? l1 : l2;
        return dummy.next;
    }
};
