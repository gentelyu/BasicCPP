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
        cout << "Person run()" << endl;
    }
private:
    int m_age;
};




int main()
{
#if 0
    {
        Person *p2 = new Person[3];

        p2->run();
        /* 只有调用了delete才会调用析构 */
        delete [] p2;
    }
#endif


#if 0
    /* auto_ptr 的使用 */
    auto_ptr<Person> p1(new Person);    // p1 = new Person[]

    // p1->run()    // 1
    // p1.run()     // 2
    p1->run();

    /* auto_ptr 不适用于数组 */
    // auto_ptr<Person[]> p2(new Person[3]{});
#endif


#if 1
    /* 引用计数 */
    {
        #if 1
        {
            shared_ptr<Person> p2;
            shared_ptr<Person> p3;
            {

                shared_ptr<Person> p1(new Person);
                p2 = p1;
                cout << "count:" << p1.use_count() << endl;
            }

            cout << "count:" << p2.use_count() << endl;
            cout << "222222" << endl;
            p3 = p2;
            cout << "count:" << p3.use_count() << endl;
        }
        cout << "3333333" << endl;
        #else
        /* 是否适用于数组 */
        shared_ptr<Person[]> p2(new Person[3]{});
        #endif


    }

#endif

    return 0;
}