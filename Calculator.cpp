#include <iostream>
#include <sstream>
#include <stdexcept>
#include <limits>

// Create functions to add, subtract, multiply, and divide

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        throw std::invalid_argument("Error: Division by zero is not allowed.");
    }
    return a / b;
}

// Display a menu for the user to choose from

void displayMenu() {
    std::cout << std::endl;
    std::cout << "Choose an operation:\n";
    std::cout << "1. Addition (+)\n";
    std::cout << "2. Subtraction (-)\n";
    std::cout << "3. Multiplication (*)\n";
    std::cout << "4. Division (/)\n";
    std::cout << "q. Quit\n";
    std::cout << std::endl;
}

// Handle any invaid input from the user

void handleInvalidInput() {
    std::cerr << "Error: Invalid input. Please enter a valid expression.\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    std::string input;
    double num1, num2;
    char op;  

    // Create loop to keep displaying the menu until the user wants to quit

    while (true) {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::getline(std::cin, input);

        if (input == "q" || input == "Q") {
            break;
        }

        if (input.size() != 1 || (input[0] < '1' || input[0] > '4')) {
            handleInvalidInput();
            continue;
        }

        op = input[0];  
        
        // Prompt the user to enter two numbers for calculation
        
        if (op != 'q' && op != 'Q') {
            std::cout << "Enter two numbers with only a space between them: ";
            std::getline(std::cin, input);

            std::istringstream iss(input);
            if (!(iss >> num1 >> num2) || iss.rdbuf()->in_avail() != 0) {
                handleInvalidInput();
                continue;
            }

            // Determine what function to use by the user's input

            try {
                switch (op) {
                    case '1':
                        std::cout << "Result: " << add(num1, num2) << "\n";
                        break;
                    case '2':
                        std::cout << "Result: " << subtract(num1, num2) << "\n";
                        break;
                    case '3':
                        std::cout << "Result: " << multiply(num1, num2) << "\n";
                        break;
                    case '4':
                        std::cout << "Result: " << divide(num1, num2) << "\n";
                        break;
                }
            } catch (const std::invalid_argument &e) {
                std::cerr << e.what() << "\n";
            }
        }
    }

    std::cout << "Thanks for using the Calculator App!.\n";
    return 0;
}