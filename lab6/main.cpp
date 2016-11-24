#include <iostream>

#include "linked_list.hpp"
#include "quarterback_list.hpp"

int main() {
    std::cout << "Quarterbacks" << std::endl;
    QuarterbackList qb_list("qb_list.txt");
    qb_list.print();

    std::cout << "Eckert-Meyer Receipients" << std::endl;
    QuarterbackList em_list("em_list.txt");
    em_list.print();

    // int temp[] = {0, 0, 0, 0};
    // qb_list.add("Robert", "Griffin III", 0, temp);
    // std::cout << "\n***" << std::endl;
    // qb_list.find(2012);
    // qb_list.find("Kurt", "Warner");

    return 0;
}
