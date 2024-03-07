#include <iostream>
using namespace std;
#include <memory>
// #include
class Car;

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
    shared_ptr<Car> m_car = nullptr;
};

class Car
{
public:
    Car()
    {
        cout << "Car()" << endl;
    }

    ~Car()
    {
        cout << "~Car()" << endl;
    }
public:
#if 0
    shared_ptr<Person> m_person = nullptr;
#else
    /* 解决shared_ptr的循环引用问题 */
    weak_ptr<Person> m_person;
#endif
};


int main()
{
    {
        shared_ptr<Person> person(new Person());
        shared_ptr<Car> car(new Car());

        person->m_car = car;
        car->m_person = person;

        cout << person->m_car.use_count() << endl;
        cout << car->m_person.use_count() << endl;
    }

    auto val = "fregr";
    cout << typeid(val).name() << endl;
    /* */
    return 0;
}

/* 
    auto_ptr 
    shared_ptr
    weak_ptr
    unique_ptr
*/