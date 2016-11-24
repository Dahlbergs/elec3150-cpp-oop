#include "person.hpp"
#include "student.hpp"
#include "intern.hpp"

int main() {
    Person sam("Sam", 22, "Hubbardston");

    Student john("John", 18, "Los Angeles", "Cal-Tech", 2016, 2020);

    john.AddSkill("Data Structures");
    john.AddSkill("Calculus");

    john.PrintSkills();

    Intern jeff("Jeff", 25, "Boston", "Wentworth", 2014, 2018,
                "Draper Labs", 22, 2017);

    jeff.AddSkill("C++");
    jeff.AddSkill("Circuit Analysis");

    jeff.PrintSkills();
}
