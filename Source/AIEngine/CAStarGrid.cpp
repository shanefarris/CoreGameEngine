#include "CAStarGrid.h"
#include "CAStarNode.h"
#include "IO/CFileSystem.h"
#include "IO/IWriteFile.h"

#include "strsafe.h"

#include "OgreVector3.h"

using namespace Core::AI;

CAStarGrid* CAStarGrid::AStarGrid = nullptr;

CAStarGrid::CAStarGrid()
{
	Initialize();
}

CAStarGrid::~CAStarGrid()
{
	Shutdown();
}

void CAStarGrid::Initialize()
{
	m_pStartNode = nullptr;
	m_pEndNode = nullptr;
	m_pCurrentNode = nullptr;
}

void CAStarGrid::Shutdown()
{
	for(auto it = m_nodes.begin(); it != m_nodes.end();)
	{
		delete (*it);
		it = m_nodes.erase(it);
	}
}

CAStarGrid* CAStarGrid::Instance()
{
	if(!AStarGrid)
		AStarGrid = new CAStarGrid;
	return AStarGrid;
}

bool CAStarGrid::CreatePath(Vector<Vector3>& path, const Vector3& Start, const Vector3& End)
{
	// Set closest node from the specified position
	if(SetStartNode(Start) == false)
		return false;

	if(SetEndNode(End) == false)
		return false;

	m_pCurrentNode = m_pStartNode;

	// Add start node to open list
	SetNodeOpened(m_pStartNode);

	while(m_openList.empty() == false)
	{
		f32 cost = 0.0f;
		for(auto it = m_nodes.cbegin(); it != m_nodes.cend(); it++)
		{
			if(IsOpened((*it)))
			{
				if(cost == 0.0f)
				{
					m_pCurrentNode = (*it);
					cost = m_pCurrentNode->GetCost();
				}

				if((*it)->GetCost() < cost)
					m_pCurrentNode = (*it);
			}
		}

		// Path complete
		if(m_pCurrentNode == m_pEndNode) 
		{
			CAStarNode* node = m_pEndNode;
			while(node != m_pStartNode)
			{
				path.push_back(node->GetPosition());
				node = node->GetParent();
			}

			// Remove node from Open/Closed lists
			for(auto it = m_nodes.cbegin(); it != m_nodes.cend(); it++)
				ClearFromLists((*it));
		}
		else
		{
			SetNodeClosed(m_pCurrentNode);

			auto connections = m_pCurrentNode->GetConnections();
			for(auto it = connections->cbegin(); it != connections->cend(); it++)
			{
				if(IsClosed((*it)) == false && IsOpened((*it)) == false)
				{
					(*it)->SetParent(m_pCurrentNode);
					SetNodeOpened((*it));

					// Calculate and set cost
					Vector3 nodeVector = (*it)->GetPosition() - m_pCurrentNode->GetPosition();
					Vector3 endVector = m_pEndNode->GetPosition() - m_pCurrentNode->GetPosition();

					f32 nodeDistance = nodeVector.length();
					f32 endDistance = endVector.length();
					
					(*it)->SetCost(nodeDistance + endDistance + m_pCurrentNode->GetCost());
				}
			}
		}
	}

	return true;
}

bool CAStarGrid::SetStartNode(const Vector3& Start)
{
	m_pStartNode = &ClosestNode(Start);

	if(m_pStartNode)
		return true;

	return false;
}

bool CAStarGrid::SetEndNode(const Vector3& End)
{
	m_pEndNode = &ClosestNode(End);

	if(m_pEndNode)
		return true;

	return false;
}

CAStarNode& CAStarGrid::ClosestNode(const Vector3& Position)
{
	f32 currentLength = 100000.0f;
	Vector3 currentPos = Position;

	CAStarNode* node = nullptr;

	if(m_nodes.empty() == false)
	{
		for(auto it = m_nodes.cbegin(); it != m_nodes.cend(); it++)
		{
			Vector3 distance = currentPos - (*it)->GetPosition();
			float length = distance.squaredLength();

			if(length < currentLength)
			{
				currentLength = length;
				node = (*it);
			}
		}
	}

	return *node;
}

void CAStarGrid::AddNode(const Vector3& Position)
{
	auto node = new CAStarNode(Position, (u32)m_nodes.size());
	m_nodes.push_back(node);
}

