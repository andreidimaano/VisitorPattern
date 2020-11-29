#ifndef SUB_H
#define DUB_H

#include "../../base.hpp"

class Sub : public Base
{
	public:
		Sub();
		Sub(Base* left, Base* right);
		double evaluate() override;
		std::string stringify() override;
        Iterator* create_iterator();
		Base* get_left();
		Base* get_right();
	private:
		Base* left; 
		Base* right;
};
#endif#ifndef SUB_H
#define DUB_H