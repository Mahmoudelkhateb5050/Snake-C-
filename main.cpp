#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;


bool gameover;
int width = 40;
int heights = 20;
int x,y,fruitx,fruity,score,sspeed,speed;
int tailx[100],taily[100];
int ntail;
bool again;
int play;

enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirecton dir;



void setup ()
{
    gameover = false;
    dir = STOP;
    x = width / 2;
    y = heights / 2;
    fruitx = rand() % width;
    fruity = rand() % heights;
    score = 0;
    /*cout << "          created by         " <<endl;
    cout << "  mahmoud abdelreheem elkhateb " <<endl;
    cout << "       CIC ID : 20197198" <<endl;
    cout << "    mail: moda5050@yahoo.com"<<endl;*/
    cout << "enter speed from 0 to 10 " ;
    cin >> sspeed;

    speed = 100 -(10*sspeed);
}

void draw ()
{
    system("cls"); //system ("clear");
    for (int i = 0; i < width+2; i++)
        cout << "#";
        cout << endl;
        for (int i = 0; i < heights; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (j==0)
                    cout << "#";
                    if(i == y && j == x)
                        cout << "O";
                    else if (i == fruity && j == fruitx)
                        cout << "@";
                    else
                    {
                        bool print = false;
                     for (int k = 0; k< ntail; k++)
                     {
                         if (tailx[k] == j && taily[k] == i)
                         {
                             cout << "o";
                             print = true;
                         }
                     }
                     if (!print)
                    cout << " ";
                }
                if (j == width-1)
                    cout << "#";
            }

            cout << endl;
        }
         for (int i = 0; i < width+2; i++)
        cout << "#";
        cout << endl;
        cout << "score : "<<score<<endl;
            cout << "press x to quit" << endl;


}
void input ()
{
    if (_kbhit())
    {
        switch (_getch())
        {
            case 'a':
            dir = LEFT;
            break;
            case 'd':
            dir = RIGHT;
            break;
            case 'w':
            dir = UP;
            break;
            case 's':
            dir = DOWN;
            break;
            case 'x':
            gameover = true;
            break;
        }
    }

}
void logic()
{
    int prevx = tailx[0];
    int prevy = taily[0];
    int prev2x, prev2y;
    tailx[0] = x;
    taily[0] = y;

    for (int i = 1; i <ntail; i++)
    {
        prev2x = tailx[i];
        prev2y = taily[i];
        tailx[i] = prevx;
        taily[i] = prevy;
        prevx = prev2x;
        prevy = prev2y;
    }


    switch (dir)
    {
        case STOP:
            break;
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
        default:
            break;


    }
    /*if (x >width || x < 0 || y > heights || y < 0)
        gameover = true;*/
    if (x >= width) x = 0; else if (x < 0) x = width - 1;
        if (y >= heights) y = 0; else if (y < 0) y = heights - 1;
        for (int i = 0; i<ntail; i++)
            if (tailx[i] == x && taily[i] == y)
            gameover = true;
    if (x == fruitx && y == fruity)
    {
        score += 10;
        fruitx = rand() % width;
        fruity = rand() % heights;
        ntail++;
    }


}

int main()
{
    setup();
    while (!gameover)
    {
        draw();
        input();
        logic();
        Sleep(speed); // sleep ()
    }


    if (gameover = true)
        cout << "Game over" << endl << "good luck in next time" << endl;
       /* cout << " press 1 to play again ";
        cin >> play;
        if (play = 1)
            gameover = false;*/

    return 0;
}
