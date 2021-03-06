#ifndef OLEDDISPLAY_HPP
#define OLEDDISPLAY_HPP

#include <hwlib.hpp>
#include "due-twi.hpp"


class OledDisplay {
private:
    hwlib::target::twi_bus_due twi_bus;
    hwlib::glcd_oled display = hwlib::glcd_oled( twi_bus, 0x3c );

    hwlib::font_default_8x8 font = hwlib::font_default_8x8();
    hwlib::window_ostream displayOstream = hwlib::window_ostream( display, font );

public:
    /**
     * @brief Constructor
     */
    OledDisplay() {};

    void layoutInitialstate();
    void layoutPlaystate();
    void layoutDonestate();
    void layoutLeaderstate();
    
    void dataInitialstate(int id, int live, int damage, int startTime, int gameTime);
    void dataPlaystate(int time, int playerId, int lives, int power);
    void dataDonestate();
    void dataLeaderstate(bool validInput, int commandId, int value, bool send);

    void clear(bool flush = false);
};

#endif // OLEDDISPLAY_HPP
