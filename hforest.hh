/*
 * HForest: a class to represent a collection of independent HTrees.
    Each HTree in the collection is the root of its own tree.
 */
//Name: Hrishee Shastri

#pragma once
#include "htree.cc"
#include <vector>

class HForest{
 public:
    using forest_t = std::vector<HTree::tree_ptr_t>;
 private:
    forest_t forest_;    
 public:
    HForest();
    ~HForest();

    // returns a vector of tree root values in forest
    std::vector<int> f_to_vec() const;
    

    // returns how many trees are in the forest
    int size() const;

    // adds a tree to the forest
    void add_tree(HTree::tree_ptr_t tree);

    // removes the HTree with the highest value in root node from forest 
    // and returns its pointer
    HTree::tree_ptr_t pop_tree();
};


