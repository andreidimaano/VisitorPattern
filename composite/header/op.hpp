#ifndef __OP_HPP__
#define __OP_HPP__

#include "../../base.hpp"
#include "../../iterator.hpp"
#include "../../visitor.hpp"

class Op : public Base
{
	public:
		Op(double value);
		virtual double evaluate();
		virtual std::string stringify();
        Iterator* create_iterator();
		Base* get_left();
		Base* get_right();
		virtual void accept(CountVisitor*);
	private:
		double value;
};
#endif //__OP_HPP__
