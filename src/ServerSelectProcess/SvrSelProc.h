/******************************************************************************************************************
                                                                                                                   
	Module Name:
																													
	Author:
	Date:
																													
	[Date][Modifier] : Modified contents
                                                                                                                   
*******************************************************************************************************************/


#ifndef _SVRSELPROC_H
#define	_SVRSELPROC_H


class CSvrSelProcess : public CWHDefProcess
{
public:
	 CSvrSelProcess();
	~CSvrSelProcess();
private:
	virtual LRESULT DefMainWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	LRESULT OnKeyDown(WPARAM wParam, LPARAM lParam);
public:
	VOID	Load();
	VOID	DeleteProc();
	VOID	SetNextProc();
	VOID	RenderScene(INT nLoopTime);
	virtual VOID ShowStatus(INT nStartX, INT nStartY);
};


#endif //_SVRSELPROC_H
