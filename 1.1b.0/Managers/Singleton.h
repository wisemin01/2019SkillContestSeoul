#pragma once

template <class T>
class Singleton
{
private:
	inline static T* pInstance = nullptr;

public:
	Singleton() {}
	virtual ~Singleton() {}

	static T& GetInstance()
	{
		if (pInstance == nullptr)
		{
			pInstance = new T();
		}

		return (*pInstance);
	}

	static void ReleaseInstance()
	{
		if (pInstance != nullptr)
		{
			delete pInstance;
			pInstance = nullptr;
		}
	}
};

#define RELEASE_INSTANCE_SINGLETON(MANAGER) MANAGER::ReleaseInstance()