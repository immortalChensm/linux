//
// Created by Administrator on 2020/5/16.
//

#include <iostream>
#include "point.h"

using namespace std;

template <class T1,class T2>
void Point<T1,T2>::display() const {
    cout<<"x="<<m_x<<",y="<<m_y<<endl;
}

template class Point<char *,char *>;
template class Point<int ,int>;
