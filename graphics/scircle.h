

void plotcircle(int x, int y, int xc, int yc)
{
	putpixel(xc+x, yc-y, WHITE);
	putpixel(xc+y, yc-x, WHITE);
	putpixel(xc+x, yc+y, WHITE);
	putpixel(xc+y, yc+x, WHITE);

	putpixel(xc-x, yc-y, WHITE);
	putpixel(xc-y, yc-x, WHITE);
	putpixel(xc-x, yc+y, WHITE);
	putpixel(xc-y, yc+x, WHITE);
}
void draw_circle(int xc, int yc, int r)
{
	int x,y,d;
	   x=0; y=r; d=5/4-r;
	   plotcircle(x,y,xc,yc);
	   while(x<=y)
	   {
			if(d<=0)
			d+=(2*x+3);
			else
			{
				d+=(2*x-2*y+5);
				y--;
			}
			x++;
			plotcircle(x, y, xc, yc);
	   }
}
