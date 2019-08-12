//include header file
#include<windows.h>

//prototype of WndProc
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//WinMain
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//variable declarations
	WNDCLASSEX wndclass;
	MSG msg;
	TCHAR szAppName[] = TEXT("MyApp");
	HWND hwnd;

	//initialisation of class variables
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;


	//Register class
	RegisterClassEx(&wndclass);

	//Create Window in Memory
	hwnd = CreateWindow(szAppName,
		TEXT("MY APPLICATION"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	//Message Loop

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);

	}

	return((int)msg.wParam);





}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	SIZE sz;
	TCHAR str[255];
	wsprintf(str, TEXT("PLEDGE"));
	int X, Y;
	//wsprintf(str, TEXT("India is my country"));
	RECT rc;
	PAINTSTRUCT ps;
	//size_t * pcch;

	switch (iMsg)
	{
	case WM_PAINT:
		GetClientRect(hwnd, &rc);
		hdc = BeginPaint(hwnd, &ps);
		SetTextColor(hdc, RGB(0, 0, 255));
		SetBkColor(hdc, RGB(0, 0, 0));		
		GetTextExtentPoint32(hdc,str,6, &sz);
		X = Y = 20;
		TextOut(hdc,X,Y,str,6);
		Y = Y + sz.cy+5;
		SetTextColor(hdc, RGB(255, 128, 0));
		TextOut(hdc, X, Y, TEXT("India is my country"), 19);
		Y = Y + sz.cy;
	    TextOut(hdc, X, Y, TEXT("and all indians are my brothers and sisters."), 44);
		Y = Y + sz.cy;
		TextOut(hdc, X, Y, TEXT("I love my country"), 17);
		Y = Y + sz.cy;
		TextOut(hdc, X, Y, TEXT("and i am proud of rich and varied heritage"), 42);		
		SetTextColor(hdc,RGB(255,255,255));
		Y = Y + sz.cy;
		TextOut(hdc, X, Y, TEXT("I shall always strive to be worthy of it."), 41);
		Y = Y + sz.cy;
		TextOut(hdc, X, Y, TEXT("and treat everyone with courtesy."), 33);
		Y = Y + sz.cy;
		TextOut(hdc, X, Y, TEXT("to my country and my people."), 28);
		SetTextColor(hdc, RGB(0,255,0));
		Y = Y + sz.cy;
		TextOut(hdc, X, Y, TEXT("I pledge my devotion"), 20);
		Y = Y + sz.cy;
		TextOut(hdc, X, Y, TEXT("In their well being and"), 23);
		Y = Y + sz.cy;
		TextOut(hdc, X, Y, TEXT("prosperity lies in my happiness"), 31);
		Y = Y + sz.cy;
		TextOut(hdc, X, Y, TEXT("Jai Hind!!!"), 11);
		EndPaint(hwnd, &ps);
		break;


	case WM_DESTROY:
		PostQuitMessage(0);
		break;


	}

	return(DefWindowProc(hwnd, iMsg, wParam, lParam));



}
