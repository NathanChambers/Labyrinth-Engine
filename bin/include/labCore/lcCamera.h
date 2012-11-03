//--------------------------------------------------------------------------------//
//
// \author      Nathan M. Chambers
// \date        21/04/2012
// \brief		DX11 Camera, Creates View and Projection Matrixies
//
//--------------------------------------------------------------------------------//
#ifndef __LCCAMERA_H_
#define __LCCAMERA_H_
//--------------------------------------------------------------------------------//
#include "lcNode.h"
//--------------------------------------------------------------------------------//

struct lcFrustrum
{
	float m_fFieldOfView;
	float m_fScreenAspect;
	float m_fNear;
	float m_fFar;
};

//--------------------------------------------------------------------------------//

class lcCamera : public lcNode
{
public:
	static lcCamera* Create(const lcFrustrum& Fustrum);
	void Release();

	void Update();
	static void FreeLookCamera(lcCamera* TargetCamera,float MovementSpeed,float a_fSensitivity);

	void LookAt(D3DXVECTOR3 Target);

	void GetView(D3DXMATRIX& View);
	void GetProjection(D3DXMATRIX& Proj);
	void GetViewProj(D3DXMATRIX& ViewProj);

private:
	lcCamera(const lcFrustrum& Fustrum);
	~lcCamera();

	lcFrustrum m_oFustrum;
	D3DXMATRIX m_mView;
	D3DXMATRIX m_mProj;
	D3DXMATRIX m_mViewProj;

	float m_fMovementBoost;
};

//--------------------------------------------------------------------------------//
#endif//__DX11CAMERA_H_
//--------------------------------------------------------------------------------//