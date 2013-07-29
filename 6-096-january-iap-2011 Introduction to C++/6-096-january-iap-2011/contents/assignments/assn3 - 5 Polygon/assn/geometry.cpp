#include "geometry.h"
#include <cmath>

//////////////////////////////////////////////////////////////////////////
 /* methods of class PointArray */

PointArray::PointArray(const Point newPoints[], const int newSize)
{
	points = new Point[newSize];
	for (int i=0; i < newSize; i++)
	{
		points[i] = newPoints[i];
	}
	size = newSize;
}

PointArray::PointArray(const PointArray& pv)
{
// 	PointArray(pv.points, pv.size);
	size = pv.size;
	points = new Point[size];
	for (int i=0; i < size; i++)
	{
		points[i] = pv.points[i];
	}
}

PointArray::~PointArray()
{
// 	if (size > 0)
// 	{
		delete[] points;
// 	}
}

void PointArray::resize(const int n)
{
	Point *tmpPoints;
// 	if (n == 0)
// 	{
// 		tmpPoints = NULL;
// 	} else {
		tmpPoints = new Point[n];

		for (int i=0; i < (size < n ? size : n); i++)
		{
			tmpPoints[i] = points[i];
		}
// 	}

// 	if (size > 0)
// 	{
		delete[] points;
// 	}

	points = tmpPoints;
	size = n;
}

void PointArray::pushBack(const Point &p)
{
	resize(size + 1);
// 	points[size] = p;
	points[size - 1] = p;
// 	size++;
}

void PointArray::insert(const int pos, const Point &p)
{
	resize(size + 1);

	for (int i = size - 1; i > pos; i--)
	{
		points[i] = points[i-1];
	}
	points[pos] = p;
}

void PointArray::remove(const int pos)
{
	if (/*size > 0 && */0 <= pos && pos <= size - 1) // pos < size implies size > 0
	{
		for (int i = pos; i < /*size - 1*/size - 2; i++)
		{
			points[i] = points[i+1];
		}

		resize(size - 1);
	}
}

void PointArray::clear()
{
	resize(0);
}

Point *PointArray::get(const int pos)
{
// 	if (0 <= pos && pos <= size-1)
// 	{
// 		return &points[pos];
// 	} else {
// 		return NULL;
// 	}
	return 0 <= pos && pos < size ? points + pos : NULL;
}

const Point *PointArray::get(const int pos) const
{
// 	if (0 <= pos && pos <= size-1)
// 	{
// 		return &points[pos];
// 	} else {
// 		return NULL;
// 	}
	return 0 <= pos && pos < size ? points + pos : NULL;
}

//////////////////////////////////////////////////////////////////////////
 /* methods of class Polygon */

// /*virtual*/ const double Polygon::area()
// {
// 	// unfinished programming
//
// 	return 0.0;
// }

int Polygon::number = 0; // type specifier is needed

//////////////////////////////////////////////////////////////////////////
 /* methods of class Rectangle */

Point  constructorPoints [4];
Point  *updateConstructorPoints ( const  Point  &p1 ,  const  Point  &p2 ,
								  const  Point  &p3 ,  const  Point  &p4  =  Point (0 ,0))  {
	constructorPoints [0]  =  p1;
	constructorPoints [1]  =  p2;
	constructorPoints [2]  =  p3;
	constructorPoints [3]  =  p4;
	return  constructorPoints ;
}

Rectangle::Rectangle(const Point &lowLeft, const Point &upRight):
Polygon(updateConstructorPoints(lowLeft, Point(lowLeft.getX(),upRight.getY()),
		upRight, Point(upRight.getX(),lowLeft.getY())), 4) {}

Rectangle::Rectangle(const int x1, const int y1, const int x2, const int y2):
Polygon(updateConstructorPoints(Point(x1,y1), Point(x1,y2), Point(x2,y2), Point(x2,y1)), 4) {}

const double Rectangle::area() const
{
// 	return (double)(polygon.get(1)->getY() - polygon.get(0)->getY()) *
// 		(polygon.get(3)->getX() - polygon.get(0)->getX());
	int length = polygon.get(1)->getY() - polygon.get(0)->getY();
	int width = polygon.get(3)->getX() - polygon.get(0)->getX();
	return /*std::*/abs((double)length * width); // std:: ?
}

//////////////////////////////////////////////////////////////////////////
 /* methods of class Triangle */

Triangle::Triangle(const Point &pt1, const Point &pt2, const Point &pt3):
Polygon(updateConstructorPoints(pt1, pt2, pt3), 3) {}

const double lenOfSegment(const Point* pt1, const Point *pt2)
{
	return sqrt(pow(pt1->getX() - pt2->getX(), 2) + pow(pt1->getY() - pt2->getY(), 2));
}
const double Triangle::area() const
{
	double a2 = lenOfSegment(polygon.get(0), polygon.get(1));
	double a0 = lenOfSegment(polygon.get(1), polygon.get(2));
	double a1 = lenOfSegment(polygon.get(2), polygon.get(0));
	double s = (a0 + a1 + a2) / 2;
	return sqrt(s * (s - a0) * (s - a1) * (s - a2)); // using Heron's formula
}
