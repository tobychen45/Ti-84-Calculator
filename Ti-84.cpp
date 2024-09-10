#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

// Function prototypes
void showMenu();
void performBasicOperation(int choice);
void performTrigonometricOperation(int choice);
double getNumber();
double getPositiveNumber();
double getAngle();

// Main menu function
void showMenu() {
    cout << "================= TI-84 Calculator =================" << endl;
    cout << "Please select an operation from the list below:" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Exponentiation (Power)" << endl;
    cout << "6. Square Root" << endl;
    cout << "7. Sine (sin)" << endl;
    cout << "8. Cosine (cos)" << endl;
    cout << "9. Tangent (tan)" << endl;
    cout << "0. Exit" << endl;
    cout << "====================================================" << endl;
}

// Function to get a valid numerical input from the user
double getNumber() {
    double num;
    while (!(cin >> num)) {
        cin.clear(); // Clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        cout << "Invalid input. Please enter a valid number: ";
    }
    return num;
}

// Function to get a positive number (for square root)
double getPositiveNumber() {
    double num;
    do {
        cout << "Enter a positive number: ";
        num = getNumber();
        if (num < 0) {
            cout << "Error: Square root of a negative number is undefined!" << endl;
        }
    } while (num < 0);
    return num;
}

// Function to get an angle for trigonometric operations
double getAngle() {
    cout << "Enter the angle in radians: ";
    return getNumber();
}

// Function to perform basic arithmetic operations
void performBasicOperation(int choice) {
    double num1, num2, result;

    // Get input numbers
    if (choice != 6) { // For non-square root operations
        cout << "Enter the first number: ";
        num1 = getNumber();
        cout << "Enter the second number: ";
        num2 = getNumber();
    } else { // For square root
        num1 = getPositiveNumber(); // Ensure positive input
    }

    // Perform the selected operation
    switch (choice) {
        case 1:
            result = num1 + num2;
            cout << "Result: " << num1 << " + " << num2 << " = " << result << endl;
            break;
        case 2:
            result = num1 - num2;
            cout << "Result: " << num1 << " - " << num2 << " = " << result << endl;
            break;
        case 3:
            result = num1 * num2;
            cout << "Result: " << num1 << " * " << num2 << " = " << result << endl;
            break;
        case 4:
            if (num2 != 0) {
                result = num1 / num2;
                cout << "Result: " << num1 << " / " << num2 << " = " << result << endl;
            } else {
                cout << "Error: Division by zero is not allowed!" << endl;
            }
            break;
        case 5:
            result = pow(num1, num2);
            cout << "Result: " << num1 << " ^ " << num2 << " = " << result << endl;
            break;
        case 6:
            result = sqrt(num1);
            cout << "Square root of " << num1 << " = " << result << endl;
            break;
        default:
            cout << "Invalid operation!" << endl;
            break;
    }
}

// Function to perform trigonometric operations
void performTrigonometricOperation(int choice) {
    double angle, result;
    angle = getAngle();

    switch (choice) {
        case 7:
            result = sin(angle);
            cout << "sin(" << angle << ") = " << result << endl;
            break;
        case 8:
            result = cos(angle);
            cout << "cos(" << angle << ") = " << result << endl;
            break;
        case 9:
            result = tan(angle);
            cout << "tan(" << angle << ") = " << result << endl;
            break;
        default:
            cout << "Invalid trigonometric operation!" << endl;
            break;
    }
}

// Main program
int main() {
    int choice;

    do {
        showMenu(); // Display the menu
        cout << "Enter your choice: ";
        choice = getNumber(); // Get the user's choice

        if (choice >= 1 && choice <= 6) {
            performBasicOperation(choice); // Perform arithmetic operations
        } else if (choice >= 7 && choice <= 9) {
            performTrigonometricOperation(choice); // Perform trigonometric operations
        } else if (choice == 0) {
            cout << "Exiting the program. Goodbye!" << endl;
        } else {
            cout << "Invalid choice. Please enter a valid option." << endl;
        }

        cout << endl; // New line for better readability
    } while (choice != 0);

    return 0;
}
