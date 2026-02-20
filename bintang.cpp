#include <math.h>
#include <glut.h>
typedef struct
{
float x, y;
}point2D_t;
typedef struct
{
float r, g, b;
}color;
typedef struct
{
float r, g, b;
}color_t;
void setColor(color col)
{
glColor3f(col.r, col.g, col.b);
}
void setColor(float r, float g, float b)
{
glColor3f(r, g, b);
}
void fillPolygon(point2D_t line[], int n, color col)
{
glBegin(GL_POLYGON);
setColor(col);
for (int i =0; i< n ; i++)
glVertex2f(line[i].x, line[i].y);
glEnd();
}
void gradatePolygon(point2D_t line[], int n, color col[])
{
glBegin(GL_POLYGON);
for (int i=0; i<n;i++)
{
setColor(col[i]);
glVertex2f(line[i].x,line[i].y);
}
glEnd();
}
void drawPolygon(point2D_t pnt[], int n) {
int i;
glBegin(GL_POLYGON);
for (i=0; i<n; i++) 
glVertex2f(pnt[i].x,pnt[i].y);
glEnd();
}
static void createStar(point2D_t p[],float a,point2D_t p1)
{
float teta=36,sudut,r=10;
for(int i=0;i<10;i++)
{
sudut=(float)i*teta/57.3;
if (r==2)r=10;else r=2;
p[i].x=p1.x+r*cos(sudut+a);
p[i].y=p1.y+r*sin(sudut+a);
}
}
void userdraw()
{
point2D_t batas[4] = {{36,20},{988,20},{988,583},{36,583}};
color wlangit[4]={{0.3,0.0,0.3},{0.3,0.0,0.3},{0.9,1,0.5},{0.9,0.8,0.5}};
gradatePolygon(batas,4,wlangit);
static float a=0;
color warna={1,1,0};
point2D_t c10[10],p10={530,121};
createStar(c10,a,p10);
point2D_t c1[10],p1={500,321};
createStar(c1,a,p1);
point2D_t c2[10],p2={433,247};
createStar(c2,a,p2);
point2D_t c3[10],p3={286,125};
createStar(c3,a,p3);
point2D_t c4[10],p4={553,150};
createStar(c4,a,p4);
point2D_t c5[10],p5={232,350};
createStar(c5,a,p5);
point2D_t c6[10],p6={643,123};
createStar(c6,a,p6);
point2D_t c7[10],p7={200,250};
createStar(c7,a,p7);
point2D_t c8[10],p8={433,247};
createStar(c8,a,p8);
point2D_t c9[10],p9={334,350};
createStar(c9,a,p9);
fillPolygon(c1,10,warna);
fillPolygon(c2,10,warna);
fillPolygon(c3,10,warna);
fillPolygon(c4,10,warna);
fillPolygon(c5,10,warna);
fillPolygon(c6,10,warna);
fillPolygon(c7,10,warna); 
fillPolygon(c8,10,warna);
fillPolygon(c9,10,warna);
fillPolygon(c10,10,warna);
a+=0.005; // Mengatur efek bintang berputar
}
void display(void)
{
glClear(GL_COLOR_BUFFER_BIT);
userdraw();
glutSwapBuffers();
}
int main (int argc, char **argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutInitWindowPosition (0,0);
glutInitWindowSize(1020,760);
glutCreateWindow("Fighting");
glClearColor(1,1,1,0);
gluOrtho2D(0,1024,768,0);
glutIdleFunc(display);
glutDisplayFunc(display);
glutMainLoop();
return 0;
}