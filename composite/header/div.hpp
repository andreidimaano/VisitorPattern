#ifndef DIV_H
#define DIV_H

#include "../../base.hpp"
#include "../../iterator.hpp"

class Div : public Base
{
	public:
		Div(Base* left, Base* right);
		double evaluate() override;
		std::string stringify() override;
        Iterator* create_iterator();
		Base* get_left();
		Base* get_right();
	private:
		Base* left;
		Base* right;
};
#endif