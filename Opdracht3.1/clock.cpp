#include "clock.hpp"

void clockTime::updateTime() {
  uint64_t new_mear = now_us();
  uint64_t diff_mear = new_mear - last_mear;
  diff_time = diff_mear / 1e6;
  if (diff_time >= 1) {
    uint64_t overflow = diff_mear - 1e6;
    seconds += diff_time;
    last_mear = new_mear + overflow;
  }
  if (seconds >= 60) {
    minutes++;
    seconds = 0;
  }
  if (minutes >= 60) {
    hours++;
    minutes = 0;
  }
  if (hours > 11) {
    hours = 0;
  }
}

void clockBase::draw(window& w) {
  for (int i = 0; i < 360; i++) {
    int x_scaled = sin_tab.get(i) * radius;
    int y_scaled = cos_tab.get(i) * radius * -1;
    xy draw_pos = xy(x_scaled, y_scaled) + start;
    w.write(draw_pos);
  }
  for (int i = 0; i < 12; i++) {
    int x_pos = sin_tab.get(i * 30) * (radius - dist_dot);
    int y_pos = cos_tab.get(i * 30) * (radius - dist_dot) * -1;
    xy draw_pos = xy(x_pos, y_pos) + start;
    w.write(draw_pos);
  }
}

void clockArm::draw(window& w) {
  if (update_needed) {
    line del_arm = line(start, old_end, color{0, 0, 0});
    del_arm.draw(w);
    int loc_table = time_val * deg_fac;
    int x_end = sin_tab.get(loc_table) * length;
    int y_end = cos_tab.get(loc_table) * length * -1;
    xy new_end = xy(x_end, y_end) + start;
    line new_arm = line(start, new_end);
    new_arm.draw(w);
    old_end = new_end;
  }
}

void clockArm::update(int new_time, bool update) {
  update_needed = (update || (time_val != new_time));  // Feature reserved for optimizing the arm draw functionality
  time_val = new_time;
}

void analogClock::draw(window& w) {
  if (first_draw) {
    base.draw(w);
    first_draw = false;
    w.flush();
  }
  hour_arm.draw(w);
  min_arm.draw(w);
  sec_arm.draw(w);
  w.flush();
}

void analogClock::updateClock(window& w) {
  // int hours_bool;
  bool min_updt = true;
  bool hour_updt = true;
  while (true) {
    but_hour_up.refresh();
    but_min_up.refresh();
    if (!but_hour_up.read()) {
      hours++;
    }
    if (!but_min_up.read()) {
      minutes++;
    }

    updateTime();
    // DRAW
    sec_arm.update(seconds, true);
    min_arm.update(minutes, min_updt);
    hour_arm.update(hours, hour_updt);
    draw(w);

    // UPDATE TO DRAW OR NOT
    // hours_bool = hours*5;
    // min_updt = (min == sec-1 || min == hours_bool-1);
    // hour_updt = (hours_bool == min-1 || hours_bool == sec-1);
    // cout << "update min | hour" << min_updt << '|' << hour_updt << endl;
  }
}