#include <iostream>
#include <graphics.h>
#include <math.h>

using namespace std;

void matMultiplication(float m1[3][3], float m2[3][3]) {
	float res[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			res[i][j] = 0;
			for (int k = 0; k < 3; k++) {
				res[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}
	line(res[0][0], res[0][1], res[1][0], res[1][1]);
	line(res[1][0], res[1][1], res[2][0], res[2][1]);
	line(res[2][0], res[2][1], res[0][0], res[0][1]);
	delay(9000);	
}


void trans(float coordMat[3][3]) {
	float tx, ty;
	cout << "Enter tx = ";
	cin >> tx;
	cout << "Enter ty = ";
	cin >> ty;
	setcolor(RED);
	float transMat[3][3] = {{1, 0, 0}, {0, 1, 0}, {tx, ty, 1}};
	matMultiplication(coordMat, transMat);
}

void scale(float coordMat[3][3]) {
	float sx, sy;
	cout << "Enter sx = ";
	cin >> sx;
	cout << "Enter sy = ";
	cin >> sy;
	setcolor(GREEN);
	float scaleMat[3][3] = {{sx, 0, 0}, {0, sy, 0}, {0, 0, 1}};
	matMultiplication(coordMat, scaleMat);
}

void rotate(float coordMat[3][3]) {
	int r;
	cout << "Enter angle = ";
	cin >> r;
	float rx = sin(r);
	float ry = cos(r);
	setcolor(YELLOW);
	float scaleMat[3][3] = {{rx, ry, 0}, {ry, rx, 0}, {0, 0, 1}};
	matMultiplication(coordMat, scaleMat);
}


int main() {
	int gdriver = DETECT, gmode;
	initgraph(&gdriver, &gmode, NULL);

	float x1, y1, x2, y2, x3, y3;
	float x1_, y1_, x2_, y2_, x3_, y3_;

	cout << "Enter co-ordinates of triangle\n";
	cout << "Enter (x1, y1) = ";
	cin >> x1 >> y1;
	cout << "Enter (x2, y2) = ";
	cin >> x2 >> y2;
	cout << "Enter (x3, y3) = ";
	cin >> x3 >> y3;

	line(x1, y1, x2, y2);
	line(x2, y2, x3, y3);
	line(x3, y3, x1, y1);

	float coordMat[3][3] = {{x1, y1, 1}, {x2, y2, 1}, {x3, y3, 1}};
	rotate(coordMat);
	closegraph();

	return 0;
}
