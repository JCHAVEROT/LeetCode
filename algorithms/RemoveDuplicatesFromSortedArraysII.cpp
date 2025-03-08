// File   : RemoveDuplicatesFromSortedArraysII.cpp
// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii
// Author : Jérémy Chaverot
// Date   : 01-03-2025

/********************************************************************************
 * 
 * Given an integer array nums sorted in non-decreasing order, remove some 
 * duplicates in-place such that each unique element appears at most twice. The 
 * relative order of the elements should be kept the same.
 * 
 * Since it is impossible to change the length of the array in some languages, 
 * you must instead have the result be placed in the first part of the array nums. 
 * More formally, if there are k elements after removing the duplicates, then 
 * the first k elements of nums should hold the final result. It does not matter 
 * what you leave beyond the first k elements.
 * 
 * Return k after placing the final result in the first k slots of nums.
 * 
 * Do not allocate extra space for another array. You must do this by modifying 
 * the input array in-place with O(1) extra memory.
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
            if (k == 0 || k == 1 || nums[k-2] != num) {
                nums[k++] = num;
            }
        }

        return k;
    }
};