#pragma once
#define _USE_MATH_DEFINES
#include "logging.h"

static const double gravity = 9.8;

void getPJMResults();

struct ProjectileMotionInputs {
	double initialHeight;
	double maximumHeight;
	double timeofFlight;
	double range;
	double angleofLaunch;
	double initialVelocity;

};


ProjectileMotionInputs getProjectileMotionInputs();


struct Formulas {
	static double anglerad(double angle);
	static double time(double initH, double initV, double angleL, const double& grav);
	static double range(double initH, double angleLaunch, const double& gravity, const double initialVelocity);
	static double maxheight(double initV, double angleL, const double& gravity, double initialH);
};