#include <iostream>

using namespace std;

int main() {
  // initialises variables for currencies
  double col_pesos, bra_reais, per_soles, usd; 
  
  // initialises variables for conversions (approximate values on 2025-04-05)
  double col_to_usd = 0.00024, bra_to_usd = 0.1711, per_to_usd = 0.27; 

  // asks for user input of each currency
  cout << "Amount of Colombian pesos: ";
  cin >> col_pesos;
  cout << "Amount of Brazilian reais: ";
  cin >> bra_reais;
  cout << "Amount of Peruvian Soles: ";
  cin >> per_soles;

  // applies conversions
  usd = col_pesos * col_to_usd + bra_reais  * bra_to_usd + per_soles * per_to_usd;

  cout << "Total in USD: $" << usd << endl;

  return 0;
}

