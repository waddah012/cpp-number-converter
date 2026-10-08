/*
Programming Assignment: 2 Converter assignment
Language: C++

Description: This prpgra will bring a menu
Menu:
1. 16 bit binary: Print out 4 digit hexadecimal
2. 32 bit Hex: Print out binary 32 bit and decimal
3. Integer 32 bit: Print out binary 32 bit and 8 digit hexadecimal
4. Exit

Compiling: g++ -o Programming_Assignment2 Programming_Assignment2.cpp

how to run: ./Programming_Assignment2

sample input and output:
16th bit binary input: 0000000000001010
Hexadecimal: 0x000A
Integer: 10

The program: this program provides a simple conversion tool which does the conversion between binary
hexadecimal and decimal integer values, it allows a uses to choose between 3 options and experiment with
different values and see the results. This system will use c++

The first feature is the 16th bit binary which you input excactly 16 binary characers of 0 or 1
and it will output a 4 didit hexadecimal and the integer value.

the second feature would be the 32 bit hexadecimal and this will need an input of 8 hexadecimal and it will output a 32 bit binary string and integer
 the third feature will have  you input a non negative integer from 0 to 4294967295 and it will output a binary string without any leading zeros and an 8 digit hexadecimal value.

printmenu(): will display the programs main menu
theChoice(): this will read the users menu sellection
pbinaty16(): this will first validate and convert it to a 16 bit binary strring
hexvvalue(): this will convert a single hex digit to its value
pHex32(): this will validate and convert a hex string to its 32 bit value
peUIntDec(): this will validate and convert a decimal string to its 32 bit value
toBinary(): this will convert an integer to a binary string of a given width
toHex(): this will convert an integer to a hexadecimal string of a given width
main(): This will run a loop to display the menu and what the user chooses until they choose to exit
 */

 #include <iostream>
 #include <string>
 using namespace std;

 //this shows the meny each time so the user can choose one of the options
 void printMenu() {
     cout << "Menu:\n";
     cout << "1. 16 bit binary value\n";
     cout << "2. 32 bit Hex value:\n";
     cout << "3. Integer 32 bit value:\n";
     cout << "4. Exit\n";
     cout << "Choose Between Option 1-4\n: ";
 }

char theChoice() { // this will read the users menu sellection and ignore any leading spaces or tabs, cleans up the input
    string line; // This will hold the user input
    getline(cin, line); //This reads the entire line

    for (size_t i = 0; i < line.length(); i++) {
        if (line[i] != ' ' && line[i] != '\t') {
            return line[i]; // this will return the first no space character
        }
    }

    return '\0'; // this will return null if the user just hits enter or inputs spaces/tabs
}

bool pbinary16(string& s, unsigned int& out) { //this function converts to binary
    if (s.size() != 16) { // 16 charcters exactly
        return false;
    }

    unsigned int value = 0; // this is the runnning total

    for (size_t i = 0; i < 16; i++) {
        char c = s[i];  // this gets each character

        if (c != '0' && c != '1') {
            return false; // this shows invalid charcter
        }
        value = value * 2 + (c - '0'); //shifts left and multpiles by 2
    }
    out = value;
    return true;
}


int hexValue(char c) { // this function converts a single hex digit to its value
    if (c >= '0' && c <= '9') {  // 0-9
        return c - '0';
    }
    if (c >= 'a' && c <= 'f') { // a-f 10-15
        return 10 + (c - 'a');
    }
    if (c >= 'A' && c <= 'F') { // A-F 10-15
        return 10 + (c - 'A');
    }
    return -1;
}


bool pHex32(string& sIn, unsigned int& out) { // this will validate and convert a hex string to its 32 bit value
    string s = sIn;
    if (s.size() >= 2 && s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
        s = s.substr(2); //  this removes the 0x or 0X prefix if present
    }

    if (s.size() == 0 || s.size() > 8) { // 1 to 8 hex digits
        return false;
    }

    unsigned int value = 0; //converts the hex string to its 32 bit value

    for (size_t i = 0; i < s.size(); ++i) {
        int d = hexValue(s[i]); // this gets the value 0 to 15 of the hex digit
        if (d < 0) {
            return false;
        }
        value = value * 16 + d; // shifts left and multiplies by 16
    }
    out = value;
    return true;
}


