# ✊✋✌️ Rock–Paper–Scissors (C++)

A simple **Rock–Paper–Scissors** console game written in C++.  
Two players enter their choices (`r`, `p`, `s`), the program validates input, and declares the winner.

---

## 🎮 Features
- Two-player gameplay  
- Input validation (accepts uppercase and lowercase)  
- Automatic conversion of uppercase to lowercase  
- Displays results with clear messages  
- Option to replay  

---

## 🛠️ Technologies Used
- **C++**  
- **Console application**  

---

##Gameplay Example (Console Screen)

player 1, symbols _ r
player 2 symbol _ s
************************
plyer 1 win
************************

    do you want to ply again (y/n) y

player 1, symbols _ p
player 2 symbol _ p
************************
game drow
************************

    do you want to ply again (y/n) n
 
## Functions Used

- bool isvalidinput(char sym) → validates if input is r, p, or s. 
-  bool iscapital(char sym) → checks if the input is uppercase.
- char tolowercase(char sym) → converts uppercase to lowercase.
- int whowin(char sym1, char sym2) → game logic; returns 0 for draw, 1 if player 1 wins, 2 if player 2 wins.
- void gamemsg(int M) → displays result messages based on winner/draw.

---

## Future Improvements

- Add scoreboard tracking (track wins/losses per player).
- Add AI opponent mode (player vs computer).
- Add menu interface instead of looping input.
- Add graphical version (SFML/Qt) for GUI experience.
- Improve input handling (avoid infinite loop if invalid input given multiple times).
