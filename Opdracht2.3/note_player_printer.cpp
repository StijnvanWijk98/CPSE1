#include "note_player_printer.hpp"

void note_player_printer::play(const note& n) {
  if (n.frequency > 0)
    cout << "Freq: " << n.frequency << ", duration: " << n.duration << endl;
}