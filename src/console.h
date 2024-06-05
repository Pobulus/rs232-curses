#ifndef console_H
#define console_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>

struct vec2 {
    int x, y;
};
/**
 * Struktura przechowująca ciągi znaków, które konsola używa do wyświetlania określonych elementów
 */
struct Font {
    std::string hLine; ///< pionowa linia
    std::string vLine; ///< pozioma linia
    std::string corNW; ///< lewy góny róg
    std::string corNE; ///< prawy górny róg
    std::string corSW; ///< lewy dolny róg
    std::string corSE; ///< prawy dolny róg

};


enum keyCode {
    NONE = -1,
    UNKNOWN = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN,
    SELECT,
    QUIT,
    SEND,
    REFRESH,
    PAUSE    
};
inline std::ostream& operator << ( std::ostream& o, const keyCode& K )
{
    switch ( K ) {
    case SELECT:
        o << "select";
        break;
    case LEFT:
        o << "left";
        break;
    case RIGHT:
        o << "right";
        break;
    case UP:
        o << "up";
        break;
    case DOWN:
        o << "down";
        break;
    case SEND:
        o << "send";
        break;
    case PAUSE:
        o << "pause";
        break;
    case REFRESH:
        o << "pause";
        break;
    case QUIT:
        o << "pause";
        break;
    default:
        o << "unknown";
    };
    return o;
}

inline std::istream& operator >> (std::istream& i, keyCode& K)
{
    K = UNKNOWN;
    std::string S;
    if(i >> S)
    {
        if(S=="right")K = RIGHT;
        else if(S=="left")K = LEFT;
        else if(S=="up")K = UP;
        else if(S=="down")K = DOWN;
        else if(S=="quit")K = QUIT;
        else if(S=="send")K = SEND;
        else if(S=="refresh")K = REFRESH;
        else if(S=="pause")K = PAUSE;
        else if(S=="select")K = SELECT;

    }
    return i;
}

/**
 * Konsola, która wyświetla dane na ekranie i wczytuje wejście z klawiatury
 */
class Console {
    std::map<int, keyCode> bindings;
    int height;
    int width;
    int offsetX=0;
    int offsetY=0;
    Font font = {"-", "|", "+","+", "+", "+"};
    void clear_abs(int x, int y, int w=1, int h=1) noexcept;
public:
    Console(const std::string& keybind_filename) noexcept;
    ~Console() noexcept;
    keyCode getInput() noexcept;
    void wait() const noexcept;
    void rebind(const std::string& keybind_filename) noexcept;
    void setTimeout(const int delay) noexcept;
    void clear(const int x, const int y, const int w=1, const int h=1) noexcept;
    void clear() const noexcept;
    void resize() noexcept;
    void setFont(const Font &f) noexcept
    {
        font = f;
    }
    Font getFont() const noexcept{
        return font;
    }
    int getWidth() const noexcept
    {
        return width;
    }
    int getHeight() const noexcept
    {
        return height;
    }
    void move(const int x, const int y) noexcept;
    vec2 getPosition() const noexcept;
    void print(const std::string& s) noexcept;
    void print(const std::string& s, const short int c) noexcept;
    void print_highlight(const std::string& s) noexcept;
    std::string prompt(std::string question, int limit = 0) noexcept;
    std::string promptUntilCorrect(std::string question, bool (*validator)(std::string), int limit = 0) noexcept;
    int prompt_key(std::string question) noexcept;
    void printCenter(std::string s, int y, bool h=false) noexcept;

};



#endif // console_ASCII_H
