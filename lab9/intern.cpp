#include "intern.hpp"

#include <iostream>

Intern::Intern(std::string name, int age, std::string home_city,
           std::string school, int class_year, int grad_year,
           std::string company, int weekly_pay, int end_year)
    : Student(name, age, home_city, school, class_year, grad_year),
      company_(company),
      weekly_pay_(weekly_pay),
      end_year_(end_year) {}

Intern::~Intern() {}

std::string Intern::GetCompany() { return company_; }
int Intern::GetWeeklyPay() { return weekly_pay_; }
int Intern::GetEndYear() { return end_year_; }

void Intern::SetCompany(std::string company) { company_ = company; }
void Intern::SetWeeklyPay(int weekly_pay) { weekly_pay_ = weekly_pay; }
void Intern::SetEndYear(int end_year) { end_year_ = end_year; }

void Intern::PrintSkills() {
    std::cout << "Intern " << this->GetName() << " Skills:" << std::endl;

    for (auto& skill : skills_) {
        std::cout << skill << std::endl;
    }
}
