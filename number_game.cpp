#include <iostream>
#include <cstdlib>   // Needed for rand() and srand()
#include <ctime>     // Needed for time()

int main() {
    // Seed the random number generator using the system clock
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Generate a random number between 1 and 100
    int secretNumber = (std::rand() % 100) + 1;
    int userGuess = 0;
    int attempts = 0;

    std::cout << "=================================\n";
    std::cout << "   WELCOME TO THE GUESSING GAME  \n";
    std::cout << "=================================\n";
    std::cout << "I have chosen a number between 1 and 100.\n";
    std::cout << "Can you guess what it is?\n\n";

    // Loop until the user guesses the correct number
    do {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;
        attempts++; // Increment the try counter

        if (userGuess > secretNumber) {
            std::cout << "Too high! Try a lower number.\n\n";
        } else if (userGuess < secretNumber) {
            std::cout << "Too low! Try a higher number.\n\n";
        } else {
            std::cout << "\n🎉 Congratulations! You got it right!\n";
            std::cout << "It took you " << attempts << " attempts to solve it.\n";
        }
    } while (userGuess != secretNumber);

    return 0;
}
