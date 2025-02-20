// Copyright 2025 Abby Holdcraft & Jacob Sherer
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<string>
#include"MathTester.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::to_string;

int calculate(int num1, int num2, char operand);
const int num_terms = 3;

// Class to track different operands and their precedents
class Operand {
  public:
    char symbol;
    int precedent;
    Operand() {
      int i = rand() % 6;
      switch (i) {
      case 0: {
        symbol = '^';
        precedent = 3;
        break;
      }
      case 1: {
        symbol = '*';
        precedent = 2;
        break;
      }
      case 2: {
        symbol = '/';
        precedent = 2;
        break;
      }
      case 3: {
        symbol = '%';
        precedent = 2;
        break;
      }
      case 4: {
        symbol = '+';
        precedent = 1;
        break;
      }
      case 5: {
        symbol = '-';
        precedent = 1;
        break;
      }
      default:
        break;
      }
    }
};

int main() {
  char play_again;
  do {
    // Take inputs: number of expressions and goal time and maximum number
    cout << "Welcome to the mental arithmetic tester." << endl;
    cout << "How many expressions would you like to evaluate? " << endl;
    int correct_answers = 0;
    int num_expressions;
    cin >> num_expressions;
    while (num_expressions <= 1) {
      cout << "Invalid number of expressions. Please enter a different number: "
      << endl;
      cin >> num_expressions;
    }
    cout << "Great! What's your goal time (in seconds)? " << endl;
    int goal_time;
    cin >> goal_time;
    while (goal_time <= 0) {
      cout << "Invalid time. Please enter a different number: " << endl;
      cin >> goal_time;
    }
    cout << "Great! What would you like the maximum number to be?" << endl;
    int max_num;
    cin >> max_num;
    max_num++;
    while (max_num <= 1) {
      cout << "Invalid maximum. Please enter a number greater than 1." << endl;
      cin >> max_num;
      max_num++;
    }

    // Start clock
    srand(time(0));
    int start = time(0);
    int numbers[num_terms];
    for (int j = 0; j < num_expressions; j++) {
      int current_time = (time(0) - start);
      cout << "Expression " << (j+1) << " (seconds passed "
      << current_time << "):" << endl;

      // Select Operands
      Operand operands[num_terms-1];

      // Select Numbers
      numbers[0] = rand() % max_num;
      for (int i = 1; i < num_terms; i++) {
        int r = 0;
        if (operands[i-1].symbol == '/') {
          while (r == 0 || numbers[i-1] % r != 0)
            r = rand() % (max_num-1) + 1;
        } else if (operands[i-1].symbol == '%') {
          r = rand() % (max_num-1) + 1;
        } else {
          r = rand() % max_num;
        }
        numbers[i] = r;
      }

      // Calculate correct answer + create string to output if false
      int correct_answer;
      string incorrect_output;
      if (operands[0].precedent >= operands[1].precedent) {  // Solve L>R
        // Precedence output
        incorrect_output = operands[0].symbol;
        if (operands[0].precedent > operands[1].precedent)
          incorrect_output += " has higher precedence than ";
        else
          incorrect_output += " is on the same precedence level as ";
        incorrect_output += operands[1].symbol;
        incorrect_output += ".\nSo the expression evaluates as follows\n";

        // (a+b)+c
        incorrect_output += "(" + to_string(numbers[0]);
        incorrect_output += operands[0].symbol;
        incorrect_output += to_string(numbers[1]) + ")";
        incorrect_output += operands[1].symbol;
        incorrect_output +=  to_string(numbers[2]) + "\n";
        // a+b
        correct_answer =
        calculate(numbers[0], numbers[1], operands[0].symbol);
        incorrect_output += to_string(correct_answer);
        incorrect_output += operands[1].symbol;
        incorrect_output += to_string(numbers[2]) + "\n";
        // c
        correct_answer =
        calculate(correct_answer, numbers[2], operands[1].symbol);
        incorrect_output += to_string(correct_answer);
      } else {  // Solve R first
        // Precedence output
        incorrect_output = operands[1].symbol;
        incorrect_output += " has higher precedence than ";
        incorrect_output += operands[0].symbol;
        incorrect_output += ".\nSo the expression evaluates as follows\n";

        // a+(b+c)
        incorrect_output += to_string(numbers[0]);
        incorrect_output += operands[0].symbol;
        incorrect_output += "(" + to_string(numbers[1]);
        incorrect_output += operands[1].symbol;
        incorrect_output += to_string(numbers[2]) + ")\n";
        // a+b
        correct_answer =
        calculate(numbers[1], numbers[2], operands[1].symbol);
        incorrect_output += to_string(numbers[0]);
        incorrect_output += operands[0].symbol;
        incorrect_output += to_string(correct_answer) + "\n";
        // c
        correct_answer =
        calculate(numbers[0], correct_answer, operands[0].symbol);
        incorrect_output += to_string(correct_answer);
      }

      // Print equation
      cout << numbers[0];
      for (int i = 1; i < num_terms; i++) {
        cout << operands[i-1].symbol << numbers[i];
      }
      cout << '=';

      // Take user answer and compare
      int user_ans;
      cin >> user_ans;

      if (user_ans == correct_answer) {
        cout << "correct!" << endl;
        correct_answers++;
      } else {
        cout << incorrect_output << endl;
      }
    }

    // Output stats: number correct and time taken
    int current_time = time(0) - start;
    cout << endl;
    cout << "You correctly answered " << correct_answers << " of "
    << num_expressions << " question" << (num_expressions != 1 ? "s" : "");
    cout << " in " << current_time << " second" << (current_time != 1 ? "s" : "")
    << "." << endl;
    // Output: compare with goal time
    int difference = current_time - goal_time;
    if (current_time < goal_time) {
      difference *= -1;
      cout << "You beat your goal time by " << difference << " second"
      << (difference != 1 ? "s" : "") << "!" << endl;
    } else if (current_time > goal_time) {
      cout << "You exceeded your goal time by " << difference << " second"
      << (difference != 1 ? "s" : "") << "." << endl;
    } else {
      cout << "You met your goal time exactly!" << endl;
    }

    // Ask user if they want to play again
    cout << "That was fun! Do you want to play again? (y/n)" << endl;
    cin >> play_again;

    while (play_again != 'y' && play_again != 'n') {
      cout << "Invalid input. Please enter y or n." << endl;
      cin >> play_again;
    }
  } while (play_again == 'y');
  cout << "Thanks for playing!" << endl;
  return 0;
}

int calculate(int num1, int num2, char operand) {
  switch (operand) {
    case '^': {
      return pow(num1, num2);
    }
    case '*': {
      return num1 * num2;
    }
    case '/': {
      return num1 / num2;
    }
    case '%': {
      return num1 % num2;
    }
    case '+': {
      return num1 + num2;
    }
    case '-': {
      return num1 - num2;
    }
    default: {
      cout << "Invalid operand index at calculate." << endl;
      return 0;
    }
  }
}
