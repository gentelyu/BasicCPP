#include <iostream>
using namespace std;
#include "myAdd.hpp"


/* 封装 */
class Point {
public:
    /* 友元函数 */
    friend ostream &operator<<(ostream &, const Point &);
private:
	int m_x;
	int m_y;
public:
    /* 初始化列表 */
	Point(int x, int y) :m_x(x), m_y(y) {}

    /* 重载加法运算符 */
    Point operator+(const Point &point); 
};

/* 友元函数 */
ostream &operator<<(ostream & cout, const Point &point)
{
    return cout << "(" << point.m_x << ", " << point.m_y << ")";
}

Point Point::operator+(const Point &point)
{
    return Point(m_x + point.m_x, m_y + point.m_y);
}

int main()
{
    // call	_Z5myAddIiET_S0_S0_@PLT
    // 汇编在链接之前, 所以这个_Z5myAddIiET_S0_S0_@PLT是随机值。
    /* 直到链接完成之后, 才会更新这个值. */
    cout << myAdd(10, 20) << endl;      // call 随机的

    cout << myAdd<float> (6.6, 9.9) << endl;

    Point p1(1, 1);
    Point p2(2, 2);
    Point point = myAdd<Point> (p1, p2);

    cout << point << endl;

    return 0;
}