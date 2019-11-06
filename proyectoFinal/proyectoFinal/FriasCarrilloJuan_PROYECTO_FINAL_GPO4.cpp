//Semestre 2020 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************			Proyecto Final      			******//
//*********    Laboratorio Computación Gráfica	- GPO4   *****//
//**********         Frías Carrillo Juan            **********//
//************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"
//#include "cmodel/CModel.h"

//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////
static GLuint ciudad_display_list;	//Display List for the Monito

int w = 500, h = 500;
int frame=0,time,timebase=0;
int deltaTime = 0;
char s[30];

CCamera objCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

int font=(int)GLUT_BITMAP_HELVETICA_18;

//GLfloat Diffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position


GLfloat LampDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat LampSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat LampPosition[] = { 0.0f, 65.0f, 0.0f, 1.0f };			// Light Position

/////////////////////// TEXTURA DE CASA ///////////////////7////

CTexture cielosol;
CTexture ladrillos;
CTexture pasto;
CTexture puerta;
CTexture reja;

CTexture wood;
CTexture sofa;
CTexture al;
CTexture lampara;
CTexture whiteWood;
CTexture bed;

////////////////// TEXTURAS  EXTERIORES CASA  /////////////////////
CFiguras sky;
CFiguras pared;
CFiguras pastof;
CFiguras pisof;
CFiguras cilindro;
CFiguras plano;
CFiguras mi_figura;

CTexture cabañapiso;
CTexture pisosala;
CTexture cabañamadera;
CTexture cabañabarda;
CTexture cabañaventana;
CTexture cabañapuerta;
CTexture cabañateja;
CTexture escalon;

CTexture arbol;
CTexture arbol1;
CTexture arbol2;
CTexture arbol3;
CTexture cercaJardin;

CFiguras prisma;
CFiguras fig1;

/////////////////////////  TEXTURA INTERIOR CASA //////////////////

CTexture estufaFront;
CTexture estufaUp;
CTexture estufaLat;
CTexture fregaderoUp;
CTexture fregaderoLat;
CTexture fregaderofront;
CTexture refrigerador;
CTexture alacenaLat;
CTexture cocinaintegral;
CTexture mesacocinaFront;
CTexture mesacocinaLat;
CTexture television;
CTexture alfombraPB;
CTexture alfombraPA;
CTexture librero;
CTexture librerolat;

////////////////////////// TEXTURA ANIMACION ///////////////////////
CTexture moltres;
CTexture articuno;

//////////////////////// MODELOS ///////////////////////////////
//CModel Avion;
//CModel silla;

////// VARIABLES DE ANIMACION SUPERMAN /////
float rotVent = 0.0;
float movMoltres = 0.0;
float movarticuno = -2.0;
float articunoX = 30.0;
float articunoY = 35.0;
float v = 5.0;
float gravedad = 9.81;
float t;
float supermanX = 53.0;
float supermanY = 80.0;
float supermanZ = 50.0;
float supermanrot = 45.0;

float art_fanimacion = false;
float art_fanimacion2 = false;

bool picada_articuno;

/////// VARIABLE ANIMACION VENTILADOR //////
bool ventiladorgira = false;
bool movMoltresDel = false;


GLuint createDL() 
{
	GLuint ciudadDL;
	//GLuint cieloDL;
	ciudadDL = glGenLists(1);

	glNewList(ciudadDL,GL_COMPILE);

	glEndList();

	return(ciudadDL);
}


///// FUNCIONES DE MODELOS /////
void lamp()
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);

	glLightfv(GL_LIGHT1, GL_DIFFUSE, LampDiffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, LampSpecular);

	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, lampara.GLindex);
		glColor3f(1.0, 1.0, 1.0);
		plano.plano(20.0, 60.0);			//plano 1
		glRotatef(45, 0, 1, 0);
		plano.plano(20.0, 60.0);			//plano 2
		glRotatef(90, 0, 1, 0);
		plano.plano(20.0, 60.0);			//plano 3
		glRotatef(135, 0, 1, 0);
		plano.plano(20.0, 60.0);			//plano 4
		glRotatef(180, 0, 1, 0);
		plano.plano(20.0, 60.0);			//plano 5
		glRotatef(225, 0, 1, 0);
		plano.plano(20.0, 60.0);			//plano 6
		glRotatef(270, 0, 1, 0);
		plano.plano(20.0, 60.0);			//plano 7
		glRotatef(315, 0, 1, 0);
		plano.plano(20.0, 60.0);			//plano 8
	glPopMatrix();
	glDisable(GL_ALPHA_TEST);
}

void silla()
{
	glColor3f(0.4, 0.2, 0.0);
	glPushMatrix();
		glTranslatef(0.0, 16.0, 0.0);
		prisma.prisma(12.0, 2.0, 12.0, whiteWood.GLindex);		//Base
		glTranslatef(5.0, -8.5, 5.0);
		prisma.prisma(2.0, 15.0, 2.0, whiteWood.GLindex);		//pata 1
		glTranslatef(-10.0, 0.0, 0.0);
		prisma.prisma(2.0, 15.0, 2.0, whiteWood.GLindex);		//pata 2
		glTranslatef(0.0, 0.0, -10.0);
		prisma.prisma(2.0, 15.0, 2.0, whiteWood.GLindex);		//pata 3
		glTranslatef(10.0, 0.0, 0.0);
		prisma.prisma(2.0, 15.0, 2.0, whiteWood.GLindex);		//pata 4
		glTranslatef(0.0, 17.0, 0.0);
		prisma.prisma(2.0, 15.0, 2.0, whiteWood.GLindex);		//parte_respaldo
		glTranslatef(0.0, 0.0, 5.0);
		prisma.prisma(2.0, 15.0, 4.0, whiteWood.GLindex);		//parte_respaldo
		glTranslatef(0.0, 0.0, 5.0);
		prisma.prisma(2.0, 15.0, 2.0, whiteWood.GLindex);		//parte_respaldo
		glTranslatef(0.0, 8.5, -5.0);
		prisma.prisma(2.0, 2.0, 12.0, whiteWood.GLindex);		//parte_respaldo
	glPopMatrix();
}

void ventilador() {
	glPushMatrix();	//Ventilador de techo
		glTranslatef(0.0, 0.0, 0.0);
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(0.0, 97.0, 0.0);
		glRotatef(rotVent, 0.0, 1.0, 0.0);
		cilindro.cilindro(5.0, 3.0, 10, al.GLindex);
		glColor3f(1.0, 1.0, 1.0);
		glRotatef(90.0, 0.0, 1.0, 0.0);
		glTranslatef(0.0, 1.25, 0.0);
		prisma.prisma(35.0, 1.0, 5.0, al.GLindex);
		glRotatef(90.0, 0.0, 1.0, 0.0);
		glTranslatef(0.0, 0.0, 0.0);
		prisma.prisma(35.0, 1.0, 5.0, al.GLindex);
		glRotatef(90.0, 0.0, 1.0, 0.0);
		glTranslatef(0.0, 0.0, 0.0);
		prisma.prisma(35.0, 1.0, 5.0, al.GLindex);
		glRotatef(90.0, 0.0, 1.0, 0.0);
		glTranslatef(0.0, 0.0, 0.0);
		prisma.prisma(35.0, 1.0, 5.0, al.GLindex);
	glPopMatrix();
}

