//��λ��Ϊmm

#define R_min 450			//��Сת��뾶
#define L			50000		//�����ǣ��Ƿ��б�Ҫ��
#define Offset_k  0.1			//����ķ���ƫ����
#define Offset_m 20		//�����������ƫ����
#define Track_w   250	//�������

//�� l*w=285*160

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
//	ȡһ��Զ��Ϊ���գ�Ŀǰ�Գ���̬����ϵΪ׼������Ҫ��Ϊ��������ϵ���ú�����������Ϊ��֤��ǰ�����Ϊֱ��	

float pp_to_r (Point p_to);

int p_z_n(float in);	 //����һ�������ж�����

float pp_d (Point p1, Point p2);	//����������

int out_the_track(Line l_in,/* Circle c_in, */float r);	//��⵱ǰ�켣�Ƿ��ƫ������