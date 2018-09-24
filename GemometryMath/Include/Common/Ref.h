#ifndef REF_FILE_H
#define REF_FILE_H
#include"Export.h"
namespace KunSen
{
	class EXPORT_API Ref
	{
	public:
		Ref();
		virtual	~Ref();

		void AddRef();
		void ReleaseRef();
		
		int Refs()const;
	private:
		
		Ref& operator=(const Ref& rhs);
		int m_Count;
	};
}
#endif

