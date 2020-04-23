// 18. 4Sum
// Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

// Note:
// The solution set must not contain duplicate quadruplets.

// Example:
// Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
// A solution set is:
// [
//   [-1,  0, 0, 1],
//   [-2, -1, 1, 2],
//   [-2,  0, 0, 2]
// ]

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        if(nums.size() < 4){
            return result;
        }
        for(int i = 0; i < nums.size() - 3; i++){
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            for(int j = i + 1; j < nums.size() - 2; j++){
                if(j > i + 1 && nums[j] == nums[j - 1]){
                    continue;
                }
                int a = j + 1;
                int b = nums.size() - 1;
                while(a < b){
                    if(nums[i] + nums[j] + nums[a] + nums[b] > target){
                        b--;
                    }else if(nums[i] + nums[j] + nums[a] + nums[b] < target){
                        a++;
                    }else if(nums[i] + nums[j] + nums[a] + nums[b] == target){
                        result.push_back({nums[i], nums[j], nums[a], nums[b]});
                        while(a < b && nums[a] == nums[a + 1]){
                            a++;
                        }
                        while(a < b && nums[b] == nums[b - 1]){
                            b--;
                        }
                        a++;
                        b--;
                    }
                }
            }
        }
        return result;
    }
};