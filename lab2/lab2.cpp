#include <iostream>
#include <ctime>
#include <vector>
#include <set>

#include <stdlib.h>

using namespace std;

string getAction(int day, int time);
vector<string> actions;

int main() {

    cout << "Please input a command using the corresponding number.\n"
         << "The following are acceptable:\n"
         << "1. date/time\n2. now\n3. exit\nSelection:";

    string selection = "";

    while (!getline(cin, selection) ||
           (selection != "1" &&
            selection != "2" &&
            selection != "3")) {
        cout << "Invalid selection, use selection number" << endl;
        cout << "Selection: ";
    }

    if (selection == "1") {
        cout << "Please enter a day from 1 to 7: " << endl;

        string day_selection = "";
        while (!getline(cin, day_selection) ||
               (selection != "1" &&
                selection != "2" &&
                selection != "3" &&
                selection != "4" &&
                selection != "5" &&
                selection != "6" &&
                selection != "7")) {
            cout << "Invalid selection, use number corresponding to day" << endl;
            cout << "Selection: ";
        }
        int day = stoi(day_selection);

        cout << "Please enter hour time from 0 to 23: ";

        string time_selection = "";

        while (!getline(cin, time_selection) ||
               stoi(time_selection < 0) ||
               stoi(time_selection > 23)) {
            cout << "Invalid selection, use time from 0 to 23:";
        }

        int time = stoi(time_selection);

        cout << "Action is: " << getAction(day, time)
    }
}

string getAction(int day, int time) {
    srand(day + time);

    return actions[rand() % actions.size()];
}
