#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>
#include <dos.h>
#include <conio.h>

#define ORG -50
struct point{
int x, y;};

point face1[]={{ 250, 125 },
			    { 350, 125 },
			    { 350, 225 },
			    { 250, 225 },
			    { 250, 125 }};
point face2[]={{ 250+ORG, 125-ORG },
			    { 350+ORG, 125-ORG },
			    { 350+ORG, 225-ORG },
			    { 250+ORG, 225-ORG },
			    { 250+ORG, 125-ORG }};

double angle = 5 * M_PI / 180;
double midx1, midy1, midx2, midy2;

void rotate (void)
{
    int i;
    for (i=0; i<5; i++)
    {
	double xnew, ynew;

	xnew = midx1 + (face1[i].x - midx1) * cos (angle) -
	       (face1[i].y - midy1) * sin (angle);
	ynew = midy1 + (face1[i].x - midx1) * sin (angle) +
		(face1[i].y - midy1) * cos (angle);

	face1[i].x = xnew;
	face1[i].y = ynew;

	xnew = midx2 + (face2[i].x - midx2) * cos (angle) -
		(face2[i].y - midy2) * sin (angle);
	ynew = midy2 + (face2[i].x - midx2) * sin (angle) +
		(face2[i].y - midy2) * cos (angle);

	face2[i].x = xnew;
	face2[i].y = ynew;
    }

    cleardevice();

    for (i=0; i<4; i++)
    {

        line (face1[i].x, face1[i].y, face1[i+1].x, face1[i+1].y);

        line (face2[i].x, face2[i].y, face2[i+1].x, face2[i+1].y);

        line (face1[i].x, face1[i].y, face2[i].x, face2[i].y);
    }

    delay (125);
}

int main()
{
    int gd = DETECT, gm;

    midx1 = (face1[0].x+ face1[1].x) / 2.0;
    midy1 = (face1[1].y + face1[2].y) / 2.0;
    midx2 = (face2[0].x + face2[1].x) / 2.0;
    midy2 = (face2[1].y + face2[2].y) / 2.0;

    initgraph (&gd, &gm, "..\\bgi");

    while (!kbhit())
	rotate();

    closegraph();
}
