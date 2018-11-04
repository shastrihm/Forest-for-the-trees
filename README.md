# Forest-for-the-trees
Simple forest and tree data structures implemented with C++ classes.

# How to build
Just use the Makefile.
>make

# Design choices
The HTree class provides the blueprint for a simple tree data structure 
with some path traversal algorithms implemented in htree.cc.

A forest in HForest is represented as a std::vector of tree pointers, with
each tree pointer pointing to the root node of an HTree. The underlying 
implementation of the forest is a heap, using std::make_heap, so that 
HForest::pop_tree can perform the operation of finding
the highest valued root node in logarithmic time. 


