#include <iostream>
using namespace std;
#include <stdio.h>

/* 无参构造函数想调用有参构造函数必须使用初始化列表. */

class Worker
{
public:
    Worker(int sarary) : m_sarary(sarary)
    {
        cout << "Worker(int sarary)" << endl;
    }
public:
    int m_sarary;
};

class Student
{
public:
    Student(int score) : m_score(score)
    {
        cout << "Student(int score)" << endl;
    }
public:
    int m_score;
};


/* 多继承 */
class Undergraduate : public Student,  public Worker
{
public:
    /* conclusion: XXXXXXX...*/
    Undergraduate(int score, int sarary, int grade) : Student(score), Worker(sarary), m_grade(grade)
    {
        cout << "Undergraduate()" << endl;
    }
    ~Undergraduate()
    {
        cout << "~Undergraduate()" << endl;
    }

    void play()
    {
        cout << "Undergraduate::play" << endl;
    }

    void printInfo()
    {
        cout << "score:" << m_score << "\tsarary:" << m_sarary << "\tgrade:" << m_grade << endl;
    }
public:
    int m_grade;
};


int main()
{
    Undergraduate ug(90, 8000, 10);
    
    int length = sizeof(ug);
    cout << "length:" << length << endl;

    ug.printInfo();
    return 0;
}