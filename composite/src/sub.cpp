#include "../header/sub.hpp"

Sub::Sub(Base* left, Base* right) : Base() {
  this->left = left;
  this->right = right;
}

double Sub::evaluate() {
  return this->left->evaluate() - this->right->evaluate();
}

std::string Sub::stringify() {
  return (this->left->stringify() + " - " + this->right->stringify());
}

Iterator* Sub::create_iterator() {
  return new BinaryIterator(this);
}

Base* Sub::get_left() {
  return this->left;
}

Base* Sub::get_right() {
  return this->right;
}