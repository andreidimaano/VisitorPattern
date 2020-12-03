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
TEST(ClassSubtractionTest, subGetLeft){
    Base* one = new Op(1);
    Base* two = new Op(2);
    Base* sum = new Sub(one, two);
    
    EXPECT_EQ(sum->get_left()->evaluate(), one->evaluate());
}

//get right
TEST(ClassSubtractionTest, subGetRight){
    Base* one = new Op(1);
    Base* two = new Op(2);
    Base* sum = new Sub(one, two);
    
    EXPECT_EQ(sum->get_right()->evaluate(), two->evaluate());
}

TEST(ClassSubtractionTest, SubVisitor) {
    Base* num1 = new Op(1);
    Base* num2 = new Op(1);
    Base* test = new Sub(num1, num2);
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

    EXPECT_EQ(visitor->op_count(), 3);
    EXPECT_EQ(visitor->sub_count(), 1);
}

TEST(ClassSubtractionTest, SubVisitor2){
    Base* num1 = new Op(1);
    Base* num2 = new Op(2);
    Base* Sub1 = new Sub(num1, num2);

    Base* num3 = new Op(3);
    Base* test = new Sub(Sub1, num3);

    Base* dummyNode = new Op(0);
    Base* dummy = new Sub(test, dummyNode);

    Iterator* it = new PreorderIterator(dummy);

    CountVisitor* visitor = new CountVisitor();
    it->first();
    while(!it->is_done()){
        Base* currentExpression = it->current();
        currentExpression->accept(visitor);
        it->next();
    }

    EXPECT_EQ(visitor->op_count(), 4);
    EXPECT_EQ(visitor->sub_count(), 2);
}

// ((1 / 2) / 3) / 4
TEST(ClassSubtractionTest, SubVisitor3){
    Base* num1 = new Op(1);
    Base* num2 = new Op(2);
    Base* Sub1 = new Sub(num1, num2);

    Base* num3 = new Op(3);
    Base* Sub2 = new Sub(Sub1, num3);

    Base* num4 = new Op(4);
    Base* test = new Sub(Sub2, num4);

    Base* dummyNode = new Op(0);
    Base* dummy = new Sub(test, dummyNode);

    Iterator* it = new PreorderIterator(dummy);

    CountVisitor* visitor = new CountVisitor();
    it->first();
    while(!it->is_done()){
        Base* currentExpression = it->current();
        currentExpression->accept(visitor);
        it->next();
    }

    EXPECT_EQ(visitor->op_count(), 5);
    EXPECT_EQ(visitor->sub_count(), 3);
}
#endif
