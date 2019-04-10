#ifndef __CASTARNODES_H__
#define __CASTARNODES_H__

#include "Defines.h"
#include "OgreVector3.h"

namespace Core
{
namespace AI
{
	class CAStarGrid;

	// AI Node class.
	class CORE_EXPORT CAStarNode
	{
		friend CAStarGrid;
	public:
		CAStarNode(const Vector3& Position, u32 NodeId);
		~CAStarNode();

		void	 SetPosition(const Vector3& Position) { m_Position = Position; }
		Vector3& GetPosition() { return m_Position; }

		void AddConnection(CAStarNode* Connection);						// Connect a one-way node to this node to the node passed.
		void RemoveConnection(CAStarNode* AStarNodes);					// Removes a node as connection.
		void RemoveAllConnections();									// Remove all connections.
		Vector<CAStarNode*>* GetConnections() { return &m_Connections; }// Returns a vector with the node connections.

		// Attributes
		void SetCost(f32 cost) { m_NodeCost = cost; }					// Sets the node cost.
		f32  GetCost() { return m_NodeCost; }							// Returns the node cost.
		int	 GetNodeId() { return m_NodeId; }

	protected:

		void		SetParent(CAStarNode* AStarNodes) { m_Parent = AStarNodes; }
		CAStarNode* GetParent() { return m_Parent; }
	
		CAStarNode*		m_Parent;
		f32				m_NodeCost;
		Vector3			m_Position;
		bool			m_Selected;
		int				m_NodeId;
		Vector<CAStarNode*> m_Connections;
	};
}
}

#endif // __CASTARNODES_H__