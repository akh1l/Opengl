//Opengl project - basket ball game
//authors: Akhil and Amit, TJIT, Bangalore

#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#include<time.h>

int firsttime = 0;
float x = 0 , y = 0, z = 0.0;
GLfloat oldy = 0, oldz = 0, tempz, dy = 0, dz = 0;
int triggered = 0;
GLfloat courtVertices[][3] = {
	//basket ball court vertices
	{-2.5, -1.0, -4.7}, {2.5, -1.0, -4.7},
	{2.5, -1.0, 4.7}, {-2.5, -1.0, 4.7}
};

GLfloat firstPoleVertices[][3] = {
	//basket pole vertuces
	//base
	{-0.1, -1.0, -5.2}, {0.1, -1.0, -5.2},
	{-0.1, -1.0, -5.0}, {0.1, -1.0, -5.0},
	//middle
	{-0.1, 0.5, -5.2}, {0.1, 0.5, -5.2},
	{-0.1, 0.4, -5.0}, {0.1, 0.4, -5.0},
	//top
	{-0.1, 1.3, -4.3 }, { 0.1, 1.3 , -4.3},
	{-0.1, 1.7, -4.3 }, { 0.1, 1.7, -4.3 }
};

GLfloat secondPoleVertices[][3] = {
	//basket pole vertuces
	//base
	{-0.1, -1.0, 5.2}, {0.1, -1.0, 5.2},
	{-0.1, -1.0, 5.0}, {0.1, -1.0, 5.0},
	//middle
	{-0.1, 0.5, 5.2}, {0.1, 0.5, 5.2},
	{-0.1, 0.4, 5.0}, {0.1, 0.4, 5.0},
	//top
	{-0.1, 1.3, 4.3 }, { 0.1, 1.3 , 4.3 },
	{-0.1, 1.7, 4.3 }, { 0.1, 1.7, 4.3 }
};

void poles(int a, int b, int c, int d)
{
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3fv(firstPoleVertices[a]);
	glVertex3fv(firstPoleVertices[b]);
	glVertex3fv(firstPoleVertices[c]);
	glVertex3fv(firstPoleVertices[d]);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3fv(secondPoleVertices[a]);
	glVertex3fv(secondPoleVertices[b]);
	glVertex3fv(secondPoleVertices[c]);
	glVertex3fv(secondPoleVertices[d]);
	glEnd();
}
void lines(float a, float b, float c, float d)
{
	//a = -2.5, b = -0.05 c = 0.05 d = 2.5
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(a , -0.9999 , b);
	glVertex3f(d , -0.9999 , b);
	glVertex3f(d , -0.9999 , c);
	glVertex3f(a , -0.9999 , c);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(a , -0.9999 , b);
	glVertex3f(d , -0.9999 , b);
	glVertex3f(d , -0.9999 , c);
	glVertex3f(a , -0.9999 , c);
	glEnd();	
}

void verticalLines(float a, float b, float c, float d)
{
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(a, b, -4.29);
	glVertex3f(d, b, -4.29);
	glVertex3f(d, c, -4.29);
	glVertex3f(a, c, -4.29);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(a, b, 4.29);
	glVertex3f(d, b, 4.29);
	glVertex3f(d, c, 4.29);
	glVertex3f(a, c, 4.29);
	glEnd();	
}

