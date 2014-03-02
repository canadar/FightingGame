#ifndef VECTOR_2D_H
#define VECTOR_2D_H
#include <math.h>


class vector_2d
{
    public:
    
        float   x;
        float   y;
        
        vector_2d() {}
        
        vector_2d(float r, float s)
        {
            x = r;
            y = s;
        }

        vector_2d& Set(float r, float s)
        {
            x = r;
            y = s;
            return (*this);
        }
        
        float& operator [](long k)
        {
            return ((&x)[k]);
        }
        
        const float& operator [](long k) const
        {
            return ((&x)[k]);
        }
        
        vector_2d& operator +=(const vector_2d& v)
        {
            x += v.x;
            y += v.y;
            return (*this);
        }
        
        vector_2d& operator -=(const vector_2d& v)
        {
            x -= v.x;
            y -= v.y;
            return (*this);
        }
        
        vector_2d& operator *=(float t)
        {
            x *= t;
            y *= t;
            return (*this);
        }
        
        vector_2d& operator /=(float t)
        {
            float f = 1.0F / t;
            x *= f;
            y *= f;
            return (*this);
        }
        
        vector_2d& operator &=(const vector_2d& v)
        {
            x *= v.x;
            y *= v.y;
            return (*this);
        }
        
        vector_2d operator -(void) const
        {
            return (vector_2d(-x, -y));
        }
        
        vector_2d operator +(const vector_2d& v) const
        {
            return (vector_2d(x + v.x, y + v.y));
        }
        
        vector_2d operator -(const vector_2d& v) const
        {
            return (vector_2d(x - v.x, y - v.y));
        }
        
        vector_2d operator *(float t) const
        {
            return (vector_2d(x * t, y * t));
        }
        
        vector_2d operator /(float t) const
        {
            float f = 1.0F / t;
            return (vector_2d(x * f, y * f));
        }
        
        float operator *(const vector_2d& v) const
        {
            return (x * v.x + y * v.y);
        }
        
        vector_2d operator &(const vector_2d& v) const
        {
            return (vector_2d(x * v.x, y * v.y));
        }
        
        bool operator ==(const vector_2d& v) const
        {
            return ((x == v.x) && (y == v.y));
        }
        
        bool operator !=(const vector_2d& v) const
        {
            return ((x != v.x) || (y != v.y));
        }
        
        vector_2d& Normalize(void)
        {
            return (*this /= sqrtf(x * x + y * y));
        }
        
        vector_2d& Rotate(float angle);
};

#endif