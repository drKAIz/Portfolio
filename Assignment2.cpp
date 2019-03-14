//Author: Kassim Izuagbe;
//Purpose: Generates a collection of diamonds at random locations;

#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>

class GLintPoint
{
	public:
		GLint x, y;
};

void init(void)
{
    glClearColor (1.0, 1.0, 1.0, 0.0);
    glMatrixMode (GL_PROJECTION);
    gluOrtho2D (-50.0, 300.0, -50.0, 300.0);

}

void drawDiamond(GLintPoint center, GLint length)
{
	
	glBegin (GL_LINE_LOOP);
		glVertex2i((center.x)-(length/2), center.y);
		glVertex2i(center.x, (center.y)-(length/2));
		glVertex2i((center.x)+(length/2), center.y);
		glVertex2i(center.x, (center.y)+(length/2));
	glEnd();
}

void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 0.0, 0.0);
    GLintPoint middle = {rand()%250, rand()%250};
    GLint size = 89;
    drawDiamond(middle, size);
    for (int x = 0; x < size*2; x++)
    {
    	GLintPoint middle = {rand()%250, rand()%250};
    	size = (rand()%89)+1;
    	drawDiamond(middle, size);
    }
    glFlush ();
}

int main(int argc, char** argv)
{
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition (530, 290);
    glutInitWindowSize (400, 400);
    glutCreateWindow ("Equilateral Diamonds");
    init ();
    glutDisplayFunc (display);
    glutMainLoop ( );
    return 0;

}
