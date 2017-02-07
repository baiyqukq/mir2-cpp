/******************************************************************************************************************
                                                                                                                   
	Module Name:
																													
	Author:
	Date:
																													
	[Date][Modifier] : Modified contents
                                                                                                                   
*******************************************************************************************************************/



#include "StdAfx.h"
#include "WHEngine.h"



/******************************************************************************************************************

	Function Name : CWHSurface::ReleaseSurface()

	Author :
	Date :

	Purpose   :
	Return   : BOOL

	[Date][Modifier] : Modified contents

*******************************************************************************************************************/
BOOL CWHSurface::ReleaseSurface()
{
	if ( m_pDDS )
	{
		m_pDDS->Release();
		m_pDDS = NULL;

		return TRUE;
	}

	return FALSE;
}



/******************************************************************************************************************

	Function Name : CWHSurface::CreateOffScreenSurface()

	Author :
	Date :

	Purpose   :
	Params   : LPDIRECTDRAW7 pDD
	         DWORD dwXSize
	         DWORD dwYSize
	Return   : BOOL

	[Date][Modifier] : Modified contents

*******************************************************************************************************************/
BOOL CWHSurface::CreateOffScreenSurface(LPDIRECTDRAW7 pDD, DWORD dwXSize, DWORD dwYSize) 
{
	HRESULT					hr;
	DDSURFACEDESC2			ddsd;

	ZeroMemory(&ddsd, sizeof(DDSURFACEDESC2));

	ddsd.dwSize			= sizeof(DDSURFACEDESC2);
	ddsd.dwFlags		= DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;
	ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;
	ddsd.dwWidth		= dwXSize;
	ddsd.dwHeight		= dwYSize;

	hr = pDD->CreateSurface(&ddsd, &m_pDDS, NULL);

	if ( hr != DD_OK )	return FALSE;

	return TRUE;
}



/******************************************************************************************************************

	Function Name : CWHSurface::CopyImageToSurface()

	Author :
	Date :

	Purpose   :
	Params   : DWORD dwSrcWidth
	         DWORD dwSrcHeight
	         WORD* pwSrc
	Return   : BOOL

	[Date][Modifier] : Modified contents

*******************************************************************************************************************/
BOOL CWHSurface::CopyImageToSurface(DWORD dwSrcWidth, DWORD dwSrcHeight, WORD* pwSrc)
{
	DDSURFACEDESC2			ddsd;
	WORD*					pwdDst = NULL;

	ZeroMemory(&ddsd, sizeof(DDSURFACEDESC2));

	ddsd.dwSize	= sizeof(DDSURFACEDESC2);

	if (m_pDDS->Lock(NULL, &ddsd, DDLOCK_WAIT, NULL) == DD_OK)
	{
		pwdDst = (WORD*)ddsd.lpSurface;

		CopyMemory(pwdDst, pwSrc, dwSrcWidth * dwSrcHeight * sizeof(WORD));

		m_pDDS->Unlock(NULL);

		DDCOLORKEY              ddck;
		ddck.dwColorSpaceLowValue =  RGB( 0,  0,  0);
		ddck.dwColorSpaceHighValue = RGB(10, 10, 10);
		m_pDDS->SetColorKey(DDCKEY_SRCBLT, &ddck);

		return TRUE;
	}

	return FALSE;
}
