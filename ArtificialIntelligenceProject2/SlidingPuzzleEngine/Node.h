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
		/* Constructors / Destructor */

		// Constructor of First Node
		Node(TileBlockRepo& repo, State& goal, TileID* idArr = nullptr);
		
		// Constructor of Later Nodes
		Node(Node& pred, Direction& movingTargetPos, State& goal);

		// Destructor
		~Node();


		/* Accessors */

		// get f^
		double getFhat();

		// get g^
		double getGhat();

		// get h^
		double getHhat();


	private:
		/* Sub-Operation */

		// Calculate g^, h^ and f^
		void calculateCosts(State& goal);


		/* Attributes */
		double m_dblFhat = 0;	// f^
		double m_dblGhat = 0;	// g^
		double m_dblHhat = 0;	// h^
	};



	inline void Node::calculateCosts(State& goal)
	{
		m_dblGhat = getRound();
		m_dblHhat = getDiffSize(goal) - 1;
		m_dblFhat = m_dblGhat + m_dblGhat;
	}

	inline double Node::getFhat()
	{
		return m_dblFhat;
	}

	inline double Node::getGhat()
	{
		return m_dblGhat;
	}

	inline double Node::getHhat()
	{
		return m_dblHhat;
	}

	typedef Node* NodePtr;
}

