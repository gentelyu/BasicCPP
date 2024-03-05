#include <iostream>
using namespace std;

#define BUFFER_SIZE 32
/* 无参构造函数想调用有参构造函数必须使用初始化列表. */

class Person
{
public:
    /* 构造 */
    Person()
    {
        cout << "Person()" << endl;

        /* */
        m_address = (char *)malloc(sizeof(char) * BUFFER_SIZE);
        if (m_address == NULL)
        {
            // throw XXX
            return;
        }

        /* todo... */
    }

    /* 析构 */
    ~Person()
    {
        cout << "~Person()" << endl;
        /* todo... */
        if (m_address)
        {
            free(m_address);
            m_address = NULL;
        }
    }
public:
    int m_age;
    char * m_address;
};

class Student : public Person
{
public:
    Student()
    {
        cout << "Student()" << endl;

        m_name = new char[BUFFER_SIZE];
        /* todo... */
    }

    ~Student()
    {
        cout << "~Student()" << endl;

        /* todo... */
        if (m_name)
        {
            delete[] m_name;
            m_name = NULL;
        }
    }

public:
    int m_no;
    char * m_name;
};

/* */


int main()
{
    #if 0
    /* 捕捉异常 */
    try
    {
        /* code */
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    #endif
    
    Student stu;
    

    return 0;
}