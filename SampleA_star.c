#include<GL/glut.h>
#include<stdio.h>
#include<limits.h>
#include<math.h>
#include"prq.h"
#define INF INT_MAX
#define WID 60
#define HIG 30//3wall 2open 1close 0still
int width = WID * 10;
int hight = HIG * 10;
int start = 0;
int goal = 0;
int graph[HIG][WID] = { 0 };
int body[WID*HIG] = { 0 };
int index[WID*HIG] = { 0 };
int dist[WID * HIG] = {-1};
int direction[4][2] = {
	{1,0},//x,y
	{0,1},
	{-1,0},
	{0,-1}
};
d2_prqueue property;
void print() {
	for (int i = 0; i < HIG; i++) {
		for (int j = 0; j < WID; j++) {
			printf("%d", graph[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void from_index_to_coordinate(int i, int* x, int* y) {
	*x = i % WID;
	*y = (i - *x) / WID;
}
void from_coordinate_to_index(int x, int y, int* i) {
	*i = WID * y + x;
}
int get_h_dist(int i,int g) {
	int ix, iy, gx, gy;
	from_index_to_coordinate(i,&ix,&iy);
	from_index_to_coordinate(g,&gx,&gy);
	return abs(gx-ix) * abs(gx-ix) + abs(gy-iy) * abs(gy-iy);
}
void init_dist() {
	for (int i = 0; i < WID * HIG;i++) {
		dist[i] = INF;
	}
}
void init_wall() {
	for (int i = 0; i < HIG;i++) {
		graph[i][0] = 3;
	}
	for (int i = 0; i < HIG; i++) {
		graph[i][WID-1] = 3;
	}
	for (int i = 0; i < WID;i++) {
		graph[0][i] = 3;
	}
	for (int i = 0; i < WID; i++) {
		graph[HIG-1][i] = 3;
	}
	graph[1][WID/2] = 3;
	graph[2][WID / 2] = 3;
	graph[3][WID / 2] = 3;
	graph[4][WID / 2] = 3;
	graph[5][WID / 2] = 3;
	graph[6][WID / 2] = 3;
	graph[7][WID / 2] = 3;
	graph[8][WID / 2] = 3;
	graph[9][WID / 2] = 3;
	graph[10][WID / 2] = 3;
	graph[11][WID / 2] = 3;
	graph[12][WID / 2] = 3;
	graph[13][WID / 2] = 3;
	graph[14][WID / 2] = 3;
	graph[40-21][29+21] = 3;
	graph[41-21][28+21] = 3;
	graph[42-21][27+21] = 3;
	graph[43-21][26+21] = 3;
	graph[44-21][25+21] = 3;
	graph[45-21][24+21] = 3;
}
void a_star(d2_prqueue* x) {
	printf("@");
	int index_from = start;
	int t_cost_from = 0;
	int x_from = 0;
	int y_from = 0;
	from_index_to_coordinate(index_from, &x_from, &y_from);
	p2_put(x,0 + get_h_dist(index_from,goal),start);
	graph[y_from][x_from] = 2;
	while (p2_get(x,&t_cost_from,&index_from)) {
		int g_cost_from = t_cost_from - get_h_dist(index_from, goal);
		from_index_to_coordinate(index_from, &x_from, &y_from);
		graph[y_from][x_from] = 2;
		if (t_cost_from > dist[index_from]) {
			continue;
		}
		if (index_from == goal) {
			break;
		}
		dist[index_from] = t_cost_from;
		for (int i = 0; i < 4;i++) {
			int index_to = 0;
			int t_cost_to = 0;
			int x_to = x_from + direction[i][0];
			int y_to = y_from + direction[i][1];
			from_coordinate_to_index(x_to,y_to,&index_to);
			t_cost_to = g_cost_from + 1 + get_h_dist(index_to,goal);
			if ((graph[y_to][x_to] != 3)&&(0 <= x_to)&&(x_to <= WID)&&(0 <= y_to)&&(y_to <= HIG)) {
				if (dist[index_to] > t_cost_to) {
					p2_put(x, t_cost_to, index_to);
					graph[y_to][x_to] = 1;
				}
			}
		}
	}
}
void frame() {
	glBegin(GL_LINES);
	for (int i = 0; i < WID;i++) {
		glVertex2i(i*10,0);
		glVertex2i(i*10,HIG*10);
	}
	for (int i = 0; i < HIG;i++) {
		glVertex2i(0,i*10);
		glVertex2i(WID*10,i*10);
	}
	glEnd();
	glFlush();
}
void dot() {
	glBegin(GL_QUADS);
	for (int i = 0; i < HIG;i++) {
		for (int j = 0; j < WID;j++) {
			if (graph[i][j] == 3) {
				glColor3d(0.3,0.3,0.3);
			}
			else if (graph[i][j] == 2) {
				glColor3d(0.4,0.4,0.7);

			}
			else if (graph[i][j] == 1) {
				glColor3d(0.7,0.7,0.5);
			}
			else {
				glColor3d(0.7,0.7,0.7);
			}
			glVertex2i(j * 10, (HIG -1 - i) * 10);
			glVertex2i(j * 10 + 10, (HIG -1 - i) * 10);
			glVertex2i(j * 10 + 10, (HIG -1 - i) * 10 + 10);
			glVertex2i(j * 10, (HIG -1 - i) * 10 + 10);
		}
	}
	glColor3d(0.9, 0.7, 0.0);
	glVertex2i(1 * 10, (HIG - 1 - 1) * 10);
	glVertex2i(1 * 10 + 10, (HIG - 1 - 1) * 10);
	glVertex2i(1 * 10 + 10, (HIG - 1 - 1) * 10 + 10);
	glVertex2i(1 * 10, (HIG - 1 - 1) * 10 + 10);

	glColor3d(0.3, 0.7, 0.5);
	glVertex2i((WID-2) * 10, 1 * 10);
	glVertex2i((WID-2) * 10 + 10, 1 * 10);
	glVertex2i((WID-2) * 10 + 10, 1 * 10 + 10);
	glVertex2i((WID-2) * 10, 1 * 10 + 10);
	glEnd();
	glFlush();
}
void init() {
	glClearColor(0.0,0.0,0.0,1.0);
}
void idle() {
	glutPostRedisplay();
}
void disp() {
	glClear(GL_COLOR_BUFFER_BIT);
	dot();
	frame();
	glFlush();
	glutSwapBuffers();
}
void reshape(int w,int h) {
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,(double)w,0.0,(double)h);
	width = w;
	hight = h;
}
void mouse(int button,int state,int x,int y) {
	if ((button == GLUT_RIGHT_BUTTON)&&(state == GLUT_DOWN)) {
		a_star(&property);
	}
}
int main(int argc,char** argv) {
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(width,hight);
	glutCreateWindow("test");
	glutDisplayFunc(disp);
	glutReshapeFunc(reshape);
	glutIdleFunc(idle);//idleするならダブルバッファリングしろ
	glutMouseFunc(mouse);
	init();
	ip2(&property, body, index, WID * HIG);
	init_wall();
	init_dist();
	from_coordinate_to_index(1,1,&start);
	from_coordinate_to_index(WID-2,HIG-2,&goal);
	glutMainLoop();
}
