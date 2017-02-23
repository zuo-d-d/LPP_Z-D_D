#define R_min 450
#define L			20000
#define Offset_k  50
#define Offset_m 50
// l*w=285*160
//单位均为mm
struct Point{
	float x;
	float y;
};

struct Circle{
	Point o; 
	float r;
};

struct Line {
	float k;
	float b;
};

float path_l(Line l_in); 
/*	取一较远点为参照，目前以车身动态坐标系为准，可能要改为赛道坐标系。
	该函数输入条件为保证当前输入仅为直线。	
*/

float pp_to_r (Point p_to);

int p_z_n(float in);
