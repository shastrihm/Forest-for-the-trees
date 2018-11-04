//name: Hrishee Shastri
#include "htree.cc"

//test trees

void htree1()
{
    // tree pictured in tree.hh (from HW5)
    auto leaf1(std::make_shared<const HTree>(9,0,nullptr,nullptr));
    auto leaf2(std::make_shared<const HTree>(6,0,leaf1,nullptr));
    auto leaf3(std::make_shared<const HTree>(12,0,nullptr,nullptr));
    auto leaf4(std::make_shared<const HTree>(-5,0,leaf3,leaf2));
    auto leaf5(std::make_shared<const HTree>(3,0,nullptr,nullptr));
    auto leaf6(std::make_shared<const HTree>(12,0,leaf5,nullptr));
    HTree tree(126,0,leaf4,leaf6);


    //path_to test cases 
    //(note that case where key  is not in tree is when program exits)
    assert(list_to_string(tree.path_to(126))=="");
    assert(list_to_string(tree.path_to(9))=="LRL");
    assert(list_to_string(tree.path_to(3))=="RL");
    assert(list_to_string(tree.path_to(-5))=="L");
    assert(list_to_string(tree.path_to(12))=="LL");
    assert(list_to_string(tree.path_to(6))=="LR");

    //get child testcases 
    assert((tree.get_child(HTree::Direction::LEFT))==leaf4);
    assert((tree.get_child(HTree::Direction::RIGHT))==leaf6);
    assert((tree.get_child(HTree::Direction::RIGHT))==leaf6);
    assert((*leaf6).get_child(HTree::Direction::RIGHT)==nullptr);
    assert((*leaf6).get_child(HTree::Direction::LEFT)==leaf5);

    std::cout<<"All tests passed in tree 1"<<"\n";
}

void htree2()
{
    // tree with 1 node
    HTree tree(1,2,nullptr,nullptr);
    
    assert(list_to_string(tree.path_to(1))=="");

    assert((tree.get_child(HTree::Direction::LEFT))==nullptr);
    assert((tree.get_child(HTree::Direction::RIGHT))==nullptr);

    std::cout<<"All tests passed in tree 2"<<"\n";
}

void htree3()
{
    // tree with only left branches
    auto leaf1(std::make_shared<const HTree>(9,0,nullptr,nullptr));
    auto leaf2(std::make_shared<const HTree>(6,0,leaf1,nullptr));
    auto leaf3(std::make_shared<const HTree>(12,0,leaf2,nullptr));
    auto leaf4(std::make_shared<const HTree>(-5,0,leaf3,nullptr));
    auto leaf5(std::make_shared<const HTree>(3,0,leaf4,nullptr));
    auto leaf6(std::make_shared<const HTree>(12,0,leaf5,nullptr));
    HTree tree(126,0,leaf6,nullptr);
 
    assert(list_to_string(tree.path_to(126))=="");
    assert(list_to_string(tree.path_to(9))=="LLLLLL");
    assert(list_to_string(tree.path_to(-5))=="LLL");
    assert(list_to_string(tree.path_to(12))=="L");

    assert((tree.get_child(HTree::Direction::LEFT))==leaf6);
    assert((tree.get_child(HTree::Direction::RIGHT))==nullptr);
    assert((*leaf6).get_child(HTree::Direction::LEFT)==leaf5);
    assert((*leaf1).get_child(HTree::Direction::RIGHT)==nullptr);
    assert((*leaf4).get_child(HTree::Direction::LEFT)==leaf3);


    std::cout<<"All tests passed in tree 3"<<"\n";
}

void htree4()
{
    // tree with only right branches
    auto leaf1(std::make_shared<const HTree>(9,0,nullptr,nullptr));
    auto leaf2(std::make_shared<const HTree>(6,0,nullptr,leaf1));
    auto leaf3(std::make_shared<const HTree>(12,0,nullptr,leaf2));
    auto leaf4(std::make_shared<const HTree>(-5,0,nullptr,leaf3));
    auto leaf5(std::make_shared<const HTree>(3,0,nullptr,leaf4));
    auto leaf6(std::make_shared<const HTree>(12,0,nullptr,leaf5));
    HTree tree(126,0,nullptr,leaf6);
 
    assert(list_to_string(tree.path_to(126))=="");
    assert(list_to_string(tree.path_to(9))=="RRRRRR");
    assert(list_to_string(tree.path_to(-5))=="RRR");
    assert(list_to_string(tree.path_to(12))=="R");

    assert((tree.get_child(HTree::Direction::RIGHT))==leaf6);
    assert((tree.get_child(HTree::Direction::LEFT))==nullptr);
    assert((*leaf6).get_child(HTree::Direction::RIGHT)==leaf5);
    assert((*leaf1).get_child(HTree::Direction::LEFT)==nullptr);
    assert((*leaf4).get_child(HTree::Direction::RIGHT)==leaf3);


    std::cout<<"All tests passed in tree 4"<<"\n";   
}

