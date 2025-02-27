#include<iostream>
using namespace std;

class Engine
{
  private:
  bool isRunning;
  public:
  Engine()
  {
    cout<<"Engine constructed."<<endl;
  }

  void start()
  {
    cout<<"Engine started."<<endl;
  }
  void stop()
  {
    cout<<"Engine stopped."<<endl;
  }
  ~Engine()
  {
    cout<<"Engine destroyed."<<endl;
  }
};
class Car
{ 
    private:
    Engine e;
    public:
    Car()
    {
        cout<<"Car constructed."<<endl;
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
        cout<<"Car destroyed."<<endl;
    }

};
int main()
{
    Car c;
    c.startcar();
    c.stopCar();
    return 0;
}
