#include <iostream>
#include <limits>
#include <string>
#include <engine.h>

#include "program.h"

//using namespace std;
// something for dev branch
// Developmental branch has more comments from mobile edits and may contain other code for testing purposes.
 

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
    //while(loop){work();}; I'd like to re-work the work() function so it is reader friendly and optimized. And should I move the while() loop into this scope or keep it inside the scope of the work() function? 
    work();
    return 0;
}

//rename to something better 
//work() returns an int based on the given input
float work()
{
    float y;
    int i;

    while(loop) // re-work this to be optimized and reader friendly. Having multiple if statements is not ideal. 
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
            // maybe break out of loop after program ends. This might fix the segmentation fault. 
        }

        // this is nothing special, just ignore this.
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
// Planning to learn about algorithms later. 
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

void test() //check compiler compliance?
{
    std::cout << std::numeric_limits<float>::is_iec559 << '\n';
    std::cout << std::numeric_limits<double>::is_iec559 << '\n';
    std::cout << std::numeric_limits<long>::is_iec559 << '\n';
}
