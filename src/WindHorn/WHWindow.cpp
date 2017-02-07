/******************************************************************************************************************
                                                                                                                   
	Module Name:
																													
	Author:
	Date:
																													
	[Date][Modifier] : Modified contents
                                                                                                                   
*******************************************************************************************************************/



#include "stdafx.h"
#include "WHEngine.h"

static CWHApp* g_pWHApp = NULL;

/******************************************************************************************************************

	CWHApp Functions.

*******************************************************************************************************************/

/******************************************************************************************************************

	Function Name : CWHApp::CWHApp()

	Author :
	Date :

	Purpose   :
	Return   :

	[Date][Modifier] : Modified contents

*******************************************************************************************************************/
CWHApp::CWHApp()
{
	g_pWHApp	= this;
	m_hInstance = NULL;
}

/******************************************************************************************************************

	Function Name : CWHApp::~CWHApp()

	Author :
	Date :

	Purpose   :
	Return   :

	[Date][Modifier] : Modified contents

*******************************************************************************************************************/
CWHApp::~CWHApp()
{
}

/******************************************************************************************************************

	Function Name : CWHApp::MainWndProc()

	Author :
	Date :

	Purpose   :
	Params   : HWND hWnd
	         UINT uMsg
	         WPARAM wParam
	         LPARAM lParam
	Return   : LRESULT

	[Date][Modifier] : Modified contents

*******************************************************************************************************************/
LRESULT CWHApp::MainWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
{
    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

/******************************************************************************************************************

	Function Name : WndProc()

	Author :
	Date :

	Purpose   :
	Params   : HWND hWnd
	         UINT uMsg
	         WPARAM wParam
	         LPARAM lParam
	Return   : LRESULT CALLBACK

	[Date][Modifier] : Modified contents

*******************************************************************************************************************/
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    return g_pWHApp->MainWndProc(hWnd, uMsg, wParam, lParam);
}










/******************************************************************************************************************

	CWHWindow Functions.

*******************************************************************************************************************/

/******************************************************************************************************************

	Function Name : CWHWindow::CWHWindow()

	Author :
	Date :

	Purpose   :
	Return   :

	[Date][Modifier] : Modified contents

*******************************************************************************************************************/
CWHWindow::CWHWindow()
{
	m_hWnd = NULL;
}

/******************************************************************************************************************

	Function Name : CWHWindow::~CWHWindow()

	Author :
	Date :

	Purpose   :
	Return   :

	[Date][Modifier] : Modified contents

*******************************************************************************************************************/
CWHWindow::~CWHWindow()
{
}

/******************************************************************************************************************

	Function Name : CWHWindow::RegisterClass()

	Author :
	Date :

	Purpose   :
	Params   : CHAR *pszMenuName
	Return   : BOOL

	[Date][Modifier] : Modified contents

*******************************************************************************************************************/
BOOL CWHWindow::RegisterClass(CHAR* pszMenuName, CHAR* pszIconName)
{
    WNDCLASSEX wc;

    wc.cbSize			= sizeof(wc);
    wc.lpszClassName	= _WINDHORN_CLASS;
    wc.lpfnWndProc		= WndProc;
    wc.style			= CS_VREDRAW | CS_HREDRAW | CS_DBLCLKS;
    wc.hInstance		= m_hInstance;
    wc.hIcon			= LoadIcon(m_hInstance, pszIconName);
    wc.hIconSm			= LoadIcon(m_hInstance, pszIconName);
    wc.hCursor			= LoadCursor(m_hInstance, IDC_ARROW);
    wc.hbrBackground	= (HBRUSH)(GRAY_BRUSH);//(COLOR_WINDOW + 1);
    wc.lpszMenuName		= pszMenuName;
    wc.cbClsExtra		= 0;
    wc.cbWndExtra		= 0;

    if ( RegisterClassEx(&wc) == 0 )
	{
        return FALSE;
	}

	return TRUE;
}

/******************************************************************************************************************

	Function Name : CWHWindow::Create()

	Author :
	Date :

	Purpose   :
	Params   : LPTSTR lpCaption
	         CHAR *pszMenuName
	Return   : BOOL

	[Date][Modifier] : Modified contents

*******************************************************************************************************************/
BOOL CWHWindow::Create(HINSTANCE hInst, LPTSTR lpCaption, CHAR *pszMenuName, CHAR* pszIconName)
{
	SethInstance(hInst);
	if ( !RegisterClass(pszMenuName, pszIconName) ) 
	{
		MessageBox(NULL, TEXT("[CWHWindow::Create]") TEXT("Register class failed."), "MirDXG", MB_ICONERROR | MB_OK);
		return FALSE;
	}

    DWORD	dwFrameWidth    = GetSystemMetrics(SM_CXSIZEFRAME);
    DWORD	dwFrameHeight   = GetSystemMetrics(SM_CYSIZEFRAME);
	DWORD	dwMenuHeight;
	
	if ( pszMenuName != NULL )		
		dwMenuHeight = GetSystemMetrics(SM_CYMENU);
	else
		dwMenuHeight = 0;

    DWORD dwCaptionHeight = GetSystemMetrics(SM_CYCAPTION);
    DWORD dwWindowWidth   = _SCREEN_WIDTH  + dwFrameWidth * 2;
    DWORD dwWindowHeight  = _SCREEN_HEIGHT + dwFrameHeight * 2 + dwMenuHeight + dwCaptionHeight;

    DWORD dwStyle = WS_POPUPWINDOW/*WS_OVERLAPPEDWINDOW*/ & ~WS_MAXIMIZEBOX;

    m_hWnd = CreateWindowEx(NULL, _WINDHORN_CLASS, lpCaption,
						    dwStyle, CW_USEDEFAULT, CW_USEDEFAULT,
  						    dwWindowWidth, dwWindowHeight, NULL, NULL, m_hInstance, NULL);

	if ( m_hWnd == NULL )
    	return FALSE;

//  ShowWindow(m_hWnd, SW_SHOW);
//  UpdateWindow(m_hWnd);

	return TRUE;
}

/******************************************************************************************************************

	Function Name : CWHWindow::MainWndProc()

	Author :
	Date :

	Purpose   :
	Params   : HWND hWnd
	         UINT uMsg
	         WPARAM wParam
	         LPARAM lParam
	Return   : LRESULT

	[Date][Modifier] : Modified contents

*******************************************************************************************************************/
LRESULT CWHWindow::MainWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
{
	switch (uMsg)
	{
		case WM_DESTROY:
			return OnDestroy();
	}

    return CWHApp::MainWndProc(hWnd, uMsg, wParam, lParam);
}

/******************************************************************************************************************

	Function Name : CWHWindow::OnDestroy()

	Author :
	Date :

	Purpose   :
	Return   : BOOL

	[Date][Modifier] : Modified contents

*******************************************************************************************************************/
LRESULT CWHWindow::OnDestroy()
{
	PostQuitMessage(NULL);
	return 0L;
}
