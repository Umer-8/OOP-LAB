#include <iostream>
#include <unistd.h> 
using namespace std;

class Blend {
public:
    void blend() {
        cout << "Selecting fruits for blending..." << endl;
        for (int i = 0; i < 5; ++i) {
            sleep(1); 
            cout << "Blending..." << endl;
        }
        cout << "Blending complete!" << endl;
    }
};

class Grind {
public:
    void grind() {
        cout << "Starting grinding process..." << endl;
        sleep(5); 
        cout << "Grinding complete!" << endl;
    }
};

class JuiceMaker {
private:
    Blend blender;
    Grind grinder;

public:
    void blendJuice() {
        blender.blend();
    }

    void grindJuice() {
        grinder.grind();
    }
};

int main() {
    JuiceMaker maker;
    cout << "Making juice..." << endl;
    maker.blendJuice();
    maker.grindJuice();
    cout << "Juice is ready!" << endl;
    return 0;
}