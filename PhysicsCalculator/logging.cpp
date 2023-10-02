#include "logging.h"
#include "kinematics.h"
#include "ProjectileMotion.h"
#include <limits>

void displayHelp() {
	std::cout << commands;
}

double getInput(const std::string& prompt) {
	// Getting the input from the user using this function instead of using "cout" and "cin" repetitively
	std::string input;
	double value;
	std::cout << prompt;
	std::cin >> input;

	if (input == "s") {
		return std::numeric_limits<double>::quiet_NaN(); // NaN as a sentinel for skipped value because using any number, the computation will treat it as an actual number 
	}
	
	// Convert input to double
	value = std::stod(input);
	return value;
}


void inputOutput() {

	std::string command;
	std::string mode;
	std::cout << banner;
	std::cout << instruction;
	bool running = true;
	
	while (running) {
		std::cout << "$ ";
		std::getline(std::cin, command); // Read the entire line
		std::istringstream iss(command); // Create a string stream from the input line
		std::string command;
		iss >> command; // Read the first word as the command. Some users put space after the command, this line make sure that the command works even though it has space in it.

		if (command == "help") {
			displayHelp();
		}

		else if (command == "view") {
			std::cout << categories;
		}
		else if (command == "quit") {
			running = false;
		}

		else if (command == "use") {
			iss >> mode;

			if (mode == "") {
				std::cout << "Please choose a category.\n";
			}

			else if(mode == "kinematics") {
				kinematicsResult();
			}
			else if (mode == "projectilemotion") {
				getPJMResults();
			}
			
		}
		else {
			std::cout << command << ": command not found\n";
		}

	}

}


