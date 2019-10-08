#include "hwlib.hpp"

using hwlib::cout;

extern "C" void uart_put_char(char c) {
  cout << c;
}

extern "C" void decompres();

int main(void) {
  namespace target = hwlib::target;

  // wait for the PC console to start
  hwlib::wait_ms(1000);
  decompres();
}