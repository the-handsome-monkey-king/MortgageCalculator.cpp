/******************************************************
*
*  MortgageCalculator.h
*
*  @author Ryan Morehouse
*  @license MIT
*
*  A simple class to encapsulate a mortgage calculator.
*
  *****************************************************/

#ifndef MORTGAGECALCULATOR_H
#define MORTGAGECALCULATOR_H

#include <string>

class MortgageCalculator {
  private:
    // input
    long principal, years, period;
    double interest;
    // output
    double total_payment, periodic_payment;

  public:
    MortgageCalculator(long principal, long years, long period, double
        interest);
    void calculate();

    // dollars, no cents
    long get_total_payment();
    long get_periodic_payment();

    // full amounts, all decimal points
    double get_total_payment_longform();
    double get_periodic_payment_longform();
    
    // get a formatted report
    std::string get_report();
};

#endif
