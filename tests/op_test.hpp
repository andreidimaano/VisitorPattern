#ifndef OPTESTH
#define OPTESTH

#include "gtest/gtest.h"
#include "../composite/header/op.hpp"

//create iterator
TEST(ClassOperandTest, OpIterator){
    Base* one = new Op(1);
    
    EXPECT_TRUE(one->create_iterator() != nullptr);
}

//get left
TEST(ClassOperandTest, OpGetLeft){
    Base* one = new Op(1);
    
    EXPECT_TRUE(one->get_left() == nullptr);
}

//get right
TEST(ClassOperandTest, OpGetRight){
    Base* one = new Op(1);
    
    EXPECT_TRUE(one->get_right() == nullptr);
}


#endif
