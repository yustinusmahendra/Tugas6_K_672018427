#include<windows.h>
#include<gl/glut.h>

void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void mouse(int button, int state, int x, int y);
void ukuran(int, int);
void mouseMotion(int x, int y);

float xrot =0;
float yrot = 0;
float xdiff = 0;
float ydiff = 0;
bool mouseDown = false;
int is_depth;

int main (int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(210, 50);
	glutCreateWindow("Yustinus Mahendra Dwi Putra - 672018427");
	init();
	glutDisplayFunc(tampil);
	glutKeyboardFunc(keyboard);
	
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	
	glutReshapeFunc(ukuran);
	glutIdleFunc(tampil);
	glutMainLoop();
	return 0;
}

void init(void)
{
	glClearColor(0.2,0.2,0.2,0);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_DEPTH_TEST);
	is_depth=1;
	glMatrixMode(GL_MODELVIEW);
	glPointSize(3.5);
	glLineWidth(1);
}

void tampil(void)
{
	if(is_depth)
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	else
	glClear(GL_COLOR_BUFFER_BIT);
	
	glLoadIdentity();
	gluLookAt(0,0,3,0,0,0,0,1,0);
	glRotatef(xrot, 1, 0,0);
	glRotatef(yrot, 0,1,0);
	glPushMatrix();
	
	//depan 1
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 190);
	glVertex3f(-45,15,0);
	glVertex3f(-15,15,0);
	glVertex3f(-15,-5,0);
	glVertex3f(-45,-5,0);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex3f(-45,-5,0);
	glVertex3f(-45,-15,0);
	glVertex3f(-15,-15,0);
	glVertex3f(-15,-5,0);
	glEnd();
	
	//depan 2
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 190);
	glVertex3f(-15,15,0);
	glVertex3f(-15,-5,0);
	glVertex3f(-15,-5,-5);
	glVertex3f(-15,15,-5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex3f(-15,-5,0);
	glVertex3f(-15,-15,0);
	glVertex3f(-15,-15,-5);
	glVertex3f(-15,-5,-5);
	glEnd();
	
	//depan 3
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 190);
	glVertex3f(-15,15,-5);
	glVertex3f(-15,-5,-5);
	glVertex3f(15,-5,-5);
	glVertex3f(15,15,-5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex3f(-15,-5,-5);
	glVertex3f(-15,-15,-5);
	glVertex3f(15,-15,-5);
	glVertex3f(15,-5,-5);
	glEnd();
	
	//depan 4
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 190);
	glVertex3f(15,15,0);
	glVertex3f(15,-5,0);
	glVertex3f(15,-5,-5);
	glVertex3f(15,15,-5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex3f(15,-5,0);
	glVertex3f(15,-15,0);
	glVertex3f(15,-15,-5);
	glVertex3f(15,-5,-5);
	glEnd();
	
	//depan 5
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 190);
	glVertex3f(45,15,0);
	glVertex3f(15,15,0);
	glVertex3f(15,-5,0);
	glVertex3f(45,-5,0);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex3f(45,-5,0);
	glVertex3f(45,-15,0);
	glVertex3f(15,-15,0);
	glVertex3f(15,-5,0);
	glEnd();
	
	//belakang
	glBegin(GL_QUADS);
	glColor3ub(220, 255, 240);
	glVertex3f(-45,-15,-95);
	glVertex3f(-45,15,-95);
	glVertex3f(45,15,-95);
	glVertex3f(45,-15,-95);
	glEnd();
	
	//tengah depan 1
	glBegin(GL_QUADS);
	glColor3ub(220, 255, 240);
	glVertex3f(-45,-15,-35);
	glVertex3f(-15,-15,-35);
	glVertex3f(-15,15,-35);
	glVertex3f(-45,15,-35);
	glEnd();
	
	//tengah depan 2
	glBegin(GL_QUADS);
	glColor3ub(220, 255, 240);
	glVertex3f(15,15,-35);
	glVertex3f(15,-15,-35);
	glVertex3f(45,-15,-35);
	glVertex3f(45,15,-35);
	glEnd();
	
	//tengah ke belakang 1
	glBegin(GL_QUADS);
	glColor3ub(220, 255, 240);
	glVertex3f(-15,15,-35);
	glVertex3f(-15,-15,-35);
	glVertex3f(-15,-15,-65);
	glVertex3f(-15,15,-65);
	glEnd();

	//tengah ke belakang 2
	glBegin(GL_QUADS);
	glColor3ub(220, 255, 240);
	glVertex3f(-15,15,-75);
	glVertex3f(-15,-15,-75);
	glVertex3f(-15,-15,-95);
	glVertex3f(-15,15,-95);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(220, 255, 240);
	glVertex3f(-15,15,-75);
	glVertex3f(-15,5,-75);
	glVertex3f(-15,5,-65);
	glVertex3f(-15,15,-65);
	glEnd();
	
	//tengah ke belakang 3
	glBegin(GL_QUADS);
	glColor3ub(220, 255, 240);
	glVertex3f(15,15,-35);
	glVertex3f(15,-15,-35);
	glVertex3f(15,-15,-95);
	glVertex3f(15,15,-95);
	glEnd();
	
	//tengah belakang
	glBegin(GL_QUADS);
	glColor3ub(220, 255, 240);
	glVertex3f(-45,-15,-65);
	glVertex3f(-45,15,-65);
	glVertex3f(45,15,-65);
	glVertex3f(45,-15,-65);
	glEnd();
	
	//kiri
	glBegin(GL_QUADS);
	glColor3ub(220, 255, 240);
	glVertex3f(-45,-15,0);
	glVertex3f(-45,15,0);
	glVertex3f(-45,15,-95);
	glVertex3f(-45,-15,-95);
	glEnd();
	
	//kanan
	glBegin(GL_QUADS);
	glColor3ub(220, 255, 240);
	glVertex3f(45,-15,0);
	glVertex3f(45,15,0);
	glVertex3f(45,15,-95);
	glVertex3f(45,-15,-95);
	glEnd();
	
	//bawah
	glBegin(GL_QUADS);
	glColor3ub(200,200,200);
	glVertex3f(-55,-15,-105);
	glVertex3f(55,-15,-105);
	glVertex3f(55,-15,35);
	glVertex3f(-55,-15,35);
	glEnd();
	
	//langit-langit 1
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 190);
	glVertex3f(-45,15,0);
	glVertex3f(-15,15,0);
	glVertex3f(-15,15,-95);
	glVertex3f(-45,15,-95);
	glEnd();
	
	//langit-langit 2
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 190);
	glVertex3f(-15,15,-5);
	glVertex3f(15,15,-5);
	glVertex3f(15,15,-95);
	glVertex3f(-15,15,-95);
	glEnd();
	
	//langit-langit 3
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 190);
	glVertex3f(15,15,0);
	glVertex3f(45,15,0);
	glVertex3f(45,15,-95);
	glVertex3f(15,15,-95);
	glEnd();
	
	//segitiga kiri
	glBegin(GL_TRIANGLES);
	glColor3ub(220, 255, 240);
	glVertex3f(-45,15,0);
	glVertex3f(-45,45,-47.5);
	glVertex3f(-45,15,-95);
	glEnd();
	
	//segitiga kanan
	glBegin(GL_TRIANGLES);
	glColor3ub(220, 255, 240);
	glVertex3f(45,15,0);
	glVertex3f(45,45,-47.5);
	glVertex3f(45,15,-95);
	glEnd();
	
	//tiang 1
	glBegin(GL_QUADS);
	glColor3ub(250,215,205);
	glVertex3f(-17,12,33);
	glVertex3f(-17,-8,33);
	glVertex3f(-13,-8,33);
	glVertex3f(-13,12,33);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(250,215,205);
	glVertex3f(-17,12,29);
	glVertex3f(-17,-8,29);
	glVertex3f(-13,-8,29);
	glVertex3f(-13,12,29);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(250,215,205);
	glVertex3f(-17,12,33);
	glVertex3f(-17,-8,33);
	glVertex3f(-17,-8,29);
	glVertex3f(-17,12,29);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(250,215,205);
	glVertex3f(-13,12,33);
	glVertex3f(-13,-8,33);
	glVertex3f(-13,-8,29);
	glVertex3f(-13,12,29);
	glEnd();
	
	//tiang 2
	glBegin(GL_QUADS);
	glColor3ub(250,215,205);
	glVertex3f(17,12,33);
	glVertex3f(17,-8,33);
	glVertex3f(13,-8,33);
	glVertex3f(13,12,33);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(250,215,205);
	glVertex3f(17,12,29);
	glVertex3f(17,-8,29);
	glVertex3f(13,-8,29);
	glVertex3f(13,12,29);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(250,215,205);
	glVertex3f(17,12,33);
	glVertex3f(17,-8,33);
	glVertex3f(17,-8,29);
	glVertex3f(17,12,29);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(250,215,205);
	glVertex3f(13,12,33);
	glVertex3f(13,-8,33);
	glVertex3f(13,-8,29);
	glVertex3f(13,12,29);
	glEnd();
	
	//tiang bawah 1
	glBegin(GL_QUADS);
	glColor3ub(255,180,170);
	glVertex3f(17.5,-15,33.5);
	glVertex3f(17.5,-8,33.5);
	glVertex3f(12.5,-8,33.5);
	glVertex3f(12.5,-15,33.5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255,180,170);
	glVertex3f(17.5,-15,28.5);
	glVertex3f(17.5,-8,28.5);
	glVertex3f(12.5,-8,28.5);
	glVertex3f(12.5,-15,28.5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255,180,170);
	glVertex3f(17.5,-15,33.5);
	glVertex3f(17.5,-8,33.5);
	glVertex3f(17.5,-8,28.5);
	glVertex3f(17.5,-15,28.5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255,180,170);
	glVertex3f(12.5,-15,33.5);
	glVertex3f(12.5,-8,33.5);
	glVertex3f(12.5,-8,28.5);
	glVertex3f(12.5,-15,28.5);
	glEnd();
	
	//tiang bawah 2
	glBegin(GL_QUADS);
	glColor3ub(255,180,170);
	glVertex3f(-17.5,-15,33.5);
	glVertex3f(-17.5,-8,33.5);
	glVertex3f(-12.5,-8,33.5);
	glVertex3f(-12.5,-15,33.5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255,180,170);
	glVertex3f(-17.5,-15,28.5);
	glVertex3f(-17.5,-8,28.5);
	glVertex3f(-12.5,-8,28.5);
	glVertex3f(-12.5,-15,28.5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255,180,170);
	glVertex3f(-17.5,-15,33.5);
	glVertex3f(-17.5,-8,33.5);
	glVertex3f(-17.5,-8,28.5);
	glVertex3f(-17.5,-15,28.5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255,180,170);
	glVertex3f(-12.5,-15,33.5);
	glVertex3f(-12.5,-8,33.5);
	glVertex3f(-12.5,-8,28.5);
	glVertex3f(-12.5,-15,28.5);
	glEnd();
	
	//atap rumah
	glBegin(GL_QUADS);
	glColor3ub(130,0,0);
	glVertex3f(-50,13.2,3);
	glVertex3f(50,13.2,3);
	glVertex3f(50,45,-47.5);
	glVertex3f(-50,45,-47.5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(130,0,0);
	glVertex3f(-50,13.2,-98);
	glVertex3f(50,13.2,-98);
	glVertex3f(50,45,-47.5);
	glVertex3f(-50,45,-47.5);
	glEnd();
		
	//teras 1
	//dinding pink kiri
	glBegin(GL_QUADS);
	glColor3ub(255,180,170);
	glVertex3f(-20,12,33);
	glVertex3f(-10,12,33);
	glVertex3f(-10,9,33);
	glVertex3f(-20,9,33);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255,180,170);
	glVertex3f(-20,12,29);
	glVertex3f(-10,12,29);
	glVertex3f(-10,9,29);
	glVertex3f(-20,9,29);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255,180,170);
	glVertex3f(-20,12,33);
	glVertex3f(-10,12,33);
	glVertex3f(-10,12,29);
	glVertex3f(-20,12,29);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255,180,170);
	glVertex3f(-20,9,33);
	glVertex3f(-10,9,33);
	glVertex3f(-10,9,29);
	glVertex3f(-20,9,29);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255,180,170);
	glVertex3f(-20,12,33);
	glVertex3f(-20,9,33);
	glVertex3f(-20,9,29);
	glVertex3f(-20,12,29);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255,180,170);
	glVertex3f(-10,12,33);
	glVertex3f(-10,9,33);
	glVertex3f(-10,9,29);
	glVertex3f(-10,12,29);
	glEnd();
	
	//dinding pink kanan
	glBegin(GL_QUADS);
	glColor3ub(255,180,170);
	glVertex3f(20,12,33);
	glVertex3f(10,12,33);
	glVertex3f(10,9,33);
	glVertex3f(20,9,33);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255,180,170);
	glVertex3f(20,12,29);
	glVertex3f(10,12,29);
	glVertex3f(10,9,29);
	glVertex3f(20,9,29);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255,180,170);
	glVertex3f(20,12,33);
	glVertex3f(10,12,33);
	glVertex3f(10,12,29);
	glVertex3f(20,12,29);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255,180,170);
	glVertex3f(20,9,33);
	glVertex3f(10,9,33);
	glVertex3f(10,9,29);
	glVertex3f(20,9,29);
	glEnd();
		
	glBegin(GL_QUADS);
	glColor3ub(255,180,170);
	glVertex3f(20,12,33);
	glVertex3f(20,9,33);
	glVertex3f(20,9,29);
	glVertex3f(20,12,29);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255,180,170);
	glVertex3f(10,12,33);
	glVertex3f(10,9,33);
	glVertex3f(10,9,29);
	glVertex3f(10,12,29);
	glEnd();
	
	//dinding pink tengah
	glBegin(GL_QUADS);
	glColor3ub(255,180,170);
	glVertex3f(-10,12,33);
	glVertex3f(10,12,33);
	glVertex3f(10,15,33);
	glVertex3f(-10,15,33);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255,180,170);
	glVertex3f(-10,12,29);
	glVertex3f(10,12,29);
	glVertex3f(10,15,29);
	glVertex3f(-10,15,29);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255,180,170);
	glVertex3f(-10,12,33);
	glVertex3f(10,12,33);
	glVertex3f(10,12,29);
	glVertex3f(-10,12,29);
	glEnd();
	
	//dinding cream
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 190);
	glVertex3f(-15,15,33);
	glVertex3f(-10,15,33);
	glVertex3f(-10,12,33);
	glVertex3f(-15,12,33);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 190);
	glVertex3f(-15,15,29);
	glVertex3f(-10,15,29);
	glVertex3f(-10,12,29);
	glVertex3f(-15,12,29);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 190);
	glVertex3f(15,15,33);
	glVertex3f(10,15,33);
	glVertex3f(10,12,33);
	glVertex3f(15,12,33);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 190);
	glVertex3f(15,15,29);
	glVertex3f(10,15,29);
	glVertex3f(10,12,29);
	glVertex3f(15,12,29);
	glEnd();
	
	//langit-langit teras
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 190);
	glVertex3f(-15,15,29);
	glVertex3f(15,15,29);
	glVertex3f(15,12,-5);
	glVertex3f(-15,12,-5);
	glEnd();
	
	//dinding samping kiri
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 190);
	glVertex3f(-17,15,36);
	glVertex3f(-15,15,36);
	glVertex3f(-15,15,0);
	glVertex3f(-17,15,0);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 190);
	glVertex3f(-17,12,36);
	glVertex3f(-15,12,36);
	glVertex3f(-15,12,0);
	glVertex3f(-17,12,0);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 190);
	glVertex3f(-17,15,36);
	glVertex3f(-17,12,36);
	glVertex3f(-17,12,0);
	glVertex3f(-17,15,0);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 190);
	glVertex3f(-15,15,36);
	glVertex3f(-15,12,36);
	glVertex3f(-15,12,0);
	glVertex3f(-15,15,0);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 190);
	glVertex3f(-17,15,36);
	glVertex3f(-17,12,36);
	glVertex3f(-15,12,36);
	glVertex3f(-15,15,36);
	glEnd();
	
	//dinding samping kanan
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 190);
	glVertex3f(17,15,36);
	glVertex3f(15,15,36);
	glVertex3f(15,15,0);
	glVertex3f(17,15,0);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 190);
	glVertex3f(17,12,36);
	glVertex3f(15,12,36);
	glVertex3f(15,12,0);
	glVertex3f(17,12,0);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 190);
	glVertex3f(17,15,36);
	glVertex3f(17,12,36);
	glVertex3f(17,12,0);
	glVertex3f(17,15,0);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 190);
	glVertex3f(15,15,36);
	glVertex3f(15,12,36);
	glVertex3f(15,12,0);
	glVertex3f(15,15,0);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 190);
	glVertex3f(17,15,36);
	glVertex3f(17,12,36);
	glVertex3f(15,12,36);
	glVertex3f(15,15,36);
	glEnd();
	
	//segitiga teras
	glBegin(GL_TRIANGLES);
	glColor3ub(255, 255, 190);
	glVertex3f(-17,15,33);
	glVertex3f(17,15,33);
	glVertex3f(0,30,33);
	glEnd();
	
	//atap teras
	glBegin(GL_QUADS);
	glColor3ub(130,0,0);
	glVertex3f(-20,13,40);
	glVertex3f(0,30,40);
	glVertex3f(0,30,-25);
	glVertex3f(-20,13,3.5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(130,0,0);
	glVertex3f(20,13,40);
	glVertex3f(0,30,40);
	glVertex3f(0,30,-25);
	glVertex3f(20,13,3.5);
	glEnd();
	
	//teras 2
	glBegin(GL_QUADS);
	glColor3ub(230,230,230);
	glVertex3f(15,12,36);
	glVertex3f(50,12,36);
	glVertex3f(50,13,0);
	glVertex3f(15,13,0);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(230,230,230);
	glVertex3f(48,-15,32.5);
	glVertex3f(48,12,32.5);
	glVertex3f(48,12,33);
	glVertex3f(48,-15,33);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(230,230,230);
	glVertex3f(48.5,-15,32.5);
	glVertex3f(48.5,12,32.5);
	glVertex3f(48.5,12,33);
	glVertex3f(48.5,-15,33);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(230,230,230);
	glVertex3f(48.5,-15,33);
	glVertex3f(48.5,12,33);
	glVertex3f(48,12,33);
	glVertex3f(48,-15,33);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(230,230,230);
	glVertex3f(48.5,-15,32.5);
	glVertex3f(48.5,12,32.5);
	glVertex3f(48,12,32.5);
	glVertex3f(48,-15,32.5);
	glEnd();

	//teras 3
	glBegin(GL_QUADS);
	glColor3ub(230,230,230);
	glVertex3f(-15,12,36);
	glVertex3f(-50,12,36);
	glVertex3f(-50,13,0);
	glVertex3f(-15,13,0);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(230,230,230);
	glVertex3f(-48,-15,32.5);
	glVertex3f(-48,12,32.5);
	glVertex3f(-48,12,33);
	glVertex3f(-48,-15,33);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(230,230,230);
	glVertex3f(-48.5,-15,32.5);
	glVertex3f(-48.5,12,32.5);
	glVertex3f(-48.5,12,33);
	glVertex3f(-48.5,-15,33);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(230,230,230);
	glVertex3f(-48.5,-15,33);
	glVertex3f(-48.5,12,33);
	glVertex3f(-48,12,33);
	glVertex3f(-48,-15,33);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(230,230,230);
	glVertex3f(-48.5,-15,32.5);
	glVertex3f(-48.5,12,32.5);
	glVertex3f(-48,12,32.5);
	glVertex3f(-48,-15,32.5);
	glEnd();

	//detail
	//aksesoris teras 1
	glBegin(GL_QUADS);
	glColor3ub(255,180,170);
	glVertex3f(1,30,40);
	glVertex3f(-1,30,40);
	glVertex3f(-1,24,40);
	glVertex3f(1,24,40);
	glEnd();
	
	//aksesoris teras 2
	glBegin(GL_QUADS);
	glColor3ub(255,180,170);
	glVertex3f(0,30,40);
	glVertex3f(0,27,40);
	glVertex3f(20,10,40);
	glVertex3f(20,13,40);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255,180,170);
	glVertex3f(0,30,40);
	glVertex3f(0,27,40);
	glVertex3f(-20,10,40);
	glVertex3f(-20,13,40);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(200, 140, 70);
	glVertex3f(-4,20.5,33.1);
	glVertex3f(0,16,33.1);
	glVertex3f(4,20.5,33.1);
	glVertex3f(0,25,33.1);
	glEnd();
	
	//pintu utama
	glBegin(GL_QUADS);
	glColor3ub(100,50,20);
	glVertex3f(-6,10,-4.9);
	glVertex3f(6,10,-4.9);
	glVertex3f(6,-15,-4.9);
	glVertex3f(-6,-15,-4.9);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3ub(0,0,0);
	glVertex3f(0,-15,-4.8);
	glVertex3f(0,5,-4.8);
	glEnd();
	
	glBegin(GL_POINTS);
	glColor3ub(0,0,0);
	glVertex3f(1,-4,-4.8);
	glVertex3f(-1,-4,-4.8);
	glEnd();
	
	//kaca atas pintu
	glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex3f(-5,9,-4.8);
	glVertex3f(5,9,-4.8);
	glVertex3f(5,6,-4.8);
	glVertex3f(-5,6,-4.8);
	glEnd();
	
	//pintu samping
	glBegin(GL_QUADS);
	glColor3ub(100,50,20);
	glVertex3f(-45.1,-15,-67);
	glVertex3f(-45.1,5,-67);
	glVertex3f(-45.1,5,-73);
	glVertex3f(-45.1,-15,-73);
	glEnd();
	
	glBegin(GL_POINTS);
	glColor3ub(0,0,0);
	glVertex3f(-45.1,-4,-72);
	glVertex3f(-45.1,-4,-72);
	glEnd();
	
	//pintu 1
	glBegin(GL_QUADS);
	glColor3ub(100,50,20);
	glVertex3f(14.9,-15,-67);
	glVertex3f(14.9,5,-67);
	glVertex3f(14.9,5,-73);
	glVertex3f(14.9,-15,-73);
	glEnd();
	
	glBegin(GL_POINTS);
	glColor3ub(0,0,0);
	glVertex3f(14.9,-4,-72);
	glVertex3f(14.9,-4,-72);
	glEnd();
	
	//pintu 2
	glBegin(GL_QUADS);
	glColor3ub(100,50,20);
	glVertex3f(14.9,-15,-57);
	glVertex3f(14.9,10,-57);
	glVertex3f(14.9,10,-63);
	glVertex3f(14.9,-15,-63);
	glEnd();
	
	glBegin(GL_POINTS);
	glColor3ub(0,0,0);
	glVertex3f(14.9,-4,-58);
	glVertex3f(14.9,-4,-58);
	glEnd();
	
	//kaca pintu 2
	glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex3f(14.8,9,-58);
	glVertex3f(14.8,9,-62);
	glVertex3f(14.8,6,-62);
	glVertex3f(14.8,6,-58);
	glEnd();
	
	//pintu 3
	glBegin(GL_QUADS);
	glColor3ub(100,50,20);
	glVertex3f(-14.9,-15,-57);
	glVertex3f(-14.9,10,-57);
	glVertex3f(-14.9,10,-63);
	glVertex3f(-14.9,-15,-63);
	glEnd();
	
	glBegin(GL_POINTS);
	glColor3ub(0,0,0);
	glVertex3f(-14.9,-4,-58);
	glVertex3f(-14.9,-4,-58);
	glEnd();
	
	//kaca pintu 3
	glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex3f(-14.8,9,-58);
	glVertex3f(-14.8,9,-62);
	glVertex3f(-14.8,6,-62);
	glVertex3f(-14.8,6,-58);
	glEnd();
	
	//pintu 4
	glBegin(GL_QUADS);
	glColor3ub(100,50,20);
	glVertex3f(-3,-15,-64.9);
	glVertex3f(-3,5,-64.9);
	glVertex3f(3,5,-64.9);
	glVertex3f(3,-15,-64.9);
	glEnd();
	
	glBegin(GL_POINTS);
	glColor3ub(0,0,0);
	glVertex3f(2,-4,-64.8);
	glVertex3f(2,-4,-64.8);
	glEnd();
	
	//jendela tengah 1
	glBegin(GL_QUADS);
	glColor3ub(100,50,20);
	glVertex3f(-14,-10,-4.9);
	glVertex3f(-14,10,-4.9);
	glVertex3f(-7,10,-4.9);
	glVertex3f(-7,-10,-4.9);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex3f(-13,-8,-4.8);
	glVertex3f(-13,5,-4.8);
	glVertex3f(-8,5,-4.8);
	glVertex3f(-8,-8,-4.8);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex3f(-13,6,-4.8);
	glVertex3f(-13,9,-4.8);
	glVertex3f(-8,9,-4.8);
	glVertex3f(-8,6,-4.8);
	glEnd();
	
	//jendela tengah 2
	glBegin(GL_QUADS);
	glColor3ub(100,50,20);
	glVertex3f(14,-10,-4.9);
	glVertex3f(14,10,-4.9);
	glVertex3f(7,10,-4.9);
	glVertex3f(7,-10,-4.9);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex3f(13,-8,-4.8);
	glVertex3f(13,5,-4.8);
	glVertex3f(8,5,-4.8);
	glVertex3f(8,-8,-4.8);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex3f(13,6,-4.8);
	glVertex3f(13,9,-4.8);
	glVertex3f(8,9,-4.8);
	glVertex3f(8,6,-4.8);
	glEnd();
	
	//jendela kanan
	glBegin(GL_QUADS);
	glColor3ub(100,50,20);
	glVertex3f(38,-10,0.1);
	glVertex3f(38,10,0.1);
	glVertex3f(22,10,0.1);
	glVertex3f(22,-10,0.1);
	glEnd();
	
	//kaca kanan
	glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex3f(29,-8,0.2);
	glVertex3f(29,5,0.2);
	glVertex3f(23,5,0.2);
	glVertex3f(23,-8,0.2);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex3f(37,-8,0.2);
	glVertex3f(37,5,0.2);
	glVertex3f(31,5,0.2);
	glVertex3f(31,-8,0.2);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex3f(37,9,0.2);
	glVertex3f(37,6,0.2);
	glVertex3f(31,6,0.2);
	glVertex3f(31,9,0.2);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex3f(29,9,0.2);
	glVertex3f(29,6,0.2);
	glVertex3f(23,6,0.2);
	glVertex3f(23,9,0.2);
	glEnd();
	
	//jendela kiri
	glBegin(GL_QUADS);
	glColor3ub(100,50,20);
	glVertex3f(-38,-10,0.1);
	glVertex3f(-38,10,0.1);
	glVertex3f(-22,10,0.1);
	glVertex3f(-22,-10,0.1);
	glEnd();
	
	//kaca kiri
	glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex3f(-29,-8,0.2);
	glVertex3f(-29,5,0.2);
	glVertex3f(-23,5,0.2);
	glVertex3f(-23,-8,0.2);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex3f(-37,-8,0.2);
	glVertex3f(-37,5,0.2);
	glVertex3f(-31,5,0.2);
	glVertex3f(-31,-8,0.2);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex3f(-37,9,0.2);
	glVertex3f(-37,6,0.2);
	glVertex3f(-31,6,0.2);
	glVertex3f(-31,9,0.2);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex3f(-29,9,0.2);
	glVertex3f(-29,6,0.2);
	glVertex3f(-23,6,0.2);
	glVertex3f(-23,9,0.2);
	glEnd();
	
	//jendela samping kiri
	glBegin(GL_QUADS);
	glColor3ub(100,50,20);
	glVertex3f(-45.1,-10,-43);
	glVertex3f(-45.1,5,-43);
	glVertex3f(-45.1,5,-48);
	glVertex3f(-45.1,-10,-48);
	glEnd();
	
	//kaca samping kiri
	glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex3f(-45.2,2,-44);
	glVertex3f(-45.2,4,-44);
	glVertex3f(-45.2,4,-47);
	glVertex3f(-45.2,2,-47);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex3f(-45.2,-8,-44);
	glVertex3f(-45.2,1,-44);
	glVertex3f(-45.2,1,-47);
	glVertex3f(-45.2,-8,-47);
	glEnd();
	
	//jendela samping kanan 1
	glBegin(GL_QUADS);
	glColor3ub(100,50,20);
	glVertex3f(45.1,-10,-43);
	glVertex3f(45.1,5,-43);
	glVertex3f(45.1,5,-48);
	glVertex3f(45.1,-10,-48);
	glEnd();
	
	//kaca samping kanan 1
	glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex3f(45.2,2,-44);
	glVertex3f(45.2,4,-44);
	glVertex3f(45.2,4,-47);
	glVertex3f(45.2,2,-47);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex3f(45.2,-8,-44);
	glVertex3f(45.2,1,-44);
	glVertex3f(45.2,1,-47);
	glVertex3f(45.2,-8,-47);
	glEnd();
	
	//jendela samping kanan 2
	glBegin(GL_QUADS);
	glColor3ub(100,50,20);
	glVertex3f(45.1,-10,-80);
	glVertex3f(45.1,0,-80);
	glVertex3f(45.1,0,-90);
	glVertex3f(45.1,-10,-90);
	glEnd();
	
	//kaca samping kanan 2
	glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex3f(45.2,-1,-85.5);
	glVertex3f(45.2,-9,-85.5);
	glVertex3f(45.2,-9,-89);
	glVertex3f(45.2,-1,-89);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex3f(45.2,-1,-81);
	glVertex3f(45.2,-9,-81);
	glVertex3f(45.2,-9,-85);
	glVertex3f(45.2,-1,-85);
	glEnd();
	
	//jendela belakang
	glBegin(GL_QUADS);
	glColor3ub(100,50,20);
	glVertex3f(-35,-3,-95.1);
	glVertex3f(-35,3,-95.1);
	glVertex3f(-25,3,-95.1);
	glVertex3f(-25,-3,-95.1);
	glEnd();
	
	//kaca belakang
	glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex3f(-34,-2,-95.2);
	glVertex3f(-34,2,-95.2);
	glVertex3f(-26,2,-95.2);
	glVertex3f(-26,-2,-95.2);
	glEnd();
	
	//objek
	//sofa 1
	glBegin(GL_QUADS);
	glColor3ub(255, 180, 162);
	glVertex3f(18,-11,0.3);
	glVertex3f(45,-11,0.3);
	glVertex3f(45,-11,7);
	glVertex3f(18,-11,7);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255, 241, 230);
	glVertex3f(18,-11,7);
	glVertex3f(45,-11,7);
	glVertex3f(45,-15,7);
	glVertex3f(18,-15,7);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255, 180, 162);
	glVertex3f(18,-5,0.3);
	glVertex3f(45,-5,0.3);
	glVertex3f(45,-5,2);
	glVertex3f(18,-5,2);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255, 180, 162);
	glVertex3f(18,-5,2);
	glVertex3f(45,-5,2);
	glVertex3f(45,-15,2);
	glVertex3f(18,-15,2);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255, 241, 230);
	glVertex3f(18,-5,0.3);
	glVertex3f(18,-15,0.3);
	glVertex3f(18,-15,2);
	glVertex3f(18,-5,2);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255, 241, 230);
	glVertex3f(18,-11,0.3);
	glVertex3f(18,-15,0.3);
	glVertex3f(18,-15,7);
	glVertex3f(18,-11,7);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255, 241, 230);
	glVertex3f(45,-5,0.3);
	glVertex3f(45,-15,0.3);
	glVertex3f(18,-15,0.3);
	glVertex3f(18,-5,0.3);
	glEnd();
	
	//sofa 2
	glBegin(GL_QUADS);
	glColor3ub(255, 180, 162);
	glVertex3f(45,-11,17);
	glVertex3f(38,-11,17);
	glVertex3f(38,-11,7);
	glVertex3f(45,-11,7);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255, 241, 230);
	glVertex3f(45,-5,0.3);
	glVertex3f(45,-15,0.3);
	glVertex3f(45,-15,17);
	glVertex3f(45,-5,17);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255, 180, 162);
	glVertex3f(43,-5,0.3);
	glVertex3f(43,-15,0.3);
	glVertex3f(43,-15,17);
	glVertex3f(43,-5,17);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255, 241, 230);
	glVertex3f(38,-11,0.3);
	glVertex3f(38,-15,0.3);
	glVertex3f(38,-15,17);
	glVertex3f(38,-11,17);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255, 241, 230);
	glVertex3f(43,-5,17);
	glVertex3f(45,-5,17);
	glVertex3f(45,-15,17);
	glVertex3f(43,-15,17);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255, 241, 230);
	glVertex3f(38,-11,17);
	glVertex3f(45,-11,17);
	glVertex3f(45,-15,17);
	glVertex3f(38,-15,17);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255, 180, 162);
	glVertex3f(45,-5,0.3);
	glVertex3f(43,-5,0.3);
	glVertex3f(43,-5,17);
	glVertex3f(45,-5,17);
	glEnd();
	
	//lemari buku
	glBegin(GL_QUADS);
	glColor3ub(188, 108, 37);
	glVertex3f(-4,-15,-62);
	glVertex3f(-4,-5,-62);
	glVertex3f(-9,-5,-62);
	glVertex3f(-9,-15,-62);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(188, 108, 37);
	glVertex3f(-9,-15,-62);
	glVertex3f(-9,-5,-62);
	glVertex3f(-9,-5,-64.9);
	glVertex3f(-9,-15,-64.9);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(188, 108, 37);
	glVertex3f(-4,-15,-64.9);
	glVertex3f(-4,-5,-64.9);
	glVertex3f(-4,-5,-62);
	glVertex3f(-4,-15,-62);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(188, 108, 37);
	glVertex3f(-9,-5,-64.9);
	glVertex3f(-9,-5,-62);
	glVertex3f(-4,-5,-62);
	glVertex3f(-4,-5,-64.9);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(188, 108, 37);
	glVertex3f(-9,-5,-64.9);
	glVertex3f(-9,-15,-64.9);
	glVertex3f(-4,-15,-64.9);
	glVertex3f(-4,-5,-64.9);
	glEnd();
	
	//lemari 2
	glBegin(GL_QUADS);
	glColor3ub(188, 108, 37);
	glVertex3f(-3,-15,-35);
	glVertex3f(-3,5,-35);
	glVertex3f(15,5,-35);
	glVertex3f(15,-15,-35);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(188, 108, 37);
	glVertex3f(-3,-15,-40);
	glVertex3f(-3,5,-40);
	glVertex3f(15,5,-40);
	glVertex3f(15,-15,-40);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(188, 108, 37);
	glVertex3f(-3,-15,-35);
	glVertex3f(-3,5,-35);
	glVertex3f(-3,5,-40);
	glVertex3f(-3,-15,-40);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(188, 108, 37);
	glVertex3f(-3,5,-35);
	glVertex3f(-3,5,-40);
	glVertex3f(15,5,-40);
	glVertex3f(15,5,-35);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(188, 108, 37);
	glVertex3f(14.9,-15,-35);
	glVertex3f(14.9,5,-35);
	glVertex3f(14.9,5,-40);
	glVertex3f(14.9,-15,-40);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex3f(-1, 4,-34.9);
	glVertex3f(-1,-5,-34.9);
	glVertex3f(3,-5,-34.9);
	glVertex3f(3,4,-34.9);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex3f(9, 4,-34.9);
	glVertex3f(9,-5,-34.9);
	glVertex3f(13,-5,-34.9);
	glVertex3f(13,4,-34.9);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3ub(0,0,0);
	glVertex3f(-3,-7,-34.9);
	glVertex3f(15,-7,-34.9);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3ub(0,0,0);
	glVertex3f(6,5,-34.9);
	glVertex3f(6,-15,-34.9);
	glEnd();	
	
	glBegin(GL_LINES);
	glColor3ub(0,0,0);
	glVertex3f(10.5,-7,-34.9);
	glVertex3f(10.5,-15,-34.9);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3ub(0,0,0);
	glVertex3f(1.5,-7,-34.9);
	glVertex3f(1.5,-15,-34.9);
	glEnd();
	
	//kasur	1
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(-30,-15,-0.1);
	glVertex3f(-30,-12,-0.1);
	glVertex3f(-30,-12,-22);
	glVertex3f(-30,-15,-22);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(-44.9,-15,-22);
	glVertex3f(-44.9,-12,-22);
	glVertex3f(-30,-12,-22);
	glVertex3f(-30,-15,-22);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(217, 217, 217);
	glVertex3f(-30,-10,-0.1);
	glVertex3f(-30,-12,-0.1);
	glVertex3f(-30,-12,-22);
	glVertex3f(-30,-10,-22);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(217, 217, 217);
	glVertex3f(-44.9,-10,-22);
	glVertex3f(-44.9,-12,-22);
	glVertex3f(-30,-12,-22);
	glVertex3f(-30,-10,-22);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(217, 217, 217);
	glVertex3f(-44.9,-10,-0.1);
	glVertex3f(-30,-10,-0.1);
	glVertex3f(-30,-10,-22);
	glVertex3f(-44.9,-10,-22);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(-44.9,-15,-0.1);
	glVertex3f(-44.9,-12,-0.1);
	glVertex3f(-30,-12,-0.1);
	glVertex3f(-30,-15,-0.1);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(217, 217, 217);
	glVertex3f(-44.9,-10,-0.1);
	glVertex3f(-44.9,-12,-0.1);
	glVertex3f(-30,-12,-0.1);
	glVertex3f(-30,-10,-0.1);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(-44.9,-15,-0.1);
	glVertex3f(-44.9,-12,-0.1);
	glVertex3f(-44.9,-12,-22);
	glVertex3f(-44.9,-15,-22);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(217, 217, 217);
	glVertex3f(-44.9,-10,-0.1);
	glVertex3f(-44.9,-12,-0.1);
	glVertex3f(-44.9,-12,-22);
	glVertex3f(-44.9,-10,-22);
	glEnd();
	
	//bantal 1
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(-45,-9,-0.1);
	glVertex3f(-38,-9,-0.1);
	glVertex3f(-38,-9,-4);
	glVertex3f(-45,-9,-4);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(-38,-10,-0.1);
	glVertex3f(-38,-9,-0.1);
	glVertex3f(-38,-9,-4);
	glVertex3f(-38,-10,-4);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(-45,-10,-4);
	glVertex3f(-38,-10,-4);
	glVertex3f(-38,-9,-4);
	glVertex3f(-45,-9,-4);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(-45,-9,-0.1);
	glVertex3f(-38,-9,-0.1);
	glVertex3f(-38,-9,-4);
	glVertex3f(-45,-9,-4);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(-44.9,-10,-0.1);
	glVertex3f(-44.9,-9,-0.1);
	glVertex3f(-44.9,-9,-4);
	glVertex3f(-44.9,-10,-4);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(-45,-10,-0.1);
	glVertex3f(-38,-10,-0.1);
	glVertex3f(-38,-9,-0.1);
	glVertex3f(-45,-9,-0.1);
	glEnd();
	
	//bantal 2
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(-30,-9,-0.1);
	glVertex3f(-37,-9,-0.1);
	glVertex3f(-37,-9,-4);
	glVertex3f(-30,-9,-4);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(-37,-10,-0.1);
	glVertex3f(-37,-9,-0.1);
	glVertex3f(-37,-9,-4);
	glVertex3f(-37,-10,-4);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(-30,-10,-4);
	glVertex3f(-37,-10,-4);
	glVertex3f(-37,-9,-4);
	glVertex3f(-30,-9,-4);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(-30,-9,-0.1);
	glVertex3f(-37,-9,-0.1);
	glVertex3f(-37,-9,-4);
	glVertex3f(-30,-9,-4);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(-30,-9,-0.1);
	glVertex3f(-30,-10,-0.1);
	glVertex3f(-30,-10,-4);
	glVertex3f(-30,-9,-4);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(-30,-10,-0.1);
	glVertex3f(-37,-10,-0.1);
	glVertex3f(-37,-9,-0.1);
	glVertex3f(-30,-9,-0.1);
	glEnd();
	
	//selimut
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(-45,-9.9,-10);
	glVertex3f(-30,-9.9,-10);
	glVertex3f(-30,-9.9,-22);
	glVertex3f(-45,-9.9,-22);
	glEnd();
	
	//kasur	2
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(-30,-15,-35.1);
	glVertex3f(-30,-12,-35.1);
	glVertex3f(-30,-12,-57);
	glVertex3f(-30,-15,-57);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(-44.9,-15,-57);
	glVertex3f(-44.9,-12,-57);
	glVertex3f(-30,-12,-57);
	glVertex3f(-30,-15,-57);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(217, 217, 217);
	glVertex3f(-30,-10,-35.1);
	glVertex3f(-30,-12,-35.1);
	glVertex3f(-30,-12,-57);
	glVertex3f(-30,-10,-57);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(217, 217, 217);
	glVertex3f(-44.9,-10,-57);
	glVertex3f(-44.9,-12,-57);
	glVertex3f(-30,-12,-57);
	glVertex3f(-30,-10,-57);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(217, 217, 217);
	glVertex3f(-44.9,-10,-35.1);
	glVertex3f(-30,-10,-35.1);
	glVertex3f(-30,-10,-57);
	glVertex3f(-44.9,-10,-57);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(-44.9,-15,-35.1);
	glVertex3f(-44.9,-12,-35.1);
	glVertex3f(-30,-12,-35.1);
	glVertex3f(-30,-15,-35.1);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(217, 217, 217);
	glVertex3f(-44.9,-10,-35.1);
	glVertex3f(-44.9,-12,-35.1);
	glVertex3f(-30,-12,-35.1);
	glVertex3f(-30,-10,-35.1);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(-44.9,-15,-35.1);
	glVertex3f(-44.9,-12,-35.1);
	glVertex3f(-44.9,-12,-57);
	glVertex3f(-44.9,-15,-57);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(217, 217, 217);
	glVertex3f(-44.9,-10,-35.1);
	glVertex3f(-44.9,-12,-35.1);
	glVertex3f(-44.9,-12,-57);
	glVertex3f(-44.9,-10,-57);
	glEnd();
	
	//bantal 1
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(-45,-9,-35.1);
	glVertex3f(-38,-9,-35.1);
	glVertex3f(-38,-9,-39);
	glVertex3f(-45,-9,-39);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(-38,-10,-35.1);
	glVertex3f(-38,-9,-35.1);
	glVertex3f(-38,-9,-39);
	glVertex3f(-38,-10,-39);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(-45,-10,-39);
	glVertex3f(-38,-10,-39);
	glVertex3f(-38,-9,-39);
	glVertex3f(-45,-9,-39);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(-45,-9,-35.1);
	glVertex3f(-38,-9,-35.1);
	glVertex3f(-38,-9,-39);
	glVertex3f(-45,-9,-39);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(-44.9,-10,-35.1);
	glVertex3f(-44.9,-9,-35.1);
	glVertex3f(-44.9,-9,-39);
	glVertex3f(-44.9,-10,-39);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(-45,-10,-35.1);
	glVertex3f(-38,-10,-35.1);
	glVertex3f(-38,-9,-35.1);
	glVertex3f(-45,-9,-35.1);
	glEnd();
	
	//bantal 2
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(-30,-9,-35.1);
	glVertex3f(-37,-9,-35.1);
	glVertex3f(-37,-9,-39);
	glVertex3f(-30,-9,-39);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(-37,-10,-35.1);
	glVertex3f(-37,-9,-35.1);
	glVertex3f(-37,-9,-39);
	glVertex3f(-37,-10,-39);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(-30,-10,-39);
	glVertex3f(-37,-10,-39);
	glVertex3f(-37,-9,-39);
	glVertex3f(-30,-9,-39);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(-30,-9,-35.1);
	glVertex3f(-37,-9,-35.1);
	glVertex3f(-37,-9,-39);
	glVertex3f(-30,-9,-39);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(-30,-9,-35.1);
	glVertex3f(-30,-10,-35.1);
	glVertex3f(-30,-10,-39);
	glVertex3f(-30,-9,-39);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(-30,-10,-35.1);
	glVertex3f(-37,-10,-35.1);
	glVertex3f(-37,-9,-35.1);
	glVertex3f(-30,-9,-35.1);
	glEnd();
	
	//selimut
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(-45,-9.9,-45);
	glVertex3f(-30,-9.9,-45);
	glVertex3f(-30,-9.9,-57);
	glVertex3f(-45,-9.9,-57);
	glEnd();
	
	//kasur	3
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(30,-15,-35.1);
	glVertex3f(30,-12,-35.1);
	glVertex3f(30,-12,-57);
	glVertex3f(30,-15,-57);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(44.9,-15,-57);
	glVertex3f(44.9,-12,-57);
	glVertex3f(30,-12,-57);
	glVertex3f(30,-15,-57);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(217, 217, 217);
	glVertex3f(30,-10,-35.1);
	glVertex3f(30,-12,-35.1);
	glVertex3f(30,-12,-57);
	glVertex3f(30,-10,-57);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(217, 217, 217);
	glVertex3f(44.9,-10,-57);
	glVertex3f(44.9,-12,-57);
	glVertex3f(30,-12,-57);
	glVertex3f(30,-10,-57);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(217, 217, 217);
	glVertex3f(44.9,-10,-35.1);
	glVertex3f(30,-10,-35.1);
	glVertex3f(30,-10,-57);
	glVertex3f(44.9,-10,-57);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(44.9,-15,-35.1);
	glVertex3f(44.9,-12,-35.1);
	glVertex3f(30,-12,-35.1);
	glVertex3f(30,-15,-35.1);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(217, 217, 217);
	glVertex3f(44.9,-10,-35.1);
	glVertex3f(44.9,-12,-35.1);
	glVertex3f(30,-12,-35.1);
	glVertex3f(30,-10,-35.1);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(44.9,-15,-35.1);
	glVertex3f(44.9,-12,-35.1);
	glVertex3f(44.9,-12,-57);
	glVertex3f(44.9,-15,-57);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(217, 217, 217);
	glVertex3f(44.9,-10,-35.1);
	glVertex3f(44.9,-12,-35.1);
	glVertex3f(44.9,-12,-57);
	glVertex3f(44.9,-10,-57);
	glEnd();
	
	//bantal 1
	glBegin(GL_QUADS);
	glColor3ub(0, 75, 100);
	glVertex3f(45,-9,-35.1);
	glVertex3f(38,-9,-35.1);
	glVertex3f(38,-9,-39);
	glVertex3f(45,-9,-39);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(38,-10,-35.1);
	glVertex3f(38,-9,-35.1);
	glVertex3f(38,-9,-39);
	glVertex3f(38,-10,-39);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(45,-10,-39);
	glVertex3f(38,-10,-39);
	glVertex3f(38,-9,-39);
	glVertex3f(45,-9,-39);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(45,-9,-35.1);
	glVertex3f(38,-9,-35.1);
	glVertex3f(38,-9,-39);
	glVertex3f(45,-9,-39);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(44.9,-10,-35.1);
	glVertex3f(44.9,-9,-35.1);
	glVertex3f(44.9,-9,-39);
	glVertex3f(44.9,-10,-39);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(45,-10,-35.1);
	glVertex3f(38,-10,-35.1);
	glVertex3f(38,-9,-35.1);
	glVertex3f(45,-9,-35.1);
	glEnd();
	
	//bantal 2
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(30,-9,-35.1);
	glVertex3f(37,-9,-35.1);
	glVertex3f(37,-9,-39);
	glVertex3f(30,-9,-39);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(37,-10,-35.1);
	glVertex3f(37,-9,-35.1);
	glVertex3f(37,-9,-39);
	glVertex3f(37,-10,-39);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(30,-10,-39);
	glVertex3f(37,-10,-39);
	glVertex3f(37,-9,-39);
	glVertex3f(30,-9,-39);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(30,-9,-35.1);
	glVertex3f(37,-9,-35.1);
	glVertex3f(37,-9,-39);
	glVertex3f(30,-9,-39);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(30,-9,-35.1);
	glVertex3f(30,-10,-35.1);
	glVertex3f(30,-10,-39);
	glVertex3f(30,-9,-39);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(30,-10,-35.1);
	glVertex3f(37,-10,-35.1);
	glVertex3f(37,-9,-35.1);
	glVertex3f(30,-9,-35.1);
	glEnd();
	
	//selimut
	glBegin(GL_QUADS);
	glColor3ub(40, 75, 100);
	glVertex3f(45,-9.9,-45);
	glVertex3f(30,-9.9,-45);
	glVertex3f(30,-9.9,-57);
	glVertex3f(45,-9.9,-57);
	glEnd();
	
	//TV
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex3f(35,2,-34.9);
	glVertex3f(25,2,-34.9);
	glVertex3f(25,-6,-34.9);
	glVertex3f(35,-6,-34.9);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex3f(35,2,-34);
	glVertex3f(25,2,-34);
	glVertex3f(25,-6,-34);
	glVertex3f(35,-6,-34);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex3f(35,-6,-34);
	glVertex3f(25,-6,-34);
	glVertex3f(25,-6,-34.9);
	glVertex3f(35,-6,-34.9);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex3f(35,2,-34);
	glVertex3f(25,2,-34);
	glVertex3f(25,2,-34.9);
	glVertex3f(35,2,-34.9);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex3f(25,2,-34);
	glVertex3f(25,-6,-34);
	glVertex3f(25,-6,-34.9);
	glVertex3f(25,2,-34.9);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex3f(35,2,-34);
	glVertex3f(35,-6,-34);
	glVertex3f(35,-6,-34.9);
	glVertex3f(35,2,-34.9);
	glEnd();
	
	//figura 1
	glBegin(GL_QUADS);
	glColor3ub(188, 108, 37);
	glVertex3f(-44.9,2,-15);
	glVertex3f(-44.9,2,-20);
	glVertex3f(-44.9,10,-20);
	glVertex3f(-44.9,10,-15);
	glEnd();
	
	//kaca figura
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-44.8,2.5,-15.5);
	glVertex3f(-44.8,2.5,-19.5);
	glVertex3f(-44.8,9.5,-19.5);
	glVertex3f(-44.8,9.5,-15.5);
	glEnd();
	
	//figura 2
	glBegin(GL_QUADS);
	glColor3ub(188, 108, 37);
	glVertex3f(44.9,2,-15);
	glVertex3f(44.9,2,-20);
	glVertex3f(44.9,10,-20);
	glVertex3f(44.9,10,-15);
	glEnd();
	
	//kaca figura
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(44.8,2.5,-15.5);
	glVertex3f(44.8,2.5,-19.5);
	glVertex3f(44.8,9.5,-19.5);
	glVertex3f(44.8,9.5,-15.5);
	glEnd();
	
	//salib
	glBegin(GL_QUADS);
	glColor3ub(188, 108, 37);
	glVertex3f(-30,10,-34.9);
	glVertex3f(-30.5,10,-34.9);
	glVertex3f(-30.5,4,-34.9);
	glVertex3f(-30,4,-34.9);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(188, 108, 37);
	glVertex3f(-32,8,-34.9);
	glVertex3f(-28.5,8,-34.9);
	glVertex3f(-28.5,8.5,-34.9);
	glVertex3f(-32,8.5,-34.9);
	glEnd();	
	
	glutSwapBuffers();
}

