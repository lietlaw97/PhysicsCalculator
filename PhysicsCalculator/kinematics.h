#pragma once
#include <utility>
#include <string>

void kinematicsResult();
void printing(double result1, double result2, std::string label1, std::string label2, std::string unit1, std::string unit2);

struct KinematicsInput {
    double initialVelocity;
    double finalVelocity;
    double time;
    double distance;
    double acceleration;

};



KinematicsInput getKinematicsInput();

struct Kinematics {
    static std::pair<double, double> dispaccel(double initialV, double finalV, double t, double dis, double acc);
    static std::pair<double, double> distime(double initialV, double finalV, double t, double dis, double acc);
    static std::pair<double, double> distiniv(double initialV, double finalV, double t, double dis, double acc);
    static std::pair<double, double> distfiniv(double initialV, double finalV, double t, double dis, double acc);
    static std::pair<double, double> finalvacc(double initialV, double finalV, double t, double dis, double acc);
    static std::pair<double, double> inivacc(double initialV, double finalV, double t, double dis, double acc);
    static std::pair<double, double> finvtime(double initialV, double finalV, double t, double dis, double acc);
    static std::pair<double, double> inivtime(double initialV, double finalV, double t, double dis, double acc);
    static std::pair<double, double> acctime(double initialV, double finalV, double t, double dis, double acc);
    static std::pair<double, double> inivfinalv(double initialV, double finalV, double t, double dis, double acc);

};

