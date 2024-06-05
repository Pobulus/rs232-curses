#pragma once
#include "console.h"

using namespace std;
 class IInput {
protected:
    vec2 position;
    string label;
public:
    IInput(vec2 position, string label) : position(position), label(label) {}
    void move(vec2 d){
        position.x += d.x;
        position.y += d.y;
    }    
    virtual ~IInput() {};
    virtual void drawOn(Console &con, bool highlight=false){};
    virtual void editValue(Console &con){};
};
