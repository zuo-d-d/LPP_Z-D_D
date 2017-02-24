#include <iostream>
#include "bicycle.h"
using namespace std;

float path_l (Line l_in) {
	Point p_to;
	float r_out;
	int b_pn = -1*p_z_n(l_in.b);
	if (fabs(l_in.b) > Offset_m) {
		if (b_pn*l_in.k <= K_l2) {
			p_to.x = X_far;
			p_to.y = (l_in.k*X_far+l_in.b)+b_pn*Offset_m;		
			r_out = pp_to_r(p_to);
			cout<<'1'<<r_out<<endl;
			while (out_the_track(l_in,r_out)) {
				r_out*=0.9;  //-10或*0.9待商讨
				if(fabs(r_out)<=R_min) {
					r_out=p_z_n(r_out) * R_min;
					break;
				}
			}
			return r_out;						
		}
		else if (b_pn*l_in.k <= K_l3) {
			p_to.x = X_far;
			p_to.y = l_in.k*X_far+l_in.b;		
			r_out = pp_to_r(p_to);
			cout<<'2'<<r_out<<endl;
			while (out_the_track(l_in,r_out)) {
				r_out*=0.9;  //-10或*0.9待商讨
				if(fabs(r_out)<=R_min) {
					r_out=p_z_n(r_out) * R_min;
					break;
				}
			}
			return r_out;	
		}
		else {
			p_to.x = X_far;
			p_to.y = (l_in.k*X_far+l_in.b)-b_pn*Offset_m;		
			r_out = pp_to_r(p_to);
			cout<<'3'<<r_out<<endl;
			while (out_the_track(l_in,r_out)) {
				r_out*=0.9;  //-10或*0.9待商讨
				if(fabs(r_out)<=R_min) {
					r_out=p_z_n(r_out) * R_min;
					break;
				}
			}
			return r_out;	
		}
	}
	else {
		if (b_pn*l_in.k < K_l1){
			p_to.x = X_far;
			p_to.y = (l_in.k*X_far+l_in.b)+b_pn*Offset_m;		
			r_out = pp_to_r(p_to);
			cout<<'4'<<r_out<<endl;
			while (out_the_track(l_in,r_out)) {
				r_out*=0.9;  //-10或*0.9待商讨
				if(fabs(r_out)<=R_min) {
					r_out=p_z_n(r_out) * R_min;
					break;
				}
			}
			return r_out;			
		}
		else if (b_pn*l_in.k <= K_l4){
			cout<<'5'<<endl;
			return L;					
		}
		else {
			p_to.x = X_far;
			p_to.y = (l_in.k*X_far+l_in.b)-b_pn*Offset_m;		
			r_out = pp_to_r(p_to);
			cout<<'6'<<r_out<<endl;
			while (out_the_track(l_in,r_out)) {
				r_out*=0.9;  //-10或*0.9待商讨
				if(fabs(r_out)<=R_min) {
					r_out=p_z_n(r_out) * R_min;
					break;
				}
			}
			return r_out;	
		}
	}
}

float path_c (Circle c_in){
	float r_out;
	return 0;
}

float pp_to_r (Point p_to) {
	if (p_to.y == 0) return L;
	Point  p_m;
	Line l_r;
	p_m.x = p_to.x / 2;
	p_m.y = p_to.y / 2;
	l_r.k = -(p_m.x / p_m.y);
	l_r.b = p_m.y - l_r.k * p_m.x;
	cout<<l_r.b<<endl;
	if (fabs(l_r.b)<R_min)	return R_min;		//超过极限半径时避免机械故障
	else								return  l_r.b;
}

int out_the_track(Line l_in, /*Circle c_in,*/ float r) {
	//该版本暂不考虑圆
	cout<<r<<endl;
	Point p_c={0,0}, p_l={0,0};
	float k1=l_in.k;
	for (float x = 0; x < X_far ; x+=5)
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
	//
	cout<<p_c.x<<' '<<p_c.y<<endl;
	//
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