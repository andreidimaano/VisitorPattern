#ifndef ADDTESTH
#define ADDTESTH

#include "gtest/gtest.h"
#include "../composite/header/op.hpp"
#include "../composite/header/add.hpp"

//create iterator
TEST(ClassAdditionTest, AddIterator){
    Base* one = new Op(1);
    Base* two = new Op(2);
    Base* sum = new Add(one, two);
    
    EXPECT_TRUE(sum->create_iterator() != nullptr);
}

//get left
TEST(ClassAdditionTest, AddGetLeft){
    Base* one = new Op(1);
    Base* two = new Op(2);
    Base* sum = new Add(one, two);
    
    EXPECT_EQ(sum->get_left()->evaluate(), one->evaluate());
}

//get right
TEST(ClassAdditionTest, AddIterator){
    Base* one = new Op(1);
    Base* two = new Op(2);
    Base* sum = new Add(one, two);
    
    EXPECT_EQ(sum->get_right()->evaluate(), two->evaluate());
}


#endif