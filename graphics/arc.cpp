#include <graphics.h>
#include <conio.h>

int main()
{
   initwindow(1080, 640, "Window");

   arc(100, 100, 0, 180, 100);// center.x, center.y, initial angle, end angle, radius // drawn from right to left

   getch();
   closegraph();
   return 0;
}
