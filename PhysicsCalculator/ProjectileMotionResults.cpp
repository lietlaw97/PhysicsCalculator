#include "ProjectileMotion.h"


void getPJMResults() {
	std::string calculation;
	std::cout << "****************\n";
	std::cout << "1.Range\n";
	std::cout << "2.Time\n";
	std::cout << "3.Height\n";
	std::cout << "****************\n";
	std::cout << "Choose the calculation: ";
	std::getline(std::cin, calculation);
	std::istringstream iss(calculation);
	iss >> calculation;


	ProjectileMotionInputs pjmInputs = getProjectileMotionInputs();
 
		if (calculation == "range") {
			std::cout << "Range: " << Formulas::range(pjmInputs.initialHeight, pjmInputs.angleofLaunch, gravity, pjmInputs.initialVelocity) << 'm' << '\n';
		}
		else if (calculation == "time") {
			std::cout << "Time: " << Formulas::time(pjmInputs.initialHeight, pjmInputs.initialVelocity, pjmInputs.angleofLaunch, gravity) << 's' << '\n';
		}
		else if (calculation == "height") {
			std::cout << "Maximum Height: " << Formulas::maxheight(pjmInputs.initialVelocity, pjmInputs.angleofLaunch, gravity, pjmInputs.initialHeight) << 'm' << '\n';
		}
	}

	
