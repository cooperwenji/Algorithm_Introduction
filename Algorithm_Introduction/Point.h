#ifndef POINT_H
#define POINT_H
#include<vector>

class Point_2
{
public:
	Point_2():x(0),y(0){}
	Point_2(int x1, int y1) :x(x1), y(y1) {}

public:
	int x;
	int y;
};

class Point_3
{
public:
	Point_3():x(0), y(0), z(0){}
	Point_3(int x1, int y1, int z1):x(x1),y(y1),z(z1){}

	std::vector<int>* operator-(const Point_3& o2);
public:
	int x;
	int y;
	int z;
};

std::vector<int>* Point_3::operator-(const Point_3& o2)
{
	std::vector<int>* temp = new std::vector<int>();
	temp->push_back(x - o2.x);
	temp->push_back(y - o2.y);
	temp->push_back(z - o2.z);
	return temp;
}

#endif // !POINT_H

