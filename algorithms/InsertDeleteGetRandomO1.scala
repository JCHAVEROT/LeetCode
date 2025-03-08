// File   : InsertDeleteGetRandomO1.scala
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

 import scala.util.Random
 import scala.collection.mutable
 
 // Complexity: O(1) time, O(n) space
 class RandomizedSet {
 
   // As Scala relies a lot on immutability, we use mutable collection objects
   // to achieve the O(1)-complexity.
   private var list: mutable.ListBuffer[Int] = mutable.ListBuffer()
   private var map: mutable.Map[Int, Int] = mutable.Map() 
 
   /**
    * Checks if a value exists in the set.
    * @param val the value to search for
    * @return true if the value is in the set, false otherwise
    */
   def search(value: Int): Boolean = map.contains(value)
 
   /**
    * Inserts a value into the set if it is not already present.
    * @param value the value to insert
    * @return true if the value was inserted, false if it was already present
    */
   def insert(value: Int): Boolean = {
     if (search(value)) return false
 
     list.append(value)  // Add the value to the list
     map.put(value, list.length - 1)  // Store the index of the value in the map
     true
   }
 
   /**
    * Removes a value from the set if it is present.
    * @param value the value to remove
    * @return true if the value was removed, false if it was not found
    */
   def remove(value: Int): Boolean = {
     if (!search(value)) return false 
 
     val index = map(value)  // Retrieve the index of the value to remove
     list(index) = list.last  // Replace the value with the last element
     map.put(list.last, index)  // Update the index of the last element in the map
     list.dropRightInPlace(1)  // Remove the last element from the list
     map.remove(value)  // Remove the value from the map
 
     true
   }
 
   /**
    * Returns a random element from the current set.
    * @return a random value from the set
    */
   def getRandom(): Int = {
     val rand = new Random
     list(rand.nextInt(list.length))
   }
 }
 
 // Your RandomizedSet object will be instantiated and called as such:
 // val obj = new RandomizedSet()
 // val param_1 = obj.insert(value)
 // val param_2 = obj.remove(value)
 // val param_3 = obj.getRandom()
 