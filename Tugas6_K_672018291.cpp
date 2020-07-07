#include <GL/glut.h>
#include <stdlib.h>

void mouse(int button, int state, int x, int y);
void mouseMotion(int x, int y);
void ukuran(int, int);
float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;

void init(void)
{
    glClearColor (0,0.6,0.9,1);
    glOrtho(-15,15,-7,7,-35,35);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_DEPTH_TEST);
    glLoadIdentity ();
    gluPerspective(90.0,2.2, 1.0, 25.0);
    glMatrixMode (GL_MODELVIEW);
}
static float ypoz = 0,
             zpoz = 0,
             xpoz = 0, a = 0, b = 0,c = -10; //deklarasi posisi awal x,y,z

void rumah(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4,int
z1,float z2,float z3){
//membuat rumah dengan perumpamaan titik koordinat
//depan
glColor3f(0.5,1,1);
glVertex3d(x1,y1,z2);
glVertex3d(x2,y2,z2);
glVertex3d(x3,y3,z2);
glVertex3d(x4,y4,z2);
//kanan
glColor3f(0.5,1,1);
glVertex3d(x2,y2,z2);
glVertex3d(x2,y2,z1);
glVertex3d(x3,y3,z1);
glVertex3d(x3,y3,z2);
//belakang
glColor3f(0.5,1,1);
glVertex3d(x1,y1,z1);
glVertex3d(x2,y2,z1);
glVertex3d(x3,y3,z1);
glVertex3d(x4,y4,z1);
//kiri
glColor3f(0.5,1,1);
glVertex3d(x1,y1,z2);
glVertex3d(x1,y1,z1);
glVertex3d(x4,y4,z1);
glVertex3d(x4,y4,z2);
//bawah
glColor3f(0.5,1,1);
glVertex3d(x1,y1,z2);
glVertex3d(x2,y2,z2);
glVertex3d(x2,y2,z1);
glVertex3d(x1,y1,z1);
//atas
glColor3f(0.5,1,1);
glVertex3d(x3,y3,z2);
glVertex3d(x4,y4,z2);
glVertex3d(x4,y4,z1);
glVertex3d(x3,y3,z1);
}
void rumah1(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int
y4,float z1,float z2,float z3){ //atap
    glColor3f(1,0.5,0);//sisi kanan
    glVertex3d(x3,y3,z1);
    glVertex3d(x3,y3,z2);
    glVertex3d(x3,y1,z3);
    glColor3f(1,0.5,0);//sisi kiri
    glVertex3d(x4,y4,z2);
    glVertex3d(x4,y4,z1);
    glVertex3d(x4,y1,z3);
}
void rumah2(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int
y4,float z1,float z2,float z3){//atap
glColor3f(1,0.5,0);//belakang
glVertex3d(x4,y4,z1);
glVertex3d(x3,y3,z1);
glVertex3d(x3,y1,z3);
glVertex3d(x4,y1,z3);
glColor3f(1,0.5,0);//depan
glVertex3d(x3,y3,z2);
glVertex3d(x4,y4,z2);
glVertex3d(x4,y1,z3);
glVertex3d(x3,y1,z3);
}
void rumahhh(void)
{
    if (is_depth)
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
        //glClear(GL_COLOR_BUFFER_BIT);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glLoadIdentity ();
    gluLookAt(0.0f,0.0f,3.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f);//perpindahan
    glRotatef(xrot, 1.0f,0.0f,0.0f);
    glRotatef(yrot, 0.0f,1.0f,0.0f);
    glPushMatrix();
    glTranslatef(a,b,c);
    glRotatef(xpoz,1,0,0);
    glRotatef(ypoz,0,1,0);
    glRotatef(zpoz,0,0,1);
    glBegin(GL_QUADS);
    rumah(-9,-2,9,-2,9,2,-9,2,-5,3,0);//titik yang digunakan untuk membuat rumah
    rumah(3,-2,9,-2,9,2.1,3,2.1,-4,4.5,0);//ruang depan
    rumah(-7,-1,7,-1,7,1,-7,1,-4,2,0);
    rumah2(-4,5,0,0,9,2,-9,2,-5.5,4.5,0); //titik yang digunakan dalam membuat atap
    rumah(-8,-1,6,-1,6,1,-8,1,-4,3,0);
    glColor3f(1,1,1);//plafon depan
    glVertex3d(3,1.7,-2);
    glVertex3d(-9,1.7,-2);
    glVertex3d(-9,1.7,4.7);
    glVertex3d(3,1.7,4.7);//
    glVertex3d(3,1.7,4.7);
    glVertex3d(-9,1.7,4.7);
    glVertex3d(-9,2,4.7);
    glVertex3d(3,2,4.7);
    glColor3f(1,1,1);//plafon belakang
    glVertex3d(9,1.7,-5.5);
    glVertex3d(-9,1.7,-5.5);
    glVertex3d(-9,1.7,4.5);
    glVertex3d(9,1.7,4.5);
    glVertex3d(9,1.7,-5.5);
    glVertex3d(-9,1.7,-5.5);
    glVertex3d(-9,1.8,-5.5);
    glVertex3d(9,1.8,-5.5);
    glVertex3d(6,-1,4.53);//jendela ruangdepan1
    glVertex3d(7.2,-1,4.53);
    glVertex3d(7.2,1,4.53);
    glVertex3d(6,1,4.53);
    glVertex3d(4.7,-1,4.53);//jendela ruangdepan2
    glVertex3d(5.9,-1,4.53);
    glVertex3d(5.9,1,4.53);
    glVertex3d(4.7,1,4.53);
    glColor3f(1,1,1);//pintu depan
    glVertex3d(-2,-2,3.03);
    glVertex3d(1,-2,3.03);
    glVertex3d(1,1.3,3.03);
    glVertex3d(-2,1.3,3.03);
    glColor3f(1,1,1);//kayu sekat
    glVertex3d(-3.6,-1,3.01);
    glVertex3d(-3.7,-1,3.01);
    glVertex3d(-3.7,1.3,3.01);
    glVertex3d(-3.6,1.3,3.01);
    glColor3f(0,0,0);//jendela rumah1 depan
    glVertex3d(-4,-1,3.01);
    glVertex3d(-2.3,-1,3.01);
    glVertex3d(-2.3,1.3,3.01);
    glVertex3d(-4,1.3,3.01);
    glVertex3d(-5,-1,3.01);//jendela rumah2 depan
    glVertex3d(-3.3,-1,3.01);
    glVertex3d(-3.3,1.3,3.01);
    glVertex3d(-5,1.3,3.01);
    glColor3f(1,1,1);//kayu sekat
    glVertex3d(-2.1,-1,3.01);
    glVertex3d(-2.3,-1,3.01);
    glVertex3d(-2.3,1.3,3.01);
    glVertex3d(-2.1,1.3,3.01);
    glVertex3d(-5,-1,3.01);//kayu sekat
    glVertex3d(-5.2,-1,3.01);
    glVertex3d(-5.2,1.3,3.01);
    glVertex3d(-5,1.3,3.01);
    glVertex3d(-6,-1,3.01);//kayu sekat
    glVertex3d(-6.3,-1,3.01);
    glVertex3d(-6.3,1.3,3.01);
    glVertex3d(-6,1.3,3.01);
    glVertex3d(-7.5,-1,3.01);//kayu sekat
    glVertex3d(-7.2,-1,3.01);
    glVertex3d(-7.2,1.3,3.01);
    glVertex3d(-7.5,1.3,3.01);
    glColor3d(0,0,0);//jendela rumah3 depan
    glVertex3d(-7.5,-1,3.01);
    glVertex3d(-6,-1,3.01);
    glVertex3d(-6,1.3,3.01);
    glVertex3d(-7.5,1.3,3.01);
    //lemari
    //glBegin(GL_QUADS);
    //glColor3f(0.5,0.9,1);
    //glVertex3d(2,-2,2.01);
    //glVertex3d(3,-2,2.01);
    //glVertex3d(3,7,2.01);
    //glVertex3d(2,7,2.01);
    glEnd();
    glBegin(GL_TRIANGLES);
    rumah1(-3,5,0,0,8,2,-8,2,-5.5,4.5,0);
    glEnd();
    glutSwapBuffers();
}
void idle()
{
    if (!mouseDown)
    {
        xrot += 0.3f;
        yrot += 0.4f;
    }
glutPostRedisplay();
}
void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
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
    if (mouseDown)
    {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}

