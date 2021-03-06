#include "../header/rand.hpp"
#include <ctime>

Rand::Rand() : Base() {
  srand(time(0));
  this->value = rand() % 100;
}

double Rand::evaluate() {
  return this->value;
}

std::string Rand::stringify() {
  return std::to_string(this->value);
}

Iterator* Rand::create_iterator() {
  return new NullIterator(this);
}

Base* Rand::get_left() {
  return nullptr;
}

Base* Rand::get_right() {
  return nullptr;
}

void Rand::accept(CountVisitor* visitor) {
   visitor->visit_rand();
}