#pragma once

#include "GameDefine.h"
#include "PlayerShot.h"
#include "Enemy.h"

// �ړ����x
#define PLAYER_SPEED		(0.1f)

#define PLAYERSHOT_COUNT (40)
#define PLAYERSHOT_WAIT (5)

class CPlayer{
private:
	CMeshContainer	m_Mesh;
	CVector3		m_Pos;
	float			m_RotZ;

	CMeshContainer m_ShotMesh;
	CPlayerShot m_ShotArray[PLAYERSHOT_COUNT];
	int m_ShotWait;

	float m_Speed;

	int m_ShotMode;

	bool m_bDead;
public:
	CPlayer();
	~CPlayer();
	bool Load();
	void Initialize();
	void Update();
	void Render();
	void RenderDebugText();
	const CVector3 GetPosition(){ return m_Pos; }
	void Release();

	void UpdateSingleShot();
	void UpdateDoubleShot();
	void UpdateTrippleShot();

	void UpdateMode();

	void RenderDebug();
	CSphere GetSphere() { return CSphere(m_Pos, 0.4f); }
	void CollisionEnemy(CEnemy& ene);
	bool IsDead() { return m_bDead; }
	void CollisionEnemyShot(CEnemyShot& shot);
};