void CAStarGrid::AddNodes(const Vector<Vector3>& Positions)
{
	for(auto it = Positions.cbegin(); it != Positions.cend(); it++)
		AddNode((*it));
}

CAStarNode* CAStarGrid::GetStartNode() 
{ 
	if(m_nodes.size() > 0)
		return m_nodes[0];
	return nullptr;
}

CAStarNode* CAStarGrid::GetEndNode() 
{ 
	if(m_nodes.size() > 1)
		return m_nodes[m_nodes.size() - 1];
	return nullptr;
}

void CAStarGrid::RemoveNode(int NodeId)
{
	if(NodeId > (s32)(m_nodes.size() / 2))
	{
		// Search in reverse order
		for(u32 i = (m_nodes.size() - 1); i > 0; i--)
		{
			if(m_nodes[i]->GetNodeId() == NodeId)
			{
				RemoveNode(m_nodes.begin() + i);
				return;
			}
		}
	}

	// Search for it in order
	for(auto it = m_nodes.begin(); it != m_nodes.end(); it++)
	{
		if((*it)->GetNodeId() == NodeId)
		{
			RemoveNode(it);
			return;
		}
	}
}

void CAStarGrid::RemoveNode(const Vector3& Position, const f32& Threshold)
{
	f32 currentLength = Threshold + 1.0f;
	Vector3 currentPos = Position;
	CAStarNode* node = nullptr;

	if(m_nodes.empty() == false)
	{
		for(auto it = m_nodes.begin(); it != m_nodes.end(); it++)
		{
			Vector3 distance = currentPos - (*it)->GetPosition();
			f32 length = distance.squaredLength();
			
			if(length < currentLength)
			{
				currentLength = length;
				node = (*it);
				if(currentLength <= Threshold)
				{
					RemoveNode(it);
					break;
				}
			}
		}
	}
}

void CAStarGrid::RemoveNode(Vector<CAStarNode*>::iterator& nodeIterator)
{
	for(auto it = m_nodes.begin(); it != m_nodes.end(); it++)
	{
		(*it)->RemoveConnection((*nodeIterator));
	}

	m_nodes.erase(nodeIterator);
	CORE_DELETE(*nodeIterator);
}

void CAStarGrid::RemoveAllNodes()
{
	Shutdown();
	Initialize();
}

CAStarNode* CAStarGrid::GetNode(const Vector3& Position, const f32& Threshold)
{
	for(auto it = m_nodes.cbegin(); it != m_nodes.cend(); it++)
	{
		f32 x = (*it)->GetPosition().x;
		f32 y = (*it)->GetPosition().y;
		f32 z = (*it)->GetPosition().z;
		if(x >= Position.x - Threshold && x <= Position.x + Threshold &&
			y >= Position.y - Threshold && y <= Position.y + Threshold &&
			z >= Position.z - Threshold && z <= Position.z + Threshold)
		{
			return (*it);
		}

	}
	return nullptr;
}

void CAStarGrid::SetNodeClosed(CAStarNode* AStarNodes)
{
	for(auto it = m_openList.begin(); it != m_openList.end(); it++)
	{
		if(AStarNodes == (*it))
		{
			m_openList.erase(it);
			break;
		}
	}

	m_closedList.push_back(AStarNodes);
}

void CAStarGrid::SetNodeOpened(CAStarNode* AStarNodes)
{
	m_openList.push_back(AStarNodes);
}

bool CAStarGrid::IsClosed(CAStarNode* AStarNodes)
{
	if(m_closedList.empty())
		return false;

	for(auto it = m_closedList.begin(); it != m_closedList.end(); it++)
	{
		if(AStarNodes == (*it))
			return true;
	}

	return false;
}

bool CAStarGrid::IsOpened(CAStarNode* AStarNodes)
{
	if(m_openList.empty())
		return false;

	for(auto it = m_openList.begin(); it != m_openList.end(); it++)
	{
		if(AStarNodes == (*it))
			return true;
	}

	return false;
}

void CAStarGrid::ClearFromLists(CAStarNode* AStarNodes)
{
	// Open list
	for(auto it = m_openList.begin(); it != m_openList.end(); it++)
	{
		if(AStarNodes == (*it))
		{
			m_openList.erase(it);
			break;
		}
	}

	// Closed list
	for(auto it = m_closedList.begin(); it != m_closedList.end(); it++)
	{
		if(AStarNodes == (*it))
		{
			m_closedList.erase(it);
			break;
		}
	}
}