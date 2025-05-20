# Delete the Middle Node of a Linked List

**Problem Link**: [2095. Delete the Middle Node of a Linked List - LeetCode](https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/)  
**Solution Link**: [My Submission](https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/submissions/1627218629)

## Intuition
The solution deletes the middle node of a linked list by:
1. Calculating the total length of the list
2. Finding the middle position (n/2)
3. Traversing to the node before the middle
4. Skipping the middle node by adjusting pointers

## Approach
1. **Edge Case Handling**:
   - Return `nullptr` if list is empty or has only one node

2. **Length Calculation**:
   - Traverse the entire list to count nodes (O(n) time)

3. **Middle Node Removal**:
   - Compute middle position as `n/2`
   - Traverse to the node before middle (O(n/2) time)
   - Bypass the middle node by setting `prev->next = curr->next`

## Complexity
- **Time Complexity**: O(n)  
  - Two passes through the list (length calculation + middle finding)
- **Space Complexity**: O(1)  
  - Uses constant extra space

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
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) 
            return nullptr;
        
        // Calculate length
        int n = 0;
        ListNode* trav = head;
        while(trav != nullptr) {
            n++;
            trav = trav->next;
        }
        
        // Find node before middle
        int to_remove = n / 2;
        trav = head;
        for (int i = 0; i < to_remove - 1; i++) {
            trav = trav->next;
        }
        
        // Delete middle node
        trav->next = trav->next->next;
        return head;
    }
};