void cama()
{
	glPushMatrix();							//Cama
		glTranslatef(0.0, 2.5, 0.0);
		prisma.prisma(60.0, 5.0, 35.0, wood.GLindex);		//Base
		glTranslatef(0.0, 6.5, 0.0);
		prisma.prisma(59.0, 8.0, 34.0, bed.GLindex);	//Colchon
		glTranslatef(31.5, 0.0, 0.0);
		prisma.prisma(3.0, 18.0, 35.0, wood.GLindex);	//Cabecera
		glTranslatef(-63.0, -3.0, 0.0);
		prisma.prisma(3.0, 12.0, 35.0, wood.GLindex);	//Piecera
		//cobija
		glTranslatef(24.5, 7.05, 17.0);
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		glColor3f(0.0, 0.0, 1.0);
		glBindTexture(GL_TEXTURE_2D, sofa.GLindex);
		plano.plano(45.0, 34.1);

		glTranslatef(0.0, 34.05, 0.0);
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		glBindTexture(GL_TEXTURE_2D, sofa.GLindex);
		plano.plano(45.0, 8.05);

		glTranslatef(0.0, 8.0, -34.1);
		glRotatef(180.0, 1.0, 0.0, 0.0);
		glBindTexture(GL_TEXTURE_2D, sofa.GLindex);
		plano.plano(45.0, 8.05);

		glRotatef(-90.0, 1.0, 0.0, 0.0);
		glRotatef(-90.0, 0.0, 1.0, 0.0);
		glTranslatef(4.0, 0.0, 22.55);
		glBindTexture(GL_TEXTURE_2D, sofa.GLindex);
		plano.plano(8.05, 34.1);
	glPopMatrix();
}


////////////////////////////////////////////// CARGA DE TEXTURAS /////////////////////////////////////////////////

void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel (GL_SMOOTH);
	//Para construir la figura comentar esto
	/*glLightfv(GL_LIGHT1, GL_POSITION, Position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);*/
	//glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable ( GL_COLOR_MATERIAL );
	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_BACK);
	//glPolygonMode(GL_BACK, GL_LINE);

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);
    
	cielosol.LoadTGA("text/cielo.tga");
	cielosol.BuildGLTexture();
	cielosol.ReleaseImage();

	ladrillos.LoadBMP("text/pisoE.bmp");
	ladrillos.BuildGLTexture();
	ladrillos.ReleaseImage();

	pasto.LoadTGA("text/pasto.tga");
	pasto.BuildGLTexture();
	pasto.ReleaseImage();

	puerta.LoadBMP("texturas/door.bmp");
	puerta.BuildGLTexture();
	puerta.ReleaseImage();

	wood.LoadTGA("text/wood.tga");
	wood.BuildGLTexture();
	wood.ReleaseImage();

	lampara.LoadTGA("text/lampara.tga");
	lampara.BuildGLTexture();
	lampara.ReleaseImage();

	bed.LoadTGA("text/bed.tga");
	bed.BuildGLTexture();
	bed.ReleaseImage();

	//sofa.LoadTGA("text/peluche.tga");
	//sofa.BuildGLTexture();
	//sofa.ReleaseImage();

	//al.LoadTGA("text/aluminum.tga");
	//al.BuildGLTexture();
	//al.ReleaseImage();

	whiteWood.LoadTGA("texturas/wood1.tga");
	whiteWood.BuildGLTexture();
	whiteWood.ReleaseImage();

	pisosala.LoadTGA("texturas/pisosala.tga");
	pisosala.BuildGLTexture();
	pisosala.ReleaseImage();

	cabañamadera.LoadTGA("texturas/cabañamadera.tga");
	cabañamadera.BuildGLTexture();
	cabañamadera.ReleaseImage();

	cabañapiso.LoadTGA("texturas/cabañapiso.tga");
	cabañapiso.BuildGLTexture();
	cabañapiso.ReleaseImage();

	cabañabarda.LoadBMP("texturas/cabañabarda.bmp");
	cabañabarda.BuildGLTexture();
	cabañabarda.ReleaseImage();

	cabañaventana.LoadTGA("texturas/ventanaDoble.tga");
	cabañaventana.BuildGLTexture();
	cabañaventana.ReleaseImage();

	cabañapuerta.LoadTGA("texturas/cabañapuerta.tga");
	cabañapuerta.BuildGLTexture();
	cabañapuerta.ReleaseImage();

	cabañateja.LoadBMP("texturas/cabañateja.bmp");
	cabañateja.BuildGLTexture();
	cabañateja.ReleaseImage();

	escalon.LoadBMP("texturas/escalon.bmp");
	escalon.BuildGLTexture();
	escalon.ReleaseImage();

	arbol.LoadTGA("texturas/arbol.tga");
	arbol.BuildGLTexture();
	arbol.ReleaseImage();

	arbol1.LoadTGA("texturas/arbol1.tga");
	arbol1.BuildGLTexture();
	arbol1.ReleaseImage();

	arbol2.LoadTGA("texturas/arbol2.tga");
	arbol2.BuildGLTexture();
	arbol2.ReleaseImage();

	arbol3.LoadTGA("texturas/arbol3.tga");
	arbol3.BuildGLTexture();
	arbol3.ReleaseImage();

	//// CARGA TEXTURAS INTERIOR ////

	cercaJardin.LoadTGA("texturas/cercaJardin.tga");
	cercaJardin.BuildGLTexture();
	cercaJardin.ReleaseImage();

	estufaFront.LoadTGA("texturas/estufaRot.tga");
	estufaFront.BuildGLTexture();
	estufaFront.ReleaseImage();

	estufaUp.LoadTGA("texturas/estufaUp.tga");
	estufaUp.BuildGLTexture();
	estufaUp.ReleaseImage();

	estufaLat.LoadTGA("texturas/estufaLat.tga");
	estufaLat.BuildGLTexture();
	estufaLat.ReleaseImage();

	fregaderoUp.LoadTGA("texturas/fregaderoUp.tga");
	fregaderoUp.BuildGLTexture();
	fregaderoUp.ReleaseImage();

	fregaderoLat.LoadTGA("texturas/fregaderoLat.tga");
	fregaderoLat.BuildGLTexture();
	fregaderoLat.ReleaseImage();

	fregaderofront.LoadTGA("texturas/fregaderofront.tga");
	fregaderofront.BuildGLTexture();
	fregaderofront.ReleaseImage();

	refrigerador.LoadTGA("texturas/refrigerador.tga");
	refrigerador.BuildGLTexture();
	refrigerador.ReleaseImage();

	cocinaintegral.LoadTGA("texturas/alacena.tga");
	cocinaintegral.BuildGLTexture();
	cocinaintegral.ReleaseImage();

	alacenaLat.LoadTGA("texturas/alacenaLat.tga");
	alacenaLat.BuildGLTexture();
	alacenaLat.ReleaseImage();

	mesacocinaFront.LoadTGA("texturas/mesacocinaFront.tga");
	mesacocinaFront.BuildGLTexture();
	mesacocinaFront.ReleaseImage();

	mesacocinaLat.LoadTGA("texturas/mesacocinaLat.tga");
	mesacocinaLat.BuildGLTexture();
	mesacocinaLat.ReleaseImage();

	alfombraPB.LoadTGA("texturas/alfombraPB.tga");
	alfombraPB.BuildGLTexture();
	alfombraPB.ReleaseImage();

	alfombraPA.LoadTGA("texturas/alfombraPA.tga");
	alfombraPA.BuildGLTexture();
	alfombraPA.ReleaseImage();

	television.LoadTGA("texturas/television.tga");
	television.BuildGLTexture();
	television.ReleaseImage();

	librero.LoadTGA("texturas/librero.tga");
	librero.BuildGLTexture();
	librero.ReleaseImage();

	librerolat.LoadTGA("texturas/librerolat.tga");
	librerolat.BuildGLTexture();
	librerolat.ReleaseImage();

	////// TEXTURAS ANIMACION /////
	moltres.LoadTGA("Texturas/Moltres.tga");
	moltres.BuildGLTexture();
	moltres.ReleaseImage();

	articuno.LoadTGA("Texturas/Articuno.tga");
	articuno.BuildGLTexture();
	articuno.ReleaseImage();

	//chair._3dsLoad("Silla.3DS");

	//END NEW//////////////////////////////

	objCamera.Position_Camera(0.0f, 2.0f, 10.0f, 0.0f, -2.0f, 0.0f, 0.0f, 1.0f, 0.0f); //camara: posicion, vista, up. Por terna de vectores en 3d

	////NEW Crear una lista de dibujo
	//ciudad_display_list = createDL();

}

