# Integer to English Words

**Problem Link**: [273. Integer to English Words - LeetCode](https://leetcode.com/problems/integer-to-english-words/)  
**Solution Link**: [Your Submission](https://leetcode.com/problems/integer-to-english-words/submissions/1629497424)

## Intuition
The solution converts a non-negative integer to its English words representation by:
1. Breaking down the number into billion, million, thousand, and hundred components
2. Processing each component separately using helper functions
3. Combining the results with proper spacing and units

## Approach
1. **Initialization**:
   - Dictionaries for numbers under 20 and tens (20-90)
   - Special case handling for zero

2. **Component Processing**:
   - Handle billions, millions, thousands sequentially
   - Use modulo to extract remaining value after each unit

3. **Helper Function**:
   - `getHundred()` processes 3-digit numbers
   - Handles hundreds, tens, and ones places

## Complexity
- **Time Complexity**: O(1)  
  - Fixed number of operations regardless of input size
  - Maximum 4 main components (billion, million, etc.)
- **Space Complexity**: O(1)  
  - Constant space for dictionaries
  - Output string grows linearly but bounded by fixed patterns

## Solution Code
```cpp
class Solution {
public:
    unordered_map<int,string> ones = {
        {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"},
        {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"},
        {9, "Nine"}, {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"},
        {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"},
        {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"},
        {19, "Nineteen"}
    };
    unordered_map<int, string> tens = {
        {2, "Twenty"}, {3, "Thirty"}, {4, "Forty"},
        {5, "Fifty"}, {6, "Sixty"}, {7, "Seventy"},
        {8, "Eighty"}, {9, "Ninety"}
    };

    string numberToWords(int num) {
        if (num == 0) return "Zero";
        
        string answer = "";
        if(num >= 1e9) {
            int n = num/1e9;
            answer += getHundred(n) + " Billion";
            num %= 1000000000;
        }
        if(num >= 1e6) {
            int n = num/1e6;
            answer += getHundred(n) + " Million";
            num %= 1000000;
        }
        if(num >= 1e3) {
            int n = num/1e3;
            answer += getHundred(n) + " Thousand";
            num %= 1000;
        }
        answer += getHundred(num);
        return answer.substr(1); // Remove leading space
    }

    string getHundred(int num) {
        string str = "";
        if(num >= 100) {
            int n = num/100;
            str += " " + ones[n] + " Hundred";
            num %= 100;
        }
        if(num >= 20) {
            int n = num/10;
            str += " " + tens[n];
            num %= 10;
        }
        if(num > 0) {
            str += " " + ones[num];
        }
        return str;
    }
};
