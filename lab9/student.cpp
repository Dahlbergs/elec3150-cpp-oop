#include "student.hpp"

#include <iostream>

Student::Student(std::string name, int age, std::string home_city,
        std::string school, int class_year, int grad_year)
    : Person(name, age, home_city),
      school_(school),
      class_year_(class_year),
      grad_year_(grad_year) {}

Student::Student(Person person, std::string school,
                 int class_year, int grad_year)
    : Person(person),
      school_(school),
      class_year_(class_year),
      grad_year_(grad_year) {}

Student::~Student() {}

std::string Student::GetSchool() { return school_; }
int Student::GetClassYear() { return class_year_; }
int Student::GetGradYear() { return grad_year_; }

void Student::SetSchool(std::string school) { school_ = school; }
void Student::SetClassYear(int class_year) { class_year_ = class_year; }
void Student::SetGradYear(int grad_year) { grad_year_ = grad_year; }

void Student::AddSkill(std::string skill) {
    skills_.push_back(skill);
}

void Student::PrintSkills() {
    std::cout << "Student " << this->GetName() << " Skills:" << std::endl;

    for (auto& skill : skills_) {
        std::cout << skill << std::endl;
    }
}

