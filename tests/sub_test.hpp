#ifndef SUBTESTH
#define SUBTESTH

#include "gtest/gtest.h"
#include "../composite/header/op.hpp"
#include "../composite/header/sub.hpp"

//create iterator
TEST(ClassSubtractionTest, subIterator){
    Base* one = new Op(1);
    Base* two = new Op(2);
    Base* sum = new Sub(one, two);
    
    EXPECT_TRUE(sum->create_iterator() != nullptr);
}

//get left
TEST(ClasssubtractionTest, subGetLeft){
    Base* one = new Op(1);
    Base* two = new Op(2);
    Base* sum = new Sub(one, two);
    
    EXPECT_EQ(sum->get_left()->evaluate(), one->evaluate());
}

//get right
TEST(ClasssubtractionTest, subGetRight){
    Base* one = new Op(1);
    Base* two = new Op(2);
    Base* sum = new Sub(one, two);
    
    EXPECT_EQ(sum->get_right()->evaluate(), two->evaluate());
}


#endif
