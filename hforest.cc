//Name: Hrishee Shastri

#include "hforest.hh"
#include <iostream>
#include <algorithm>

// compares two trees. Returns true if the root 1 < root 2
bool compare_trees(HTree::tree_ptr_t t1, HTree::tree_ptr_t t2) 
{
    return t1->get_value() < t2->get_value();
}


// Initialize with an empty vector with associated heap
HForest::HForest()
{   
    forest_ = {};
}

// deconstructor 
HForest::~HForest()
{
    for(auto tree : this->forest_)
    {
        tree->HTree::~HTree();
    }
}

// returns a vector of tree root values in forest
std::vector<int> HForest::f_to_vec() const
{
    std::vector<int> tree_vals = {};
    for(auto tree : this->forest_)
    {
        tree_vals.push_back((*tree).get_value());
    }   
    return tree_vals;
}

// prints vector of ints
void print_vector(std::vector<int> v)
{
    for(auto i : v)
    {
        std::cout<< i << " ";
    }

    std::cout<<"\n";
}


// returns how many trees are in the forest
int HForest::size() const
{
    return this->forest_.size();
}


// adds a tree to the forest and then pushes it to the heap
void HForest::add_tree(HTree::tree_ptr_t tree)
{
    this->forest_.push_back(tree);
}


// removes the HTree with the highest value in root node from forest 
// and heap and returns its pointer
HTree::tree_ptr_t HForest::pop_tree()
{
    // first tree in heap will have the highest value in root
    if(this->forest_.empty())
    {
        return nullptr;
    }
    std::make_heap(this->forest_.begin(), this->forest_.end(), compare_trees);
    auto popped_tree = this->forest_.front();
    this->forest_.erase(this->forest_.begin());
    return popped_tree;
}

