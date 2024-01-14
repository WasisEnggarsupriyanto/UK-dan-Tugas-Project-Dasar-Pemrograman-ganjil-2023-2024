#include <iostream>
#include <cstdlib>

using namespace std;

void displayBoard_1(char b[3][3])
{
    cout << "\n  " << b[0][0] << " | " << b[0][1] << " | " << b[0][2] << "\n";
    cout << " ---+---+---\n";
    cout << "  " << b[1][0] << " | " << b[1][1] << " | " << b[1][2] << "\n";
    cout << " ---+---+---\n";
    cout << "  " << b[2][0] << " | " << b[2][1] << " | " << b[2][2] << "\n";
}
void displayBoard_2(char b[3][3])
{
    cout << "\n  " << b[0][0] << " | " << b[0][1] << " | " << b[0][2] << "\n";
    cout << " ---+---+---\n";
    cout << "  " << b[1][0] << " | " << b[1][1] << " | " << b[1][2] << "\n";
    cout << " ---+---+---\n";
    cout << "  " << b[2][0] << " | " << b[2][1] << " | " << b[2][2] << "\n";
}
    
void playerMove(char b[3][3], int p, int kot, int bar, int kol, int &win)
{
    do
    {
        cout << "\n Masukkan Kotak Yang Anda Pilih : ";
        cin >> kot;

        if (kot >= 1 && kot <= 3)
        {
            bar = 0;
            kol = kot - 1;
        }
        else if (kot >= 4 && kot <= 6)
        {
            bar = 1;
            kol = kot - 4;
        }
        else
        {
            bar = 2;
            kol = kot - 7;
        }

    } while (kot < 1 || kot > 9 || b[bar][kol] == 'X' || b[bar][kol] == 'O');

    if (p == 1)
    {
        b[bar][kol] = 'X';
    }
    else
    {
        b[bar][kol] = 'O';
    }

    for (bar = 0; bar < 3; bar++)
    {
        if (b[bar][0] == b[bar][1] && b[bar][1] == b[bar][2])
        {
            win = p;
            return; 
        }
    }

    for (kol = 0; kol < 3; kol++)
    {
        if (b[0][kol] == b[1][kol] && b[1][kol] == b[2][kol])
        {
            win = p;
            return; 
        }
    }

    if (b[0][0] == b[1][1] && b[1][1] == b[2][2])
    {
        win = p;
        return; 
    }
    else if (b[0][2] == b[1][1] && b[1][1] == b[2][0])
    {
        win = p;
        return; 
    }
}

int main()
{
    int gil, p, kot, bar, kol, win;
    char ulang = '1';

    while (ulang == '1')
    {
        win = 0;
        char b[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
        
        for (gil = 0; gil < 9 && win == 0; gil++)
        {   
            system("cls");
            cout << " >>> Ronde <<<"<<endl;
            cout << " >>>   " << gil + 1 << "   <<<\n";
            
            displayBoard_1(b);
            
            p = gil % 2 + 1;
            cout << "\n*Pemain " << p;
            
            playerMove(b, p, kot, bar, kol, win);
            
        }
            system("cls");
            cout << " ==Selesai==\n";
            
            displayBoard_2(b);
            
            if (win != 0)
        {
            cout << "\n =Pemain " << win << "!=\n >>>> YOU WIN <<<<\n";
        }
        else
        {
            cout << "\n >>>Seri!<<<\n";
        }

        cout << "\n Ketik 1 Untuk Duel Ulang : ";
        cin >> ulang;
    }
    return 0;
}
