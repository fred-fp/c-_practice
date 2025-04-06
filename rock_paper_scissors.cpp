#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <list>

using namespace std;

int PlayerChoice() {

  int player_choice;
  
  cout << "Make your choice: " << endl;
  cout << "1: Rock\n2: Paper\n3: Scissors\n";
  cout << "4: Lizard\n5: Spock" << endl;
  cin >> player_choice;
  
  return player_choice;
}

// compares player vs CPU choices, handles result
double ResultHandler(int player_choice, int cpu_choice) {
 
  // handles ties, returns half a point
  if (player_choice == cpu_choice) {
    cout << "It's a tie!" << endl;
    return 0.5;
  }
 
  // handles wins and losses
  switch(player_choice) {

    case 1: // rock

      if (cpu_choice == 2) {
        cout << "Paper covers Rock, you lose!" << endl;
        return 0;
      } else if (cpu_choice == 3) {
        cout << "Rock crushes Scissors, you win!" << endl;
        return 1;
      } else if (cpu_choice == 4) {
        cout << "Rock crushes Lizard, you win!" << endl;
        return 1;
      } else if (cpu_choice == 5) {
        cout << "Spock vaporises Rock, you lose!" << endl;
        return 0;
      }
      break;

    case 2: // paper

      if (cpu_choice == 1) {
        cout << "Paper covers Rock, you win!" << endl;
        return 1;
      } else if (cpu_choice == 3) {
        cout << "Scissors cuts Paper, you lose!" << endl;
        return 0;
      } else if (cpu_choice == 4) {
        cout << "Lizard eats Paper, you lose!" << endl;
        return 0;
      } else if (cpu_choice == 5) {
        cout << "Paper disproves Spock, you win!" << endl;
        return 1;
      }
      break;

    case 3: // scissors

      if (cpu_choice == 1) {
        cout << "Rock crushes Scissors, you lose!" << endl;
        return 0;
      } else if (cpu_choice == 2) {
        cout << "Scissors cuts Paper, you win!" << endl;
        return 1;
      } else if (cpu_choice == 4) {
        cout << "Scissors decapitates Lizard, you win!" << endl;
        return 1;
      } else if (cpu_choice == 5) {
        cout << "Spock smashes Scissors, you lose!" << endl;
        return 0;
      }
      break;

    case 4: // Lizard 

      if (cpu_choice == 1) {
        cout << "Rock crushes Lizard, you lose!" << endl;
        return 0;
      } else if (cpu_choice == 2) {
        cout << "Lizard eats Paper, you win!" << endl;
        return 1;
      } else if (cpu_choice == 3) {
        cout << "Scissors decapitates Lizard, you lose!" << endl;
        return 0;
      } else if (cpu_choice == 5) {
        cout << "Lizard poisons Spock, you win!" << endl;
        return 1;
      }
      break;

    case 5: // Spock 

      if (cpu_choice == 1) {
        cout << "Spock vaporises Rock, you win!" << endl;
        return 1;
      } else if (cpu_choice == 2) {
        cout << "Paper disproves Spock, you lose!" << endl;
        return 0;
      } else if (cpu_choice == 3) {
        cout << "Spock smashes Scissors, you win!" << endl;
        return 1;
      } else if (cpu_choice == 4) {
        cout << "Lizard poisons Spock, you lose!" << endl;
        return 0;
      }
      break;

    default:
      cout << "You chose wrong bro, no points for you" << endl; 
      return 0;
      break;
  }

  return 0;
}


int main() {

  double points = 0;
  int rounds;
  
  // intro message, choice of rounds
  cout << "\n\nWelcome to Rock Paper Scissors Lizard Spock!" << endl;
  cout << "How many rounds would you like to play?" << endl;
  cin >> rounds;

  // initialises gameplay loop for the specified amount of rounds
  for (int i = 0; i < rounds; i++){
   
    cout << "\n==============" << endl;
    cout << "ROUND " << i+1 << endl;

    // player makes choice
    int player_choice = 0;
    player_choice = PlayerChoice();

    // computer makes random choice from 1 to 5
    srand(time(0)); // makes sure output changes every time program runs
    int cpu_choice = rand() % 5 + 1;
    list<string> cpu_choice_name = {"Rock", "Paper", "Scissors", "Lizard", "Spock"};

    // prints computer choice
    auto iterator = cpu_choice_name.begin();
    advance(iterator, cpu_choice - 1);
    cout << "\nCPU chose " << *iterator << "." << endl;


    points += ResultHandler(player_choice, cpu_choice);

  }

  // prints final results
  cout << "\n\nFINAL RESULTS" << endl;
  cout << "After " << rounds << " rounds, you won " << points << " points!" << endl;

}

