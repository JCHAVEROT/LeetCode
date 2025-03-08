// File   : BestTimeToBuyAndSellStockII.cpp
// Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii
// Author : Jérémy Chaverot
// Date   : 01-03-2025

/********************************************************************************
 * 
 * You are given an integer array prices where prices[i] is the price of a given 
 * stock on the ith day. 
 * 
 * On each day, you may decide to buy and/or sell the stock. You can only hold at 
 * most one share of the stock at any time. However, you can buy it then 
 * immediately sell it on the same day.
 * 
 * Find and return the maximum profit you can achieve.
 * 
 ********************************************************************************/

#include <vector>
using namespace std;

class Solution {
public:
    // Complexity: O(n) time, O(1) space
    int maxProfit(vector<int>& prices) {
        // Empty check
        if (prices.empty()) { return 0; }

        int price = prices[0], profit = 0;

        for (int i = 1; i < prices.size(); i++) {
            // Check if a positive profit is possible
            if (prices[i] > price) {
                profit += prices[i] - price;
            }

            // Update the buy price, as you can now buy multiple times in a row
            price = prices[i];
        }

        return profit;
    }
};