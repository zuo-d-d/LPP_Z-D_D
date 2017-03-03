#include <stdio.h>
#include "bicycle.h"

int main() {
	Line l1;
	Circle c1;
	l1.k=0.5;
	l1.b=-20;
	c1.o.x=-30;
	c1.o.y=1990;
	c1.r=2000;
	printf("%f\n",path_c(c1));
	getchar();
	return 0;
}
