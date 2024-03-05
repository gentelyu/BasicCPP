#include <iostream>
using namespace std;


int myHeight()
{
    return 70;
}

int myAge()
{
    return 30;
}

class Person
{
public:
    Person(int height, int age)
    {
        #if 0
        /* review... */
        this->m_height = height;
        this->m_age = age;
        #elif 0
        m_height = height;
        m_age = age;
        #else
        m_height = myHeight();
        m_age = myAge();
        #endif
    }
public:
    int m_height;
    int m_age;
};


class Student
{
public:
    /* 初始化列表 */
    Student(int height, int age) : m_height(myHeight()), m_age(myAge()) {}
public:
    int m_height;
    int m_age;
};
/* 基本一模一样. */

int main()
{
    Person person(60, 22);
    cout << "age:" << person.m_age << "\theight:" << person.m_height << endl;

    Student stu(60, 22);
    cout << "age:" << stu.m_age << "\theight:" << stu.m_height << endl;
    return 0;
}