void keyboard(unsigned char key, int x, int y)
{
 switch (key) {
    case 'x':
    case 'X':
    xpoz=xpoz+5;
    if (xpoz>360) xpoz=0;
    glutPostRedisplay();
break;
    case 'y':
    case 'Y':
    ypoz=ypoz+5;
    if (ypoz>360) ypoz=0;
    glutPostRedisplay();
break;
    case 'z':
    case 'Z':
    zpoz = zpoz+1;
    if (zpoz>360) zpoz=0;
    glutPostRedisplay();
break;
    case 'w':
    case 'W':
    b = b + 1;
    glutPostRedisplay();
break;
    case 's':
    case 'S':
    b = b - 1;
    glutPostRedisplay();
break;
    case 'a':
    case 'A':
    a = a + 1;
    glutPostRedisplay();
break;
    case 'd':
    case 'D':
    a = a - 1;
    glutPostRedisplay();
break;
    case '1':
    c = c + 1;
    glutPostRedisplay();
break;
    case '2':
    c = c - 1;
    glutPostRedisplay();
break;
    case '5':
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 2;
            glEnable(GL_DEPTH_TEST);
        }
 }
}
//void ukuran(int lebar, int tinggi)
//{
//    if(tinggi == 0) tinggi = 1;

//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluPerspective(50.0,lebar/tinggi,5.0,500.0);
//    glTranslatef(0.0, -5.0, -150.0);
//    glMatrixMode(GL_MODELVIEW);
//}
int main(int argc, char** argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode (GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
 glutInitWindowSize (700, 550);
 glutInitWindowPosition (100, 100);
 glutCreateWindow("AURILIA DINDA PERMATASARI-672018291");
 init ();
 glutDisplayFunc(rumahhh);
// glutReshapeFunc(ukuran);
 glutKeyboardFunc(keyboard);
 glutMouseFunc(mouse);
 glutMotionFunc(mouseMotion);
 glutIdleFunc(rumahhh);
 glutMainLoop();
 return 0;
}
