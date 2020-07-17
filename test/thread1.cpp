//
// Created by Administrator on 2020/7/1.
//

#include <iostream>
#include <string.h>
#include <vector>
#include <map>
#include <thread>
#include <windows.h>
#include <unistd.h>
#include <mutex>


using namespace std;

class CellServer;

class ClientObj
{
public:
    int _id;
public:
    void show(int who,CellServer &obj)
    {
        cout << who << " do " << _id << endl;
        printf("cellServer=%#x\n",&obj);
    }
};
class CellServer
{
private:
    std::vector<ClientObj*> _clients;
    std::vector<ClientObj*> _clientsBuf;
    std::map<int, ClientObj*> _clientWorker;
    std::mutex _mutex;
public:
    int _who;
public:
    void run()
    {
        while (1) {

            //cout<<"thread "<<_who<<" working clientBuf size: "<<_clientsBuf.size()<<endl;
            if (!_clientsBuf.empty()) {

                std::lock_guard<std::mutex> lock(_mutex);

                for (auto client : _clientsBuf) {

                    _clientWorker[client->_id] = client;


                }
                _clientsBuf.clear();
            }

            if (_clientWorker.empty()) {

                //std::chrono::milliseconds t(1);
                //std::this_thread::sleep_for(t);

                continue;
            }

            std::vector<ClientObj*> _clientsTmp;
            if (!_clientWorker.empty()) {
                for (auto client : _clientWorker) {


                    client.second->show(_who,*this);

                    _clientsTmp.push_back(client.second);


                }
            }

            for (auto client : _clientsTmp) {

                _clientWorker.erase(client->_id);
                delete client;
            }

        }
    }
    void start()
    {
        std::thread t(&CellServer::run, this);
        cout << "子线程启动了" << endl;
        t.detach();
    }

    void addClient(ClientObj* client)
    {
        _clientsBuf.push_back(client);
    }
};

class Server
{
private:
    std::vector<CellServer*> _cellServers;
    int _num;
    int counter;
public:
    Server() {
        counter = 0;
    }
    void Start(int num)
    {
        _num = num;
        for (int i = 0; i < num; i++) {

            auto cell = new CellServer();
            _cellServers.push_back(cell);
            cell->_who = i;
            cell->start();
        }
    }


    void run()
    {

        if (!_cellServers.empty()) {
            for (auto cell : _cellServers) {
                ClientObj* client = new ClientObj();
                if (client != nullptr) {
                    client->_id = counter++;

                    cell->addClient(client);
                }


                sleep(2);
            }
        }

    }
};

//消息发送任务类
class CellSendMsg2ClientTask:public CellTask
{
    ClientSocket* _pClient;
    DataHeader* _header;
public:
    CellSendMsg2ClientTask(ClientSocket* pClient, DataHeader* header)
    {
        _pClient = pClient;
        _header = header;
    }

    void doTask()
    {
        _pClient->sendData(_header);
        delete _header;
    }

}
#include <assert.h>
int main()
{

//    Server obj;
//    obj.Start(2);
//
//    while (1) {
//
//        obj.run();
//    }
    //while(1){}

    /* std::map<int, char> obj1;
     obj1[1345235235] = 'a';*/
    assert(1==0);
    return 0;
}