void htree5()
{
    // tree with only 1 left node whose key is also in right nodes
    auto leaf0(std::make_shared<const HTree>(-5,0,nullptr,nullptr));
    auto leaf1(std::make_shared<const HTree>(9,0,nullptr,nullptr));
    auto leaf2(std::make_shared<const HTree>(6,0,nullptr,leaf1));
    auto leaf3(std::make_shared<const HTree>(12,0,nullptr,leaf2));
    auto leaf4(std::make_shared<const HTree>(-5,0,nullptr,leaf3));
    auto leaf5(std::make_shared<const HTree>(3,0,nullptr,leaf4));
    auto leaf6(std::make_shared<const HTree>(12,0,nullptr,leaf5));
    HTree tree(126,0,leaf0,leaf6);
 
    assert(list_to_string(tree.path_to(126))=="");
    assert(list_to_string(tree.path_to(9))=="RRRRRR");
    assert(list_to_string(tree.path_to(-5))=="L");
    assert(list_to_string(tree.path_to(12))=="R");

    assert((tree.get_child(HTree::Direction::RIGHT))==leaf6);
    assert((tree.get_child(HTree::Direction::LEFT))==leaf0);
    assert((*leaf6).get_child(HTree::Direction::RIGHT)==leaf5);
    assert((*leaf1).get_child(HTree::Direction::LEFT)==nullptr);
    assert((*leaf4).get_child(HTree::Direction::RIGHT)==leaf3);


    std::cout<<"All tests passed in tree 5"<<"\n";  
}

void htree6()
{
    // tree with only one right node whose key is also in left nodes
    auto leaf0(std::make_shared<const HTree>(-5,0,nullptr,nullptr));
    auto leaf1(std::make_shared<const HTree>(9,0,nullptr,nullptr));
    auto leaf2(std::make_shared<const HTree>(6,0,leaf1,nullptr));
    auto leaf3(std::make_shared<const HTree>(12,0,leaf2,nullptr));
    auto leaf4(std::make_shared<const HTree>(-5,0,leaf3,nullptr));
    auto leaf5(std::make_shared<const HTree>(3,0,leaf4,nullptr));
    auto leaf6(std::make_shared<const HTree>(12,0,leaf5,nullptr));
    HTree tree(126,0,leaf6,leaf0);
 
    assert(list_to_string(tree.path_to(126))=="");
    assert(list_to_string(tree.path_to(9))=="LLLLLL");
    assert(list_to_string(tree.path_to(-5))=="LLL");
    assert(list_to_string(tree.path_to(12))=="L");

    assert((tree.get_child(HTree::Direction::LEFT))==leaf6);
    assert((tree.get_child(HTree::Direction::RIGHT))==leaf0);
    assert((*leaf6).get_child(HTree::Direction::LEFT)==leaf5);
    assert((*leaf1).get_child(HTree::Direction::RIGHT)==nullptr);
    assert((*leaf4).get_child(HTree::Direction::LEFT)==leaf3);


    std::cout<<"All tests passed in tree 6"<<"\n";
}

void htree7()
{
    // tree with all same keys (same structure as htree1)
    auto leaf1(std::make_shared<const HTree>(9,0,nullptr,nullptr));
    auto leaf2(std::make_shared<const HTree>(9,0,leaf1,nullptr));
    auto leaf3(std::make_shared<const HTree>(9,0,nullptr,nullptr));
    auto leaf4(std::make_shared<const HTree>(9,0,leaf3,leaf2));
    auto leaf5(std::make_shared<const HTree>(9,0,nullptr,nullptr));
    auto leaf6(std::make_shared<const HTree>(9,0,leaf5,nullptr));
    HTree tree(9,0,leaf4,leaf6);

    assert(list_to_string(tree.path_to(9))=="");

    assert((tree.get_child(HTree::Direction::LEFT))==leaf4);
    assert((tree.get_child(HTree::Direction::RIGHT))==leaf6);
    assert((tree.get_child(HTree::Direction::RIGHT))==leaf6);
    assert((*leaf6).get_child(HTree::Direction::RIGHT)==nullptr);
    assert((*leaf6).get_child(HTree::Direction::LEFT)==leaf5);

    std::cout<<"All tests passed in tree 7"<<"\n";
}

void htree8()
{
    // tree with 2 nodes
    auto leaf1(std::make_shared<const HTree>(1,10,nullptr,nullptr));
    HTree tree(10,100,leaf1,nullptr);

    assert(list_to_string(tree.path_to(10))=="");
    assert(list_to_string(tree.path_to(1))=="L");

    assert((tree.get_child(HTree::Direction::LEFT))==leaf1);
    assert((tree.get_child(HTree::Direction::RIGHT))==nullptr);
    assert(((*leaf1).get_child(HTree::Direction::LEFT))==nullptr);
    assert(((*leaf1).get_child(HTree::Direction::RIGHT))==nullptr);

    std::cout<<"All tests passed in tree 8"<<"\n";
}
int main()
{
    htree1();
    htree2();
    htree3();
    htree4();
    htree5();
    htree6();
    htree7();
    htree8();

    //valgrind did not detect any memory mismanagement.

    return 0; 
}