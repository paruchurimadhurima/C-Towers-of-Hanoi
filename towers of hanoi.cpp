#include <iostream>
#include <stdio.h>
#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <conio.h>
#include <string.h>

using namespace std;


HANDLE console =GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;


inline void d()
{
    unsigned long ms=(10);
    Sleep( ms );
}
void title();
void game_start();
void clear_console();
void g(int x, int y);
void vertical(int x,int y);
void horizontal(int x,int y);
void dash_a_box1();
void dash_a_box2();
void dash_a_box3();
void dash_b_box1();
void dash_b_box2();
void dash_b_box3();
void dash_c_box1();
void dash_c_box2();
void dash_c_box3();
void baseline();
void display_board();
int input();
int check_process(char from,char inser);
int check_win();
int ar1[3]= {1,2,3},ar2[3]= {0},ar3[3]= {0};
int top1=3,top2=0,top3=0,sol=0,mov=0;
int main()
{
    HWND console = GetConsoleWindow();
    system("color 0b");
    MoveWindow(console, 400,0, 800,740, TRUE);
    title();
    game_start();
    int win=0;
    display_board();
    while(win==0)
    {
        win=input();
        while(sol==1)
        {
            g(42,29);
            printf("Invalid Move\n");
            win=input();
        }
        display_board();
    }
    g(37,31);
    if(win==1)
    {
        printf("****Congratulations you won the game in %d moves****",mov);
        g(0,40);
    }

    return 0;
}
void title()
{
    int i;
    for(i=32; i<90; i++)
    {
        g(i,3);
        printf("*");
        g(i,8);
        printf("*");
    }
    for(i=3; i<9; i++)
    {
        g(32,i);
        printf("*");
        g(89,i);
        printf("*");
    }
//t
    g(35,4);
    printf("__");
    g(36,5);
    printf("|");
    g(36,6);
    printf("|");
    g(36,4);
    printf("__");
    //o
    g(39,5);
    printf("|");
    g(39,6);
    printf("|");
    g(40,4);
    printf("__");
    g(40,6);
    printf("__");
    g(42,5);
    printf("|");
    g(42,6);
    printf("|");
    //w
    g(43,5);
    printf("|");
    g(43,6);
    printf("|");
    g(44,6);
    printf("/");
    g(45,6);
    printf("\\");
    g(46,5);
    printf("|");
    g(46,6);
    printf("|");
    //e
    g(47,5);
    printf("|");
    g(47,6);
    printf("|");
    g(48,4);
    printf("__");
    g(48,5);
    printf("__");
    g(48,6);
    printf("__");
    //r
    g(51,5);
    printf("|");
    g(51,6);
    printf("|");
    g(52,4);
    printf("_");
    g(52,5);
    printf("_");
    g(53,5);
    printf("|");
    g(52,6);
    printf("\\");
    //s
    g(55,4);
    printf("__");
    g(54,5);
    printf("|");
    g(55,5);
    printf("_");
    g(56,6);
    printf("|");
    g(54,6);
    printf("__");
    //o
    g(59,5);
    printf("|");
    g(59,6);
    printf("|");
    g(60,4);
    printf("__");
    g(60,6);
    printf("__");
    g(62,5);
    printf("|");
    g(62,6);
    printf("|");
    //f
    g(63,5);
    printf("|");
    g(63,6);
    printf("|");
    g(64,4);
    printf("__");
    g(64,5);
    printf("__");
    //h
    g(68,5);
    printf("|");
    g(68,6);
    printf("|");
    g(69,5);
    printf("__");
    g(71,5);
    printf("|");
    g(71,6);
    printf("|");
    //a
    g(72,6);
    printf("/");
    g(73,5);
    printf("/");
    g(75,6);
    printf("\\");
    g(74,5);
    printf("\\");
    //n
    g(76,5);
    printf("|");
    g(76,6);
    printf("|");
    g(77,5);
    printf("\\");
    g(78,6);
    printf("\\");
    g(79,5);
    printf("|");
    g(79,6);
    printf("|");
    //o
    g(80,5);
    printf("|");
    g(80,6);
    printf("|");
    g(81,4);
    printf("__");
    g(81,6);
    printf("__");
    g(83,5);
    printf("|");
    g(83,6);
    printf("|");
    //i
    g(84,4);
    printf("__");
    g(85,5);
    printf("|");
    g(85,6);
    printf("|");
    g(85,4);
    printf("__");
    g(84,6);
    printf("_");
    g(86,6);
    printf("_");
}
//helper functions
int check_win()
{
    int i,flag1=0,flag2=0,flag3=0;
    for(i=0; i<3; i++)
    {
        if(ar1[i]!=0)
            flag1=1;
        if(ar2[i]!=0)
            flag2=1;
        if(ar3[i]==0)
            flag3=1;
    }
    if(flag1==0&&flag2==0&&flag3==0)
        return 1;
    else
        return 0;
}
int input()
{
    g(42,25);
    printf("Enter a place name to remove from : ");
    char from;
    scanf(" %c",&from);
    g(42,27);
    printf("Enter a place name to insert into : ");
    char inser;
    scanf(" %c",&inser);
    mov++;
    int res=check_process(from,inser);
    if(res==0)
        sol=1;
    else
        sol=0;

    if(res==1)
    {
        return check_win();
    }
    else return 0;
}
int check_process(char from,char inser)
{
    int a1,b1;
    if((from=='a'||from=='A'))
    {
        a1=top1;
    }
    else if((from=='b'||from=='B'))
    {
        a1=top2;
    }
    else if((from=='c'||from=='C'))
    {
        a1=top3;
    }
    if((inser=='a'||inser=='A'))
    {
        b1=top1;
    }
    else if((inser=='b'||inser=='B'))
    {
        b1=top2;
    }
    else if((inser=='c'||inser=='C'))
    {
        b1=top3;
    }
    if(a1==0&&b1==0)
        return 0;
    if((from=='a'||from=='A')&&(inser=='b'||inser=='B'))
    {
        if(top1!=0&&top2==0||ar1[top1-1]>ar2[top2-1])
        {
            ar2[top2]=ar1[top1-1];
            ar1[top1-1]=0;
            top1--;
            top2++;
            return 1;
        }
        else
            return 0;
    }
    else if((from=='a'||from=='A')&&(inser=='c'||inser=='C'))
    {
        if(top1!=0&&ar1[top1-1]>ar3[top3-1]||top3==0)
        {
            ar3[top3]=ar1[top1-1];
            ar1[top1-1]=0;
            top1--;
            top3++;
            return 1;
        }
        else
            return 0;
    }
    else if((from=='b'||from=='B')&&(inser=='a'||inser=='A'))
    {
        if(top2!=0&&ar2[top2-1]>ar1[top1-1]||top1==0)
        {
            ar1[top1]=ar2[top2-1];
            ar2[top2-1]=0;
            top2--;
            top1++;
            return 1;
        }
        else
            return 0;
    }
    else if((from=='b'||from=='B')&&(inser=='c'||inser=='C'))
    {
        if(top2!=0&&ar2[top2-1]>ar3[top3-1]||top3==0)
        {
            ar3[top3]=ar2[top2-1];
            ar2[top2-1]=0;
            top2--;
            top3++;
            return 1;
        }
        else
            return 0;
    }
    else if((from=='c'||from=='C')&&(inser=='a'||inser=='A'))
    {
        if(top3!=0&&ar3[top3-1]>ar1[top1-1]||top1==0)
        {
            ar1[top1]=ar3[top3-1];
            ar3[top3-1]=0;
            top3--;
            top1++;
            return 1;
        }
        else
            return 0;
    }
    else if((from=='c'||from=='C')&&(inser=='b'||inser=='B'))
    {
        if(top3!=0&&ar3[top3-1]>ar2[top2-1]||top2==0)
        {
            ar2[top2]=ar3[top3-1];
            ar3[top3-1]=0;
            top3--;
            top2++;
            return 1;
        }
        else
            return 0;
    }
    else
        return 0;
}
void display_board()
{
    clear_console();
    title();
    int i;
    for(i=0; i<3; i++)
    {
        if(ar1[i]!=0)
        {
            if(ar1[i]==1)
            {
                dash_a_box1();
            }
            else if(ar1[i]==2)
            {
                dash_a_box2();
            }
            else if(ar1[i]==3)
            {
                dash_a_box3();
            }
        }
    }
    for(i=0; i<3; i++)
    {
        if(ar2[i]!=0)
        {
            if((ar2[i])==1)
            {
                dash_b_box1();
            }
            else if(ar2[i]==2)
            {
                dash_b_box2();
            }
            else if(ar2[i]==3)
            {
                dash_b_box3();
            }
        }
    }
    for(i=0; i<3; i++)
    {
        if(ar3[i]!=0)
        {
            if(ar3[i]==1)
            {
                dash_c_box1();
            }
            else if(ar3[i]==2)
            {
                dash_c_box2();
            }
            else if(ar3[i]==3)
            {
                dash_c_box3();
            }
        }
    }

    baseline();
}
void clear_console()
{
    system("cls");
}
void g(int x, int y)
{
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console,CursorPosition);
}

