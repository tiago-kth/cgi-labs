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

// ---------------------------------------------------------
// FUNCTION DECLARATIONS
void Draw();
void Interpolate(glm::vec3 a, glm::vec3 b, vector<glm::vec3>& result);
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
    }

}

void Draw()
{
	sdlAux->clearPixels();

	for (int y = 0; y<SCREEN_HEIGHT; ++y)
	{
		for (int x = 0; x<SCREEN_WIDTH; ++x)
		{
			vec3 color(0.0,0.0,1.0);
			sdlAux->putPixel(x, y, color);
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