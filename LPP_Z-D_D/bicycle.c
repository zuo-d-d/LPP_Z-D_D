#include <stdio.h>
#include <math.h>
#include "bicycle.h"

float path_l (Line l_in) {
	Point p_to;
	float r_out;
	int b_pn = -1*p_z_n(l_in.b);
	if (fabs(l_in.b) > Offset_m) {
		if (b_pn*l_in.k <= K_l2) {
			p_to.x = X_far;
			p_to.y = (l_in.k*X_far+l_in.b)+b_pn*Offset_m;
			r_out = pp_to_r(p_to);
			printf("1 %f\n",r_out);
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
			printf("2 %f\n",r_out);
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
			printf("3 %f\n",r_out);
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
			printf("4 %f\n",r_out);
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
			printf("5 \n");
			return L;
		}
		else {
			p_to.x = X_far;
			p_to.y = (l_in.k*X_far+l_in.b)-b_pn*Offset_m;
			r_out = pp_to_r(p_to);
			printf("6 %f\n",r_out);
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
	Point p_to;
	float r_out;
	int r_l= c_in.o.y > 0 ? 1 : -1;
	y0 = c_in.o.y-r_l*pow((c_in.r*c_in.r-c_in.o.x*c_in.o.x),0.5f);
	k0 = c_in.o.x/(y0-c_in.o.y);
	if (y0 <=0) {
		if (r_l*k0 < K_c2) {
			p_to.x = X_far;
			if (p_to.x > c_in.r - c_in.o.x) p_to.x =  c_in.r - c_in.o.x;
			p_to.y =  c_in.o.y-r_l*pow((c_in.r*c_in.r-pow(p_to.x-c_in.o.x,2)),0.5f)+r_l*Offset_m;
			r_out = pp_to_r(p_to);
			printf("1 %f\n",r_out);
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
			p_to.y =  c_in.o.y-r_l*pow((c_in.r*c_in.r-pow(p_to.x-c_in.o.x,2)),0.5f);
			r_out = pp_to_r(p_to);
			printf("2 %f\n",r_out);
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
			p_to.y =  c_in.o.y-r_l*pow((c_in.r*c_in.r-pow(p_to.x-c_in.o.x,2)),0.5f)-r_l*Offset_m;
			r_out = pp_to_r(p_to);
			printf("3 %f\n",r_out);
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
			p_to.y =  c_in.o.y-r_l*pow((c_in.r*c_in.r-pow(p_to.x-c_in.o.x,2)),0.5f)+r_l*Offset_m;
			r_out = pp_to_r(p_to);
			printf("4 %f\n",r_out);
			//是否需要？
			if(fabs(r_out)<=R_min)
				r_out=p_z_n(r_out) * R_min;
			return r_out;
		}
		else if (r_l*k0 < K_c2) {
			p_to.x = X_far;
			if (p_to.x > c_in.r - c_in.o.x) p_to.x =  c_in.r - c_in.o.x;
			p_to.y =  c_in.o.y-r_l*pow((c_in.r*c_in.r-pow(p_to.x-c_in.o.x,2)),0.5f);
			r_out = pp_to_r(p_to);
			printf("5 %f\n",r_out);
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
			p_to.y =  c_in.o.y-r_l*pow((c_in.r*c_in.r-pow(p_to.x-c_in.o.x,2)),0.5f)-r_l*Offset_m;
			r_out = pp_to_r(p_to);
			printf("6 %f\n",r_out);
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
	Point  p_m;
	Line l_r;
	if (p_to.y == 0) return L;
	p_m.x = p_to.x / 2;
	p_m.y = p_to.y / 2;
	l_r.k = -(p_m.x / p_m.y);
	l_r.b = p_m.y - l_r.k * p_m.x;
	printf("%f\n",l_r.b);
	if (fabs(l_r.b)<R_min)	return R_min;		//超过极限半径时避免机械故障
	else								return  l_r.b;
}

int out_the_track_l(Line l_in, float r) {
	Point p_t, p_l;
	float k1=l_in.k;
	float x,y,k,b2;
	p_t.x=0;	p_t.y=0;
	p_l.x=0;	p_l.y=0;
	printf("%f\n",r);
	for (x = 0; x < X_far ; x+=5)
	{
		y=r-pow((r*r-x*x),0.5f);
		k=x/(r-y);
		if (fabs(l_in.k-k) < k1)	 {
			k1=fabs(l_in.k-k) ;
			p_t.x=x;
			p_t.y=y;
		}
	}
	b2=p_t.y+p_t.x/l_in.k;
	p_l.x=(b2-l_in.b)*l_in.k/(l_in.k*l_in.k+1);
	p_l.y=(l_in.b-b2)/(l_in.k*l_in.k+1)+b2;
	//
	printf("%f %f\n",p_t.x, p_t.y);
	//
	if (pp_d(p_t,p_l) > Track_w-Car_w ) return 1;
	else return 0;
}

int out_the_track_c(Circle c_in, float r){
	Point p_c, p_t,p_r;
	float d;
	p_t.x=0;	p_t.y=0;
	p_c.x=0;	p_c.y=0;
	printf("%f\n",r);
	if (r*c_in.o.y < 0){
		p_r.x = 0,	p_r.y = r;
		d = r+c_in.r-pp_d(p_r ,c_in.o);
		if (d > Track_w-Car_w ) return 1;
		else return 0;
	}
	else {
		p_r.x = 0,	p_r.y = r;
		d = r-c_in.r+pp_d(p_r ,c_in.o);
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
	return pow(pow((p1.x-p2.x),2)+pow((p1.y-p2.y),2),0.5f);
}
