#include <iostream>
#include "bicycle.h"
using namespace std;

int main() {
  Circle c1;
  const float Pi = 3.14159;
  c1.center[0]=0;
  c1.center[1]=0;
  c1.r=5;
  cout<<Pi*c1.r*c1.r;
  
  return 0;
}
