#include <iostream>
#include "bicycle.h"
using namespace std;

int main() {
	Line l1;
	l1.k=1;
	l1.b=100;
	cout<<path_l(l1);
	system("pause");
	return 0;
}
