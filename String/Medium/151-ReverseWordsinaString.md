# Reverse Words in a String

**Problem Link**: [151. Reverse Words in a String - LeetCode](https://leetcode.com/problems/reverse-words-in-a-string/)  
**Solution Link**: [Your Submission](https://leetcode.com/problems/reverse-words-in-a-string/submissions/1627199442)

## Intuition
The solution reverses the order of words in a string by:
1. Extracting individual words while ignoring extra spaces
2. Reversing the collected words
3. Reconstructing the string with single spaces between words

## Approach
1. **Word Extraction**:
   - Iterate through each character
   - Build words when encountering non-space characters
   - Store completed words in a vector when encountering spaces

2. **Word Reversal**:
   - Reverse the order of words using `std::reverse`

3. **String Reconstruction**:
   - Join the reversed words with single spaces
   - Ensure no trailing space at the end

## Complexity
- **Time Complexity**: O(n)  
  - Two passes through the string (extraction + reconstruction)
  - One O(n) reversal operation
- **Space Complexity**: O(n)  
  - Storage for words vector and result string

## Solution Code
```cpp
class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string temp;

        // Extract words
        for (char c : s) {
            if (c != ' ') {
                temp += c;
            } else {
                if (!temp.empty()) {
                    words.push_back(temp);
                    temp.clear();
                }
            }
        }
        // Add last word if exists
        if (!temp.empty()) {
            words.push_back(temp);
        }

        // Reverse word order
        reverse(words.begin(), words.end());

        // Reconstruct string
        string result;
        for (int i = 0; i < words.size(); ++i) {
            result += words[i];
            if (i != words.size() - 1) {
                result += " ";
            }
        }

        return result;
    }
};
