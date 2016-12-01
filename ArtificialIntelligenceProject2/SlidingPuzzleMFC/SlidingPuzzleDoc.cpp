// �� MFC ���� �ҽ� �ڵ�� MFC Microsoft Office Fluent ����� �������̽�("Fluent UI")�� 
// ����ϴ� ����� ���� �ָ�, MFC C++ ���̺귯�� ����Ʈ��� ���Ե� 
// Microsoft Foundation Classes Reference �� ���� ���� ������ ���� 
// �߰������� �����Ǵ� �����Դϴ�.  
// Fluent UI�� ����, ��� �Ǵ� �����ϴ� �� ���� ��� ����� ������ �����˴ϴ�.  
// Fluent UI ���̼��� ���α׷��� ���� �ڼ��� ������ 
// http://go.microsoft.com/fwlink/?LinkId=238214.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

// SlidingPuzzleDoc.cpp : CSlidingPuzzleDoc Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "SlidingPuzzleApp.h"
#endif

#include "SlidingPuzzleDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSlidingPuzzleDoc

IMPLEMENT_DYNCREATE(CSlidingPuzzleDoc, CDocument)

BEGIN_MESSAGE_MAP(CSlidingPuzzleDoc, CDocument)
END_MESSAGE_MAP()


// CSlidingPuzzleDoc ����/�Ҹ�

CSlidingPuzzleDoc::CSlidingPuzzleDoc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

}

CSlidingPuzzleDoc::~CSlidingPuzzleDoc()
{
	if (m_pPuzzle) {
		delete m_pPuzzle;
	}
}

// TODO: �Ʒ� �Լ��� Ư�� ���� ũ��� ����/��ǥ ���� �ϵ� �ڵ� �Ǿ� �����Ƿ� ������ ��
void CSlidingPuzzleDoc::initializePuzzle()
{
	int startNode[] = { 0, 2, 4, 3,   10, 5, 8, 11,   12, 14, 9, 7,   1, 13, 6, 15 };
	int goalNode[] = { 2, 4, 8, 3,   10, 5, 0, 11,   12, 14, 9, 7,   1, 13, 6, 15 };
	m_pPuzzle->initPuzzle(startNode);
	m_pPuzzle->initGoal(goalNode);
}

BOOL CSlidingPuzzleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	m_pPuzzle = new SlidingPuzzle(PUZZLESIZE, PUZZLESIZE);	// TODO: ���� ������ �����̹Ƿ� ���߿� ���� �����ϰ� ����
	initializePuzzle();

	return TRUE;
}


// CSlidingPuzzleDoc serialization

void CSlidingPuzzleDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
	}
}

#ifdef SHARED_HANDLERS

// ����� �׸��� �����մϴ�.
void CSlidingPuzzleDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// ������ �����͸� �׸����� �� �ڵ带 �����Ͻʽÿ�.
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

// �˻� ó���⸦ �����մϴ�.
void CSlidingPuzzleDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������ �����Ϳ��� �˻� �������� �����մϴ�.
	// ������ �κ��� ";"�� ���еǾ�� �մϴ�.

	// ��: strSearchContent = _T("point;rectangle;circle;ole object;");
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


// CSlidingPuzzleDoc ����

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


// CSlidingPuzzleDoc ���
