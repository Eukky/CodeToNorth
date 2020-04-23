// 32. Longest Valid Parentheses
// Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

// Example 1:
// Input: "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()"

// Example 2:
// Input: ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()"

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.size());
        int result = 0;
        for(int i = 1; i < s.size(); ++i){
            if(s[i] == ')'){
                if(s[i - 1] == '('){
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                }else{
                    if(i - dp[i - 1] > 0 and s[i - dp[i - 1] - 1] == '('){
                        dp[i] = dp[i - 1] + (i - dp[i - 1] >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                    }
                }
                result = max(result, dp[i]);
            }
        }
        return result;
    }
};