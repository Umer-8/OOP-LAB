#include <iostream>
using namespace std;

class Glass {
public:
    int liquidlevel;

    void drink(int millimeters) {
        refill();
    }

    void refill() {
        liquidlevel = 200;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        return 1;
    }

    int remaining = 200;
    Glass g;
    g.liquidlevel = 200;

    for (int i = 1; i < argc; i++) {
        int mm = stoi(argv[i]);
        remaining = g.liquidlevel - mm;

        if (remaining < 100) {
            g.drink(remaining);
        }
    }

    return 0;
}
