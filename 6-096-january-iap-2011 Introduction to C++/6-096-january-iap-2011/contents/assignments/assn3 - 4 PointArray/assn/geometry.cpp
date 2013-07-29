#include "geometry.h"

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

void PointArray::resize(const int n) // EFFICIENCY !!! double allocation will do better ..
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
	resize(size+1);
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
		for (int i = pos; i < size - 1; i++) // " size - 1 " is correct
		{
			points[i] = points[i+1];
		}
	
		resize(size - 1);
	}
}

const int PointArray::getSize() const
{
	return size;
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