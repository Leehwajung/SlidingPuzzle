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

// SlidingPuzzleView.cpp : CSlidingPuzzleView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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


// CSlidingPuzzleView 생성/소멸

CSlidingPuzzleView::CSlidingPuzzleView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CSlidingPuzzleView::~CSlidingPuzzleView()
{
}

BOOL CSlidingPuzzleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}


// CSlidingPuzzleView 그리기

void CSlidingPuzzleView::OnDraw(CDC* /*pDC*/)
{
	CSlidingPuzzleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CSlidingPuzzleView 진단

#ifdef _DEBUG
void CSlidingPuzzleView::AssertValid() const
{
	CView::AssertValid();
}

void CSlidingPuzzleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSlidingPuzzleDoc* CSlidingPuzzleView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSlidingPuzzleDoc)));
	return (CSlidingPuzzleDoc*)m_pDocument;
}
#endif //_DEBUG


// CSlidingPuzzleView 메시지 처리기