void vertical(int x,int y)
{
    HWND console = GetConsoleWindow();
    system("color 0b");
    MoveWindow(console, 400,0, 800,740, TRUE);
    g(x,y);
    printf("|");
}

void horizontal(int x,int y)
{
    HWND console = GetConsoleWindow();
    system("color 0b");
    MoveWindow(console, 400,0, 800,740, TRUE);
    g(x,y);
    printf("-");
}

void dash_a_box1()
{
    int i;
    for(i=20; i<40; i++)
    {
        horizontal(i,17);
        horizontal(i,20);
    }
    vertical(20,18);
    vertical(20,19);
    vertical(39,19);
    vertical(39,18);
    g(30,19);
    printf("1");
}

void dash_a_box2()
{
    int i,j=0;
    if(top1==1)
        j=3;
    else if(top1==2&&ar1[0]==2)
        j=3;
    for(i=22; i<38; i++)
    {
        horizontal(i,14+j);
        horizontal(i,17+j);
    }
    vertical(22,16+j);
    vertical(22,15+j);
    vertical(37,15+j);
    vertical(37,16+j);

    g(30,16+j);
    printf("2");
}

void dash_a_box3()
{
    int i,j=0;
    if(top1==1)
        j=6;
    else if(top1==2)
        j=3;
    for(i=24; i<36; i++)
    {
        horizontal(i,11+j);
        horizontal(i,14+j);
    }
    vertical(24,13+j);
    vertical(24,12+j);
    vertical(35,12+j);
    vertical(35,13+j);
    g(30,13+j);
    printf("3");
}

