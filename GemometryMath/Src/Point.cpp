#include "..\Include\Math\Point.h"
#include<iostream>

Point::Point()
{
	x = 0.0f;
	y = 0.0f;
}


void Point::setPoint(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Point::display()
{

}
Point::~Point()
{
}
