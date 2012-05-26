

#include <windows.h>
#include <GL/glut.h>

typedef float	M3DVector3f[3];	
// Rotation amounts
static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;

void m3dCrossProduct(M3DVector3f result, const M3DVector3f u, const M3DVector3f v)
	{
	result[0] = u[1]*v[2] - v[1]*u[2];
	result[1] = -u[0]*v[2] + v[0]*u[2];
	result[2] = u[0]*v[1] - v[0]*u[1];
	}

void m3dFindNormal(M3DVector3f result, const M3DVector3f point1, const M3DVector3f point2, 
							const M3DVector3f point3)
	{
	M3DVector3f v1,v2;		// Temporary vectors

	// Calculate two vectors from the three points. Assumes counter clockwise
	// winding!
	v1[0] = point1[0] - point2[0];
	v1[1] = point1[1] - point2[1];
	v1[2] = point1[2] - point2[2];

	v2[0] = point2[0] - point3[0];
	v2[1] = point2[1] - point3[1];
	v2[2] = point2[2] - point3[2];

	// Take the cross product of the two vectors to get
	// the normal vector.
	m3dCrossProduct(result, v1, v2);
	}


// Called to draw scene
void RenderScene(void)
	{
	M3DVector3f vNormal;	// Storeage for calculated surface normal

	// Clear the window with current clearing color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	/***********************************first ship start*********************************************/ 
	// Save the matrix state and do the rotations
	glPushMatrix();
	glRotatef(xRot, -80.0f, 20.0f, 0.0f);
	glRotatef(yRot, -80.0f, 20.0f, 0.0f);
	//set position
	glTranslatef(-80.0f, 0.0f, 0.0f);
    // Set material color
	glColor3ub(92, 64, 51);
	glBegin(GL_TRIANGLES);
       
        //sisi1
		{
        M3DVector3f vPoints[3] = {{ -40.0f,20.0f,0.0f },
                                  {-30.0f, 0.0f, 0.0f},
                                {-30.0f, 20.0f, 20.0f }};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }

		//sisi2
		{
        M3DVector3f vPoints[3] = {{ -30.0f,20.0f,20.0f },
                                  {-30.0f, 0.0f, 0.0f},
                                {30.0f, 0.0f, 0.0f }};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }

		//sisi3
		{
        M3DVector3f vPoints[3] = {{ -30.0f,20.0f,20.0f },
                                  {30.0f, 0.0f, 0.0f},
                                {30.0f,20.0f,20.0f }};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }

		//sisi4
		{
        M3DVector3f vPoints[3] = {{ 30.0f, 20.0f, 20.0f },
                                  {30.0f, 0.0f, 0.0f},
                                {40.0f,20.0f,0.0f }};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }

		      //sisi1b
		{
        M3DVector3f vPoints[3] = {{ -40.0f,20.0f,0.0f },
								{-30.0f, 20.0f, -20.0f },
                                  {-30.0f, 0.0f, 0.0f}
                                };

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }

		//sisi2b
		{
        M3DVector3f vPoints[3] = {{ -30.0f,20.0f,-20.0f },
								{30.0f, 0.0f, 0.0f },
                                  {-30.0f, 0.0f, 0.0f}
                                };

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }

		//sisi3b
		{
        M3DVector3f vPoints[3] = {{ -30.0f,20.0f,-20.0f },
									{30.0f,20.0f,-20.0f },
                                  {30.0f, 0.0f, 0.0f}
                                };

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }

		//sisi4b
		{
        M3DVector3f vPoints[3] = {{ 30.0f, 20.0f, -20.0f },
									{40.0f,20.0f,0.0f },
                                  {30.0f, 0.0f, 0.0f}
                                };

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }
		glColor3ub(107, 66, 38);
			//sisia1
		{
        M3DVector3f vPoints[3] = {{ -40.0f, 20.0f, 0.0f },
                                  {-30.0f, 20.0f, 20.0f},
                                {-30.0f,20.0f,-20.0f }};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }
	
				//sisia2
		{
        M3DVector3f vPoints[3] = {{ -30.0f, 20.0f, -20.0f },
                                  {-30.0f, 20.0f, 20.0f},
								{30.0f,20.0f,20.0f }
                                };

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }
		//sisia3
	{
        M3DVector3f vPoints[3] = {{ 30.0f, 20.0f, 20.0f },
								{30.0f,20.0f,-20.0f },
                                 {-30.0f, 20.0f, -20.0f}
                                };

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }
		//sisia4
	
			{
        M3DVector3f vPoints[3] = {{30.0f, 20.0f, 20.0f},
								{ 40.0f, 20.0f, 0.0f },
                                {30.0f,20.0f,-20.0f }};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }

	//sampingnya cube
	//sc1
	
			{
        M3DVector3f vPoints[3] = {{-10.0f, 20.0f, 8.0f},
								{ -5.0f, 20.0f, 8.0f },
                                {-10.0f,24.0f,8.0f }};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }
		//sc2
	
			{
        M3DVector3f vPoints[3] = {{-10.0f, 24.0f, 8.0f},
								{ -5.0f, 20.0f, 8.0f },
                                {-5.0f,20.0f,-8.0f }};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }
			//sc3
	
			{
        M3DVector3f vPoints[3] = {{-10, 24.0f, 8.0f},
									{-5.0f,20.0f,-8.0f },
								{ -10.0f, 24.0f, -8.0f }  };

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }
			//sc4
		{
        M3DVector3f vPoints[3] = {{-10.0f, 20.0f, -8.0f},
								{-10.0f,24.0f,-8.0f },
								{ -5.0f, 20.0f, -8.0f }};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }
	
	//tiang
		glColor3ub(107, 66, 38);
		//t1
		{
        M3DVector3f vPoints[3] = {{18.0f, 20.0f, 1.0f},
								{20.0f,20.0f,1.0f },
								{ 18.0f, 60.0f, 1.0f }};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }
		//t2
		{
        M3DVector3f vPoints[3] = {{20.0f, 20.0f, 1.0f},
								{20.0f,60.0f,1.0f },
								{ 18.0f, 60.0f, 1.0f }};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }
		//t3
		{
        M3DVector3f vPoints[3] = {{20.0f, 20.0f, 1.0f},
								{20.0f,20.0f,-1.0f },
								{ 20.0f, 60.0f, 1.0f }};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }
		//t4
		{
        M3DVector3f vPoints[3] = {{20.0f, 20.0f, -1.0f},
								{20.0f,60.0f,-1.0f },
								{ 20.0f, 60.0f, 1.0f }};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }
		//t5
		{
        M3DVector3f vPoints[3] = {{18.0f, 20.0f, -1.0f},
								{ 18.0f, 60.0f, -1.0f },
								{20.0f,20.0f,-1.0f }};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }
		//t6
		{
        M3DVector3f vPoints[3] = {{20.0f, 20.0f, -1.0f},
								{ 18.0f, 60.0f, -1.0f },
								{20.0f,60.0f,-1.0f }};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }
		//t7
		{
        M3DVector3f vPoints[3] = {{20.0f, 20.0f, 1.0f},
								{ 20.0f, 60.0f, 1.0f },
								{20.0f,20.0f,-1.0f }};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }
		//t8
		{
        M3DVector3f vPoints[3] = {{20.0f, 20.0f, -1.0f},
								{ 20.0f, 60.0f, 1.0f },
								{20.0f,60.0f,-1.0f }};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }

		//layar
		glColor3ub(205, 179, 134);
		//l1
		{
        M3DVector3f vPoints[3] = {{19.0f, 40.0f, -20.0f},
								{ 19.0f, 59.0f, -10.0f },
								{19.0f,59.0f,10.0f }};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }
		//l2
		{
        M3DVector3f vPoints[3] = {{19.0f, 40.0f, -20.0f},
								{19.0f,40.0f,20.0f },
								{ 19.0f, 59.0f, 10.0f }};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }

		//l3
		{
        M3DVector3f vPoints[3] = {{19.0f, 40.0f, -20.0f},
								{19.0f,59.0f,10.0f },
								{ 19.0f, 59.0f, -10.0f }};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }
		//l4
		{
        M3DVector3f vPoints[3] = {{19.0f, 40.0f, -20.0f},
								{ 19.0f, 59.0f, 10.0f },
								{19.0f,40.0f,20.0f }};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }

		//layarbawah
		//lb1
		{
        M3DVector3f vPoints[3] = {{19.0f, 25.0f, -20.0f},
								{ 19.0f, 39.0f, 20.0f },
								{19.0f,39.0f,-20.0f }};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }
		//lb2
		{
        M3DVector3f vPoints[3] = {{19.0f, 25.0f, -20.0f},
								{19.0f,25.0f,20.0f },
								{ 19.0f, 39.0f, 20.0f }};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }

		//lb3
		{
        M3DVector3f vPoints[3] = {{19.0f, 25.0f, -20.0f},
								{19.0f,39.0f,-20.0f },
								{ 19.0f, 39.0f, 20.0f }};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }
		//lb4
		{
        M3DVector3f vPoints[3] = {{19.0f, 25.0f, -20.0f},
								{ 19.0f, 39.0f, 20.0f },
								{19.0f,25.0f,20.0f }};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }
		

	glEnd();
   	// Restore the matrix state


	/* upper part*/
	//cube
	glColor3ub(107, 66, 38);
	glTranslatef(-18.0f, 16.0f, 0.0f);
	glutSolidCube(16.0f);
	glPopMatrix();
	glPushMatrix();
	glRotatef(xRot, -80.0f, 20.0f, 0.0f);
	glRotatef(yRot, -80.0f, 20.0f, 0.0f);
	glTranslatef(-61.0f, 60.2f, 0.0f);
	glutSolidCube(2.0f);
	glPopMatrix();



	/************************************first ship end********************************************/ 
	/***********************************second ship start******************************************/
	glPushMatrix();
	glRotatef(xRot, 80.0f, 10.0f, -50.0f);
	glRotatef(yRot, 80.0f, 10.0f, -50.0f);
	glTranslatef(80.0f, 10.0f, -50.0f);
	glColor3ub(128, 128, 128);
	glBegin(GL_TRIANGLES);
 
        //sisi1
		{
        M3DVector3f vPoints[3] = {{0.0f, 0.0f, 20.0f},
								{ -10.0f,30.0f,0.0f },
								{-25.0f, 0.0f, 6.78f }}; //ganti ©об╬ ╬ъ╦ч -,.-
        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }

		//sisi2
		{
        M3DVector3f vPoints[3] = {{ -10.0f,30.0f,0.0f },
									{0.0f, 0.0f, 20.0f },
                                  {0.0f, 30.0f, 5.0f}};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }

		//sisi3
		{
        M3DVector3f vPoints[3] = {{ 0.0f,0.0f,20.0f },
								{10.0f, 30.0f, 0.0f},
								{0.0f,30.0f,5.0f }};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }

		//sisi4
		{
        M3DVector3f vPoints[3] = {{10.0f,30.0f,0.0f },
								{ 0.0f, 0.0f, 20.0f },                                
								{25.0f, 0.0f, 6.78f}}; //ganti

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }
		//sisi5
		{
        M3DVector3f vPoints[3] = {{ -10.0f, 30.0f, 0.0f },
                                  {0.0f, 30.0f, 5.0f},
                                {10.0f,30.0f,0.0f }};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }
		//sisi6
		{
		M3DVector3f vPoints[3] = {{-25.0f, 0.0f, 6.78f},
									{25.0f, 0.0f, 6.78f},
                                  {0.0f, 0.0f, 20.0f}};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }
		//sisi7
		{
		M3DVector3f vPoints[3] = {{-25.0f, 0.0f, 6.78f},
									{-10.0f, 30.0f, 0.0f},
                                  {-25.0f, 0.0f, -10.0f}};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }
		//sisi8
		{
		M3DVector3f vPoints[3] = {{25.0f, 0.0f, 6.78f},
								{25.0f, 0.0f, -10.0f},
									{10.0f, 30.0f, 0.0f}};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
        }

		//upper part
		//up1
		{
        M3DVector3f vPoints[3] = {{ 10.0f, 30.0f, -70.0f },
									{-10.0f, 30.0f, 0.0f},
									 {10.0f,30.0f,0.0f }};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
		}
		//up2
		{
        M3DVector3f vPoints[3] = {{ -10.0f, 30.0f, 0.0f },
									{10.0f,30.0f,-70.0f },
									{-10.0f, 30.0f, -70.0f}};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
		}
		//up3
		{
        M3DVector3f vPoints[3] = {{ 10.0f, 30.0f, -70.0f },
									{0.0f,30.0f,-75.0f },
									{-10.0f, 30.0f, -70.0f}};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
		}
		//back part
		//b1
		{
        M3DVector3f vPoints[3] = {{ 0.0f, 0.0f, -95.0f },
									{-10.0f, 30.0f, -70.0f},
									{0.0f,30.0f,-75.0f }};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
		}
		//b2
		{
        M3DVector3f vPoints[3] = {{ 0.0f, 0.0f, -95.0f },
								{0.0f,30.0f,-75.0f },
									{10.0f, 30.0f, -70.0f}};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
		}
		//b3
		{
        M3DVector3f vPoints[3] = {{-10.0f, 30.0f, -70.0f},
								{ 0.0f, 0.0f, -95.0f },									
								{-25.0f,0.0f,-83.0f }};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
		}
		//b4
		{
        M3DVector3f vPoints[3] = {{ 0.0f, 0.0f, -95.0f },
								{10.0f, 30.0f, -70.0f},																
								{25.0f,0.0f,-83.0f }};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
		}
		//side part
		//s1
		{
        M3DVector3f vPoints[3] = {{ -10.0f, 30.0f, 0.0f },
								{-10.0f, 30.0f, -70.0f},
								{-25.0f,0.0f,-83.0f }};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
		}
		//s2
		{
        M3DVector3f vPoints[3] = {{ -10.0f, 30.0f, 0.0f },
								{-25.0f,0.0f,-83.0f },
								{-25.0f, 0.0f, 6.78f}};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
		}
		//s3
		{
        M3DVector3f vPoints[3] = {{ 10.0f, 30.0f, 0.0f },
								{25.0f,0.0f,-83.0f },
								{10.0f, 30.0f, -70.0f}};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
		}
		//s4
		{
        M3DVector3f vPoints[3] = {{ 10.0f, 30.0f, 0.0f },
								{25.0f, 0.0f, 6.78f},
								{25.0f,0.0f,-83.0f }};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
		}
		//bottom part
		//bt1
		{
        M3DVector3f vPoints[3] = {{ 0.0f, 0.0f, -95.0f },
								{25.0f,0.0f,-83.0f },
								{-25.0f,0.0f,-83.0f}};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
		}
		//bt2
		{
        M3DVector3f vPoints[3] = {{ -25.0f,0.0f,-83.0f},
								{25.0f,0.0f,-83.0f },
								{25.0f, 0.0f, 6.78f}};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
		}
		//bt3
		{
         M3DVector3f vPoints[3] = {{ -25.0f,0.0f,-83.0f},
								{25.0f,0.0f,6.78f },
								{-25.0f, 0.0f, 6.78f}};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
		}

		//wingspart
		//w1
		{
         M3DVector3f vPoints[3] = {{ -25.0f,0.0f,-83.0f},
								{-40.0f, -30.0f, -83.0f},
								{-25.0f, 0.0f, 6.78f}};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
		}
		//w2
		{
         M3DVector3f vPoints[3] = {{ -25.0f,0.0f,-83.0f},
								{-25.0f, 0.0f, 6.78f},
								{-40.0f, -30.0f, -83.0f}};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
		}
		//w3
		{
         M3DVector3f vPoints[3] = {{ -40.0f, -30.0f,6.78f},
								{-25.0f, 0.0f, 6.78f},
								{-40.0f, -30.0f, -83.0f}};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
		}
		//w4
		{
         M3DVector3f vPoints[3] = {{ -40.0f, -30.0f,6.78f},
								{-40.0f, -30.0f, -83.0f},
								{-25.0f, 0.0f, 6.78f}};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
		}
		//w5
		{
         M3DVector3f vPoints[3] = {{ 25.0f,0.0f,-83.0f},
								{40.0f, -30.0f, -83.0f},
								{25.0f, 0.0f, 6.78f}};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
		}
		//w6
		{
         M3DVector3f vPoints[3] = {{ 25.0f,0.0f,-83.0f},
								{25.0f, 0.0f, 6.78f},
								{40.0f, -30.0f, -83.0f}};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
		}
		//w7
		{
         M3DVector3f vPoints[3] = {{ 40.0f, -30.0f,6.78f},
								{25.0f, 0.0f, 6.78f},
								{40.0f, -30.0f, -83.0f}};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
		}
		//w8
		{
         M3DVector3f vPoints[3] = {{ 40.0f, -30.0f,6.78f},
								{40.0f, -30.0f, -83.0f},
								{25.0f, 0.0f, 6.78f}};

        m3dFindNormal(vNormal, vPoints[0], vPoints[1], vPoints[2]);
        glNormal3fv(vNormal);
		glVertex3fv(vPoints[0]);
		glVertex3fv(vPoints[1]);
		glVertex3fv(vPoints[2]);
		}
	glEnd();

	glColor3ub(10, 10, 10);
	//cube
	glTranslatef(0.0f, 16.0f, 0.0f);
	glutSolidCube(18.0f);
	glPopMatrix();

	/***********************************second ship end******************************************/

	// Display the results
	glutSwapBuffers();
	}

