#define R_min		300 			//��Сת��뾶
#define L				2000			//ֱ����ֵ
#define Offset_m	30			//���������ƫ����

#define K_c1		0				//<0�������
#define K_c2		0.176		//<0.176�ڵ�����0~0.176�������>0.176�������
#define K_c3		0.364		//0.176~0.364�ڵ�����>0.364�ڵ�����

#define K_l1			0				//<0�ڵ�ͬ��
#define K_l2			0.176		//<0.176���ͬ��
#define K_l3			0.577		//0.176~0.577�������>0.577������
#define K_l4			0.466		//0~0.466�ڵ���ֱ>0.466�ڵ����

#define Track_w  220		//�������
#define X_far		600			//��ȡ�Ľ�Զ������
#define Car_w		80			//��ģ���

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

float path_s (Circle c1, Circle c2);		//S�䣬��������˫Բ����

float path_ls (Line l_in, Point p0 );	//��S��

float path_lc (Line l_in, Circle c_in, Point p0 );	//����

float path_cl (Line l_in, Circle c_in, Point p0 );	//����

float path_o (Point p1,Point p2, Line l_in);

turn_t local_route_plan(route routine);