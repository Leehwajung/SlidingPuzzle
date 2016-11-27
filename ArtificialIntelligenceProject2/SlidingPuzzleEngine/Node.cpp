#include "pch.h"
#include "Node.h"

namespace SlidingPuzzleSpace
{
	Node::Node(TileBlockRepoPtr repo, TileID* idArr = nullptr)
		:State(repo, idArr)
	{
	}


	Node::~Node()
	{
	}
}
