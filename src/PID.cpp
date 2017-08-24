#include "PID.h"

#include <math.h>


PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    this->Kd = Kd;
    this->Kp = Kp;
    this->Ki = Ki;
}

void PID::UpdateError(double cte) {
    d_error = cte - p_error;
    p_error = cte;
    i_error += cte;
}

double PID::cappedControl() {
    double control = Kp * p_error + Kd * d_error + Ki * i_error;
    if (control > 1) control = 1;
    if (control < -1) control = -1;
    return control;
}

double PID::TotalError() {
    return i_error;
}