// This function does any needed initialization on the rendering
// context. 
void SetupRC()
    {
    // Light values and coordinates
    GLfloat  ambientLight[] = { 0.3f, 0.3f, 0.3f, 1.0f };
    GLfloat  diffuseLight[] = { 0.7f, 0.7f, 0.7f, 1.0f };
    GLfloat  specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat  specref[] = { 1.0f, 1.0f, 1.0f, 1.0f };

    glEnable(GL_DEPTH_TEST);	// Hidden surface removal
    glFrontFace(GL_CCW);		// Counter clock-wise polygons face out
    glEnable(GL_CULL_FACE);		// Do not calculate inside of jet

    // Enable lighting
    glEnable(GL_LIGHTING);

    // Setup and enable light 0
    glLightfv(GL_LIGHT0,GL_AMBIENT,ambientLight);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuseLight);
    glLightfv(GL_LIGHT0,GL_SPECULAR, specular);
    glEnable(GL_LIGHT0);

    // Enable color tracking
    glEnable(GL_COLOR_MATERIAL);
	
    // Set Material properties to follow glColor values
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    // All materials hereafter have full specular reflectivity
    // with a high shine
    glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
    glMateriali(GL_FRONT, GL_SHININESS, 128);
    
    // Light blue background
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f );
    
    glEnable(GL_NORMALIZE);
    }

