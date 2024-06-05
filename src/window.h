#pragma once
#include "Input.hpp"
#include "dial.h"
#include <vector>
#include <memory>
using namespace std;

class Window {
    vec2 position, size;
    string name;
    
    string content;
    vector<string> visibleBuff;
    vector<shared_ptr<IInput>> inputs;
    Dial selected;
public:
    Window(vec2 p, vec2 s,  string name = "") : position(p), size(s), name(name) {
        selected = {0,0,0};
    }
    void drawFrameOn(Console &con, short int color = 0) {
        con.move(position.x, position.y); for(int x = 0; x < size.x; x++) con.print(con.getFont().hLine, color);
        if(name.size()){
            con.move(position.x+1, position.y); con.print("["+name+"]", color);
        }
        con.move(position.x, position.y+size.y); for(int x = 0; x < size.x; x++) con.print(con.getFont().hLine, color);
        for(int y = position.y; y <= size.y; y++) {con.move(position.x, y);  con.print(con.getFont().vLine, color); }
        for(int y = position.y; y <= size.y; y++) { con.move(position.x+size.x, y);  con.print(con.getFont().vLine, color); }
        con.move(position.x, position.y); con.print(con.getFont().corNW, color);
        con.move(position.x+size.x, position.y); con.print(con.getFont().corNE, color);
        con.move(position.x, position.y+size.y); con.print(con.getFont().corSW, color);
        con.move(position.x+size.x, position.y+size.y); con.print(con.getFont().corSE, color);
    }
    void drawOn(Console &con){
        con.clear(position.x+1, position.y+1, size.x-1, size.y-2);
        
        for(size_t i = 0; i < visibleBuff.size(); i++){
            con.move(position.x+1, position.y+1+i);
            con.print(visibleBuff[i]);    
        }
        for(int i = 0; i < (int)inputs.size(); i++){
            inputs[i]->drawOn(con, (i==selected));
        }
        con.move(position.x,position.y);
        con.print(std::to_string(selected));
        
    }
    void setContent(string c){
        content = c;
        string temp = c;
        visibleBuff.clear();
        while(temp.size() >(size_t)size.x-2){
            visibleBuff.push_back(temp.substr(0, size.x-1));
            temp = temp.substr(size.x-1);
        }
        visibleBuff.push_back(temp);
        
    }
    void addInput(shared_ptr<IInput> input){
        input->move(position);
        inputs.push_back(input);
        selected = {0, inputs.size()-1};
    }
    void processKey(keyCode c, Console &con){
        switch(c){
            case UP:
                selected--;
                 break;
            case DOWN:
                selected++;
                break;
            case SELECT:
                inputs[selected]->editValue(con);
                break;
            default:
                break;
        }
    }
};
