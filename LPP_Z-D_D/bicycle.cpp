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
			while (out_the_track_l(l_in,r_out)) {
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
			while (out_the_track_l(l_in,r_out)) {
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
			while (out_the_track_l(l_in,r_out)) {
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
			while (out_the_track_l(l_in,r_out)) {
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
			while (out_the_track_l(l_in,r_out)) {
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

float path_c (Circle c_in) {
	float k0,y0;
	int r_l= c_in.o.y > 0 ? 1 : -1;
	y0 = c_in.o.y-r_l*pow((c_in.r*c_in.r-c_in.o.x*c_in.o.x),0.5);
	k0 = c_in.o.x/(y0-c_in.o.y);
	Point p_to;
	float r_out;
	if (y0 <=0) {
		if (r_l*k0 < K_c2) {
			p_to.x = X_far;
			if (p_to.x > c_in.r - c_in.o.x) p_to.x =  c_in.r - c_in.o.x;
			p_to.y =  c_in.o.y-r_l*pow((c_in.r*c_in.r-pow(p_to.x-c_in.o.x,2)),0.5)+r_l*Offset_m;
			r_out = pp_to_r(p_to);
			cout<<'1'<<r_out<<endl;
			while (out_the_track_c(c_in, r_out)) {
				if (r_l*r_out < 0)
					r_out*=0.9;  //-10或*0.9待商讨
				else {
					if (fabs(r_out) < L) r_out*=1.1;
					else r_out*=-1;					//r过大时要考虑反打方向
				}
				if(fabs(r_out)<=R_min) {
					r_out=p_z_n(r_out) * R_min;
					break;
				}
			}
			return r_out;
		}
		else if (r_l*k0 < K_c3) {
			p_to.x = X_far;
			if (p_to.x > c_in.r - c_in.o.x) p_to.x =  c_in.r - c_in.o.x;
			p_to.y =  c_in.o.y-r_l*pow((c_in.r*c_in.r-pow(p_to.x-c_in.o.x,2)),0.5);
			r_out = pp_to_r(p_to);
			cout<<'2'<<r_out<<endl;
			//是否需要？
			while (out_the_track_c(c_in, r_out)) {
				if (r_out >= L) {
					r_out=L;
					break;
				}
				else {
					r_out*=1.1;
					continue;
				}
				if(fabs(r_out)<=R_min) {
					r_out=p_z_n(r_out) * R_min;
					break;
				}
			}
			return r_out;
		}
		else {
			p_to.x = X_far;
			if (p_to.x > c_in.r - c_in.o.x) p_to.x =  c_in.r - c_in.o.x;
			p_to.y =  c_in.o.y-r_l*pow((c_in.r*c_in.r-pow(p_to.x-c_in.o.x,2)),0.5)-r_l*Offset_m;
			r_out = pp_to_r(p_to);
			cout<<'3'<<r_out<<endl;
			//是否需要？
			while (out_the_track_c(c_in, r_out)) {
				r_out*=0.9;
				if(fabs(r_out)<=R_min) {
					r_out=p_z_n(r_out) * R_min;
					break;
				}
			}
			return r_out;
		}
	}
	else	{
		if (r_l*k0 < K_c1) {
			p_to.x = X_far;
			if (p_to.x > c_in.r - c_in.o.x) p_to.x =  c_in.r - c_in.o.x;
			p_to.y =  c_in.o.y-r_l*pow((c_in.r*c_in.r-pow(p_to.x-c_in.o.x,2)),0.5)+r_l*Offset_m;
			r_out = pp_to_r(p_to);
			cout<<'4'<<r_out<<endl;
			//是否需要？
			if(fabs(r_out)<=R_min)
				r_out=p_z_n(r_out) * R_min;
			return r_out;
		}
		else if (r_l*k0 < K_c2) {
			p_to.x = X_far;
			if (p_to.x > c_in.r - c_in.o.x) p_to.x =  c_in.r - c_in.o.x;
			p_to.y =  c_in.o.y-r_l*pow((c_in.r*c_in.r-pow(p_to.x-c_in.o.x,2)),0.5);
			r_out = pp_to_r(p_to);
			cout<<'5'<<r_out<<endl;
			while (out_the_track_c(c_in, r_out)) {
				r_out*=0.9;
				if(fabs(r_out)<=R_min) {
					r_out=p_z_n(r_out) * R_min;
					break;
				}
			}
			return r_out;
		}
		else {
			p_to.x = X_far;
			if (p_to.x > c_in.r - c_in.o.x) p_to.x =  c_in.r - c_in.o.x;
			p_to.y =  c_in.o.y-r_l*pow((c_in.r*c_in.r-pow(p_to.x-c_in.o.x,2)),0.5)-r_l*Offset_m;
			r_out = pp_to_r(p_to);
			cout<<'6'<<r_out<<endl;
			while (out_the_track_c(c_in, r_out)) {
				r_out*=0.9;
				if(fabs(r_out)<=R_min) {
					r_out=p_z_n(r_out) * R_min;
					break;
				}
			}
			return r_out;
		}
	}
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

int out_the_track_l(Line l_in, float r) {
	cout<<r<<endl;
	Point p_t={0,0}, p_l={0,0};
	float k1=l_in.k;
	for (float x = 0; x < X_far ; x+=5)
	{
		float y=r-pow((r*r-x*x),0.5);
		float k=x/(r-y);
		if (fabs(l_in.k-k) < k1)	 {
			k1=fabs(l_in.k-k) ;
			p_t.x=x;
			p_t.y=y;
		}
	}
	float b2=p_t.y+p_t.x/l_in.k;
	p_l.x=(b2-l_in.b)*l_in.k/(l_in.k*l_in.k+1);
	p_l.y=(l_in.b-b2)/(l_in.k*l_in.k+1)+b2;
	//
	cout<<p_t.x<<' '<<p_t.y<<endl;
	//
	if (pp_d(p_t,p_l) > Track_w-Car_w ) return 1;
	else return 0;
}

int out_the_track_c(Circle c_in, float r){
	cout<<r<<endl;
	Point p_c={0,0}, p_t={0,0};
	if (r*c_in.o.y < 0){
		Point p_r = {0,r};
		float d = r+c_in.r-pp_d(p_r ,c_in.o);
		if (d > Track_w-Car_w ) return 1;
		else return 0;
	}
	else {
		Point p_r = {0,r};
		float d = r-c_in.r+pp_d(p_r ,c_in.o);
		if (d > Track_w-Car_w ) return 1;
		else return 0;
	}
}

int p_z_n(float in){
	if (in>0)			return 1;
	else if (in<0)		return -1;
	else					return 0;
}

float pp_d (Point p1, Point p2){
	return pow(pow((p1.x-p2.x),2)+pow((p1.y-p2.y),2),0.5);
}
