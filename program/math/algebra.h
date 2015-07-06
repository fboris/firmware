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
#endif