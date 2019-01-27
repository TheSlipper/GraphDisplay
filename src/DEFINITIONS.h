#pragma once
////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////

/// Menu stuff
#define MY_WIN_CLASS_NAME "GraphDisplay"
#define MY_WIN_NAME "Graph Display"
#define EV_ABOUT 0
#define EV_SINE 1
#define EV_TAN 2
#define EV_FIB 3
#define EV_NWD 4
#define EV_DESTROY 5

#define X_PADDING 10
#define Y_PADDING 10
#define MENU_WIDTH 500
#define MENU_HEIGHT 250

/// Application metadata
#define APP_NAME "GraphDisplay"
#define APP_X_PADDING X_PADDING+MENU_WIDTH
#define APP_Y_PADDING Y_PADDING

/// MACROs
#define SCRWIDTH this->_data->window.getSize().x
#define SCRHEIGHT this->_data->window.getSize().y

/// Available Graphs
enum GraphType {Fibonacci, NWD, Sine, Tan};

/// Fonts
#define MAIN_FONT_NAME "mainFont"
#define MAIN_FONT_PATH "assets/fonts/SF Pro/SF-Pro-Display-Light.otf"