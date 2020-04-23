// 22. Generate Parentheses
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
// For example, given n = 3, a solution set is:
// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        addParenthesis(n, n, "", result);
        return result;
    }
    void addParenthesis(int left, int right, string out, vector<string>& res){
        if(left > right){
            return;
        }
        if(left == 0 && right == 0){
            res.push_back(out);
        }else{
            if(left > 0){
                addParenthesis(left - 1, right, out + "(", res);
            }
            if(right > 0){
                addParenthesis(left, right - 1, out + ")", res);
            }
        }

    }
};