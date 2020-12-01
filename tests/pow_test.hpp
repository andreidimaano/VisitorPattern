#ifndef POWTESTH
#define POWTESTH

#include "gtest/gtest.h"
#include "../composite/header/op.hpp"
#include "../composite/header/pow.hpp"

//create iterator
TEST(ClassPowerTest, PowIterator){
    Base* one = new Op(1);
    Base* two = new Op(2);
    Base* exponent = new Pow(one, two);
    
    EXPECT_TRUE(exponent->create_iterator() != nullptr);
}

//get left
TEST(ClassPowerTest, PowGetLeft){
    Base* one = new Op(1);
    Base* two = new Op(2);
    Base* exponent = new Pow(one, two);
    
    EXPECT_EQ(exponent->get_left()->evaluate(), one->evaluate());
}

//get right
TEST(ClassPowerTest, PowIterator){
    Base* one = new Op(1);
    Base* two = new Op(2);
    Base* exponent = new Pow(one, two);
    
    EXPECT_EQ(exponent->get_right()->evaluate(), two->evaluate());
}


#endif