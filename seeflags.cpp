//-------------------------------------------------------------------
//	seeflags.cpp
//
//	This program shows how we can use 'inline' assembly language
//	to peek at the value in the x86 processor's RFLAGS register.
//	In particular, the 2-bit IOPL-field is separately displayed.
//
//		to compile:  $ g++ seeflags.cpp -o seeflags
//		to execute:  $ ./seeflags
//
//	programmer: ALLAN CRUSE
//	written on: 20 APR 2009
//-------------------------------------------------------------------

#include <stdio.h>	// for printf() 

long long	rflags_image = ~0;

int main( int argc, char **argv )
{
	// transfer the image of the RFLAGS register to a global variable
	asm(" pushfq \n popq rflags_image ");

	// display the values of the variable and its 2-bit IOPL-subfield
	printf( "\n    RFLAGS = 0x%016llX ", rflags_image ); 
	printf( " IOPL = %X \n\n", (unsigned int)(rflags_image >> 12)&3 );
}

