
#include<iostream>

struct A2
{
    int value;
};

class A
{
private:
    int value;

public:
    A(int n):value(n){}
    A(const A& other){ value = other.value; }
    void Print()
    {
        std::cout<<value<<std::endl;
    }

};

int main()
{

    A a = 10;
    A b = a;
    b.Print();
    
    return 0;
}
