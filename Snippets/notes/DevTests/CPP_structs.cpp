#include <string>
#include <utility>

struct Person
{
    std::string name;
    int age;

    // Default constructor
    Person() : name("unknown"), age(0) {}

    // Parameterized constructor with a member initializer list
    Person(std::string n, int a) : name(std::move(n)), age(a) {}
};

Person a;            // unknown, 0
Person b("Sam", 30); // Sam, 30