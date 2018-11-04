//Name: Hrishee Shastri

#include "htree.hh"
#include <iostream>
#include <assert.h>
#include <string>
// Initialize with a key and a value and children:
HTree::HTree(int key, 
             uint64_t value, 
             HTree::tree_ptr_t left, 
             HTree::tree_ptr_t right)
{   
    key_ = key;
    value_ = value;
    left_ = left;
    right_ = right;
}


// deconstructor    
HTree::~HTree()
{
    if(this->left_ != nullptr)
    {   
        this->left_->~HTree();        
    }
    if(this->right_ != nullptr)
    {
        this->right_->~HTree();
    }
}

//get key at current node
int HTree::get_key() const
{
    return this->key_;
}

//get value at current node
uint64_t HTree::get_value() const
{
    return this->value_;
}

HTree::tree_ptr_t HTree::get_child(Direction dir) const
{
    switch(dir)
    {
        case Direction::LEFT:
            return this->left_;
            break;
        case Direction::RIGHT:
            return this->right_;
            break;
    }

    return nullptr;
}

bool HTree::is_key_in_tree(int key) const
{   
    if(this->key_ == key)
    {
        return true;
    }
    if(this->left_ != nullptr and this->right_ != nullptr)
    {
        return this->left_->is_key_in_tree(key) or this->right_->is_key_in_tree(key);
    }
    if(this->left_ != nullptr)
    {
        return this->left_->is_key_in_tree(key);
    }
    if(this->right_ != nullptr)
    {   
        return this->right_->is_key_in_tree(key);
    }

    return false;
}

// helper function that concatenates two lists
static HTree::path_t concatenate(HTree::path_t path1, HTree::path_t path2)
{
    for(auto i : path2)
    {
        path1.push_back(i);
    }

    return path1;
}

//print list
void print_list(HTree::path_t path)
{
    for(auto i : path)
    {
        if(i == HTree::Direction::LEFT)
        {
            std::cout<<"LEFT"<<" ";
        }
        if(i == HTree::Direction::RIGHT)
        {
            std::cout<<"RIGHT"<<" ";
        }
    }
    std::cout<<"\n";
}

std::string list_to_string(HTree::path_t path)
{   
    std::string str_path = "";
    for(auto i : path)
    {
        if(i == HTree::Direction::LEFT)
        {
            str_path+="L";
        }
        if(i == HTree::Direction::RIGHT)
        {
            str_path+="R";
        }
    }
    return str_path;
}

HTree::path_t HTree::path_to(int key) const
{
    assert(this->HTree::is_key_in_tree(key));

    if(this->key_ == key)
    {
        return std::list<HTree::Direction>();
    }
    else if(this->left_ != nullptr and this->left_->HTree::is_key_in_tree(key))
    {
        std::list<HTree::Direction> l = {Direction::LEFT};
        return concatenate(l, this->left_->path_to(key)); 
    }
    else
    {
        std::list<HTree::Direction> r = {Direction::RIGHT}; 
        return concatenate(r, this->right_->path_to(key));
    }
}


