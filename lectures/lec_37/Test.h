#ifndef TEST_H_
#define TEST_H_

#include <iostream>

using namespace std;

class Test
{
public:
    static int const MAX = 99;

private:
    int id;
    static int count;

public:
    Test();
    ~Test();
    void ShowInfo();
    static void ShowCount(){ cout << count << endl; }; // To access static private data, need a static method as well
};

#endif