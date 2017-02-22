#include <iostream>
#include "bicycle.h"
using namespace std;

Circle path_l(Line l_in) {
	Circle circle_out;
	float    x_far = 300;
	Point  p_m;
	Line l_r;
	p_m.x = x_far / 2.0;
	p_m.y = (l_in.k * x_far + l_in.b) / 2.0;
	l_r.k = -(p_m.x / p_m.y);
	l_r.b = p_m.y - l_r.k * p_m.x;
	cout<<p_m.x<<' '<<p_m.y<<endl<<l_r.k<<' '<<l_r.b;
	circle_out.center.y = circle_out.r = l_r.b;
	circle_out.center.x = 0;
	return circle_out;
}

void print_test(Circle circle_out){
	printf("\n圆心:(%f,%f)\t半径:%f\n", circle_out.center.x, circle_out.center.y, circle_out.r);
	return;
}
