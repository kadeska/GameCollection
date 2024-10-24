#include <iostream>
#include <limits>
#include <string>
#include "include/engine.h"

#include "include/core.h"

//using namespace std;

// Release -- v0.2.2 alpha
//--------------------------------------function declaraions
float run();
float algorithm_A(int input);
void test();
int parsToInt(std::string str);
//--------------------------------------------------------
bool loop = true;
//-----------------------------------------functions

//main function
int main() // Entry level 0
{
    std::cout << "Hello world!" << '\n';
    //while(loop){work();}; I'd like to re-work the work() function so it is reader friendly and optimized. And should I move the while() loop into this scope or keep it inside the scope of the work() function?
    //run();
    //return 0; 
    return run(); 
}

float run()
{
    float result;

    while(loop) // re-work this to be optimized and reader friendly. Having multiple if statements is not ideal.
    {
        std::string input;
        std::cout << "Please enter a number 0 through 9, or a command: " << '\n';
        std::cin >> input;
        //std::cout << str << '\n';

        if (input == "exit" || input == "stop" || input == "abort")
        {
            return 0;
        }
        else if (input == "test")
        {
            test();
            continue;
        }
        else if (input == "engine")
        {
            std::cout << "Starting Engine... \n";
            create_Window();
            continue;
        }
        else if (input == "breakout")
        {
            std::cout << "Breakout Game!...\n";
            startGame();
            continue;
        }

        int number = parsToInt(input);
        // this is nothing special, just ignore this.
        if (number >= 0 && number <= 9)
        {
            std::cout << "You entered: " << number << '\n';
            result = algorithm_A(number);
            std::cout << "OUTPUT:  " << result << '\n';
        }
        else
        {
            std::cout << "ERROR! - Please enter a number 0 through 9" << '\n';
        }
    }
    return result;
}

//algorithmA takes an input and returns some int output after some manipulation.
// Planning to learn about algorithms later.
float algorithm_A(int input)
{
    float x = static_cast<float>(input);
    x += (x * (x/2));
    //cout << x << endl;
    return x;
}

// Parse string to int
int parsToInt(std::string str)
{
    try
    {
        return std::stoi(str);
    }
    catch(std::exception e)
    {
        std::cout << "WARNING: An exception has been cought." << '\n';
        return -1;
    }
}

void test() //check compiler compliance?
{
    std::cout << std::numeric_limits<float>::is_iec559 << '\n';
    std::cout << std::numeric_limits<double>::is_iec559 << '\n';
    std::cout << std::numeric_limits<long>::is_iec559 << '\n';
}
