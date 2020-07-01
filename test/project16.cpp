//
// Created by Administrator on 2020/6/23.
//

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

using namespace std;


class mobile
{
public:
    mobile(string brand, string name) :_brand(brand), _name(name) {};
    ~mobile(){

        //delete _brand;
    }
public:
    string _brand;
    string _name;
};

class Worker
{
public:
    Worker(string name) :_userName(name) {
        _assembleCount = 0;
    }
    void assembleMobile()
    {
        while (1) {

            if (!_factoryMobiles.empty()) {
                for (auto mobile : _factoryMobiles) {

                    std::lock_guard<mutex> lock(_mutx);
                    _workerMobiles.push_back(mobile);
                }
                _factoryMobiles.clear();
            }

            if (_workerMobiles.empty()) {
                cout << _userName << " no mobile component to assemble" << endl;
                std::chrono::milliseconds t(1);
                std::this_thread::sleep_for(t);
                continue;
            }

            for(int m= _workerMobiles.size()-1;m>=0;m--){

                cout << _userName << " is assembling " << _workerMobiles[m]->_brand << " machine" << endl;

                auto it = _workerMobiles.begin()+m;
                if (it != _workerMobiles.end()) {
                    delete _workerMobiles[m];
                    _workerMobiles.erase(it);
                }

                cout<<"remain "<<_workerMobiles.size()<<endl;
            }
        }
    }
    void Start()
    {

        _tHread = thread(&Worker::assembleMobile, this);
        _tHread.detach();
    }

    int getMobileCount()
    {
        return (int)_factoryMobiles.size() + (int)_workerMobiles.size();
    }

    void addMobile(mobile* m)
    {
        _factoryMobiles.push_back(m);
    }
public:
    std::thread _tHread;
    string _userName;
    vector<mobile*> _factoryMobiles;
    vector<mobile*> _workerMobiles;
    int _assembleCount;
    std::mutex _mutx;
};


class boss
{
public:
    void workerStart()
    {

        string userName[] = { "jack","tom","lucy","tony" ,"jack","tom","lucy","tony"};
        for (int i = 0; i < 3; i++) {

            Worker* worker = new Worker(userName[i]);
            _workers.push_back(worker);
            worker->Start();
        }
    }
    void OnAssembleEvent()
    {

    }
    void Run()
    {
        string mobiles[] = { "apple","huawei","nokia","oppo","vivo","xiaomi","rasberry" };
        while (1) {

            for (string b : mobiles) {
                mobile* m = new mobile(b, (char*)"mobile");

                auto minWorker = _workers[0];
                for (auto worker : _workers) {

                    //if (minWorker->getMobileCount() > worker->getMobileCount()) {
                    minWorker = worker;
                    //}
                }

                minWorker->addMobile(m);

            }
            std::chrono::milliseconds t(10);
            std::this_thread::sleep_for(t);
        }
    }
public:
    vector<Worker*> _workers;
};
int main()
{

    boss b;
    b.workerStart();

    b.Run();


   // while (1){}

    return 0;
}