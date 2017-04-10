#define R_min		300 			//��Сת��뾶
#define L				50000			//ֱ����ֵ
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

enum rtype {rstraight, rcircle};

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

turn_t local_route_plan(route routine);