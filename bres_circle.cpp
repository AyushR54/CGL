#include <iostream>
#include <graphics.h>

using namespace std;

void drawcircle(int xc, int yc, int x, int y) {
	putpixel(xc + x, yc - y, RED);
	putpixel(xc - x, yc - y, BLUE);
	putpixel(xc + x, yc + y, GREEN);
	putpixel(xc - x, yc + y, YELLOW);
	putpixel(xc + y, yc - x, RED);
	putpixel(xc - y, yc - x, BLUE);
	putpixel(xc + y, yc + x, GREEN);
	putpixel(xc - y, yc + x, YELLOW);
	delay(50);
}


void bresenham_circle(int xc, int yc, int r) {
	int x = 0, y = r;
	int d = 3 - (2 * r);
	
	while (x < y) {
		drawcircle(xc, yc, x, y);
		x++;
		if (d < 0) {
			d = d + (4 * x) + 6;	
		} else {
			y--;
			d = d + 4 * (x - y) + 10;
		}
	}
}

int main() {
	int gdriver = DETECT, gmode;
	initgraph(&gdriver, &gmode, NULL);
	bresenham_circle(250, 250, 200);
	delay(2000);
	closegraph();
	return 0;
}
