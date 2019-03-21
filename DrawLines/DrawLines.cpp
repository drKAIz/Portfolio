#include <iostream>
#include <fstream>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <vector>

using namespace std;
int no;      					//number of polylines
vector<double> data;			//main data container
vector<double> iter;			//smaller data container

void init(void)
{
    glClearColor (1.0, 1.0, 1.0, 0.0);
    glMatrixMode (GL_PROJECTION);
    gluOrtho2D (0.0, 200.0, 0.0, 150.0);

}

void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    int pointer = 1;         	//<-- Acts as a sort of pointer that should only
    							//point to the number of points in a set of 
    							//polyline data. I guess it stores the index
    
	while(pointer < data.size())
	{
		iter.clear();
		for (int c = pointer; c < (pointer+(data[pointer]*2)+3+1); c++)
		{
			iter.push_back(data[c]);	   //a part of the main 1-D vector is 
		}                                  //copied into another smaller vector
				
		glColor3f (iter[1], iter[2], iter[3]);
		if (signbit(iter[0]))             //Checks if the number of polylines
		{                                 //to be drawn is negative.
    		glBegin (GL_LINE_LOOP);
    		for (int b = 4; b < iter.size(); b+=2)
    		{
        		glVertex2i (iter[b], iter[b+1]);
    		}
    		glEnd ();
    	}
    	else if (!signbit(iter[0]))
    	{
    		glBegin (GL_LINES);
    		for (int b = 4; b < iter.size(); b+=2)
    		{
        		glVertex2i (iter[b], iter[b+1]);
    		}
    		glEnd ();
    	}
		pointer = pointer+(data[pointer]*2)+3+1;	//pointer is updated to
													//point to the next number
													//polylines
	}
    glFlush ();
}


int main(int argc, char** argv)
{
	ifstream infile;
	infile.open("tester.txt");  //insert filename here.
	if (infile)
	{
		double d;
		while (infile >> d)
		{
			data.push_back(d);
		}	
	}
	infile.close();
	no = data[0];				//Represents the number of sets of polylines
	
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition (530, 290);
    glutInitWindowSize (500, 400);
    glutCreateWindow ("Draw Lines");
    init ();
    glutDisplayFunc (display);
    glutMainLoop ( );
    return 0;

}
