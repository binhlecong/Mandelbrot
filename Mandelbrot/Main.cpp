#include "SDL.h"
#include "windows.h"

#define HEIGHT 1000
#define WIDTH  1000

int maxIteration = 100;
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
	window = SDL_CreateWindow("BINH", 200, 40, 1000, 1000, 0);
	renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_RenderSetLogicalSize(renderer, WIDTH, HEIGHT);

	// frame time
	const int FPS = 1;
	const int framedelay = 3000 / FPS;
	Uint32 frameStart = 0;
	int frameTime = 0;

	//// color conversion
	//float H;
	//float S = 0.75, V = 0.75;
	//float C = V * S;
	//float m = V - C;


	while (true)
	{
		frameStart = SDL_GetTicks();

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

				int brightness = map(n, 0, maxIteration, 30, 330);

				if (n == maxIteration)
				{
					brightness = 0;
				}

				int red, green, blue;
				if (0 < brightness && brightness < 120)
				{
					red = 255 - map(brightness, 0, 120, 0, 255);
					green = map(brightness, 0, 120, 0, 255);
					blue = 0;
				}
				else if (120 <= brightness && brightness < 240)
				{
					red = 0;
					green = 255 - map(brightness, 120, 240, 0, 255);
					blue = map(brightness, 120, 240, 0, 255);
				}
				else if (240 <= brightness && brightness < 360)
				{
					red = map(brightness, 240, 360, 0, 255);
					green = 0;
					blue = 255 - map(brightness, 240, 360, 0, 255);
				}
				else
				{
					red = 0;
					green = 0;
					blue = 0;
				}

				/*int red = brightness;
				int green = map(brightness * brightness, 0, 255 * 255, 0, 255);
				int blue = map(sqrt(brightness), 0, sqrt(255), 0, 255);*/

				/*int red   = 255 * (_R + m);
				int green = 255 * (_G + m);
				int blue  = 255 * (_B + m);*/

				SDL_SetRenderDrawColor(renderer, red, green, blue, 255);
				SDL_RenderDrawPoint(renderer, i, j);
			}
		}

		
		if (SDL_PollEvent(&event) && event.type == SDL_QUIT) 
			break;

		//maxIteration = max(10, maxIteration - 10);

		/*frameTime = SDL_GetTicks() - frameStart;
		if (framedelay > frameTime)
			SDL_Delay(framedelay - frameTime);*/
	}

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	return 0;
}