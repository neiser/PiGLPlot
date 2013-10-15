﻿#ifndef GLTOOLS_H
#define GLTOOLS_H
#include "system.h"
#include "Structs.h"

class Vector2 {
private:
    vec2_t _v;

public:

    Vector2( const vec2_t& v ): _v(v) {}
    Vector2( const float& x=0.0f, const float& y=0.0f ) {
        _v.x = x;
        _v.y = y;
    }

    const vec2_t& Stuct() const { return _v; }

    const float& X() const { return _v.x; }
    const float& Y() const { return _v.y; }

    float& X() { return _v.x; }
    float& Y() { return _v.y; }

    void operator+= ( const Vector2& v ) { _v.x = v.X(); _v.y += v.Y(); }

};

class Color {
private:
    GLfloat _color[4];

public:
    Color( const float r=0, const float g=0, float b=0, float a=1.0f) {
        _color[0] = r;
        _color[1] = g;
        _color[2] = b;
        _color[3] = a;
    }

    inline float& Red()   { return _color[0]; }
    inline float& Green() { return _color[1]; }
    inline float& Blue()  { return _color[2]; }
    inline float& Alpha() { return _color[3]; }

    inline void Activate() { glColor4fv( _color ); }

};

#define kRed    Color(1.0f, 0.0f, 0.0f)
#define kGreen  Color(0.0f, 1.0f, 0.0f)
#define kBlue   Color(0.0f, 0.0f, 1.0f)
#define kWhite  Color(1.0f, 1.0f, 1.0f)
#define kBlack  Color(0.0f, 0.0f, 0.0f)
#define kPink   Color(1.0f, 0.0f, 1.0f)
#define kYellow Color(1.0f, 1.0f, 0.0f)
#define kCyan   Color(0.0f, 1.0f, 1.0f)

#define dTextColor  kWhite
#define dBackColor  kBlack


class Rectangle {
private:
    float _width;
    float _height;
    Vector2 _center;
    vec2_t _vertices[4];

    void _update_vertices();

public:
    Rectangle( const float x1, const float y1, const float x2, const float y2 );
    Rectangle( const Vector2& center, const float width, const float height);

    virtual ~Rectangle() {}

    float Width() const { return _width; }
    float Height() const { return _height; }

    const Vector2& Center() const { return _center; }

    void SetCenter( const Vector2& center );
    void SetWidth( const float width );
    void SetHeight( const float height );

    void Draw( GLenum mode );

};



#endif
