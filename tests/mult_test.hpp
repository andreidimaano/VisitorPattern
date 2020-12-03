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

TEST(ClassMultiplicationTest, MultVisitor){
    Base* num1 = new Op(1);
    Base* num2 = new Op(2);
    Base* test = new Mult(num1, num2);

    Base* dummyNode = new Op(0);
    Base* dummy = new Mult(test, dummyNode);

    Iterator* it = new PreorderIterator(dummy);

    CountVisitor* visitor = new CountVisitor();
    it->first();
    while(!it->is_done()){
        Base* currentExpression = it->current();
        currentExpression->accept(visitor);
        it->next();
    }

    EXPECT_EQ(visitor->op_count(), 3);
    EXPECT_EQ(visitor->mult_count(), 1);
}

TEST(ClassMultiplicationTest, MultVisitor2){
    Base* num1 = new Op(1);
    Base* num2 = new Op(2);
    Base* Mult1 = new Mult(num1, num2);

    Base* num3 = new Op(3);
    Base* test = new Mult(Mult1, num3);

    Base* dummyNode = new Op(0);
    Base* dummy = new Mult(test, dummyNode);

    Iterator* it = new PreorderIterator(dummy);

    CountVisitor* visitor = new CountVisitor();
    it->first();
    while(!it->is_done()){
        Base* currentExpression = it->current();
        currentExpression->accept(visitor);
        it->next();
    }

    EXPECT_EQ(visitor->op_count(), 4);
    EXPECT_EQ(visitor->mult_count(), 2);
}

TEST(ClassMultiplicationTest, MultVisitor3){
    Base* num1 = new Op(1);
    Base* num2 = new Op(2);
    Base* Mult1 = new Mult(num1, num2);

    Base* num3 = new Op(3);
    Base* Mult2 = new Mult(Mult1, num3);

    Base* num4 = new Op(4);
    Base* test = new Mult(Mult2, num4);

    Base* dummyNode = new Op(0);
    Base* dummy = new Mult(test, dummyNode);
    Iterator* it = new PreorderIterator(dummy);

    CountVisitor* visitor = new CountVisitor();
    it->first();
    while(!it->is_done()){
        Base* currentExpression = it->current();
        currentExpression->accept(visitor);
        it->next();
    }

    EXPECT_EQ(visitor->op_count(), 5);
    EXPECT_EQ(visitor->mult_count(), 3);
}
#endif
