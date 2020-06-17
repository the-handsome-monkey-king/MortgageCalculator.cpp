/*************************************************************
*
*  test_calculator.cpp
*
*  @author Ryan Morehouse
*  @license MIT
*
*  A test of the functionality of the MortgageCalculator class.
*
  ************************************************************/

#include <string>
#include <sstream>
#include "TerminalPrompt.h"
#include "MortgageCalculator.h"

int main() {
  // user variables
  long principal, years, period;
  double interest;

  TerminalPrompt term;

  // get principal
  std::string prompt = "Please enter the principal without decimal place";
  principal = term.get_positive_long(&prompt);

  // get years
  prompt = "Please enter the years for the mortgage";
  years = term.get_positive_long(&prompt);

  // get period
  std::ostringstream oss;
  oss << "Please enter the period from the selection below:\n";
  oss << "1. Monthly (12 per annum)\n";
  oss << "2. Weekly (48 per annum)\n";
  oss << "3. Daily (365 per annum)\n";
  oss << "> ";
  prompt = oss.str();
  int selection;
  bool is_valid = false;
  while(!is_valid) {
    selection = term.get_positive_int(&prompt);
    if (selection == 1 || selection == 2 || selection == 3) {
      is_valid = true;
      break;
    } else {
      std::cout << "Please select from the menu options, try again.\n";
    }
  }

  switch (selection) {
    case 1:
      period = 12;
      break;
    case 2:
      period = 48;
      break;
    case 3:
      period = 365;
      break;
  }

  // get interest
  prompt = "Please enter the interest (%5 as 0.05, etc)";
  interest = term.get_positive_double(&prompt);

  std::cout << "Principal: " << principal << std::endl;
  std::cout << "Years: " << years << std::endl;
  std::cout << "Period (in days per annum): " << period << std::endl;
  std::cout << "Interest: " << interest << std::endl;

  // plug variables into calculator
  MortgageCalculator calc(principal, years, period, interest);
  calc.calculate();

  std::cout << calc.get_report();

  return 0;
}
