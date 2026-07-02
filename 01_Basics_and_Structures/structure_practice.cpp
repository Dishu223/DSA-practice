#include <iostream>
#include <stdio.h>

using namespace std;

struct Student
{
    int roll;
    // char address[50];
    // char branch[15];
};

int main()
{
    struct Student s1;
    s1.roll = 21;
    cout << s1.roll;
}