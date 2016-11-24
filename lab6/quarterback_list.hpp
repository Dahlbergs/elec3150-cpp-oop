#include "quarterback_entry.hpp"
#include "linked_list.hpp"

class QuarterbackList {
public:
    QuarterbackList(std::string file);

    void loadList(std::string file);

    void add(QuarterbackEntry entry);
    void add(std::string first_name, std::string last_name, int num_wins, int win_years[4]);

    void remove(std::string firstName, std::string lastName);
    void removeAll();

    void find(std::string first_name, std::string last_name);
    void find(int win_years);

    void print();

private:
    LinkedList<QuarterbackEntry> qb_list;

};
