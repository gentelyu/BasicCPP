#include <iostream>
using namespace std;
#include <memory>

class Person
{
public:
    Person()
    {
        cout << "Person()" << endl;
    }

    ~Person()
    {
        cout << "~Person()" << endl;
    }
public:
    void run()
    {
        cout << "run()" << endl;
    }
};

int main()
{

    {

        unique_ptr<Person> p2 = nullptr;
        {
            unique_ptr<Person> p1(new Person);
            p1->run();
            #if 0
            unique_ptr<Person> p2 = p1;
            unique_ptr<Person> p2(p1);
            #else
            /* person对象的所有权转移到P2 */
            p2 = std::move(p1);
        }
        cout << "1111111111111111111" << endl;
        /* */
        p2->run();
        cout << "222222222222222222" << endl;
        /* p2对象结束 调用析构函数. */
        #endif

        #if 0
        /* 适用于数组 */
        unique_ptr<Person[]> p1(new Person[3]{});
        #endif
        

    }

    return 0;
}