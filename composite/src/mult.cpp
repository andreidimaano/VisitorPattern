#include "../header/mult.hpp"

Mult::Mult(Base* left, Base* right) : Base() {
  this->left = left;
  this->right = right;
}

double Mult::evaluate() {
  return this->left->evaluate() * this->right->evaluate();
}

std::string Mult::stringify() {
  return (this->left->stringify() + " * " + this->right->stringify());
}

Iterator* Mult::create_iterator() {
  return new BinaryIterator(this);
}

Base* Mult::get_left() {
  return this->left;
}

Base* Mult::get_right() {
  return this->right;
}
void Mult::accept(CountVisitor* visitor) {
   visitor->visit_mult();
}
