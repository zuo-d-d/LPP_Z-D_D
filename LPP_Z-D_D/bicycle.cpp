#include <iostream>
#include "bicycle.h"
using namespace std;

float path_l (Line l_in) {
	const float x_far = 300;					    //取较远点为300
	Point p_to;
	float r_out;
	if (fabs(l_in.k)< Offset_k) {
		if (l_in.k*l_in.b<0) {
			//(1)偏角小偏距小，e-，车向稳定，返回设定阈值，不需调整
			if (fabs(l_in.b)< Offset_m)	
				return L;		
			//(2)偏角小偏距大，e-
			else 	{
				p_to.x = x_far;
				p_to.y = (l_in.k*x_far+l_in.b)+p_z_n(l_in.k)*Offset_m;		
				r_out = pp_to_r(p_to);
				while (out_the_track(l_in,r_out))	r_out*=0.9;  //-10或*0.9待商讨
				return r_out;						
			}
		}
		else {
			//(3)偏角小偏距小，e+
			if (fabs(l_in.b)< Offset_m){
				p_to.x = x_far;
				p_to.y = (l_in.k*x_far+l_in.b)-p_z_n(l_in.k)*Offset_m;		
				r_out = pp_to_r(p_to);
				while (out_the_track(l_in,r_out))	r_out*=0.9;  //-10或*0.9待商讨
				return r_out;						
			}
			//(4)偏角小偏距大，e+
			else{
				p_to.x = x_far;							
				p_to.y = (l_in.k*x_far+l_in.b)-p_z_n(l_in.k)*Offset_m;		
				r_out = pp_to_r(p_to);
				while (out_the_track(l_in,r_out))	r_out*=0.9;  //-10或*0.9待商讨
				return r_out;					
			}
		}
	}
	//(5)偏角大，向-k方向修正
	else {
		p_to.x = x_far;							
		p_to.y = (l_in.k*x_far+l_in.b)-p_z_n(l_in.k)*Offset_m;		
		r_out = pp_to_r(p_to);
		while (out_the_track(l_in,r_out))	r_out*=0.9;  //-10或*0.9待商讨
		return r_out;			
	}
}

float pp_to_r (Point p_to) {
	Point  p_m;
	Line l_r;
	p_m.x = p_to.x / 2;
	p_m.y = p_to.y / 2;
	l_r.k = -(p_m.x / p_m.y);
	l_r.b = p_m.y - l_r.k * p_m.x;
	if (fabs(l_r.b)<R_min)	return R_min;		//超过极限半径时避免机械故障
	else								return  l_r.b;
}

int out_the_track(Line l_in, /*Circle c_in,*/ float r) {
	//该版本暂不考虑圆
	cout<<r<<endl;
	const float x_far = 300;
	Point p_c={0,0}, p_l={0,0};
	float k1=l_in.k;
	for (float x = 0; x < x_far ; x+=5)
	{
		float y=r-pow((r*r-x*x),0.5);
		float k=x/(r-y);
		if (fabs(l_in.k-k) < k1)	 {
			k1=fabs(l_in.k-k) ;
			p_c.x=x;
			p_c.y=y;
		}
	}
	float b2=p_c.y+p_c.x/l_in.k;
	p_l.x=(b2-l_in.b)*l_in.k/(l_in.k*l_in.k+1);
	p_l.y=(l_in.b-b2)/(l_in.k*l_in.k+1)+b2;
	cout<<p_c.x<<' '<<p_c.y<<endl;
	if (pp_d(p_c,p_l) > Track_w-80 ) return 1;
	else return 0;
}

int p_z_n(float in){
	if (in>0)			return 1;
	else if (in<0)		return -1;
	else					return 0;
}

float pp_d (Point p1, Point p2){
	return pow(pow((p1.x-p2.x),2)+pow((p1.y-p2.y),2),0.5);
}