//
// Created by Administrator on 2020/5/15.
//

#include "func.h"
//20 19 15 8 9 3
//19 20
//19 15 20
//19 15 8 20
//19 15 8 9 20
//19 15 8 9 3 20

void bobble_sort(int arr[],int n)
{
    for (int i = 0; i <n-1 ; ++i) {

        bool isSorted=true;
        for (int j = 0; j <n-1-i ; ++j) {
            if(arr[j]>arr[j+1]){
                isSorted=false;
                Swap(arr[j],arr[j+1]);
                /**
                 * temp = arr[j]
                 * arr[j] = arr[j+1]
                 * arr[j+1]= temp
                 */
            }
        }
        if(isSorted)break;
    }
}