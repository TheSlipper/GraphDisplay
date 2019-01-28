////////////////////////////////////////////////////////////
// Created by Kornel Domeradzki.
// Copyright © 2018 Kornel Domeradzki. All rights reserved.
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "App Engine/App.hpp"
#include "WinAPIMenu.h"

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


