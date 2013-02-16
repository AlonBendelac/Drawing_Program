#include <Adafruit_GFX.h>
#include <Adafruit_GFX.cpp>

typedef enum PEN_STATES {PEN_UP, PEN_DOWN};

PEN_STATES pen_state;

// Color definitions
#define BLACK    0x0000
//#define BLUE     0x001F
//#define RED      0xF800
//#define GREEN    0x07E0
//#define CYAN     0x07FF
//#define MAGENTA  0xF81F
//#define YELLOW   0xFFE0
#define WHITE    0xFFFF

const int MID_SCREEN_X = 42;
const int MID_SCREEN_Y = 24;

void update_pen_state (PEN_STATES * pen_state);
void update_x (int * x);
void update_y (int * y);
boolean PenIsDown ();
void Blink (int x, int y);
void make_dot (int x, int y);

void setup () {
  fillScreen(WHITE);
  setCursor(MID_SCREEN_X, MID_SCREEN_Y);
}

void loop () {
  static int Blink = 0;
  static int z;
  static int x, y;
  
  fillScreen(WHITE);
  
  update_pen_state (&pen_state);
  update_x (&x);
  update_y (&y);
  
  Blink++;
  Blink (x, y);
  
  if (pen_state == PEN_DOWN) {
    make_dot (x, y);
  }
}

void update_pen_state (PEN_STATES * pen_state) {
  if (PenIsDown) {
    *pen_state = PEN_DOWN;
  }
  else {
    *pen_state = PEN_UP;
  }
}

void update_x (int * x) {
  // set the x value
  *x = ;
}

void update_y (int * y) {
  // set the y value
  *y = ;
}

boolean PenIsDown () {
  if (/*joystick held down*/) {
    return true;
  }
  else {
    return false;
  }
}

void Blink (int x, int y) {
  if (Blink % 2 == 0) {
    drawPixel(x, y, WHITE);
  }
  else {
    drawPixel(x, y, BLACK);
  }  
}

void make_dot (int x, int y) {
  drawPixel(x, y, BLACK);
}
