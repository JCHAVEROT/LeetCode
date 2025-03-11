// File   : GasStation.cpp
// Source : https://leetcode.com/problems/gas-station
// Author : Jérémy Chaverot
// Date   : 11-03-2025

/********************************************************************************
 * 
 * There are n gas stations along a circular route, where the amount of gas at 
 * the ith station is gas[i].
 * 
 * You have a car with an unlimited gas tank and it costs cost[i] of gas to travel 
 * from the ith station to its next (i + 1)th station. You begin the journey with 
 * an empty tank at one of the gas stations.
 * 
 * Given two integer arrays gas and cost, return the starting gas station's index 
 * if you can travel around the circuit once in the clockwise direction, otherwise 
 * return -1. If there exists a solution, it is guaranteed to be unique.
 * 
 ********************************************************************************/

#include <vector>
using namespace std;

class Solution {
public:
    // Complexity: O(n) time, O(1) space
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // Check if a complete circuit is possible
        int totalGas = 0, totalCost = 0;
        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
        }
        if (totalGas < totalCost) {
            return -1;
        }

        // Find the start station
        int current_gas = 0, start_station = 0;
        for (int i = 0; i < gas.size(); i++) {
            current_gas += gas[i] - cost[i];
            if (current_gas < 0) {
                current_gas = 0;
                start_station = i + 1;  // Skip all stations up to and including i
            }
        }

        return start_station;
    }
};