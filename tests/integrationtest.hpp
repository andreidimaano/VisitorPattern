#ifndef INTEGRATIONTESTH
#define INTEGRATIONTESTH

#include "gtest/gtest.h"
#include "../composite/header/op.hpp"
#include "../composite/header/add.hpp"
#include "../composite/header/div.hpp"
#include "../composite/header/pow.hpp"
#include "../composite/header/sub.hpp"
#include "../composite/header/mult.hpp"
#include "../composite/header/rand.hpp"

//((1 + 2) * 3) / 4
TEST(ClassIntegrationTest, Integration1){
    Base* num1 = new Op(1);
    Base* num2 = new Op(2);
    Base* Add1 = new Add(num1, num2);

    Base* num3 = new Op(3);
    Base* mult1 = new Mult(Add1, num3);

    Base* num4 = new Op(4);
    Base* test = new Div(mult1, num4);

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
    EXPECT_EQ(visitor->add_count(), 1);
    EXPECT_EQ(visitor->div_count(), 1);
    EXPECT_EQ(visitor->div_count(), 1);
}


#endif