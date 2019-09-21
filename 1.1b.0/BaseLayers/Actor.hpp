#pragma once
#include "../MDXIncludes.h"
#include "Actor.h"

template<class COM>
inline COM* Actor::AddComponent()
{
	uint identifier = get_component<COM>::type::GetComponentID();

	auto find = m_mapComponents.find(identifier);

	if (find == m_mapComponents.end())
	{
		COM* component = new COM();

		// TODO: initialize variable 'component'

		component->SetActor(this);
		component->Initialize();

		m_mapComponents.insert(std::make_pair(identifier, component));

		return component;
	}

	if constexpr (Debug::IsDebuging == true)
	{
		string context = "Actor::AddComponent<T>() : It already contains a component with the same unique key.\nDuplicate components : ";
		
		context += COM::GetStaticComponentName();
		context += ", ";
		context += find->second->GetComponentName();

		throw already_exists_exception(context.c_str());
	}

	return nullptr;
}

template<class COM>
inline COM* Actor::GetComponent()
{
	uint identifier = get_component<COM>::type::GetComponentID();

	if (auto find = m_mapComponents.find(identifier); find != m_mapComponents.end())
	{
		return static_cast<COM*>(find->second);
	}

	return nullptr;
}

template<class COM, typename ...Args>
inline COM* Actor::AddComponent(Args ...args)
{
	uint identifier = get_component<COM>::type::GetComponentID();

	if (auto find = m_mapComponents.find(identifier); find == m_mapComponents.end())
	{
		COM* component = new COM(args...);

		// TODO: initialize variable 'component'

		component->SetActor(this);
		component->Initialize();

		m_mapComponents.insert(std::make_pair(identifier, component));

		return component;
	}

	return nullptr;
}
