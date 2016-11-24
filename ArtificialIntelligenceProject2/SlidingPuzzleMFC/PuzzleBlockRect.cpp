// PuzzleBlockRect.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "PuzzleBlockRect.h"
#include <cmath>	// for abs()

using namespace Gdiplus;

// CPuzzleBlockRect

SizeF CPuzzleBlockRect::m_Size;

CPuzzleBlockRect::CPuzzleBlockRect()
{
}

CPuzzleBlockRect::CPuzzleBlockRect(int num)
	: m_nNum(num)
{
}

CPuzzleBlockRect::~CPuzzleBlockRect()
{
}


// CPuzzleBlockRect 멤버 함수

void CPuzzleBlockRect::move(Direction dir)
{
	switch (dir)
	{
	case Direction::UP:
		break;
	case Direction::LEFT:
		break;
	case Direction::RIGHT:
		break;
	case Direction::DOWN:
		break;
	case Direction::NODIR:
		break;
	default:
		break;
	}
}

void CPuzzleBlockRect::draw(Graphics& graphics)
{
	RectF drawingArea(m_Point, m_Size);
	draw(graphics, drawingArea);
}

RectF CPuzzleBlockRect::movingDraw(Graphics& graphics, PointF& originPoint, PointF& targetPoint)
{
	PointF offset = targetPoint - originPoint;
	
	if (abs(offset.X) > abs(offset.Y)) {
		offset.Y = 0;
	}
	else {
		offset.X = 0;
	}

	RectF drawingArea(m_Point, m_Size);
	drawingArea.Offset(offset);

	draw(graphics, drawingArea);

	return drawingArea;
}

void CPuzzleBlockRect::draw(Graphics& graphics, RectF& drawingArea)
{
	if (m_pFill) {
		graphics.FillRectangle(m_pFill, drawingArea);
	}
	if (m_pOutline) {
		graphics.DrawRectangle(m_pOutline, drawingArea);
	}
	if (m_pFont && m_pFontFill) {
		CString num;
		num.Format(_T("%d"), m_nNum);
		StringFormat format;
		format.SetAlignment(StringAlignmentCenter);
		graphics.DrawString(num, num.GetLength(), m_pFont, drawingArea, &format, m_pFontFill);
	}
}


