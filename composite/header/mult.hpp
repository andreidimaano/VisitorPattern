#ifndef MULT_H
#define MULT_H

#include "../../base.hpp"

class Mult : public Base
{
	public:
		Mult(Base* left, Base* right);
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