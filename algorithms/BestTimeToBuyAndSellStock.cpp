// File   : BestTimeToBuyAndSellStock.cpp
// Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock
// Author : Jérémy Chaverot
// Date   : 01-03-2025

/********************************************************************************
 * 
 * You are given an array prices where prices[i] is the price of a given stock 
 * on the ith day.
 * 
 * You want to maximize your profit by choosing a single day to buy one stock and 
 * choosing a different day in the future to sell that stock.
 * 
 * Return the maximum profit you can achieve from this transaction. If you cannot 
 * achieve any profit, return 0.
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
            // Check if lower price to buy the stock
            if (prices[i] < price) {
                price = prices[i];
            }

            // Update the profit
            profit = max(profit, prices[i] - price);
        }

        return profit;
    }
};