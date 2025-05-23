# 25. Reverse Nodes in k-Group - Solution

## Problem Link
[25. Reverse Nodes in k-Group - LeetCode](https://leetcode.com/problems/reverse-nodes-in-k-group/)

## Solution Link
[My Submission](https://leetcode.com/problems/reverse-nodes-in-k-group/submissions/1642350053)

## Intuition
The problem requires reversing nodes of a linked list k at a time. The key insights are:
1. Recursively process the list in chunks of size k
2. For each chunk, check if there are enough nodes to reverse
3. Reverse the current k nodes and connect it to the reversed remainder

## Approach
1. **Base Case Handling**:
   - Check if there are at least k nodes remaining
   - If not, return the head as-is
2. **Recursive Processing**:
   - Reverse the next k-group recursively
   - Reverse the current k nodes
   - Connect the reversed current group to the reversed remainder
3. **Reversal Technique**:
   - Standard linked list reversal for k nodes
   - Maintain proper connections between groups

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;
        
        // Check if there are at least k nodes remaining
        while(count < k) {
            if(temp == nullptr) return head;
            temp = temp->next;
            count++;
        }
        
        // Reverse the next k-group recursively
        ListNode* prev = reverseKGroup(temp, k);
        
        // Reverse the current k nodes
        temp = head;
        count = 0;
        while(count < k) {
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
            count++;
        }
        
        return head = prev;
    }
};
