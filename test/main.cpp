#include <iostream>

struct test{
    unsigned char b:1;
};

struct test a;
int main() {

    printf("%s\n",a.b);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}