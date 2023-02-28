#include <iostream>
#include <ctime>

using namespace std;

int main() {
    srand((unsigned int)time(NULL)); // set random seed

    const int number = rand() % 100 + 1;
    int guess;
    int number_of_guesses = 0;

    cout << "## Welcome to guess the number game ##" << endl;

    do{
        cout << "Please, guess a number between 1 and 100> " << flush;
        cin >> guess;

        if(guess > number) cout << "Too high!" << endl;
        if(guess < number) cout << "Too low!" << endl;
        number_of_guesses++;

    }while(guess != number);

    cout << "Congratulations! The number is " << number << endl;
    cout << "It took you " << number_of_guesses << " guesses to get it right!" << endl;
    
    return 0;
}