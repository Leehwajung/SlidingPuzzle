// 이 MFC 샘플 소스 코드는 MFC Microsoft Office Fluent 사용자 인터페이스("Fluent UI")를 
// 사용하는 방법을 보여 주며, MFC C++ 라이브러리 소프트웨어에 포함된 
// Microsoft Foundation Classes Reference 및 관련 전자 문서에 대해 
// 추가적으로 제공되는 내용입니다.  
// Fluent UI를 복사, 사용 또는 배포하는 데 대한 사용 약관은 별도로 제공됩니다.  
// Fluent UI 라이선싱 프로그램에 대한 자세한 내용은 
// http://go.microsoft.com/fwlink/?LinkId=238214.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

// SlidingPuzzleDoc.cpp : CSlidingPuzzleDoc 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "SlidingPuzzleApp.h"
#endif

#include "SlidingPuzzleDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define PUZZLESIZE 4	// TODO: 퍼즐 사이즈 고정이므로 나중에 변경 가능하게 수정


// CSlidingPuzzleDoc

IMPLEMENT_DYNCREATE(CSlidingPuzzleDoc, CDocument)

BEGIN_MESSAGE_MAP(CSlidingPuzzleDoc, CDocument)
END_MESSAGE_MAP()


// CSlidingPuzzleDoc 생성/소멸

CSlidingPuzzleDoc::CSlidingPuzzleDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CSlidingPuzzleDoc::~CSlidingPuzzleDoc()
{
	if (m_pPuzzle) {
		delete m_pPuzzle;
	}
}

BOOL CSlidingPuzzleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	// TODO: 아래는 특정 퍼즐 크기와 시작/목표 노드로 하드 코딩 되어 있으므로 수정할 것
	m_pPuzzle = new SlidingPuzzle(PUZZLESIZE, PUZZLESIZE);	// TODO: 퍼즐 사이즈 고정이므로 나중에 변경 가능하게 수정
	int startNode[] = { 0, 2, 4, 3,   10, 5, 8, 11,   12, 14, 9, 7,   1, 13, 6, 15 };
	int goalNode[] = { 2, 4, 8, 3,   10, 5, 0, 11,   12, 14, 9, 7,   1, 13, 6, 15 };
	m_pPuzzle->initPuzzle(startNode);
	m_pPuzzle->initGoal(goalNode);

	return TRUE;
}


// CSlidingPuzzleDoc serialization

void CSlidingPuzzleDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void CSlidingPuzzleDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 검색 처리기를 지원합니다.
void CSlidingPuzzleDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CSlidingPuzzleDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS


// CSlidingPuzzleDoc 진단

#ifdef _DEBUG
void CSlidingPuzzleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSlidingPuzzleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CSlidingPuzzleDoc 명령
