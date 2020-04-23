// 14. Longest Common Prefix
// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".

// Example 1:
// Input: ["flower","flow","flight"]
// Output: "fl"

// Example 2:
// Input: ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.

// Note:
// All given inputs are in lowercase letters a-z.

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
            return "";
        }
        string compare = strs[0];
        int min = compare.size();
        for(int i = 1; i < strs.size(); i++){
            if(strs[i].size() < min){
                if(strs[i] == ""){
                    return "";
                }
                min = strs[i].size();
            }
            for(int j = 0; j < min; j++){
                if(compare == ""){
                    return "";
                }
                if(compare[j] != strs[i][j]){
                    compare = compare.substr(0, j);
                }
                else if(j == min - 1){
                    compare = compare.substr(0, j+1);
                }
            }
        }
        return compare;
    }
};