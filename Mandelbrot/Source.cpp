//#include <cmath>
//#include <iostream>
//#include <windows.h>
//using namespace std;
//#define MAX_CHECK 150
//#define SIZE_and_ACCURACY 0.004
//#define OFFSETX 600
//#define OFFSETY 600
//
//struct Complex 
//{
//	double a, b;
//};
//
//Complex plusComplex(Complex phuc1, Complex phuc2) 
//{
//	Complex c;
//	c.a = phuc1.a + phuc2.a;
//	c.b = phuc1.b + phuc2.b;
//	return c;
//}
//
//Complex mulComplex(Complex phuc1, Complex phuc2) 
//{
//	Complex c;
//	c.a = phuc1.a * phuc2.a - phuc1.b * phuc2.b;
//	c.b = phuc1.a * phuc2.b + phuc1.b * phuc2.a;
//	return c;
//}
//
//double complexLength(Complex phuc) 
//{
//	return sqrt(phuc.a * phuc.a + phuc.b * phuc.b);
//}
//
//bool Try(Complex c) 
//{
//	Complex z{ 0,0 };
//	for (int i = 0; i < MAX_CHECK; i++) 
//	{
//		if (complexLength(z) > 2)return false;
//		z = plusComplex(mulComplex(z, z), c);
//	}
//	return true;
//}
//
//HDC hdc = GetDC(GetConsoleWindow());
//void DrawMandelbrot() 
//{
//	for (double i = -2; i <= 2; i += SIZE_and_ACCURACY) 
//	{
//		for (double j = -2; j <= 2; j += SIZE_and_ACCURACY) 
//		{
//			Complex c{ i,j };
//			if (Try(c))
//				SetPixel(hdc,
//					OFFSETX + int(i * (1 / SIZE_and_ACCURACY)),
//					OFFSETY + int(j * (1 / SIZE_and_ACCURACY)),
//					RGB(255, 255, 255));
//		}
//	}
//}
//
//int main() 
//{
//	system("mode 120, 50");
//	DrawMandelbrot();
//	return 0;
//}