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
#include "SlidingPuzzleApp.h"
#endif

#include "SlidingPuzzleDoc.h"
#include "SlidingPuzzleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define PADDING 10;

using namespace Gdiplus;
using namespace SlidingPuzzleSpace;


// CSlidingPuzzleView

IMPLEMENT_DYNCREATE(CSlidingPuzzleView, CView)

BEGIN_MESSAGE_MAP(CSlidingPuzzleView, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_GAME_AI, &CSlidingPuzzleView::OnGameAI)
	ON_UPDATE_COMMAND_UI(ID_GAME_AI, &CSlidingPuzzleView::OnUpdateGameAI)
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

void CSlidingPuzzleView::OnDraw(CDC* pDC)
{
	CSlidingPuzzleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// ��� ���
	Graphics graphicsDC(*pDC);	// gdi+ �׸��⸦ ���� ��ü https://msdn.microsoft.com/en-us/library/windows/desktop/ms534453(v=vs.85).aspx

	// Graphics ���� (for Double Buffering)
	CRect cliRect;
	GetClientRect(cliRect);
	Bitmap bmpCanvas(cliRect.right, cliRect.bottom);	// ĵ���� ��Ʈ�� ����
	Graphics canvas(&bmpCanvas);						// ĵ���� �׷��Ƚ� ����
	canvas.Clear(Color::White);							// ĵ���� ���� ����

	// Antialising
	canvas.SetSmoothingMode(SmoothingModeHighQuality);

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	SlidingPuzzle *pPuzzle = pDoc->m_pPuzzle;
	
	int xSize = cliRect.Width() / pPuzzle->getWidth();
	int ySize = cliRect.Height() / pPuzzle->getHeight();



	//pPuzzle->



	// ĵ���� �׸��� (for Double Buffering)
	graphicsDC.DrawImage(&bmpCanvas, cliRect.left, cliRect.top, cliRect.right, cliRect.bottom);	// ĵ���� �׸���
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



void CSlidingPuzzleView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CView::OnLButtonDown(nFlags, point);
}


void CSlidingPuzzleView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CView::OnLButtonUp(nFlags, point);
}


void CSlidingPuzzleView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CView::OnMouseMove(nFlags, point);
}


void CSlidingPuzzleView::OnGameAI()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_bAIMode = !m_bAIMode;
}


void CSlidingPuzzleView::OnUpdateGameAI(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	pCmdUI->SetCheck(m_bAIMode);
}
