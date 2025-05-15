# Linked List Cycle II

**Problem Link**: [142. Linked List Cycle II - LeetCode](https://leetcode.com/problems/linked-list-cycle-ii/)  
**Solution Link**: [My Submission](https://leetcode.com/problems/linked-list-cycle-ii/submissions/1627212282)

## Intuition
The solution uses Floyd's Tortoise and Hare algorithm to:
1. Detect if a cycle exists
2. Find the exact node where the cycle begins

## Approach
1. **Phase 1 (Cycle Detection)**:
   - Slow pointer moves 1 step, fast pointer moves 2 steps
   - If they meet, cycle exists

2. **Phase 2 (Cycle Start Detection)**:
   - Reset slow pointer to head
   - Move both pointers 1 step until they meet
   - Meeting point is the cycle start node

## Complexity
- **Time Complexity**: O(n)  
  - Linear time regardless of cycle presence
- **Space Complexity**: O(1)  
  - Uses only two pointers

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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            
            if(slow == fast) {
                slow = head;
                while(slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};
