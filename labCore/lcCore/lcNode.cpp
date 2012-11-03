//--------------------------------------------------------------------------------//
//
// \author      Nathan M. Chambers
// \date        05/03/2012
// \brief		Basic lcNode Class
//
//--------------------------------------------------------------------------------//
#include "lcNode.h"
//--------------------------------------------------------------------------------//

lcNode::lcNode()
{
	m_uiChildCount = 0;
	m_pChildren.empty();
	m_pParent = 0;
	m_sName.empty();

	m_kLocalTranslate = D3DXVECTOR3(0,0,0);
	D3DXMatrixIdentity(&m_mLocalRotate);
	D3DXMatrixIdentity(&m_mLocalTransform);

	D3DXMatrixIdentity(&m_mWorldRotate);
	D3DXMatrixIdentity(&m_mWorldTransform);
}

//--------------------------------------------------------------------------------//

lcNode::lcNode(const char* a_pName)
{
	m_uiChildCount = 0;
	m_pChildren.empty();
	m_pParent = 0;
	m_sName = a_pName;

	m_kLocalTranslate = D3DXVECTOR3(0,0,0);
	D3DXMatrixIdentity(&m_mLocalRotate);
	D3DXMatrixIdentity(&m_mLocalTransform);

	D3DXMatrixIdentity(&m_mWorldRotate);
	D3DXMatrixIdentity(&m_mWorldTransform);
}

//--------------------------------------------------------------------------------//

lcNode::~lcNode()
{
	m_pChildren.empty();
}

//--------------------------------------------------------------------------------//

void lcNode::Update()
{
	UpdateWorldTransform();

	if(m_uiChildCount > 0)
	{
		for(unsigned int i = 0;i < m_uiChildCount;i++)
		{
			lcNode* pChild = GetAt(i);
			pChild->Update();
		}
	}
}

void lcNode::UpdateProperties()
{
	if(m_uiChildCount > 0)
	{
		for(auto pIter = m_pChildren.begin();pIter != m_pChildren.end();++pIter)
		{
			(*pIter)->UpdateProperties();
		}
	}
}

//--------------------------------------------------------------------------------//

void lcNode::UpdateWorldTransform()
{
	D3DXMATRIX kTranslationMatrix;
	D3DXMatrixTranslation(&kTranslationMatrix,m_kLocalTranslate.x,m_kLocalTranslate.y,m_kLocalTranslate.z);
	D3DXMatrixMultiply(&m_mLocalTransform,&m_mLocalRotate,&kTranslationMatrix);

	if(m_pParent)
	{
		m_mWorldTransform = m_mLocalTransform * m_pParent->m_mWorldTransform;
		return;	
	}

	m_mWorldTransform = m_mLocalTransform;
}

//--------------------------------------------------------------------------------//

lcNode* lcNode::Clone()
{
	lcNode* pClone = new lcNode;
	pClone->m_mLocalRotate = m_mLocalRotate;
	pClone->m_mLocalTransform = m_mLocalTransform;
	pClone->m_kLocalTranslate = m_kLocalTranslate;
	pClone->UpdateWorldTransform();

	return pClone;
}


//--------------------------------------------------------------------------------//

void lcNode::AttachChild(lcNode* a_pChild)
{
	//Change Local of Child
	D3DXMATRIX kInvRotate;
	float fDeterminant = D3DXMatrixDeterminant(&m_mLocalRotate);
	D3DXMatrixInverse(&kInvRotate,&fDeterminant,&m_mLocalRotate);
	a_pChild->m_kLocalTranslate -= m_kLocalTranslate;
	D3DXVec3TransformCoord(&a_pChild->m_kLocalTranslate,&a_pChild->m_kLocalTranslate,&kInvRotate);
	D3DXMatrixMultiply(&a_pChild->m_mLocalRotate,&a_pChild->m_mLocalRotate,&kInvRotate);
	
	a_pChild->m_pParent = this;
	m_pChildren.push_back(a_pChild);
	m_uiChildCount++;
}

//--------------------------------------------------------------------------------//

void lcNode::DetachChild(lcNode* a_pChild)
{
	for(auto pChildIter = m_pChildren.begin();pChildIter != m_pChildren.end();++pChildIter)
	{
		if(*pChildIter == a_pChild)
		{
			//Change Local of Child
			D3DXVec3TransformCoord(&a_pChild->m_kLocalTranslate,&a_pChild->m_kLocalTranslate,&m_mLocalRotate);
			D3DXMatrixMultiply(&a_pChild->m_mLocalRotate,&a_pChild->m_mLocalRotate,&m_mLocalRotate);
			a_pChild->m_kLocalTranslate += m_kLocalTranslate;

			a_pChild->m_pParent = NULL;
			m_pChildren.remove(a_pChild);
			m_uiChildCount--;
			return;
		}
	}
}

//--------------------------------------------------------------------------------//

lcNode* lcNode::GetAt(unsigned int a_uiIndex)
{
	auto oHead = m_pChildren.begin();
	for(unsigned int i = 0;i < a_uiIndex;i++)
	{
		oHead++;
	}

	return *oHead;
}

//--------------------------------------------------------------------------------//

void lcNode::SetName(const char* a_pName)
{
	m_sName = a_pName;
}

//--------------------------------------------------------------------------------//

D3DXMATRIX lcNode::GetTransform()
{
	return m_mWorldTransform;
}

//--------------------------------------------------------------------------------//

D3DXVECTOR3 lcNode::GetTranslate()
{
	return m_kLocalTranslate;
}

//--------------------------------------------------------------------------------//

D3DXMATRIX lcNode::GetRotate()
{
	return m_mLocalRotate;
}

//--------------------------------------------------------------------------------//

void lcNode::SetTranslate(D3DXVECTOR3 a_kTranslate)
{
	m_kLocalTranslate = a_kTranslate;
}

//--------------------------------------------------------------------------------//

void lcNode::SetRotate(D3DXMATRIX a_kRotation)
{
	m_mLocalRotate = a_kRotation;
}

//--------------------------------------------------------------------------------//

std::string lcNode::GetName()
{
	return m_sName;
}

//--------------------------------------------------------------------------------//

lcNode* lcNode::GetParent()
{
	return m_pParent;
}

//--------------------------------------------------------------------------------//

unsigned int lcNode::GetChildCount()
{
	return m_uiChildCount;
}

//--------------------------------------------------------------------------------//

NodeIter lcNode::GetHead()
{
	return m_pChildren.begin();
}

//--------------------------------------------------------------------------------//

NodeIter lcNode::GetTail()
{
	return m_pChildren.end();
}

//--------------------------------------------------------------------------------//