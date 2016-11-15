#include <iostream>
#include <vector>
#include <ctime>

#include <stdlib.h>

std::string getAction(int day, int time);
std::vector<std::string> actions_ =
    { "Running",
      "Slaying dragons",
      "Grabbing cats",
      "Deleting emails",
      "Not having relations with that woman",
      "Running for prez" };

int main() {
    int select = 0;

    while (select == 0) {
        std::cout << "Please input a command." << std::endl;
        std::cout << "1 for date/time, 2 for now, or 3 to exit" << std::endl;
        std::cout << "Selection: ";

        std::string selection;
        if (!std::getline(std::cin, selection)) {
            std::cout << "Invalid input\n" << std::endl;
        } else {
            select = stoi(selection);

            if (select < 1 || select > 3) {
                std::cout << "Invalid number, enter 1-3" << std::endl;
                select = 0;
            }
        }
    }

    if (select == 1) {
        int day = 0;

        std::cout << "Enter a number 1-7 for the corresponding weekday" << std::endl;

        while (day == 0) {
            std::string day_select;

            if (!std::getline(std::cin, day_select)) {
                std::cout << "Invalid input\n" << std::endl;
            } else {
                day = stoi(day_select);

                if (day < 1 || day > 7) {
                    std::cout << "Invalid day, enter 1-7\n" << std::endl;
                    day = 0;
                }
            }
        }

        int time = -1;

        std::cout << "Enter a number 0-23 for the corresponding hour" << std::endl;

        while (time == -1) {
            std::string time_select;

            if (!std::getline(std::cin, time_select)) {
                std::cout << "Invalid input\n" << std::endl;
            } else {
                time = stoi(time_select);

                if (time < 0 || time > 23) {
                    std::cout << "Invalid time, enter 0-23\n" << std::endl;
                    time = -1;
                }
            }
        }

        std::cout << "Action is: " << getAction(day, time) << std::endl;

    } else if (select == 2) {
        std::time_t now = std::time(0);

        std::tm *now_time = localtime(&now);

        std::cout << "Action is: " << getAction(now_time->tm_wday, now_time->tm_hour) << std::endl;
    } else {
        std::cout << "Exiting, goodbye." << std::endl;
    }
}

std::string getAction(int day, int time) {
    srand(day + time);

    return actions_[(rand() % actions_.size())];
}
