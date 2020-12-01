#include "../header/add.hpp"

Add::Add(Base* left, Base* right) : Base() {
  this->left = left;
  this->right = right;
}

double Add::evaluate() {
  return this->left->evaluate() + this->right->evaluate();
}

std::string Add::stringify() {
  return (this->left->stringify() + " + " + this->right->stringify());
}

Iterator* Add::create_iterator() {
  return new BinaryIterator(this);
}

Base* Add::get_left() {
  return this->left;
}

Base* Add::get_right() {
  return this->right;
}

void Add::accept(CountVisitor* visitor) {
  visitor->visit_add();
}