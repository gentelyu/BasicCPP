#include <iostream>
using namespace std;





class Student
{
public:
#if 0
    /* 这是错误使用情况, 本质是临时变量 */
    Student()
    {
        Student(0, 0);
        cout << "Student() : Student(0, 0) " << endl;
    }
    /* 初始化列表 */
    Student(int height, int age) : m_height(height), m_age(age) 
    {
        cout << "Student(int height, int age) : m_height(height), m_age(age)" << endl;
    }
#else
    Student() : Student(0, 0) 
    {
        cout << "Student() : Student(0, 0) " << endl;
    }
    /* 初始化列表 */
    Student(int height, int age) : m_height(height), m_age(age) 
    {
        cout << "Student(int height, int age) : m_height(height), m_age(age)" << endl;
    }
#endif
public:
    int m_height;
    int m_age;
};
/* 基本一模一样. */
/* 初始化列表 todo... */


int main()
{
    // Person person(60, 22);
    // cout << "age:" << person.m_age << "\theight:" << person.m_height << endl;

    Student stu;
    cout << "age:" << stu.m_age << "\theight:" << stu.m_height << endl;
    return 0;
}