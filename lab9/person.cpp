#include "person.hpp"

Person::Person(std::string name, int age, std::string home_city)
    : name_(name),
      age_(age),
      home_city_(home_city) {}

Person::Person(Person& copy) :
    name_(copy.GetName()),
    age_(copy.GetAge()),
    home_city_(copy.GetHomeCity()) {}

Person::~Person() { }

std::string Person::GetName() { return name_; }
int Person::GetAge() { return age_; }
std::string Person::GetHomeCity() { return home_city_; }

void Person::SetName(std::string name) { name_ = name; }
void Person::SetAge(int age) { age_ = age; }
void Person::SetHomeCity(std::string home_city) { home_city_ = home_city; }
