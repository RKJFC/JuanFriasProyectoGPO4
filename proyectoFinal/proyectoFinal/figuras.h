//#include <windows.h>  //Solo para Windows
//#include <GL/gl.h>     // The GL Header File
//#include <stdio.h>

//#include <math.h>
#include "Main.h"


class CFiguras
{
	public:

	float text_der;
	float text_izq;
	void plano(GLuint text);
	void skybox(float altura, float largo, float profundidad, GLuint text, GLuint text2);//Funcion creacion cielo
	void pared(float altura, float largo, float profundidad, GLuint text);
	void piso(float altura, float largo, float profundidad, GLuint text);
	
	//Nuevo
	void prisma(float largo, float altura, float profundidad, GLuint text);
	void plano(float largo, float altura);
	void cerca(GLuint text);
	void cilindro(float radio, float altura, int resolucion, GLuint text);

	void cabañapris(GLuint textura1, GLuint textura2);
	void cabañapris1(GLuint textura1, GLuint textura2);
	void cabañapris2(GLuint textura1, GLuint textura2);
	void cabañapris3(GLuint textura1, GLuint textura2);
	void cabañapris4(GLuint textura1, GLuint textura2);
	void cabañapris5(GLuint textura1, GLuint textura2);
	void mueble(GLuint text, GLuint text2, GLuint text3, GLuint text4, GLuint text5, GLuint text6);

	void prisma1(float altura, float largo, float profundidad, GLuint text, GLuint text2);// funcion que crea los edificios


};
