#include <iostream>
using namespace std;

#define BUFFER_SIZE 32


class Student
{
public:
    Student()
    {
        cout << "Student()" << endl;
    }

    ~Student()
    {
        cout << "~Student()" << endl;
    }

    int setNo()
    {
        this->m_no = 31;
    }
#if 1
    void printInfo()
    {
        cout << "m_no:" << this->m_no << endl;
        cout << "m_room:" << this->m_room << endl;
    }
#endif

    /* 静态方法呢？*/
    static void printInfo()
    {
        cout << "m_no:" << m_no << endl;
        cout << "m_room:" << m_room << endl;

        /* THIS是属于对象 */
        // this-> ? 


        this->
    }
    /* static: 
        static修饰的变量(属性)：
            1. 是属于类的
            2. 访问方式3种
        static修饰的函数(方法)
            1. 拿不到普通函数
            2. 拿不到普通变量
            因为在静态函数内部没有this，因为this是属于对象的。
    */


public:
    /* 成员变量 : 属性 */
    int m_no;
    /* 静态成员变量 */
    static int m_room;
};

/* 静态成员变量 初始化: */
int Student::m_room = 0;



int main()
{
    /* 静态变量的获取方式 */
    /* case 1: */
    Student stu;
    stu.m_room = 254;

    /* case 2: */
    /* todo... */
    Student::m_room = 257;

    /* case 3: */
    Student * pStu = new Student();
    pStu->m_room = 888;


    cout << "Student::m_room:" << Student::m_room << endl;
    

    return 0;
}