void keyboard (unsigned char key, int x, int y)
{
	switch (key)
	{
		case 'w':
		case 'W':
			glTranslatef(0,0,3);
			break;
		case 'd':
		case 'D':
			glTranslatef(3,0,0);
			break;	
		case 's':
		case 'S':
			glTranslatef(0,0,-3);
			break;	
		case 'a':
		case 'A':
			glTranslatef(-3,0,0);
			break;	
		case '7':
			glTranslatef(0,3,0);
			break;
		case '9':
			glTranslatef(0,-3,0);
			break;
		case '2':
			glRotatef(2,1,0,0);
			break;
		case '8':
			glRotatef(-2,1,0,0);
			break;
		case '6':
			glRotatef(2,0,1,0);
			break;	
		case '4':
			glRotatef(-2,0,1,0);
			break;
		case '1':
			glRotatef(2,0,0,1);
			break;	
		case '3':
			glRotatef(-2,0,0,1);
			break;
		case '5':
			if(is_depth)
			{
				is_depth = 0;
				glDisable(GL_DEPTH_TEST);
			}
			else
			{
				is_depth = 1;
				glEnable(GL_DEPTH_TEST);
			}
	}
	tampil();
}

void idle()
{
	if (!mouseDown)
	{
		xrot += 0.3;
		yrot += 0.4;
	}
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		mouseDown = true;
		xdiff = x - yrot;
		ydiff = -y + xrot;
	}
	else
	mouseDown = false;
}

void mouseMotion(int x, int y)
{
	if(mouseDown)
	{
		yrot = x - xdiff;
		xrot = y + ydiff;
		
		glutPostRedisplay();
	}
}

void ukuran(int lebar, int tinggi)
{
	if (tinggi ==0) tinggi =1;
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(50,lebar/tinggi, 5, 500);
glTranslatef(0,0,-200);
glMatrixMode(GL_MODELVIEW);
}
