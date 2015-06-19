#ifndef FILE_ALGEBRA_H
#define FILE_ALGEBRA_H

/*
A vector that has 3 floating-point variable.
*/
typedef struct float_vect3{
	
	float x, y, z;

}float_vect3;

static inline float_vect3 float_vect3_init(float x, float y, float z)
{
	float_vect3 v = {x, y, z};
	return v;
}
/*
a + b
*/
static inline float_vect3 float_vect3_add(const float_vect3 *a, const float_vect3 *b)
{
	float_vect3 v = { a->x + b->x, a->y + b->y, a->z + b->z};
	return v;
}
/*
a - b
*/
static inline float_vect3 float_vect3_sub(const float_vect3 *a, const float_vect3 *b)
{
	float_vect3 v = { a->x - b->x, a->y - b->y, a->z - b->z};
	return v;
}
/*
a*s
*/
static inline float_vect3 float_vect3_scale(const float_vect3 *a, float s)
{
	float_vect3 v = {a->x * s, a->y * s, a->z * s};
	return v;
}
/*
a dot b
*/
static inline float float_vect3_dot(const float_vect3 *a, const float_vect3 *b)
{
	return ( a->x*b->x + a->y*b->y + a->z*b->z);
}
/*
the length of this vector
*/
static inline float float_vect3_length(const float_vect3 *a)
{
	return sqrtf(a->x * a->x + a->y * a->y + a->z * a->z);
}
/*
normalize 
*/
static inline float_vect3 float_vect3_normalize(const float_vect3 *a)
{
	float u = 1.0f/sqrtf(a->x * a->x + a->y * a->y + a->z * a->z);
	float_vect3 v = {a->x * u, a->y * u, a->z * u};
	return v;
}
#endif