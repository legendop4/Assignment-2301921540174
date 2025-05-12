# Word Break II

**Problem Link**: [140. Word Break II - LeetCode](https://leetcode.com/problems/word-break-ii/)  
**Solution Link**: [My Submission](https://leetcode.com/problems/word-break-ii/submissions/1632197799)

## Intuition
The solution generates all possible sentences formed by breaking the string `s` into words from the dictionary using:
1. Recursive backtracking to explore all valid word breaks
2. Memoization to cache intermediate results
3. Early pruning of invalid paths

## Approach
1. **Initialization**:
   - Convert word dictionary to a set for O(1) lookups
   - Initialize memoization cache

2. **Backtracking**:
   - For each starting index, try all possible end indices
   - If substring is a valid word, recursively process remaining string
   - Combine results with all valid continuations

3. **Memoization**:
   - Cache results by starting index to avoid recomputation
   - Return cached results when available

## Complexity
- **Time Complexity**: O(N³)  
  - N = length of string `s`
  - In worst case, explores all possible breaks with memoization
- **Space Complexity**: O(N³)  
  - Storage for cache and result sentences
  - Recursion stack depth

## Solution Code
```cpp
class Solution {
public:
    vector<string> backtrack(int i, const string& s, unordered_set<string>& wordSet, unordered_map<int, vector<string>>& cache) {
        if (i == s.size()) return {""};
        if (cache.count(i)) return cache[i];
        
        vector<string> res;
        for (int j = i; j < s.size(); j++) {
            string temp = s.substr(i, j - i + 1);
            if (wordSet.find(temp) == wordSet.end()) continue;
            
            vector<string> strings = backtrack(j + 1, s, wordSet, cache);
            if (strings.empty()) continue;
            
            for (string& substr : strings) {
                string sentence = temp;
                if (!substr.empty()) sentence += " " + substr;
                res.push_back(sentence);
            }
        }
        cache[i] = res;
        return res;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        unordered_map<int, vector<string>> cache;
        return backtrack(0, s, wordSet, cache);
    }
};
