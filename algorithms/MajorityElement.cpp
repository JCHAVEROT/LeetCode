// File   : MajorityElement.cpp
// Source : https://leetcode.com/problems/majority-element
// Author : Jérémy Chaverot
// Date   : 01-03-2025

/********************************************************************************
 * 
 * Given an array nums of size n, return the majority element.
 * 
 * The majority element is the element that appears more than ⌊n / 2⌋ times. 
 * You may assume that the majority element always exists in the array.
 * 
 ********************************************************************************/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Complexity: O(n) time, O(n) space
    int majorityElement(vector<int>& nums) {
        // Empty check
        if (nums.empty()) { return 0; }
        
        // Unordered map to keep track of the frequencies
        int n = nums.size();
        unordered_map<int, int> countMap;

        // Retrieve frequencies
        for (int num : nums) {
            countMap[num]++;

            // Check if current element count exceeds n / 2
            if (countMap[num] > n / 2) {
                return num;
            }
        }

        // If no majority element found, return error code
        return -1;
    }
};