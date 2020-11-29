#ifndef __OP_HPP__
#define __OP_HPP__

#include "../../base.hpp"

class Op : public Base
{
	public:
		Op(double value);
		virtual double evaluate();
		virtual std::string stringify();
        Iterator* create_iterator();
	private:
		double value;
};
#endif //__OP_HPP__