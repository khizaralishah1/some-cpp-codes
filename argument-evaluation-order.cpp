#include <iostream>

void PrintSum(int a, int b)
{
    std::cout << a << " + " << b << " = " << ( a + b ) << std::endl;
}

int main()
{
    int value = 0;
    //          Compiler can evaluate in parallel until c++17
    //          POSTFIX expressions evaluate in serially
    PrintSum(value++, value++);
    //PrintSum(value++, ++value);

    std::cout << "outside, value = " << value << std::endl;

    // TAKEAWAY: evaluation is NOT in PARALLEL

    return 0;
}