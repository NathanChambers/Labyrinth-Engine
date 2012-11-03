//--------------------------------------------------------------------------------//
//
// \author      Nathan M. Chambers
// \date        21/04/2012
// \brief		DX11 Camera, Creates View and Projection Matrixies
//
//--------------------------------------------------------------------------------//
#include "lcCamera.h"
#include "lcMouse.h"
#include "lcKeyboard.h"
#include "lcTimers.h"
#include "lmCore.h"
//--------------------------------------------------------------------------------//

lcCamera* lcCamera::Create(const lcFrustrum& a_kFustrum)
{
	lcCamera* pCamera = new lcCamera(a_kFustrum);
	return pCamera;
}

//--------------------------------------------------------------------------------//

void lcCamera::Release()
{
	delete this;
}

//--------------------------------------------------------------------------------//

lcCamera::lcCamera(const lcFrustrum& a_oFustrum)
{
	m_oFustrum = a_oFustrum;
}

//--------------------------------------------------------------------------------//

lcCamera::~lcCamera()
{

}

//--------------------------------------------------------------------------------//

void lcCamera::Update()
{
	D3DXVECTOR3 vUp(0.0f,1.0f,0.0f);
	D3DXVECTOR3 vLookAt(0.0f,0.0f,1.0f);

	D3DXVec3TransformCoord(&vLookAt,&vLookAt,&m_mLocalRotate);
	D3DXVec3TransformCoord(&vUp,&vUp,&m_mLocalRotate);

	D3DXVECTOR3 vCamPos = GetTranslate();
	vLookAt = vCamPos + vLookAt;

	D3DXMatrixLookAtLH(&m_mView,&vCamPos,&vLookAt,&vUp);

	D3DXMatrixPerspectiveFovLH(&m_mProj,
		m_oFustrum.m_fFieldOfView,m_oFustrum.m_fScreenAspect,
		m_oFustrum.m_fNear,m_oFustrum.m_fFar);

	D3DXMatrixMultiply(&m_mViewProj,&m_mView,&m_mProj);
}

//--------------------------------------------------------------------------------//

void lcCamera::FreeLookCamera(lcCamera* TargetCamera,float a_fMovementSpeed,float a_fSensitivity)
{
	if(lcKeyboard::Get()->IsKeyDown(KEY_LSHIFT))
	{
		a_fMovementSpeed *= 2;
	}

	D3DXMATRIX mRotate = TargetCamera->GetRotate();
	D3DXVECTOR3 mTranslate = TargetCamera->GetTranslate();

	D3DXVECTOR3 vForward(mRotate._31,mRotate._32,mRotate._33);
	D3DXVECTOR3 vRight(mRotate._11,mRotate._12,mRotate._13);
	D3DXVECTOR3 vUp(0,1,0);

	if(lcKeyboard::IsKeyDown(KEY_LSHIFT))
		a_fMovementSpeed *= 2.0f;

	if(lcMouse::IsScrollingUp())
		mTranslate += vForward * a_fMovementSpeed * 0.5f;

	if(lcMouse::IsScrollingDown())
		mTranslate -= vForward * a_fMovementSpeed * 0.5f;
	
	if(lcKeyboard::IsKeyDown(KEY_W))
		mTranslate += vForward * lcTime::DeltaTime() * a_fMovementSpeed;
	
	if(lcKeyboard::IsKeyDown(KEY_S))
		mTranslate -= vForward * lcTime::DeltaTime() * a_fMovementSpeed;
	
	if(lcKeyboard::IsKeyDown(KEY_D))
		mTranslate += vRight * lcTime::DeltaTime() * a_fMovementSpeed;
	
	if(lcKeyboard::IsKeyDown(KEY_A))
		mTranslate -= vRight * lcTime::DeltaTime() * a_fMovementSpeed;

	if(lcKeyboard::IsKeyDown(KEY_E))
		mTranslate += vUp * lcTime::DeltaTime() * a_fMovementSpeed;

	if(lcKeyboard::IsKeyDown(KEY_Q))
		mTranslate -= vUp * lcTime::DeltaTime() * a_fMovementSpeed;

	if(lcMouse::Get()->IsButtonDown(lcMouse::RIGHT))
	{
		int iXMovement,iYMovement;
		lcMouse::Get()->GetDeltaPosition(iXMovement,iYMovement);
		
		D3DXMATRIX mYaw;
		D3DXVECTOR3 vYAxis(0,1,0);
		D3DXMatrixRotationAxis(&mYaw,&vYAxis,(LM_PI * (iXMovement * (float)lcTime::DeltaTime() * a_fSensitivity)));
		D3DXMatrixMultiply(&mRotate,&mRotate,&mYaw);

		D3DXMATRIX mPitch;
		D3DXVECTOR3 vXAxis(mRotate._11,mRotate._12,mRotate._13);
		D3DXMatrixRotationAxis(&mPitch,&vXAxis,(LM_PI * (iYMovement * (float)lcTime::DeltaTime() * a_fSensitivity)));
		D3DXMatrixMultiply(&mRotate,&mRotate,&mPitch);
	}

	TargetCamera->SetRotate(mRotate);
	TargetCamera->SetTranslate(mTranslate);
}

//--------------------------------------------------------------------------------//

void lcCamera::LookAt(D3DXVECTOR3 a_vTarget)
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

void lcCamera::GetView(D3DXMATRIX& a_mView)
{
	a_mView = m_mView;
}

//--------------------------------------------------------------------------------//

void lcCamera::GetProjection(D3DXMATRIX& a_mProj)
{
	a_mProj = m_mProj;
}

//--------------------------------------------------------------------------------//

void lcCamera::GetViewProj(D3DXMATRIX& a_mViewProj)
{
	a_mViewProj = m_mViewProj;
}

//--------------------------------------------------------------------------------//