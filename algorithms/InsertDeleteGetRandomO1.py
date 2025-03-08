# File   : InsertDeleteGetRandomO1.py
# Source : https://leetcode.com/problems/insert-delete-getrandom-o1
# Author : Jérémy Chaverot
# Date   : 08-03-2025

"""

Implement the RandomizedSet class:

     RandomizedSet() Initializes the RandomizedSet object.

     bool insert(int val) Inserts an item val into the set if not present. 
     Returns true if the item was not present, false otherwise.

     bool remove(int val) Removes an item val from the set if present. 
     Returns true if the item was present, false otherwise.

     int getRandom() Returns a random element from the current set of elements 
     (it's guaranteed that at least one element exists when this method is 
     called). Each element must have the same probability of being returned.

You must implement the functions of the class such that each function works in 
average O(1) time complexity.

"""

import random 

# Complexity: O(1) time, O(n) space
class RandomizedSet(object):

    def __init__(self):
        self._lst = list()
        self._idx_map = dict()
        

    def search(self, val: int) -> bool:
        return val in self.idx_map


    def insert(self, val: int) -> bool:
        # Check that val is not alreay in the array
        if self.search(val): 
            return False

        # Append val to the array
        self.lst.append(val)
        # Store the index in the hashmap
        self.idx_map.update({val: len(self.lst) - 1})
        return True
        

    def remove(self, val: int) -> bool:
        # Check that val is already in the array
        if not self.search(val): 
            return False

        # Retrieve the index of val in the list
        index = self.idx_map[val]
       
        # Replace val by the last element in the list
        self.lst[index] = self.lst[-1]

        # Change the index of the previously last element in the hashmap
        self.idx_map[self.lst[-1]] = index

        # Pop the value to remove
        self.lst.pop()
        self.idx_map.pop(val)

        return True
        

    def getRandom(self) -> int:
        return random.choice(self.lst)


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()