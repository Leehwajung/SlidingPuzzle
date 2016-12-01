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

// SlidingPuzzleView.h : CSlidingPuzzleView Ŭ������ �������̽�
//

#pragma once

using SlidingPuzzleSpace::LinkedList;

class CSlidingPuzzleDoc;

class CSlidingPuzzleView : public CView
{
// �����Դϴ�.
protected:	// serialization������ ��������ϴ�.
	CSlidingPuzzleView();
	DECLARE_DYNCREATE(CSlidingPuzzleView)

// Ư���Դϴ�.
public:
	CSlidingPuzzleDoc* GetDocument() const;
	BOOL m_bAIMode = FALSE;
	CPuzzleBlockRect **m_Blocks = NULL;
	CPuzzleBlockRect *m_BlockRepo = NULL;
	LinkedList *m_pOpen = NULL;
	LinkedList *m_pClose = NULL;
	LinkedList *m_pPath = NULL;
	int m_nPathLen = 0;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);	// �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// �����Դϴ�.
public:
	virtual ~CSlidingPuzzleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnGameAI();
	afx_msg void OnUpdateGameAI(CCmdUI *pCmdUI);
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // SlidingPuzzleView.cpp�� ����� ����
inline CSlidingPuzzleDoc* CSlidingPuzzleView::GetDocument() const
   { return reinterpret_cast<CSlidingPuzzleDoc*>(m_pDocument); }
#endif

