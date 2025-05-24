# 432. All O`one Data Structure - Solution

## Problem Link
[432. All O`one Data Structure - LeetCode](https://leetcode.com/problems/all-oone-data-structure/)

## Solution Link
[My Submission](https://leetcode.com/problems/all-oone-data-structure/submissions/1643283864)

## Approach
The solution implements an all-in-one data structure using:
1. **Doubly Linked List**: To maintain nodes in frequency order
2. **Hash Map**: For O(1) access to nodes
3. **Frequency Maintenance**:
   - `inc()`: Increases key's frequency and moves node forward
   - `dec()`: Decreases key's frequency and moves node backward
   - Nodes are automatically repositioned to maintain sorted order

## Solution Code
```cpp
struct Node {
    string word;
    int freq;
    Node* prev;
    Node* next;
    Node(string k): word(k), freq(1), prev(nullptr), next(nullptr) {}
};

class AllOne {
public:
    Node* head, *tail;
    unordered_map<string, Node*> map;
    
    AllOne() {
        head = new Node("");
        tail = new Node("");
        head->next = tail;
        tail->prev = head;
    }
    
    void movenext(Node* node) {
        Node* ptr = node->next;
        while (ptr != tail && node->freq > ptr->freq) {
            ptr = ptr->next;
        }
        if (ptr != node->next) {
            node->prev->next = node->next;
            node->next->prev = node->prev;

            ptr->prev->next = node;
            node->prev = ptr->prev;
            node->next = ptr;
            ptr->prev = node;
        }
    }
    
    void moveprev(Node* node) {
        Node* ptr = node->prev;
        while (ptr != head && node->freq < ptr->freq) {
            ptr = ptr->prev;
        }
        if (ptr->next != node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;

            node->next = ptr->next;
            node->prev = ptr;
            ptr->next->prev = node;
            ptr->next = node;
        }
    }

    void inc(string key) {
        if (map.find(key) != map.end()) {
            Node* node = map[key];
            node->freq++;
            movenext(node);
        } else {
            Node* node = new Node(key);
            node->next = head->next;
            node->prev = head;
            head->next->prev = node;
            head->next = node;

            map[key] = node;
            movenext(node);
        }
    }
    
    void dec(string key) {
        Node* node = map[key];
        node->freq--;
        moveprev(node);
        if (node->freq == 0) {
            node->next->prev = node->prev;
            node->prev->next = node->next;
            map.erase(key);
            delete node;
        }
    }
    
    string getMaxKey() {
        string ans = "";
        if (tail->prev != head)
            ans = tail->prev->word;
        return ans;
    }
    
    string getMinKey() {
        string ans = "";
        if (head->next != tail)
            ans = head->next->word;
        return ans;
    }
};
