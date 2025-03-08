// File   : InsertDeleteGetRandomO1.cpp
// Source : https://leetcode.com/problems/insert-delete-getrandom-o1
// Author : Jérémy Chaverot
// Date   : 08-03-2025

/********************************************************************************
 * 
 * Implement the RandomizedSet class:
 * 
 *      RandomizedSet() Initializes the RandomizedSet object.
 * 
 *      bool insert(int val) Inserts an item val into the set if not present. 
 *      Returns true if the item was not present, false otherwise.
 * 
 *      bool remove(int val) Removes an item val from the set if present. 
 *      Returns true if the item was present, false otherwise.
 * 
 *      int getRandom() Returns a random element from the current set of elements 
 *      (it's guaranteed that at least one element exists when this method is 
 *      called). Each element must have the same probability of being returned.
 * 
 * You must implement the functions of the class such that each function works in 
 * average O(1) time complexity.
 * 
 ********************************************************************************/

#include <vector>
#include <stdlib.h>
#include <unordered_map>
using namespace std;

class RandomizedSet {
public:
    // Complexity: O(1) time, O(n) space
    RandomizedSet() {}  // Constructor
    
    bool search(int val) {
        return map.find(val) != map.end();
    }

    bool insert(int val) {
        // Check if the element to insert is already there
        if (search(val)) {
            return false;
        }

        // Add the element to both the vector and the map
        vect.push_back(val);
        map[val] = vect.size()-1;
        
        return true;
    }
    
    bool remove(int val) {
        // Check if the element to remove is indeed already there
        if (!search(val)) {
            return false;
        }

        // Move the last element in vect to replace val
        auto it = map.find(val);
        vect[it->second] = vect.back();

        // Remove the last element in vect
        vect.pop_back();

        // Change the value in the map of the moved element
        map[vect[it->second]] = it->second;

        // Erase the removed value in the map
        map.erase(val);

        return true;
    }
    
    int getRandom() {
        return vect[rand() % vect.size()];
    }

private:
    vector<int> vect;
    unordered_map<int, int> map;
};


/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */