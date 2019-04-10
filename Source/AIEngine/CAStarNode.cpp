#include "CAStarNode.h"

using namespace Core::AI;

CAStarNode::CAStarNode(const Vector3& Position, u32 NodeId) : m_Position(Position), m_NodeId(NodeId)
{
	m_Parent = nullptr;
	m_NodeCost = 0;
	m_Selected = false;
}

CAStarNode::~CAStarNode()
{
}

void CAStarNode::AddConnection(CAStarNode* AStarNodes)
{
	m_Connections.push_back(AStarNodes);
}

void CAStarNode::RemoveConnection(CAStarNode* AStarNodes)
{
	for(auto it = m_Connections.begin(); it != m_Connections.end(); it++)
	{
		if(AStarNodes == (*it))
		{
			m_Connections.erase(it);
			break;
		}
	}
}

void CAStarNode::RemoveAllConnections()
{
	while(m_Connections.empty() == false)
		m_Connections.pop_back();
}