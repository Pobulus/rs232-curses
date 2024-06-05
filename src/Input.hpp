#pragma once
#include "IInput.hpp"
using namespace std;
class StringInput : public IInput{
    string value;
public:
    StringInput(vec2 position, string label, string init) : IInput(position, label), value(init) {}
    string getValue() {return value;}
    void drawOn(Console &con, bool highlight){
        con.move(position.x, position.y);
        
        if(highlight) con.print_highlight(label+":__________");
        else con.print(label+":__________");
        con.move(position.x+label.size()+1, position.y);
        if(highlight) con.print_highlight(value);
        else  con.print(value);
    }
    void editValue(Console &con) {
        value = con.prompt(label);
    }
    ~StringInput() {}
    
};
