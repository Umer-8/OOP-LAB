#include <iostream>
using namespace std;

class Engine
    {
private:
    bool isRunning; 
public:
    Engine() : isRunning(false)
    {
        cout << "Engine constructed." << endl;
    }

    void start() 
        {
        if (!isRunning) 
        {
            isRunning = true;
            cout << "Engine started." << endl;
        } else 
        {
            cout << "Engine is already running." << endl;
        }
    }

    void stop()
        {
        if (isRunning)
        {
            isRunning = false;
            cout << "Engine stopped." << endl;
        } else 
        {
            cout << "Engine is already stopped." << endl;
        }
    }

    ~Engine()
    {
        cout << "Engine destroyed." << endl;
    }
};

class Car {
private:
    Engine e;
public:
    Car()
    {
        cout << "Car constructed." << endl;
    }

    void startcar() 
    {
        e.start();
    }

    void stopCar()
    {
        e.stop();
    }

    ~Car() 
    {
        cout << "Car destroyed." << endl;
    }
};

int main()
{
    Car c;
    c.startcar();
    c.stopCar();
    return 0;
}
