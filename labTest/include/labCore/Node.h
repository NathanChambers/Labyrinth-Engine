//--------------------------------------------------------------------------------//
//
// \author      Nathan M. Chambers
// \date        05/03/2012
// \brief		Basic Node Class
//
//--------------------------------------------------------------------------------//
#ifndef __NODE_H_
#define __NODE_H_
//--------------------------------------------------------------------------------//
#include <list>
#include <D3DX11.h>
#include <D3DX10math.h>

#include "Utilities.h"
//--------------------------------------------------------------------------------//

class Node;
typedef std::list<Node*>::iterator NodeIter;

//--------------------------------------------------------------------------------//

class Node
{
public:
	Node();
	Node(const char* a_pName);	
	virtual ~Node();	

	virtual void Update();
	virtual Node* Clone();
	
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

	Node* GetParent();
	void AttachChild(Node*);
	void DetachChild(Node*);
	unsigned int GetChildCount();
	Node* GetAt(unsigned int a_uiIndex);
	NodeIter GetHead();
	NodeIter GetTail();

protected:
	void UpdateWorldTransform();

	std::string				m_sName;

	Node*					m_pParent;
	std::list<Node*>		m_pChildren;
	unsigned int					m_uiChildCount;
	
	D3DXMATRIX				m_mLocalTranslate;
	D3DXMATRIX				m_mLocalRotate;
	D3DXMATRIX				m_mLocalTransform;

	D3DXMATRIX				m_mWorldTranslate;
	D3DXMATRIX				m_mWorldRotate;
	D3DXMATRIX				m_mWorldTransform;
};

//--------------------------------------------------------------------------------//
#endif//__NODE_H_
//--------------------------------------------------------------------------------//