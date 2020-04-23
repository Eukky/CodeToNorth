// 4. Median of Two Sorted Arrays
// There are two sorted arrays nums1 and nums2 of size m and n respectively.
// Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
// You may assume nums1 and nums2 cannot be both empty.

// Example 1:
// nums1 = [1, 3]
// nums2 = [2]
// The median is 2.0

// Example 2:
// nums1 = [1, 2]
// nums2 = [3, 4]
// The median is (2 + 3)/2 = 2.5

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int s1 = nums1.size();
        int s2 = nums2.size();
        int last = 0;
        int lastone = 0;
        int i = 0; 
        int j = 0;
        int k = 0;
        while(i < s1 && j < s2 && k <= (s1 + s2) / 2){
            lastone = last;
            if(nums1[i] <= nums2[j]){
                last = nums1[i++];
            }else{
                last = nums2[j++];
            }
            k++;
        }
        while(k <= (s1 + s2) / 2 && i < s1){
            lastone = last;
            last = nums1[i++];
            k++;
        }
        while(k <= (s1 + s2) / 2 && j < s2){
            lastone = last;
            last = nums2[j++];
            k++;
        }
        if((s1 + s2) % 2 == 0){
            return (last + lastone) / 2.0;
        }else{
            return last;
        }
    }  
};