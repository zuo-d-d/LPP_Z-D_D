#include <iostream>
#include "bicycle.h"
using namespace std;

float path_l (Line l_in) {
	const float x_far = 300;					    //取较远点为300
	Point p_to;
	if (fabs(l_in.k)> Offset_k) {
		if (l_in.k*l_in.b<0) {
			//(1)偏角小偏距小，e-，车向稳定，返回设定阈值，不需调整
			if (fabs(l_in.b)< Offset_m)	
				return L;		
			//(2)偏角小偏距大，e-
			else 	{
				p_to.x = x_far;
				p_to.y = (l_in.k*x_far+l_in.b)+p_z_n(l_in.k)*Offset_m;		

				/*需进行是否偏出赛道的检测，未写*/		
				
				return pp_to_r(p_to);						
			}
		}
		else {
			//(3)偏角小偏距小，e+
			if (fabs(l_in.b)< Offset_m){
				p_to.x = x_far;
				p_to.y = (l_in.k*x_far+l_in.b)-p_z_n(l_in.k)*Offset_m;		

				/*需进行是否偏出赛道的检测，未写*/		
				
				return pp_to_r(p_to);						
			}
			//(4)偏角小偏距大，e+
			else{
				p_to.x = x_far;							
				p_to.y = (l_in.k*x_far+l_in.b)-p_z_n(l_in.k)*Offset_m;		

				/*需进行是否偏出赛道的检测，未写*/		
				
				return pp_to_r(p_to);						
			}
		}
	}
	//(5)偏角大，向-k方向修正
	else {
		p_to.x = x_far;							
		p_to.y = (l_in.k*x_far+l_in.b)-p_z_n(l_in.k)*Offset_m;		

				/*需进行是否偏出赛道的检测，未写*/		
				
		return pp_to_r(p_to);				
	}
}

float pp_to_r (Point p_to) {
	Point  p_m;
	Line l_r;
	p_m.x = p_to.x / 2.0;
	p_m.y = p_to.y / 2.0;
	l_r.k = -(p_m.x / p_m.y);
	l_r.b = p_m.y - l_r.k * p_m.x;
	if (fabs(l_r.b)<R_min)	return R_min;		//超过极限半径时避免机械故障
	else								return  l_r.b;
}

int p_z_n(float in){
	if (in>0)			return 1;
	else if (in<0)		return -1;
	else					return 0;
}