void polygon(int a, int b, int c, int d)
{
	//outer color
	//top face
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.1, 0.0);
	glVertex3f(-3.0, -1.1, -5.2);
	glVertex3f(3.0, -1.1, -5.2);
	glVertex3f(3.0, -1.1, 5.2);
	glVertex3f(-3.0, -1.1, 5.2);
	glEnd();
	//bottom face
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.1, 0.0);
	glVertex3f(-3.0, -1.5, -5.2);
	glVertex3f(3.0, -1.5, -5.2);
	glVertex3f(3.0, -1.5, 5.2);
	glVertex3f(-3.0, -1.5, 5.2);
	glEnd();
	//sides
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.1, 0.0);
	glVertex3f(-3.0, -1.1, -5.2);
	glVertex3f(-3.0, -1.5, -5.2);
	glVertex3f(-3.0, -1.5, 5.2);
	glVertex3f(-3.0, -1.1, 5.2);
	glEnd();
	//the other side
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.1, 0.0);
	glVertex3f(3.0, -1.1, -5.2);
	glVertex3f(3.0, -1.5, -5.2);
	glVertex3f(3.0, -1.5, 5.2);
	glVertex3f(3.0, -1.1, 5.2);
	glEnd();
	//pole sides
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.1, 0.0);
	glVertex3f(-3.0, -1.1, 5.2);
	glVertex3f(3.0, -1.1, 5.2);
	glVertex3f(3.0, -1.5, 5.2);
	glVertex3f(-3.0, -1.5, 5.2);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.1, 0.0);
	glVertex3f(-3.0, -1.1, -5.2);
	glVertex3f(3.0, -1.1, -5.2);
	glVertex3f(3.0, -1.5, -5.2);
	glVertex3f(-3.0, -1.5, -5.2);
	glEnd();

	//court color
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.4, 1.0);
	glVertex3fv(courtVertices[a]);
	glColor3f(0.0, 0.4, 1.0);
	glVertex3fv(courtVertices[b]);
	glColor3f(0.0, 0.4, 1.0);
	glVertex3fv(courtVertices[c]);
	glColor3f(0.0, 0.4, 1.0);
	glVertex3fv(courtVertices[d]);	
	glEnd();
	//first pole polygon
	poles(0, 1, 3, 2);
	poles(4, 5, 7, 6);
	poles(2, 3, 7, 6);
	poles(4, 5, 1, 0);
	poles(3, 1, 5, 7);
	poles(0, 2, 6, 4);

	//poles from center to board
	poles(6, 7, 9, 8);
	poles(4, 5, 11, 10);
	poles(6, 4, 10 , 8);
	poles(7, 5, 11, 9);

	//board
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-0.5, 1.0, -4.3);
	glVertex3f( 0.5, 1.0, -4.3);
	glVertex3f( 0.5, 2.0, -4.3);
	glVertex3f(-0.5, 2.0, -4.3);
	glEnd();

	//center line
	lines(-2.5, -0.05, 0.05, 2.5);

	//side lines
	lines(-2.50, 4.7, -4.7, -2.55);
	lines(2.50, 4.7, -4.7, 2.55);

	//base lines
	lines(-2.55, 4.70, 4.75, 2.55);
	lines(-2.55, -4.70, -4.75, 2.55);


	//three pointer lines
	lines(-2.2, 4.7, 4.05, -2.27);
	lines( 2.2, 4.7, 4.05, 2.27);

	lines(-2.2, -4.7, -4.05, -2.27);
	lines( 2.2, -4.7, -4.05, 2.27);

	//two pointer lines
	lines(-0.6, 4.7, 2.8, -0.64);
	lines(0.6, 4.7, 2.8, 0.64);

	lines(-0.6, -4.7, -2.8, -0.64);
	lines(0.6, -4.7, -2.8, 0.64);

	//lines joining the above two lines
	lines(-0.6, 2.8, 2.84, 0.6);
	lines(-0.6, -2.8, -2.84, 0.6);

	//vertical lines on the board
	verticalLines(-0.15, 1.2, 1.24, 0.15); //bottom
	verticalLines(-0.15, 1.5, 1.54, 0.15); //down

	verticalLines(-0.15, 1.2, 1.5, -0.10);
	verticalLines(0.15, 1.2, 1.5, 0.10);
	//second board
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-0.5, 1.0, 4.3);
	glVertex3f( 0.5, 1.0, 4.3);
	glVertex3f( 0.5, 2.0, 4.3);
	glVertex3f(-0.5, 2.0, 4.3);
	glEnd();
}

