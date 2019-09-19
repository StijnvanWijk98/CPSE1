#ifndef _NOTE_PLAYER_NATIVE_HPP
#define _NOTE_PLAYER_NATIVE_HPP

#include "note_player.hpp"
#include "hwlib.hpp"

using hwlib::cout;
using hwlib::endl;

class note_player_native : public note_player {
public:
   void play( const note & n ) override;
};

#endif
