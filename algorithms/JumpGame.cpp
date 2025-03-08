// File   : JumpGame.cpp
// Source : https://leetcode.com/problems/jump-game
// Author : Jérémy Chaverot
// Date   : 01-03-2025

/********************************************************************************
 * 
 * You are given an integer array nums. You are initially positioned at the
 * array's first index, and each element in the array represents your maximum 
 * jump length at that position.
 * 
 * Return true if you can reach the last index, or false otherwise.
 * 
 * Find and return the maximum profit you can achieve.
 * 
 ********************************************************************************/

#include <vector>
using namespace std;

class Solution {
public:
    // Complexity: O(n) time, O(1) space
    bool canJump(vector<int>& nums) {
        // Empty check
        if (nums.empty()) { return false; }

        int totalJumpLength = 0;

        for (int i = 0; i < nums.size(); i++) {
            
            // Return false if the current index cannot be reached
            if (i > totalJumpLength) { return false; }

            // Update the total jump length
            totalJumpLength = max(totalJumpLength, i + nums[i]);
        }
        return true;
    }
};