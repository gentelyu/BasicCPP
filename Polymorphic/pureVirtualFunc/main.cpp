#include <iostream>
using namespace std;

#define BUFFER_SIZE 32


class Person
{
public:
    /* 构造 */
    Person()
    {
        cout << "Person()" << endl;
    }

    /* 析构 */
    ~Person()
    {
        cout << "~Person()" << endl;  
    }

public:
    /* 纯虚函数 */
    virtual int makeMoney() = 0; 

    /* 纯虚函数 */
    virtual int shop() = 0;
    
public:
    long m_age;
};

class Student : public Person
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
public:
    /* 重写(override) */
    int makeMoney()
    {
        cout << "Student - makeMoney() - 兼职" << endl;
        return 0;
    }

#if 1
    int shop()
    {
        cout << "Student - shopping() - 买书" << endl;
        return 0;
    }
#endif

    virtual int study()
    {
        cout << "study()" << endl;
        return 0;
    }
private:
    long m_no;
};


int main()
{
    // Person person;
    Student stu1;

    return 0;
}

