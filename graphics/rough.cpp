#include<iostream>
#include"AthertonNew.h"
using namespace std;
//struct Point {int x, y;};

int main()
{
    initwindow(1080, 640);

    Point sub[5]={{120,220}, {170,320}, {250,220}, {250,350}, {120, 350} };
    Point win[5]={{100, 300}, {100,200}, {200,100}, {300,200},{300,300} };
    //Point win[4]={ {10,10}, {10,200}, {200, 200}, {200,10}};

    int i,j;
    setcolor(YELLOW);
    for(i=0;i<5;++i)
    {
        j=(i+1)%5;
        line(sub[i].x, sub[i].y, sub[j].x, sub[j].y);
    }
    for(i=0;i<5;++i)
    {
        j=(i+1)%5;
        line(win[i].x, win[i].y, win[j].x, win[j].y);
    }
    setcolor(0);
    Weiler(sub, win, 5, 5);
    setcolor(15);
    for(i=0;i<5;++i)
    {
        j=(i+1)%5;
        line(win[i].x, win[i].y, win[j].x, win[j].y);
    }
    getch();
    closegraph();
}
