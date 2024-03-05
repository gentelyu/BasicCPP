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
        Person::makeMoney();
        cout << "Student - makeMoney() - 兼职" << endl;
        return 0;
    }

private:
    int m_no;
};



int main()
{

    Person * per = new Student;
    per->makeMoney();

    return 0;
}

