/******************************************************************************************************************
                                                                                                                   
	Module Name:
																													
	Author:
	Date:
																													
	[Date][Modifier] : Modified contents
                                                                                                                   
*******************************************************************************************************************/


#ifndef _CPLAYERCHAR_H
#define _CPLAYERCHAR_H


#include <ddraw.h>
#include <mmsystem.h>


class CPlayerChar : public CCharacter
{
private:	
public:
	CDLList<CItem>		m_xBeltItemList;

protected:
public:
	CPlayerChar();
	~CPlayerChar();
};

#endif // _CPLAYERCHAR_H
