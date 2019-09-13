#include "stdafx.h"
#include "NtlSkill.h"
#include "UseItemTable2.h"
#include "SystemEffectTable.h"
#include "Serializer.h"

WCHAR* UseItemTable2::m_pwszSheetList[] =
{
	L"Table_Data_KOR",
	NULL
};

UseItemTable2::UseItemTable2(void)
{
	Init();
}

UseItemTable2::~UseItemTable2(void)
{
	Destroy();
}

bool UseItemTable2::Create(DWORD dwCodePage)
{
	return Table::Create(dwCodePage);
}

void UseItemTable2::Destroy()
{
	Table::Destroy();
}

void UseItemTable2::Init()
{
}

void* UseItemTable2::AllocNewTable(WCHAR* pwszSheetName, DWORD dwCodePage)
{
	if (0 == wcscmp(pwszSheetName, L"Table_Data_KOR"))
	{
		sUSE_ITEM_TBLDAT2* pNewItem = new sUSE_ITEM_TBLDAT2;
		if (NULL == pNewItem)
			return NULL;

		CPINFO cpInfo;
		if (false == GetCPInfo(dwCodePage, &cpInfo))
		{
			delete pNewItem;
			return NULL;
		}

		m_dwCodePage = dwCodePage;
		return pNewItem;
	}

	return NULL;
}

bool UseItemTable2::DeallocNewTable(void* pvTable, WCHAR* pwszSheetName)
{
	if (0 == wcscmp(pwszSheetName, L"Table_Data_KOR"))
	{
		sUSE_ITEM_TBLDAT2* pItem = (sUSE_ITEM_TBLDAT2*)pvTable;
		if (FALSE != IsBadReadPtr(pItem, sizeof(*pItem)))
			return false;

		delete pItem;

		return true;
	}

	return false;
}

bool UseItemTable2::AddTable(void * pvTable, bool bReload)
{
	sUSE_ITEM_TBLDAT2* pTbldat = (sUSE_ITEM_TBLDAT2*)pvTable;
	sUSE_ITEM_TBLDAT2 * pExistTbldat = NULL;

	if (bReload)
	{
		pExistTbldat = (sUSE_ITEM_TBLDAT2*)FindData(pTbldat->tblidx);
		if (pExistTbldat)
		{
			CopyMemory(pTbldat, pExistTbldat, pTbldat->GetDataSize());
			// ����Ÿ�� ������ ���� false ��ȯ
			return true;
		}
	}

	if (false == m_mapTableList.insert(std::pair<TBLIDX, sTBLDAT*>(pTbldat->tblidx, pTbldat)).second)
	{
		Table::CallErrorCallbackFunction(L"[File] : %s\r\n Table Tblidx[%u] is Duplicated ", m_wszXmlFileName, pTbldat->tblidx);
		_ASSERTE(0);
		return false;
	}


	return true;
}

bool UseItemTable2::SetTableData(void* pvTable, WCHAR* pwszSheetName, std::wstring* pstrDataName, BSTR bstrData)
{
	if (0 == wcscmp(pwszSheetName, L"Table_Data_KOR"))
	{
		sUSE_ITEM_TBLDAT2* pItem = (sUSE_ITEM_TBLDAT2*)pvTable;

		if (0 == wcscmp(pstrDataName->c_str(), L"Tblidx"))
		{
			CheckNegativeInvalid(pstrDataName->c_str(), bstrData);
			pItem->tblidx = READ_DWORD(bstrData);
		}
		else
		{
			Table::CallErrorCallbackFunction(L"[File] : %s\n[Error] : Unknown field name found!(Field Name = %s)", m_wszXmlFileName, pstrDataName->c_str());
			return false;
		}
	}
	else
	{
		return false;
	}

	return true;
}


sTBLDAT* UseItemTable2::FindData(TBLIDX tblidx)
{
	if (0 == tblidx)
		return NULL;

	TABLEIT iter;
	iter = m_mapTableList.find(tblidx);
	if (End() == iter)
		return NULL;

	return (sTBLDAT*)(iter->second);
}

bool UseItemTable2::LoadFromBinary(Serializer& serializer, bool bReload)
{
	if (false == bReload)
	{
		Reset();
	}

	BYTE byMargin = 1;
	serializer >> byMargin;

	bool bLoop = true;
	do
	{
		sUSE_ITEM_TBLDAT2* pTableData = new sUSE_ITEM_TBLDAT2;
		if (NULL == pTableData)
		{
			//- yoshiki : To log system!
			Destroy();
			return false;
		}

		if (false == pTableData->LoadFromBinary(serializer))
		{
			delete pTableData;
			bLoop = false;
			break;
		}

		//  [4/26/2008 zeroera] : ���� : �����ϴ��� Load�� ���Ῡ�δ� File Loading���� �����Ѵ�
		if (false == AddTable(pTableData, bReload))
		{
			delete pTableData;
		}

	} while (false != bLoop);

	return true;
}

bool UseItemTable2::SaveToBinary(Serializer& serializer)
{
	serializer.Refresh();

	BYTE byMargin = 1;
	serializer << byMargin;

	TABLE::iterator iter;
	for (iter = Begin(); End() != iter; iter++)
	{
		sUSE_ITEM_TBLDAT2* pTableData = (sUSE_ITEM_TBLDAT2*)(iter->second);

		pTableData->SaveToBinary(serializer);
	}

	return true;
}