#include <iostream>

class Point
{
private:
	int x, y;

public:
	Point(int u = 0, int v = 0):x(u), y(v){}

	int getX() const {return x;}
	int getY() const {return y;}
	void setX(const int newX) {x = newX;}
	void setY(const int newY) {y = newY;}

};

class PointArray
{
private:
	Point *points;
	int size;

	void resize(const int n);

public:
//	PointArray() {points = NULL; size = 0;}
	PointArray() {points = new Point[0];} //Allows deleting later
	PointArray(const Point newPoints[], const int newSize);
	PointArray(const PointArray &pv);
	~PointArray();

	void pushBack(const Point &p);
	void insert(const int pos, const Point &p);
	void remove(const int pos);
	const int getSize() const {return size;}
	void clear();
	Point *get(const int pos);
	const Point *get(const int pos) const;
};

class Polygon
{
protected:
	PointArray polygon;
	static int number;

public:
	Polygon(const Point newPoints[], const int newSize): polygon(/*PointArray(*/newPoints, newSize/*)*/) {number++;}
	Polygon(const PointArray &pv): polygon(pv) {number++;}
	Polygon(const Polygon &newPolygon): polygon(newPolygon.polygon){}
	~Polygon() {/*delete polygon;*/ number--;}

	virtual const double area()/*;*/ const = 0; // strange notation but it is right
	static const int getNumPolygons() {return number;}
	const int getNumSizes() {return /*polygon.size*/polygon.getSize();}
	const PointArray *getPoints() {return &polygon;}
};


class Rectangle: public Polygon
{
public:
	Rectangle(const Point &lowerLeft, const Point &upperRight);
	Rectangle(const int x1, const int y1, const int x2, const int y2);

// 	const double area();
	virtual const double area() const;
};

class Triangle: public Polygon
{
public:
	Triangle(const Point &pt1, const Point &pt2, const Point &pt3);

	virtual const double area() const;
};
