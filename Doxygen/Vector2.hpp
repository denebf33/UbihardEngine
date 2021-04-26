/**
 *@file Vector2.hpp
 *@brief Defination of Vector2
 *@details Contains basical funtion to describe two dimension surface
 */
#ifndef Vector2_hpp
#define Vector2_hpp

#include <stdio.h>
#include <math.h>
#include <iostream>
/**
 *@brief Defination of Vector2
 *@details Contains basical funtion to describe two dimension surface
 */
class Vector2
{
public:
    /**
     *@brief Default constructor of Vector2
     */
    Vector2();
    
    /**
     *@brief Constructor of Vector2
     *@param x the first dimension of Vector2
     *@param y the second dimension of Vector2
     */
    Vector2(float x, float y);
    
    Vector2 operator+(Vector2 const& rhs);
    
    Vector2& operator+=(Vector2 const& rhs);
    
    Vector2 operator-(Vector2 const& rhs);
    
    Vector2& operator-=(Vector2 const& rhs);
    
    Vector2 operator-();
    
    Vector2 operator*(float rhs);
    
    friend std::ostream& operator << (std::ostream & os, const Vector2 & vec)
    {
        os<<"("<<vec.x<<","<<vec.y<<")";
        return os;
    }
    
    /**
     *@brief normalize the vector2
     *@return a vector with magnitude of 1
     */
    Vector2 normalize();
    
    /**
     *@brief get the length of the vecoer
     *@return the length of the vector
     */
    float magnitude();
    
    /**
     *@brief get the distance between two points
     *@param a the first point
     *@param b the second point
     */
    static float distance(Vector2 a, Vector2 b);
    
    /**
     *@brief get the angle between two vectors, 0-180
     *@param a the first point
     *@param b the second point
     */
    static float angle(Vector2 a, Vector2 b);
    
    float x;///first dimension
    float y;///second dimension
    
    static Vector2 up;
    
    static Vector2 left;
    
private:
    
};

#endif /* Vector2_hpp */
