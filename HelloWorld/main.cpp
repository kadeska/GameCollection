#include <iostream>
#include <limits>
#include <string>
#include <engine.h>

#include "program.h"

//using namespace std;

// Release v0.2.1

//--------------------------------------function declaraions
float work();
float algorithm_A(int input);
void test();
int parsToInt(std::string str);
//--------------------------------------------------------
bool loop = true;
//-----------------------------------------functions

//main function
int main()
{
    std::cout << "Hello world!" << '\n';
    //while(loop){work();};
    work();
    return 0;
}

//work() returns an int based on the given input
float work()
{
    float y;
    int i;

    while(loop)
    {
        std::string str;
        std::cout << "Please enter a number 0 through 9" << '\n';
        std::cin >> str;
        std::cout << str << '\n';
        i = parsToInt(str);

        if (str == "exit" || str == "stop" || str == "abort")
        {
            return 0;
        }
        if (str == "test")
        {
            test();
        }
        if (str == "engine")
        {
            std::cout << "Starting Engine... \n";
            create_Window();
        }
        if (str == "breakout")
        {
            std::cout << "Breakout Game!...\n";
            startProgram();
        }
        if (i >= 0 && i <= 9)
        {
            std::cout << "You entered: " << i << '\n';
            std::cout << "OUTPUT:  " << (y = algorithm_A(i)) << '\n';
        }
        else
        {
            std::cout << "ERROR! - Please enter a number 0 through 9" << '\n';
        }

    }


    return y;
}

//algorithmA takes an input and returns some int output after some manipulation.
float algorithm_A(int input)
{
    float x = (input * 1.0);
    x += (x * (x/2));
    //cout << x << endl;
    return x;
}

int parsToInt(std::string str)
{
    try
    {
        int i = std::stoi(str);
    }
    catch(std::exception e)
    {
        //std::cout << "WARNING: An exception has been cought." << '\n';
    }
}

void test()
{
    std::cout << std::numeric_limits<float>::is_iec559 << '\n';
    std::cout << std::numeric_limits<double>::is_iec559 << '\n';
    std::cout << std::numeric_limits<long>::is_iec559 << '\n';
}
