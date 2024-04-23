#include <iostream>
#include <string>

using namespace std;

bool isNumberString(const string& s) {
    // Check if the string contains only numeric characters
    for (char c : s) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

int main() {
    string ccNumber;

    cout << "This program uses the Luhn Algorithm to validate a credit card number." << endl;
    cout << "You can enter 'exit' at any time to quit." << endl;

    while (true) {

        cout << "Please enter a credit card number to validate: ";
        cin >> ccNumber;

        if (ccNumber == "exit") {
            break;
        }
        else if (!isNumberString(ccNumber) || ccNumber.length() < 12 || ccNumber.length() > 19) {
            // Check for non-numeric characters or invalid length
            cout << "Invalid input! Please enter a numeric string of length 12 to 19." << endl;
            continue;
        }

        int len = ccNumber.length();
        int doubleEvenSum = 0;

        // Step 1: Double every second digit from the right, starting from the second-to-last digit.
        // If the result is a two-digit number, add the digits together.
        for (int i = len - 2; i >= 0; i -= 2) {
            int dbl = ((ccNumber[i] - '0') * 2);
            if (dbl > 9) {
                dbl = (dbl / 10) + (dbl % 10);
            }
            doubleEvenSum += dbl;
        }

        // Step 2: Add every odd-placed digit from the right to the sum.
        for (int i = len - 1; i >= 0; i -= 2) {
            doubleEvenSum += (ccNumber[i] - '0');
        }

        // Step 3: Check if the total sum modulo 10 equals 0.
        // If it does, the credit card number is valid; otherwise, it's invalid.
        cout << (doubleEvenSum % 10 == 0 ? "Valid!" : "Invalid!") << endl;

    }

    return 0;
}
sss
