//
// Created by Administrator on 2020/6/13.
//
#ifndef __STU__H__
#define __STU__H__

//int number; 不可以，但是c可以

class Stu
{
private:
        int score;
        void initScore(int s);
public:
        int _number;
        char _name[100];
        void initStu(int number, char* name);
public:
        Stu(int number, char* name);
};

#endif
