// File   : ProductOfArrayExceptSelf.cpp
// Source : https://leetcode.com/problems/product-of-array-except-self
// Author : Jérémy Chaverot
// Date   : 08-03-2025

/********************************************************************************
 * 
 * Given an integer array nums, return an array answer such that answer[i] is 
 * equal to the product of all the elements of nums except nums[i].
 * 
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit 
 * integer.
 * 
 * You must write an algorithm that runs in O(n) time and without using the 
 * division operation.
 * 
 ********************************************************************************/

#include <vector>
using namespace std;

class Solution {
public:
    // Complexity: O(n) time, O(1) extra space
    vector<int> productExceptSelf(vector<int>& nums) {
        // Instanciate the answer array
        int size = nums.size();
        vector<int> answer(size);
        fill(answer.begin(), answer.end(), 1);

        // Compute the prefix products
        int cumulative_product = 1;
        for (int i = 0; i < size; i++) {
            answer[i] *= cumulative_product ;
            cumulative_product *= nums[i];
        }

        // Compute the suffix products
        cumulative_product  = 1;
        for (int i = size-1; i >= 0; i--) {
            answer[i] *= cumulative_product ;
            cumulative_product *= nums[i];
        }

        return answer;
    }
};