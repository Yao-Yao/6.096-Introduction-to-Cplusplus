#include  <iostream>
#include <string>

//#define min(a,b) (((a) < (b)) ? (a) : (b))

template <typename T>
T min(const T a, const T b);

int main ()
{
    std::cout << min<int>(4,3) << std::endl;

	return 0;
}

template <typename T>
T min(const T a, const T b)
{
    return a < b ? a : b;
}

//int main()
//{
//    std::cout << min(4.7, 2.0) << std::endl;
//
//    return 0;
//}
