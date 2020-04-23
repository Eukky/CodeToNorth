// 39. Combination Sum
// Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
// The same repeated number may be chosen from candidates unlimited number of times.
// Note:
// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.

// Example 1:
// Input: candidates = [2,3,6,7], target = 7,
// A solution set is:
// [
//   [7],
//   [2,2,3]
// ]

// Example 2:
// Input: candidates = [2,3,5], target = 8,
// A solution set is:
// [
//   [2,2,2,2],
//   [2,3,3],
//   [3,5]
// ]

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> out;
        dfs(candidates, target, 0, out, res);
        return res;
    }
    
    void dfs(vector<int>& candidates, int target, int start, vector<int>& out, vector<vector<int>>& res){
        if(target < 0){
            return;
        }
        if(target == 0){
            res.push_back(out);
        }
        for(int i = start; i < candidates.size(); ++i){
            out.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i, out, res);
            out.pop_back();
        }
    }
};