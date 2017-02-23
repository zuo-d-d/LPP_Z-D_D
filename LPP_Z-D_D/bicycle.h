//单位均为mm

#define R_min 450			//最小转弯半径
#define L			50000		//舵机零角，是否有必要？
#define Offset_k  0.1			//允许的方向偏移量
#define Offset_m 20		//允许的中心线偏移量
#define Track_w   250	//赛道半宽

//车 l*w=285*160

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
//	取一较远点为参照，目前以车身动态坐标系为准，可能要改为赛道坐标系。该函数输入条件为保证当前输入仅为直线	

float pp_to_r (Point p_to);

int p_z_n(float in);	 //输入一个数，判断正负

float pp_d (Point p1, Point p2);	//求两点间距离

int out_the_track(Line l_in,/* Circle c_in, */float r);	//检测当前轨迹是否会偏出赛道