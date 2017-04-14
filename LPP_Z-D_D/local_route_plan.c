#include <stdio.h>
#include <math.h>
#include "local_route_plan.h"

turn_t local_route_plan(route routine){
	turn_t lrp_out;
	if(routine.element[0].type) {
		lrp_out.turn_radius=path_c(routine.element[0].c);
		if (lrp_out.turn_radius>0) lrp_out.direction=1;
		else {
			lrp_out.direction=0;
			lrp_out.turn_radius*=-1;
		}
	}
	else {
		lrp_out.turn_radius=path_l(routine.element[0].l);
		if (lrp_out.turn_radius>0) lrp_out.direction=1;
		else {
			lrp_out.direction=0;
			lrp_out.turn_radius*=-1;
		}
	}
	return lrp_out;

	/* 
	if (routine.length==1){
	if(routine.element[0].type) return path_c(routine.element[0].c);
	else return path_l(routine.element[0].l);
	}
	else if(routine.element[0].type == 0){
	if (routine.element[0].l.far_point.y<50 && routine.element[1].type) return path_c(routine.element[1].c)

	}
	*/
}

float path_l (Line2 l) {
	Line l_in;
	Point p_to;
	float r_out;
	l_in=two_p_to_kb(l);
	p_to.x = X_far;
	p_to.y = (l_in.k*X_far+l_in.b);
	r_out = pp_to_r(p_to);
	if(r_out>L) return L;
	if(r_out<L) return -L;
	return r_out;
}

float path_c (Circle c_in) {
	Point p_to;
	float r_out;
	int r_l= p_z_n(c_in.o.x);
	p_to.x = X_far;
	if (p_to.x > c_in.r + c_in.o.y) p_to.x =  c_in.r + c_in.o.y;
	p_to.y =  c_in.o.x-r_l*pow((c_in.r*c_in.r-pow(p_to.x-c_in.o.y,2)),0.5f);
	r_out = pp_to_r(p_to);
	if(r_out>L) return L;
	if(r_out<L) return -L;
	return r_out;
}

