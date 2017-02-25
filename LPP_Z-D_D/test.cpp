#include <iostream>
#include "bicycle.h"
using namespace std;

int main() {
	Line l1;
	l1.k=0.5;
	l1.b=-20;
	Circle c1;
	c1.o.x=500;
	c1.o.y=1000;
	c1.r=2000;
	cout<<path_c(c1)<<endl;
	system("pause");
	return 0;
}
