#ifndef SUBTESTH
#define SUBTESTH

#include "gtest/gtest.h"
#include "../composite/header/op.hpp"
#include "../composite/header/sub.hpp"
#include "../iterator.hpp"
#include "../visitor.hpp"


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

TEST(ClasssubtractionTest, SubVisitor) {
    Base* test = new Op(1);
    Base* dummyNode = new Op(2);
    Base* dummy = new Sub(test, dummyNode);

    Iterator* it = new PreorderIterator(dummy);

    CountVisitor *visitor = new CountVisitor();
    it->first();
    while(!it->is_done()){
         Base* currentExpression = it->current();
	 currentExpression->accept(visitor);
	 it->next();
    }

    EXPECT_EQ(visitor->op_count(), 2);
    EXPECT_EQ(visitor->sub_count(), 0);
}
#endif
