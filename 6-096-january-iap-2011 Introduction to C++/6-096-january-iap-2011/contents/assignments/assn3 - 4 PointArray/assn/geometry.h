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
	PointArray() {points = new Point[0];} // Allows deleting later !!!

	PointArray(const Point newPoints[], const int newSize);
	PointArray(const PointArray &pv);
	~PointArray();

	void pushBack(const Point &p);
	void insert(const int pos, const Point &p);
	void remove(const int pos);
	const int getSize() const;
	void clear();
	Point *get(const int pos);
	const Point *get(const int pos) const;
};