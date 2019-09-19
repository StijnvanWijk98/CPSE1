#include "note_player_native.hpp"

void note_player_native::setup() {
  writefile.open("melody.cpp");
  writefile << "#include \"melody.hpp\"\n";
  writefile << "class auto_melody : public melody {\n";
  writefile << "public:\n";
  writefile << "  void play( note_player & p ){\n";
  writefile.close();
}
void note_player_native::close() {
  cout << "In melody.cpp";
  writefile.open("melody.cpp", ofstream::app);
  writefile << "  }\n";
  writefile << "};";
  writefile.close();
}

void note_player_native::play(const note& n) {
  if (firstPlay) {
    cout << "Call setup" << endl;
    setup();
    firstPlay = false;
  }
  writefile.open("melody.cpp", ofstream::app);
  writefile << "    p.play( note{ " << n.frequency << " , " << n.duration << " } );\n";
  writefile.close();
}