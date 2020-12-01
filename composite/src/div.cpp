  
#include "../header/div.hpp"

Div::Div(Base* left, Base* right) : Base() {
  this->left = left;
  this->right = right;
}

double Div::evaluate() {
  if(this->right->evaluate() == 0){
    return -1;
  }

  return this->left->evaluate() / this->right->evaluate();
}

std::string Div::stringify() {
  return (this->left->stringify() + " / " + this->right->stringify());
}

Iterator* Div::create_iterator() {
  return new BinaryIterator(this);
}

Base* Div::get_left() {
  return this->left;
}

Base* Div::get_right() {
  return this->right;
}

void Div::accept(CountVisitor* visitor) {
  visitor->visit_op();
}