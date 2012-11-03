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
	virtual void UpdateProperties();

	virtual lcNode* Clone();
	
	std::string GetName();
	void SetName(const char* a_pName);

	//Translate
	void SetTranslate(D3DXVECTOR3 a_kTranslate);
	D3DXVECTOR3 GetTranslate();

	//Rotate
	void SetRotate(D3DXMATRIX a_kRotate);
	D3DXMATRIX GetRotate();

	//Transform
	D3DXMATRIX GetTransform();

	//Parenting
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
	
	D3DXVECTOR3				m_kLocalTranslate;
	D3DXMATRIX				m_mLocalRotate;
	D3DXMATRIX				m_mLocalTransform;

	D3DXVECTOR3				m_mWorldTranslate;
	D3DXMATRIX				m_mWorldRotate;
	D3DXMATRIX				m_mWorldTransform;
};

////////////////////////////////////////////////////////////////////////////////
#endif//__LCNODE_H_