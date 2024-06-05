/**
 * @file tetris
 * @authors Paweł Chmielewski
 */
#include "Input.hpp"
#include "window.h"
#include "console.h"

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string.h>
#include <ctime>
#include <memory>

/**
 * Funkcja wyświetla wiadomoćć pomocy
 */
void helpMessage() {
    std::cout << "This is a console based rs232 terminal" << std::endl<< std::endl;
    std::cout << "OPTIONS:" << std::endl;
    std::cout << " -k <filename> \tto use custom key binds specified in a file" << std::endl;
    std::cout << " -h \t display this help message" << std::endl;
}

/**
 * Funkcja interpretuje argumenty podane podczas wywoływania programu
 */
bool parse_arguments(int argc, char* argv[], std::string& kb_file_name) {
    for (int i = 1; i < argc; i++) {
        if (not strcmp(argv[i], "-k")) { //key binds file
            kb_file_name = argv[i + 1];
        }
        else if (not strcmp(argv[i], "-h")) { //help message
            helpMessage();
            return true;
        }

    }
    return false;
}


int main(int argc, char* argv[]) {
    std::string kb_file_name="";
    if(parse_arguments(argc, argv, kb_file_name))
        return 1; //exit because of help helpMessage
    Console con(kb_file_name);
    Window test({1,1},{40, 20}, "Window 1");
    Window test2({41,1},{80, 20}, "Window 2");
    test.drawFrameOn(con, 2);
    test2.addInput(std::make_shared<StringInput>( vec2{1,1}, "Console", "" ));
    test2.addInput(std::make_shared<StringInput>( vec2{1,2}, "BaudRate", "" ));
    test2.drawFrameOn(con, 4);
    test.setContent("Hello world!aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    test.drawOn(con);
    test2.drawOn(con);
    // std::string  newContent = "uuuu"; // con.prompt("content?", 100);
    // test.setContent(newContent);
    test.drawOn(con);
    keyCode resp = con.getInput();
    while(resp != QUIT){
        con.move(0,1);
        con.print(std::to_string(resp));
        test2.processKey(resp, con);
        test2.drawOn(con);
        resp = con.getInput();        
    }
    
    con.print("Closed");
    // con.wait();
    return 0;
}

