// 5. Longest Palindromic Substring
// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

// Example 1:
// Input: "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.

// Example 2:
// Input: "cbbd"
// Output: "bb"

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 0 | s.size() == 1){
            return s;
        }
        vector<vector <bool>> dp(s.size(), vector<bool>(s.size(), false));
        int start = 0;
        int end = 0;
        int max = 1;
        string result;
        for(int i = 0; i < s.size(); i++){
            for(int j = i; j >= 0; j--){
                if(i == j){
                    dp[j][i] = true;
                    continue;
                }
                if(s[i] == s[j]){
                    if(i - j == 1){
                        dp[j][i] = true;
                    }else{
                        dp[j][i] = dp[j+1][i-1];
                    }
                }
                if(dp[j][i] && i - j + 1 > max){
                    start = j;
                    end = i;
                    max = i - j + 1;
                }
            }
        }
        for(int i = start; i <= end; i++){
            result += s[i];
        }
        return result;
    }
};