#pragma once
#include <sstream>
#include <iostream>
#include <cmath>

static void displayHelp();
void inputOutput();

double getInput(const std::string& prompt);



//Welcome message

static const char* instruction = R"""(
Enter the physics category you need (e.g., kinematics, dynamics) 
and follow the prompts to input values. Use the interactive menu to explore options. 
Convert units for convenience. For help, type "help" to view basic commands. Enjoy calculating with ease!

)""";

static const char* banner = R"""(
========================
  Welcome to PhysiCal   
========================
)""";

static const char* commands = R"""(
Available commands
help - display this message
use <category> - use the desired category
view - display all the available category
quit - exit the program
)""";

static const char* categories = R"""(
1. Kinematics
2. Dynamics
3. Projectile Motion
*****MORE CATEGORIES SOON*****
)""";