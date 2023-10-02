#include "kinematics.h"
#include "logging.h"


//getting the necessary values from the KinematicsInput struct
KinematicsInput getKinematicsInput() {
    KinematicsInput input;

    std::cout << "Note that the default unit is m, m/s, s, and m/s^2. Use 's' to skip if there is none\n\n";
    input.initialVelocity = getInput("Initial Velocity: ");
    input.finalVelocity = getInput("Final Velocity: ");
    input.time = getInput("Time: ");
    input.distance = getInput("Distance/Displacement: ");
    input.acceleration = getInput("Acceleration: ");
    std::cout << "\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return input;
}

//  formulas to be use
//  unit s = displacement/distance, t = time, u = initial velocity, v = final velocity, a = constant acceleration
//  velocity v = u + at
//  displacement/distance s = ut + 1/2at^2
//  time independent velocity v^2 = u^2 + 2as
//  acceleration independent displacement s = (1/2*(v+u))/t

    std::pair<double, double> Kinematics::dispaccel(double initialV, double finalV, double t, double dis, double acc) {
        //if acceleration & displacement is none 
        double acceleration = (finalV - initialV) / t;
        double displacement = (initialV * t) + (0.5 * acceleration * pow(t, 2.0));
        return std::make_pair(acceleration, displacement);
    }

    std::pair<double, double> Kinematics::distime(double initialV, double finalV, double t, double dis, double acc) {
        //if displacement & time is none
        double time = (finalV - initialV) / acc;
        double displacement = (initialV * time) + (0.5 * acc * pow(time, 2.0));
        return std::make_pair(displacement, time);
    }

    std::pair<double, double> Kinematics::distiniv(double initialV, double finalV, double t, double dis, double acc) {
        //if displacement & initial velocity is none
        double initialVel = finalV - (acc * t);
        double displacement = (initialVel * t) + (0.5 * acc * pow(t, 2.0));
        return std::make_pair(displacement, initialVel);
    }

    std::pair<double, double> Kinematics::distfiniv(double initialV, double finalV, double t, double dis, double acc) {
        // if displacement & final velocity is none
        double finalVel = initialV + (acc * t);
        double displacement = (initialV * t) + (0.5 * acc * pow(t, 2));
        return std::make_pair(displacement, finalVel);
    }
    std::pair<double, double> Kinematics::finalvacc(double initialV, double finalV, double t, double dis, double acc) {
        // if final velocity & acceleration is none
        double acceleration = (dis - (initialV * t)) / (0.5 * pow(t, 2));
        double finalVel = initialV + (acceleration * t);
        return std::make_pair(acceleration, finalVel);
    }
    std::pair<double, double> Kinematics::inivacc(double initialV, double finalV, double t, double dis, double acc) {
        // if inital velocity & acceleration is none
        double initialVel = ((2 * dis) / t) - finalV;
        double acceleration = (finalV - initialVel) / t;
        return std::make_pair(initialVel, acceleration);

    }
    std::pair<double, double> Kinematics::finvtime(double initialV, double finalV, double t, double dis, double acc) {
        // if final velocity & time is none
        double finalVel = sqrt(pow(initialV, 2) + (2 * acc * dis));
        double time = (finalVel - initialV) / acc;
        return std::make_pair(finalVel, time);
    }
    std::pair<double, double> Kinematics::inivtime(double initialV, double finalV, double t, double dis, double acc) {
        // if initial velocity & time is none
        double initialVel = sqrt(pow(finalV, 2) - (2 * acc * dis));
        double time = (finalV - initialVel) / acc;
        return std::make_pair(initialVel, time);

    }
    std::pair<double, double> Kinematics::acctime(double initialV, double finalV, double t, double dis, double acc) {
        // if acceleration & time is none
        double time = (2 * dis) / (finalV + initialV);
        double acceleration = (finalV - initialV) / time;
        return std::make_pair(acceleration, time);
    }
    std::pair<double, double> Kinematics::inivfinalv(double initialV, double finalV, double t, double dis, double acc) {
        // if initial velocity & final velocity is none
        double initialVel = (dis / t) - (0.5 * acc * t);
        double finalVel = initialVel + (acc * t);
        return std::make_pair(initialVel, finalVel);
    }



