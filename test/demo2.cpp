//
// Created by Administrator on 2020/4/13.
//

#include <stdlib.h>
#include <stdio.h>

namespace SHAO{
  int age;
  char *name;
  typedef struct {
      int score;
      char *address;
  }test;

  test a = {.score=100,.address="guiyang"};

  void display()
  {
      printf("%s %d\n",a.address,a.score);
  }
};
namespace DIAN{
    int age;
    char *name;
    typedef struct {
        int score;
        char *address;
    }test;

    test a = {.score=200,.address="beijing"};

    void display()
    {
        printf("%s %d\n",a.address,a.score);
    }
};

int main()
{
    //using SHAO::display;
    //display();
    //using DIAN::display;
    //display();
    //SHAO::display();
    //DIAN::display();
    using namespace SHAO;
    display();
    return 0;
}