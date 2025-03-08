// File   : RotateArray.cpp
// Source : https://leetcode.com/problems/rotate-array
// Author : Jérémy Chaverot
// Date   : 01-03-2025

/********************************************************************************
 * 
 * Given an integer array nums, rotate the array to the right by k steps, 
 * where k is non-negative.
 * 
 ********************************************************************************/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Complexity: O(n) time, O(1) space
    void rotate(vector<int>& nums, int k) {
        // Empty check
        if (nums.empty()) { return; }

        // Take k modulo nums.size in case k is greater than nums.size
        k = k % nums.size();

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};