# Delete Node in a Linked List

**Problem Link**: [237. Delete Node in a Linked List - LeetCode](https://leetcode.com/problems/delete-node-in-a-linked-list/)  
**Solution Link**: [My Submission](https://leetcode.com/problems/delete-node-in-a-linked-list/submissions/1633022957)

## Intuition
The solution deletes a node from a singly-linked list without access to the head by:
1. Copying the value from the next node
2. Skipping over the next node in the list
3. Effectively removing the current node by making it a clone of the next node

## Approach
1. **Value Copy**:
   - Overwrite current node's value with next node's value
2. **Pointer Adjustment**:
   - Set current node's next pointer to skip the next node
3. **Memory Consideration**:
   - Original next node becomes unreachable (would need explicit deletion in C++)

## Complexity
- **Time Complexity**: O(1)  
  - Constant time operations
- **Space Complexity**: O(1)  
  - No additional space used

## Solution Code
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
