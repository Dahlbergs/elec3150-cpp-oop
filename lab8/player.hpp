#include <string>

class Player {
public:
    Player(std::string name, int number, int two_accuracy, int three_accuracy);

    int takeShot(int shot_type);
    void setTwoPointAccuracy(int acc);
    void setThreePointAccuracy(int acc);
private:
    std::string name;
    int number;
    int two_accuracy;
    int three_accuracy;
};
