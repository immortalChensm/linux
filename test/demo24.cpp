//
// Created by Administrator on 2020/4/19.
//

#include <iostream>
#include <string>

using namespace std;


namespace Jack
{
  class City
  {
  private:
      char *m_address;
      char *m_code;
  public:
      City(char *address,char *code);
      ~City();
      void getCity();
  };

  City::City(char *address, char *code):m_address(address),m_code(code) {}
  void City::getCity() {
      cout<<"my city address is "<<m_address<<" and code is "<<m_code<<endl;
  }
  City::~City() {
      //cout<<m_address<<"over\n";
      cout<<"over"<<endl;
  }
};
int main()
{
    using namespace Jack;
    City cities[2] = {City((char*)"guiyang",(char*)"123"),City((char*)"shanghai",(char*)"456")};

    for (int i = 0; i <2 ; ++i) {

        cities[i].getCity();
    }

    City *cityes1[2] = {new City((char*)"japanese",(char*)"12345"),new City((char*)"american",(char*)"67890")};

    for (int j = 0; j <2 ; ++j) {
        cityes1[j]->getCity();
        //delete [] cityes1[j];
    }
    cout<<"test"<<endl;
    
    return 0;
}