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
#include "SlidingPuzzleApp.h"
#endif

#include "MainFrm.h"
#include "SlidingPuzzleView.h"
#include "SlidingPuzzleDoc.h"

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

void CSlidingPuzzleView::OnDraw(CDC* pDC)
{
	CSlidingPuzzleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// 출력 대상
	Graphics graphicsDC(*pDC);	// gdi+ 그리기를 위한 객체 https://msdn.microsoft.com/en-us/library/windows/desktop/ms534453(v=vs.85).aspx

	// Graphics 설정 (for Double Buffering)
	CRect cliRect;
	GetClientRect(cliRect);
	Bitmap bmpCanvas(cliRect.right, cliRect.bottom);	// 캔버스 비트맵 생성
	Graphics canvas(&bmpCanvas);						// 캔버스 그래픽스 생성
	canvas.Clear(Color::White);							// 캔버스 배경색 지정

	// Antialising
	canvas.SetSmoothingMode(SmoothingModeHighQuality);

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	SlidingPuzzle *pPuzzle = pDoc->m_pPuzzle;
	
	float xSize = float(cliRect.Width()) / float(pPuzzle->getWidth());
	float ySize = float(cliRect.Height()) / float(pPuzzle->getHeight());
	
	// TODO: 아래를 CPuzzleBlockRect를 사용하도록 리펙토링하기
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

	// 캔버스 그리기 (for Double Buffering)
	graphicsDC.DrawImage(&bmpCanvas, cliRect.left, cliRect.top, cliRect.right, cliRect.bottom);	// 캔버스 그리기
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



void CSlidingPuzzleView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CView::OnLButtonDown(nFlags, point);
}


void CSlidingPuzzleView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CView::OnLButtonUp(nFlags, point);
}


void CSlidingPuzzleView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CView::OnMouseMove(nFlags, point);
}


// TODO: 적당한 위치를 찾아서 리펙토링하기
namespace	// 외부에서의 엑세스를 제한하기 위한 무명 네임스페이스
{
	// TODO: 적당한 위치를 찾아서 리펙토링하기
	// 자식 확장
	void expandChild(SlidingPuzzle* pPuzzle, LinkedList& openList, NodePtr openHead)
	{
		pPuzzle->displace(openHead);
		Direction dirs[] = { Direction::UP, Direction::DOWN, Direction::LEFT, Direction::RIGHT };
		for (int i = 0; i < 4; i++) {
			NodePtr movedNode = new Node(*openHead, dirs[i], *pPuzzle->getGoal());
			if (!movedNode->equalsPred()) {
				pPuzzle->moveBlock(movedNode);
				openList.put(movedNode);
			}
		}
	}
}


// TODO: 인공지능 동작으로 하드코딩 되어 있으니 나중에 시간 나면 사용자가 퍼즐을 움직일 수 있도록 수정하기
void CSlidingPuzzleView::OnGameAI()
{
	CSlidingPuzzleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	COutputWnd &WndOutput = ((CMainFrame*)AfxGetApp()->m_pMainWnd)->GetWndOutput();
	WndOutput.AddResult(_T("인공지능 퍼즐 풀이를 시작합니다."));

	//m_bAIMode = !m_bAIMode;	// TODO: 인공지능으로 고정시켜 놓은 하드코딩이니 사용자 선택 가능하게 수정하기
	m_bAIMode = TRUE;

	Invalidate();	// 퍼즐 그리기

	// A*를 이용한 경로 찾기
	m_pOpen = new LinkedList(TRUE);		// OPEN LIST
	m_pClose = new LinkedList(FALSE);	// CLOSE LIST
	
	SlidingPuzzle *pPuzzle = pDoc->m_pPuzzle;

	m_pOpen->put(pPuzzle->getCurrNode());

	while (!pPuzzle->isSolved()) {
		NodePtr openHead = m_pOpen->removeFirst();
		m_pClose->put(openHead);
		expandChild(pPuzzle, *m_pOpen, openHead);
	}

	// 찾은 경로
	m_pPath = new LinkedList(FALSE);
	NodePtr curr = pPuzzle->getCurrNode();
	while (curr->getPred()) {
		m_pPath->put(curr);
		curr = (NodePtr) curr->getPred();
	}

	WndOutput.AddResult(_T("퍼즐을 풀기 위한 최적의 방안(경로)을 찾았습니다."));

	// 찾은 경로를 화면으로 보여주기
	m_nPathLen = 0;
	pDoc->initializePuzzle();
	SetTimer(0, 1000, NULL);	// TODO: 풀이 속도 바꾸기 기능 추가
}


void CSlidingPuzzleView::OnUpdateGameAI(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(m_bAIMode);
}


// TODO: 인공지능 동작으로 하드코딩 되어 있으니 나중에 시간 나면 사용자가 퍼즐을 움직일 수 있도록 수정하기
void CSlidingPuzzleView::OnTimer(UINT_PTR nIDEvent)
{
	CSlidingPuzzleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	COutputWnd &WndOutput = ((CMainFrame*)AfxGetApp()->m_pMainWnd)->GetWndOutput();

	if (!pDoc->m_pPuzzle->isSolved()) {
		m_nPathLen++;
		pDoc->m_pPuzzle->moveBlock(m_pPath->removeFirst());
		Invalidate();	// 퍼즐 그리기
		WndOutput.AddResult(_T("블록을 이동합니다."));
	}
	else {
		CString result;
		result.Format(_T("퍼즐을 완성하였습니다. 블록 이동 횟수는 %d회입니다."), m_nPathLen);
		WndOutput.AddResult(result);

		if (m_pPath) {
			delete m_pPath;
		}
		KillTimer(0);

		result.Format(_T("Success!!\nNumber of moves required = %d"), m_nPathLen);
		MessageBox(result, _T("This is goal!"));

		m_nPathLen = 0;
		m_bAIMode = FALSE;

		WndOutput.AddResult(_T("인공지능 퍼즐 풀이를 종료합니다."));
	}

	CView::OnTimer(nIDEvent);
}
