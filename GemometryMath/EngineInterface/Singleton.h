#ifndef SINGLETON_FILE_H_
#define SINGLETON_FILE_H_

#include<assert.h>

template<typename T> class Singleton
{
private:

	Singleton(const Singleton<T>&);

	Singleton& operator=(const Singleton<T>&);

protected:

	static T* m_Singleton;

public:

	Singleton()
	{
		assert(!m_Singleton);

		m_Singleton = static_cast<T*> (this);
	}
	~Singleton()
	{
		assert(m_Singleton);
		m_Singleton = 0;
	}
	static T& GetSingleton()
	{
		assert(m_Singleton);
		return *m_Singleton;
	}
	static T* GetSingleton()
	{
		return m_Singleton;
	}
};
#endif