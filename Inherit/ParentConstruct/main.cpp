#include <iostream>
using namespace std;

/* 无参构造函数想调用有参构造函数必须使用初始化列表. */
class Person
{
public:
#if 0
    Person()
    {
        cout << "Person()" << endl;
    }
#endif
    Person(int age) : m_age(m_age) 
    {
        cout << "Person(int age) : m_age(m_age) " << endl;
    }
public:
    int m_age;
};

class Student : public Person
{
public:
    Student() : Student(0, 0) 
    {
        cout << "Student()" << endl;
    }

#if 0
    Student(int age, int no)
    {
        /* 私有属性，子类拿不到 */
        m_age = age;
        m_no = no;
        cout << "Student(int age, int no)" << endl;
    }
#elif 0
    Student(int age, int no) : m_age(age), m_no(no)
    {
        cout << "Student(int age, int no)" << endl;
    }
#else
    Student(int age, int no) : Person(30), m_no(3) 
    {
        cout << "Student(int age, int no) : Person(30), m_no(3) " << endl;
    }
#endif

public:
public:
    int m_no;
};

/* 1. 子类的构造函数默认会调用父类的【无参】构造函数 */

int main()
{
    Student stu(22, 3);
    

    return 0;
}