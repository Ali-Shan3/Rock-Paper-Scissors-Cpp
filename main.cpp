#include <iostream>
using namespace std;

int whowin(char sym1, char sym2);
void gamemsg(int M);
bool isvalidinput(char sym);
bool iscapital(char sym);
char tolowercase(char sym);

int main()
{
    int M;
    char sym1, sym2, choice;
    do
    {
        cout << "Player 1, symbol: ";
        do
        {
            cin >> sym1;
        } while (isvalidinput(sym1) == false);

        cout << "Player 2, symbol: ";
        do
        {
            cin >> sym2;
        } while (isvalidinput(sym2) == false);

        sym1 = tolowercase(sym1);
        sym2 = tolowercase(sym2);   // 🔥 Added: ensure both lowercase

        M = whowin(sym1, sym2);

        cout << "************************" << endl;
        gamemsg(M);
        cout << endl << "************************" << endl;

        cout << endl << "Do you want to play again (y/n): ";
        cin >> choice;
        choice = tolowercase(choice);
        cout << endl;
    } while (choice == 'y');   // 🔥 Fixed: use == not =

    return 0;
}

char tolowercase(char sym)
{
    if (iscapital(sym))
        sym = sym + 32;
    return sym;
}

bool iscapital(char sym)
{
    return (sym >= 'A' && sym <= 'Z');
}

bool isvalidinput(char sym)
{
    return (sym == 'r' || sym == 'R' ||
            sym == 's' || sym == 'S' ||
            sym == 'p' || sym == 'P');
}

int whowin(char sym1, char sym2)
{
    if (sym1 == sym2)
    {
        return 0; // draw
    }

    if ((sym1 == 'p' && sym2 == 'r') ||
        (sym1 == 'r' && sym2 == 's') ||
        (sym1 == 's' && sym2 == 'p'))
    {
        return 1; // player 1 wins
    }
    else
        return 2; // player 2 wins
}

void gamemsg(int M)
{
    switch (M)
    {
    case 0:
        cout << "Game Draw";
        break;
    case 1:
        cout << "Player 1 Wins";
        break;
    case 2:
        cout << "Player 2 Wins";
        break;
    }
}
