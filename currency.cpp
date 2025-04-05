#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// function to convert an amount of a currency to dollars
double ConvertToUSD(double amount, int currency) {

  // approximate currency conversion factors on 2025-04-05
  switch(currency){
    case 1: // USD
      return amount;
    case 2: // BRL
      return amount * 0.1711;
    case 3: // PEN
      return amount * 0.27;
    case 4: // COP
      return amount * 0.00024;
    case 5: // EUR
      return amount * 1.1;
    default:
      cout << currency << " is not a supported number." << endl;
      return 0;
  }
  return 0;
}


int main() {

  // variables to track total
  double total = 0, converted_amount = 0;

  // variables to call conversion function
  double amount = 0;
  int currency;

  // welcome message
  cout << "Welcome to the currency conversion tool!" << endl;

  // initialises loop
  while(true) {
  
    // currency input
    cout << "Choose currency:\n";
    cout << "1: USD\n2: BRL\n3: PEN\n4: COP\n5: EUR\n0: quit" << endl;
    cin >> currency;
    
    // quits if user chooses
    if(currency == 0){
      break; 
    }
    
    // amount input
    cout << "\nEnter amount: ";
    cin >> amount;
   
    // applies conversion function, adds to total
    converted_amount = ConvertToUSD(amount, currency);
    total += converted_amount;

    // informs user of running total
    cout << "\nAdded " << converted_amount << " USD." << endl;
    cout << "Your current total is " << fixed << setprecision(2)
    << total << " USD." << endl;
    cout << "==============\n" << endl;
  };

  // prints total to user
  cout << "\nYour final total is " << total << " USD. Thanks for using the tool!" << endl;

  return 0;
}

