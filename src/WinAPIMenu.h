////////////////////////////////////////////////////////////
// Created by Kornel Domeradzki.
// Copyright © 2018 Kornel Domeradzki. All rights reserved.
////////////////////////////////////////////////////////////
#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <Windows.h>
#include <cstdlib>
#include "DEFINITIONS.h"
#include "App Engine/App.hpp"

////////////////////////////////////////////////////////////
// Global variables
////////////////////////////////////////////////////////////
HMENU hMenu;
ArktisProductions::App *app;

void AddComponents(HWND hWnd)
{
	// Add label (static) and buttons
	CreateWindow("Button", "fibonacci/time", WS_VISIBLE | WS_CHILD, 50, 10, 120, 70, hWnd, (HMENU)EV_FIB, NULL, NULL);
	CreateWindow("Button", "NWD/time", WS_VISIBLE | WS_CHILD, 180, 10, 120, 70, hWnd, (HMENU)EV_NWD, NULL, NULL);
	CreateWindow("Button", "Sine/time", WS_VISIBLE | WS_CHILD, 120, 100, 120, 70, hWnd, (HMENU)EV_SINE, NULL, NULL);
	CreateWindow("Button", "Tan/time", WS_VISIBLE | WS_CHILD, 250, 100, 120, 70, hWnd, (HMENU)EV_TAN, NULL, NULL);
	CreateWindow("Button", "About", WS_VISIBLE | WS_CHILD, 310, 10, 120, 70, hWnd, (HMENU)EV_ABOUT, NULL, NULL);
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		exit(0);
		break;
	case WM_CREATE:
		AddComponents(hWnd);
		break;
	case WM_COMMAND:

		switch (wp)
		{
			// Menus
		case EV_DESTROY:
			PostQuitMessage(0);
			break;
		case EV_ABOUT:
			MessageBox(NULL, "This is a program that shows the efficiency of ASM in comparison to C++.", "About", MB_ICONINFORMATION);
			break;
		case EV_SINE:
			free(app);
			app = new ArktisProductions::App((std::string)APP_NAME + " - sin(x)", APP_X_PADDING, APP_Y_PADDING, GraphType::Sine);
			break;
		case EV_TAN:
			free(app);
			app = new ArktisProductions::App((std::string)APP_NAME + " - tan(x)", APP_X_PADDING, APP_Y_PADDING, GraphType::Tan);
			break;
		case EV_FIB:
			free(app);
			app = new ArktisProductions::App((std::string)APP_NAME + " - fib(x)", APP_X_PADDING, APP_Y_PADDING, GraphType::Fibonacci);
			break;
		case EV_NWD:
			free(app);
			app = new ArktisProductions::App((std::string)APP_NAME + " - nwd(x)", APP_X_PADDING, APP_Y_PADDING, GraphType::NWD);
			break;
			// 
		default:
			return DefWindowProc(hWnd, msg, wp, lp);
		}

		break;
	default:
		return DefWindowProc(hWnd, msg, wp, lp);
	}
}
