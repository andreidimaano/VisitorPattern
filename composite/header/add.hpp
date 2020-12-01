#ifndef ADD_H
#define ADD_H

#include "../../base.hpp"
#include "../../iterator.hpp"
#include "../../visitor.hpp"

class Add : public Base
{
	public:
		Add(Base* left, Base* right);
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
