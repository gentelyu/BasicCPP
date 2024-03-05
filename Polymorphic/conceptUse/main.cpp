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
    int makeMoney()
    {
        cout << "Person - makeMoney()" << endl;
        return 0;
    }
public:
    int m_age;
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
private:
    int m_no;
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
private:
    int m_hair;
};


int main()
{
    Person *per = new Student();
    per->makeMoney();

    return 0;
}