void circle(float r)
{
	int i;
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POINTS);
	for(i = 0; i< 1000; i++)
	{
		//x and y defines the radius
		glVertex3f( (r * cos(2*3.14159 * i/1000.0)), -0.99, (r * sin(2*3.14159 * i/1000.0)));
	}
	glEnd();
}

void Dcircle(float r)
{
	int i;
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POINTS);
	for(i = 0; i< 1000; i++)
	{
		//x and y defines the radius
		glVertex3f( (r * cos(1*3.14159 * i/1000.0)), -0.99, 2.8 - (r * sin(1*3.14159 * i/1000.0)));
		glVertex3f( (r * cos(1*3.14159 * i/1000.0)), -0.99, -2.8 + (r * sin(1*3.14159 * i/1000.0)));

	}

	for(i = 0; i < 20; i++)
	{
		//x and y defines the radius
		glVertex3f( (r * cos(1*3.14159 * i/20.0)), -0.99, 2.8 + (r * sin(1*3.14159 * i/20.0)));
		glVertex3f( (r * cos(1*3.14159 * i/20.0)), -0.99, -2.8 - (r * sin(1*3.14159 * i/20.0)));
	}
	glEnd();
}

void ring(float r)
{
	int i;
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	for(i = 0; i< 1000; i++)
	{
		//x and y defines the radius
		glVertex3f((r * cos(2*3.14159 * i/1000.0)), 1.2, 4.3 - 0.19 + (r * sin(2*3.14159 * i/1000.0)));
		glVertex3f((r * cos(2*3.14159 * i/1000.0)), 1.2, -4.3 + 0.19 + (r * sin(2*3.14159 * i/1000.0)));

	}
	glEnd();
}


void semicircle(float r)
{
	int i;
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POINTS);
	for(i = 0; i < 1000; i++)
	{
		glVertex3f((r * cos(1*3.14159 * i/1000.0)), -0.99, 4.05 - (r * sin(1*3.14159 * i/1000.0)));
		glVertex3f((r * cos(1*3.14159 * i/1000.0)), -0.99, -4.05 + (r * sin(1*3.14159 * i/1000.0)));

	}
	glEnd();
}

void ball()
{	
	if(firsttime)
	{
		glTranslatef(0.0, 1.2, -1.5); //calculated using the last vertex of parabola
	}
	else
	{
		glTranslatef(0.0, 0.8, -2.8); //calculated using the last vertex of parabola
	}
	glColor3f(0.81176, 0.3254, 0.0);
	glutSolidSphere(0.15, 1000, 20);
}
void headfunction()
{
	glPushMatrix();
	glColor3f(202.0 / 255.0, 160.0/255.0, 100.0/225.0);
	glTranslatef(0.0, 0.8, +0.05);
	glutSolidSphere(0.30, 1000, 20);
	glPopMatrix();
}