//float path_s (Circle c1, Circle c2){
//	Point p_to;
//	float r_out;
//	if (c1.r==c2.r) {
//		p_to.x=(c1.o.x+c2.o.x)/2;
//		p_to.y=(c1.o.y+c2.o.y)/2;
//	}
//	else {
//		p_to.x=c1.o.x+(c2.o.x-c1.o.x)*c1.r/(c1.r+c2.r);
//		p_to.y=c1.o.y+(c2.o.y-c1.o.y)*c1.r/(c1.r+c2.r);
//	}
//	r_out=pp_to_r(p_to);
//	while (out_the_track_c(c1, r_out)) {
//		if (c1.o.y*r_out < 0)
//			r_out*=0.9;  //-10或*0.9待商讨
//		else {
//			if (fabs(r_out) < L) r_out*=1.1;
//			else r_out*=-1;					//r过大时要考虑反打方向
//		}
//		if(fabs(r_out)<=R_min) {
//			r_out=p_z_n(r_out) * R_min;
//			break;
//		}
//	}
//	return r_out;
//}
//
//float path_ls (Line l_in, Point p0 ){
//	float r_out;
//	Point p_to;
//	if (p0.x>200) 	p_to=p0;
//	else {
//		p_to.x=p0.x;
//		p_to.y=l_in.k*p0.x;
//	}
//	r_out = pp_to_r(p_to);
//	while (out_the_track_l(l_in,r_out)) {
//		r_out*=0.9;
//		if(fabs(r_out)<=R_min) {
//			r_out=p_z_n(r_out) * R_min;
//			break;
//		}
//	}
//	if (r_out>L || r_out<-L ) return L;
//	return r_out;
//}
//
//float path_lc (Line l_in, Circle c_in, Point p0 ){
//	int turn;
//	float r_out;
//	Point p_to;
//	if (c_in.o.y>p0.y)  turn = 1;
//	else turn =-1 ;
//	if ( turn*l_in.b < Offset_m ) {
//		if ( p0.x>500) {
//			p_to.x=p0.x;
//			p_to.y=p0.y-turn*Offset_m;
//		}
//		else p_to = p0;
//	}
//	else {
//		if (p0.x>200) {
//			p_to.x=p0.x;
//			p_to.y=p0.y-turn*Offset_m;
//		}
//		else {
//			p_to.x=p0.x;
//			p_to.y=l_in.k*p0.x;
//		}
//	}
//	r_out = pp_to_r(p_to);
//	while (out_the_track_l(l_in,r_out)) {
//		r_out*=0.9;
//		if(fabs(r_out)<=R_min) {
//			r_out=p_z_n(r_out) * R_min;
//			break;
//		}
//	}
//	if (r_out>L || r_out<-L ) return L;
//	return r_out;
//}
//
//float path_cl (Line l_in, Circle c_in, Point p0 ){
//	int turn;
//	float r_out;
//	Point p_to;
//	float y0,x0;
//	if (c_in.o.y>0) turn = 1 ;
//	else turn = -1;
//	if (p0.x>500){
//		p_to.x=p0.x;
//		p_to.y=p0.y-turn*Offset_m;
//		r_out = pp_to_r(p_to);
//		while (out_the_track_c(c_in,r_out)) {
//			r_out*=0.9;
//			if(fabs(r_out)<=R_min) {
//				r_out=p_z_n(r_out) * R_min;
//				break;
//			}
//		}
//		if (r_out>L || r_out<-L) return L;
//		return r_out;
//	}
//	else {
//		y0 = c_in.o.y-turn*pow((c_in.r*c_in.r-c_in.o.x*c_in.o.x),0.5f);
//	    x0 = (-y0)/l_in.k;
//		r_out = x0*tan(45+atan(l_in.k)/2);
//		while (out_the_track_c(c_in,r_out)) {
//			r_out*=0.9;
//			if(fabs(r_out)<=R_min) {
//				r_out=p_z_n(r_out) * R_min;
//				break;
//			}
//		}
//		if (r_out>L || r_out<-L) return L;
//		return r_out;
//	}
//}
//
////以下为工具类函数
//
//
//
//int out_the_track_l(Line l_in, float r) {
//	Point p_t, p_l;
//	float k1=l_in.k;
//	float x,y,k,b2;
//	int rl=p_z_n(r);
//	p_t.x=0;	p_t.y=0;
//	p_l.x=0;	p_l.y=0;
//	for (x = 0; x < X_far ; x+=5)
//	{
//		y=r-rl*pow((r*r-x*x),0.5f);
//		k=x/(r-y);
//		if (fabs(l_in.k-k) < k1)	 {
//			k1=fabs(l_in.k-k) ;
//			p_t.x=x;
//			p_t.y=y;
//		}
//	}
//	b2=p_t.y+p_t.x/l_in.k;
//	p_l.x=(b2-l_in.b)*l_in.k/(l_in.k*l_in.k+1);
//	p_l.y=(l_in.b-b2)/(l_in.k*l_in.k+1)+b2;
//	if (pp_d(p_t,p_l) > Track_w-Car_w ) return 1;
//	else return 0;
//}
//
//int out_the_track_c(Circle c_in, float r){
//	Point p_c, p_t,p_r;
//	float d;
//	p_t.x=0;	p_t.y=0;
//	p_c.x=0;	p_c.y=0;
//	if (r*c_in.o.y < 0){
//		p_r.x = 0,	p_r.y = r;
//		d = r+c_in.r-pp_d(p_r ,c_in.o);
//		if (d > Track_w-Car_w ) return 1;
//		else return 0;
//	}
//	else {
//		p_r.x = 0,	p_r.y = r;
//		d = r-c_in.r+pp_d(p_r ,c_in.o);
//		if (d > Track_w-Car_w ) return 1;
//		else return 0;
//	}
//}
//
//int out_the_track_p(Point p,float x, float r){
//	Point p_c;
//	int rl=p_z_n(r);
//	int i;
//	for (i=0; i<x; i+=5){
//		p_c.x=i;
//		p_c.y=r-rl*pow((r*r-x*x),0.5f);
//		if (pp_d(p_c,p)<Car_w+20) return 0;
//	}
//	return 1;
//}
//
//int out_the_track_l2(Line l_in, float r) {
//	Point p_t, p_l;
//	float k1=l_in.k;
//	float x,y,k,b2;
//	int rl=p_z_n(r);
//	p_t.x=0;	p_t.y=0;
//	p_l.x=0;	p_l.y=0;
//	for (x = 0; x < X_far ; x+=5)
//	{
//		y=r-rl*pow((r*r-x*x),0.5f);
//		k=x/(r-y);
//		if (fabs(l_in.k-k) < k1)	 {
//			k1=fabs(l_in.k-k) ;
//			p_t.x=x;
//			p_t.y=y;
//		}
//	}
//	b2=p_t.y+p_t.x/l_in.k;
//	p_l.x=(b2-l_in.b)*l_in.k/(l_in.k*l_in.k+1);
//	p_l.y=(l_in.b-b2)/(l_in.k*l_in.k+1)+b2;
//	if (pp_d(p_t,p_l) < Car_w ) return 1;
//	else return 0;
//}

float pp_to_r (Point p_to) {
	Point  p_m;
	Line l_r;
	if (p_to.y == 0) return L;
	p_m.x = p_to.x / 2;
	p_m.y = p_to.y / 2;
	l_r.k = -(p_m.x / p_m.y);
	l_r.b = p_m.y - l_r.k * p_m.x;
	if (fabs(l_r.b)<R_min)	return p_z_n(l_r.b)*R_min;		//超过极限半径时避免机械故障
	else								return  l_r.b;
}
//求数为正或负
int p_z_n(float in){
	if (in>0)			return 1;
	else if (in<0)		return -1;
	else					return 0;
}

//求两点间距离
float pp_d (Point p1, Point p2){
	return pow(pow((p1.x-p2.x),2)+pow((p1.y-p2.y),2),0.5f);
}

Line two_p_to_kb(Line2 l0){
	Line l;
	l.k=(l0.far_point.x-l0.near_point.x)/(l0.far_point.y-l0.near_point.y);
	l.b=l0.near_point.x-l.k*l0.near_point.y;
	return l;
}