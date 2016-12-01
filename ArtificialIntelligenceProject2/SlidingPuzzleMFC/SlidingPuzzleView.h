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

// SlidingPuzzleView.h : CSlidingPuzzleView 클래스의 인터페이스
//

#pragma once


class CSlidingPuzzleView : public CView
{
// 생성입니다.
protected:	// serialization에서만 만들어집니다.
	CSlidingPuzzleView();
	DECLARE_DYNCREATE(CSlidingPuzzleView)

// 특성입니다.
public:
	CSlidingPuzzleDoc* GetDocument() const;
	BOOL m_bAIMode = TRUE;	// TODO: 시작을 인공지능으로 고정시켜 놓음, 사용자 입력으로 시작하도록 수정하기 (FALSE로 바꾸기)
	CPuzzleBlockRect **m_Blocks = NULL;
	CPuzzleBlockRect *m_BlockRepo = NULL;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);	// 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 구현입니다.
public:
	virtual ~CSlidingPuzzleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnGameAI();
	afx_msg void OnUpdateGameAI(CCmdUI *pCmdUI);
};

#ifndef _DEBUG  // SlidingPuzzleView.cpp의 디버그 버전
inline CSlidingPuzzleDoc* CSlidingPuzzleView::GetDocument() const
   { return reinterpret_cast<CSlidingPuzzleDoc*>(m_pDocument); }
#endif

