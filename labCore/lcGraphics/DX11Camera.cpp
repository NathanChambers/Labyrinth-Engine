//--------------------------------------------------------------------------------//
//
// \author      Nathan M. Chambers
// \date        21/04/2012
// \brief		DX11 Camera, Creates View and Projection Matrixies
//
//--------------------------------------------------------------------------------//
#include "DX11Camera.h"
#include "../lcInput/Mouse.h"
#include "../lcInput/Keyboard.h"
#include "../lcCore/Timers.h"
//--------------------------------------------------------------------------------//

DX11Camera* DX11Camera::Create(DX11Frustrum a_oFustrum)
{
	DX11Camera* pCamera = new DX11Camera(a_oFustrum);
	return pCamera;
}

//--------------------------------------------------------------------------------//

void DX11Camera::Release()
{
	delete this;
}

//--------------------------------------------------------------------------------//

DX11Camera::DX11Camera(DX11Frustrum a_oFustrum)
{
	m_oFustrum = a_oFustrum;
}

//--------------------------------------------------------------------------------//

DX11Camera::~DX11Camera()
{

}

//--------------------------------------------------------------------------------//

void DX11Camera::Update()
{
	D3DXVECTOR3 vUp(0.0f,1.0f,0.0f);
	D3DXVECTOR3 vLookAt(0.0f,0.0f,1.0f);

	D3DXVec3TransformCoord(&vLookAt,&vLookAt,&m_mLocalRotate);
	D3DXVec3TransformCoord(&vUp,&vUp,&m_mLocalRotate);

	D3DXVECTOR3 vCamPos;
	GetTranslate(vCamPos);
	vLookAt = vCamPos + vLookAt;

	D3DXMatrixLookAtLH(&m_mView,&vCamPos,&vLookAt,&vUp);

	D3DXMatrixPerspectiveFovLH(&m_mProj,
		m_oFustrum.m_fFieldOfView,m_oFustrum.m_fScreenAspect,
		m_oFustrum.m_fNear,m_oFustrum.m_fFar);
}

//--------------------------------------------------------------------------------//

void DX11Camera::FreeLookCamera(DX11Camera* TargetCamera,float a_fMovementSpeed)
{
	if(Keyboard::Get()->IsKeyDown((char)KEY_LSHIFT))
	{
		a_fMovementSpeed *= 2;
	}

	D3DXMATRIX mRotate = TargetCamera->GetRotate();
	D3DXVECTOR3 mTranslate = TargetCamera->GetTranslate();

	D3DXVECTOR3 vForward(mRotate._31,mRotate._32,mRotate._33);
	D3DXVECTOR3 vRight(mRotate._11,mRotate._12,mRotate._13);
	D3DXVECTOR3 vUp(0,1,0);

	if(Mouse::Get()->IsScrollingUp())
		mTranslate += vForward * a_fMovementSpeed;

	if(Mouse::Get()->IsScrollingDown())
		mTranslate -= vForward * a_fMovementSpeed;
	
	if(Keyboard::Get()->IsKeyDown(KEY_W))
		mTranslate += vForward * (float)GameTime::GetTimeElapsed() * a_fMovementSpeed;
	
	if(Keyboard::Get()->IsKeyDown(KEY_S))
		mTranslate -= vForward * (float)GameTime::GetTimeElapsed() * a_fMovementSpeed;
	
	if(Keyboard::Get()->IsKeyDown(KEY_D))
		mTranslate += vRight * (float)GameTime::GetTimeElapsed() * a_fMovementSpeed;
	
	if(Keyboard::Get()->IsKeyDown(KEY_A))
		mTranslate -= vRight * (float)GameTime::GetTimeElapsed() * a_fMovementSpeed;

	if(Keyboard::Get()->IsKeyDown(KEY_E))
		mTranslate += vUp * (float)GameTime::GetTimeElapsed() * a_fMovementSpeed;

	if(Keyboard::Get()->IsKeyDown(KEY_Q))
		mTranslate -= vUp * (float)GameTime::GetTimeElapsed() * a_fMovementSpeed;
	

	if(Mouse::Get()->IsButtonDown(Mouse::RIGHT))
	{
		int iXMovement,iYMovement;
		Mouse::Get()->GetDeltaPosition(iXMovement,iYMovement);
		
		D3DXMATRIX mYaw;
		D3DXVECTOR3 vYAxis(0,1,0);
		D3DXMatrixRotationAxis(&mYaw,&vYAxis,(3.145f * (iXMovement * (float)GameTime::GetTimeElapsed())) * a_fMovementSpeed);
		D3DXMatrixMultiply(&mRotate,&mRotate,&mYaw);

		D3DXMATRIX mPitch;
		D3DXVECTOR3 vXAxis(mRotate._11,mRotate._12,mRotate._13);
		D3DXMatrixRotationAxis(&mPitch,&vXAxis,(3.145f * (iYMovement * (float)GameTime::GetTimeElapsed())) * a_fMovementSpeed);
		D3DXMatrixMultiply(&mRotate,&mRotate,&mPitch);
	}

	TargetCamera->SetRotate(mRotate);
	TargetCamera->SetTranslate(mTranslate);
}

//--------------------------------------------------------------------------------//

void DX11Camera::LookAt(D3DXVECTOR3 a_vTarget)
{
	D3DXMATRIX mRotate = GetRotate();
	D3DXVECTOR3 mTranslate = GetTranslate();
	
	D3DXVECTOR3 vXAxis(1,0,0);//Right
	D3DXVECTOR3 vYAxis(0,1,0);//Up
	D3DXVECTOR3 vZAxis(0,0,1);//Forward

	D3DXVec3Subtract(&vZAxis,&a_vTarget,&mTranslate);
	D3DXVec3Normalize(&vZAxis,&vZAxis);

	D3DXVec3Cross(&vXAxis,&vYAxis,&vZAxis);
	D3DXVec3Cross(&vYAxis,&vZAxis,&vXAxis);
	
	D3DXMATRIX oRot(vXAxis.x,vXAxis.y,vXAxis.z,0.0f,
					vYAxis.x,vYAxis.y,vYAxis.z,0.0f,
					vZAxis.x,vZAxis.y,vZAxis.z,0.0f,
					0.0f,0.0f,0.0f,1.0f);


	//D3DXMatrixMultiply(&mRotate,&mRotate,&oRot);

	SetRotate(oRot);
}

//--------------------------------------------------------------------------------//

void DX11Camera::GetView(D3DXMATRIX& a_mView)
{
	a_mView = m_mView;
}

//--------------------------------------------------------------------------------//

void DX11Camera::GetProjection(D3DXMATRIX& a_mProj)
{
	a_mProj = m_mProj;
}

//--------------------------------------------------------------------------------//

void DX11Camera::GetViewProj(D3DXMATRIX& a_mProj)
{
	D3DXMatrixMultiply(&a_mProj,&m_mView,&m_mProj);
}

//--------------------------------------------------------------------------------//