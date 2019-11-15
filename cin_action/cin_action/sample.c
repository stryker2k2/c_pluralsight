#include <stdio.h>
#include <stdlib.h>		// allows use of malloc and atoi
#include <string.h>		// allows use of strerror and strlen and strcmp
#include <ctype.h>		// allows use of isalnum and tolower
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
	static int eggs = 4;  // static cannot be assigned as 'eggs = hens' because hens in not yet defined until compilation
	int newegg = hens;
	
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


/*	Structs are like Classes and Functions in Structs are like Methods and has it's own namespace 
	Struct = Public
	Class = Private
*/
struct Normal					// This is a normal struct.  In order to call this, you must call 'struct Normal n;'
{
	float X;
	float Y;
};

typedef struct					// This is a struct with typedef built in which removed the need to call 'struct Pixel p = { 10.0f, 20.0f };' later on... just call 'Pixel p = { 10.0f, 20.0f };'
{
	float X;
	float Y;
}Pixel;

typedef struct					// This is a struct with typedef built in which removed the need to call 'struct Color c;' later on; just call 'Color c;'
{
	byte Red;
	byte Green;
	byte Blue;
}Color;

typedef struct
{
	short first;	// [size: 02]		xx__    (occupys 2 bytes but is assigned 4 bytes for padding)
	int second;		// [size: 04]		xxxx    (occupys 4 bytes)
	short third;	// [size: 02]		xx__    (occupys 2 bytes but is assigned 4 bytes for padding)
					// [total size: 12]			(4 + 4 + 4)

	/* If...
	short first;	// [size: 02]		xx__    (occupys 2 bytes)
	short third;	// [size: 02]		__xx    (occupys 2 bytes)
	int second;		// [size: 04]		xxxx    (occupys 4 bytes)
					// [total size: 8]			(2 + 2 + 4)
	*/
}Layout;

typedef union		// Typedefs are pretty damn important.  Without it, you would have to call 'union.OneThingOrAnother'.
{
	int Integer;
	//float RealNumber;
	char Character;
}OneThingOrAnother;

typedef enum
{
	TheInteger = 10,
	TheCharacter = 20
}WhichThing;

int * PrintArray(int* begin, int end)
{
	if (begin == end)
	{
		return 0;
	}

	int* largest = begin;

	for (; begin != end; ++begin)
	{
		printf("%d\n", *begin);

		if (*largest < *begin)
		{
			largest = begin;
		}
	}

	return largest;
}

int StringLength(char* string)
{
	int length = 0;

	while (*string++)		//while *string != 0 [aka NULL terminator]
	{
		++length;
	}

	return length;
}

void MinMax(int * begin, int * end, int ** val_smallest, int ** val_largest)
{
	if (begin == end)
	{
		*val_smallest = 0;
		*val_largest = 0;
	}
	else
	{
		*val_smallest = *val_largest = begin;

			while (++begin != end)
			{
				if (*begin < **val_smallest)
				{
					*val_smallest = begin;			// Notice the double-dereference.  We are comparing values but only updating pointers!
				}

				if (*begin > ** val_largest)
				{
					*val_largest = begin;
				}
					
			}
	}
}

