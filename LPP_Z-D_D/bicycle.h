#define R_min 450
// l*w=285*160
//��λ��Ϊmm
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

float path_l(Line l_in); //ȡһ��Զ��Ϊ���գ�Ŀǰ�Գ���̬����ϵΪ׼������Ҫ��Ϊ��������ϵ
