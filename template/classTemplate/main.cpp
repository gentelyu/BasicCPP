#include <iostream>
using namespace std;
#include <cstring>
#include <vector>


/* 封装 */
class Point {
public:
    /* 友元函数 */
    friend ostream & operator<<(ostream & cout, const Point &point)
    {
        return cout << "(" << point.m_x << ", " << point.m_y << ")";
    }
private:
	int m_x;
	int m_y;
public:
    /* 初始化列表 */
	Point(int x, int y) :m_x(x), m_y(y) {}

    /* 重载加法运算符 */
    Point operator+(const Point &point)
    {
        return Point(m_x + point.m_x, m_y + point.m_y);
    }
};

// template <typename Item>
// class Array;



template <typename Item>
class Array
{
public:
    template <typename T> friend ostream & operator<<(ostream &, const Array<T> &);
private:
    Item * m_data;
    int m_size;
    int m_capacity;

    /* 常量 */
    const int default_value = 10;
public:
    Array() : Array(10) {};

    Array(int capacity)
    {
        if (capacity <= 0)
        {
            capacity = default_value;
        }

        m_data = new Item[capacity];
        if (m_data == NULL)
        {
            throw "new error";
        }
        /* 清空内存 */
        memset(m_data, 0, sizeof(Item) * capacity);

        /* initialization */
        m_size = 0;
        m_capacity = capacity;
    }

    /* 析构函数 */
    ~Array()
    {
        if (m_data)
        {
            delete[] m_data;
        }
    }

private:
    bool checkIndexLegal(int index);
public:
    int add(Item value);
    void insert(int index, Item value);
    Item & get(int index);
	void remove(int index);
	int size();
	Item & operator[](int index);
};


template <typename Item> ostream & operator<< (ostream & cout, const Array<Item> & array1)
{
    cout << "[";

    for (int i = 0; i < array1.m_size; i++) {
        if (i != 0) {
            cout << ", ";
        }
        cout << array1.m_data[i];
    }

    return cout << "]";
}

/* 重载 */
template <typename Item>
Item & Array<Item>::operator[](int index)
{
    return get(index);
}

// template <typename Item>
// ostream &operator<< <>(ostream &cout, const Array<Item> &array) 
// {
// 	cout << "[";

// 	for (int i = 0; i < array.m_size; i++) {
// 		if (i != 0) {
// 			cout << ", ";
// 		}
// 		cout << array.m_data[i];
// 	}

// 	return cout << "]";
// }

/* 函数: 将重复的代码抽象出来 */
template <typename Item>
bool Array<Item>::checkIndexLegal(int index)
{
    if (index < 0 || index >= this->m_size)
    {
        return false;
    }
    return true;
}

/* 类模板类外实现需要加上模板信息 */
template <typename Item>
int Array<Item>::add(Item value)
{
    /* 扩容 */
    if (m_size == m_capacity)
    {
        /* 扩容 */
    }
    /* 程序到这个地方, 空间够 */
    m_data[m_size++] = value;
    return 0;
}

template <typename Item>
Item & Array<Item>::get(int index)
{
    // if (!checkIndexLegal(index))
    // {
    //     return XXX;
    // }

    return this->m_data[index];
}



int main()
{   
    Array<int> array;
    
    array.add(11);
    array.add(22);
    array.add(33);

    /* 重载[]运算符 */
    cout << array[2] << endl;
    /* 重载<<运算符 */
    cout << array << endl;

    array[2] = 888;
    cout << array[2] << endl;



    /* [11, 22, 33] */

    return 0;
}