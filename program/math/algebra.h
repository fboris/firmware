#ifndef FILE_ALGEBRA_H
#define FILE_ALGEBRA_H
#include <math.h>
/*
A vector that has 3 floating-point variable.
*/
typedef struct vect3{

	float x, y, z;

}vect3;

static inline vect3 vect3_init(float x, float y, float z)
{
	vect3 v = {x, y, z};
	return v;
}
/*
a + b
*/
static inline vect3 vect3_add(const vect3 *a, const vect3 *b)
{
	vect3 v = { a->x + b->x, a->y + b->y, a->z + b->z};
	return v;
}
/*
a - b
*/
static inline vect3 vect3_sub(const vect3 *a, const vect3 *b)
{
	vect3 v = { a->x - b->x, a->y - b->y, a->z - b->z};
	return v;
}
/*
a*s
*/
static inline vect3 vect3_scale(const vect3 *a, float s)
{
	vect3 v = {a->x * s, a->y * s, a->z * s};
	return v;
}
/*
a dot b
*/
static inline float vect3_dot(const vect3 *a, const vect3 *b)
{
	return ( a->x*b->x + a->y*b->y + a->z*b->z);
}
/*
the length of this vector
*/
static inline float vect3_norm2(const vect3 *a)
{
	return sqrtf(a->x * a->x + a->y * a->y + a->z * a->z);
}
/*
normalize 
*/
static inline vect3 vect3_normalized(const vect3 *a)
{
	float u = 1.0f/sqrtf(a->x * a->x + a->y * a->y + a->z * a->z);
	vect3 v = {a->x * u, a->y * u, a->z * u};
	return v;
}

/*
A 3x3 matrix type
it is row-major order
*/
typedef struct mat33{
	union{
		float m[9];

		struct {
			float m00, m01, m02,
			      m10, m11, m12,
			      m20, m21, m22;
		};
	};
}mat33;

/*
initialize matrix
*/
static inline mat33 mat33_init( float m00, float m01, float m02,
				float m10, float m11, float m12,
				float m20, float m21, float m22)
{
	mat33 m = { m00, m01, m02,
		    m10, m11, m12,
	            m20, m21, m22};

	return m;
}

/*

3x3 identity matrix
  [ 1 0 0;
    0 1 0;
    0 0 1;]

*/

static inline mat33 mat33_identity()
{
	mat33 m = { 1.0f, 0.0f, 0.0f,
		    0.0f, 1.0f, 0.0f,
	            0.0f, 0.0f, 1.0f};
	return m;
}

/*

3x3 diagonal matrix
  [ m00  0   0;
    0    m11 0;
    0    0   m22;]

*/

static inline mat33 mat33_diag(float m00, float m11, float m22)
{
	mat33 m = { m00, 0.0f, 0.0f,
		    0.0f, m11, 0.0f,
	            0.0f, 0.0f, m22};

	return m;
}

/*
matrix addition
m_out = m1 + m2
*/

static inline void mat33_add(mat33 *m_out, const mat33 *m1, const mat33 *m2)
{
	m_out->m00 = m1->m00 + m2->m00;
	m_out->m01 = m1->m01 + m2->m01;
	m_out->m02 = m1->m02 + m2->m02;
	m_out->m10 = m1->m10 + m2->m10;
	m_out->m11 = m1->m11 + m2->m11;
	m_out->m12 = m1->m12 + m2->m12;
	m_out->m20 = m1->m20 + m2->m20;
	m_out->m21 = m1->m21 + m2->m21;
	m_out->m22 = m1->m22 + m2->m22;

}


/*
matrix subtraction
m_out = m1 - m2
*/

static inline void mat33_sub(mat33 *m_out, const mat33 *m1, const mat33 *m2)
{
	m_out->m00 = m1->m00 - m2->m00;
	m_out->m01 = m1->m01 - m2->m01;
	m_out->m02 = m1->m02 - m2->m02;
	m_out->m10 = m1->m10 - m2->m10;
	m_out->m11 = m1->m11 - m2->m11;
	m_out->m12 = m1->m12 - m2->m12;
	m_out->m20 = m1->m20 - m2->m20;
	m_out->m21 = m1->m21 - m2->m21;
	m_out->m22 = m1->m22 - m2->m22;

}

/*
matrix multiplication
m_out = m1*m2
*/

static inline void mat33_multiply(mat33 *m_out, const mat33 *m1, const mat33 *m2)
{
	m_out->m00 = m1->m00 * m2->m00 + m1->m01 * m2->m10 + m1->m02 * m2->m20;
	m_out->m01 = m1->m00 * m2->m01 + m1->m01 * m2->m11 + m1->m02 * m2->m21;
	m_out->m02 = m1->m00 * m2->m02 + m1->m01 * m2->m12 + m1->m02 * m2->m22;
	m_out->m10 = m1->m10 * m2->m00 + m1->m11 * m2->m10 + m1->m12 * m2->m20;
	m_out->m11 = m1->m10 * m2->m01 + m1->m11 * m2->m11 + m1->m12 * m2->m21;
	m_out->m12 = m1->m10 * m2->m02 + m1->m11 * m2->m12 + m1->m12 * m2->m22;
	m_out->m20 = m1->m20 * m2->m00 + m1->m21 * m2->m10 + m1->m22 * m2->m20;
	m_out->m21 = m1->m20 * m2->m01 + m1->m21 * m2->m11 + m1->m22 * m2->m21;
	m_out->m22 = m1->m20 * m2->m02 + m1->m21 * m2->m12 + m1->m22 * m2->m22;
}

/*
matrix transposed
m_out = m_in'
*/

static inline void mat33_transpose(mat33 *m_out, const mat33 *m_in)
{
	m_out->m[0] = m_in->m[0];
	m_out->m[1] = m_in->m[3];
	m_out->m[2] = m_in->m[6];
	m_out->m[3] = m_in->m[1];
	m_out->m[4] = m_in->m[4];
	m_out->m[5] = m_in->m[7];
	m_out->m[6] = m_in->m[2];
	m_out->m[7] = m_in->m[5];
	m_out->m[8] = m_in->m[8];
}

#endif