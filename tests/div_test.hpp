#ifndef DIVTESTH
#define DIVTESTH

#include "gtest/gtest.h"
#include "../composite/header/op.hpp"
#include "../composite/header/div.hpp"

//create iterator
TEST(ClassDivisionTest, DivIterator){
    Base* one = new Op(1);
    Base* two = new Op(2);
    Base* exponent = new Div(one, two);
    
    EXPECT_TRUE(exponent->create_iterator() != nullptr);
}

//get left
TEST(ClassDivisionTest, DivGetLeft){
    Base* one = new Op(1);
    Base* two = new Op(2);
    Base* exponent = new Div(one, two);
    
    EXPECT_EQ(exponent->get_left()->evaluate(), one->evaluate());
}

//get right
TEST(ClassDivisionTest, DivGetRight){
    Base* one = new Op(1);
    Base* two = new Op(2);
    Base* exponent = new Div(one, two);
    
    EXPECT_EQ(exponent->get_right()->evaluate(), two->evaluate());
}

TEST(ClassDivisionTest, OpVisitor){
    Base* num1 = new Op(1);
    Base* num2 = new Op(2);
    Base* test = new Div(num1, num2);

    Base* dummyNode = new Op(0);
    Base* dummy = new Div(test, dummyNode);

    Iterator* it = new PreorderIterator(dummy);

    CountVisitor* visitor = new CountVisitor();
    it->first();
    while(!it->is_done()){
        Base* currentExpression = it->current();
        currentExpression->accept(visitor);
        it->next();
    }

    EXPECT_EQ(visitor->op_count(), 3);
    EXPECT_EQ(visitor->div_count(), 1);
}

// (1 / 2) / 3
TEST(ClassDivisionTest, OpVisitor2){
    Base* num1 = new Op(1);
    Base* num2 = new Op(2);
    Base* div1 = new Div(num1, num2);

    Base* num3 = new Op(3);
    Base* test = new Div(div1, num3);

    Base* dummyNode = new Op(0);
    Base* dummy = new Div(test, dummyNode);

    Iterator* it = new PreorderIterator(dummy);

    CountVisitor* visitor = new CountVisitor();
    it->first();
    while(!it->is_done()){
        Base* currentExpression = it->current();
        currentExpression->accept(visitor);
        it->next();
    }

    EXPECT_EQ(visitor->op_count(), 4);
    EXPECT_EQ(visitor->div_count(), 2);
}

// ((1 / 2) / 3) / 4
TEST(ClassDivisionTest, OpVisitor3){
    Base* num1 = new Op(1);
    Base* num2 = new Op(2);
    Base* div1 = new Div(num1, num2);

    Base* num3 = new Op(3);
    Base* div2 = new Div(div1, num3);

    Base* num4 = new Op(4);
    Base* test = new Div(div2, num4);

    Base* dummyNode = new Op(0);
    Base* dummy = new Div(test, dummyNode);

    Iterator* it = new PreorderIterator(dummy);

    CountVisitor* visitor = new CountVisitor();
    it->first();
    while(!it->is_done()){
        Base* currentExpression = it->current();
        currentExpression->accept(visitor);
        it->next();
    }

    EXPECT_EQ(visitor->op_count(), 5);
    EXPECT_EQ(visitor->div_count(), 3);
}

#endif
