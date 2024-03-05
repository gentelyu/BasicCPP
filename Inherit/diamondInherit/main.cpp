#include <iostream>
using namespace std;

#define BUFFER_SIZE 32


class Person
{
public:
    /* 成员变量 : 属性 */
    long m_age1;
    long m_age2;
    long m_age3;
    long m_age4;
    long m_age5;
    long m_age6;
    long m_age7;
    long m_age8;
    long m_age9;
    long m_age10;
};

class Student : public Person
{
public:
    /* 成员变量 : 属性 */
    long m_score;
};

class Worker : public Person
{
public:
    /* 成员变量 : 属性 */
    long m_sarary;
};

class undergraduate: public Worker, public Student
{
public:
    /* 成员变量 : 属性 */
    long m_grade;
};


int main()
{
    undergraduate ug;

    int length = sizeof(ug);

    cout << "length:" << length << endl;
    

    return 0;
}