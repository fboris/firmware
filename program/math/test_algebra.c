#include "algebra.h"
#include <stdio.h>


#define DEBUG_PRINT printf
#define DISPLAY_VECT3(_v) DEBUG_PRINT("[%f %f %f]'", _v.x, _v.y, _v.z)
#define DISPLAY_MAT33(_m) DEBUG_PRINT("[%f %f %f\r\n%f %f %f\r\n%f %f %f]\r\n", _m.m00, _m.m01, _m.m02, \
									    _m.m10, _m.m11, _m.m12, \
									    _m.m20, _m.m21, _m.m22)

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

	mat33 m = mat33_init(1.1f, 1.2f, 1.3f, 1.4f, 1.5f, 1.6f, 1.7f, 1.8f, 1.9f);
	DEBUG_PRINT("show m:\r\n");
	DISPLAY_MAT33(m);
	DEBUG_PRINT("\r\n");

	m = mat33_identity();
	DEBUG_PRINT("show 3X3 identity matrix:\r\n");
	DISPLAY_MAT33(m);
	DEBUG_PRINT("\r\n");

	m = mat33_diag(1.4f, 5.5f, 6.6f);
	DEBUG_PRINT("show 3X3 diagonal matrix:\r\n");
	DISPLAY_MAT33(m);

	mat33 m1 = mat33_init(1.1f, 1.2f, 1.3f, 1.4f, 1.5f, 1.6f, 1.7f, 1.8f, 1.9f);
	mat33 m2 = mat33_init(2.1f, 2.2f, 2.3f, 2.4f, 2.5f, 2.6f, 2.7f, 2.8f, 2.9f);
	mat33 m_out;

	mat33_add( &m_out, &m1, &m2);
	DEBUG_PRINT( "show m1 + m2:\r\n");
	DISPLAY_MAT33( m1);
	DEBUG_PRINT( "+\r\n");
	DISPLAY_MAT33( m2);
	DEBUG_PRINT( "=");
	DISPLAY_MAT33( m_out);

	mat33_multiply( &m_out, &m1, &m2);
	DEBUG_PRINT("m1*m2 = \r\n");
	DISPLAY_MAT33( m_out);

	mat33_transpose( &m_out, &m1);
	DEBUG_PRINT("m1' = \r\n");
	DISPLAY_MAT33( m_out);
	return 0;

}