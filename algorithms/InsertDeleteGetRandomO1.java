// File   : InsertDeleteGetRandomO1.java
// Source : https://leetcode.com/problems/insert-delete-getrandom-o1
// Author : Jérémy Chaverot
// Date   : 08-03-2025

/**
 * Implement the RandomizedSet class:
 *
 *     RandomizedSet() Initializes the RandomizedSet object.
 *
 *     boolean insert(int val) Inserts an item val into the set if not present. 
 *     Returns true if the item was not present, false otherwise.
 *
 *     boolean remove(int val) Removes an item val from the set if present. 
 *     Returns true if the item was present, false otherwise.
 *
 *     int getRandom() Returns a random element from the current set of elements 
 *     (it's guaranteed that at least one element exists when this method is 
 *     called). Each element must have the same probability of being returned.
 *
 * You must implement the functions of the class such that each function works in 
 * average O(1) time complexity.
 */

import java.util.*;

// Complexity: O(1) time, O(n) space
public class RandomizedSet {
    
    private List<Integer> list; 
    private Map<Integer, Integer> map;

    // Constructor
    public RandomizedSet() {
        list = new ArrayList<>();
        map = new HashMap<>();
    }
    
    /**
     * Checks if a value exists in the set.
     * @param val the value to search for
     * @return true if the value is in the set, false otherwise
     */
    public boolean search(int val) {
        return map.containsKey(val);
    }

    /**
     * Inserts a value into the set if it is not already present.
     * @param val the value to insert
     * @return true if the value was inserted, false if it was already present
     */
    public boolean insert(int val) {
        if (search(val)) return false;
        
        list.add(val); // Add the value to the list
        map.put(val, list.size() - 1); // Store the index of the value in the map
        return true;
    }
    
    /**
     * Removes a value from the set if it is present.
     * @param val the value to remove
     * @return true if the value was removed, false if it was not found
     */
    public boolean remove(int val) {
        if (!search(val)) return false;

        int index = map.get(val); // Retrieve the index of the value to remove
        list.set(index, list.get(list.size() - 1)); // Replace the value with the last element
        map.put(list.get(index), index); // Update the index of the last element in the map
        list.remove(list.size() - 1); // Remove the last element from the list
        map.remove(val); // Remove the value from the map

        return true;
    }
    
    /**
     * Returns a random element from the current set.
     * @return a random value from the set
     */
    public int getRandom() {
        Random rand = new Random();
        return list.get(rand.nextInt(list.size()));
    }
}


// Your RandomizedSet object will be instantiated and called as such:
// RandomizedSet obj = new RandomizedSet();
// boolean param_1 = obj.insert(val);
// boolean param_2 = obj.remove(val);
// int param_3 = obj.getRandom();
