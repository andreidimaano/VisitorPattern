#ifndef RAND_H
#define RAND_H

#include "../../base.hpp"

class Rand : public Base
{
	public:
		Rand();
		double evaluate() override;
		std::string stringify() override;
        Iterator* create_iterator();
	private:
		double value;
};
#endif