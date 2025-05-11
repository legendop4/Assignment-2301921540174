# Maximum Score Words Formed by Letters

**Problem Link**: [1255. Maximum Score Words Formed by Letters - LeetCode](https://leetcode.com/problems/maximum-score-words-formed-by-letters/)  
**Solution Link**: [My Submission](https://leetcode.com/problems/maximum-score-words-formed-by-letters/submissions/1631078040)

## Intuition
The solution uses backtracking to explore all possible combinations of words that can be formed from given letters, calculating the maximum score by:
1. Checking which words can be formed with available letters
2. Recursively trying both including and excluding each valid word
3. Tracking the highest score obtained

## Approach
1. **Letter Counting**:
   - Create frequency count of available letters
2. **Backtracking**:
   - For each word, decide to either:
     - Skip the word (explore other combinations)
     - Use the word (if possible) and recurse
3. **Scoring**:
   - Calculate word scores using given values
   - Maintain maximum score found

## Complexity
- **Time Complexity**: O(2^N × M)  
  - N = number of words (exponential backtracking)
  - M = average word length (for letter checks)
- **Space Complexity**: O(N + L)  
  - N = recursion stack depth
  - L = unique letters (for frequency map)

## Solution Code
```cpp
class Solution {
public:
    bool canform(string w, unordered_map<char, int>& letter_cnt) {
        unordered_map<char, int> word_cnt;
        for (char c : w) word_cnt[c]++;
        for (auto& [ch, count] : word_cnt) {
            if (letter_cnt[ch] < count) return false;
        }
        return true;
    }

    int get_score(string w, vector<int>& score) {
        int res = 0;
        for (char c : w) res += score[c - 'a'];
        return res;
    }

    int backtrack(int i, vector<string>& words, unordered_map<char, int>& letter_cnt, vector<int>& score) {
        if (i == words.size()) return 0;
        
        int res = backtrack(i + 1, words, letter_cnt, score); // Skip
        
        if (canform(words[i], letter_cnt)) {
            for (char c : words[i]) letter_cnt[c]--; // Use letters
            int used = get_score(words[i], score) + backtrack(i + 1, words, letter_cnt, score);
            res = max(res, used);
            for (char c : words[i]) letter_cnt[c]++; // Backtrack
        }
        
        return res;
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char, int> letter_cnt;
        for (char c : letters) letter_cnt[c]++;
        return backtrack(0, words, letter_cnt, score);
    }
};
