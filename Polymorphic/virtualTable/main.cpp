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
    virtual int makeMoney()
    {
        cout << "Person - makeMoney()" << endl;
        return 0;
    }

    virtual int shop()
    {
        cout << "Person - shopping()" << endl;
        return 0;
    }
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

    int shop()
    {
        cout << "Student - shopping() - 买书" << endl;
        return 0;
    }

    virtual int study()
    {
        cout << "study()" << endl;
        return 0;
    }
private:
    long m_no;
};



class Teacher : public Person
{
public:
    Teacher()
    {
        cout << "Teacher()" << endl;
    }

    ~Teacher()
    {
        cout << "~Teacher()" << endl;
    }
public:
    /* 重写(override) */
    int makeMoney()
    {
        cout << "Teacher - makeMoney() - 出书" << endl;
        return 0;
    }

    int shop()
    {
        cout << "Teacher - shopping() - 买房" << endl;
        return 0;
    }
private:
    int m_hair;
};


int main()
{
    Student stu;
    int length = sizeof(stu);
    cout << "length:" << length << endl;

    return 0;
}

