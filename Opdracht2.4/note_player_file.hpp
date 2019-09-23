#ifndef _NOTE_PLAYER_FILE_HPP
#define _NOTE_PLAYER_FILE_HPP

#include "note_player.hpp"
#include "hwlib.hpp"
#include "fstream"

using hwlib::cout;
using hwlib::endl;
using std::ofstream;

class note_player_file : public note_player {
   ofstream writefile;
   bool firstPlay = true;
public:
   void play( const note & n ) override;
   void setup();
   void close();

};

#endif


