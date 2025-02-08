// Copyright 2025 Abby Holdcraft
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

void calculate_decimal(int num, int base);
void print_highest();

int highest_num;
int highest_num_index = -1;
int current_index = 0;

int main() {
    int numbers[100];
    int bases[100];

    // Take inputs
    for (char next = 'y'; next == 'y'; current_index++) {
        int inputNum;
        int inputBase;
        cin >> inputNum;
        numbers[current_index] = inputNum;
        cin >> inputBase;
        bases[current_index] = inputBase;
        cin >> next;
        if (next != 'n' && next != 'y')
            cout << "Invalid character. Stop." << endl;
    }

    // Print results
    int i = current_index;
    for (current_index = 0; current_index < i; current_index++)
        calculate_decimal(numbers[current_index], bases[current_index]);

    // Print highest number
    if (highest_num_index != -1) {
        print_highest();
        cout << endl;
    }

    return 0;
}

void calculate_decimal(int num, int base) {
    // Check valid base
    if (base < 2 || base > 9) {
         cout << "Base Not Accepted" << endl;
         exit(0);
    }
    int temp_num = num;
    int decimal_num = 0;
    int power = 0;
    for (int i = 0; temp_num != 0; i++) {
        // Get digit
        int digit = temp_num % 10;
        if (digit < 0)
            digit *= -1;
        temp_num /= 10;

        // Check valid number
        if (digit >= base) {
            cout << "Invalid Digit(s) in Number" << endl;
            exit(0);
        }

        // Convert to decimal
        if (i == 0)
            power = 1;
        else
            power *= base;
        decimal_num += digit * power;
    }
    if (num < 0)
        decimal_num *= -1;

    // Find highest
    if (highest_num < decimal_num || highest_num_index == -1) {
        highest_num = decimal_num;
        highest_num_index = current_index + 1;
    }

    // return
    cout << decimal_num << endl;
}

void print_highest() {
    cout << "Of the " << current_index << " values input, the ";
    cout << highest_num_index;
    if (highest_num_index % 100 < 10 || highest_num_index % 100 > 20) {
        if (highest_num_index % 10 == 1)
            cout << "st";
        else if (highest_num_index % 10 == 2)
            cout << "nd";
        else if (highest_num_index % 10 == 3)
            cout << "rd";
        else
            cout << "th";
    } else {
        cout << "th";
    }
    cout << " value entered (" << highest_num << ") was the largest";
    return;
}
