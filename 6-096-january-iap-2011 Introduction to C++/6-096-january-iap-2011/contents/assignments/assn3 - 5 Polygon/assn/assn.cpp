#include  <iostream>
#include "geometry.h"

// using namespace std, in order to omit " std:: " operator
using namespace std;

void printAttributes(Polygon *);

int  main ()  {

	cout << "Please enter the coordinates of lower-left and upper-right points of the rectangle." << endl;
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
// 	Point point1(x1, y1), point2(x2, y2);
// 	Rectangle rect(point1, point2);
	Rectangle rect(Point(x1, y1), Point(x2, y2));

	printAttributes(&rect);

	cout << "Please enter the coordinates of 3 points of the triangle." << endl;
	int x3, y3;
// 	Point point3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
// 	point1.setX(x1);
// 	point1.setY(y1);
// 	point2.setX(x2);
// 	point2.setY(y2);
// 	point3.setX(x3);
// 	point3.setY(y3);
// 	Triangle tri(point1, point2, point3);
	Triangle tri(Point(x1, y1), Point(x2, y2), Point(x3, y3));

	printAttributes(&tri);

	return 0;
}

void printAttributes(Polygon *polygonPtr)
{
	cout << "The area of the polygon is " << polygonPtr->area() << " ." << endl;
	for (int i = 0; i < polygonPtr->getNumSizes(); i++)
	{
		cout << "The coordinates of point " << i << " (" << polygonPtr->getPoints()->get(i)->getX() << ", ";
		cout << polygonPtr->getPoints()->get(i)->getY() << ")." << endl;
	}
}

