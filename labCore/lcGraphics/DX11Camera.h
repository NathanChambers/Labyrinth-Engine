//--------------------------------------------------------------------------------//
//
// \author      Nathan M. Chambers
// \date        21/04/2012
// \brief		DX11 Camera, Creates View and Projection Matrixies
//
//--------------------------------------------------------------------------------//
#ifndef __DX11CAMERA_H_
#define __DX11CAMERA_H_
//--------------------------------------------------------------------------------//
#include "../lcCore/Node.h"
//--------------------------------------------------------------------------------//

struct DX11Frustrum
{
	float m_fFieldOfView;
	float m_fScreenAspect;
	float m_fNear;
	float m_fFar;
};

//--------------------------------------------------------------------------------//

class DX11Camera : public Node
{
public:
	static DX11Camera* Create(DX11Frustrum Fustrum);
	void Release();

	void Update();
	static void FreeLookCamera(DX11Camera* TargetCamera,float MovementSpeed);

	void LookAt(D3DXVECTOR3 Target);

	void GetView(D3DXMATRIX& View);
	void GetProjection(D3DXMATRIX& Proj);
	void GetViewProj(D3DXMATRIX& ViewProj);

private:
	DX11Camera(DX11Frustrum a_oFustrum);
	~DX11Camera();

	DX11Frustrum m_oFustrum;
	D3DXMATRIX m_mView;
	D3DXMATRIX m_mProj;

};

//--------------------------------------------------------------------------------//
#endif//__DX11CAMERA_H_
//--------------------------------------------------------------------------------//