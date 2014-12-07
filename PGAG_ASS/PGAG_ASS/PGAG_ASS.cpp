#include <iostream>
#include <SDL.h>
#include "Vec2.h"

int main(int argc, char *argv[])
{
	Vec2 g(3.0f, 5.0f);
	Vec2 f(0.0f, 5.0f);
	Vec2 k; 
	
	g += f;
	
	std::cout << g.x << "," << g.y;
	std::cin.get();
	return 0;
	
}