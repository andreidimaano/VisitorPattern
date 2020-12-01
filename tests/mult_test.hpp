#ifndef MULTTESTH
#define MULTTESTH

#include "gtest/gtest.h"
#include "../composite/header/op.hpp"
#include "../composite/header/mult.hpp"

//create iterator
TEST(ClassMultisionTest, MultIterator){
    Base* one = new Op(1);
    Base* two = new Op(2);
    Base* exponent = new Mult(one, two);
    
    EXPECT_TRUE(exponent->create_iterator() != nullptr);
}

//get left
TEST(ClassMultisionTest, MultGetLeft){
    Base* one = new Op(1);
    Base* two = new Op(2);
    Base* exponent = new Mult(one, two);
    
    EXPECT_EQ(exponent->get_left()->evaluate(), one->evaluate());
}

//get right
TEST(ClassMultisionTest, MultGetRight){
    Base* one = new Op(1);
    Base* two = new Op(2);
    Base* exponent = new Mult(one, two);
    
    EXPECT_EQ(exponent->get_right()->evaluate(), two->evaluate());
}


#endif