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

// SlidingPuzzleView.cpp : CSlidingPuzzleView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "SlidingPuzzle.h"
#endif

#include "SlidingPuzzleDoc.h"
#include "SlidingPuzzleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSlidingPuzzleView

IMPLEMENT_DYNCREATE(CSlidingPuzzleView, CView)

BEGIN_MESSAGE_MAP(CSlidingPuzzleView, CView)
END_MESSAGE_MAP()


// CSlidingPuzzleView ����/�Ҹ�

CSlidingPuzzleView::CSlidingPuzzleView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CSlidingPuzzleView::~CSlidingPuzzleView()
{
}

BOOL CSlidingPuzzleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}


// CSlidingPuzzleView �׸���

void CSlidingPuzzleView::OnDraw(CDC* /*pDC*/)
{
	CSlidingPuzzleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CSlidingPuzzleView ����

#ifdef _DEBUG
void CSlidingPuzzleView::AssertValid() const
{
	CView::AssertValid();
}

void CSlidingPuzzleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSlidingPuzzleDoc* CSlidingPuzzleView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSlidingPuzzleDoc)));
	return (CSlidingPuzzleDoc*)m_pDocument;
}
#endif //_DEBUG


// CSlidingPuzzleView �޽��� ó����

