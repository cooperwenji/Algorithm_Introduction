#ifndef PLANE_2D
#define PLANE_2D

//包含必要的数学库
#include<cmath>

//常量定义
const double PI = 3.14159265;

//2维Point类
class POINT_2
{
public:
	POINT_2();
	POINT_2(double xa=0,double ya=0):x(xa),y(ya) { }

private:
	double x;  //x坐标
	double y;  //y坐标
};

#endif