void net(int poleChooser)
{
	float r = 0.15;
	int i;
	float poleDecider = 0;
	GLfloat topVertices[10][200];
	GLfloat middleVertices[10][200];
	GLfloat bottomVertices[10][200];

	//choosing the pole
	if(poleChooser == 1)
	{
		poleDecider = 4.3 - 0.19;
	}
	else
	{
		poleDecider = -4.3 + 0.19;
	}

	//top vertices
	glColor3f(235.0/255.0, 63.0/255.0, 23.0/255.0);
	for(i = 0; i < 20; i++)
	{
		topVertices[0][i] = ((r) * cos(2 * 3.14159 * i/20.0)); //x values
		topVertices[1][i] = (poleDecider + (r) * sin(2 * 3.14159 * i/20.0)); //y values
		glBegin(GL_POINTS);
		glVertex3f(topVertices[0][i], 1.2, topVertices[1][i]);
		glEnd();
	}

	//middle vertices
	for(i = 0; i < 20; i++)
	{
		middleVertices[0][i] = ((r - 0.05)* cos(2 * 3.14159 * i/20.0)); //x values
		middleVertices[1][i] = ( poleDecider + (r - 0.05)* sin(2 * 3.14159 * i/20.0)); //y values
		glBegin(GL_POINTS);
		glVertex3f(middleVertices[0][i], 1.0, middleVertices[1][i]);
		glEnd();
	}

	//bottom vertices
	for(i = 0; i < 20; i++)
	{
		bottomVertices[0][i] = ((r - 0.05)* cos(2 * 3.14159 * i/20.0)); //x values
		bottomVertices[1][i] = ( poleDecider + (r - 0.05)* sin(2 * 3.14159 * i/20.0)); //y values
		glBegin(GL_POINTS);
		glVertex3f(bottomVertices[0][i], 0.8, bottomVertices[1][i]);
		glEnd();
	}


	//drawing lines using vertices to get the rhombus pattern
	for(i = 0; i < 20; i++)
	{
		//from top vertices to the middle vertices
		glBegin(GL_LINES);
		if(i == 19)
		{
			glVertex3f(topVertices[0][i], 1.2, topVertices[1][i]);
			glVertex3f(middleVertices[0][0], 1.0, middleVertices[1][0]);
		}
		else
		{
			glVertex3f(topVertices[0][i], 1.2, topVertices[1][i]);
			glVertex3f(middleVertices[0][i + 1], 1.0, middleVertices[1][i + 1]);
		}
		glEnd();

		glBegin(GL_LINES);
		if(i == 0)
		{
			glVertex3f(topVertices[0][i], 1.2, topVertices[1][i]);
			glVertex3f(middleVertices[0][19], 1.0, middleVertices[1][19]);
		}
		else
		{
			glVertex3f(topVertices[0][i], 1.2, topVertices[1][i]);
			glVertex3f(middleVertices[0][i - 1], 1.0, middleVertices[1][i - 1]);
		}
		glEnd();


		//from middle vertices to bottom vertices
		glBegin(GL_LINES);
		if(i == 19)
		{
			glVertex3f(middleVertices[0][i], 1.0, middleVertices[1][i]);
			glVertex3f(bottomVertices[0][0], 0.8, bottomVertices[1][0]);
		}
		else
		{
			glVertex3f(middleVertices[0][i], 1.0, middleVertices[1][i]);
			glVertex3f(bottomVertices[0][i + 1], 0.8, bottomVertices[1][i + 1]);
		}
		glEnd();

		glBegin(GL_LINES);
		if(i == 0)
		{
			glVertex3f(middleVertices[0][i], 1.0, middleVertices[1][i]);
			glVertex3f(bottomVertices[0][19], 0.8, bottomVertices[1][19]);
		}
		else
		{
			glVertex3f(middleVertices[0][i], 1.0, middleVertices[1][i]);
			glVertex3f(bottomVertices[0][i - 1], 0.8, bottomVertices[1][i - 1]);
		}
		glEnd();

	}
}

void parabola()
{ 
	float z, tempz, y ,a = 1 , b = 1 , dy = 0, dz = 0;
	glBegin(GL_POINTS);
	glColor3f(0.0, 0.0, 0.0);
	for(z = -1.0; z < 1.0; z+=0.01)
	{
		y = - (2 * z * z) + 3.2; // c is height
		tempz = z - 3.1;
		glVertex3f(0, y, tempz);
		dy = y - oldy;
		dz = z - oldz;
		oldy = y;
		oldz = z;
	}
	glEnd();
}

//shoes
float rightLeg[][3] = {
	{0.03, -0.99, -0.1}, {0.03, -0.99, 0.1}, {0.2, -0.99, 0.1}, {0.2, -0.99, -0.1},
	{0.03, -0.6, -0.1}, {0.03, -0.6, 0.1}, {0.2, -0.6, 0.1}, {0.2, -0.6, -0.1}
};
float leftLeg[][3] = {
	{-0.2, -0.99, -0.1}, {-0.2, -0.99, 0.1}, {-0.03, -0.99, 0.1}, {-0.03, -0.99, -0.1},
	{-0.2, -0.6, -0.1}, {-0.2, -0.6, 0.1}, {-0.03, -0.6, 0.1}, {-0.03, -0.6, -0.1}
};

