// 34. Find First and Last Position of Element in Sorted Array
// Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
// Your algorithm's runtime complexity must be in the order of O(log n).
// If the target is not found in the array, return [-1, -1].

// Example 1:
// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]

// Example 2:
// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]

class Solution {
public:
    int find_first(vector<int>& nums, int target){
        int first = 0;
        int last = nums.size() -  1;
        while(first < last){
            int mid = (first + last) / 2;
            if(nums[mid] >= target){
                last = mid;
            }else{
                first = mid + 1;
            }
        }
        if(nums[first] != target){
            return -1;
        }
        return first;
    }
    int find_last(vector<int>& nums, int target){
        int first = 0;
        int last = nums.size() - 1;
        while(first < last){
            int mid = (first + last + 1) / 2;
            if(nums[mid] <= target){
                first = mid;
            }else{
                last = mid - 1;
            }
        }
        if(nums[last] != target){
            return -1;
        }
        return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        if(nums.empty()){
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        result.push_back(find_first(nums, target));
        result.push_back(find_last(nums, target));
        return result;
    }
};