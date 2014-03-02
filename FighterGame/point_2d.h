#pragma once
#ifndef POINT_2D_H
#define POINT_2D_H
#include "vector_2d.h"

class point_2d : public vector_2d
{
    public:
        
        point_2d() {}
        
        point_2d(float r, float s) : vector_2d(r, s) {}
        
        point_2d& operator =(const vector_2d& v)
        {
            x = v.x;
            y = v.y;
            return (*this);
        }
        
        point_2d& operator *=(float t)
        {
            x *= t;
            y *= t;
            return (*this);
        }
        
        point_2d& operator /=(float t)
        {
            float f = 1.0F / t;
            x *= f;
            y *= f;
            return (*this);
        }
        
        point_2d operator -(void) const
        {
            return (point_2d(-x, -y));
        }
        
        point_2d operator +(const vector_2d& v) const
        {
            return (point_2d(x + v.x, y + v.y));
        }
        
        point_2d operator -(const vector_2d& v) const
        {
            return (point_2d(x - v.x, y - v.y));
        }
        
        vector_2d operator -(const point_2d& p) const
        {
            return (vector_2d(x - p.x, y - p.y));
        }
        
        point_2d operator *(float t) const
        {
            return (point_2d(x * t, y * t));
        }
        
        point_2d operator /(float t) const
        {
            float f = 1.0F / t;
            return (point_2d(x * f, y * f));
        }
};


inline vector_2d operator *(float t, const vector_2d& v)
{
    return (vector_2d(t * v.x, t * v.y));
}

inline point_2d operator *(float t, const point_2d& p)
{
    return (point_2d(t * p.x, t * p.y));
}

inline float Dot(const vector_2d& v1, const vector_2d& v2)
{
    return (v1 * v2);
}

inline float Magnitude(const vector_2d& v)
{
    return (sqrtf(v.x * v.x + v.y * v.y));
}

inline float InverseMag(const vector_2d& v)
{
    return (1.0F / sqrtf(v.x * v.x + v.y * v.y));
}

inline float SquaredMag(const vector_2d& v)
{
    return (v.x * v.x + v.y * v.y);
}


struct Origin2D_
{
    const point_2d& operator +(const vector_2d& v)
    {
        return (static_cast<const point_2d&>(v));
    }
    
    point_2d operator -(const vector_2d& v)
    {
        return (point_2d(-v.x, -v.y));
    }
};


extern Origin2D_ Origin2D;

#endif