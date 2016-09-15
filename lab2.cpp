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
        cout << "Please enter a day: " << endl;
    }
}

string getAction(int day, int time) {

    srand(day + time);

    return actions[rand() % actions.size()];

}
