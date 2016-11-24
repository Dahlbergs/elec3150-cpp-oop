#include "quarterback_list.hpp"

#include <iostream>
#include <sstream>
#include <fstream>

QuarterbackList::QuarterbackList(std::string file)
    : qb_list() {
    loadList(file);
}

void QuarterbackList::loadList(std::string file) {
    std::ifstream read_file(file);
    std::string line;
    int num_lines = 0;

    if (read_file.is_open()) {
        std::ifstream count_stream(file);
        while (std::getline(count_stream, line)) {
            ++num_lines;
        }
    }

    QuarterbackEntry entries[num_lines];

    if (read_file.is_open()) {
        int counter = 0;
        std::string items[3];

        while (std::getline(read_file, line)) {
            std::istringstream ss(line);

            int line_count = 0;
            while (ss) {
                ss >> items[line_count];
                line_count++;
            }

            for (int i = 0; i < num_lines; i++) {
                if (entries[i].first_name != "") {
                    if (entries[i].first_name == items[0] &&
                        entries[i].last_name == items[1]) {

                        entries[i].numWins++;

                        for(int j = 0; j < 4; j++) {
                            if(entries[i].winYears[j] == 0) {
                                entries[i].winYears[j] = stoi(items[2]);
                                break;
                            }
                        }

                        break;
                    }
                } else {
                    int temp[4] = {0,0,0,0};
                    temp[0] = stoi(items[2]);
                    entries[i] = QuarterbackEntry(items[0], items[1], 1, temp);
                    break;
                }
            }
        }

        for (int i = 0; i < num_lines; i++) {
            if (entries[i].first_name != "" && entries[i].last_name != "") {
                // entries[i].print();
                qb_list.add(entries[i]);
            }
        }

        read_file.close();
    }
}

void QuarterbackList::add(QuarterbackEntry entry) {
    qb_list.add(entry);
}

void QuarterbackList::add(std::string first_name, std::string last_name, int num_wins, int win_years[4]) {
    QuarterbackEntry qb(first_name, last_name, num_wins, win_years);
    this->add(qb);
}

void QuarterbackList::removeAll() {
    qb_list.removeAll();
}

void QuarterbackList::remove(std::string first_name, std::string last_name) {
    for (int i = 0; i < qb_list.size(); i++) {
        QuarterbackEntry elem = qb_list.get();

        if (elem.first_name == first_name &&
            elem.last_name == last_name) {
            qb_list.remove();
        }

        qb_list.next();
    }
}

void QuarterbackList::find(std::string first_name, std::string last_name) {
    for (int i = 0; i < qb_list.size(); i++) {
        QuarterbackEntry elem = qb_list.get();

        if (elem.first_name == first_name &&
            elem.last_name == last_name) {
            qb_list.get().print();
        }

        qb_list.next();
    }
}

void QuarterbackList::find(int win_year) {
    for (int i = 0; i < qb_list.size(); i++) {
        for(int j = 0; j < 4; j++) {\
            if (win_year == qb_list.get().winYears[j]) {
                qb_list.get().print();
                break;
            }
        }
        qb_list.next();
    }
}

void QuarterbackList::print() {
    for (int i = 0; i < qb_list.size(); i++) {
        qb_list.get().print();
        qb_list.next();
    }

    std::cout << "*****" << std::endl;
}
