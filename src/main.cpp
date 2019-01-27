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
		case EV_DESTROY:
			PostQuitMessage(0);
			break;
		/* case EV_CLEAR:
			// TODO: Here handle clearing
			break; */
		case EV_SINE:
			free(app);
			app = new ArktisProductions::App(APP_NAME, APP_X_PADDING, APP_Y_PADDING, GraphType::Sine);
			break;
		case EV_FIB:
			free(app);
			app = new ArktisProductions::App(APP_NAME, APP_X_PADDING, APP_Y_PADDING, GraphType::Fibonacci);
			// TODO: Free the memory in this case and the latter one
			break;
		case EV_SORT:
			free(app);
			app = new ArktisProductions::App(APP_NAME, APP_X_PADDING, APP_Y_PADDING, GraphType::Sort);
			break;
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
	// Add menus
	hMenu = CreateMenu();
	AppendMenu(hMenu, MF_STRING, EV_FIB, "Fibonacci");
	AppendMenu(hMenu, MF_STRING, EV_SORT, "Sort");
	AppendMenu(hMenu, MF_STRING, EV_SINE, "Sine");
	AppendMenu(hMenu, MF_STRING, EV_CLEAR, "Clear");
	AppendMenu(hMenu, MF_STRING, EV_DESTROY, "Exit");
	SetMenu(hWnd, hMenu);

	// Add label (static) and buttons
	CreateWindow("Static", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 90, 130, 300, 300, hWnd, NULL, NULL, NULL);
	CreateWindow("Button", "fibonacci/czas", WS_VISIBLE | WS_CHILD, 50, 10, 120, 70, hWnd, (HMENU)EV_FIB, NULL, NULL);
	CreateWindow("Button", "Sortowanie/czas", WS_VISIBLE | WS_CHILD, 180, 10, 120, 70, hWnd, (HMENU)EV_SORT, NULL, NULL);
	CreateWindow("Button", "Wyczysc output", WS_VISIBLE | WS_CHILD, 310, 10, 120, 70, hWnd, (HMENU)EV_CLEAR, NULL, NULL);
}
