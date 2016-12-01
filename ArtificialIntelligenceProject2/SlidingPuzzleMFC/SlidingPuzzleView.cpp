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
	ON_WM_TIMER()
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
	
	float xSize = float(cliRect.Width()) / float(pPuzzle->getWidth());
	float ySize = float(cliRect.Height()) / float(pPuzzle->getHeight());
	
	// TODO: �Ʒ��� CPuzzleBlockRect�� ����ϵ��� �����丵�ϱ�
	const Pen pen(Color::Black);
	const SolidBrush brush(Color::Black);
	TileBlockPtr **blocks = pDoc->m_pPuzzle->getCurrNode()->getBlocks();
	for (int i = 0; i < PUZZLESIZE; i++) {
		for (int j = 0; j < PUZZLESIZE; j++) {
			const RectF drawingArea(xSize * i, ySize * j, xSize, ySize);
			canvas.DrawRectangle(&pen, drawingArea);

			TileID id = blocks[j][i]->getID();
			if (id != 0) {
				CString num;
				FontFamily fontfamily(_T("Arial"));
				num.Format(_T("%d"), blocks[j][i]->getID());
				Gdiplus::Font font(&fontfamily, 50, FontStyleRegular, UnitPixel);
				Gdiplus::StringFormat format;
				//format.SetAlignment(StringAlignmentCenter);
				canvas.DrawString(num, num.GetLength(), &font, drawingArea, &format, &brush);
			}
		}
	}

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


// TODO: ������ ��ġ�� ã�Ƽ� �����丵�ϱ�
namespace	// �ܺο����� �������� �����ϱ� ���� ���� ���ӽ����̽�
{
	// TODO: ������ ��ġ�� ã�Ƽ� �����丵�ϱ�
	// �ڽ� Ȯ��
	void expandChild(SlidingPuzzle* pPuzzle, LinkedList& openList, NodePtr openHead)
	{
		pPuzzle->displace(openHead);
		Direction dirs[] = { Direction::UP, Direction::DOWN, Direction::LEFT, Direction::RIGHT };
		//NodePtr currNode = pPuzzle->getCurrNode();
		for (int i = 0; i < 4; i++) {
			NodePtr movedNode = new Node(*openHead, dirs[i], *pPuzzle->getGoal());
			if (!movedNode->equalsPred()) {
				pPuzzle->moveBlock(movedNode);
				openList.put(movedNode);
			}
			


			//if (pPuzzle->moveBlock(dirs[i])) {

			//}
		}
	}
}


// TODO: �ΰ����� �������� �ϵ��ڵ� �Ǿ� ������ ���߿� �ð� ���� ����ڰ� ������ ������ �� �ֵ��� �����ϱ�
void CSlidingPuzzleView::OnGameAI()
{
	CSlidingPuzzleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	//m_bAIMode = !m_bAIMode;	// TODO: �ΰ��������� �������� ���� �ϵ��ڵ��̴� ����� ���� �����ϰ� �����ϱ�

	m_pOpen = new LinkedList(TRUE);		// OPEN LIST
	m_pClose = new LinkedList(FALSE);	// CLOSE LIST
	
	m_pOpen->put(pDoc->m_pPuzzle->getCurrNode());
	Invalidate();		// ���� �׸���

	SetTimer(0, 1000, NULL);	// TODO: Ǯ�� �ӵ� �ٲٱ�
}


void CSlidingPuzzleView::OnUpdateGameAI(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	//pCmdUI->SetCheck(m_bAIMode);
	pCmdUI->SetCheck(TRUE);		// TODO: �ΰ��������� �������� ���� �ϵ��ڵ��̴� ����� ���� �����ϰ� �����ϱ�
}


// TODO: �ΰ����� �������� �ϵ��ڵ� �Ǿ� ������ ���߿� �ð� ���� ����ڰ� ������ ������ �� �ֵ��� �����ϱ�
void CSlidingPuzzleView::OnTimer(UINT_PTR nIDEvent)
{
	CSlidingPuzzleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	if (!pDoc->m_pPuzzle->isSolved()) {
		NodePtr openHead = m_pOpen->removeFirst();
		m_pClose->put(openHead);
		//pDoc->m_pPuzzle->undo();
		expandChild(pDoc->m_pPuzzle, *m_pOpen, openHead);
		Invalidate();
	}
	else {
		KillTimer(0);
		MessageBox(_T("�Ϸ�!"));
	}

	CView::OnTimer(nIDEvent);
}
