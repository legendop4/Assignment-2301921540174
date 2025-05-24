# Subtract Two Numbers Represented as Linked Lists - Solution

## Problem
Given two numbers represented by linked lists, subtract the smaller number from the larger one and return the result as a linked list.

## Approach
1. **Compare Lengths**: Determine which number is larger by comparing lengths
2. **Handle Equal Lengths**: Compare digit by digit if lengths are equal
3. **Reverse Lists**: Reverse both lists to facilitate subtraction from least significant digit
4. **Subtract Digit-wise**: Perform subtraction with borrow handling
5. **Clean Result**: Remove leading zeros and handle edge cases

## Solution Code
```cpp
class Solution {
public:
    int length(Node* n) {
        int ret = 0;
        while (n) {
            ret++;
            n = n->next;
        }
        return ret;
    }

    Node* reverse(Node* head) {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }

    Node* subLinkedList(Node* l1, Node* l2) {
        int n1 = length(l1);
        int n2 = length(l2);

        if (n1 == 0 && n2 == 0) {
            return new Node(0);
        }

        if (n2 > n1) {
            swap(l1, l2);
        }

        if (n1 == n2) {
            Node* t1 = l1;
            Node* t2 = l2;
            while (t1->data == t2->data) {
                t1 = t1->next;
                t2 = t2->next;

                if (t1 == nullptr) {
                    return new Node(0);
                }
            }

            if (t2->data > t1->data) {
                swap(l1, l2);
            }
        }

        l1 = reverse(l1);
        l2 = reverse(l2);

        Node* res = nullptr;
        Node* t1 = l1;
        Node* t2 = l2;

        while (t1 != nullptr) {
            int small = (t2 != nullptr) ? t2->data : 0;

            if (t1->data < small) {
                if (t1->next) {
                    t1->next->data -= 1;
                }
                t1->data += 10;
            }

            Node* n = new Node(t1->data - small);
            n->next = res;
            res = n;

            t1 = t1->next;
            if (t2 != nullptr) {
                t2 = t2->next;
            }
        }

        while (res != nullptr && res->data == 0) {
            Node* temp = res;
            res = res->next;
            delete temp;
        }

        if (res == nullptr) {
            return new Node(0);
        }

        return res;
    }
};
