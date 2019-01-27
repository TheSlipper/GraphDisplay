////////////////////////////////////////////////////////////
// Created by Kornel Domeradzki.
// Copyright © 2018 Kornel Domeradzki. All rights reserved.
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "App Engine/App.hpp"
#include <Windows.h>
#include <cstdlib>

HMENU hMenu;
ArktisProductions::App *app;

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
void AddComponents(HWND);

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow)
{
	WNDCLASS winClass = { 0 };
	winClass.hbrBackground = (HBRUSH)COLOR_WINDOW;
	winClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	winClass.hInstance = hInst;
	winClass.lpszClassName = MY_WIN_CLASS_NAME; // Maybe L before string
	winClass.lpfnWndProc = WindowProcedure;

	if (!RegisterClass(&winClass)) // RegisterClassW
		return EXIT_FAILURE;

	CreateWindow(MY_WIN_CLASS_NAME, MY_WIN_NAME, WS_OVERLAPPEDWINDOW | WS_VISIBLE, X_PADDING, Y_PADDING, MENU_WIDTH, MENU_HEIGHT,
					NULL, NULL,NULL,NULL); // CreateWindowW
	
	MSG msg = { 0 };
	// Message / Event loop
	while (GetMessage(&msg, NULL, NULL, NULL))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
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

void AddComponents(HWND hWnd)
{
	// Add label (static) and buttons
	CreateWindow("Button", "fibonacci/time", WS_VISIBLE | WS_CHILD, 50, 10, 120, 70, hWnd, (HMENU)EV_FIB, NULL, NULL);
	CreateWindow("Button", "NWD/time", WS_VISIBLE | WS_CHILD, 180, 10, 120, 70, hWnd, (HMENU)EV_NWD, NULL, NULL);
	CreateWindow("Button", "Sine/time", WS_VISIBLE | WS_CHILD, 120, 100, 120, 70, hWnd, (HMENU)EV_SINE, NULL, NULL);
	CreateWindow("Button", "Tan/time", WS_VISIBLE | WS_CHILD, 250, 100, 120, 70, hWnd, (HMENU)EV_TAN, NULL, NULL);
	CreateWindow("Button", "About", WS_VISIBLE | WS_CHILD, 310, 10, 120, 70, hWnd, (HMENU)EV_ABOUT, NULL, NULL);
}
