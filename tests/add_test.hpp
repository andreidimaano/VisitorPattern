#ifndef __CLASS_ADD_TEST__
#define __CLASS_ADD_TEST__

#include "gtest/gtest.h"
#include "../composite/header/op.hpp"
#include "../composite/header/add.hpp"
#include "../iterator.hpp"
#include "../visitor.hpp"


//create iterator
TEST(AdditionTest, AddIterator){
    Base* one = new Op(1);
    Base* two = new Op(2);
    Base* sum = new Add(one, two);
    
    EXPECT_TRUE(sum->create_iterator() != nullptr);
}
//get left
TEST(AdditionTest, AddGetLeft){
      Base* one = new Op(1);
      Base* two = new Op(2);
      Base* sum = new Add(one, two);
    
    EXPECT_EQ(sum->get_left()->evaluate(), one->evaluate());
}

//get right
TEST(AdditionTest, AddGetRight){
    Base* one = new Op(1);
    Base* two = new Op(2);
    Base* sum = new Add(one, two);
    
    EXPECT_EQ(sum->get_right()->evaluate(), two->evaluate());
}

TEST(AdditionTest, AddVisitorTest){
    Base* num1 = new Op(1);
    Base* num2 = new Op(2);
    Base* test = new Add(num1, num2);
    Base* dummyNode = new Op(0);
    Base* dummy = new Add(test, dummyNode);

    Iterator* it = new PreorderIterator(dummy);

    CountVisitor * visitor = new CountVisitor();
    it->first();
    while(!it->is_done()) {
	Base* currentExpression = it->current();
	currentExpression->accept(visitor);
	it->next();
    }

    EXPECT_EQ(visitor->op_count(), 3);
    EXPECT_EQ(visitor->add_count(), 1);
}

TEST(ClassAdditionTest, AddVisitor2){
    Base* num1 = new Op(1);
    Base* num2 = new Op(2);
    Base* Add1 = new Add(num1, num2);

    Base* num3 = new Op(3);
    Base* test = new Add(Add1, num3);

    Base* dummyNode = new Op(0);
    Base* dummy = new Add(test, dummyNode);

    Iterator* it = new PreorderIterator(dummy);

    CountVisitor* visitor = new CountVisitor();
    it->first();
    while(!it->is_done()){
        Base* currentExpression = it->current();
        currentExpression->accept(visitor);
        it->next();
    }

    EXPECT_EQ(visitor->op_count(), 4);
    EXPECT_EQ(visitor->add_count(), 2);
}

// ((1 / 2) / 3) / 4
TEST(ClassAdditionTest, AddVisitor3){
    Base* num1 = new Op(1);
    Base* num2 = new Op(2);
    Base* Add1 = new Add(num1, num2);

    Base* num3 = new Op(3);
    Base* Add2 = new Add(Add1, num3);

    Base* num4 = new Op(4);
    Base* test = new Add(Add2, num4);

    Base* dummyNode = new Op(0);
    Base* dummy = new Add(test, dummyNode);

    Iterator* it = new PreorderIterator(dummy);

    CountVisitor* visitor = new CountVisitor();
    it->first();
    while(!it->is_done()){
        Base* currentExpression = it->current();
        currentExpression->accept(visitor);
        it->next();
    }

    EXPECT_EQ(visitor->op_count(), 5);
    EXPECT_EQ(visitor->add_count(), 3);
}
#endif //__Add_TEST_HPP__
