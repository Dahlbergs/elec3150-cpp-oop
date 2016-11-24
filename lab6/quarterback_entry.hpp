#include <string>
#include <iostream>

struct QuarterbackEntry {
    std::string first_name;
    std::string last_name;

    int numWins;
    int winYears[4];

    QuarterbackEntry();
    QuarterbackEntry(std::string, std::string, int, int years[4]);

    void print();
};
