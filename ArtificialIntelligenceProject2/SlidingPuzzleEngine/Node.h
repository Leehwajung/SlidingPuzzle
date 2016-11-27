#pragma once
#include "State.h"

namespace SlidingPuzzleSpace
{
	/* ���� (��, ���)
	* n��m Ÿ�Ϻ���� �ϳ��� Ŭ������ ��Ÿ��.
	* �̴� 2���� �迭�� �ʵ�� ������ Ŭ������ �����Ͽ� �̿���.
	*/
	class Node sealed : public State
	{
	public:
		Node(TileBlockRepoPtr repo, TileID* idArr /*= nullptr*/);
		~Node();

	private:
		double m_dblFhat = 0;
		double m_dblGhat = 0;
		double m_dblHhat = 0;
	};
}

