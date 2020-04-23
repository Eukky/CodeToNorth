// 16. 3Sum Closest
// Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

// Example:
// Given array nums = [-1, 2, 1, -4], and target = 1.

// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int min = INT_MAX;
        int dif = 0;
        int result = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++){
            int j = i + 1;
            int k = nums.size() - 1;
            while(j < k){
                if(nums[i] + nums[j] + nums[k] > target){
                    dif = nums[i] + nums[j] + nums[k] - target;
                    if(dif < min){
                        min = dif;
                        result = nums[i] + nums[j] + nums[k];
                    }
                    k--;
                }else if(nums[i] + nums[j] + nums[k] < target){
                    dif = target - (nums[i] + nums[j] + nums[k]);
                    if(dif < min){
                        min = dif;
                        result = nums[i] + nums[j] + nums[k];
                    }
                    j++;
                }else if(nums[i] + nums[j] + nums[k] == target){
                    return (nums[i] + nums[j] + nums[k]);
                    
                }
            }
        }
        return result;
    }
};