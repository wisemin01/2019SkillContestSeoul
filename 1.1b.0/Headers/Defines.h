#pragma once

// Define functions

#define PropertyG(G) __declspec(property(get = G))
#define PropertyS(S) __declspec(property(put = S))
#define PropertyGS(G, S) __declspec(property(get = G, put = S))

constexpr float Half(float f) { return ((f) / 2.0f); }

// Define variables

#define g_pDevice		DXUTGetD3D9Device()
#define g_fNowTime		DXUTGetTime()
#define g_fDeltaTime	DXUTGetElapsedTime()

struct null_t {};

template <class _component_t>
struct is_unique_component
{
	typedef typename _component_t::component_identifier_t	identifier_t;
	typedef typename identifier_t::parent_component_t		parent_t;

	enum
	{
		value = std::conditional<identifier_t::is_unique, std::true_type, is_unique_component<parent_t>>::type::value
	};
};
template <>
struct is_unique_component<null_t>
{
	enum { value = false };
};

template <class _component_t>
struct get_unique_component
{
	typedef typename _component_t::component_identifier_t	identifier_t;
	typedef typename identifier_t::parent_component_t		parent_t;

	typedef typename std::conditional<identifier_t::is_unique, _component_t, typename get_unique_component<parent_t>::type>::type type;
};
template <>
struct get_unique_component<null_t>
{
	typedef null_t type;
};


template <class _component_t>
struct get_component
{
	typedef typename std::conditional<
		is_unique_component<_component_t>::value,
		typename get_unique_component<_component_t>::type,
		_component_t>::type type;
};

template <class _component_t, class _parent_component_t, bool _is_unique>
struct _component_identifier
{
	typedef _component_t current_component_t;
	typedef _parent_component_t parent_component_t;

	enum { is_unique = _is_unique };
};

#define COMPONENT_HEAD(component_name, parent_component_name, unique_component) \
	public: \
		typedef _component_identifier<component_name, parent_component_name, unique_component> component_identifier_t; \
		static uint GetComponentID(void) { return reinterpret_cast<uint>(&identifier); } \
		virtual const char* GetComponentName(void) { return #component_name; } \
		static const char* GetStaticComponentName(void) { return #component_name; } \
		using Super = parent_component_name;\
	private: \
		inline static component_identifier_t identifier; \

using _tag_type = int;