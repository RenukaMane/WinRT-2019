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

	ShowWindow(hwnd,iCmdShow);
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
	TCHAR str[] = TEXT("Hello World!!!");
	RECT rc;
	PAINTSTRUCT ps;

	switch (iMsg)
	{
	case WM_PAINT:
		//get changing rectangle
		GetClientRect(hwnd,&rc);
		//call the specialist
		hdc = BeginPaint(hwnd,&ps);
		//set color
		SetTextColor(hdc, RGB(0, 255, 0));
		//set background color
		SetBkColor(hdc, RGB(0, 0, 0));
		//now draw actual text
		DrawText(hdc,str,-1,&rc,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
        //Send back the specialist
		EndPaint(hwnd,&ps);
		break;


	case WM_DESTROY:
		PostQuitMessage(0);
		break;


	}

	return(DefWindowProc(hwnd, iMsg, wParam, lParam));



}
