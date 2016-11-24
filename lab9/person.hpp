#pragma once

#include <string>

class Person {
public:
    Person(std::string name, int age, std::string home_city);
    Person(Person& copy);

    ~Person();

    /* Getters */
    std::string GetName();
    int GetAge();
    std::string GetHomeCity();

    /* Setters */
    void SetName(std::string name);
    void SetAge(int age);
    void SetHomeCity(std::string home_city);

private:
    std::string name_;
    int age_;
    std::string home_city_;

};
