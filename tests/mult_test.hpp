#ifndef MULTTESTH
#define MULTTESTH

#include "gtest/gtest.h"
#include "../composite/header/op.hpp"
#include "../composite/header/mult.hpp"
#include "../iterator.hpp"
#include "../visitor.hpp"

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

TEST(ClassMultTest, MultVisitTest) {
    Base* test = new Op(1);
    Base* dummyNode = new Op(2);
    Base* dummy = new Mult(test, dummyNode);
    Iterator* it = new PreorderIterator(dummy);

    CountVisitor *visitor = new CountVisitor();
    it->first();
    while(!it->is_done()) {
      Base* currentExpression = it->current();
      currentExpression->accept(visitor);
      it->next();
    }

    EXPECT_EQ(visitor->op_count(), 2);
    EXPECT_EQ(visitor->sub_count(), 0);
}
#endif
