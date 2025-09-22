
#include <iostream>
#include <conio.h>
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
        cout << "player 1, symbols _ ";
        do
        {
            cin >> sym1;
        } while (isvalidinput(sym1) == false);
        cout << "player 2 symbol _ ";
        do
        {
            cin >> sym2;
        } while (isvalidinput(sym2) == false);
        sym1 = tolowercase(sym1);
        M = whowin(sym1, sym2);
        cout << "************************" << endl;
        gamemsg(M);
        cout << endl << "************************" << endl;
        cout << endl << "do you want to ply again (y/n) ";
        cin >> choice;
        choice = tolowercase(choice);
        cout << endl;
    } while (choice = 'y');
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
    return(sym >= 'A' && sym <= 'Z');

}
bool isvalidinput(char sym)
{
    return(sym == 'r' || sym == 'R' || sym == 's' || sym == 'S' || sym == 'p' || sym == 'P');

}
int whowin(char sym1, char sym2)
{
    if (sym1 == sym2)
    {
        return 0;
    }

    if (sym1 == 'p' && sym2 == 'r')
    {
        return 1;
    }
    else if (sym1 == 'r' && sym2 == 's')
    {
        return 1;
    }
    else if (sym1 == 's' && sym2 == 'p')
    {
        return 1;
    }

    else
        return 2;
}
void gamemsg(int M)
{
    switch (M)
    {
    case 0:
        cout << "game drow";
        break;
    case 1:
        cout << "plyer 1 win";
        break;
    case 2:
        cout << "plyer 2 win";
        break;
    }
}
