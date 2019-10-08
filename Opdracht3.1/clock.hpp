#ifndef CLOCK_HPP
#define CLOCK_HPP

#include "lookup.hpp"

#define ARRTYPE float

using hwlib::circle;
using hwlib::color;
using hwlib::cout;
using hwlib::drawable;
using hwlib::endl;
using hwlib::line;
using hwlib::now_us;
using hwlib::pin_in;
using hwlib::window;
using hwlib::xy;
using std::array;

class clockTime {
 protected:
  uint64_t last_mear;
  uint64_t diff_time = 0;  // In microseconds
  unsigned int seconds = 0;
  unsigned int minutes = 0;
  unsigned int hours = 0;
  pin_in& but_hour_up;
  pin_in& but_min_up;

  void updateTime();
  void updateButton();

 public:
  clockTime(pin_in& but_hour, pin_in& but_min) : last_mear(0), but_hour_up(but_hour), but_min_up(but_min) {
    last_mear = now_us();
  }
  uint64_t getActual();
  void addToActual(int to_add);
};

class clockBase : public drawable {
 private:
  int radius;
  int dist_dot;
  lookup<360, ARRTYPE> sin_tab;
  lookup<360, ARRTYPE> cos_tab;

 public:
  clockBase() : drawable(xy(0, 0)) {}

  clockBase(xy mid, int radius, const lookup<360, ARRTYPE>& sin_tab, const lookup<360, ARRTYPE>& cos_tab)
      : drawable(mid), radius(radius), sin_tab(sin_tab), cos_tab(cos_tab) {
    dist_dot = radius / 7;
  }

  void draw(window& w) override;
};

class clockArm : public drawable {
 private:
  bool update_needed;
  bool first_draw;
  int length;
  lookup<360, ARRTYPE> sin_tab;
  lookup<360, ARRTYPE> cos_tab;
  bool hour;
  int deg_fac;
  int time_val = 0;
  xy old_end = xy(0, 0);

 public:
  clockArm() : drawable(xy(0, 0)) {}
  clockArm(xy mid, int length, const lookup<360, ARRTYPE>& sin_tab, const lookup<360, ARRTYPE>& cos_tab,
           bool hour = false)
      : drawable(mid), length(length), sin_tab(sin_tab), cos_tab(cos_tab), hour(hour) {
    if (hour) {
      deg_fac = 360 / 12;
    } else {
      deg_fac = 360 / 60;
    }
  }

  void draw(window& w) override;
  void update(int new_time, bool update);
};

class analogClock : public drawable, public clockTime {
 private:
  int radius;
  const lookup<360, ARRTYPE> sin_tab;
  const lookup<360, ARRTYPE> cos_tab;
  clockBase base;
  clockArm sec_arm;
  clockArm min_arm;
  clockArm hour_arm;
  bool first_draw = true;

 public:
  analogClock(xy loc, int radius, const lookup<360, ARRTYPE>& sin_tab, const lookup<360, ARRTYPE>& cos_tab,
              pin_in& but_1, pin_in& but_2)
      : drawable(loc),
        clockTime(but_1, but_2),
        radius(radius),
        sin_tab(sin_tab),
        cos_tab(cos_tab)
  {
    base = clockBase(loc, radius, sin_tab, cos_tab);
    sec_arm = clockArm(loc, radius - (radius / 4), sin_tab, cos_tab);
    min_arm = clockArm(loc, radius - (radius / 3), sin_tab, cos_tab);
    hour_arm = clockArm(loc, radius - (radius / 2), sin_tab, cos_tab, true);
  }

  void draw(window& w) override;
  void updateClock(window& w);
};

class binaryClock : public drawable, public clockTime {
	
};

#endif