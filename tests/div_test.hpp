#ifndef DIVTESTH
#define DIVTESTH

#include "gtest/gtest.h"
#include "../composite/header/op.hpp"
#include "../composite/header/div.hpp"

//create iterator
TEST(ClassDivisionTest1, DivIterator){
    Base* one = new Op(1);
    Base* two = new Op(2);
    Base* exponent = new Div(one, two);
    
    EXPECT_TRUE(exponent->create_iterator() != nullptr);
}

//get left
TEST(ClassDivisionTest2, DivGetLeft){
    Base* one = new Op(1);
    Base* two = new Op(2);
    Base* exponent = new Div(one, two);
    
    EXPECT_EQ(exponent->get_left()->evaluate(), one->evaluate());
}

//get right
TEST(ClassDivisionTest3, DivIterator){
    Base* one = new Op(1);
    Base* two = new Op(2);
    Base* exponent = new Div(one, two);
    
    EXPECT_EQ(exponent->get_right()->evaluate(), two->evaluate());
}


#endif
