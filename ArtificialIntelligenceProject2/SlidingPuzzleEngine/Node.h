#pragma once
#include "State.h"

namespace SlidingPuzzleSpace
{
	/* 상태 (즉, 노드)
	 * n×m 타일블록을 하나의 클래스로 나타냄.
	 * 이는 2차원 배열을 필드로 가지는 클래스를 정의하여 이용함.
	 */
	class Node sealed : public State
	{
	public:
		Node(TileBlockRepo& repo, TileID* idArr = nullptr);
		~Node();

	private:
		double m_dblFhat = 0;
		double m_dblGhat = 0;
		double m_dblHhat = 0;
	};
}

