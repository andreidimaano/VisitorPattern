#ifndef ADD_H
#define ADD_H

#include "../../base.hpp"

class Add : public Base
{
	public:
		Add(Base* left, Base* right);
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