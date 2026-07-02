#include<iostream>

using namespace std;

struct Rect
{
  int length, breadth;
} a,b;

int main()
{
  Rect *p;

  p = new Rect;

  p ->length = 20;
  p ->breadth = 5;

  cout << "Using pointer :" << endl;
  cout << p->length << endl << p->breadth << endl;

  return 0;
}