// File   : JumpGameII.cpp
// Source : https://leetcode.com/problems/jump-game-ii
// Author : Jérémy Chaverot
// Date   : 08-03-2025

/********************************************************************************
 * 
 * You are given a 0-indexed array of integers nums of length n. You are 
 * initially positioned at nums[0].
 * 
 * Each element nums[i] represents the maximum length of a forward jump from 
 * index i. In other words, if you are at nums[i], you can jump to any 
 * nums[i + j] where:
 * 
 *      1. 0 <= j <= nums[i] and
 *      2. i + j < n
 * 
 * Return the minimum number of jumps to reach nums[n - 1]. The test cases are 
 * generated such that you can reach nums[n - 1].
 * 
 ********************************************************************************/

#include <vector>
using namespace std;

class Solution {
public:
    // Complexity: O(n) time, O(1) space
    int jump(vector<int>& nums) {
        // Empty check
        if (nums.empty()) { return 0; }

        int numberOfJumps = 0, index = 0;

        // Replace nums[i] to hold the max reachable index from a single jump from i
        for (int i = 1; i < nums.size(); i++) {
            nums[i] = max(i + nums[i], nums[i-1]);
        }

        // Accumulate the number of jumps
        while (index < nums.size() - 1) {
            numberOfJumps++;
            index = nums[index];
        }

        return numberOfJumps;
    }
};