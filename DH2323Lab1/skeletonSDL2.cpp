// DH2323 Lab 1
// Introduction lab that covers:
// * SDL2 (https://www.libsdl.org/)
// * C++, std::vector and glm::vec3 (https://glm.g-truc.net)
// * 2D graphics
// * Plotting pixels
// * Video memory
// * Color representation
// * Linear interpolation

#include <iostream>
#include <glm/glm.hpp>
#include <vector>
#include "SDL2Auxiliary.h"

using namespace std;
using glm::vec3;

// ---------------------------------------------------------
// GLOBAL VARIABLES
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
SDL2Aux *sdlAux;
vector<glm::vec3> stars( 1000 );
int t;
float speed = 0.0005;

int control = 0;

// ---------------------------------------------------------
// FUNCTION DECLARATIONS
void Draw_task2();
void Draw_task3();
void Interpolate(glm::vec3 a, glm::vec3 b, vector<glm::vec3>& result);
void Update(); // is this just to move the functions to the top of the scope?
// ---------------------------------------------------------

// FUNCTION DEFINITIONS
int main(int argc, char* argv[])
{
    /*
	sdlAux = new SDL2Aux(SCREEN_WIDTH, SCREEN_HEIGHT);
	while (!sdlAux->quitEvent()) {
		Draw();
	}
	sdlAux->saveBMP("screenshot.bmp");
	return 0;
     */

    /* Interpolation between integers
    vector<float> result(10);

    Interpolate(5, 14, result);

    for( int i=0; i<result.size(); ++i )
        cout << result[i] << " ";
    */

    /*
    vector<glm::vec3> result(4);

    vec3 a(1,4,9.2);
    vec3 b(4,1,9.8);

    Interpolate( a, b, result );

    for( int i=0; i<result.size(); ++i )
    {
        cout << "( "
             << result[i].x << ", "
             << result[i].y << ", "
             << result[i].z << " ) \n";
    }*/

    // for task 2
    /*
    sdlAux = new SDL2Aux(SCREEN_WIDTH, SCREEN_HEIGHT);
    while (!sdlAux->quitEvent()) {
        Draw_task2();
    }
    sdlAux->saveBMP("screenshot.bmp");
    return 0;
     */

    // for task 3

    //cout << 0.2f;
    // initialize positions
    for (auto & star : stars) {

        // x and y between -1 and +1
        star.x = 2 * ( float(rand()) / float(RAND_MAX) - 0.5 );
        star.y = 2 * ( float(rand()) / float(RAND_MAX) - 0.5 );
        // z between 0 and 1;
        star.z = float(rand()) / float(RAND_MAX);

    }

    t = SDL_GetTicks();

    //cout << stars[346].x << ', ' << stars[346].y << ', ' << stars[346].z;

    sdlAux = new SDL2Aux(SCREEN_WIDTH, SCREEN_HEIGHT, false);
    while (!sdlAux->quitEvent()) {
        //Draw_task2();
        Update();
        Draw_task3();
    }
    sdlAux->saveBMP("screenshot.bmp");
    return 0;

}

void Draw_task3()
{
    sdlAux->clearPixels();

    float f = SCREEN_HEIGHT / 2;

    float x0 = SCREEN_WIDTH / 2;
    float y0 = SCREEN_HEIGHT / 2;

    for (int i = 0; i < stars.size(); i++) {
        float u = f * stars[i].x / stars[i].z + x0;
        float v = -f * stars[i].y / stars[i].z + y0;

        glm::vec3 color = 0.4f * glm::vec3(1,1,1) / (stars[i].z * stars[i].z);

        /*if (i == 45) {
            cout << '\n' << stars[i].x << ' , ' << stars[i].z;
        }*/

        sdlAux->putPixel(u, v, color);

    }

    sdlAux->render();
}

void Draw_task2()
{
	sdlAux->clearPixels();

    vec3 topLeft(1,0,0); // red
    vec3 topRight(0,0,1); // blue
    vec3 bottomLeft(1,1,0); // yellow
    vec3 bottomRight(0,1,0); // green

    vector<vec3> leftSide( SCREEN_HEIGHT );
    vector<vec3> rightSide( SCREEN_HEIGHT );

    Interpolate( topLeft, bottomLeft, leftSide );
    Interpolate( topRight, bottomRight, rightSide );

	for (int y = 0; y<SCREEN_HEIGHT; ++y)
	{
        vector<glm::vec3> row_colors(SCREEN_WIDTH);

        Interpolate(leftSide[y], rightSide[y], row_colors);

		for (int x = 0; x<SCREEN_WIDTH; ++x)
		{
			//vec3 color(0.0,0.0,1.0);
			sdlAux->putPixel(x, y, row_colors[x]);
		}
	}

	sdlAux->render();
}

float interpolate_dimension(glm::vec3 a, glm::vec3 b, char dimension, int i, int last_position) {

    return a[dimension] * (1 - float(i) / last_position) + b[dimension] * (float(i) / last_position);

}

void Interpolate(glm::vec3 a, glm::vec3 b, vector<glm::vec3>& result) {

    const int size = result.size();
    const float last_position = size - 1;

    //cout << size;

    if (size == 1) {
        result[0] = a;
        return;
    }

    for (int i = 0; i < size; i++) {
        result[i].x = a.x * (1 - float(i) / last_position) + b.x * (float(i) / last_position);
        result[i].y = a.y * (1 - float(i) / last_position) + b.y * (float(i) / last_position);
        result[i].z = a.z * (1 - float(i) / last_position) + b.z * (float(i) / last_position);
        //result[i].x = interpolate_dimension(a, b, 'x', i, last_position);
    }

}

void Update() {

    float t_now = SDL_GetTicks();

    float dt = float(t_now - t);

    t = t_now;

    /*if (control < 10) {
        cout << "\n" << dt;
        control++;
    }*/

    for(int s=0; s<stars.size(); ++s )
    {
        if (control < 10) {
            cout << "\n" << s << "\n Antes: " << stars[s].z;
            cout << "\n dt: " << dt;
            cout << "\n spped * dt: " << speed * dt;
        }

        stars[s].z = stars[s].z - speed * dt;

        if (control < 10) {
            cout << "\n Depois: " << stars[s].z;
            control++;
        }

        if( stars[s].z <= 0 ) stars[s].z += 1;
        if( stars[s].z > 1 ) stars[s].z -= 1;
    }
}

// not used
/*
void Interpolate(float a, float b, vector<float>& result) {

    const int size = result.size();
    const float last_position = size - 1;

    //cout << size;

    if (size == 1) {
        result[0] = a;
        return;
    }

    for (int i = 0; i < size; i++) {
        float num = a * (1 - float(i) / last_position) + b * (float(i) / last_position);
        result[i] = num;
    }

}
 */