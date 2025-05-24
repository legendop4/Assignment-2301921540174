# 1206. Design Skiplist - Solution

## Problem Link
[1206. Design Skiplist - LeetCode](https://leetcode.com/problems/design-skiplist/)

## Solution Link
[My Submission](https://leetcode.com/problems/design-skiplist/submissions/1643290588)

## Approach
The solution implements a basic skiplist using a singly linked list with:
1. **Search**: Linear scan through the list to find target value
2. **Insert**: Maintains sorted order while inserting new nodes
3. **Delete**: Removes nodes while preserving list structure

## Solution Code
```cpp
struct Node {
    int val;
    Node* next;
    Node(int d) {
        val = d;
        next = nullptr;     
    }
};

class Skiplist {
public:
    Node* root;
    
    Skiplist() {
        root = nullptr;
    }
    
    bool search(int target) {
        Node* ref = root;
        while(ref != nullptr) {
            if(ref->val == target) {
                return true;
            }
            ref = ref->next;
        }
        return false;
    }
    
    void add(int num) {
        if(root == nullptr) {
            root = new Node(num);
        } else {
            Node* ref = root;
            if(ref->val > num) {
                Node* nn = new Node(num);
                nn->next = root;
                root = nn;
            } else {
                while(ref->next != nullptr && num >= ref->next->val) {
                    ref = ref->next;
                }
                Node* temp = ref->next;
                Node* mm = new Node(num);
                mm->next = temp;
                ref->next = mm;
            }
        }
    }
    
    bool erase(int num) {
        if (!root) return false;

        if (root->val == num) {
            Node* temp = root;
            root = root->next;
            delete temp;
            return true;
        } else {
            Node* re = root;
            while (re->next != nullptr) {
                if (re->next->val == num) {
                    Node* toDelete = re->next;
                    re->next = re->next->next;
                    delete toDelete;
                    return true;
                }
                re = re->next;
            }
            return false;
        }
    }
};
