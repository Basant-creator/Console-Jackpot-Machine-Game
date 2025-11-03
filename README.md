🎰 Console Slot Machine (C++)
A simple console-based slot machine game written in C++. Deposit money, choose how many lines to bet on, spin the reels, and see if luck is on your side!

This project demonstrates:

1.Function organization, loops, and conditionals
2.Use of vector and map for storing symbols and values
3.Random number generation for simulating slot reels
4.Simple game logic and user input handling

📝 Overview

This is a console slot machine where the player can:

Deposit a starting balance

Choose 1–3 horizontal lines to bet on

Place bets per line

Spin the reels

Win based on matching symbols

⚙️ Installation

Open a terminal in the project directory.

Compile the code with g++:
g++ Spin.cpp -o Spin

Run the program:
./Spin      # On Windows: Spin.exe



🎮 How to Play

1.Deposit Money
2.Enter an amount greater than 0 to start playing.
3.Select Number of Lines
4.Enter 1, 2, or 3 to bet on the top, top+middle, or all three rows.
5.Place Your Bet
6.Enter a bet amount per line.
7.Total bet = bet × number of lines.
  Spin the Reels
  Symbols are randomly generated and displayed in rows.
  Check Winnings
  You win if all symbols in a row match.
  Only the rows you bet on are checked.
8.Repeat or Exit
9.Choose to play again if your balance is still positive.
  Game ends automatically if you run out of money.

💰 Symbols and Payouts
Symbol	Count	Value Multiplier
A	   2   	 5×
B	   4     4×
C	   6   	 3×
D	   8	   2×

Rare symbols are harder to get but pay more.

Common symbols are easier to hit but pay less.

📊 Example Spin
D | D | B
B | B | B
B | D | C
If you bet on 3 lines, only the second row matches → you win the payout for that row.

⚠️ Notes
The game only checks horizontal rows; diagonals don’t count.
To increase complexity, you could add wild symbols, diagonal payouts, or a high score tracker.
Perfect for demonstrating C++ fundamentals in a small, playable project.
