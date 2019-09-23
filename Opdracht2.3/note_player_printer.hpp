#ifndef _NOTE_PLAYER_PRINTER_HPP
#define _NOTE_PLAYER_PRINTER_HPP

#include "note_player.hpp"
#include "hwlib.hpp"

using hwlib::cout;
using hwlib::endl;

class note_player_printer : public note_player {
public:
   void play( const note & n ) override;
};

#endif
