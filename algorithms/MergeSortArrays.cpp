// File   : MergeSortArrays.cpp
// Source : https://leetcode.com/problems/merge-sorted-array
// Author : Jérémy Chaverot
// Date   : 01-03-2025

/********************************************************************************
 * 
 * You are given two integer arrays nums1 and nums2, sorted in non-decreasing 
 * order, and two integers m and n, representing the number of elements in nums1 
 * and nums2 respectively.
 * 
 * Merge nums1 and nums2 into a single array sorted in non-decreasing order.
 * 
 * The final sorted array should not be returned by the function, but instead be 
 * stored inside the array nums1. To accommodate this, nums1 has a length 
 * of m + n, where the first m elements denote the elements that should be merged, 
 * and the last n elements are set to 0 and should be ignored. nums2 has a 
 * length of n.
 * 
 ********************************************************************************/

#include <vector>
using namespace std;

class Solution {
public:
    // Complexity: O(m+n) time, O(m) space
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Handle the case where arrays can be empty
        if (m == 0 || n == 0) {
            if (m == 0) {
                nums1 = nums2;
            }
            return;
        }

        // Initialize the counters to iterate over the arrays
        int i = 0, j = 0, k = 0;

        // Deep copy of nums1 as the final sorted array is returned in-place
        // Note: merging backwards could prevent this copy, but more readable
        // this way
        vector<int> copy_nums1 = nums1;

        // While loop condition: end if we went through all numbers
        while (i < m && j < n) {
            if (copy_nums1[i] <= nums2[j]) {
                nums1[k++] = copy_nums1[i++];
            } else {
                nums1[k++] = nums2[j++];
            }
        }

        // If one of the array still has integers left, proceed to add them
        while (i != m) {
            nums1[k++] = copy_nums1[i++];
        }

        while (j != n) {
            nums1[k++] = nums2[j++];
        }
    }
};