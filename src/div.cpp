/* Copyright 2013, Garbanzo Prime

    This file is part of armabipp.
    armabipp is subject to the license specified in LICENSE.txt
*/

#include "kul/memory.hpp"

using namespace kul ;

extern "C" {
	int64_t __aeabi_uidivmod( unsigned int numerator, unsigned int denominator ) ;
	uint32_t __aeabi_uidiv( unsigned int numerator , unsigned int denominator ) ;
	uint32_t __umodsi3( uint32_t numerator , uint32_t denominator ) ;
}

struct uidiv_return {
	unsigned int qot ;
	unsigned int rem ;

	operator int64_t() const {
		return *reinterpret_cast<const int64_t*>(this) ; 
	}
} ;

unsigned int __aeabi_uidiv( unsigned int numerator , unsigned int denominator ) {
}

uint32_t __umodsi3( uint32_t numerator , uint32_t denominator ) {
	return 0 ;
}

int64_t __aeabi_uidivmod( unsigned int numerator, unsigned int denominator ) {
		unsigned int x = denominator ;
		unsigned int current_bit = 1 ;
		while( x < numerator ) {
			x <<= 1 ;
			current_bit <<= 1 ;
		}

		unsigned int result = 0 ;
		while( numerator >= denominator ) {
			if( x <= numerator ) {
				numerator -= x ;
				result |= current_bit ;
			}
			current_bit >>= 1 ;
			x >>= 1 ;
		}

	return uidiv_return{ result , numerator } ;
}
