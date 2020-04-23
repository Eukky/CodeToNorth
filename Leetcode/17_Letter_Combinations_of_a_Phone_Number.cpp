// 17. Letter Combinations of a Phone Number
// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
// A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

// Example:
// Input: "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

// Note:
// Although the above answer is in lexicographical order, your answer could be in any order you want.

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        string num[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if(digits.size() > 0){
            vector<string> tmp = letterCombinations(digits.substr(1, digits.size() - 1));
            if(tmp.size() == 0){
                tmp.push_back("");
            }
            for(int i = 0; i < num[digits[0] - '0'].size(); i++){
                for(int j = 0; j < tmp.size(); j++){
                    result.push_back(num[digits[0]-'0'][i] + tmp[j]);
                }
            }
        }
        return result;
    }
};

