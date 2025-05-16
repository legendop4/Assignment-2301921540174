# Remove Nodes from Linked List

**Problem Link**: [2487. Remove Nodes From Linked List - LeetCode](https://leetcode.com/problems/remove-nodes-from-linked-list/)  
**Solution Link**: [My Submission](https://leetcode.com/problems/remove-nodes-from-linked-list/submissions/1633040849)

## Intuition
The solution removes nodes from a linked list where a node should be deleted if there exists a node with a greater value to its right by:
1. Using a monotonic stack to track nodes in decreasing order
2. Reconstructing the list from the stack to maintain only valid nodes

## Approach
1. **Stack Processing**:
   - Traverse the linked list while maintaining a stack of nodes in decreasing order
   - Pop nodes from stack when current node's value is greater than top node's value

2. **List Reconstruction**:
   - Rebuild the list from the stack in reverse order
   - Set next pointers appropriately to form the final list

## Complexity
- **Time Complexity**: O(n)  
  - Single pass through the linked list
  - Each node pushed and popped from stack at most once
- **Space Complexity**: O(n)  
  - Stack storage in worst case (when list is strictly decreasing)

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
    ListNode* removeNodes(ListNode* head) {
        ListNode* node = head;
        stack<ListNode*> s;
        
        // Build monotonic stack
        while(node != nullptr) {
            while(!s.empty() && s.top()->val < node->val) {
                s.pop();
            }
            s.push(node);
            node = node->next;
        }
        
        // Reconstruct list
        ListNode* nxt = nullptr;
        while(!s.empty()) {
            node = s.top();
            s.pop();
            node->next = nxt;
            nxt = node;
        }
        
        return node;
    }
};
