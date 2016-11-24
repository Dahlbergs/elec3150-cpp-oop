#pragma once

#include "person.hpp"

#include <vector>

class Student : public Person {
public:
    Student(std::string name, int age, std::string home_city,
            std::string school, int class_year, int grad_year);
    Student(Person person, std::string school, int class_year, int grad_year);
    ~Student();

    std::string GetSchool();
    int GetClassYear();
    int GetGradYear();

    void SetSchool(std::string school);
    void SetClassYear(int class_year);
    void SetGradYear(int grad_year);

    void AddSkill(std::string skill);
    virtual void PrintSkills();

protected:
    std::vector<std::string> skills_;

private:
    std::string school_;
    int class_year_;
    int grad_year_;
};
