#include "StdAfx.h"
#include "MerchantTable2.h"
#include "Serializer.h"

WCHAR* MerchantTable2::m_pwszSheetList[] =
{
	L"Table_Data_KOR",
	NULL
};

MerchantTable2::MerchantTable2(void)
{
	Init();
}

MerchantTable2::~MerchantTable2(void)
{
	Destroy();
}

bool MerchantTable2::Create(DWORD dwCodePage)
{
	return Table::Create(dwCodePage);
}

void MerchantTable2::Destroy()
{
	Table::Destroy();
}

void MerchantTable2::Init()
{
}

void* MerchantTable2::AllocNewTable(WCHAR* pwszSheetName, DWORD dwCodePage)
{
	if (0 == wcscmp(pwszSheetName, L"Table_Data_KOR"))
	{
		sMERCHANT_TBLDAT2* pMerchant = new sMERCHANT_TBLDAT2;
		if (NULL == pMerchant)
			return NULL;

		CPINFO cpInfo;
		if (false == GetCPInfo(dwCodePage, &cpInfo))
		{
			delete pMerchant;
			return NULL;
		}

		m_dwCodePage = dwCodePage;
		return pMerchant;
	}

	return NULL;
}

bool MerchantTable2::DeallocNewTable(void* pvTable, WCHAR* pwszSheetName)
{
	if (0 == wcscmp(pwszSheetName, L"Table_Data_KOR"))
	{
		sMERCHANT_TBLDAT2* pMerchant = (sMERCHANT_TBLDAT2*)pvTable;
		if (FALSE != IsBadReadPtr(pMerchant, sizeof(*pMerchant)))
			return false;

		delete pMerchant;

		return true;
	}

	return false;
}

bool MerchantTable2::AddTable(void * pvTable, bool bReload)
{
	sMERCHANT_TBLDAT2 * pTbldat = (sMERCHANT_TBLDAT2*)pvTable;
	sMERCHANT_TBLDAT2 * pExistTbldat = NULL;

	if (bReload)
	{
		pExistTbldat = (sMERCHANT_TBLDAT2*)FindData(pTbldat->tblidx);
		if (pExistTbldat)
		{
			CopyMemory(pTbldat, pExistTbldat, pTbldat->GetDataSize());
			// ����Ÿ�� ������ ���� false ��ȯ
			return true;
		}
	}

	if (false == m_mapTableList.insert(std::map<TBLIDX, sTBLDAT*>::value_type(pTbldat->tblidx, pTbldat)).second)
	{
		Table::CallErrorCallbackFunction(L"[File] : %s\r\n Table Tblidx[%u] is Duplicated ", m_wszXmlFileName, pTbldat->tblidx);
		_ASSERTE(0);
		return false;
	}


	return true;
}

bool MerchantTable2::SetTableData(void* pvTable, WCHAR* pwszSheetName, std::wstring* pstrDataName, BSTR bstrData)
{
	if (0 == wcscmp(pwszSheetName, L"Table_Data_KOR"))
	{
		sMERCHANT_TBLDAT2* pMerchant = (sMERCHANT_TBLDAT2*)pvTable;

		if (0 == wcscmp(pstrDataName->c_str(), L"Tblidx"))
		{
			pMerchant->tblidx = READ_DWORD(bstrData);
		}
		else if (0 == wcscmp(pstrDataName->c_str(), L"Name_Text"))
		{
			READ_STRINGW(bstrData, pMerchant->wszNameText, _countof(pMerchant->wszNameText));
		}
		else if (0 == wcscmp(pstrDataName->c_str(), L"Sell_Type"))
		{
			pMerchant->bySell_Type = READ_BYTE(bstrData, pstrDataName->c_str());
		}
		else if (0 == wcscmp(pstrDataName->c_str(), L"Tab_Name"))
		{
			pMerchant->Tab_Name = READ_DWORD(bstrData);
		}
		else if (0 == wcscmp(pstrDataName->c_str(), L"Need_Mileage"))
		{
			pMerchant->dwNeedMileage = READ_DWORD(bstrData);
		}
		else if (0 == wcsncmp(pstrDataName->c_str(), L"Item_Tblidx_", wcslen(L"Item_Tblidx_")))
		{
			bool bFound = false;

			WCHAR szBuffer[1024] = { 0x00, };
			for (int i = 0; i < MAX_MERCHANT_COUNT; i++)
			{
				swprintf(szBuffer, 1024, L"Item_Tblidx_%d", i + 1);

				if (0 == wcscmp(pstrDataName->c_str(), szBuffer))
				{
					pMerchant->aitem_Tblidx[i] = READ_DWORD(bstrData);

					bFound = true;
					break;
				}
			}

			if (false == bFound)
			{
				Table::CallErrorCallbackFunction(L"[File] : %s\n[Error] : Unknown field name found!(Field Name = %s)", m_wszXmlFileName, pstrDataName->c_str());
				return false;
			}
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


sTBLDAT* MerchantTable2::FindData(TBLIDX tblidx)
{
	if (0 == tblidx)
		return NULL;

	TABLEIT iter;
	iter = m_mapTableList.find(tblidx);
	if (End() == iter)
		return NULL;

	return (sTBLDAT*)(iter->second);
}

TBLIDX MerchantTable2::FindMerchantItem(sMERCHANT_TBLDAT2* psTbldat, BYTE byIndex)
{
	if (MAX_MERCHANT_COUNT <= byIndex || 0 > byIndex)
		return INVALID_TBLIDX;

	return psTbldat->aitem_Tblidx[byIndex];
}

bool MerchantTable2::LoadFromBinary(Serializer& serializer, bool bReload)
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
		sMERCHANT_TBLDAT2* pTableData = new sMERCHANT_TBLDAT2;
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

bool MerchantTable2::SaveToBinary(Serializer& serializer)
{
	serializer.Refresh();

	BYTE byMargin = 1;
	serializer << byMargin;

	TABLE::iterator iter;
	for (iter = Begin(); End() != iter; iter++)
	{
		sMERCHANT_TBLDAT2* pTableData = (sMERCHANT_TBLDAT2*)(iter->second);

		pTableData->SaveToBinary(serializer);
	}

	return true;
}