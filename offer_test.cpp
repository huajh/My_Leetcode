
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

 
    int a = 15;
    int b = a>>1;
    
    return 0;
}
