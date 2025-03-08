// File   : H-Index.cpp
// Source : https://leetcode.com/problems/h-index
// Author : Jérémy Chaverot
// Date   : 08-03-2025

/********************************************************************************
 * 
 * Given an array of integers citations where citations[i] is the number of 
 * citations a researcher received for their ith paper, return the researcher's 
 * h-index. 
 * 
 * According to the definition of h-index on Wikipedia: The h-index is defined as 
 * the maximum value of h such that the given researcher has published at least h 
 * papers that have each been cited at least h times.
 * 
 ********************************************************************************/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Complexity: O(n log n) time, O(1) space
    int hIndex(vector<int>& citations) {

        // Sort the citations array in descending order 
        sort(citations.rbegin(), citations.rend());

        // Find the maximum h-index
        for (int h = 0; h < citations.size(); h++) {
            if (citations[h] < h+1) {
                return h;
            } 
        }

        return citations.size();
    }
};