#ifndef __LCNODE_H_
#define __LCNODE_H_
////////////////////////////////////////////////////////////////////////////////
#include <D3DX11.h>
#include <D3DX10math.h>
#include <list>

#include "lcUtilities.h"
////////////////////////////////////////////////////////////////////////////////

class lcNode;
typedef std::list<lcNode*>::iterator NodeIter;

class lcNode
{
public:
	lcNode();
	lcNode(const char* a_pName);	
	virtual ~lcNode();	

	virtual void Update();
	virtual lcNode* Clone();
	
	std::string GetName();
	void SetName(const char* a_pName);

	D3DXMATRIX GetTransform();
	D3DXVECTOR3 GetTranslate();
	D3DXMATRIX GetRotate();
	D3DXMATRIX GetWorldTransform();
	D3DXVECTOR3 GetWorldTranslate();
	D3DXMATRIX GetWorldRotate();

	void GetTransform(D3DXMATRIX& Transform);
	void GetTranslate(D3DXVECTOR3& Position);
	void GetRotate(D3DXMATRIX& Rotation);
	void GetWorldTransform(D3DXMATRIX& Transform);
	void GetWorldTranslate(D3DXVECTOR3& Position);
	void GetWorldRotate(D3DXMATRIX& Rotation);

	void SetTransform(D3DXMATRIX& Transform);
	void SetTranslate(D3DXVECTOR3& Position);
	void SetTranslate(float X,float Y,float Z);

	void SetRotate(D3DXMATRIX& Rotation);
	void SetRotate(D3DXQUATERNION& Rotation);
	void SetRotateX(float Angle);
	void SetRotateY(float Angle);
	void SetRotateZ(float Angle);

	lcNode* GetParent();
	void AttachChild(lcNode*);
	void DetachChild(lcNode*);
	unsigned int GetChildCount();
	lcNode* GetAt(unsigned int a_uiIndex);
	NodeIter GetHead();
	NodeIter GetTail();

protected:
	void UpdateWorldTransform();

	std::string				m_sName;

	lcNode*					m_pParent;
	std::list<lcNode*>		m_pChildren;
	unsigned int			m_uiChildCount;
	
	D3DXMATRIX				m_mLocalTranslate;
	D3DXMATRIX				m_mLocalRotate;
	D3DXMATRIX				m_mLocalTransform;

	D3DXMATRIX				m_mWorldTranslate;
	D3DXMATRIX				m_mWorldRotate;
	D3DXMATRIX				m_mWorldTransform;
};

////////////////////////////////////////////////////////////////////////////////
#endif//__LCNODE_H_