//Headers
#include<windows.h>
#define MYTIMER 500

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
    static RECT rc,rctemp;
	PAINTSTRUCT ps;
	HBRUSH hBrush;
	GetClientRect(hwnd, &rc);
	rctemp.top = rc.top;
	rctemp.bottom = rc.bottom;
	rctemp.left = rc.left;
	//rctemp.right = rc.right;
	rctemp.right = rc.left + (rc.right - rc.left) / 8;
	
	//code
	switch (iMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_CREATE:
		SetTimer(hwnd,MYTIMER,2000,NULL);
		break;

    case WM_TIMER:
		KillTimer(hwnd,MYTIMER);
			iPaintFlag++;
		if (iPaintFlag > 7)
			iPaintFlag = 0;
		InvalidateRect(hwnd,NULL,TRUE);
		SetTimer(hwnd, MYTIMER, 2000, NULL);
		break;


	case WM_PAINT:
	{

				//GetClientRect(hwnd, &rc);
		hdc = BeginPaint(hwnd, &ps);
	
		

		switch(iPaintFlag)
		{

		case 1:
		 { 
		
			hBrush = CreateSolidBrush(RGB(255, 0, 0));
			SelectObject(hdc, hBrush);
			FillRect(hdc, &rctemp, hBrush);
		}
		break;

		case 2:
		{
			rctemp.left = rctemp.left + ((rc.right-rc.left)/8);
			rctemp.right = rctemp.left + (rc.right - rc.left) / 8;
			hBrush = CreateSolidBrush(RGB(0, 255, 0));
			SelectObject(hdc, hBrush);
			FillRect(hdc, &rctemp, hBrush);
		}
		break;


		case 3:
		{	
			rctemp.left = rctemp.left + 2*((rc.right - rc.left) / 8);
			rctemp.right = rctemp.left + (rc.right - rc.left) / 8;
			hBrush = CreateSolidBrush(RGB(0, 0, 255));
			SelectObject(hdc, hBrush);
			FillRect(hdc, &rctemp, hBrush);
		}
		break;


		case 4:
		{
			rctemp.left = rctemp.left + 3*((rc.right - rc.left) / 8);
			rctemp.right = rctemp.left + (rc.right - rc.left) / 8;
			hBrush = CreateSolidBrush(RGB(0, 255, 255, ));
			SelectObject(hdc, hBrush);
			FillRect(hdc, &rctemp, hBrush);
		}
		break;

		case 5:
		{
			rctemp.left = rctemp.left + 4 * ((rc.right - rc.left) / 8);
			rctemp.right = rctemp.left + (rc.right - rc.left) / 8;
			hBrush = CreateSolidBrush(RGB(255, 0, 255));
			SelectObject(hdc, hBrush);
			FillRect(hdc, &rctemp, hBrush);
		}
		break;


		case 6:
		{
			rctemp.left = rctemp.left + 5 * ((rc.right - rc.left) / 8);
			rctemp.right = rctemp.left + (rc.right - rc.left) / 8;
			hBrush = CreateSolidBrush(RGB(255, 255, 0));
			SelectObject(hdc, hBrush);
			FillRect(hdc, &rctemp, hBrush);
		}
		break;

		case 7:
		{
			rctemp.left = rctemp.left + 6* ((rc.right - rc.left) / 8);
			rctemp.right = rctemp.left + (rc.right - rc.left) / 8;
			hBrush = CreateSolidBrush(RGB(255, 255, 255));
			SelectObject(hdc, hBrush);
			FillRect(hdc, &rctemp, hBrush);
		}
		break;

		case 8:
		{
			rctemp.left = rctemp.left + 7 * ((rc.right - rc.left) / 8);
			rctemp.right = rctemp.left + (rc.right - rc.left) / 8;
			hBrush = CreateSolidBrush(RGB(0, 0, 0));
			SelectObject(hdc, hBrush);
			FillRect(hdc, &rctemp, hBrush);
		}
		break;

	
		EndPaint(hwnd, &ps);

    	}//switch iPaintFlag
			
			

	}//switch WM_PAINT
		break;

	}//switch iMsg
	

	return(DefWindowProc(hwnd, iMsg, wParam, lParam));


}

