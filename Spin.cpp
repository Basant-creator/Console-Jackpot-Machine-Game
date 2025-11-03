#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstdlib>  // for random number generation
#include <ctime>    // for time()
using namespace std;

// Global variables
const int ROWS = 3;
const int COLS = 3;

// Symbol definitions
map<char, int> SYMBOLS_COUNT = {
    {'A', 2},
    {'B', 4},
    {'C', 6},
    {'D', 8}
};
// Symbol Multipliers
map<char, int> SYMBOLS_VALS = {
    {'A', 5},
    {'B', 4},
    {'C', 3},
    {'D', 2}
};

// Method to deposit money
double deposit() {
    while (true) {
        cout << "Transfer an amount: ";
        double depositAmount;
        cin >> depositAmount;

        if (cin.fail() || depositAmount <= 0) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid, Please Try again..." << endl;
        } else {
            return depositAmount;
        }
    }
}

// Method to select number of lines
int getNumberOfLines() {
    while (true) {
        cout << "Enter the number of lines to bet on (1-3): ";
        int lines;
        cin >> lines;

        if (cin.fail() || lines <= 0 || lines > 3) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid, Please Try again..." << endl;
        } else {
            return lines;
        }
    }
}

// Method to take bet from user
double getBet(double balance, int lines) {
    while (true) {
        cout << "Total bet amount: ";
        double bet;
        cin >> bet;

        if (cin.fail() || bet <= 0) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid, Please Try again..." << endl;
        } else {
            return bet;
        }
    }
}

// Spin function to generate reels
vector<vector<char>> spin() {
    vector<char> symbols;
    for (auto &pair : SYMBOLS_COUNT) {
        char symbol = pair.first;
        int count = pair.second;
        for (int i = 0; i < count; i++) {
            symbols.push_back(symbol);
        }
    }

    vector<vector<char>> reels(COLS, vector<char>());
    for (int i = 0; i < COLS; i++) {
        vector<char> reelSymbols = symbols;
        for (int j = 0; j < ROWS; j++) {
            int randomIndex = rand() % reelSymbols.size();
            char selectedSymbol = reelSymbols[randomIndex];
            reels[i].push_back(selectedSymbol);
            reelSymbols.erase(reelSymbols.begin() + randomIndex);
        }
    }
    return reels;
}

// Transpose function to convert reels to rows
vector<vector<char>> transpose(const vector<vector<char>>& reels) {
    vector<vector<char>> rows(ROWS, vector<char>());

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            rows[i].push_back(reels[j][i]);
        }
    }
    return rows;
}

// Print rows to console
void printRows(const vector<vector<char>>& rows) {
    for (const auto& row : rows) {
        for (size_t i = 0; i < row.size(); i++) {
            cout << row[i];
            if (i != row.size() - 1)
                cout << " | ";
        }
        cout << endl;
    }
}

// Get winnings
double getWinnings(const vector<vector<char>>& rows, double bet, int lines) {
    double winnings = 0;
    for (int row = 0; row < lines; row++) {
        const vector<char>& symbols = rows[row];
        bool allSame = true;

        for (char symbol : symbols) {
            if (symbol != symbols[0]) {
                allSame = false;
                break;
            }
        }
        if (allSame) {
            winnings += bet * SYMBOLS_VALS[symbols[0]];
        }
    }
    return winnings;
}

int main() {
    srand(time(0));
    double balance = deposit();
    bool playing = true;
    while (balance > 0 && playing) {
        int numberOfLines = getNumberOfLines();
        double betting = getBet(balance, numberOfLines);
        vector<vector<char>> reels = spin();
        vector<vector<char>> rows = transpose(reels);
        printRows(rows);
        double winnings = getWinnings(rows, betting, numberOfLines);
        balance -= betting * numberOfLines;   // total money spent
        balance += winnings;                  // add winnings back
        cout << "You won: " << winnings << endl;
        cout << "Your new balance: " << balance << endl;

        if(balance > 0){
            cout << "Do you want to continue playing? (y/n): ";
            char answer;
            cin >> answer;
            if(answer != 'y' && answer != 'Y'){
                playing = false;
            }
        }else{
            cout << "You don't have enough balance to continue playing." << endl;
            playing = false;
        } 
    }

    return 0;
}
