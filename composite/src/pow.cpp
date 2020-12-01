#include "../header/pow.hpp"
#include <math.h> 

Pow::Pow(Base* left, Base* right) : Base() {
  this->left = left;
  this->right = right;
}

double Pow::evaluate() {
  return pow(this->left->evaluate(), this->right->evaluate());
}

std::string Pow::stringify() {
  return (this->left->stringify() + " ** " + this->right->stringify());
}

Iterator* Pow::create_iterator() {
  return new BinaryIterator(this);
}

Base* Pow::get_left() {
  return this->left;
}

Base* Pow::get_right() {
  return this->right;
}

void Pow::accept(CountVisitor* visitor) {
  visitor->visit_pow();
}
