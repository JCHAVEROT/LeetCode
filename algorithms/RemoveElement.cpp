// File   : RemoveElement.cpp
// Source : https://leetcode.com/problems/remove-element
// Author : Jérémy Chaverot
// Date   : 01-03-2025

/********************************************************************************
 * 
 * Given an integer array nums and an integer val, remove all occurrences of val 
 * in nums in-place. The order of the elements may be changed. Then return the 
 * number of elements in nums which are not equal to val.
 * 
 * Consider the number of elements in nums which are not equal to val be k, to 
 * get accepted, you need to do the following things:
 * 
 *      1. Change the array nums such that the first k elements of nums contain 
 *      the elements which are not equal to val. The remaining elements of nums 
 *      are not important as well as the size of nums. 
 * 
 *      2. Return k.
 * 
 ********************************************************************************/

#include <vector>
using namespace std;

class Solution {
public:
    // Complexity: O(n²) time, O(1) space
    int removeElement(vector<int>& nums, int val) {
        // Empty check
        if (nums.empty()) { return 0; }

        int size = nums.size();
        int k = 0;

        // Run trough the array backwards
        for (int i = size-1; i >= 0; i--) {

            // Check the remove condition
            if (nums[i] == val) {

                // Shift values in the array
                for (int j = i; j < size-1; j++) {
                    nums[j] = nums[j+1];
                }

            // Increment the counter k otherwise 
            } else {
                k++;
            }
        }

        return k;
    }
};