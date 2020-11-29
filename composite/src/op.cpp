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
  return new BinaryIterator(this);
}

Iterator* Op::create_iterator() {
  return new BinaryIterator(this);
}

Base* Op::get_left() {
  return nullptr;
}

Base* Op::get_right() {
  return nullptr;
}