void dash_b_box1()
{
    int i;
    for(i=50; i<70; i++)
    {
        horizontal(i,17);
        horizontal(i,20);
    }

    vertical(69,19);
    vertical(69,18);
    vertical(50,19);
    vertical(50,18);
    g(60,19);
    printf("1");
}

void dash_b_box2()
{
    int i,j=0;
    if(top2==1)
        j=3;
    else if(top2==2&&ar2[0]==2)
        j=3;
    for(i=52; i<68; i++)
    {
        horizontal(i,14+j);
        horizontal(i,17+j);
    }
    vertical(52,15+j);
    vertical(52,16+j);
    vertical(67,15+j);
    vertical(67,16+j);
    g(60,16+j);
    printf("2");
}

void dash_b_box3()
{
    int i,j=0;
    if(top2==1)
        j=6;
    else if(top2==2)
        j=3;
    for(i=54; i<66; i++)
    {
        horizontal(i,11+j);
        horizontal(i,14+j);
    }
    vertical(54,12+j);
    vertical(54,13+j);
    vertical(65,12+j);
    vertical(65,13+j);
    g(60,13+j);
    printf("3");
}

void dash_c_box1()
{
    int i;
    for(i=80; i<100; i++)
    {
        horizontal(i,17);
        horizontal(i,20);
    }
    vertical(80,19);
    vertical(80,18);
    vertical(99,19);
    vertical(99,18);
    g(90,19);
    printf("1");
}

void dash_c_box2()
{
    int i,j=0;
    if(top3==1)
        j=3;
    else if(top3==2&&ar3[0]==2)
        j=3;
    for(i=82; i<98; i++)
    {
        horizontal(i,14+j);
        horizontal(i,17+j);
    }
    vertical(82,15+j);
    vertical(82,16+j);
    vertical(97,15+j);
    vertical(97,16+j);
    g(90,16+j);
    printf("2");
}

void dash_c_box3()
{
    int i,j=0;
    if(top3==1)
        j=6;
    else if(top3==2)
        j=3;
    for(i=84; i<96; i++)
    {
        horizontal(i,11+j);
        horizontal(i,14+j);
    }
    vertical(84,12+j);
    vertical(84,13+j);
    vertical(95,12+j);
    vertical(95,13+j);
    g(90,13+j);
    printf("3");
}

void baseline()
{
    int i;
    for(i=15; i<105; i++)
    {
        horizontal(i,20);
    }
    g(27,22);
    printf("A Place");
    g(57,22);
    printf("B Place");
    g(87,22);
    printf("C Place");
}

void game_start()
{
//first dash
    dash_a_box3();
    dash_a_box2();
    dash_a_box1();
//second dash
    dash_b_box1();
    dash_b_box2();
    dash_b_box3();
//third dash
    dash_c_box1();
    dash_c_box2();
    dash_c_box3();
    baseline();
    g(45,25);
    printf("Input any key to play the game : \n") ;
    char cha;
    g(78,25);
    scanf(" %c",&cha);

}


