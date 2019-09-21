#pragma once
#include "Singleton.h"

class Actor;

class ActorManager :
	public Singleton<ActorManager>
{
private:
	std::list< Actor* > m_listActors;

public:
	ActorManager() {}
	~ActorManager() { Reset(); }

	// �� ���͸� �����մϴ�.
	// DEFAULT_COMPONENT ��ũ�� �ɼ��� ���� �⺻���� ���Ϳ� ������ ������Ʈ��
	// ������ �� �ֽ��ϴ�.
	Actor* Create(_tag_type tag = -1, bool isVisible = true, bool isActive = true, int layer = 0);
	Actor* Create(_tag_type tag, int layer);

	// �� �� ���͸� �����մϴ�.
	Actor* CreateEmpty(_tag_type tag = -1, bool isVisible = true, bool isActive = true);

	// �±׿� �´� ���͸� �����ɴϴ�.
	// ���� ù��°�� �����ϴ� ��ü�� �����ɴϴ�.
	Actor* FindActor(_tag_type tag);

	int GetSize() { return m_listActors.size(); }

	void Update();
	void Reset();

	PropertyG(GetSize) int Size;
};

#define ACTORMANAGER ActorManager::GetInstance()