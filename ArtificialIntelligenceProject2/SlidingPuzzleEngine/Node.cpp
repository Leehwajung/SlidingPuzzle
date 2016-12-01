#include "pch.h"
#include "Node.h"

namespace SlidingPuzzleSpace
{
	Node::Node(TileBlockRepo& repo, State& goal, TileID* idArr/* = nullptr*/)
		: State(repo, idArr)
	{
		calculateCosts(goal);
	}

	Node::Node(Node& pred, Direction& movingTargetPos, State& goal)
		: State(pred, movingTargetPos)
	{
		calculateCosts(goal);
	}

	Node::~Node()
	{
	}


}
