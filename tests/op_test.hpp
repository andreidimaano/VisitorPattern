#ifndef OPTESTH
#define OPTESTH

#include "gtest/gtest.h"
#include "../composite/header/op.hpp"
#include "../composite/header/add.hpp"
#include "../iterator.hpp"
#include "../visitor.hpp"

//create iterator
TEST(ClassOperandTest, OpIterator){
    Base* one = new Op(1);
    
    EXPECT_TRUE(one->create_iterator() != nullptr);
}

//get left
TEST(ClassOperandTest, OpGetLeft){
    Base* one = new Op(1);
    
    EXPECT_TRUE(one->get_left() == nullptr);
}

//get right
TEST(ClassOperandTest, OpGetRight){
    Base* one = new Op(1);
    
    EXPECT_TRUE(one->get_right() == nullptr);
}

//
TEST(ClassOperandTest, OpVisitor){
    Base* test = new Op(1);
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

    EXPECT_EQ(visitor->op_count(), 2);
    EXPECT_EQ(visitor->add_count(), 0);
}


#endif
