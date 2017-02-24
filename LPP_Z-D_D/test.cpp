#include <iostream>
#include "bicycle.h"
using namespace std;

int main() {
	Line l1;
	l1.k=0.5;
	l1.b=-20;
	cout<<path_l(l1)<<endl;
	system("pause");
	return 0;
}
