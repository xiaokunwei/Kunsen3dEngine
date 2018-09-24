
#ifndef IMESH_FILE_H_
#define IMESH_FILE_H_
#include"Platform.h"
#include"IResource.h"

#include "Math/Matrix.h"

struct RenderOperation;


#define MAX_MESHATTRIBUTE_COUNT 100

class VertexFormat
{
public:

	enum Useage
	{
		POSITION = 1,
		NORMAL = 2,
		TANGENT = 4,
		BINORMAL = 5,
		BLENDWEIGHTS = 6,
		BLENDINDICES = 7,
		TEXCOORD0 = 8,
		TEXCOORD1 = 9,
		TEXCOORD2 = 10,
		TEXCOORD3 = 11,
		TEXCOORD4 = 12,
		TEXCOORD5 = 13,
		TEXCOORD6 = 14,
		TEXCOORD7 = 15,
		INSTANCE_MATRIX = 15
	};
	class Element
	{
	public:
		Useage m_usage;
		int32 m_size;
		Element(){ m_usage = POSITION; }
		Element(Useage useage, int32 size) { m_usage = useage; m_size = size; }

		bool operator==(const Element& e)const { return m_size == e.m_size&& m_usage == e.m_usage; }
		bool operator!=(const Element& e)const { return !(*this == e); }
	};

	VertexFormat(const Element* elements, int32 elementCount)
	{
		uint32 vertexSize = GetVertexSize();

		for (uint32 i = 0; i < elementCount; i++)
		{
			Element element;
			memcpy(&element, &elements[i], sizeof(Element));
			m_Elements.push_back(element);
			m_VertexSize += element.m_size*sizeof(float);
		}
	}

	~VertexFormat();

	VertexFormat(){}

	const Element& GetElement(uint32 index)const { return m_Elements[index]; }

	uint32 GetElementCount()const { return (uint32)m_Elements.size(); }

	uint32 GetVertexSize()const { return m_VertexSize; }

	bool operator==(const VertexFormat& f)const{ return true; }

	bool operator!=(const VertexFormat& f)const { return false; }

private:

	std::vector<Element> m_Elements;
	uint32 m_VertexSize;



};

class VertexBuffer
{
public:

	uint8* data;

	bool m_NeedRebind;


	uint32 m_VertexCount;

	VertexFormat m_Format;

	uint32 m_VertexSize;

	VertexBuffer(const VertexFormat& foramt)
	{
		m_Format = foramt;
	}

	void SetData(void* data, uint32 size)
	{
		m_VertexSize = size;
		memcpy(data, data, size);
	}
};


struct IndexBuffer
{
	uint8* data;
	uint32 m_count;
	uint32 currAddress;
	bool m_needRebind;

	uint32 userData;
	bool wordBit;


	IndexBuffer(uint32 count, bool bit16 = false)
	{
		data = 0;
		m_count = count;

		userData = 0;
		if (bit16)
		{
			data = new uint8[count * 2];
		}
		else
		{
			data = new uint8[count * 4];
		}

		wordBit = bit16;

		m_needRebind = false;
	}
	~IndexBuffer()
	{
		delete[] data;
	}

	bool NeedRebind(){ return m_needRebind; }

	void SetBind(){
		m_needRebind = false;
	}


	void MarkWrite()
	{
		if (!data)
		{
			if (wordBit)
			{
				data = new uint8[m_count * 2];
			}
			else
			{
				data = new uint8[m_count * 4];
			}
		}
	}

	void UnMarkWrite()
	{
		if (data)
		{
			delete[] data;
			data = 0;
		}
	}

	uint32 GetSize()
	{
		return m_count * (wordBit ? sizeof(uint16) : sizeof(uint32));
	}

	void ResizeDiscard(uint32 size)
	{
		m_count = size;

		currAddress = 0;

		if (data)
		{
			delete[] data;
		}
		if (wordBit)
		{
			data = new uint8[m_count * 2];
		}
		else
		{
			data = new uint8[m_count * 4];
		}
		m_needRebind = true;
	}
	void Clear()
	{
		memset(data, 0, GetSize());
		currAddress = 0;
	}

	uint32 GetData(uint32 count)
	{
		if (wordBit)
		{
			uint16* data16 = (uint16*)data;
			return data16[count];
		}
		else
		{
			uint32* data32 = (uint32*)data;

			return data32[count];
		}
	}

	void Push_back(uint32 index)
	{

	}

private:

	IndexBuffer(const IndexBuffer& other);
	IndexBuffer& operator =(const IndexBuffer& other);
};


struct SubMesh
{
	VertexBuffer* vb;
	IndexBuffer* ib;

	uint32 indexStart;
	uint32 indexCount;
	std::string mtlName;

	SubMesh()
	{
		vb = 0;
		ib = 0;
		indexStart = 0;
		indexCount = 0;
	}
};


struct IMeshLoader
{
	struct CacheEntry{
		uint32 index;
		CacheEntry* pNext;
	};
	struct ObjFace
	{
		uint32 posIdx[3];		// 位置索引
		uint32 nrmIdx[3];		// 法线索引
		uint32 texIdx[3];		// 纹理坐标索引
		uint32 tex1Idx[3];		// 纹理坐标索引
		uint32 tgtIdx[3];		// 切线索引
		uint32 bnmIdx[3];		// 副法线索引

	};

	struct SubSet
	{
		std::string mtlNames;
		uint32 startIndex;
		uint32 endIndex;
	};

	virtual bool LoadGeometry(const char* fileName) = 0;

	virtual VertexBuffer* GetVertexBuffer() = 0;

	virtual IndexBuffer* GetIndexBuffer() = 0;

	virtual uint32 GetSubMeshCount() = 0;

	virtual void GetSubSet(uint32 index, uint32& start, uint32& end, std::string name);

	virtual void FinishLoading() = 0;

	virtual uint16 GetBoneTransformCount() = 0;

	virtual void  GetBoneTransformMatrix(KunSen::Matrix& matrix, uint16 index) = 0;


};

class IMesh :public IResource
{
public:

	typedef std::vector<KunSen::Matrix> BoneBaseTransforms;

	IMesh(IResourceManager* creator, const std::string& name){}

	virtual ~IMesh(){}

	virtual void OnReset() = 0;

	virtual void OnLost() = 0;

	virtual BoneBaseTransforms& GetBoneBaseTransform() = 0;

	virtual void GetRenderOperation() = 0;

	virtual uint32 GetSubMeshCount() = 0;

	virtual VertexBuffer* GetVertBuffer() = 0;

	virtual IndexBuffer* GetIndexBuffer() = 0;

	virtual void UpdateBuffer() = 0;

	virtual void ReleaseBuffer() = 0;


};
#endif 