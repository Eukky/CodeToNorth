// 33. Search in Rotated Sorted Array
// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
// (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
// You are given a target value to search. If found in the array return its index, otherwise return -1.
// You may assume no duplicate exists in the array.
// Your algorithm's runtime complexity must be in the order of O(log n).

// Example 1:
// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4

// Example 2:
// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int first = 0;
        int last = nums.size() - 1;
        while(first <= last){
            int mid = (first + last) / 2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] < nums[last]){
                if(target > nums[mid] && target <= nums[last]){
                    first = mid + 1;
                }else{
                    last = mid - 1;
                }
            }else{
                if(target < nums[mid] && target >= nums[first]){
                    last = mid - 1;
                }else{
                    first = mid + 1;
                }
            }
        }
        return -1;
    }
};