#include <iostream>
using namespace std;
#include <string.h>

#define BUFFER_SIZE 32


class Person
{
public:
    /* 构造 */
    Person()
    {
        cout << "Person()" << endl;
    }

    /* 虚析构 */
    virtual ~Person()
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
    Student(const char * name)
    {
        cout << "Student()" << endl;
        
        #if 0
        m_name = (char *)malloc(sizeof(char) * BUFFER_SIZE);
        #else
        m_name = new char[BUFFER_SIZE];
        #endif
        /* todo... */

        strncpy(m_name, name, strlen(name) + 1);
    }

    ~Student()
    {
        if (m_name)
        {
            delete[] m_name;
        }
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
    long m_no;
    char * m_name;
};


int main()
{
    Person *per = new Student("zhangsan");
    
    delete per;

    return 0;
}

