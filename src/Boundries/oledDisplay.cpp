#include <hwlib.hpp>

#include "oledDisplay.hpp"

void OledDisplay::layoutInitialstate() {
    for(int i = 0; i < 128; i++){
        display.write( hwlib::location( i, 0 ), hwlib::black );
    }
    for(int i = 0; i < 128; i++){
        display.write( hwlib::location( i, 63 ), hwlib::black );
    }
    for(int i = 0; i < 64; i++){
        display.write( hwlib::location( 0, i ), hwlib::black );
    }
    for(int i = 0; i < 64; i++){
        display.write( hwlib::location( 127, i ), hwlib::black );
    }
    displayOstream 
    << "\t0303" << "Time:"
    << hwlib::flush;
}

void OledDisplay::layoutPlaystate() {
    for(int i = 0; i < 128; i++){
        display.write( hwlib::location( i, 0 ), hwlib::black );
    }
    for(int i = 0; i < 128; i++){
        display.write( hwlib::location( i, 63 ), hwlib::black );
    }
    for(int i = 0; i < 64; i++){
        display.write( hwlib::location( 0, i ), hwlib::black );
    }
    for(int i = 0; i < 64; i++){
        display.write( hwlib::location( 127, i ), hwlib::black );
    }
    for(int i = 0; i < 128; i++){
        display.write( hwlib::location( i, 19 ), hwlib::black );
    }
    for(int i = 0; i < 128; i++){
        display.write( hwlib::location( i, 44), hwlib::black );
    }
    for(int i = 0; i < 18; i++){
        display.write( hwlib::location( 52, i), hwlib::black );
    }
     for(int i = 20; i < 44; i++){
        display.write( hwlib::location( 84, i), hwlib::black );
    }
    displayOstream 
    << "\t0101" <<"ID:" << "\t0701" << "Lives:"
    << "\t0103" << "Kills:--" << "\t1103" << "Time:"
    << "\t0104" << "Power:"
    << "\t0106" << "Streak:--"
    << hwlib::flush;
}

void OledDisplay::layoutDonestate() {
    for(int i = 0; i < 128; i++){
        display.write( hwlib::location( i, 0 ), hwlib::black );
    }
    for(int i = 0; i < 128; i++){
        display.write( hwlib::location( i, 63 ), hwlib::black );
    }
    for(int i = 0; i < 64; i++){
        display.write( hwlib::location( 0, i ), hwlib::black );
    }
    for(int i = 0; i < 64; i++){
        display.write( hwlib::location( 127, i ), hwlib::black );
    }
    displayOstream 
    << "\t0303" << "Gameover!"
    << hwlib::flush;
}

void OledDisplay::dataInitialstate(int time) {
    displayOstream
    << "\t0903" << time
    << hwlib::flush;
}

void OledDisplay::dataPlaystate(int time, int playerId, int lives, int power) {
    displayOstream 
    << "\t0401" << playerId << "\t1301" << lives
    << "\t0704" << power << "\t1204" << time
    << hwlib::flush;
}

void OledDisplay::clear(bool flush) {
    display.clear();
    if(flush){
        display.flush();
    }
}