/////////////////////////////////////////////////////
// Handle arrow keys
void SpecialKeys(int key, int x, int y)
    {
    if(key == GLUT_KEY_UP)
        xRot-= 5.0f;

    if(key == GLUT_KEY_DOWN)
        xRot += 5.0f;

    if(key == GLUT_KEY_LEFT)
        yRot -= 5.0f;

    if(key == GLUT_KEY_RIGHT)
        yRot += 5.0f;

    if(key > 356.0f)
        xRot = 0.0f;

    if(key < -1.0f)
        xRot = 355.0f;

    if(key > 356.0f)
        yRot = 0.0f;

    if(key < -1.0f)
        yRot = 355.0f;

    // Refresh the Window
    glutPostRedisplay();
    }


//////////////////////////////////////////////////////////
// Reset projection and light position
void ChangeSize(int w, int h)
    {
    GLfloat fAspect;
    GLfloat lightPos[] = { -50.f, 50.0f, 100.0f, 1.0f };

    // Prevent a divide by zero
    if(h == 0)
        h = 1;

    // Set Viewport to window dimensions
    glViewport(0, 0, w, h);

    // Reset coordinate system
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    fAspect = (GLfloat) w / (GLfloat) h;
    gluPerspective(45.0f, fAspect, 1.0f, 225.0f);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
    glTranslatef(0.0f, -20.0f, -150.0f);
    }

int main(int argc, char* argv[])
    {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1000,400);
	glutCreateWindow(".:: OpenGL model - Boat & Stealth Ship(Ghost Ship! Not a walrus robot) ::.");
    glutReshapeFunc(ChangeSize);
    glutSpecialFunc(SpecialKeys);
    glutDisplayFunc(RenderScene);
    SetupRC();
    glutMainLoop();

    return 0;
    }
