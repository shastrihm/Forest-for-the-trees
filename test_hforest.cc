//Name: Hrishee Shastri

#include "hforest.cc"
#include "functional"


// test forests

// test trees from test_htree.cc, with different root values
namespace t1
{

    auto leaf1(std::make_shared<const HTree>(9,0,nullptr,nullptr));
    auto leaf2(std::make_shared<const HTree>(6,0,leaf1,nullptr));
    auto leaf3(std::make_shared<const HTree>(12,0,nullptr,nullptr));
    auto leaf4(std::make_shared<const HTree>(-5,0,leaf3,leaf2));
    auto leaf5(std::make_shared<const HTree>(3,0,nullptr,nullptr));
    auto leaf6(std::make_shared<const HTree>(12,0,leaf5,nullptr));
    auto tree1(std::make_shared<const HTree>(126,1,leaf4,leaf6));
}

namespace t2
{
    auto tree2(std::make_shared<const HTree>(1,2,nullptr,nullptr));
}

namespace t3
{
    auto leaf1(std::make_shared<const HTree>(9,0,nullptr,nullptr));
    auto leaf2(std::make_shared<const HTree>(6,0,leaf1,nullptr));
    auto leaf3(std::make_shared<const HTree>(12,0,leaf2,nullptr));
    auto leaf4(std::make_shared<const HTree>(-5,0,leaf3,nullptr));
    auto leaf5(std::make_shared<const HTree>(3,0,leaf4,nullptr));
    auto leaf6(std::make_shared<const HTree>(12,0,leaf5,nullptr));
    auto tree3(std::make_shared<const HTree>(126,100,leaf6,nullptr));
}

namespace t4
{
    auto leaf1(std::make_shared<const HTree>(9,0,nullptr,nullptr));
    auto leaf2(std::make_shared<const HTree>(6,0,nullptr,leaf1));
    auto leaf3(std::make_shared<const HTree>(12,0,nullptr,leaf2));
    auto leaf4(std::make_shared<const HTree>(-5,0,nullptr,leaf3));
    auto leaf5(std::make_shared<const HTree>(3,0,nullptr,leaf4));
    auto leaf6(std::make_shared<const HTree>(12,0,nullptr,leaf5));
    auto tree4(std::make_shared<const HTree>(126,31,nullptr,leaf6));       
}

namespace t5
{
    auto leaf0(std::make_shared<const HTree>(-5,0,nullptr,nullptr));
    auto leaf1(std::make_shared<const HTree>(9,0,nullptr,nullptr));
    auto leaf2(std::make_shared<const HTree>(6,0,nullptr,leaf1));
    auto leaf3(std::make_shared<const HTree>(12,0,nullptr,leaf2));
    auto leaf4(std::make_shared<const HTree>(-5,0,nullptr,leaf3));
    auto leaf5(std::make_shared<const HTree>(3,0,nullptr,leaf4));
    auto leaf6(std::make_shared<const HTree>(12,0,nullptr,leaf5));
    auto tree5(std::make_shared<const HTree>(126,16,leaf0,leaf6));  
}

namespace t6
{
    auto leaf0(std::make_shared<const HTree>(-5,0,nullptr,nullptr));
    auto leaf1(std::make_shared<const HTree>(9,0,nullptr,nullptr));
    auto leaf2(std::make_shared<const HTree>(6,0,leaf1,nullptr));
    auto leaf3(std::make_shared<const HTree>(12,0,leaf2,nullptr));
    auto leaf4(std::make_shared<const HTree>(-5,0,leaf3,nullptr));
    auto leaf5(std::make_shared<const HTree>(3,0,leaf4,nullptr));
    auto leaf6(std::make_shared<const HTree>(12,0,leaf5,nullptr));
    auto tree6(std::make_shared<const HTree>(126,0,leaf6,leaf0));   
}

namespace t7
{   
    auto leaf1(std::make_shared<const HTree>(9,0,nullptr,nullptr));
    auto leaf2(std::make_shared<const HTree>(9,0,leaf1,nullptr));
    auto leaf3(std::make_shared<const HTree>(9,0,nullptr,nullptr));
    auto leaf4(std::make_shared<const HTree>(9,0,leaf3,leaf2));
    auto leaf5(std::make_shared<const HTree>(9,0,nullptr,nullptr));
    auto leaf6(std::make_shared<const HTree>(9,0,leaf5,nullptr));
    auto tree7(std::make_shared<const HTree>(9,74,leaf4,leaf6));
}

namespace t8
{
    auto leaf1(std::make_shared<const HTree>(1,10,nullptr,nullptr));
    auto tree8(std::make_shared<const HTree>(10,31,leaf1,nullptr)); 
}

namespace t9
{
    auto tree9(std::make_shared<const HTree>(10,80,nullptr,nullptr));
}

// test forest
void hforest1()
{

    HForest test_hforest;
    
    assert(test_hforest.size() == 0);

    test_hforest.add_tree(t1::tree1);
    test_hforest.add_tree(t2::tree2);
    test_hforest.add_tree(t3::tree3);
    test_hforest.add_tree(t4::tree4);

    assert(test_hforest.size() == 4);

    test_hforest.add_tree(t5::tree5);
    test_hforest.add_tree(t6::tree6);
    test_hforest.add_tree(t7::tree7);
    test_hforest.add_tree(t8::tree8);
    test_hforest.add_tree(t9::tree9);

    assert(test_hforest.size() == 9);

    auto f_vec = test_hforest.f_to_vec();
    std::sort(f_vec.begin(),f_vec.end());
    std::vector<int>k ={0,1,2,16,31,31,74,80,100};

    // check that test_hforest contains all trees 
    assert(f_vec == k);

    // tests that pop_tree pops the highest valued tree
    // and returns it

    // root with largest value in forest
    assert(test_hforest.pop_tree() == t3::tree3);
    assert(test_hforest.size() == 8);

    assert(test_hforest.pop_tree() == t9::tree9);
    assert(test_hforest.pop_tree() == t7::tree7);

    // two trees with root values of 31
    auto thirtyone = test_hforest.pop_tree(); 
    assert(thirtyone == t8::tree8 or thirtyone == t4::tree4);

    test_hforest.pop_tree();

    assert(test_hforest.size() == 4);

    assert(test_hforest.pop_tree() == t5::tree5);
    assert(test_hforest.pop_tree() == t2::tree2);
    assert(test_hforest.pop_tree() == t1::tree1);

    // tree with root value 0 is last to be popped
    assert(test_hforest.pop_tree() == t6::tree6);

    assert(test_hforest.size() == 0);
    assert(test_hforest.pop_tree() == nullptr);

    std::cout<<"All tests in hforest1 passed"<<"\n";
}


int main()
{  
    hforest1();
    // valgrind detected no memory mismanagement.
    return 0;
}