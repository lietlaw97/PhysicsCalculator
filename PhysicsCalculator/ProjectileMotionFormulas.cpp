#include "ProjectileMotion.h"



ProjectileMotionInputs getProjectileMotionInputs() {
	ProjectileMotionInputs pjm;
	std::cout << "Note that the default units are m, s, deg, m/s\n";
	pjm.initialHeight = getInput("Initial Height: ");
	pjm.timeofFlight = getInput("Time of Flight: ");
	pjm.range = getInput("Range/Distance: ");
	pjm.angleofLaunch = getInput("Angle of Launch in deg: ");
	pjm.initialVelocity = getInput("Initial Velocity: ");
	pjm.maximumHeight = getInput("Maximum Height: ");
	std::cout << '\n';
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return pjm;
}


double Formulas::anglerad(double angle) {

	return angle * (M_PI / 180); //converting the input from deg to rad cause argument for sin() is in radians
}

double Formulas::time(double initH, double initV, double angleL, const double& grav) {
	double Vy = initV * sin(anglerad(angleL));
	double timeFlight = (Vy + sqrt((pow(Vy, 2) + 2 * grav * initH)))/grav;
	return timeFlight;
	
}

double Formulas::range(double initH, double angleLaunch, const double& gravity, double initialVelocity) {
	double angleinRad = anglerad(angleLaunch);
	double Vx = initialVelocity * cos(angleinRad);
	double Vy = initialVelocity * sin(angleinRad);
	double range = Vx * (Vy + (sqrt(pow(Vy, 2) + 2 * gravity * initH)))/ gravity;	
	return range;	
}

double Formulas::maxheight(double initV, double angleL, const double& gravity, double initialH) {
	double Vy = initV * sin(anglerad(angleL));
	double maxheight =  ((pow(Vy, 2)) / (2*gravity)) + initialH;
	return maxheight;
}
