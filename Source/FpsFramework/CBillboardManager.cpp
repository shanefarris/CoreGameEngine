#include "CBillboardManager.h"
#include "CGameManager.h"
#include "IO/CoreLogging.h"

#include "OgreBillboardSet.h"
#include "OgreSceneNode.h"
#include "OgreSceneManager.h"
#include "OgreRenderQueue.h"
#include "OgreBillboard.h"

using namespace Core;

CBillboardManager* CBillboardManager::BillboardManager = nullptr;

CBillboardManager::CBillboardNodeSet::CBillboardNodeSet(s32 sz)
{
	set = nullptr;
	counter = 0;
	size = sz;
}

CBillboardManager::CBillboardNodeSet::~CBillboardNodeSet()
{
}

void CBillboardManager::CBillboardNodeSet::Update(const f32& elapsedTime)
{
	// Update buffer
	for (auto it = buffer.cbegin(); it != buffer.cend(); it++)
	{
		if ((*it)->bill != nullptr)
		{
			if((*it)->liveTime <= 0)
			{
				set->removeBillboard((*it)->bill);
				(*it)->bill = nullptr;
			}
			else
			{
				(*it)->liveTime -= elapsedTime;
			}
		}
	}
}

void CBillboardManager::CBillboardNodeSet::Finalize(SceneNode* parent)
{
	// Clear buffer
	for (u32 i = 0; i < buffer.size(); i++)
	{
		if (buffer[i]->bill != nullptr)
		{
			set->removeBillboard(buffer[i]->bill);
		}
		CORE_DELETE(buffer[i]);
	}
	buffer.clear();

	// Detach and remove set
	parent->detachObject(set);
	CGameManager::Instance()->GetSceneManager()->destroyBillboardSet(set);
	set = nullptr;
}

CBillboardManager::CBillboardNode::CBillboardNode() : bill(nullptr), liveTime(0)
{
}

CBillboardManager::CBillboardNode::~CBillboardNode()
{
}

CBillboardManager* CBillboardManager::Instance()
{
	if(!BillboardManager)
		BillboardManager = new CBillboardManager();
	return BillboardManager;
}

CBillboardManager::CBillboardManager() : m_BillNode(nullptr)
{
}

CBillboardManager::~CBillboardManager()
{
	Shutdown();
}

void CBillboardManager::Shutdown()
{
	try
	{
		//traverse all m_Sets and delete all
		auto it = m_Sets.begin();
		while (it != m_Sets.end()) 
		{
			auto nodeSet = (*it).second;
			if(nodeSet)
			{
				auto it2 = nodeSet->buffer.begin();
				while (it2 != nodeSet->buffer.end()) 
				{
					auto bbnode = (*it2);
					if(bbnode->bill)
						nodeSet->set->removeBillboard(bbnode->bill);
					CORE_DELETE(bbnode);
					it2++;
				}
				nodeSet->buffer.clear();
				CGameManager::Instance()->GetSceneManager()->destroyBillboardSet(nodeSet->set);
			}

			CORE_DELETE(nodeSet);
			m_Sets.erase(it++);
		}

		m_Sets.clear();

		//remove m_BillNode
		if(m_BillNode)
		{
			CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->removeAndDestroyChild(m_BillNode->getName());
			m_BillNode = nullptr;
		}
	}
	catch(std::exception& e)
	{
		CORE_ASSERT(false);
		throw(e);
	}
	catch(...)
	{
		throw("Error in CBillboardManager::Shutdown()");
	}
}

void CBillboardManager::CreateBillboard(const String& Name, u32 Type, u32 PoolSize, const String& MaterialName, const f32& Width, const f32& Height)
{
	if(!m_BillNode || m_BillNode->getName() == "")
		m_BillNode = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode("BillboardSystemNode");

	if(m_Sets.find(Name) == m_Sets.cend())
	{
		CBillboardNodeSet* bset = nullptr;
		try
		{
			bset = new CBillboardNodeSet(PoolSize);
			bset->set = CGameManager::Instance()->GetSceneManager()->createBillboardSet(Name, PoolSize);
			bset->set->setMaterialName(MaterialName);
			bset->set->setDefaultDimensions(Width, Height);
			bset->set->setBillboardType((BillboardType)Type);
			bset->set->setRenderQueueGroup(RENDER_QUEUE_SKIES_LATE);

			// TODO: make data-driven
			if(Type > 0)
				bset->set->setCommonDirection(Vector3::NEGATIVE_UNIT_Z);

			AxisAlignedBox aabInf;
			aabInf.setInfinite();
			bset->set->setBounds(aabInf, 1024);
			m_BillNode->attachObject(bset->set);

			// Create billboard buffer
			for (u32 i = 0; i < PoolSize; i++)
			{
				CBillboardNode* bbnode = new CBillboardNode();
				bset->buffer.push_back(bbnode);
			}

			m_Sets[Name] = bset;
		}
		catch(...)
		{
			CORE_DELETE(bset);
			CORE_ERR("Invalid billboard set.");
			return;
		}
	}
	else
	{
		String msg = "CBillboardManager::CreateBillboard trying to add a billboard of the same name: " + Name;
		CORE_ERR(msg.c_str());
	}
}

void CBillboardManager::Update(const f32& elapsedTime)
{
	for(auto it = m_Sets.cbegin(); it != m_Sets.cend(); it++) 
	{
		if((*it).second)
			(*it).second->Update(elapsedTime);
	}
}

int CBillboardManager::ShowBillboard(const char* name, const Vector3& Position, const f32& Time)
{
	//remove if exists
	CBillboardNodeSet* bset = m_Sets[String(name)];
	if(bset)
	{
		int ret = bset->counter;

		if (bset->GetCurrent()->bill != nullptr)
		{
			bset->set->removeBillboard(bset->GetCurrent()->bill);
		}

		bset->GetCurrent()->bill = bset->set->createBillboard(Position, ColourValue::White);
		bset->GetCurrent()->liveTime = Time;
		bset->IncCounter();

		return ret;
	}
	String msg = "CBillboardManager::ShowBillboard unable to find: " + String(name);
	CORE_ERR(msg.c_str());
	return -1;
}

void CBillboardManager::UpdateBillboard(const char* name, int id, const Vector3& Position)
{
	CBillboardNodeSet* bset = m_Sets[String(name)];
	if (bset->buffer[id]->bill != nullptr)
	{
		bset->buffer[id]->bill->setPosition(Position);
	}
}

void CBillboardManager::HideBillboard(const char* name, int id)
{
	CBillboardNodeSet* bset = m_Sets[String(name)];
	if (bset->buffer[id]->bill != nullptr)
	{
		bset->buffer[id]->liveTime = 0;
	}
}