bool peUIntDec(string& s, unsigned int& out) { // This will validate and convert a decimal string to its 32 bit value
    if (s.size() == 0) {
        return false;
    }
    unsigned long long v = 0; // this is the running total using 64 bit to detect overflow

    for (size_t i = 0; i < s.size(); ++i) {
        char ch = s[i];
        if (ch < '0' || ch > '9') {
            return false;
        }
       int digit = ch - '0';                        // this converts char to a number

     if (v > 429496729 || (v == 429496729 && digit > 5)) {
            return false;                               // This is the overflow beyond 32-bit unsigned
        }

        v = v * 10 + digit;                     // This will shift left by a multiple of 10 and then adds a digit
    }
    out = v;
    return true;
}

string toBinary(unsigned int value, int width) { //this will convert an integer to a binary string of a given width
    if (width < 1) { //this will ensure the minimum width is 1
        width = 1;
    }

    string out = "";

    for (int i = 0; i < width; i++) {
        int bit = value % 2; // this gets the least significant bit
        out = char('0' + bit) + out;
        value = value / 2; // this shifts right by 1
    }

    return out;
}


string toHex(unsigned int value, int width) { // this will convert an integer to a hexadecimal string of a given width
    if (width < 1) { // this will ensure the minimum width is 1
        width = 1;
    }

    const string HEX = "0123456789ABCDEF";
    string out = "";

    for (int i = 0; i < width; i++) {
        int digit = value % 16;     // this gets the least significant hex digit
        out = HEX[digit] + out;
        value = value / 16;        //this will move it to the enxt
    }

    return out;
}


int main() { // this is the main function that will run a loop to display the menu and what the user chooses until they choose to exit
    while (true) {
        printMenu(); // this will display the menu
        char c = theChoice();

        if (c == '4') { //quit option
            cout << "\n Goodbye!Thanks for using the converter.\n";
            break;
        }
        else if (c == '1') { // 16-bit Binary input

            cout << "\nEnter a 16-bit binary value exactly 16 characters of 0 or 1): ";
            string bin; getline(cin, bin);

            unsigned int value = 0;
            if (!pbinary16(bin, value)) {
                cout << "The binary is invalid. it Must be a length 16 with only 0 or 1.\n\n";
                continue;  // this will go back to the menu
            }

            cout << "Hexadecimal: 0x" << toHex(value, 4) << "\n";
            cout << "Integer):      " << value << "\n\n";
        }
        else if (c == '2') { // this converts the hex from binary to integer

            cout << "\nPlease Enter a 32-bit hexadecimal value up to 8 hex digits: ";
            string hex; getline(cin, hex);

            unsigned int value = 0;
            if (!pHex32(hex, value)) {
                cout << "the hex is invalid. Use up to 8 digits optional 0x.\n\n";
                continue;
            }

            cout << "Binary (32 bits): " << toBinary(value, 32) << "\n";
            cout << "Integer:          " << value << "\n\n";
        }
        else if (c == '3') { // this converts the integer input to binary

            cout << "\n Please enter a non-negative integer : ";
            string dec; getline(cin, dec);

            unsigned int value = 0;
            if (!peUIntDec(dec, value)) {
                cout << "The integer is invalid. Digits only .\n\n";
                continue;
            }


            string b32 = toBinary(value, 32);  // this shows the binary without the leading zeros
            size_t first1 = b32.find('1'); // This is the full 32 bit string
            string niceBin = (first1 == string::npos) ? "0" : b32.substr(first1);

            cout << "Binary:  " << niceBin << "\n";
            cout << "Hexadecimal: 0x" << toHex(value, 8) << "\n\n";
        }
        else {
            cout << "Please choose 1, 2, 3, or 4.\n\n";
        }
    }
    return 0;
}
