#pragma once
/*
 * EventListener<T> :
 * �̺�Ʈ �����ʴ�
 * CreateListener(Type, Function) �� ���� ������ �� �̺�Ʈ �ڵ鷯�� ����Ͽ� ����մϴ�.
 * �̺�Ʈ�� �߻��� ������ ����� �Լ��� ����˴ϴ�.
 * T = �Լ� ���� Ÿ��.
*/
template <typename T>
class EventListener
{
	template <typename T>
	friend class EventHandler;
private:
	std::function< void(T) > m_Function;
public:
	EventListener(std::function<void(T)>&& func)
		: m_Function(func)
	{
		
	}
};

/*
 * EventHandler<T> :
 * �̺�Ʈ �ڵ鷯�� �̺�Ʈ �����ʵ��� �����ϴ� ��ü�Դϴ�.
 * �� �̺�Ʈ�� �߻����� �� �� �����ʿ��� ���ڸ� �����ϸ� ȣ���ų �� �ֽ��ϴ�.
 * T = �̺�Ʈ�� �߻����� �� ������ ���� Ÿ��.
*/
template <typename T>
class EventHandler
{
private:

	std::set< EventListener<T>* > m_setListeners;

public:
	~EventHandler()
	{
		for (auto iter : m_setListeners)
			delete iter;

		m_setListeners.clear();
	}

	inline void operator +=(EventListener<T>* listener)
	{
		AddListener(listener);
	}

	inline void operator -=(EventListener<T>* listener)
	{
		Detach(listener);
	}

	void AddListener(EventListener<T>* listener)
	{
		m_setListeners.insert(listener);
	}

	// ����� �ʿ����� ����
	void Detach(EventListener<T>* listener)
	{
		m_setListeners.erase(listener);
	}

	// �ʿ��� ���� & �޸𸮱��� ����
	void Remove(EventListener<T>* listener)
	{
		m_setListeners.erase(listener);
		SAFE_DELETE(listener);
	}

	void operator()(const T& argument)
	{
		for (auto iter : m_setListeners) {
			iter->m_Function(argument);
		}
	}
};

struct EmptyEventArg {};

#define CreateListener(Type, Function) \
new EventListener<Type>([this](Type value){ Function(value); })