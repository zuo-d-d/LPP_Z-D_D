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

#define Pi            3.14159

typedef enum {rstraight, rcircle}rtype  ;

typedef struct {
	float x;
	float y;
}Point;

typedef struct {
	Point near_point,far_point;
}Line2;

typedef struct {
	float k;
	float b; 
}Line;

typedef struct {
	Point o;
	float r;
}Circle;


typedef struct {
	rtype type;
	Line2 l;
	Circle c;
}elements;

typedef struct {
	unsigned int length;
	elements *element;
}route;

typedef struct {
	float turn_radius;
	bool direction;
}turn_t;

float pp_to_r (Point p_to);

int p_z_n(float in);

float pp_d (Point p1, Point p2);

Line two_p_to_kb(Line2 l0);

int out_the_track_l(Line l_in, float r);

int out_the_track_c(Circle c_in, float r);

int out_the_track_p(Point p,float x, float r);

int out_the_track_l2(Line l_in, float r);

float path_l (Line2 l);

float path_c (Circle c_in);

float path_s (Circle c1, Circle c2);		//S弯，包括所有双圆输入

float path_ls (Line l_in, Point p0 );	//入S弯

float path_lc (Line l_in, Circle c_in, Point p0 );	//入弯

float path_cl (Line l_in, Circle c_in, Point p0 );	//出弯

float path_o (Point p1,Point p2, Line l_in);

turn_t local_route_plan(route routine);