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

	D3DXMatrixIdentity(&m_mLocalTranslate);
	D3DXMatrixIdentity(&m_mLocalRotate);
	D3DXMatrixIdentity(&m_mLocalTransform);

	D3DXMatrixIdentity(&m_mWorldTranslate);
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

	D3DXMatrixIdentity(&m_mLocalTranslate);
	D3DXMatrixIdentity(&m_mLocalRotate);
	D3DXMatrixIdentity(&m_mLocalTransform);

	D3DXMatrixIdentity(&m_mWorldTranslate);
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

lcNode* lcNode::Clone()
{
	lcNode* pClone = new lcNode;
	pClone->m_mLocalRotate = m_mLocalRotate;
	pClone->m_mLocalTransform = m_mLocalTransform;
	pClone->m_mLocalTranslate = m_mLocalTranslate;
	pClone->UpdateWorldTransform();

	return pClone;
}

//--------------------------------------------------------------------------------//

void lcNode::UpdateWorldTransform()
{
	D3DXMatrixMultiply(&m_mLocalTransform,&m_mLocalRotate,&m_mLocalTranslate);

	if(m_pParent)
	{
		return;	
	}

	m_mWorldTransform = m_mLocalTransform;
	m_mWorldTranslate = m_mLocalTranslate;
	m_mWorldRotate = m_mLocalRotate;
}

//--------------------------------------------------------------------------------//

void lcNode::AttachChild(lcNode* a_pChild)
{
	for(auto pChildIter = m_pChildren.begin();pChildIter != m_pChildren.end();++pChildIter)
	{
		if(*pChildIter == a_pChild)
		{
			D3DXMATRIX mInvWorldTransform;
			D3DXMatrixInverse(&mInvWorldTransform,0,&m_pParent->m_mWorldTransform);

			D3DXMatrixMultiply(&m_mWorldTransform,&m_mLocalTransform,&mInvWorldTransform);

			return;
		}
	}

	a_pChild->m_pParent = this;
	m_pChildren.push_back(a_pChild);
	m_uiChildCount++;

	//Mod Transform
	D3DXMatrixMultiply(&a_pChild->m_mLocalTranslate,&a_pChild->m_mLocalTranslate,&m_mWorldTranslate);

}

//--------------------------------------------------------------------------------//

void lcNode::DetachChild(lcNode* a_pChild)
{
	for(auto pChildIter = m_pChildren.begin();pChildIter != m_pChildren.end();++pChildIter)
	{
		if(*pChildIter == a_pChild)
		{
			//Mod Transform
			D3DXMATRIX mInvTransform;
			D3DXMatrixInverse(&mInvTransform,0,&m_mWorldTranslate);
			D3DXMatrixMultiply(&a_pChild->m_mLocalTranslate,&mInvTransform,&a_pChild->m_mLocalTranslate);
			

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

void lcNode::GetTransform(D3DXMATRIX& a_mTransform)
{
	a_mTransform = m_mLocalTransform;
}

//--------------------------------------------------------------------------------//

D3DXMATRIX lcNode::GetTransform()
{
	return m_mLocalTransform;
}

//--------------------------------------------------------------------------------//

void lcNode::SetTransform(D3DXMATRIX& a_mTransform)
{
	m_mLocalTransform = a_mTransform;
}

//--------------------------------------------------------------------------------//

void lcNode::GetTranslate(D3DXVECTOR3& a_vPosition)
{
	a_vPosition = D3DXVECTOR3(m_mLocalTranslate._41,m_mLocalTranslate._42,m_mLocalTranslate._43);
}

//--------------------------------------------------------------------------------//

D3DXVECTOR3 lcNode::GetTranslate()
{
	return D3DXVECTOR3(m_mLocalTranslate._41,m_mLocalTranslate._42,m_mLocalTranslate._43);
}

//--------------------------------------------------------------------------------//

void lcNode::SetTranslate(D3DXVECTOR3& a_vPosition)
{
	D3DXMatrixTranslation(&m_mLocalTranslate,a_vPosition.x,a_vPosition.y,a_vPosition.z);
}

//--------------------------------------------------------------------------------//

void lcNode::SetTranslate(float a_fX,float a_fY,float a_fZ)
{
	D3DXMatrixTranslation(&m_mLocalTranslate,a_fX,a_fY,a_fZ);
}

//--------------------------------------------------------------------------------//

void lcNode::GetRotate(D3DXMATRIX& a_mRotation)
{
	a_mRotation = m_mLocalRotate;
}

//--------------------------------------------------------------------------------//

D3DXMATRIX lcNode::GetRotate()
{
	return m_mLocalRotate;
}

//--------------------------------------------------------------------------------//

void lcNode::SetRotate(D3DXMATRIX& a_mRotation)
{
	m_mLocalRotate = a_mRotation;
}

//--------------------------------------------------------------------------------//

void lcNode::SetRotate(D3DXQUATERNION& a_mRotation)
{
	D3DXMatrixRotationQuaternion(&m_mLocalRotate,&a_mRotation);
}

//--------------------------------------------------------------------------------//

void lcNode::SetRotateX(float a_fAngle)
{
	D3DXMatrixRotationX(&m_mLocalRotate,a_fAngle);
}

//--------------------------------------------------------------------------------//

void lcNode::SetRotateY(float a_fAngle)
{
	D3DXMatrixRotationY(&m_mLocalRotate,a_fAngle);
}

//--------------------------------------------------------------------------------//

void lcNode::SetRotateZ(float a_fAngle)
{
	D3DXMatrixRotationZ(&m_mLocalRotate,a_fAngle);
}

//--------------------------------------------------------------------------------//

void lcNode::GetWorldTransform(D3DXMATRIX& a_mTransform)
{
	a_mTransform = m_mWorldTransform;
}

//--------------------------------------------------------------------------------//

D3DXMATRIX lcNode::GetWorldTransform()
{
	return m_mWorldTransform;
}

//--------------------------------------------------------------------------------//

void lcNode::GetWorldTranslate(D3DXVECTOR3& a_vPosition)
{
	a_vPosition = D3DXVECTOR3(m_mWorldTranslate._41,m_mWorldTranslate._42,m_mWorldTranslate._43);
}

//--------------------------------------------------------------------------------//

D3DXVECTOR3 lcNode::GetWorldTranslate()
{
	return D3DXVECTOR3(m_mWorldTranslate._41,m_mWorldTranslate._42,m_mWorldTranslate._43);
}

//--------------------------------------------------------------------------------//

void lcNode::GetWorldRotate(D3DXMATRIX& a_mRotation)
{
	a_mRotation = m_mWorldRotate;
}

//--------------------------------------------------------------------------------//

D3DXMATRIX lcNode::GetWorldRotate()
{
	return m_mWorldRotate;
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