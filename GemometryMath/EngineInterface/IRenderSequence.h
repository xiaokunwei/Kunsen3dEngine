#ifndef IRENDERESEQUENCE_FILE_H
#define IRENDERESEQUENCE_FILE_H

struct Renderable;

struct RenderLight;

enum Renderable_FileMode
{
	General,
	ShadowCas0,
	ShadowCas1,
	ShadowCas2,
};

struct IRenderSequence
{
	virtual void AddToRenderSequence(Renderable* drawable,int ID) = 0;

	virtual void AddToRenderSequence(Renderable* drawable);

	virtual void AddRenderLight(RenderLight* light) = 0;

	virtual void MarkFinished() = 0;

	virtual void Clear();

};

#endif