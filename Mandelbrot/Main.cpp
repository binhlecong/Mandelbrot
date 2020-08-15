#include "SDL.h"

#define HEIGHT 1000
#define WIDTH  1000

int maxIteration = 200;
long double min = -2.0;
long double max = 2.0;

long double map(long double x, long double in_min, long double in_max, 
	long double out_min, long double out_max) 
{
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event event;

	//Uint32 flag = SDL_WINDOW_FULLSCREEN;
	window = SDL_CreateWindow("BINH", 200, 40, 1600, 1000, 0);
	renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_RenderSetLogicalSize(renderer, WIDTH, HEIGHT);

	while (true)
	{
		SDL_RenderPresent(renderer);

		for (size_t i = 0; i < WIDTH; i++)
		{
			for (size_t j = 0; j < HEIGHT; j++)
			{
				long double a = map(i, 0, WIDTH, min, max);
				long double b = map(j, 0, HEIGHT, min, max);

				long double ai = a, bi = b;

				int n = 0;
				
				for (int k = 0; k < maxIteration; k++)
				{
					long double a1 = a * a - b * b;
					long double b1 = 2 * a * b;

					a = a1 + ai;
					b = b1 + bi;

					if (a + b > 2)
					{
						break;
					}

					n++;
				}

				int brightness = map(n, 0, maxIteration, 0, 255);

				if (n == maxIteration)
				{
					brightness = 0;
				}

				int red = brightness;
				int green = map(brightness * brightness, 0, 255 * 255, 0, 255);
				int blue = map(sqrt(brightness), 0, sqrt(255), 0, 255);

				SDL_SetRenderDrawColor(renderer, red, green, blue, 255);
				SDL_RenderDrawPoint(renderer, i, j);
			}
		}

		
		if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
		{
			break;
		}
	}

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	return 0;
}