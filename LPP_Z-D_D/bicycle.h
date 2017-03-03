//��λ��Ϊmm

#define R_min		300 			//��Сת���뾶
#define L				50000		//����������ֵ���Ƿ��б�Ҫ��
#define Offset_m	30			//������������ƫ����

#define K_c1		0				//<0�������������У�
#define K_c2		0.176		//<0.176���ڵ����У�0~0.176���������ߣ�>0.176����������
#define K_c3		0.364		//0.176~0.364���ڵ����ߣ�>0.364���ڵ�����

#define K_l1			0				//<0��ֱ���ڲ�����
#define K_l2			0.176		//<0.176����������
#define K_l3			0.577		//0.176~0.577���������ߣ�>0.577����������
#define K_l4			0.466		//0~0.466���ڲ�׼ֱ��>0.466���ڲ�����

#define Track_w  220			//��������
#define X_far		600			//��ȡ�Ľ�Զ��x����
#define Car_w		80			//������

//��				l*w=285*160
//�ӳ�����	300~600

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
}Line ;

float path_l(Line l_in); // ȡһ��Զ��Ϊ���գ�Ŀǰ�Գ�����̬����ϵΪ׼������Ҫ��Ϊ��������ϵ��������Ϊֱ��

float path_c (Circle c_in);

float pp_to_r (Point p_to);				//���������㣬��ת���뾶

int p_z_n(float in);							//����һ�������ж�����

float pp_d (Point p1, Point p2);		//������������

int out_the_track_l(Line l_in, float r);	//���⵱ǰ�켣�Ƿ���ƫ������

int out_the_track_c(Circle c_in, float r);
