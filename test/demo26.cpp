//
// Created by Administrator on 2020/4/19.
//

#include <iostream>
#include <string>
//c++成员对象  =封闭类
using namespace std;

class House{
private:
    char *m_address;
    int m_area;
public:
    House(char *address,int area);
    void show()const;
};

House::House(char *address, int area):m_address(address),m_area(area) {}
void House::show() const {
    cout<<"house address is:"<<this->m_address<<",area is "<<this->m_area<<endl;
}

class MarketHouse
{
private:
    int m_price;
    House m_house;
public:
    MarketHouse(int price, char *address,int area);
    void show() const;
};

MarketHouse::MarketHouse(int price, char *address,int area):m_price(price),m_house(address,area) {}
void MarketHouse::show() const {
    cout<<"marketableHousing price is:"<<this->m_price<<endl;
    this->m_house.show();
}
int main()
{
    MarketHouse house(100,(char*)"beijing",300);
    house.show();

    return 0;
}