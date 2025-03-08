// File   : RemoveDuplicatesFromSortedArrays.cpp
// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-array
// Author : Jérémy Chaverot
// Date   : 01-03-2025

/********************************************************************************
 * 
 * Given an integer array nums sorted in non-decreasing order, remove the 
 * duplicates in-place such that each unique element appears only once. The 
 * relative order of the elements should be kept the same. Then return the number 
 * of unique elements in nums.
 * 
 * Consider the number of unique elements of nums to be k, to get accepted, you 
 * need to do the following things:
 * 
 *      1. Change the array nums such that the first k elements of nums contain the 
 *      unique elements in the order they were present in nums initially. The 
 *      remaining elements of nums are not important as well as the size of nums.
 * 
 *      2. Return k.
 * 
 ********************************************************************************/

#include <vector>
using namespace std;

class Solution {
public:
    // Complexity: O(n) time, O(1) space
    int removeDuplicates(vector<int>& nums) {
        // Empty check
        if (nums.empty()) { return 0; }

        int k = 0;

        for (int num : nums) {
            // Check the duplicate condition and write in the in-place modified array
            if (k == 0 || nums[k-1] != num) {
                nums[k++] = num;
            }
        }

        return k;
    }
};