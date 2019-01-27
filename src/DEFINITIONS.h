#pragma once
////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////

/// Menu stuff
#define MY_WIN_CLASS_NAME "GraphDisplay"
#define MY_WIN_NAME "Graph Display"
#define EV_FIB -70
#define EV_SORT -69
#define EV_CLEAR -68
#define EV_DESTROY -67

#define X_PADDING 10
#define Y_PADDING 10
#define MENU_WIDTH 500
#define MENU_HEIGHT 500

/// Application metadata
#define APP_NAME "Diagram Displayer"
#define APP_X_PADDING X_PADDING+MENU_WIDTH
#define APP_Y_PADDING Y_PADDING

/// MACROs
#define SCRWIDTH this->_data->window.getSize().x
#define SCRHEIGHT this->_data->window.getSize().y

/// Available Graphs
enum GraphType {Fibonacci, Sort, Sine};