void pintaTexto(float x, float y, float z, void *font,char *string)
{
  
  char *c;     //Almacena los caracteres a escribir
  glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
  //glWindowPos2i(150,100);
  for (c=string; *c != '\0'; c++) //Condicion de fin de cadena
  {
    glutBitmapCharacter(font, *c); //imprime
  }
}

//////////////////////////////////////// COLOCACION DE MODELOS CON SUS TEXTURAS ////////////////////////////

void estufa() {  //- Derecha, Atrás, Izq, Frente, Abajo, Arriba
	glDisable(GL_LIGHTING);
	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.0);
	//glScalef(3.0, 7.0, 7.0);
	mi_figura.mueble(estufaLat.GLindex, estufaLat.GLindex, estufaLat.GLindex, estufaFront.GLindex, estufaLat.GLindex, estufaUp.GLindex);
	glDisable(GL_LIGHTING);
	glPopMatrix();
}

void fregadero() {  //- Derecha, Atrás, Izq, Frente, Abajo, Arriba
	glDisable(GL_LIGHTING);
	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.0);
	//glScalef(3.0, 7.0, 7.0);
	mi_figura.mueble(fregaderoLat.GLindex, fregaderoLat.GLindex, fregaderofront.GLindex, fregaderoLat.GLindex, fregaderoLat.GLindex, fregaderoUp.GLindex);
	glDisable(GL_LIGHTING);
	glPopMatrix();
}

void refrigeradormodelo() {  //- Derecha, Atrás, Izq, Frente, Abajo, Arriba
	glDisable(GL_LIGHTING);
	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.0);
	//glScalef(3.0, 7.0, 7.0);
	mi_figura.mueble(fregaderoLat.GLindex, fregaderoLat.GLindex, fregaderoLat.GLindex, refrigerador.GLindex, fregaderoLat.GLindex, fregaderoLat.GLindex);
	glDisable(GL_LIGHTING);
	glPopMatrix();
}

void cocinaintegralmodelo() {  //- Derecha, Atrás, Izq, Frente, Abajo, Arriba
	glDisable(GL_LIGHTING);
	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.0);
	//glScalef(3.0, 7.0, 7.0);
	mi_figura.mueble(cocinaintegral.GLindex, alacenaLat.GLindex, alacenaLat.GLindex, alacenaLat.GLindex, alacenaLat.GLindex, alacenaLat.GLindex);
	glDisable(GL_LIGHTING);
	glPopMatrix();
}

void mesacocina() {  //- Derecha, Atrás, Izq, Frente, Abajo, Arriba
	glDisable(GL_LIGHTING);
	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.0);
	//glScalef(3.0, 7.0, 7.0);
	mi_figura.mueble(mesacocinaLat.GLindex, mesacocinaLat.GLindex, mesacocinaLat.GLindex, mesacocinaFront.GLindex, mesacocinaLat.GLindex, mesacocinaLat.GLindex);
	glDisable(GL_LIGHTING);
	glPopMatrix();
}

void alfombramodelo() {  //Alfombra
	glDisable(GL_LIGHTING);
		glPushMatrix();
		glTranslatef(0.0, 0.0, 0.0);
		//glScalef(2.0, 4.0, 0.0);
		mi_figura.plano(alfombraPB.GLindex);
		glDisable(GL_LIGHTING);
	glPopMatrix();
}

void alfombramodelo2() {  //Alfombra
	glDisable(GL_LIGHTING);
		glPushMatrix();
		glTranslatef(0.0, 0.0, 0.0);
		//glScalef(2.0, 4.0, 0.0);
		mi_figura.plano(alfombraPA.GLindex);
		glDisable(GL_LIGHTING);
	glPopMatrix();
}

void televisionmodelo() {  //Television
	glDisable(GL_LIGHTING);
		glPushMatrix();
		glTranslatef(0.0, 0.0, 0.0);
		//glScalef(2.0, 4.0, 0.0);
		mi_figura.plano(television.GLindex);
		glDisable(GL_LIGHTING);
	glPopMatrix();
}

void libreromodelo() {  //- Derecha, Atrás, Izq, Frente, Abajo, Arriba
	glDisable(GL_LIGHTING);
	glPushMatrix();
		glTranslatef(0.0, 0.0, 0.0);
		//glScalef(3.0, 7.0, 7.0);
		mi_figura.mueble(librerolat.GLindex, librerolat.GLindex, librerolat.GLindex, librero.GLindex, librerolat.GLindex, librerolat.GLindex);
		glDisable(GL_LIGHTING);
	glPopMatrix();
}

void moltresmodelo() {  //Moltres
	glDisable(GL_LIGHTING);
	glPushMatrix();
		glTranslatef(0.0, 0.0, 0.0);
		//glScalef(2.0, 4.0, 0.0);
		mi_figura.plano(moltres.GLindex);
		glDisable(GL_LIGHTING);
	glPopMatrix();
}

void articunomodelo() {  //Articuno
	glDisable(GL_LIGHTING);
	glPushMatrix();
		glTranslatef(0.0, 0.0, 0.0);
		//glScalef(2.0, 4.0, 0.0);
		mi_figura.plano(articuno.GLindex);
		glDisable(GL_LIGHTING);
	glPopMatrix();
}

