/* Copyright 2013, Garbanzo Prime

    This file is part of armabipp.
    armabipp is subject to the license specified in LICENSE.txt
*/
extern "C" {
	void __aeabi_memset (void *dest, unsigned int n, int c);
}


//this memset is hellishly lazy, fix it please
void __aeabi_memset (void *dest, unsigned int n, int c) {
	asm volatile(
		"1: strb %[c], [%[dest]];"
		"add %[dest], %[dest] , #1;"
		"subs %[n], %[n], #1;"
		"bne 1b"
	: [dest]"=r"(dest) , [n]"=r"(n)
	: [dest]"r"(dest) , [n]"r"(n) , [c]"r"(c)
	: ) ;	
}
