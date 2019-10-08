#include "clock.hpp"

int main(void) {
  namespace target = hwlib::target;

  auto hour_plus = target::pin_in{target::pins::d25};
  auto minutes_plus = target::pin_in{target::pins::d24};
  auto change = target::pin_in{target::pins::d23};

  auto scl = target::pin_oc{target::pins::scl};
  auto sda = target::pin_oc{target::pins::sda};
  auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda(scl, sda);
  auto oled = hwlib::glcd_oled(i2c_bus);
  oled.clear();

  xy screensize = xy(128, 64);
  xy mid_point = screensize/2;
  constexpr auto sin_tab = lookup<360, ARRTYPE>(sinFromDeg);
  constexpr auto cos_tab = lookup<360, ARRTYPE>(cosFromDeg);

  auto test_clock = analogClock(mid_point, 30, sin_tab, cos_tab, hour_plus, minutes_plus);
  test_clock.updateClock(oled);
}