#ifndef _SPRITEDEF_H
#define _SPRITEDEF_H



/******************************************************************************************************************

	Actor Sprite Frame Define

*******************************************************************************************************************/

//~~~ Hero와 몬스터, NPC를 위한 FrameDefinition. ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
typedef struct tagSPRFRMDEF
{
	WORD		wFstFrm;						// Action의 시작 Frame.
	WORD		wFrmCnt;						// Action의 FrameNumber.
	WORD		wDelay;							// Action의 지연시간.
}SPRFRMDEF, *LPSPRFRMDEF;


/******************************************************************************************************************

	Effect Sprite Frame Define

*******************************************************************************************************************/

//~~~ Spell을 위한 FrameDefinition. ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
typedef struct tagEFFECTSPRINFO
{
	DWORD		dwFstFrm;
	DWORD		dwEndFrm;
	WORD		wDelay;
	WORD		wImgIdx;
	WORD		wEffectIdx;
	BYTE		bLightRadius[2];				// 광원 너비.
	BYTE		bLightColor [2][3];				// 광원 색.
	BYTE		bMagicColor [3];				// Spell 색.
	BYTE		bBlendType;
	BYTE		bOpa;
	BYTE		bSwingCnt;
}EFFECTSPRINFO, *LPEFFECTSPRINFO;


class CSprite
{
public:
	EFFECTSPRINFO		m_stEffectSpr[_MAX_EFFECT];			// Spell의 시전및 검법효과.
	EFFECTSPRINFO		m_stMagicSpr[_MAX_MAGIC];			// Spell효과.
	EFFECTSPRINFO		m_stExplosionSpr[_MAX_EXPLOSION];	// Spell폭발효과.

	EFFECTSPRINFO		m_stMonEffectSpr[_MAX_EFFECT];			// Spell의 시전및 검법효과.
	EFFECTSPRINFO		m_stMonMagicSpr[_MAX_MAGIC];			// Spell효과.
	EFFECTSPRINFO		m_stMonExplosionSpr[_MAX_EXPLOSION];	// Spell폭발효과.


	SPRFRMDEF			m_stHeroSpr[_MAX_HERO_MTN];			// Hero의 ActionFrame Definition.
	SPRFRMDEF			m_stMonSpr [_MAX_MON_MTN];			// Monster의 ActionFrame Definition.
	SPRFRMDEF			m_stNPCSpr [_MAX_MON_MTN];			// Monster의 ActionFrame Definition.

	BYTE				m_bWOrder[_MAX_HERO_REALFRAME];	

public:
	CSprite();
	~CSprite();

	VOID InitSpriteInfo();
	VOID DeleteSpriteInfo();

	VOID SetInfo();

	VOID SetSprDfn(LPSPRFRMDEF pstSprDfn, WORD wFstFrm, WORD wFrmCnt, WORD wDelay);

	VOID SetEffectInfo(LPEFFECTSPRINFO pstEffect, DWORD dwFstFrm, DWORD dwEndFrm, WORD wDelay, WORD wImgIdx, WORD wEffectIdx,
					   BYTE bSLightRadius, BYTE bLLightRadius, 
					   BYTE bSLightRColor, BYTE bSLightGColor, BYTE bSLightBColor,
					   BYTE bLLightRColor, BYTE bLLightGColor, BYTE bLLightBColor, 
					   BYTE bMagicRColor = 255, BYTE bMagicGColor = 255, BYTE bMagicBColor = 255, 
					   BYTE bBlendType = _BLEND_LIGHTINV, BYTE bOpa = 0, BYTE bSwingCnt = 0);

	LPEFFECTSPRINFO GetEffectInfo(WORD wEffectNum);
	LPEFFECTSPRINFO GetExplosionInfo(WORD wEffectNum);
	LPEFFECTSPRINFO GetMagicInfo(WORD wEffectNum);

	VOID			SetMonFrameInfo(WORD wMonNum);

	BOOL			SetWeaponOrder(CHAR* szFileName);
};



#endif //_SPRITEDEF_H



















