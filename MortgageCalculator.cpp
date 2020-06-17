/******************************************************
*
*  MortgageCalculator.cpp
*
*  @author Ryan Morehouse
*  @license MIT
*
*  A simple class to encapsulate a mortgage calculator.
*
  *****************************************************/

#include <math.h>
#include <sstream>
#include <stdexcept>
#include "MortgageCalculator.h"

MortgageCalculator::MortgageCalculator(
    long principal, long years, long period, double interest) 
{
  // verify input
  if(principal <= 0 || years <= 0 || period <= 0 || interest <= 0)
    throw std::invalid_argument("Invalid non-positive arguments.");
  
  this->principal = principal;
  this->years = years;
  this->period = period;
  this->interest = interest;

  this->total_payment = 0;
  this->periodic_payment = 0;
}

void MortgageCalculator::calculate() {
  // total # of payments
  double all_periods = static_cast<double>(this->years);
  all_periods *= static_cast<double>(this->period);

  // payment per period
  double pay = static_cast<double>(principal);
  pay *= this->interest * pow(1.0 + this->interest, all_periods);
  pay /= pow(1.0 + this->interest, all_periods) - 1.0;
  this->periodic_payment = pay;
  this->total_payment = pay * all_periods;
}

long MortgageCalculator::get_total_payment() {
  return static_cast<long>(this->total_payment);
}

long MortgageCalculator::get_periodic_payment() {
  return static_cast<long>(this->periodic_payment);
}

double MortgageCalculator::get_total_payment_longform() {
  return this->total_payment;
}

double MortgageCalculator::get_periodic_payment_longform() {
  return this->periodic_payment;
}

std::string MortgageCalculator::get_report() {
  std::ostringstream oss;
  oss << "Principal: " << this->principal << "\n";
  oss << "Years: " << this->years << "\n";
  oss << "Period per annum: " << this->period << "\n";
  oss << "Interest: " << this->interest << std::endl << "\n";
  oss << "Total Payment (rounded): " << static_cast<long>(this->total_payment) << "\n";
  oss << "Periodic Payment (rounded): ";
  oss << static_cast<long>(this->periodic_payment) << "\n";
  return oss.str();
}
