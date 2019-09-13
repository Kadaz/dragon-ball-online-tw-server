#pragma once

#include "Table.h"
#include "NPCTable.h"


enum eMOB_PROPERTY_TYPE
{
	MOB_PROPERTY_DUNGEON_BOSS,
	MOB_PROPERTY_NONE = 0xFF
};

// MOB
#pragma pack(push, 4)
struct sMOB_TBLDAT : public sBOT_TBLDAT
{
public:
	DWORD			Mob_Group;//Mob_Group
	WORD			wMob_Kind;//Mob_Kind
	// -----------------------  
	//BYTE paidd[2];
	// -----------------------  	
	DWORD			fDrop_Zenny_Rate;
	float			notknow;	
	DWORD			fDrop_Exp_Rate;//fDrop_Exp_Rate
	
	//BYTE unk;

	// -----------------------
	//BYTE	Padding3[7];
	// -----------------------

	BYTE unk1;

	// -----------------------  
	//BYTE padding;
	// -----------------------  
	BYTE unk2[2];
	WORD			dwDrop_Zenny[2];
	DWORD			unk3;
	WORD			wExp;
	// -----------------------  
	//BYTE    Padding[2];
	// -----------------------  
	DWORD			byMob_Type;
	WORD			unk4;
	//WORD			padding;
	DWORD			unk5;
	WORD			unk6;

	// -----------------------
	//BYTE			padding5[2];
	// -----------------------

	DWORD			unk7;
	BYTE			unk8;
	WORD unk9;

	// -----------------------
	//BYTE			padding6;
	// -----------------------

	BYTE			byDropTypeRateControl;
	BYTE			byDropEachRateControl;
	// -----------------------  
//	BYTE padding[2];
	// -----------------------  
	BYTE			byDropNItemRateControl;
	BYTE			byDropSItemRateControl;
	BYTE			byDropEItemRateControl;
	BYTE			byDropLItemRateControl;
	BYTE unk10;
	// -----------------------  
	//BYTE padding;
	// -----------------------  
	DWORD			unk11;
	// -----------------------  
	//BYTE padding[2];
	// -----------------------  
	BYTE			byProperty;//Correct
	BYTE			size;
	BYTE			unk29;
	WORD			wSightAngle;
	// -----------------------

	DWORD			unk30;
	BYTE			unk31;
	WORD			unk32;
	WORD			unk33;
	BYTE			unk34;
	BYTE			unk35;
	BYTE			unk36;
	WORD			unk37;
	BYTE			unk38;
	BYTE			unk39;
	DWORD			unk40;
	WORD			unk41;
	BYTE			unk42a;
	BYTE			unk43b;
	WORD			unk44c;
	BYTE			unk42d;
	BYTE			unk43e;
	WORD			unk44f;
	BYTE			unk42g;
	BYTE			unk43h;
	WORD			unk44i;
	BYTE			unk42j;
	BYTE			unk43k;
	WORD			unk44l;
	BYTE			unk42m;
	BYTE			unk43n;
	WORD			unk44o;
	BYTE			unk42p;
	BYTE			unk43q;
	WORD			unk44r;
	BYTE			unk42pp;
	BYTE			unk43qp;
	WORD			unk44rp;
	BYTE unk45;
	BYTE unk47;
	BYTE unk48;
	BYTE unk49;

public:

	virtual int GetDataSize()
	{
		return sizeof(*this) - sizeof(void*);
	}
};
#pragma pack(pop)

class MobTable : public Table
{
public:
	typedef std::map<DWORD, TBLIDX> MOB_TABLE;
	typedef MOB_TABLE::iterator MOB_TABLEIT;
	typedef MOB_TABLE::value_type MOB_TABLEVAL;

public:
	MobTable(void);
public:
	virtual ~MobTable(void);

	bool Create(DWORD dwCodePage);
	void Destroy();

protected:
	void Init();

public:
	MOB_TABLEIT	MobBegin() { return m_mapMobTableList.begin(); }
	MOB_TABLEIT	MobEnd() { return m_mapMobTableList.end(); }

	sTBLDAT *			FindData(TBLIDX tblidx);
	TBLIDX				FindTblidxByGroup(DWORD dwMobGroup);
protected:
	WCHAR** GetSheetListInWChar() { return &(MobTable::m_pwszSheetList[0]); }
	void* AllocNewTable(WCHAR* pwszSheetName, DWORD dwCodePage);
	bool DeallocNewTable(void* pvTable, WCHAR* pwszSheetName);
	bool AddTable(void * pvTable, bool bReload);
	bool SetTableData(void* pvTable, WCHAR* pwszSheetName, std::wstring* pstrDataName, BSTR bstrData);

public:

	virtual bool				LoadFromBinary(Serializer& serializer, bool bReload);

	virtual bool				SaveToBinary(Serializer& serializer);


private:
	static WCHAR* m_pwszSheetList[];
	MOB_TABLE			m_mapMobTableList;
};
