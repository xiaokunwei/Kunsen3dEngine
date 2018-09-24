
#include"..\Include\Common\Ref.h"
namespace KunSen
{
	Ref::Ref()
	{
		m_Count++;
	}
	Ref::~Ref()
	{
		if (m_Count <= 0)
		{
			delete this;
		}
	}

	void Ref::AddRef()
	{
		m_Count++;
	}
	void Ref::ReleaseRef()
	{
		m_Count--;
		if (m_Count <= 0)
		{
			delete this;
		}
	}
	int  Ref::Refs()const
	{
		return m_Count;
	}



}

