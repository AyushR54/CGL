#include<iostream>
#include<graphics.h>
#include<math.h>

using namespace std;

void drawcircle(int xc, int yc, int x, int y) {
	putpixel(xc + x, yc - y, RED);
	putpixel(xc - x, yc - y, RED);
	putpixel(xc + x, yc + y, RED);
	putpixel(xc - x, yc + y, RED);
	putpixel(xc + y, yc - x, RED);
	putpixel(xc - y, yc - x, RED);
	putpixel(xc + y, yc + x, RED);
	putpixel(xc - y, yc + x, RED);
}

int round(float n) {
    if (n - (int)n < 0.5)
        return (int)n;
    return (int)(n + 1);
}

void line(int x0, int y0, int x1, int y1) {
    int dx = x1 - x0;
    int dy= y1 - y0;
       
    int step;

    if (abs(dx) > abs(dy))
        step = abs(dx);
    else
        step = abs(dy);

    float x_incr = (float)dx / step;
    float y_incr = (float)dy / step;
       
    float x = x0;
    float y = y0;
     
    for (int i = 0; i < step; i++) {
        putpixel(round(x), round(y), RED);
        x += x_incr;
        y += y_incr;
    }
}


void bresCircle(int xc, int yc, int r) {
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
	int xc = 150, yc = 150, r = 100;
	int d = (sqrt(3) / 2) * r;

	int gdriver = DETECT, gmode;
	initgraph(&gdriver, &gmode, NULL);
	
	bresCircle(xc, yc, r);
	line(xc, yc-r, xc+d, yc+(r/2));
	line(xc+d, yc+(r/2), xc-d, yc+(r/2));
	line(xc-d, yc+(r/2), xc, yc-r);
	bresCircle(xc, yc, (r / 2));
	delay(2500);
	closegraph();
	return 0;
}