float trunk[][3] = {
	{-0.2, -0.6, -0.1}, {-0.2, -0.6, 0.1}, {0.2, -0.6, 0.1}, {0.2, -0.6, -0.1},
	{-0.2, -0.4, -0.1}, {-0.2, -0.4, 0.1}, {0.2, -0.4, 0.1}, {0.2, -0.4, -0.1}
};
float body[][3] = {
	{-0.2, -0.4, -0.1}, {-0.2, -0.4, 0.1}, {0.2, -0.4, 0.1}, {0.2, -0.4, -0.1},
	{-0.2, 0.3, -0.1}, {-0.2, 0.3, 0.1}, {0.2, 0.3, 0.1}, {0.2, 0.3, -0.1}
};

float head[][3] = {
	{-0.4, 0.35, -0.2}, {-0.4, 0.35, 0.2}, {0.4, 0.35, 0.2}, {0.4, 0.35, -0.2},
	{-0.4, 1.1, -0.2}, {-0.4, 1.1, 0.2}, {0.4, 1.1, 0.2}, {0.4, 1.1, -0.2}
};

float leftHand[][3] = {
	{-0.2, 0.2, -0.1}, {-0.2, 0.2, 0.1}, {-0.4, 0.2, 0.1}, {-0.4, 0.2, -0.1},
	{-0.2, -0.6, -0.1}, {-0.2, -0.6, 0.1}, {-0.4, -0.6, 0.1}, {-0.4, -0.6, -0.1}
};

