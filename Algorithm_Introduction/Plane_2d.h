#ifndef PLANE_2D
#define PLANE_2D

//������Ҫ����ѧ��
#include<cmath>

//��������
const double PI = 3.14159265;

//2άPoint��
class POINT_2
{
public:
	POINT_2();
	POINT_2(double xa=0,double ya=0):x(xa),y(ya) { }

private:
	double x;  //x����
	double y;  //y����
};

#endif

