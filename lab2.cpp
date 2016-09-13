
#include <iostream>
#include <string>

enum Day {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

Day selected_day;

int main() {

    std::cout << "Please input a command. The following are acceptable: "
              << "1. date/time, 2. now, 3. exit" << std::endl;


    std::string selection = "";
    if (!std::getline(std::cin, selection)) {
        std::cout << "Invalid selection, use selection number, or string" << std::endl;
    }

    if(selection == "date/time" || selection == "1") {
        std::cout << "Please enter a day: " << std::endl;

        std::string day_selection = "";
        if(!std::getline(std::cin, day_selection)) {
            std::cout << "Invalid day, try again" << std::endl;
        }
    }
}
