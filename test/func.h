//
// Created by Administrator on 2020/5/15.
//

#ifndef _FUNC_H
#define _FUNC_H

template <typename T>void Swap(T &a,T &b);
void bobble_sort(int arr[],int n);

template <typename T>void Swap(T &a,T &b)
{
    T temp = a;
    a=b;
    b=temp;
}
#endif //SWOOLE_TEST_FUNC_H
