#include<stdio.h>
#include<dos.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>

int main()
{
    int c = -200, i = 0, x = 40, l = 15, h = 15, ht = 0;
    initwindow(1080, 640, "Window");
    cleardevice();

    line(0, 201, 600, 201); //ground

  cont:

    while (!kbhit()) {


	circle(x - 20, 115, 15);
	line(x - 20, 130, x - 20, 175);//body
	line(x - 20, 175, x - 20 - l, 200);//leg
	line(x - 20, 175, x - 20 + l, 200);//leg
	line(x - 20, 140, x-20+h, 150);// static hand
	line(x - 20, 140, x - 20 - h, 160);//hand

	//setcolor(0);

	delay(50);
	cleardevice();

	// COORDINATES OF THE MAN
	x++;

	// MOVING the LEG
	l--;
	if (l == -15)
	    l = 15;

	// MOVING the HAND
	if (ht == 1)
	    h++;
	else
	    h--;

	if (h == 15)
	    ht = 0;
	else if (h == -15)
	    ht = 1;

    }
}
