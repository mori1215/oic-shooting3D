#include "PlayerShot.h"

/**
 * コンストラクタ
 */
CPlayerShot::CPlayerShot() :
m_pMesh(NULL),
m_Pos(0.0f,0.0f,0.0f),
m_bShow(false),
m_Speed(0,0,0){
}

/**
 * デストラクタ
 */
CPlayerShot::~CPlayerShot(){
}

/**
 * 初期化
 */
void CPlayerShot::Initialize(void){
	m_Pos = Vector3(0.0f, 0.0f, 0.0f);
	m_bShow = false;
}

/**
 * 発射
 */
void CPlayerShot::Fire(const Vector3& p,Vector3 vec){
	m_Speed = vec;
	m_Pos = p;
	m_bShow = true;
}

/**
 * 更新
 */
void CPlayerShot::Update(void){
	if (!m_bShow)
	{
		return;
	}
	m_Pos += m_Speed;
	if (FIELD_HALF_Z < m_Pos.z)
	{
		m_bShow = false;
	}
}

/**
 * 描画
 */
void CPlayerShot::Render(void){
	if (!m_bShow)
	{
		return;
	}
	CMatrix44 wMat;
	wMat.Translation(m_Pos);
	m_pMesh->Render(wMat);
}

void CPlayerShot::RenderDebug()
{
	if (!m_bShow)
	{
		return;
	}
	CGraphicsUtilities::RenderSphere(GetSphere(), Vector4(0, 1, 0, 0.3f));
}
