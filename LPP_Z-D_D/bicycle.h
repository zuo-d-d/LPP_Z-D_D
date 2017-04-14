//单位均为mm

#define R_min		300 			//最小转弯半径
#define L				2000			//直线阈值
#define Offset_m	30			//允许的中线偏移量

#define K_c1		0				//<0外道内切
#define K_c2		0.176		//<0.176内道内切0~0.176外道中线>0.176外道外切
#define K_c3		0.364		//0.176~0.364内道中线>0.364内道外切

#define K_l1			0				//<0内道同侧
#define K_l2			0.176		//<0.176外道同侧
#define K_l3			0.577		//0.176~0.577外道中线>0.577外道异侧
#define K_l4			0.466		//0~0.466内道保直>0.466内道异侧

#define Track_w  220		//赛道半宽
#define X_far		600			//所取的较远点坐标
#define Car_w		80			//车模半宽

//l*w=285*160
//可视距离 300~600

typedef struct {
	float x;
	float y;
}Point;

typedef struct {
	Point o;
	float r;
}Circle;

typedef struct {
	float k;
	float b;
}Line;

typedef struct {
	float rho0;
	float thet0;
}Line2;

typedef struct {
	float k;
	float x0;
}Line3;

float path_l(Line l_in);					//纯直线

float path_c (Circle c_in);				//纯弯道

float path_s (Circle c1, Circle c2);		//S弯，包括所有双圆输入

float path_ls (Line l_in, Point p0 );	//入S弯

float path_lc (Line l_in, Circle c_in, Point p0 );	//入弯

float path_cl (Line l_in, Circle c_in, Point p0 );	//出弯

float path_o (Point p1,Point p2, Line l_in);
