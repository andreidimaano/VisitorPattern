#include "../header/op.hpp"

Op::Op(double val) : Base() {
	this->value = val;
}

double Op::evaluate() {
	return this->value;
}

std::string Op::stringify() {
	return std::to_string(this->value);
}

Iterator* Op::create_iterator() {
  return new NullIterator(this);
}

Base* Op::get_left() {
  return nullptr;
}

Base* Op::get_right() {
  return nullptr;
}

void Op::accept(CountVisitor* visitor) {
   visitor->visit_op();
}
