#define R_min 450
#define L			20000
#define Offset_k  50
#define Offset_m 50
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

float path_l(Line l_in); 
/*	ȡһ��Զ��Ϊ���գ�Ŀǰ�Գ���̬����ϵΪ׼������Ҫ��Ϊ��������ϵ��
	�ú�����������Ϊ��֤��ǰ�����Ϊֱ�ߡ�	
*/

float pp_to_r (Point p_to);

int p_z_n(float in);
