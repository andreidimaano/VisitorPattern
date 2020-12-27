#ifndef MULT_H
#define MULT_H

#include "../../base.hpp"
#include "../../iterator.hpp"
#include "../../visitor.hpp"

class Mult : public Base
{
	public:
		Mult(Base* left, Base* right);
		double evaluate() override;
		std::string stringify() override;
                Iterator* create_iterator();
		Base* get_left();
		Base* get_right();
		virtual void accept(CountVisitor*);
	private:
		Base* left;
		Base* right;
};
#endif
