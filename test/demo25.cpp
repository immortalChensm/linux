//
// Created by Administrator on 2020/4/19.
//
#include <iostream>

using namespace std;

class Tyre
{
public:
    Tyre(int radius,int with);
    void show() const;

private:
    int m_radius;
    int m_width;
};

Tyre::Tyre(int radius, int with):m_radius(radius),m_width(with) {}
void Tyre::show() const {
    cout<<"radius:"<<this->m_radius<<"inch\n";
    cout<<"width:"<<this->m_width<<"mm"<<endl;
}

class Engine
{
public:
    Engine(float displacement=3.0);
    void show() const;

private:
    float m_displacement;
};
Engine::Engine(float displacement):m_displacement(displacement) {}
void Engine::show() const {
    cout<<"displacement:"<<this->m_displacement<<"L\n";
}

class Car
{
public:
    Car(int price,int radius,int width);
    void show() const;

private:
    int m_price;
    Tyre m_tyre;
    Engine m_engine;
};

Car::Car(int price, int radius, int width):m_price(price),m_tyre(radius,width) {}
void Car::show() const {
    cout<<"price:"<<this->m_price<<"$\n";
    this->m_tyre.show();
    this->m_engine.show();
}

int main()
{
    Car car(2000,30,500);
    car.show();

    return 0;
}
