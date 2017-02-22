// #define R_min 450
// l*w=285*160
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

Circle path_l(Line l_in);

void print_test(Circle circle_out);
