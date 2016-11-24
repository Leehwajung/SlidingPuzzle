#pragma once

// CPuzzleBlockRect ��� ����Դϴ�.

using SlidingPuzzleSpace::Direction;

class CPuzzleBlockRect : public CObject
{
public:
	CPuzzleBlockRect();
	CPuzzleBlockRect(int num);
	virtual ~CPuzzleBlockRect();

	/* Operations */

	void move(Direction dir);

	void draw(Gdiplus::Graphics& graphics);

	Gdiplus::RectF movingDraw(Gdiplus::Graphics& graphics, Gdiplus::PointF& originPoint, Gdiplus::PointF& targetPoint);

private:
	void draw(Gdiplus::Graphics& graphics, Gdiplus::RectF& drawingArea);

public:
	/* Mutators */
	void setNumber(int num);

	void move(Gdiplus::PointF& PointF);

	static void resize(Gdiplus::SizeF& SizeF);

	static void resize(Gdiplus::REAL width, Gdiplus::REAL height);

	void setFont(Gdiplus::Font* font);

	void setFontFill(Gdiplus::Brush* fontBrush);

	void setOutline(Gdiplus::Pen* outlinePen);

	void setFill(Gdiplus::Brush* fillBrush);

private:
	/* Attributes */
	int m_nNum = -1;						// ��� ��ȣ
	Gdiplus::PointF m_Point;				// ��� ��ġ (�»�� ��ǥ)
	static Gdiplus::SizeF m_Size;			// ��� ũ�� (��� ��� ����)
	Gdiplus::Pen* m_pOutline = nullptr;		// ������ ��
	Gdiplus::Brush* m_pFill = nullptr;		// ä��� �귯��
	Gdiplus::Brush* m_pFontFill = nullptr;	// ���� �׸��� �귯��
	Gdiplus::Font* m_pFont = nullptr;		// ���� ��Ʈ
};

inline void CPuzzleBlockRect::setNumber(int num)
{
	m_nNum = num;
}

inline void CPuzzleBlockRect::move(Gdiplus::PointF& PointF)
{
	m_Point = PointF;
}

inline void CPuzzleBlockRect::resize(Gdiplus::SizeF& SizeF)
{
	m_Size = SizeF;
}

inline void CPuzzleBlockRect::resize(Gdiplus::REAL width, Gdiplus::REAL height)
{
	m_Size.Width = width;
	m_Size.Height = height;
}

inline void CPuzzleBlockRect::setOutline(Gdiplus::Pen* outlinePen)
{
	m_pOutline = outlinePen;
}

inline void CPuzzleBlockRect::setFill(Gdiplus::Brush* fillBrush)
{
	m_pFill = fillBrush;
}

inline void CPuzzleBlockRect::setFontFill(Gdiplus::Brush* fontBrush)
{
	m_pFontFill = fontBrush;
}

inline void CPuzzleBlockRect::setFont(Gdiplus::Font* font)
{
	m_pFont = font;
}
