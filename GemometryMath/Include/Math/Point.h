
#ifndef POINT_H
#define POINT_H

#include<iostream>
#include"Export.h"
class EXPORT_API Point
{
public:
	Point();
	~Point();

private:
	float x, y;
public:
	void setPoint(float a, float b);
	void display();
};
#endif
