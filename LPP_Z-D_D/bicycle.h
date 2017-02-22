#define R_min 450
// l*w=285*160
//单位均为mm
struct Point{
	float x;
	float y;
};

struct Circle{
	Point center;
	float r;
};

struct Line {
	float k;
	float b;
};

float path_l(Line l_in); //取一较远点为参照