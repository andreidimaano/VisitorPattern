#ifndef POW_H
#define POW_H

#include "../../base.hpp"

class Pow : public Base
{
	public:
		Pow(Base* left, Base* right);
		double evaluate() override;
		std::string stringify() override;
        Iterator* create_iterator();
	private:
		Base* left;
		Base* right;
};
#endif