void Techo() {
	glPushMatrix();
		//piso
		glBindTexture(GL_TEXTURE_2D, cabañapiso.GLindex);
		glBegin(GL_POLYGON);
		glNormal3f(1.0f, 0.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0, 0.0, 0);//1
		glTexCoord2f(1.0f, 0.0f); glVertex3f(20, 0.0, 0);//2
		glTexCoord2f(1.0f, 4.0f); glVertex3f(20, 0.0, -20);//3  
		glTexCoord2f(0.0f, 4.0f); glVertex3f(0, 0.0, -20);
		glEnd();

		// Frente
		glBindTexture(GL_TEXTURE_2D, whiteWood.GLindex);
		glBegin(GL_TRIANGLES);
		glNormal3f(1.0f, 0.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0, 0.0, 0);//1
		glTexCoord2f(0.0f, 8.0f); glVertex3f(20, 0.0, 0);//2
		glTexCoord2f(0.5f, 4.0f); glVertex3f(10, 10.0, 0);//3  
		glEnd();

		//Atras
		glTranslatef(0, 0, -20);
		glBindTexture(GL_TEXTURE_2D, whiteWood.GLindex);
		glBegin(GL_TRIANGLES);
		glNormal3f(1.0f, 0.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0, 0.0, 0);//1
		glTexCoord2f(0.0f, 8.0f); glVertex3f(20, 0.0, 0);//2
		glTexCoord2f(0.5f, 4.0f); glVertex3f(10, 10.0, 0);//3  
		glEnd();

		//Techo izquierdo
		glTranslatef(0, 0, -1);
		glColor3f(1.0, 0.0, 0.0);
		glBindTexture(GL_TEXTURE_2D, cabañateja.GLindex);
		glBegin(GL_POLYGON);
		glNormal3f(1.0f, 0.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0, 0, 0);//1
		glTexCoord2f(1.0f, 0.0f); glVertex3f(10, 10.0, 0);//2
		glTexCoord2f(1.0f, 1.0f); glVertex3f(10, 10.0, 22);//3 
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0, 0.0, 22);//4
		glEnd();

		//Techo derecho
		glBegin(GL_POLYGON);
		glNormal3f(1.0f, 0.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(10, 10.0, 0);//1
		glTexCoord2f(1.0f, 0.0f); glVertex3f(20, 0.0, 0);//2
		glTexCoord2f(1.0f, 1.0f); glVertex3f(20, 0.0, 22);//3 
		glTexCoord2f(0.0f, 1.0f); glVertex3f(10, 10.0, 22);//4
		glEnd();

	glPopMatrix();
}

void barandal()
{
	//BARANDAL 1
	glPushMatrix();
		glTranslatef(-9.75, 1.75, 10 + 2);
		glColor3f(0.8, 0.8, 0.8);
		glScalef(0.5, 0.5, 4.0);
		fig1.cabañapris3(cabañamadera.GLindex, cabañamadera.GLindex);
	glPopMatrix();

	//soporte 1
	glPushMatrix();
		glTranslatef(-9.75, 0.25, 10 + 2);
		glRotatef(90, 1, 0, 0);
		glColor3f(0.8, 0.8, 0.8);
		glScalef(0.5, 0.5, 2.5);
		fig1.cabañapris3(cabañamadera.GLindex, cabañamadera.GLindex);
	glPopMatrix();

	//soporte 2
	glPushMatrix();
		glTranslatef(-9.75, 0.25, 10 + 2 + 1.75);
		glRotatef(90, 1, 0, 0);
		glColor3f(0.8, 0.8, 0.8);
		glScalef(0.5, 0.5, 2.5);
		fig1.cabañapris3(cabañamadera.GLindex, cabañamadera.GLindex);
	glPopMatrix();

	//BARANDAL 2
	glPushMatrix();
		glTranslatef(-10 + 1.5, 1.75, 10 + 2 + 1.75);
		glColor3f(0.8, 0.8, 0.8);
		glScalef(3.0, 0.5, 0.5);
		fig1.cabañapris3(cabañamadera.GLindex, cabañamadera.GLindex);
	glPopMatrix();

	//soporte 3
	glPushMatrix();
		glTranslatef(-10 + 2.75, 0.25, 10 + 2 + 1.75);
		glRotatef(90, 1, 0, 0);
		glColor3f(0.8, 0.8, 0.8);
		glScalef(0.5, 0.5, 2.5);
		fig1.cabañapris3(cabañamadera.GLindex, cabañamadera.GLindex);
	glPopMatrix();

	//BARANDAL 3
	glPushMatrix();
		glTranslatef(-1.5, 1.75, 10 + 2 + 1.75);
		glColor3f(0.8, 0.8, 0.8);
		glScalef(3.0, 0.5, 0.5);
		fig1.cabañapris3(cabañamadera.GLindex, cabañamadera.GLindex);
	glPopMatrix();

	//soporte 4
	glPushMatrix();
		glTranslatef(-3 + 0.25, 0.25, 10 + 2 + 1.75);
		glRotatef(90, 1, 0, 0);
		glColor3f(0.8, 0.8, 0.8);
		glScalef(0.5, 0.5, 2.5);
		fig1.cabañapris3(cabañamadera.GLindex, cabañamadera.GLindex);
	glPopMatrix();

	//soporte 5
	glPushMatrix();
		glTranslatef(-0.25, 0.25, 10 + 2 + 1.75);
		glRotatef(90, 1, 0, 0);
		glColor3f(0.8, 0.8, 0.8);
		glScalef(0.5, 0.5, 2.5);
		fig1.cabañapris3(cabañamadera.GLindex, cabañamadera.GLindex);
	glPopMatrix();

	//BARANDAL 4
	glPushMatrix();
		glTranslatef(-0.25, 1.75, 10 + 2);
		glColor3f(0.8, 0.8, 0.8);
		glScalef(0.5, 0.5, 4.0);
		fig1.cabañapris3(cabañamadera.GLindex, cabañamadera.GLindex);
	glPopMatrix();

	//soporte 6
	glPushMatrix();
		glTranslatef(-0.25, 0.25, 10 + 2);
		glRotatef(90, 1, 0, 0);
		glColor3f(0.8, 0.8, 0.8);
		glScalef(0.5, 0.5, 2.5);
		fig1.cabañapris3(cabañamadera.GLindex, cabañamadera.GLindex);
	glPopMatrix();

}

void tree(GLint text)
{
	glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, text);
		glBegin(GL_QUADS); //plano
		glColor3f(1.0, 1.0, 1.0);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
		glEnd();
	glPopMatrix();

	glPushMatrix();
		glRotatef(45, 0, 1, 0);
		glBegin(GL_QUADS); //plano
		glColor3f(1.0, 1.0, 1.0);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
		glEnd();
	glPopMatrix();

	glPushMatrix();
		glRotatef(-45, 0, 1, 0);
		glBegin(GL_QUADS); //plano
		glColor3f(1.0, 1.0, 1.0);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
		glEnd();
	glPopMatrix();

	glPushMatrix();
		glRotatef(90, 0, 1, 0);
		glBegin(GL_QUADS); //plano
		glColor3f(1.0, 1.0, 1.0);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
		glEnd();
	glPopMatrix();
	glDisable(GL_ALPHA_TEST);
	glEnable(GL_LIGHTING);
}

