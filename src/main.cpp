#include "../include/engine.hpp"
#include <iostream>
#include <limits>
#include <string>

#include "../include/core.hpp"
#include "../include/networking.hpp"
#include "../include/helper.hpp"

// using namespace std;

// Release -- v0.2.3 alpha
//--------------------------------------function declaraions
int run();
float algorithm_A(int input);
void test();
int parsToInt(std::string str);
bool stop();
//--------------------------------------------------------
bool loop = true;
std::string program_args;
std::string user_input;
//-----------------------------------------functions

// main function
int main() // Entry level 0
{
  std::cout << "Hello world!" << '\n';
  // while(loop){work();}; I'd like to re-work the work() function so it is
  // reader friendly and optimized. And should I move the while() loop into this
  // scope or keep it inside the scope of the work() function? run(); return 0;
  return run();
}

Helper helper;
std::string dir = "/src/shaders/breakout";
int run() {
  int choice;
  while (loop) {

    // For debugging reasons
    getFilesInFolder(helper.currentPathStr + dir);

    // Display the menu
    std::cout << "\nMain Menu:\n";
    std::cout << "1. Say Hello\n";
    std::cout << "2. Run Breakout Game\n";
    std::cout << "3. Run Server\n";
    std::cout << "4. Run Client\n";
    std::cout << "5. Run Test\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter your choice: ";
    //std::cin >> choice; // Take input from the user

    if (!(std::cin >> choice)) { // Check if input is invalid
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid input. Please enter a number between 1 and 6.\n";
            continue; // Restart the loop
        }

    // Use switch-case to decide what command to run
    switch (choice) {
    case 1:
      std::cout << "\n Hello, User! \n";
      break;
    case 2:
      std::cout << "\n Running Breakout Game \n";
      startGame();
      break;
    case 3:
      std::cout << "\n Running Server \n";
      startServer();
      break;
    case 4:
      std::cout << "\n Running Client \n";
      startClient();
      break;
    case 5:
      std::cout << "\n Running test... \n";
      test();
      create_Window();
      break;
    case 6:
      std::cout << "\n Exiting... Goodbye! \n";
      std::cout << "Stopping the program... \n";
      if (stop()) {
        loop = false; // Exit the loop
      }
      break;
    default:
      std::cout << "Invalid choice. Please try again.\n";
      break;
    }
  }
  return 0;
}

// algorithmA takes an input and returns some int output after some
// manipulation.
//  Planning to learn about algorithms later.
float algorithm_A(int input) {
  float x = static_cast<float>(input);
  x += (x * (x / 2));
  // cout << x << endl;
  return x;
}

// Parse string to int
int parsToInt(std::string str) {
  try {
    return std::stoi(str);
  } catch (std::exception e) {
    std::cout << "WARNING: An exception has been cought." << '\n';
    return -1;
  }
}

void test() // check compiler compliance?
{
  std::cout << std::numeric_limits<float>::is_iec559 << '\n';
  std::cout << std::numeric_limits<double>::is_iec559 << '\n';
  std::cout << std::numeric_limits<long>::is_iec559 << '\n';
}

bool stop() {
  std::string check;
  std::cout << "Are you sure you want to stop? y/n ... \n";
  std::cin >> check;
  if (!(check == "y" || check == "n")) {
    std::cout << "Incorect input, returning to menu...\n";
    return false;
  } else if (check == "y") {
    return true;
  } else if (check == "n") {
    return false;
  }
  return false;
}
