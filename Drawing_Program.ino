#include <Adafruit_GFX.h>
#include <Adafruit_GFX.cpp>

typedef enum PEN_STATES {PEN_UP, PEN_DOWN};

PEN_STATES pen_state;

void setup () {
  setCursor(42/*x*/, 24/*y*/);
}

void loop () {
  static int Blink = 0;
  static int z;
  static float x, y;
  
  update_pen_state ();
  update_x ();
  update_y ();
  
  Blink++;
  Blink (x, y);
  
  if (pen_state == PEN_DOWN) {
    make_dot ();
  }
}

void update_pen_state () {
  if (check_z () == 0) {
    pen_state = PEN_UP;
  }
  else if (check_z () == 1) {
    pen_state = DOWN;
  }
}

void update_x () {
  
}

void update_y () {
  
}

void Blink (float x, float y) {
  if (Blink % 2 == 0) {
    drawPixel(x, y, uint16_t color);
  }
  else {
    drawPixel(x, y, uint16_t color);
  }  
}

void make_dot () {
  drawPixel(x, y, uint16_t color);
}
