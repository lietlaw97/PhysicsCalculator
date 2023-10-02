#include "logging.h"
#include "kinematics.h"
#include <string>

void printing(double result1, double result2, std::string label1, std::string label2, std::string unit1, std::string unit2) {
	std::cout << "**********************\n";
	std::cout << label1 << result1 << unit1 << '\n';
	std::cout << label2 << result2 << unit2 << '\n';
	std::cout << "**********************\n";
}


void kinematicsResult() {
	KinematicsInput kinematicsInput = getKinematicsInput();
	
	if (std::isnan(kinematicsInput.distance)) {
		if (std::isnan(kinematicsInput.acceleration)) {
			auto results = Kinematics::dispaccel(kinematicsInput.initialVelocity, kinematicsInput.finalVelocity, kinematicsInput.time, kinematicsInput.distance, kinematicsInput.acceleration);
			printing(results.first, results.second, "Acceleration (a): ", "Displacement (s): ", " m/s^2", " m");
		}
		else if (std::isnan(kinematicsInput.time)) {
			auto results = Kinematics::distime(kinematicsInput.initialVelocity, kinematicsInput.finalVelocity, kinematicsInput.time, kinematicsInput.distance, kinematicsInput.acceleration);
			printing(results.first, results.second, "Displacement (s): ", "Time (t): ", " m", " s");
		}
		else if (std::isnan(kinematicsInput.initialVelocity)) {
			auto results = Kinematics::distiniv(kinematicsInput.initialVelocity, kinematicsInput.finalVelocity, kinematicsInput.time, kinematicsInput.distance, kinematicsInput.acceleration);
			printing(results.first, results.second, "Displacement (s): ", "Initial Velocity (u): ", " m", " m/s");
		}
		
		else if (std::isnan(kinematicsInput.finalVelocity)) {
			auto results = Kinematics::distfiniv(kinematicsInput.initialVelocity, kinematicsInput.finalVelocity, kinematicsInput.time, kinematicsInput.distance, kinematicsInput.acceleration);
			printing(results.first, results.second, "Displacement (s): ", "Final Velocity (v): ", " m", " m/s");
		}
	}

	else if (std::isnan(kinematicsInput.time)) {
		if (std::isnan(kinematicsInput.finalVelocity)) {
			auto results = Kinematics::finvtime(kinematicsInput.initialVelocity, kinematicsInput.finalVelocity, kinematicsInput.time, kinematicsInput.distance, kinematicsInput.acceleration);
			printing(results.first, results.second, "Final Velocity (v): ", "Time: (t) ", " m/s", " s");
	}
		else if (std::isnan(kinematicsInput.initialVelocity)) {
			auto results = Kinematics::inivtime(kinematicsInput.initialVelocity, kinematicsInput.finalVelocity, kinematicsInput.time, kinematicsInput.distance, kinematicsInput.acceleration);
			printing(results.first, results.second, "Initial Velocity (u): ", "Time (t): ", " m/s", " s");
		}
		else if (std::isnan(kinematicsInput.acceleration)) {
			auto results = Kinematics::acctime(kinematicsInput.initialVelocity, kinematicsInput.finalVelocity, kinematicsInput.time, kinematicsInput.distance, kinematicsInput.acceleration);
			printing(results.first, results.second, "Acceleration (a): ", "Time (t): ", " m/s^2", " s");
		}
	}

	else if (std::isnan(kinematicsInput.acceleration)) {
		if (std::isnan(kinematicsInput.finalVelocity)) {
			auto results = Kinematics::finalvacc(kinematicsInput.initialVelocity, kinematicsInput.finalVelocity, kinematicsInput.time, kinematicsInput.distance, kinematicsInput.acceleration);
			printing(results.first, results.second, "Acceleration (a): ", "Final Velocity (v): ", " m/s^2", " m/s");
		}
		else if (std::isnan(kinematicsInput.initialVelocity)) {
			auto results = Kinematics::inivacc(kinematicsInput.initialVelocity, kinematicsInput.finalVelocity, kinematicsInput.time, kinematicsInput.distance, kinematicsInput.acceleration);
			printing(results.first, results.second, "Initial Velocity (u): ", "Acceleration (a): ", " m/s", " m/s^2");
		}
	}

	else if (std::isnan(kinematicsInput.finalVelocity) and std::isnan(kinematicsInput.initialVelocity)) {
		
		auto results = Kinematics::inivfinalv(kinematicsInput.initialVelocity, kinematicsInput.finalVelocity, kinematicsInput.time, kinematicsInput.distance, kinematicsInput.acceleration);
		printing(results.first, results.second, "Initial Velocity (u): ", "Final Velocity (v): ", " m/s", " m/s");	
	}

	else {
		std::cout << "Unsupported combination of inputs. Please check your inputs.\n";
	}
}