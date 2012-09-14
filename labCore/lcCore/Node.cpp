//--------------------------------------------------------------------------------//
//
// \author      Nathan M. Chambers
// \date        05/03/2012
// \brief		Basic Node Class
//
//--------------------------------------------------------------------------------//
#include "Node.h"
//--------------------------------------------------------------------------------//

Node::Node()
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

Node::Node(const char* a_pName)
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

Node::~Node()
{
	m_pChildren.empty();
}

//--------------------------------------------------------------------------------//

void Node::Update()
{
	UpdateWorldTransform();

	if(m_uiChildCount > 0)
	{
		for(unsigned int i = 0;i < m_uiChildCount;i++)
		{
			Node* pChild = GetAt(i);
			pChild->Update();
		}
	}
}

Node* Node::Clone()
{
	Node* pClone = new Node;
	pClone->m_mLocalRotate = m_mLocalRotate;
	pClone->m_mLocalTransform = m_mLocalTransform;
	pClone->m_mLocalTranslate = m_mLocalTranslate;
	pClone->UpdateWorldTransform();

	return pClone;
}

//--------------------------------------------------------------------------------//

void Node::UpdateWorldTransform()
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

void Node::AttachChild(Node* a_pChild)
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

void Node::DetachChild(Node* a_pChild)
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

Node* Node::GetAt(unsigned int a_uiIndex)
{
	auto oHead = m_pChildren.begin();
	for(unsigned int i = 0;i < a_uiIndex;i++)
	{
		oHead++;
	}

	return *oHead;
}

//--------------------------------------------------------------------------------//

void Node::SetName(const char* a_pName)
{
	m_sName = a_pName;
}

//--------------------------------------------------------------------------------//

std::string Node::GetName()
{
	return m_sName;
}

//--------------------------------------------------------------------------------//

Node* Node::GetParent()
{
	return m_pParent;
}

//--------------------------------------------------------------------------------//

void Node::GetTransform(D3DXMATRIX& a_mTransform)
{
	a_mTransform = m_mLocalTransform;
}

//--------------------------------------------------------------------------------//

D3DXMATRIX Node::GetTransform()
{
	return m_mLocalTransform;
}

//--------------------------------------------------------------------------------//

void Node::SetTransform(D3DXMATRIX& a_mTransform)
{
	m_mLocalTransform = a_mTransform;
}

//--------------------------------------------------------------------------------//

void Node::GetTranslate(D3DXVECTOR3& a_vPosition)
{
	a_vPosition = D3DXVECTOR3(m_mLocalTranslate._41,m_mLocalTranslate._42,m_mLocalTranslate._43);
}

//--------------------------------------------------------------------------------//

D3DXVECTOR3 Node::GetTranslate()
{
	return D3DXVECTOR3(m_mLocalTranslate._41,m_mLocalTranslate._42,m_mLocalTranslate._43);
}

//--------------------------------------------------------------------------------//

void Node::SetTranslate(D3DXVECTOR3& a_vPosition)
{
	D3DXMatrixTranslation(&m_mLocalTranslate,a_vPosition.x,a_vPosition.y,a_vPosition.z);
}

//--------------------------------------------------------------------------------//

void Node::SetTranslate(float a_fX,float a_fY,float a_fZ)
{
	D3DXMatrixTranslation(&m_mLocalTranslate,a_fX,a_fY,a_fZ);
}

//--------------------------------------------------------------------------------//

void Node::GetRotate(D3DXMATRIX& a_mRotation)
{
	a_mRotation = m_mLocalRotate;
}

//--------------------------------------------------------------------------------//

D3DXMATRIX Node::GetRotate()
{
	return m_mLocalRotate;
}

//--------------------------------------------------------------------------------//

void Node::SetRotate(D3DXMATRIX& a_mRotation)
{
	m_mLocalRotate = a_mRotation;
}

//--------------------------------------------------------------------------------//

void Node::SetRotate(D3DXQUATERNION& a_mRotation)
{
	D3DXMatrixRotationQuaternion(&m_mLocalRotate,&a_mRotation);
}

//--------------------------------------------------------------------------------//

void Node::SetRotateX(float a_fAngle)
{
	D3DXMatrixRotationX(&m_mLocalRotate,a_fAngle);
}

//--------------------------------------------------------------------------------//

void Node::SetRotateY(float a_fAngle)
{
	D3DXMatrixRotationY(&m_mLocalRotate,a_fAngle);
}

//--------------------------------------------------------------------------------//

void Node::SetRotateZ(float a_fAngle)
{
	D3DXMatrixRotationZ(&m_mLocalRotate,a_fAngle);
}

//--------------------------------------------------------------------------------//

void Node::GetWorldTransform(D3DXMATRIX& a_mTransform)
{
	a_mTransform = m_mWorldTransform;
}

//--------------------------------------------------------------------------------//

D3DXMATRIX Node::GetWorldTransform()
{
	return m_mWorldTransform;
}

//--------------------------------------------------------------------------------//

void Node::GetWorldTranslate(D3DXVECTOR3& a_vPosition)
{
	a_vPosition = D3DXVECTOR3(m_mWorldTranslate._41,m_mWorldTranslate._42,m_mWorldTranslate._43);
}

//--------------------------------------------------------------------------------//

D3DXVECTOR3 Node::GetWorldTranslate()
{
	return D3DXVECTOR3(m_mWorldTranslate._41,m_mWorldTranslate._42,m_mWorldTranslate._43);
}

//--------------------------------------------------------------------------------//

void Node::GetWorldRotate(D3DXMATRIX& a_mRotation)
{
	a_mRotation = m_mWorldRotate;
}

//--------------------------------------------------------------------------------//

D3DXMATRIX Node::GetWorldRotate()
{
	return m_mWorldRotate;
}

//--------------------------------------------------------------------------------//

unsigned int Node::GetChildCount()
{
	return m_uiChildCount;
}

//--------------------------------------------------------------------------------//

NodeIter Node::GetHead()
{
	return m_pChildren.begin();
}

//--------------------------------------------------------------------------------//

NodeIter Node::GetTail()
{
	return m_pChildren.end();
}

//--------------------------------------------------------------------------------//