float rightHand[][3] = {
	{0.2, 0.2, -0.1}, {0.2, 0.2, 0.1}, {0.4, 0.2, 0.1}, {0.4, 0.2, -0.1},
	{0.2, -0.6, -0.1}, {0.2, -0.6, 0.1}, {0.4, -0.6, 0.1}, {0.4, -0.6, -0.1}
};
void characterDesign(int a, int b, int c, int d)
{
	float R = 143.0/255.0, G = 125.0 / 255.0, B = 100.0 / 225.0;
	//float R = 0.0, G = 0.0, B = 0.0;
	
	glColor3f(202.0 / 255.0, 160.0/255.0, 100.0/225.0);
	glBegin(GL_POLYGON);
	glVertex3fv(trunk[a]);
	glVertex3fv(trunk[b]);
	glVertex3fv(trunk[c]);
	glVertex3fv(trunk[d]);    
	glEnd();


	glColor3f(202.0 / 255.0, 160.0/255.0, 100.0/225.0);
	glBegin(GL_POLYGON);
	glVertex3fv(body[a]);
	glVertex3fv(body[b]);
	glVertex3fv(body[c]);
	glVertex3fv(body[d]);    
	glEnd();
	//head. rotated by 3
	glPushMatrix();
	glRotatef(3.0, 1.0, 0.0, 0.0);
	glColor3f(202.0 / 255.0, 160.0/255.0, 100.0/225.0);
	glBegin(GL_POLYGON);
	glVertex3fv(head[a]);
	glVertex3fv(head[b]);
	glVertex3fv(head[c]);
	glVertex3fv(head[d]);    
	glEnd();

	glColor3f(R, G, B);
	glBegin(GL_LINE_LOOP);
	glVertex3fv(head[a]);
	glVertex3fv(head[b]);
	glVertex3fv(head[c]);
	glVertex3fv(head[d]);    
	glEnd();
	//headfunction();
	//eyes
	int i;
	float r = 0.05;
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	for(i = 0; i< 1000; i++)
	{
		//x and y defines the radius
		glVertex3f( 0.15 - (r * cos(2*3.14159 * i/1000.0)), 0.8 + (r * sin(2*3.14159 * i/1000.0)), -0.2);
		glVertex3f( -0.15 - (r * cos(2*3.14159 * i/1000.0)), 0.8 + (r * sin(2*3.14159 * i/1000.0)), -0.2);
	}
	//another ring to make the eyes look darker
	for(i = 0; i< 1000; i++)
	{
		//x and y defines the radius
		glVertex3f( 0.15 - ((r - 0.005) * cos(2*3.14159 * i/1000.0)), 0.8 + ((r - 0.005) * sin(2*3.14159 * i/1000.0)), -0.2);
		glVertex3f( -0.15 - ((r - 0.005) * cos(2*3.14159 * i/1000.0)), 0.8 + ((r - 0.005) * sin(2*3.14159 * i/1000.0)), -0.2);
	}
	glEnd();	

	//mouth
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(0.0 , 0.55 , -0.21);
	glVertex3f(0.05 , 0.6, -0.21);
	glVertex3f(-0.05 , 0.6 , -0.21);
	glEnd();
	glPopMatrix();

	glColor3f(202.0 / 255.0, 160.0/255.0, 100.0/225.0);
	glBegin(GL_POLYGON);
	glVertex3fv(rightLeg[a]);
	glVertex3fv(rightLeg[b]);
	glVertex3fv(rightLeg[c]);
	glVertex3fv(rightLeg[d]);    
	glEnd();

	glColor3f(202.0 / 255.0, 160.0/255.0, 100.0/225.0);
	glBegin(GL_POLYGON);
	glVertex3fv(leftLeg[a]);
	glVertex3fv(leftLeg[b]);
	glVertex3fv(leftLeg[c]);
	glVertex3fv(leftLeg[d]);    
	glEnd();

	glPushMatrix();
	glRotatef(135.0, 1.0, 0.0, 0.0);
	glColor3f(202.0 / 255.0, 160.0/255.0, 100.0/225.0);
	glBegin(GL_POLYGON);
	glVertex3fv(leftHand[a]);
	glVertex3fv(leftHand[b]);
	glVertex3fv(leftHand[c]);
	glVertex3fv(leftHand[d]);    
	glEnd();

	glColor3f(R, G, B);
	glBegin(GL_LINE_LOOP);
	glVertex3fv(leftHand[a]);
	glVertex3fv(leftHand[b]);
	glVertex3fv(leftHand[c]);
	glVertex3fv(leftHand[d]);    
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(135.0, 1.0, 0.0, 0.0);
	glColor3f(202.0 / 255.0, 160.0/255.0, 100.0/225.0);
	glBegin(GL_POLYGON);
	glVertex3fv(rightHand[a]);
	glVertex3fv(rightHand[b]);
	glVertex3fv(rightHand[c]);
	glVertex3fv(rightHand[d]);    
	glEnd();

	glColor3f(R, G, B);
	glBegin(GL_LINE_LOOP);
	glVertex3fv(rightHand[a]);
	glVertex3fv(rightHand[b]);
	glVertex3fv(rightHand[c]);
	glVertex3fv(rightHand[d]);    
	glEnd();
	glPopMatrix();


	//borders

	glColor3f(R, G, B);
	glBegin(GL_LINE_LOOP);
	glVertex3fv(trunk[a]);
	glVertex3fv(trunk[b]);
	glVertex3fv(trunk[c]);
	glVertex3fv(trunk[d]);    
	glEnd();

	glColor3f(R, G, B);
	glBegin(GL_LINE_LOOP);
	glVertex3fv(rightLeg[a]);
	glVertex3fv(rightLeg[b]);
	glVertex3fv(rightLeg[c]);
	glVertex3fv(rightLeg[d]);    
	glEnd();

	glColor3f(R, G, B);
	glBegin(GL_LINE_LOOP);
	glVertex3fv(leftLeg[a]);
	glVertex3fv(leftLeg[b]);
	glVertex3fv(leftLeg[c]);
	glVertex3fv(leftLeg[d]);    
	glEnd();

	glColor3f(R, G, B);
	glBegin(GL_LINE_LOOP);
	glVertex3fv(body[a]);
	glVertex3fv(body[b]);
	glVertex3fv(body[c]);
	glVertex3fv(body[d]);    
	glEnd();

	
}
void character()
{
	glScalef(0.7, 0.7, 0.7);
	glTranslatef(0.0, -0.4, -1.5);
	characterDesign(0, 1, 2, 3); 
	characterDesign(4, 5, 6, 7); 
	characterDesign(0, 1, 5, 4); 
	characterDesign(2, 3, 7, 6); 
	characterDesign(1, 2, 6, 5); 
	characterDesign(0, 3, 7, 4); 
}

