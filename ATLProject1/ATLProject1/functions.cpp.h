// functions.cpp.h : Declaration of the functions.cpp class

#pragma once

#include <atlhandlerimpl.h>

using namespace ATL;

class functions.cpp : public CAtlDocumentImpl
{
public:
	functions.cpp(void)
	{
	}

	virtual ~functions.cpp(void)
	{
	}

	virtual HRESULT LoadFromStream(IStream* pStream, DWORD grfMode);
	virtual void InitializeSearchContent();

protected:
	void SetSearchContent(CString& value);
	virtual void OnDrawThumbnail(HDC hDrawDC, LPRECT lprcBounds);
};
