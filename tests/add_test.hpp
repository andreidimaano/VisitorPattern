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
    Base* test = new Op(1);
    Base* dummyNode = new Op(2);
    Base* dummy = new Add(test, dummyNode);

    Iterator* it = new PreorderIterator(dummy);

    CountVisitor * visitor = new CountVisitor();
    it->first();
    while(!it->is_done()) {
	Base* currentExpression = it->current();
	currentExpression->accept(visitor);
	it->next();
    }

    EXPECT_EQ(visitor->op_count(), 2);
    EXPECT_EQ(visitor->add_count(), 0);
}
#endif //__Add_TEST_HPP__
