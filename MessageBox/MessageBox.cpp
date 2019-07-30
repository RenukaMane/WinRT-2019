//including header files
#include<windows.h>

//declaration of WndProc
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//WinMain
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
   //variable declarations
	WNDCLASSEX wndclass;
	MSG msg;
	HWND hwnd;
	TCHAR szAppName[] = TEXT("MyApp");

	MessageBox(NULL, TEXT("Applicatin Started"), TEXT("Message"), MB_OK|MB_ICONINFORMATION|MB_APPLMODAL);

	//initialization of WNDCLASSEX
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = 0;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	//register the class
	RegisterClassEx(&wndclass);

	//create window in memory
	        hwnd=CreateWindow(szAppName,
		                 TEXT("MY APP"),
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
	TCHAR str[255];

	switch (iMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;


	case WM_CREATE:
		wsprintf(str, TEXT("WM_CREATE Arrived"));
		MessageBox(hwnd,str,TEXT("Message Box"),MB_OK|MB_ICONINFORMATION);
		break;

	case WM_KEYDOWN:
		wsprintf(str,TEXT("KeyDown"));
		MessageBox(hwnd,str,TEXT("Message Box"),MB_OK|MB_ICONINFORMATION);
		break;

	case WM_LBUTTONDOWN:
		wsprintf(str, TEXT("Mouse Button Down"));
		MessageBox(hwnd, str, TEXT("Message Box"), MB_OK | MB_ICONINFORMATION);
		break;

	
	
	}


	return(DefWindowProc(hwnd, iMsg, wParam, lParam));

}
