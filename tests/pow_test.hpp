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
TEST(ClassPowerTest, PowGetRight){
    Base* one = new Op(1);
    Base* two = new Op(2);
    Base* exponent = new Pow(one, two);
    
    EXPECT_EQ(exponent->get_right()->evaluate(), two->evaluate());
}

TEST(ClassPowisionTest, PowVisitor){
    Base* num1 = new Op(1);
    Base* num2 = new Op(2);
    Base* test = new Pow(num1, num2);

    Base* dummyNode = new Op(0);
    Base* dummy = new Pow(test, dummyNode);

    Iterator* it = new PreorderIterator(dummy);

    CountVisitor* visitor = new CountVisitor();
    it->first();
    while(!it->is_done()){
        Base* currentExpression = it->current();
        currentExpression->accept(visitor);
        it->next();
    }

    EXPECT_EQ(visitor->op_count(), 3);
    EXPECT_EQ(visitor->pow_count(), 1);
}

// (1 / 2) / 3
TEST(ClassPowisionTest, PowVisitor2){
    Base* num1 = new Op(1);
    Base* num2 = new Op(2);
    Base* Pow1 = new Pow(num1, num2);

    Base* num3 = new Op(3);
    Base* test = new Pow(Pow1, num3);

    Base* dummyNode = new Op(0);
    Base* dummy = new Pow(test, dummyNode);

    Iterator* it = new PreorderIterator(dummy);

    CountVisitor* visitor = new CountVisitor();
    it->first();
    while(!it->is_done()){
        Base* currentExpression = it->current();
        currentExpression->accept(visitor);
        it->next();
    }

    EXPECT_EQ(visitor->op_count(), 4);
    EXPECT_EQ(visitor->pow_count(), 2);
}

// ((1 / 2) / 3) / 4
TEST(ClassPowisionTest, PowVisitor3){
    Base* num1 = new Op(1);
    Base* num2 = new Op(2);
    Base* Pow1 = new Pow(num1, num2);

    Base* num3 = new Op(3);
    Base* Pow2 = new Pow(Pow1, num3);

    Base* num4 = new Op(4);
    Base* test = new Pow(Pow2, num4);

    Base* dummyNode = new Op(0);
    Base* dummy = new Pow(test, dummyNode);

    Iterator* it = new PreorderIterator(dummy);

    CountVisitor* visitor = new CountVisitor();
    it->first();
    while(!it->is_done()){
        Base* currentExpression = it->current();
        currentExpression->accept(visitor);
        it->next();
    }

    EXPECT_EQ(visitor->op_count(), 5);
    EXPECT_EQ(visitor->pow_count(), 3);
}


#endif
