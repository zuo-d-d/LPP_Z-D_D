#include <iostream>
#include "bicycle.h"
using namespace std;

float path_l(Line l_in) {
	float    x_far = 300;                //取较远点为300
	Point  p_m;
	Line l_r;
	p_m.x = x_far / 2.0;
	p_m.y = (l_in.k * x_far + l_in.b) / 2.0;
	l_r.k = -(p_m.x / p_m.y);
	l_r.b = p_m.y - l_r.k * p_m.x;
	if (fabs(l_r.b)>5000)				l_r.b=20000;	//车向稳定时设定阈值，不需调整
	else if (fabs(l_r.b)<R_min)	l_r.b=R_min;		//超过极限半径时避免机械故障
	return  l_r.b;
}

float path_c(Circle c_in){
	float r_now ;
	const float offset = 10;
	if (fabs(c_in.o.x)<offset) {								//车身位置良好
		r_now = c_in.o.y;
		if (r_now>c_in.r-100 && r_now<c_in.r)	//100为车宽加上赛道余量
			return r_now;
		else if (r_now<c_in.r+100)						//0.9为修正系数
			return r_now*0.9;
		else
			return R_min;
	}
	else {															//车身位置不好

	}
}
