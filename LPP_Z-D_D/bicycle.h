//单位均为mm

#define R_min		300 			//最小转弯半径
#define L				50000		//舵机零角阈值，是否有必要？
#define Offset_m	30			//允许的中心线偏移量

#define K_c1		0				//<0，曲线外道内切；
#define K_c2		0.176		//<0.176，内道内切；0~0.176，外道中线；>0.176，外道外线
#define K_c3		0.364		//0.176~0.364，内道中线；>0.364，内道外切

#define K_l1			0				//<0，直线内侧内切
#define K_l2			0.176		//<0.176，外侧内切
#define K_l3			0.577		//0.176~0.577，外侧中线；>0.577，外侧外切
#define K_l4			0.466		//0~0.466，内测准直；>0.466，内测外切

#define Track_w  220			//赛道半宽
#define X_far		600			//所取的较远点x坐标

//车				l*w=285*160
//视场距离	300~600

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

float path_l(Line l_in); // 取一较远点为参照，目前以车身动态坐标系为准，可能要改为赛道坐标系。输入仅为直线	

float path_c (Circle c_in);

float pp_to_r (Point p_to);				//出入两个点，求转弯半径

int p_z_n(float in);							//输入一个数，判断正负

float pp_d (Point p1, Point p2);		//求两点间距离

int out_the_track_l(Line l_in, float r);	//检测当前轨迹是否会偏出赛道

int out_the_track_c(Circle c_in, float r);