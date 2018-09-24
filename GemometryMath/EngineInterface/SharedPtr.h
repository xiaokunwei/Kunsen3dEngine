#ifndef SHADERPATR_FILE_H
#define SHADERPATR_FILE_H

#include<assert.h>

template<class T> 
class SharedPtr
{
protected:
	T* pRep;

	unsigned int* pUseCount;

public:
	SharedPtr() :pRep(0), pUseCount(0)
	{

	}
	SharedPtr(int tempnullPtr)
		:pRep(0), pUseCount(0)
	{

	}
	template<class Y>
	explicit SharedPtr(Y* rep) :pRep(rep), pUseCount(new unsigned int(1))
	{

	}
	SharedPtr(const SharedPtr& r) :pRep(0), pUseCount(0)
	{
		pRep = r.pRep;
		pUseCount = r.pUseCount;
		if (pUseCount)
		{
			++(*pUseCount);
		}
	}
	SharedPtr& operator=(const SharedPtr& r)
	{
		if (pRep == r.pRep)
		{
			return *this;
		}
		SharedPtr<T> tmp(r);
		Swap(tmp);
		return *this;
	}

	bool operator ==(const SharedPtr& r)
	{
		if (pRep == r.pRep)
		{
			return true;
		}
		return false;
	}

	template<class Y>

	SharedPtr(const SharedPtr<Y>& r) :pRep(0), pUseCount(0)
	{
		{
			pRep = r.GetPointer();
			pUseCount = r.UseCountPointer();
			if (pUseCount)
			{
				++(*pUseCount);
			}
		}
	}

	template<class Y>
	SharedPtr& operator =(const SharedPtr<Y>& r)
	{
		if (pRep == r.pRep)
		{
			return *this;
		}
		SharedPtr<T> tmp(r);
		Swap(tmp);

		return *this;
	}


	virtual ~SharedPtr()
	{
		Release();
	}
	inline T& operator*()const{ assert(pRep); return *pRep; }
	inline T* operator->()const{ assert(pRep); return pRep; }

	inline T* Get()const{ return pRep; }
	void Bind(T* rep)
	{
		assert(!pRep&&!pUseCount);

		pUseCount = new unsigned int(1);

		pRep = rep;
	}
	void AddRef()
	{
		++(*pUseCount);
	}
	inline bool Unique()const { assert(pUseCount); return *pUseCount == 1; }
	inline unsigned int UseCount()const { assert(pUseCount); return *pUseCount; }

	inline unsigned int* UseCountPointer()const { return pUseCount; }
	inline T* GetPointer()const{ return pRep; }
	inline bool IsNull()const{ return pRep == 0; }
	inline void SetNull(){
		if (pRep)
		{
			Release();
			pRep = 0;
			pUseCount = 0;
		}
	}
protected:

	inline void Release()
	{
		bool destoryThis = false;

		{
			if (pUseCount)
			{
				if (--(*pUseCount) == 0)
				{
					destoryThis = true;
				}
			}
		}
		if (destoryThis)
		{
			Destroy();
		}
	}
	virtual void Destroy()
	{
		delete pRep;
		delete pUseCount;
	}
	virtual void Swap(SharedPtr<T> & other)
	{
		std::swap(pRep, other.pRep);
		std::swap(pUseCount, other.pUseCount);
	}
};

template<class T, class U> inline bool operator==(SharedPtr<T> const& a, SharedPtr<U> const& b)
{
	return a.Get() == b.Get();
}

template<class T, class U> inline bool operator!=(SharedPtr<T> const& a, SharedPtr<U> const& b)
{
	return a.Get() != b.Get();
}
#endif