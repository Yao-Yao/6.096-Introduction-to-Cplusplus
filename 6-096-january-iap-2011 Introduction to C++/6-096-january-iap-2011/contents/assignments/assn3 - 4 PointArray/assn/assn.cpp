#include  <iostream> 
#include "geometry.h"

// using namespace std, in order to omit " std:: " operator
using namespace std;


int  main ()  {
	
	Point pointA(1);
	PointArray pa(&pointA, 1);
	pa.pushBack(Point(2));
	pa.pushBack(Point(3));

	cout << " x = " << pointA.getX() << " y = " << pointA.getY() << endl;

	pa.remove(1);

	cout << "pa" << endl;
	for (int i=0; i < pa.getSize();i++)
	{
		cout << " x = " << pa.get(i)->getX() << " y = " << pa.get(i)->getY() << endl;
	}

	return 0;
}
