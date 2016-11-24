#include "quarterback_entry.hpp"

QuarterbackEntry::QuarterbackEntry()
    : first_name(""),
      last_name(""),
      numWins(0) {
    for (int i = 0; i < 4; i++) {
        winYears[i] = 0;
    }
}

QuarterbackEntry::QuarterbackEntry(std::string first, std::string last, int wins, int years[4])
    : first_name(first),
      last_name(last),
      numWins(wins) {
    std::copy(years, years + 4, winYears);
}

void QuarterbackEntry::print() {
    std::string wins;


    if (first_name != "" &&
        last_name != "") {
        for (int i = 0; i < 4; i++) {
            std::string temp = std::to_string(winYears[i]);
            wins += (temp + " ");
        }

        std::cout << first_name << " "
                  << last_name << " "
                  << numWins <<" [ "
                  << wins << "]" << std::endl;
    }
}
