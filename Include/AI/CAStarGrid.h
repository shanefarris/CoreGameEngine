#ifndef __CASTAR_GRID_H__
#define __CASTAR_GRID_H__

#include "Defines.h"

namespace Ogre
{
	class Vector3;
}

namespace Core
{
namespace AI
{
	class CAStarNode;

	class CORE_EXPORT CAStarGrid
	{
	public:
		static CAStarGrid* Instance();

		// Adds a path to the stack from the specified positions. Searches the nodegraph, and fills the specified stack with position vectors.
		bool CreatePath(Vector<Vector3>& Path, const Vector3& Start, const Vector3& End);	
		void AddNode(const Vector3& Position);
		void AddNodes(const Vector<Vector3>& Positions);
		void RemoveNode(int NodeId);
		void RemoveNode(const Vector3& Position, const f32& Threshold = 10.0f);
		void RemoveAllNodes();
		
		CAStarNode* GetStartNode();
		CAStarNode* GetEndNode();
		CAStarNode* GetNode(const Vector3& Position, const f32& Threshold = 3.0f);
		Vector<CAStarNode*>* GetNodes() { return &m_nodes; }								// Returns a vector of all nodes.

	private:
		CAStarGrid();
		~CAStarGrid();

		static CAStarGrid* AStarGrid;

		void SetNodeClosed(CAStarNode* AStarNodes);
		void SetNodeOpened(CAStarNode* AStarNodes);
		bool SetStartNode(const Vector3& start);
		bool SetEndNode(const Vector3& end);
		bool IsClosed(CAStarNode* AStarNodes);
		bool IsOpened(CAStarNode* AStarNodes);

		void ClearFromLists(CAStarNode* AStarNodes);
		CAStarNode& ClosestNode(const Vector3& Position);

		inline void RemoveNode(Vector<CAStarNode*>::iterator& nodeIterator);

		void Initialize();
		void Shutdown();
	
		CAStarNode*			m_pStartNode;
		CAStarNode*			m_pEndNode; 
		CAStarNode*			m_pCurrentNode;
		Vector<CAStarNode*> m_nodes;
		Vector<CAStarNode*> m_openList;
		Vector<CAStarNode*> m_closedList;
	};
}
}

#endif // __CASTAR_H__