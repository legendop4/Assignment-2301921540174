# Word Ladder

**Problem Link**: [127. Word Ladder - LeetCode](https://leetcode.com/problems/word-ladder/)  
**Solution Link**: [My Submission](https://leetcode.com/problems/word-ladder/submissions/1628606670)

## Intuition
The solution uses Breadth-First Search (BFS) to find the shortest transformation sequence from `beginWord` to `endWord` by:
1. Changing one letter at a time
2. Only using words from the given word list
3. Tracking the number of steps taken

## Approach
1. **Initialization**:
   - Queue stores pairs of (current word, step count)
   - Convert word list to a set for O(1) lookups
   - Remove beginWord from set to avoid reuse

2. **BFS Traversal**:
   - Dequeue a word and its step count
   - Return steps if word matches endWord
   - Generate all possible one-letter transformations
   - Enqueue valid transformations found in word list

3. **Termination**:
   - Return 0 if endWord isn't reachable

## Complexity
- **Time Complexity**: O(M² × N)  
  - M: Word length
  - N: Number of words
  - Each word generates M transformations, each checked in O(1) time
- **Space Complexity**: O(N)  
  - Storage for queue and word set

## Solution Code
```cpp
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);
        
        while(!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            if(word == endWord) return steps;
            
            for(int i = 0; i < word.size(); i++) {
                char original = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if(st.find(word) != st.end()) {
                        st.erase(word);
                        q.push({word, steps + 1});
                    }
                    word[i] = original;
                }
            }
        }
        return 0;
    }
};
