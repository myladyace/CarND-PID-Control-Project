#include "PID.h"
#include <cmath>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  PID::Kp = Kp;
  PID::Ki = Ki;
  PID::Kd = Kd;
  p_error = 0;
  i_error = 0;
  d_error = 0;
  init = true;
  total_error = 0;
}

void PID::UpdateError(double cte) {
  if(init==true){
    p_error = cte;
  }
  d_error = cte - p_error;
  p_error = cte;
  i_error += cte;

  total_error += pow(cte, 2);
}

double PID::TotalError() {
  return total_error;
}

