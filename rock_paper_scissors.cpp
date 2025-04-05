#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <list>

using namespace std;

int main() {

  // computer makes random choice from 1 to 5
  srand(time(0)); // makes sure output changes every time program runs
  int cpu_choice = rand() % 5 + 1;
  list<string> cpu_choice_name = {"Rock", "Paper", "Scissors", "Lizard", "Spock"};

  // initialises player choice
  int player_choice = 0;

  // prompts player for choice
  cout << "Make your choice: " << endl;
  cout << "1: Rock\n2: Paper\n3: Scissors\n";
  cout << "4: Lizard\n5: Spock" << endl;
  cin >> player_choice;

  // prints computer choice
  auto iterator = cpu_choice_name.begin();
  advance(iterator, cpu_choice - 1);
  cout << "CPU chose " << cpu_choice << ": " << *iterator << endl;

  // handles tie now so that i can ignore this case later
  if (player_choice == cpu_choice) {
    cout << "It's a tie!" << endl;
    return 0;
  }

  // compares player and cpu choice, considering the game's rules
  switch(player_choice) {
    case 1: // rock
      if ((cpu_choice == 3) || (cpu_choice == 4)) {
        cout << "You win!" << endl; // crushes scissors and lizard
      } else {
        cout << "You lose!" << endl; // paper covers, spock vaporises
      }
      break;
    case 2: // paper  
      if ((cpu_choice == 1) || (cpu_choice == 5)) {
        cout << "You win!" << endl; // covers rock, disproves Spock 
      } else {
        cout << "You lose!" << endl; // scissors cut, lizard eats
      }
      break;
    case 3: // scissors
      if ((cpu_choice == 2) || (cpu_choice == 4)) {
        cout << "You win!" << endl; // cuts paper, decapitates lizard 
      } else {
        cout << "You lose!" << endl; // rock breaks, Spock smashes
      }
      break;
    case 4: // lizard 
      if ((cpu_choice == 2) || (cpu_choice == 5)) {
        cout << "You win!" << endl; // eats paper, poisons Spock 
      } else {
        cout << "You lose!" << endl; // rock crushes, scissors decapitate 
      }
      break;
    case 5: // Spock 
      if ((cpu_choice == 1) || (cpu_choice == 3)) {
        cout << "You win!" << endl; // vaporises rock, smashes scissors 
      } else {
        cout << "You lose!" << endl; // paper disproves, lizard poisons 
      }
      break;
    default:
      cout << "You chose wrong bro" << endl; // user didn't read instructions lol
  }

}