void cabaña()
{
	glDisable(GL_LIGHTING);
	//cabañapiso
	glPushMatrix();
		glTranslatef(0, -2, 0);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(20.0, 2.0, 20.0);
		fig1.cabañapris(pisosala.GLindex, cabañabarda.GLindex);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-5, -2, 10 + 2);
		glColor3f(0.8, 0.8, 0.8);
		glScalef(10.0, 2.0, 4.0);
		fig1.cabañapris3(whiteWood.GLindex, whiteWood.GLindex);
	glPopMatrix();

	//Piso entrada
	glPushMatrix();
		glTranslatef(5, -2.25, 10 + 1.5);
		glColor3f(0.8, 0.8, 0.8);
		glScalef(5.0, 1.5, 3.0);
		fig1.cabañapris3(cabañabarda.GLindex, whiteWood.GLindex);
	glPopMatrix();
	//Techo entrada
	glPushMatrix();
		glTranslatef(2.0, 8.5, 10 + 3.0);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(0.3, 0.3, 0.15);
		Techo();
	glPopMatrix();
	//Viga izquierda
	glPushMatrix();
		glTranslatef(5 - 2.25, 3.5, 10 + 2.75);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(0.5, 10.0, 0.5);
		fig1.cabañapris3(whiteWood.GLindex, whiteWood.GLindex);
	glPopMatrix();
	//Viga derecha
	glPushMatrix();
		glTranslatef(5 + 2.25, 3.5, 10 + 2.75);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(0.5, 10.0, 0.5);
		fig1.cabañapris3(whiteWood.GLindex, whiteWood.GLindex);
	glPopMatrix();


	//Barandales
	glPushMatrix();
		barandal();
	glPopMatrix();

	//escaleras
	glPushMatrix();
		glTranslatef(-5.0, -2.25, 14.55);
		glColor3f(0.7, 0.7, 0.7);
		glScalef(4.0, 1.5, 1.0);
		fig1.cabañapris1(whiteWood.GLindex, whiteWood.GLindex);
		glPushMatrix();
			glTranslatef(0, -0.25, 1);
			glScalef(1.0, 0.5, 1.0);
			fig1.cabañapris1(whiteWood.GLindex, whiteWood.GLindex);
		glPopMatrix();
	glPopMatrix();

	//Muro Izquierdo
	glPushMatrix();
		glTranslatef(-9.75, 4 + 5, 0);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(0.5, 20.0, 19.5);
		fig1.cabañapris4(whiteWood.GLindex, whiteWood.GLindex);
	glPopMatrix();

	//Vigas exteriores
	/*glPushMatrix();
	glTranslatef(-9.5, 4.0, 8);
	glColor3f(1.0, 1.0, 1.0);
	glScalef(1.0, 10.0, 1.0);
	fig1.cabañapris3(whiteWood.GLindex, whiteWood.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(9.5, 4.0, -9.5);
	glColor3f(1.0, 1.0, 1.0);
	glScalef(1.0, 10.0, 1.0);
	fig1.cabañapris3(whiteWood.GLindex, whiteWood.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(9.5, 4.0, -1.0);
	glColor3f(1.0, 1.0, 1.0);
	glScalef(1.0, 10.0, 1.0);
	fig1.cabañapris3(whiteWood.GLindex, whiteWood.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(9.5, 4.0, 8);
	glColor3f(1.0, 1.0, 1.0);
	glScalef(1.0, 10.0, 1.0);
	fig1.cabañapris3(whiteWood.GLindex, whiteWood.GLindex);
	glPopMatrix();*/


	//Muro Trasero
	glPushMatrix();
		glTranslatef(0, 4 + 5, -9.75);
		glRotatef(180, 0, 1, 0);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(19.5, 20.0, 0.5);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1);
		fig1.cabañapris2(whiteWood.GLindex, whiteWood.GLindex);
		glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	//Muro Derecho inferior 1
	glPushMatrix();
		glTranslatef(9.75, 4, 5);
		glRotatef(180, 0, 0, 1);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(0.5, 10.0, 10);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1);
		fig1.cabañapris5(cabañaventana.GLindex, cabañaventana.GLindex);
		glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	//Muro Derecho inferior 2
	glPushMatrix();
		glTranslatef(9.75, 4, -5);
		glRotatef(180, 0, 0, 1);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(0.5, 10.0, 10);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1);
		fig1.cabañapris5(cabañaventana.GLindex, cabañaventana.GLindex);
		glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	//Muro Derecho superior
	glPushMatrix();
		glTranslatef(9.75, 4 + 5 + 5, 0);
		glRotatef(180, 0, 0, 1);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(0.5, 10.0, 20);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1);
		fig1.cabañapris5(whiteWood.GLindex, whiteWood.GLindex);
		glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	//Muro Frente izquierdo
	glPushMatrix();
		glTranslatef(-5.0, 4, 9.75);
		glRotatef(180, 0, 0, 1);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(10.0, 10.0, 0.5);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1);
		fig1.cabañapris2(cabañaventana.GLindex, cabañaventana.GLindex);
		glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	//Muro frente centro
	glPushMatrix();
		glTranslatef(1.25, 4, 9.75);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(2.5, 10.0, 0.5);
		fig1.cabañapris2(whiteWood.GLindex, whiteWood.GLindex);
	glPopMatrix();

	//puerta
	glPushMatrix();
		glTranslatef(5, 4, 9.75);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(5.0, 10.0, 0.25);
		fig1.cabañapris3(puerta.GLindex, puerta.GLindex);
	glPopMatrix();

	//Muro frente derecho
	glPushMatrix();
		glTranslatef(8.75, 4, 9.75);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(2.5, 10.0, 0.5);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1);
		fig1.cabañapris2(whiteWood.GLindex, whiteWood.GLindex);
		glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	//Muro frente superior
	glPushMatrix();
		glTranslatef(0, 4 + 10, 9.75);
		glRotatef(180, 0, 1, 0);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(19.5, 10.0, 0.5);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1);
		fig1.cabañapris2(whiteWood.GLindex, whiteWood.GLindex);
		glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	//Techo
	glPushMatrix();
		glTranslatef(-10, 19, 10);
		glColor3f(1.0, 1.0, 1.0);
		Techo();
	glPopMatrix();


	//Segundo piso
	glPushMatrix();
		glTranslatef(2.5, 10, 0);
		glColor3f(0.8, 0.4, 0.0);
		glScalef(14.75, 1.0, 19.5);
		fig1.cabañapris(whiteWood.GLindex, whiteWood.GLindex);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-7.25, 10, -7.5);
		glScalef(4.75, 1.0, 4.75);
		fig1.cabañapris(whiteWood.GLindex, whiteWood.GLindex);
	glPopMatrix();

	//Escaleras
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
		glTranslatef(-10 + 2.75, 0, 5.25);
		fig1.prisma(4.75, 1.0, 1.0, escalon.GLindex);
		glTranslatef(0, 1.0, -1.0);
		fig1.prisma(4.75, 1.0, 1.0, escalon.GLindex);
		glTranslatef(0, 1.0, -1.0);
		fig1.prisma(4.75, 1.0, 1.0, escalon.GLindex);
		glTranslatef(0, 1.0, -1.0);
		fig1.prisma(4.75, 1.0, 1.0, escalon.GLindex);
		glTranslatef(0, 1.0, -1.0);
		fig1.prisma(4.75, 1.0, 1.0, escalon.GLindex);
		glTranslatef(0, 1.0, -1.0);
		fig1.prisma(4.75, 1.0, 1.0, escalon.GLindex);
		glTranslatef(0, 1.0, -1.0);
		fig1.prisma(4.75, 1.0, 1.0, escalon.GLindex);
		glTranslatef(0, 1.0, -1.0);
		fig1.prisma(4.75, 1.0, 1.0, escalon.GLindex);
		glTranslatef(0, 1.0, -1.0);
		fig1.prisma(4.75, 1.0, 1.0, escalon.GLindex);
		glTranslatef(0, 1.0, -1.0);
		fig1.prisma(4.75, 1.0, 1.0, escalon.GLindex);
		glTranslatef(0, 1.0, -1.0);
		fig1.prisma(4.75, 1.0, 1.0, escalon.GLindex);
	glPopMatrix();
	//Fin Escalera

	/*VERJAS*/
	glPushMatrix();
		glTranslatef(-35, -3, 20);
		glPushMatrix();	//arbustos izquierdos
			glTranslatef(8, 0.0, -2.0);
			glScalef(0.3, 0.3, 0.3);
			tree(arbol2.GLindex);
			glTranslatef(10.0, 0.0, -30.0);
			glPushMatrix();
				glScalef(2.5, 4.0, 2.5);
				tree(arbol.GLindex);
				glTranslatef(0, 0.0, -20.0);
				tree(arbol1.GLindex);
			glPopMatrix();
			glTranslatef(-10.0, 0.0, -90.0);
			tree(arbol2.GLindex);
		glPopMatrix();
		glScalef(1.1, 1.0, 0.7);
		glPushMatrix();	//verja izquierda
			glTranslatef(4.0, -0.7, -1.0);
			glRotatef(90.0, 0.0, 1.0, 0.0);
			glScalef(0.3, 0.3, 0.0);
			fig1.cerca(cercaJardin.GLindex);
			glPushMatrix();
				glTranslatef(19.44, 0.0, 0.0);
				fig1.cerca(cercaJardin.GLindex);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(38.9, 0.0, 0.0);
				fig1.cerca(cercaJardin.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(58.44, 0.0, 0.0);
				fig1.cerca(cercaJardin.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(77.9, 0.0, 0.0);
				fig1.cerca(cercaJardin.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(97.4, 0.0, 0.0);
				fig1.cerca(cercaJardin.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(116.8, 0.0, 0.0);
				fig1.cerca(cercaJardin.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(136.2, 0.0, 0.0);
				fig1.cerca(cercaJardin.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(155.6, 0.0, 0.0);
				fig1.cerca(cercaJardin.GLindex);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(175.1, 0.0, 0.0);
				fig1.cerca(cercaJardin.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(194.5, 0.0, 0.0);
				fig1.cerca(cercaJardin.GLindex);
			glPopMatrix();

		glPopMatrix();

		glTranslatef(47.0, 0.0, 0.0);
		glPushMatrix();	//arbustos derechos
			glTranslatef(1.0, 0.0, -2.0);
			glScalef(0.3, 0.3, 0.3);
			tree(arbol2.GLindex);
			glTranslatef(0.0, 0.0, -30.0);
			tree(arbol3.GLindex);
			glTranslatef(0.0, 0.0, -30.0);
			tree(arbol3.GLindex);
			glTranslatef(0.0, 0.0, -30.0);
			tree(arbol3.GLindex);
			glTranslatef(0.0, 0.0, -30.0);
			tree(arbol3.GLindex);
			glTranslatef(0.0, 0.0, -30.0);
			tree(arbol3.GLindex);
			glTranslatef(0.0, 0.0, -30.0);
			tree(arbol2.GLindex);
		glPopMatrix();
		glPushMatrix();	//verja derecha
			glTranslatef(4.0, -0.7, -1.0);
			glRotatef(90.0, 0.0, 1.0, 0.0);
			glScalef(0.3, 0.3, 0.0);
			fig1.cerca(cercaJardin.GLindex);
			glPushMatrix();
				glTranslatef(19.44, 0.0, 0.0);
				fig1.cerca(cercaJardin.GLindex);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(38.9, 0.0, 0.0);
				fig1.cerca(cercaJardin.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(58.44, 0.0, 0.0);
				fig1.cerca(cercaJardin.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(77.9, 0.0, 0.0);
				fig1.cerca(cercaJardin.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(97.4, 0.0, 0.0);
				fig1.cerca(cercaJardin.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(116.8, 0.0, 0.0);
				fig1.cerca(cercaJardin.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(136.2, 0.0, 0.0);
				fig1.cerca(cercaJardin.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(155.6, 0.0, 0.0);
				fig1.cerca(cercaJardin.GLindex);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(175.1, 0.0, 0.0);
				fig1.cerca(cercaJardin.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(194.5, 0.0, 0.0);
				fig1.cerca(cercaJardin.GLindex);
			glPopMatrix();
		glPopMatrix();

		glTranslatef(-58.0, 0.0, -2.0);
		glRotatef(-90.0, 0.0, 1.0, 0.0);
		glPushMatrix();	//verja frontal
			glTranslatef(4.0, -0.7, -1.0);
			glRotatef(90.0, 0.0, 1.0, 0.0);
			glScalef(0.3, 0.3, 0.0);

			glPushMatrix();
				glTranslatef(58.44, 0.0, 0.0);
				fig1.cerca(cercaJardin.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(77.9, 0.0, 0.0);
				fig1.cerca(cercaJardin.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(97.4, 0.0, 0.0);
				fig1.cerca(cercaJardin.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(116.8, 0.0, 0.0);
				fig1.cerca(cercaJardin.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(136.2, 0.0, 0.0);
				fig1.cerca(cercaJardin.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(175.1, 0.0, 0.0);
				fig1.cerca(cercaJardin.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(194.5, 0.0, 0.0);
				fig1.cerca(cercaJardin.GLindex);
			glPopMatrix();

		glPopMatrix();

		glTranslatef(-65.0, 0.0, 0.5);
		glPushMatrix();	//verja trasera
			glTranslatef(4.0, -0.7, -1.0);
			glRotatef(90.0, 0.0, 1.0, 0.0);
			glScalef(0.3, 0.3, 0.0);
			
			glPushMatrix();
				glTranslatef(58.44, 0.0, 0.0);
				fig1.cerca(cercaJardin.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(77.9, 0.0, 0.0);
				fig1.cerca(cercaJardin.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(97.4, 0.0, 0.0);
				fig1.cerca(cercaJardin.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(116.8, 0.0, 0.0);
				fig1.cerca(cercaJardin.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(136.2, 0.0, 0.0);
				fig1.cerca(cercaJardin.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(155.6, 0.0, 0.0);
				fig1.cerca(cercaJardin.GLindex);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(175.1, 0.0, 0.0);
				fig1.cerca(cercaJardin.GLindex);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(194.5, 0.0, 0.0);
				fig1.cerca(cercaJardin.GLindex);
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
	/**FIN VERJAS*/


	///// MUEBLES INTERIOR PLANTA BAJA ////
	
	//Estufa
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
		glTranslatef(8.3, 0.8, 0);
		glScalef(2, 3.5, 3.0);
		//glRotatef(-90.0, 0.0, 0.0, 1.0);
		estufa();
	glPopMatrix();

	//Fregadero
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
		glTranslatef(8.3, 0.8, 5.5);
		glScalef(2.0, 3.5, 6.0);
		glRotatef(90.0, 0.0, 1.0, 0.0);
		fregadero();
	glPopMatrix();

	//Refrigerador
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
		glTranslatef(-3.5, 2.05, 3.8);
		glScalef(2.0, 6.0, 3.0);
		glRotatef(180, 0.0, 1.0, 0.0);
		refrigeradormodelo();
	glPopMatrix();

	//Cocina Integral
	glColor3f(1.0, 1.0, 1.0);
		glPushMatrix();
		glTranslatef(0.0, 5.5, -8.5);
		glScalef(6.5, 3.0, 2.0);
		//glRotatef(-90.0, 0.0, 0.0, 1.0);
		cocinaintegralmodelo();
	glPopMatrix();

	//Mesa Cocina
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
		glTranslatef(8.3, 0.8, -5.5);
		glScalef(2, 3.5, 5.5);
		//glRotatef(-90.0, 0.0, 0.0, 1.0);
		mesacocina();
	glPopMatrix();

	//AlfombraPB
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
		glTranslatef(1.0, -0.9, -6.5);
		glScalef(0.40, 0.25, 0.25);
		glRotatef(90.0, 1.0, 0.0, 0.0);
		alfombramodelo();
	glPopMatrix();

	//Moltres
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
		glTranslatef(-30.0+movMoltres, 35.0, 0.0);
		glScalef(0.80, 0.50, 0.50);
		//glRotatef(90.0, 1.0, 0.0, 0.0);
		moltresmodelo();
	glPopMatrix();

	//Articuno
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
		glTranslatef(articunoX, articunoY, movarticuno);
		glScalef(0.40, 0.25, 0.25);
		//glRotatef(90.0, 1.0, 0.0, 0.0);
		articunomodelo();
	glPopMatrix();


	///// MUEBLES INTERIOR PLANTA ALTA ////

	//AlfombraPB
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
		glTranslatef(0.0, 10.7, -2.0);
		glScalef(0.25, 0.40, 0.50);
		glRotatef(90.0, 1.0, 0.0, 0.0);
		alfombramodelo2();
	glPopMatrix(); 

	//Librero
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
		glTranslatef(6.5, 14.0, -8.5);
		glScalef(4.0, 7.0, 3.0);
		glRotatef(90, 0.0, 1.0, 0.0);
		libreromodelo();
	glPopMatrix();

	glEnable(GL_LIGHTING);
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	
		
	glPushMatrix();
		glRotatef(g_lookupdown,1.0f,0,0);

		gluLookAt(	objCamera.mPos.x,  objCamera.mPos.y,  objCamera.mPos.z,	
					objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,	
					objCamera.mUp.x,   objCamera.mUp.y,   objCamera.mUp.z);
	

		glPushMatrix();

			glPushMatrix(); //Creamos cielo
				glDisable(GL_LIGHTING);
				glTranslatef(0, 0, 0);
				glColor3f(1.0, 1.0, 1.0);
				sky.skybox(850.0, 600.0, 600.0, cielosol.GLindex, cielosol.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glTranslatef(0, 64.0, 0);


			//Inicia estructura de la casa
			glPushMatrix();
				glTranslatef(0, -256.0 + 30.0, 0);
				glScalef(10, 10 , 10);
				cabaña();
			glPopMatrix();

			//Inicia pasto
			glPushMatrix();
				glDisable(GL_LIGHTING);
				glTranslatef(-(75.0 + 175.0), -256.0, 0.0);
				glColor3f(1.0, 1.0, 1.0);
				pastof.piso(350.0, 0.5, 600.0, pasto.GLindex); //PASTO 1
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
				glDisable(GL_LIGHTING);
				glTranslatef(0.0, -256.0, -(150.0 + 50.0));
				glColor3f(1.0, 1.0, 1.0);
				pastof.piso(150.0, 0.5, 200.0, pasto.GLindex); //PASTO 2
				glEnable(GL_LIGHTING);
			glPopMatrix();
			
			glPushMatrix();
				glDisable(GL_LIGHTING);
				glTranslatef(75.0 + 175.0, -256.0, 0.0);
				glColor3f(1.0, 1.0, 1.0);
				pastof.piso(350.0, 0.5, 600.0, pasto.GLindex); //PASTO 3
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
				glDisable(GL_LIGHTING);
				glTranslatef(0.0, -256.0, 150.0 + 50.0);
				glColor3f(1.0, 1.0, 1.0);
				pastof.piso(150.0, 0.5, 200.0, pasto.GLindex); //PASTO 4
				glEnable(GL_LIGHTING);
			glPopMatrix();
			//Finaliza pasto

			//ladrillos de entrada
			glPushMatrix();
				glDisable(GL_LIGHTING);

				glTranslatef(50, -256.0 + 0.25, 250.0 + 10.0);
				pisof.piso(40.0, 0.5, 35.0, ladrillos.GLindex);

				glTranslatef(0.0, 0.0, -47.5);
				pisof.piso(40.0, 0.5, 35.0, ladrillos.GLindex);
				
				glTranslatef(0.0, 0.0, -47.5);
				pisof.piso(40.0, 0.5, 35.0, ladrillos.GLindex);

				glEnable(GL_LIGHTING);
			glPopMatrix();
			//fin ladrillos de entrada


		///////////// MODELADO DE OBJETOS COMO SILLAS; MESA Y CAMA ////////////////////

			/////// CAMA //////////
				glPushMatrix();
					glRotatef(90.0, 0.0, 1.0, 0.0);
					glTranslatef(-40, -120.0, 70.0);
					glScalef(1.0, 1.5, 1.0);
					cama();
				glPopMatrix();

			////// VENTILADOR //////
				glPushMatrix();
					//glRotatef(90.0, 0.0, 1.0, 0.0);
					glTranslatef(0, -187.0, 0.0);
					glScalef(1.0, 1.5, 1.0);
					ventilador();
				glPopMatrix();


			//	
			//	glPushMatrix();					//Sillon individual
			//		glTranslatef(55.0, 7.5, -45.0);
			//		glRotatef(135.0, 0.0, 1.0, 0.0);
			//		glColor3f(0.2, 0.1, 0.0);
			//		prisma.prisma(20.0, 5.0, 20.0, sofa.GLindex);		//Base
			//		glTranslatef(0.0, 7.5, 7.5);
			//		prisma.prisma(20.0, 10.0, 5.0, sofa.GLindex);		//Respaldo
			//		glTranslatef(12.5, -2.5, -7.5);
			//		prisma.prisma(5.0, 15.0, 20.0, sofa.GLindex);		//Coderas
			//		glTranslatef(-25.0, 0.0, 0.0);
			//		prisma.prisma(5.0, 15.0, 20.0, sofa.GLindex);		//Coderas
			//		glTranslatef(-1.25, -10.0, 8.75);
			//		glColor3f(0.88, 0.88, 0.88);
			//		prisma.prisma(2.5, 5.0, 2.5, al.GLindex);		//Pata 1
			//		glTranslatef(0.0, 0.0, -17.5);
			//		prisma.prisma(2.5, 5.0, 2.5, al.GLindex);		//Pata 2
			//		glTranslatef(27.5, 0.0, 0.0);
			//		prisma.prisma(2.5, 5.0, 2.5, al.GLindex);		//Pata 3
			//		glTranslatef(0.0, 0.0, 17.5);
			//		prisma.prisma(2.5, 5.0, 2.5, al.GLindex);		//Pata 4
			//		glColor3f(0.0, 0.4, 0.8);
			//		glTranslatef(-13.75, 15.0, -6.00);
			//		prisma.prisma(20.0, 15.0, 2.5, sofa.GLindex);		//Cojin 1
			//		glColor3f(1.0, 0.0, 0.0);
			//	glPopMatrix();

				//glPushMatrix();	//Ventilador de techo
					//glTranslatef(0.0, 0.0, 0.0);
					//glColor3f(1.0, 1.0, 1.0);
					//glTranslatef(0.0, 97.0, 0.0);
					//glRotatef(rotVent, 0.0, 1.0, 0.0);
					//cilindro.cilindro(5.0, 3.0, 10, al.GLindex);
					//glColor3f(1.0, 1.0, 1.0);
					//glRotatef(90.0, 0.0, 1.0, 0.0);
					//glTranslatef(0.0, 1.25, 0.0);
					//prisma.prisma(35.0, 1.0, 5.0, al.GLindex);
					//glRotatef(90.0, 0.0, 1.0, 0.0);
					//glTranslatef(0.0, 0.0, 0.0);
					//prisma.prisma(35.0, 1.0, 5.0, al.GLindex);
					//glRotatef(90.0, 0.0, 1.0, 0.0);
					//glTranslatef(0.0, 0.0, 0.0);
					//prisma.prisma(35.0, 1.0, 5.0, al.GLindex);
					//glRotatef(90.0, 0.0, 1.0, 0.0);
					//glTranslatef(0.0, 0.0, 0.0);
					//prisma.prisma(35.0, 1.0, 5.0, al.GLindex);
				//glPopMatrix();

			//	glPushMatrix();					//Mueble TV
			//		glColor3f(0.6, 0.6, 0.6);
			//		glTranslatef(-37.5, 0.75, -55.0);
			//		prisma.prisma(39.0, 1.5, 15.0, wood.GLindex);		//Base 1
			//		glTranslatef(0.0, 0.75 + 11.0 + 0.75, 0.0);
			//		prisma.prisma(39.0, 1.5, 15.0, wood.GLindex);		//base 2
			//		glTranslatef(0.0, 12.5, 0.0);
			//		prisma.prisma(39.0, 1.5, 15.0, wood.GLindex);		//Base 3
			//		glTranslatef(0.0, 12.5, 0.0);
			//		prisma.prisma(39.0, 1.5, 15.0, wood.GLindex);		//Base 4
			//		glTranslatef(-18.75, -18.75, 0.0);
			//		prisma.prisma(1.5, 39.0, 15.0, wood.GLindex);		//Pata 1
			//		glTranslatef(12.5, 0.0, 0.0);
			//		prisma.prisma(1.5, 39.0, 15.0, wood.GLindex);		//Pata 2
			//		glTranslatef(12.5, 0.0, 0.0);
			//		prisma.prisma(1.5, 39.0, 15.0, wood.GLindex);		//Pata 3
			//		glTranslatef(12.5, 0.0, 0.0);
			//		prisma.prisma(1.5, 39.0, 15.0, wood.GLindex);		//Pata 4
			//	glPopMatrix();

				glPushMatrix();								//Mueble ESTUDIO
					glColor3f(0.8, 0.4, 0.0);
					glTranslatef(7.0, -107.0, -85.0);
					glRotatef(270.0, 0.0, 1.0, 0.0);
					prisma.prisma(15.0, 27.0, 3.0, whiteWood.GLindex);	//1
					glTranslatef(0.0, 15.0, 18.5);
					prisma.prisma(15.0, 3.0, 40.0, whiteWood.GLindex);	//2
					glTranslatef(0.0, -15.0, 18.5);
					prisma.prisma(15.0, 27.0, 3.0, whiteWood.GLindex);	//3
					glTranslatef(0.0, 0.0, -26.0);
					prisma.prisma(15.0, 3.0, 20.0, whiteWood.GLindex);	//4
					glTranslatef(0.0, -8.0, 8.5);
					prisma.prisma(15.0, 13.0, 3.0, whiteWood.GLindex);	//5
				glPopMatrix();

				//////////////// COLOCACION DE SILLAS ///////////
			glPushMatrix();
				glTranslatef(-30.0, -120.0, -65.0);
				glRotatef(270.0, 0.0, 1.0, 0.0);
				silla();
				glPopMatrix();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(5.0, -55.0, -50.0);
				glRotatef(-125.0, 0.0, 1.0, 0.0);
				silla();
			glPopMatrix();

			
		glPopMatrix(); 

	glPopMatrix();		///// NO BORRAR


	glutSwapBuffers ( ); //// NO BORRAR


}

//////////////////////////////////////////7/// FUNCION PARA ANIMACION ////////////////////

void animacion()
{

	////////////////////////// INICIO ANIMACION VENTILADOR /////////////
	if(ventiladorgira)
	{
		rotVent += 1.5;
	}
	////////////////////////// FINAL ANIMACION VENTILADOR /////////////////

	////////////////////////// INICIO ANIMACION MOLTRES /////////////
	if (movMoltresDel)
	{
		movMoltres += 0.01;
	}

	////////////////////////// FINAL ANIMACION MOLTRES /////////////////

	////////////////////////// INICIO ANIMACION ARTICUNO /////////////
	if (art_fanimacion)
	{
		movarticuno += 0.01;
	}

	if (art_fanimacion2)
	{
		movarticuno -= 0.01;
	}
	
	if (picada_articuno)
	{
		t += 0.1;
		articunoX = v*t*cos(45);
		articunoY = v*t*sin(45) - 0.5*gravedad*(t*t);

	}

	////////////////////////// FINAL ANIMACION ARTICUNO /////////////////


	glutPostRedisplay(); ///// NO BORRAR 
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 900.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

///////////////////////////////// TECLAS DE MOVIMIENTO Y ACTIVACION DE ANIMACIONES /////////////////////

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {

		case 'w':   //Movimientos de camara
		case 'W':
			objCamera.Move_Camera( CAMERASPEED + 0.5);
			break;

		case 's':
		case 'S':
			objCamera.Move_Camera(-(CAMERASPEED + 0.5));
			break;

		case 'a':
		case 'A':
			objCamera.Strafe_Camera(-(CAMERASPEED + 0.5));
			break;

		case 'd':
		case 'D':
			objCamera.Strafe_Camera( CAMERASPEED + 0.5);
			break;

		
			/////////////////////////Para Activar animación de ventilador /////////////////////
 		case '3':
			ventiladorgira = true;
			break;

			/////////////////////////Para Activar animación de Moltres /////////////////////
		case '4':
			movMoltresDel = true;
			break;

			/////////////////////////Para Activar animación de Articuno /////////////////////
		case '5':
			art_fanimacion2 = true;
			//movarticuno = 0;
			//picada_articuno = true;
			break;

		case '6':
			//art_fanimacion2 = true;
			//movarticuno = 0;
			picada_articuno = true;
			break;

			////////////////////////////////////////////////////////////////////////////////////////


		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }

  glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
	case GLUT_KEY_PAGE_UP:
		objCamera.UpDown_Camera(CAMERASPEED + 0.2);
		break;

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED - 0.2);
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 2.0f;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 2.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View( CAMERASPEED);
		break;

    default:
		break;
  }
  glutPostRedisplay();
}

int main ( int argc, char** argv )   // Main Function
{

  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (640, 480);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Proyecto Final - Frías Carrillo Juan - GPO4"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );


  glutMainLoop        ( );          // 

  return 0;
}
