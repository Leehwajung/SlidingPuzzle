#pragma once

#include "TileBlock.h"

namespace SlidingPuzzleSpace
{
#define DEFAULT_BLANK	0	// Ÿ���� ���� ������ 0�� �־� ���´�.

	class TileBlockRepo
	{
	public:
		TileBlockRepo(int height, int width, 
			TileID blankID = DEFAULT_BLANK, TileID startID = DEFAULT_START_ID);
		~TileBlockRepo();


		/* Operator */

		// ����� ����
		TileBlock* operator[](int index) const;


		/* Accessors */

		// ���� ����� ����
		int getSize();

		// ������ �ʺ�
		int getWidth();

		// ������ ����
		int getHeight();


	private:
		/* Attributes */
		int m_Width = 0;	// ������ �ʺ�
		int m_Height = 0;	// ������ ����


		/* Support */
		TileBlock *m_BlockRepo = nullptr;	// ��ü ��ϵ��� ������� ������ �ִ� ����� �迭
	};



	inline TileBlockRepo::TileBlockRepo(int height, int width, 
		TileID blankID/* = DEFAULT_BLANK*/, TileID startID/* = DEFAULT_START_ID*/)
		:m_Height(height), m_Width(width)
	{
		TileBlock::resetStartID(startID);
		int size = height * width;
		m_BlockRepo = new TileBlock[size];
		for (int i = 0; i < size; i++) {
			if (m_BlockRepo[i].getID() == blankID) {
				m_BlockRepo[i].setBlank();
				break;
			}
		}
	}

	inline TileBlockRepo::~TileBlockRepo()
	{
		if (m_BlockRepo) {
			delete[] m_BlockRepo;
		}
	}

	inline TileBlock* TileBlockRepo::operator[](int index) const
	{
		return &m_BlockRepo[index];
	}

	inline int TileBlockRepo::getSize()
	{
		return m_Width * m_Height;
	}

	inline int TileBlockRepo::getWidth()
	{
		return m_Width;
	}

	inline int TileBlockRepo::getHeight()
	{
		return m_Height;
	}



	typedef TileBlockRepo* TileBlockRepoPtr;
}