void draw(void)
{
	glPushMatrix();
	if(firsttime == 0)
	{
		glTranslatef(0, y, dz);
	}
	ball();
	glPopMatrix();

	polygon(0, 1, 2, 3);
	//center circle
	circle(0.60);
	circle(0.61);
	circle(0.62);
	circle(0.63);
	circle(0.64);
	circle(0.65);

	//parabola();

	Dcircle(0.6);

	net(1);
	net(2);

	ring(0.15);
	ring(0.16);
	ring(0.17);
	ring(0.18);
	////three pointer semi cirlce
	semicircle(2.22);
	semicircle(2.23);
	semicircle(2.24);
	semicircle(2.25);
	semicircle(2.26);
	semicircle(2.27);

	//character
	character();
}

static GLfloat theta[] = {0.0, 0.0, 0.0};
static GLint axis = 2;
static GLdouble viewer[] =  {0.0, 7.0, 7.0};

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(viewer[0], viewer[1], viewer[2], 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glRotatef(theta[0], 1.0, 0.0, 0.0);
	glRotatef(theta[1], 0.0, 1.0, 0.0);
	glRotatef(theta[2], 0.0, 0.0, 1.0);
	draw();
	glFlush();
	glutSwapBuffers();
} 
void update(int value)
{
	if(firsttime)
	{
		y = 0.5;
		dz = 1.2;  
		firsttime = 0;      
	}
	if(triggered && y >= -2 && z >= -1.0)
	{
		y = -(2 * dz * dz) + 3.6;
		dz -= 0.05;
	}
	else
	{
		y = -0.7;
		dz = 1.4;
		triggered = 0;
	}
	glutPostRedisplay();
	glutTimerFunc(25,update,0);
}

void mouse(int btn, int state, int x, int y)
{
	if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		axis = 1;
	if(btn == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
		axis = 0;
	if(btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		axis = 2;
	theta[axis] += 2.0;
	if(theta[axis] > 360.0) 
		theta[axis] -= 360.0;
	display();
}

void myReshape(int w, int h)
{
	glViewport(0, 0, w , h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w <= h)
		glFrustum(-2.0, 2.0, -2.0 * (GLfloat)h / (GLfloat)w , 2.0 * (GLfloat)h / (GLfloat)w, 2.0, 20.0);
	else
		glFrustum(-2.0, 2.0, -2.0 * (GLfloat)w / (GLfloat)h , 2.0 * (GLfloat)w / (GLfloat)h,  2.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
}

void keys(unsigned char key, int x, int y)
{
	//test conditions to ensure that the camera always capture the obejct and does move too far from the object
	if(key == 'x' && viewer[0] != -6) viewer[0] -= 1.0;
	if(key == 'X' && viewer[0] != 6) viewer[0] += 1.0;
	if(key == 'y' && viewer[1] != 0) viewer[1] -= 1.0;
	if(key == 'Y' && viewer[1] != 9) viewer[1] += 1.0;
	if(key == 'z'  && viewer[2] != 4) viewer[2] -= 1.0;
	if(key == 'Z'  && viewer[2] != 10) viewer[2] += 1.0;
	if(key == 's' || key == 'S')
	{
		triggered = 1;
		firsttime = 1;
		printf("triggered\n");
	}
	printf("%f\n",viewer[0] );
	display();
}

void main(int argc, char **argv)
{
	glutInit(&argc , argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1000, 1000);
	glutCreateWindow("Colourable viewer");
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keys);
	glEnable(GL_DEPTH_TEST);
	glutTimerFunc(1, update, 0);
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glutMainLoop();
}