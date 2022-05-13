#include "math_func.h"
#include "math.h"


// Function which returns the squared length of the difference of two vectors
float length_squared(Vector2 u, Vector2 v) {
    return ((u.x - v.x) * (u.x - v.x) + (u.y - v.y) * (u.y - v.y));
}


// Function which returns the scalar product of two vectors
float dot(Vector2 u, Vector2 v) {
    return u.x * v.x + u.y * v.y;
}


// Function that returns the addition of two vectors
Vector2 addition(Vector2 u, Vector2 v) {
    return {u.x + v.x, u.y + v.y};
}


// Function returns the substraction of two vectors
Vector2 substraction(Vector2 u, Vector2 v) {
    return {u.x - v.x, u.y - v.y};
}


// Function which returns the maximum of the two floats
float max(float a, float b) {
    return (a < b) ? b : a; 
}


// Function which returns the minimum of the two floats
float min(float a, float b) {
    return !(b < a) ? a : b;
}


// Function which returns a vector multiplied by a scalar
Vector2 scale_vector(Vector2 v, float s) {
    return {v.x * s, v.y * s};
}


// Function which returns the round value of a number
double round_number(double d)
{
  return floor(d + 0.5);
}