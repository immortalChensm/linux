#include <iostream>
using namespace std;
#include <vector>
#include <algorithm> //for_each()
//#include<functional>
#include <thread>
#include <mutex>
class classTest
{
public:
    int Dosomething()
    {
        cout << "output from method Dosomething !" << '\n';
        return 0;
    }
public:
    void Start()
    {
        _thread = new std::thread(Dosomething,this);
        _thread->join();
    }
private:
    std::thread* _thread;
};

int main()
{
    classTest t;
    t.Start();
    cout << "main thread"<<endl;
    return 0;
}
