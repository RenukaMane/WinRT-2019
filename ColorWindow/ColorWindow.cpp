//Headers
#include<windows.h>

//global function declaration
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//WinMain
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//variable declarations
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("MyApp");



	//code
	//initialization of WNDCLASSEX
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	//REGISTER ABOVE CLASS
	RegisterClassEx(&wndclass);

	//create window
	hwnd = CreateWindow(szAppName,
		TEXT("My Application"),
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

	//message loop
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);

	}

	return((int)msg.wParam);

}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	static int iPaintFlag = 0;
	HDC hdc;
	RECT rc;
	PAINTSTRUCT ps;
	HBRUSH hBrush;

	//code
	switch (iMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;


	case WM_CHAR:
	{
		switch (LOWORD(wParam))
		{
		case 'R':
		case 'r':
			iPaintFlag = 1;
			InvalidateRect(hwnd,NULL,TRUE);
			break;

		case 'G':
		case 'g':
			iPaintFlag = 2;
			InvalidateRect(hwnd, NULL, TRUE);
			break;

		case 'B':
		case 'b':
			iPaintFlag = 3;
			InvalidateRect(hwnd,NULL,TRUE);
			break;

		case 'C':
		case 'c':
			iPaintFlag = 4;
			InvalidateRect(hwnd, NULL, TRUE);
			break;

		case 'M':
		case 'm':
			iPaintFlag = 5;
			InvalidateRect(hwnd,NULL,TRUE);
			break;

		case 'Y':
	    case 'y':
			iPaintFlag = 6;
			InvalidateRect(hwnd, NULL, TRUE);
			break;

		case 'W':
		case 'w':
			iPaintFlag = 7;
			InvalidateRect(hwnd,NULL,TRUE);
			break;


		case 'K':
		case 'k':
		default:
			iPaintFlag = 8;
			InvalidateRect(hwnd, NULL, TRUE);
			break;


		}
		break;

	case WM_PAINT:
	{

		GetClientRect(hwnd, &rc);
		hdc = BeginPaint(hwnd, &ps);

		switch (iPaintFlag)
		{
		  
		case 1:
		{
			hBrush = CreateSolidBrush(RGB(255, 0, 0));
			SelectObject(hdc, hBrush);
			FillRect(hdc,&rc,hBrush);
		}
		break;
		
		case 2:
		{
			hBrush = CreateSolidBrush(RGB(0,255,0));
			SelectObject(hdc, hBrush);
			FillRect(hdc, &rc, hBrush);
		}
		break;


		case 3:
		{
			hBrush = CreateSolidBrush(RGB(0, 0, 255));
			SelectObject(hdc, hBrush);
			FillRect(hdc, &rc, hBrush);
		}
		break;


		case 4:
		{
			hBrush = CreateSolidBrush(RGB(0,255, 255,));
			SelectObject(hdc, hBrush);
			FillRect(hdc, &rc, hBrush);
		}
		break;

		case 5:
		{
			hBrush = CreateSolidBrush(RGB(255, 0, 255));
			SelectObject(hdc, hBrush);
			FillRect(hdc, &rc, hBrush);
		}
		break;


		case 6:
		{
			hBrush = CreateSolidBrush(RGB(255, 255, 0));
			SelectObject(hdc, hBrush);
			FillRect(hdc, &rc, hBrush);
		}
		break;

		case 7:
		{
			hBrush = CreateSolidBrush(RGB(255, 255, 255));
			SelectObject(hdc, hBrush);
			FillRect(hdc, &rc, hBrush);
		}
		break;

		case 8:
		{
			hBrush = CreateSolidBrush(RGB(0, 0, 0));
			SelectObject(hdc, hBrush);
			FillRect(hdc, &rc, hBrush);
		}
		break;
	
		}
		EndPaint(hwnd,&ps);
		
	}
	break;



 	}//switch WM_PAINT


	}//switch iMsg

	return(DefWindowProc(hwnd, iMsg, wParam, lParam));


}