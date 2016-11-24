#pragma once

#include "student.hpp"

class Intern : public Student {
public:
    Intern(std::string name, int age, std::string home_city,
           std::string school, int class_year, int grad_year,
           std::string company, int weekly_pay, int end_year);

    ~Intern();

    std::string GetCompany();
    int GetWeeklyPay();
    int GetEndYear();

    void SetCompany(std::string company);
    void SetWeeklyPay(int weekly_pay);
    void SetEndYear(int end_year);
    void PrintSkills();

private:
    std::string company_;
    int weekly_pay_;
    int end_year_;
};

