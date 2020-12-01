#ifndef POW_H
#define POW_H

#include "../../base.hpp"
#include "../../iterator.hpp"

class Pow : public Base
{
	public:
		Pow(Base* left, Base* right);
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