int main()
{
	float celsius = 0;

	printf("\nWhile Loop:\n");
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

	printf("\nCalling Functions:\n");
	printf("4 * 5 = %d\n", multiply(4, 5));


	/* Declarations */
	printf("\nDeclarations:\n");
	runhens();
	runhens();
	runhens();

	/* Types */
	printf("\nTypes:\n");
	int i = 123;
	float f = 1.23f;
	double d = 2.34;
	char ch = 'c';
	unsigned int ui = 123u;		//usually 32-bit on 32-bit machines
	short int si = 123;			//half max bit of machine (ex: 16 or 32)
	long int li = 123;			//max bit of machine	(ex: 32 or 64)

	byte b = 0x12;				//typedef unsigned char byte;

	printf("%d (%d)\n", i, (int) sizeof(int));


	/* Structures using pixels and colors for practice */
	Pixel p = { 10.0f, 20.0f };	//float x, y; defined in Pixel Struct
	Color c = { 255, 128, 0 };	//unsigned char red, green, blue; defined in Color Struct

	float x = p.X;
	c.Blue = 255;
	
	/* Structures */
	printf("\nStructures:\n");
	printf("short %d\n", (int) sizeof(short));
	printf("int %d\n", (int) sizeof(int));
	printf("struct %d\n", (int) sizeof(Layout));

	/* Unions */
	printf("\nUnions:\n");
	printf("int %d\n", (int) sizeof(int));
	//printf("float %d\n", (int) sizeof(float));
	printf("char %d\n", (int) sizeof(char));
	printf("aggregate %d\n", (int) sizeof(OneThingOrAnother));


	/* Enumerations with Unions */
	OneThingOrAnother var;
	var.Integer = 123;

	WhichThing type = TheInteger;
	printf("\nEnumerators:\n");
	printf("var %d type=%d\n", var.Integer, type);

	var.Character = 'V';
	type = TheCharacter;

	printf("var %d type=%d\n", var.Character, type);

	int width = 100;
	int height = 200;

	int area = width * height;

	/* Memory */
	int mem = 1234;
	int * pntr = 0;
	pntr = &mem;
	int jpt = *pntr;
	*pntr = 2345;

	printf("\nMemory:\n");
	printf("0x%p\n", &mem);
	printf("mem = %d / jpt = %d\n", mem, jpt);

	/* Pointers and Arrays */
	int numbz[] = { 1, 5, 4, 2, 3 };				// Have to determine size
	int numbz_size = sizeof(numbz) / sizeof(numbz[0]);

	int* nptr = numbz;
	int* end = nptr + numbz_size;

	printf("\nPointers:\n");
	for (i = 0; i < numbz_size; i++) // using numbz and nptr
	{
		printf("%d\n", numbz[i]);
		printf("%d\n", nptr[i]);
	}

	for (; nptr != end; ++nptr)
	{
		printf("%d\n", *nptr);
	}

	int a1 = *nptr;	// Dereferencing
	int a2 = *numbz;

	int * largest = PrintArray(numbz, numbz + numbz_size);

	if (largest)
	{
		printf("largest %d\n", *largest);
	}

	/* Strings */
	char* string = "Hello World";			// PRO: can change context
	char string_array[] = "Hello World";	// PRO: can ask for size, has NULL terminator  //CON: cannot change context
	
	printf("\nStrings:\n");
	printf("size %d\n", (int) sizeof(string_array));

	int length = 0;

	for (char* p = string_array; * p != 0; ++p)
	{
		++length;
	}

	printf("length %d\n", length);

	printf("%d\n", StringLength("Hello World"));
	printf("%d\n", StringLength(""));
	printf("%d\n", StringLength("Hi!"));

	/* Pointers to Pointers */
	int pvalue = 123;
	int* my_p = &pvalue;
	int* my_pp = &my_p;

	int values[] = { 5, 2, 4, 3, 6 };
	int size = sizeof(values) / sizeof(values[0]);

	int* val_smallest = 0;
	int* val_largest = 0;

	MinMax(values, values + size, &val_smallest, &val_largest);

	printf("\nPointers to Pointers:\n");
	printf("min = %d max = %d\n", *val_smallest, *val_largest);


	printf("\nPointers to Pointers:\n");
	int* m = (int*) malloc(4);

	if (!m)
	{
		return 1;  // No mem room available :(
	}

	*m = 42;
	int m_val = *m;	// "Dereferencing" and *m is no longer valid which might cause accidental freeing of new code occupying the mem space of *m if free(m) is called.
	free(m);
	m = 0;

	void* frame = malloc(1514);
	free(frame);
	frame = 0;		// Doing this ensures that frame is freed and NULL to prevent accidental modification of originally assigned memory space (will cause crash if called).

	char* message = (char*) malloc(141);
	free(message);
	message = 0;
	printf("{NULL}\n");

	/* printf */
	printf("\nPrintf:\n");
	printf("Using d: %d\n", 111222333444);
	printf("Using I64d: %I64d\n", 111222333444);
	printf("Using I64x: %I64x\n", 111222333444);
	printf("Using x: %x\n", 123);
	printf("Using X: %X\n", 123);
	printf("Using 0x: 0x%x\n", 123);
	printf("Using #X: %#X\n", 123);
	printf("Using #x: %#x\n", 123);
	printf("Using f: %f\n", 123.456);
	printf("Using .2f: %.2f\n", 123.456);
	printf("Using 10.2f: %10.2f\n", 123.456);
	printf("Using -10.2f: %-10.2f left-align\n", 123.456);
	printf("Using -10d  : %-10d left-align\n", 123456);

	char* msg = "Hello world, Goodbye cruel world!";
	printf("Using s: %s\n", msg);
	int sz = 11;
	printf("Using .*s: %.*s", sz, msg);

	/* Security and Sprintf_s */
	printf("\nSecurity and Sprint:\n");
	char* font = "Myriad Pro";
	int fsize = 32;
	char* my_msg = "Hello World";

	// sprintf 'prints' somewhere else that is not a console.  In this case, it 'prints' into the buffer.  Can also be used to concatenate strings.
	// This old sprintf display the string before crashing... thus allowing malicious use of memory past the buffer (aka buffer overflow).  Compiler suggest we use sprintf_s.
	// char buffer[50];
	// sprintf(buffer, "<html><body><p style='font-family:%s;font-size:%dpx'>%s</p></body></html>", font, size, my_msg);  
	
	// This will crash before the string is displayed because buffer is too small... thus preventing malicious use of memory (aka buffer overflow).
	//char buffer[50];
	//sprintf_s(buffer, sizeof(buffer), "<html><body><p style='font-family:%s;font-size:%dpx'>%s</p></body></html>", font, size, my_msg);
	//printf("%s\n", buffer);  

	// This will work because buffer is large enough.
	char buffer[500];
	sprintf_s(buffer, sizeof(buffer), "<html><body><p style='font-family:%s;font-size:%dpx'>%s</p></body></html>", font, size, my_msg);
	printf("%s\n", buffer);

	/* Scanf and Scanf_s*/
	printf("\nSecurity and Scanf:\n");
	
	// scanf is vulnerable to buffer overflow also!  
	// The world "Indoctrination" would surpass the buffer of [10] and crash after the program has been ran and '...tion' has been written past the buffer.
	// char amsg[10];
	// scanf("%s", amsg);

	// scanf_s will limit the input only to the 'sizeof(amsg)' buffer.  If input is over buffer size, only the first %9s will be saved.
	char amsg[10];
	printf("Type in your input[10]: ");
	scanf_s("%9s", amsg, sizeof(amsg));		// doing just %s will save NOTHING.  %9s saves first [9].
	printf("Input was: %s\n", amsg);

	/* Fprintf_s */
	printf("\nFprintf and Strerror:\n");
	FILE* file = 0;

	errno_t result = fopen_s(&file, "C:\\dev\\message.txt", "w");


	if (result != 0)
	{
		char buffer[100];
		strerror_s(buffer, sizeof(buffer), result);

		printf("%s (%d)\n", buffer, result);
		return result;

	}

	fprintf_s(file, "Hello World!\n");
	fclose(file);

	/* More Strings */
	printf("\nMore Strings using 'isSomething':\n");

	char* msg01 = "This string has an escape sequence and a NULL Terminator at the end.\n";
	char* msg02 = "The r escape sequence 'returns' to the beginning of the line and prints.\rThus overwriting previous string.";
	char* msg03 = "HTTP requires the r + n sequence.\r\n";
	char* msg04 = "Here is a \"escape quote\" with a \ttab\t and a file structure c:\\dev\\cin_action\\ and a website https://www.google.com\n";
	char* msg05 = "abcDefg\nhijk:lmnop\\qrsTuvwXyz!";

	printf(msg01);
	printf(msg02);
	printf(msg03);
	printf(msg04);

	for (char* p = msg05; *p; ++p)
	{
		char c = *p;
		printf("%c\t", c);

		if (isalnum(c))	printf("isalnum ");
		if (isalpha(c)) printf("isalpha ");
		if (islower(c)) printf("islower ");
		if (isupper(c)) printf("isupper ");
		if (isdigit(c)) printf("isdigit ");
		if (isxdigit(c)) printf("isxdigit ");
		if (iscntrl(c)) printf("iscntrl ");
		if (isgraph(c)) printf("isgraph ");
		if (isspace(c)) printf("isblank ");
		if (isprint(c)) printf("isprint ");
		if (ispunct(c)) printf("ispunct ");

		printf("\n");
	}

	/* More Strings using 'toSomething' */
	printf("\nMore Strings using 'toSomething':\n");
	char msg06[] = "Hello World!\n";
	for (char* p = msg06; *p; ++p)
	{
		if (isupper(*p)) *p = (char)tolower(*p);
		else if (islower(*p)) *p = (char)toupper(*p);
	}
	printf("Capilization Flip: \t%s",msg06);

	/* More Strings using 'atof and atoi' */
	printf("\nMore Strings using atof and atoi:\n");
	double d01 = atof("123.456");								//atof = ___ to Float
	int i01 = atoi("1234");										//atoi = ___ to Int
	printf("atof: %.3f \tatoi: %d\n", d01, i01);

	char* numbz01 = "12 0x123 101";
	char* next01 = numbz01;
	int first01 = strtol(next01, &next01, 10);					//strtol = String To Long			//strtol (string, pointer to next-to-last interpreted character, toBase10)
	int second01 = strtol(next01, &next01, 0);					//strtol = String To Long			//strtol (string, pointer to next-to-last interpreted character, auto-determine)
	int third01 = strtol(next01, &next01, 2);					//strtol = String To Long			//strtol (string, pointer to next-to-last interpreted character, binary)
	printf("first: %d\tsecond: %d\tthird: %d\n", first01, second01, third01);

	/* More Strings using 'strlen' */
	printf("\nMore Strings using 'strlen':\n");
	char* msg07 = "Hello World";
	printf("size: %d\n", (int)strlen(msg07));
	printf("Apples %d\n", strcmp(msg07, "Apples"));
	printf("Oranges %d\n", strcmp(msg07, "Oranges"));			//Greater than zero - It returns a value greater than zero when the matching character of left string has greater ASCII value than the character of the right string.
	printf("Hello World %d\n", strcmp(msg07, "Hello World"));
	printf("Hello World! %d\n", strcmp(msg07, "Hello World!"));




	/*	Other Notes:
		void Execute(char const * statement) const				// const - I'm soooo confused... like, wtf?  #TODO - research 'const'
	*/


	printf("\n\n");
	return 0;
}