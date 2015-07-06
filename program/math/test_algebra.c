#include "algebra.h"
#include <stdio.h>


#define DEBUG_PRINT printf
#define DISPLAY_VECT3(_v) DEBUG_PRINT("[%f %f %f]'", _v.x, _v.y, _v.z)

int main()
{

	vect3 v1 = vect3_init(2,3,4), v2 = vect3_init(1.5,3.5,4.2), v3;
	/* test vector addition*/
	v3 = vect3_add(&v1, &v2);
	DISPLAY_VECT3(v1);
	DEBUG_PRINT(" + ");
	DISPLAY_VECT3(v2);
	DEBUG_PRINT(" = ");
	DISPLAY_VECT3(v3);
	DEBUG_PRINT("\r\n");
	/* test vector addition*/
	v3 = vect3_sub(&v1, &v2);
	DISPLAY_VECT3(v1);
	DEBUG_PRINT(" - ");
	DISPLAY_VECT3(v2);
	DEBUG_PRINT(" = ");
	DISPLAY_VECT3(v3);
	DEBUG_PRINT("\r\n");
	/* test vector scaling*/
	v3 = vect3_scale(&v1, 3);
	DISPLAY_VECT3(v1);
	DEBUG_PRINT(" * 3 = ");
	DISPLAY_VECT3(v3);
	DEBUG_PRINT("\r\n");
	/* test vector inner product */
	float f = vect3_dot(&v1, &v2);
	DISPLAY_VECT3(v1);
	DEBUG_PRINT(" _dot_ ");
	DISPLAY_VECT3(v2);
	DEBUG_PRINT("= %f \r\n",f);

	float v1_len = vect3_norm2( &v1);
	DEBUG_PRINT("length of ");
	DISPLAY_VECT3(v1);
	DEBUG_PRINT("= %f \r\n", v1_len);

	v3 = vect3_normalized( &v1);
	DEBUG_PRINT("normalized v1 = ");
	DISPLAY_VECT3(v3);
	DEBUG_PRINT("\r\n ");
	return 0;

}