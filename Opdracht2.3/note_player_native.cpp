#include "note_player_native.hpp"

void note_player_native::play(const note& n) {
  if (n.frequency > 0)
    cout << "Freq: " << n.frequency << ", duration: " << n.duration << endl;
}