#pragma once

#include "GameDefine.h"

// ˆÚ“®‘¬“x
#define PLAYERSHOT_SPEED	(0.4f)

class CPlayerShot{
private:
	CMeshContainer*		m_pMesh;
	Vector3				m_Pos;
	bool				m_bShow;
	Vector3 m_Speed;
public:
	CPlayerShot();
	~CPlayerShot();
	void Initialize();
	void Fire(const Vector3& p,Vector3 vec);
	void Update();
	void Render();
	void SetMesh(CMeshContainer *pm){ m_pMesh = pm; }
	bool GetShow(){ return m_bShow; }
};