#include <stdio.h>
#include "multiply.h"

#define LEVEL 2

float celsius_to_fahrenheit(float celsius)
{
	return celsius * 9 / 5 + 32;
}

float celsius_to_kelvin(float celsius)
{
	return celsius + 273.15f;
}

void runhens()
{
	int hens = 4;
	static int eggs = 4;  // cannot be assigned as 'eggs = hens' because hens in not yet defined until compilation

	hens += 1;
	eggs += 1;

	printf("%d %d\n", hens, eggs);
}

void tramplehens()
{
	int a = 123;
	int b = 123;
}

typedef unsigned char byte;		// typedef a type of 'byte' to be considered an 'unsigned char' which is normally used to express... well... bytes.

int main()
{
	float celsius = 0;

	// Calls functions in this
	while (celsius < 100)
	{
		celsius = celsius + 10;

		printf("%.2f C = %.2f F = %.2f K\n", celsius, celsius_to_fahrenheit(celsius), celsius_to_kelvin(celsius));
	}

	// Using function declared in multiply.h
	multiply(4, 5);

	/* 
	This #if/#define/#endif type of code will evaluate this code at pre-compile time.  
	If needed (aka pass #if test), the code will be included.
	If not needed (aka fail #if test), the code will be deleted and won't even be compiled.
	This could greatly increase code quality by removing unneeded code... hense the !defined(RUNFAST) definition switch.
	*/

	#if LEVEL > 0
	SQUARE(9);
	#endif

	#if !defined(RUNFAST)
	SQUARE(9);
	#endif

	printf("4 * 5 = %d\n", multiply(4, 5));


	/* Declarations */
	runhens();
	runhens();
	runhens();

	/* Types */
	int i = 123;
	float f = 1.23f;
	double d = 2.34;
	char c = 'c';
	unsigned int ui = 123u;		//usually 32-bit on 32-bit machines
	short int si = 123;			//half max bit of machine (ex: 16 or 32)
	long int li = 123;			//max bit of machine	(ex: 32 or 64)

	byte b = 0x12;				//typedef unsigned char byte;

	return 0;
}