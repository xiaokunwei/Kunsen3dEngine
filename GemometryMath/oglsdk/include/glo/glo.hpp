///////////////////////////////////////////////////////////////////////////////////
/// OpenGL Overload (www.g-truc.net)
///
/// Copyright (c) 2013 - 2013 G-Truc Creation (www.g-truc.net)
/// Permission is hereby granted, free of charge, to any person obtaining a copy
/// of this software and associated documentation files (the "Software"), to deal
/// in the Software without restriction, including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
/// copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions:
/// 
/// The above copyright notice and this permission notice shall be included in
/// all copies or substantial portions of the Software.
/// 
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
/// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
/// THE SOFTWARE.
///
/// @ref core
/// @file glo/glo.hpp
/// @date 2013-02-10 / 2013-02-10
/// @author Christophe Riccio
///////////////////////////////////////////////////////////////////////////////////
#pragma once

#ifdef WIN32
#	define WIN32_LEAN_AND_MEAN
#	include <windows.h>
#	include <GL/gl.h>
#	include "core/glcorearb.h"
#elif defined(linux) || defined(__linux)
#	define GL_GLEXT_PROTOTYPES 1
#	define GLCOREARB_PROTOTYPES 1
#	include <GL/gl.h>
#	include <GL/glext.h>
#elif defined(__APPLE__)
#	include <OpenGL/gl3.h>
#define GL_COMPRESSED_RGB_S3TC_DXT1_EXT 0x83F0
#define GL_COMPRESSED_RGBA_S3TC_DXT1_EXT 0x83F1
#define GL_COMPRESSED_RGBA_S3TC_DXT3_EXT 0x83F2
#define GL_COMPRESSED_RGBA_S3TC_DXT5_EXT 0x83F3
#else
#	error "Unsupported platform"
#endif

#ifdef WIN32
#	define gloGetProcAddress wglGetProcAddress

	// OpenGL 1.0
	// PFNGLENABLEPROC glEnable;
	// PFNGLVIEWPORTPROC glViewport;

	// OpenGL 1.1
	// PFNGLGETINTEGERVPROC glGetIntegerv;
	// PFNGLGETERRORPROC glGetError;

	// OpenGL 1.2 
extern PFNGLBLENDCOLORPROC glBlendColor;
extern PFNGLBLENDEQUATIONPROC glBlendEquation;
extern PFNGLDRAWRANGEELEMENTSPROC glDrawRangeElements;
extern PFNGLTEXIMAGE3DPROC glTexImage3D;
extern PFNGLTEXSUBIMAGE3DPROC glTexSubImage3D;
extern PFNGLCOPYTEXSUBIMAGE3DPROC glCopyTexSubImage3D;

	// OpenGL 1.3
extern PFNGLACTIVETEXTUREPROC glActiveTexture;
extern PFNGLSAMPLECOVERAGEPROC glSampleCoverage;
extern PFNGLCOMPRESSEDTEXIMAGE3DPROC glCompressedTexImage3D;
extern PFNGLCOMPRESSEDTEXIMAGE2DPROC glCompressedTexImage2D;
extern PFNGLCOMPRESSEDTEXIMAGE1DPROC glCompressedTexImage1D;
extern PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glCompressedTexSubImage3D;
extern PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glCompressedTexSubImage2D;
extern PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC glCompressedTexSubImage1D;
extern PFNGLGETCOMPRESSEDTEXIMAGEPROC glGetCompressedTexImage;

	// OpenGL 1.4
	#define GL_COMPARE_R_TO_TEXTURE 0x884E
	
extern PFNGLBLENDFUNCSEPARATEPROC glBlendFuncSeparate;
extern PFNGLPOINTPARAMETERFPROC glPointParameterf;
extern PFNGLPOINTPARAMETERFVPROC glPointParameterfv;
extern PFNGLPOINTPARAMETERIPROC glPointParameteri;
extern PFNGLPOINTPARAMETERIVPROC glPointParameteriv;

	// OpenGL 1.5
extern PFNGLGENQUERIESPROC glGenQueries;
extern PFNGLDELETEQUERIESPROC glDeleteQueries;
extern PFNGLISQUERYPROC glIsQuery;
extern PFNGLBEGINQUERYPROC glBeginQuery;
extern PFNGLENDQUERYPROC glEndQuery;
extern PFNGLGETQUERYIVPROC glGetQueryiv;
extern PFNGLGETQUERYOBJECTIVPROC glGetQueryObjectiv;
extern PFNGLGETQUERYOBJECTUIVPROC glGetQueryObjectuiv;
extern PFNGLBINDBUFFERPROC glBindBuffer;
extern PFNGLDELETEBUFFERSPROC glDeleteBuffers;
extern PFNGLGENBUFFERSPROC glGenBuffers;
extern PFNGLISBUFFERPROC glIsBuffer;
extern PFNGLBUFFERDATAPROC glBufferData;
extern PFNGLBUFFERSUBDATAPROC glBufferSubData;
extern PFNGLGETBUFFERSUBDATAPROC glGetBufferSubData;
extern PFNGLUNMAPBUFFERPROC glUnmapBuffer;
extern PFNGLGETBUFFERPARAMETERIVPROC glGetBufferParameteriv;
extern PFNGLGETBUFFERPOINTERVPROC glGetBufferPointerv;

	// OpenGL 2.0
extern PFNGLBLENDEQUATIONSEPARATEPROC glBlendEquationSeparate;
extern PFNGLDRAWBUFFERSPROC glDrawBuffers;
extern PFNGLSTENCILOPSEPARATEPROC glStencilOpSeparate;
extern PFNGLSTENCILFUNCSEPARATEPROC glStencilFuncSeparate;
extern PFNGLSTENCILMASKSEPARATEPROC glStencilMaskSeparate;

	// Program and shader
extern PFNGLCREATESHADERPROC glCreateShader;
extern PFNGLDELETESHADERPROC glDeleteShader;
extern PFNGLCREATEPROGRAMPROC glCreateProgram;
extern PFNGLDELETEPROGRAMPROC glDeleteProgram;
extern PFNGLSHADERSOURCEPROC glShaderSource;
extern PFNGLCOMPILESHADERPROC glCompileShader;
extern PFNGLGETSHADERIVPROC glGetShaderiv;
extern PFNGLVALIDATEPROGRAMPROC glValidateProgram;
extern PFNGLGETPROGRAMIVPROC glGetProgramiv;
extern PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog;
extern PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog;
extern PFNGLATTACHSHADERPROC glAttachShader;
extern PFNGLLINKPROGRAMPROC glLinkProgram;
extern PFNGLUSEPROGRAMPROC glUseProgram;
extern PFNGLGETVERTEXATTRIBDVPROC glGetVertexAttribdv;
extern PFNGLGETVERTEXATTRIBFVPROC glGetVertexAttribfv;
extern PFNGLGETVERTEXATTRIBIVPROC glGetVertexAttribiv;
extern PFNGLGETVERTEXATTRIBPOINTERVPROC glGetVertexAttribPointerv;
extern PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer;
extern PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;
extern PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray;
extern PFNGLBINDATTRIBLOCATIONPROC glBindAttribLocation;
extern PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation;
extern PFNGLGETATTRIBLOCATIONPROC glGetAttribLocation;
extern PFNGLUNIFORM1FPROC glUniform1f;
extern PFNGLUNIFORM2FPROC glUniform2f;
extern PFNGLUNIFORM3FPROC glUniform3f;
extern PFNGLUNIFORM4FPROC glUniform4f;
extern PFNGLUNIFORM1IPROC glUniform1i;
extern PFNGLUNIFORM2IPROC glUniform2i;
extern PFNGLUNIFORM3IPROC glUniform3i;
extern PFNGLUNIFORM4IPROC glUniform4i;
extern PFNGLUNIFORM1FVPROC glUniform1fv;
extern PFNGLUNIFORM2FVPROC glUniform2fv;
extern PFNGLUNIFORM3FVPROC glUniform3fv;
extern PFNGLUNIFORM4FVPROC glUniform4fv;
extern PFNGLUNIFORM1IVPROC glUniform1iv;
extern PFNGLUNIFORM2IVPROC glUniform2iv;
extern PFNGLUNIFORM3IVPROC glUniform3iv;
extern PFNGLUNIFORM4IVPROC glUniform4iv;
extern PFNGLUNIFORMMATRIX2FVPROC glUniformMatrix2fv;
extern PFNGLUNIFORMMATRIX3FVPROC glUniformMatrix3fv;
extern PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv;
extern PFNGLGETACTIVEATTRIBPROC glGetActiveAttrib;
extern PFNGLGETACTIVEUNIFORMPROC glGetActiveUniform;

extern PFNGLVERTEXATTRIB1DPROC glVertexAttrib1d;
extern PFNGLVERTEXATTRIB1DVPROC glVertexAttrib1dv;
extern PFNGLVERTEXATTRIB1FPROC glVertexAttrib1f;
extern PFNGLVERTEXATTRIB1FVPROC glVertexAttrib1fv;
extern PFNGLVERTEXATTRIB1SPROC glVertexAttrib1s;
extern PFNGLVERTEXATTRIB1SVPROC glVertexAttrib1sv;
extern PFNGLVERTEXATTRIB2DPROC glVertexAttrib2d;
extern PFNGLVERTEXATTRIB2DVPROC glVertexAttrib2dv;
extern PFNGLVERTEXATTRIB2FPROC glVertexAttrib2f;
extern PFNGLVERTEXATTRIB2FVPROC glVertexAttrib2fv;
extern PFNGLVERTEXATTRIB2SPROC glVertexAttrib2s;
extern PFNGLVERTEXATTRIB2SVPROC glVertexAttrib2sv;
extern PFNGLVERTEXATTRIB3DPROC glVertexAttrib3d;
extern PFNGLVERTEXATTRIB3DVPROC glVertexAttrib3dv;
extern PFNGLVERTEXATTRIB3FPROC glVertexAttrib3f;
extern PFNGLVERTEXATTRIB3FVPROC glVertexAttrib3fv;
extern PFNGLVERTEXATTRIB3SPROC glVertexAttrib3s;
extern PFNGLVERTEXATTRIB3SVPROC glVertexAttrib3sv;
extern PFNGLVERTEXATTRIB4DPROC glVertexAttrib4d;
extern PFNGLVERTEXATTRIB4DVPROC glVertexAttrib4dv;
extern PFNGLVERTEXATTRIB4FPROC glVertexAttrib4f;
extern PFNGLVERTEXATTRIB4FVPROC glVertexAttrib4fv;
extern PFNGLVERTEXATTRIB4SPROC glVertexAttrib4s;
extern PFNGLVERTEXATTRIB4SVPROC glVertexAttrib4sv;
extern PFNGLVERTEXATTRIB4NBVPROC glVertexAttrib4Nbv;
extern PFNGLVERTEXATTRIB4NIVPROC glVertexAttrib4Niv;
extern PFNGLVERTEXATTRIB4NSVPROC glVertexAttrib4Nsv;
extern PFNGLVERTEXATTRIB4NUBPROC glVertexAttrib4Nub;
extern PFNGLVERTEXATTRIB4NUBVPROC glVertexAttrib4Nubv;
extern PFNGLVERTEXATTRIB4NUIVPROC glVertexAttrib4Nuiv;
extern PFNGLVERTEXATTRIB4NUSVPROC glVertexAttrib4Nusv;
extern PFNGLVERTEXATTRIB4BVPROC glVertexAttrib4bv;
extern PFNGLVERTEXATTRIB4IVPROC glVertexAttrib4iv;
extern PFNGLVERTEXATTRIB4UBVPROC glVertexAttrib4ubv;
extern PFNGLVERTEXATTRIB4UIVPROC glVertexAttrib4uiv;
extern PFNGLVERTEXATTRIB4USVPROC glVertexAttrib4usv;

	// OpenGL 3.0
extern PFNGLCOLORMASKIPROC glColorMaski;
extern PFNGLGETBOOLEANI_VPROC glGetBooleani_v;
extern PFNGLGETINTEGERI_VPROC glGetIntegeri_v;
extern PFNGLENABLEIPROC glEnablei;
extern PFNGLDISABLEIPROC glDisablei;
extern PFNGLISENABLEDIPROC glIsEnabledi;
extern PFNGLBEGINTRANSFORMFEEDBACKPROC glBeginTransformFeedback;
extern PFNGLENDTRANSFORMFEEDBACKPROC glEndTransformFeedback;
extern PFNGLBINDBUFFERRANGEPROC glBindBufferRange;
extern PFNGLBINDBUFFERBASEPROC glBindBufferBase;
extern PFNGLTRANSFORMFEEDBACKVARYINGSPROC glTransformFeedbackVaryings;
extern PFNGLGETTRANSFORMFEEDBACKVARYINGPROC glGetTransformFeedbackVarying;
extern PFNGLCLAMPCOLORPROC glClampColor;
extern PFNGLBEGINCONDITIONALRENDERPROC glBeginConditionalRender;
extern PFNGLENDCONDITIONALRENDERPROC glEndConditionalRender;
extern PFNGLVERTEXATTRIBIPOINTERPROC glVertexAttribIPointer;
extern PFNGLGETVERTEXATTRIBIIVPROC glGetVertexAttribIiv;
extern PFNGLGETVERTEXATTRIBIUIVPROC glGetVertexAttribIuiv;
extern PFNGLVERTEXATTRIBI1IPROC glVertexAttribI1i;
extern PFNGLVERTEXATTRIBI2IPROC glVertexAttribI2i;
extern PFNGLVERTEXATTRIBI3IPROC glVertexAttribI3i;
extern PFNGLVERTEXATTRIBI4IPROC glVertexAttribI4i;
extern PFNGLVERTEXATTRIBI1UIPROC glVertexAttribI1ui;
extern PFNGLVERTEXATTRIBI2UIPROC glVertexAttribI2ui;
extern PFNGLVERTEXATTRIBI3UIPROC glVertexAttribI3ui;
extern PFNGLVERTEXATTRIBI4UIPROC glVertexAttribI4ui;
extern PFNGLVERTEXATTRIBI1IVPROC glVertexAttribI1iv;
extern PFNGLVERTEXATTRIBI2IVPROC glVertexAttribI2iv;
extern PFNGLVERTEXATTRIBI3IVPROC glVertexAttribI3iv;
extern PFNGLVERTEXATTRIBI4IVPROC glVertexAttribI4iv;
extern PFNGLVERTEXATTRIBI1UIVPROC glVertexAttribI1uiv;
extern PFNGLVERTEXATTRIBI2UIVPROC glVertexAttribI2uiv;
extern PFNGLVERTEXATTRIBI3UIVPROC glVertexAttribI3uiv;
extern PFNGLVERTEXATTRIBI4UIVPROC glVertexAttribI4uiv;
extern PFNGLVERTEXATTRIBI4BVPROC glVertexAttribI4bv;
extern PFNGLVERTEXATTRIBI4SVPROC glVertexAttribI4sv;
extern PFNGLVERTEXATTRIBI4UBVPROC glVertexAttribI4ubv;
extern PFNGLVERTEXATTRIBI4USVPROC glVertexAttribI4usv;
extern PFNGLGETUNIFORMUIVPROC glGetUniformuiv;
extern PFNGLBINDFRAGDATALOCATIONPROC glBindFragDataLocation;
extern PFNGLGETFRAGDATALOCATIONPROC glGetFragDataLocation;
extern PFNGLUNIFORM1UIPROC glUniform1ui;
extern PFNGLUNIFORM2UIPROC glUniform2ui;
extern PFNGLUNIFORM3UIPROC glUniform3ui;
extern PFNGLUNIFORM4UIPROC glUniform4ui;
extern PFNGLUNIFORM1UIVPROC glUniform1uiv;
extern PFNGLUNIFORM2UIVPROC glUniform2uiv;
extern PFNGLUNIFORM3UIVPROC glUniform3uiv;
extern PFNGLUNIFORM4UIVPROC glUniform4uiv;
extern PFNGLTEXPARAMETERIIVPROC glTexParameterIiv;
extern PFNGLTEXPARAMETERIUIVPROC glTexParameterIuiv;
extern PFNGLGETTEXPARAMETERIIVPROC glGetTexParameterIiv;
extern PFNGLGETTEXPARAMETERIUIVPROC glGetTexParameterIuiv;
extern PFNGLCLEARBUFFERIVPROC glClearBufferiv;
extern PFNGLCLEARBUFFERUIVPROC glClearBufferuiv;
extern PFNGLCLEARBUFFERFVPROC glClearBufferfv;
extern PFNGLCLEARBUFFERFIPROC glClearBufferfi;
extern PFNGLGETSTRINGIPROC glGetStringi;

	// GL_ARB_framebuffer_object
extern PFNGLISRENDERBUFFERPROC glIsRenderbuffer;
extern PFNGLBINDRENDERBUFFERPROC glBindRenderbuffer;
extern PFNGLDELETERENDERBUFFERSPROC glDeleteRenderbuffers;
extern PFNGLGENRENDERBUFFERSPROC glGenRenderbuffers;
extern PFNGLRENDERBUFFERSTORAGEPROC glRenderbufferStorage;
extern PFNGLGETRENDERBUFFERPARAMETERIVPROC glGetRenderbufferParameteriv;
extern PFNGLISFRAMEBUFFERPROC glIsFramebuffer;
extern PFNGLBINDFRAMEBUFFERPROC glBindFramebuffer;
extern PFNGLDELETEFRAMEBUFFERSPROC glDeleteFramebuffers;
extern PFNGLGENFRAMEBUFFERSPROC glGenFramebuffers;
extern PFNGLCHECKFRAMEBUFFERSTATUSPROC glCheckFramebufferStatus;
extern PFNGLFRAMEBUFFERTEXTURE1DPROC glFramebufferTexture1D;
extern PFNGLFRAMEBUFFERTEXTURE2DPROC glFramebufferTexture2D;
extern PFNGLFRAMEBUFFERTEXTURE3DPROC glFramebufferTexture3D;
extern PFNGLFRAMEBUFFERRENDERBUFFERPROC glFramebufferRenderbuffer;
extern PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC glGetFramebufferAttachmentParameteriv;
extern PFNGLGENERATEMIPMAPPROC glGenerateMipmap;
extern PFNGLBLITFRAMEBUFFERPROC glBlitFramebuffer;
extern PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC glRenderbufferStorageMultisample;
extern PFNGLFRAMEBUFFERTEXTURELAYERPROC glFramebufferTextureLayer;

	// GL_ARB_vertex_array_object
extern PFNGLBINDVERTEXARRAYPROC glBindVertexArray;
extern PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays;
extern PFNGLGENVERTEXARRAYSPROC glGenVertexArrays;
extern PFNGLISVERTEXARRAYPROC glIsVertexArray;

	// GL_ARB_provoking_vertex
extern PFNGLPROVOKINGVERTEXPROC glProvokingVertex;

	// OpenGL 3.1
extern PFNGLDRAWARRAYSINSTANCEDPROC glDrawArraysInstanced;
extern PFNGLDRAWELEMENTSINSTANCEDPROC glDrawElementsInstanced;
extern PFNGLTEXBUFFERPROC glTexBuffer;
extern PFNGLPRIMITIVERESTARTINDEXPROC glPrimitiveRestartIndex;

	// GL_ARB_copy_buffer
extern PFNGLCOPYBUFFERSUBDATAPROC glCopyBufferSubData;

	// OpenGL 3.2
extern PFNGLGETINTEGER64I_VPROC glGetInteger64i_v;
extern PFNGLGETBUFFERPARAMETERI64VPROC glGetBufferParameteri64v;
extern PFNGLFRAMEBUFFERTEXTUREPROC glFramebufferTexture;

	// GL_ARB_map_buffer_range
extern PFNGLMAPBUFFERRANGEPROC glMapBufferRange;
extern PFNGLFLUSHMAPPEDBUFFERRANGEPROC glFlushMappedBufferRange;

	// GL_ARB_draw_elements_base_vertex
extern PFNGLDRAWELEMENTSBASEVERTEXPROC glDrawElementsBaseVertex;
extern PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC glDrawRangeElementsBaseVertex;
extern PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC glDrawElementsInstancedBaseVertex;
extern PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC glMultiDrawElementsBaseVertex;

	// GL_ARB_uniform_buffer_object
extern PFNGLGETUNIFORMINDICESPROC glGetUniformIndices;
extern PFNGLGETACTIVEUNIFORMSIVPROC glGetActiveUniformsiv;
extern PFNGLGETACTIVEUNIFORMNAMEPROC glGetActiveUniformName;
extern PFNGLGETUNIFORMBLOCKINDEXPROC glGetUniformBlockIndex;
extern PFNGLGETACTIVEUNIFORMBLOCKIVPROC glGetActiveUniformBlockiv;
extern PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC glGetActiveUniformBlockName;
extern PFNGLUNIFORMBLOCKBINDINGPROC glUniformBlockBinding;

	// GL_ARB_texture_multisample
extern PFNGLTEXIMAGE2DMULTISAMPLEPROC glTexImage2DMultisample;
extern PFNGLTEXIMAGE3DMULTISAMPLEPROC glTexImage3DMultisample;
extern PFNGLGETMULTISAMPLEFVPROC glGetMultisamplefv;
extern PFNGLSAMPLEMASKIPROC glSampleMaski;

	// GL_ARB_sync
extern PFNGLFENCESYNCPROC glFenceSync;
extern PFNGLISSYNCPROC glIsSync;
extern PFNGLDELETESYNCPROC glDeleteSync;
extern PFNGLCLIENTWAITSYNCPROC glClientWaitSync;
extern PFNGLWAITSYNCPROC glWaitSync;
extern PFNGLGETINTEGER64VPROC glGetInteger64v;
extern PFNGLGETSYNCIVPROC glGetSynciv;

	// OpenGL 3.3
extern PFNGLVERTEXATTRIBDIVISORPROC glVertexAttribDivisor;

	// GL_ARB_sampler_objects
extern PFNGLGENSAMPLERSPROC glGenSamplers;
extern PFNGLDELETESAMPLERSPROC glDeleteSamplers;
extern PFNGLISSAMPLERPROC glIsSampler;
extern PFNGLBINDSAMPLERPROC glBindSampler;
extern PFNGLSAMPLERPARAMETERIPROC glSamplerParameteri;
extern PFNGLSAMPLERPARAMETERIVPROC glSamplerParameteriv;
extern PFNGLSAMPLERPARAMETERFPROC glSamplerParameterf;
extern PFNGLSAMPLERPARAMETERFVPROC glSamplerParameterfv;
extern PFNGLSAMPLERPARAMETERIIVPROC glSamplerParameterIiv;
extern PFNGLSAMPLERPARAMETERIUIVPROC glSamplerParameterIuiv;
extern PFNGLGETSAMPLERPARAMETERIVPROC glGetSamplerParameteriv;
extern PFNGLGETSAMPLERPARAMETERIIVPROC glGetSamplerParameterIiv;
extern PFNGLGETSAMPLERPARAMETERFVPROC glGetSamplerParameterfv;
extern PFNGLGETSAMPLERPARAMETERIUIVPROC glGetSamplerParameterIuiv;

	// OpenGL 4.0
extern PFNGLMINSAMPLESHADINGPROC glMinSampleShading;
extern PFNGLBLENDEQUATIONIPROC glBlendEquationi;
extern PFNGLBLENDEQUATIONSEPARATEIPROC glBlendEquationSeparatei;
extern PFNGLBLENDFUNCIPROC glBlendFunci;
extern PFNGLBLENDFUNCSEPARATEIPROC glBlendFuncSeparatei;

	// GL_ARB_draw_indirect
extern PFNGLDRAWARRAYSINDIRECTPROC glDrawArraysIndirect;
extern PFNGLDRAWELEMENTSINDIRECTPROC glDrawElementsIndirect;

	// GL_ARB_gpu_shader_fp64
extern PFNGLUNIFORM1DPROC glUniform1d;
extern PFNGLUNIFORM2DPROC glUniform2d;
extern PFNGLUNIFORM3DPROC glUniform3d;
extern PFNGLUNIFORM4DPROC glUniform4d;
extern PFNGLUNIFORM1DVPROC glUniform1dv;
extern PFNGLUNIFORM2DVPROC glUniform2dv;
extern PFNGLUNIFORM3DVPROC glUniform3dv;
extern PFNGLUNIFORM4DVPROC glUniform4dv;
extern PFNGLUNIFORMMATRIX2DVPROC glUniformMatrix2dv;
extern PFNGLUNIFORMMATRIX3DVPROC glUniformMatrix3dv;
extern PFNGLUNIFORMMATRIX4DVPROC glUniformMatrix4dv;
extern PFNGLUNIFORMMATRIX2X3DVPROC glUniformMatrix2x3dv;
extern PFNGLUNIFORMMATRIX2X4DVPROC glUniformMatrix2x4dv;
extern PFNGLUNIFORMMATRIX3X2DVPROC glUniformMatrix3x2dv;
extern PFNGLUNIFORMMATRIX3X4DVPROC glUniformMatrix3x4dv;
extern PFNGLUNIFORMMATRIX4X2DVPROC glUniformMatrix4x2dv;
extern PFNGLUNIFORMMATRIX4X3DVPROC glUniformMatrix4x3dv;
extern PFNGLGETUNIFORMDVPROC glGetUniformdv;

	// GL_ARB_shader_subroutine
extern PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC glGetSubroutineUniformLocation;
extern PFNGLGETSUBROUTINEINDEXPROC glGetSubroutineIndex;
extern PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC glGetActiveSubroutineUniformiv;
extern PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC glGetActiveSubroutineUniformName;
extern PFNGLGETACTIVESUBROUTINENAMEPROC glGetActiveSubroutineName;
extern PFNGLUNIFORMSUBROUTINESUIVPROC glUniformSubroutinesuiv;
extern PFNGLGETUNIFORMSUBROUTINEUIVPROC glGetUniformSubroutineuiv;
extern PFNGLGETPROGRAMSTAGEIVPROC glGetProgramStageiv;

	// GL_ARB_tessellation_shader
extern PFNGLPATCHPARAMETERIPROC glPatchParameteri;
extern PFNGLPATCHPARAMETERFVPROC glPatchParameterfv;

	// GL_ARB_transform_feedback2
extern PFNGLBINDTRANSFORMFEEDBACKPROC glBindTransformFeedback;
extern PFNGLDELETETRANSFORMFEEDBACKSPROC glDeleteTransformFeedbacks;
extern PFNGLGENTRANSFORMFEEDBACKSPROC glGenTransformFeedbacks;
extern PFNGLISTRANSFORMFEEDBACKPROC glIsTransformFeedback;
extern PFNGLPAUSETRANSFORMFEEDBACKPROC glPauseTransformFeedback;
extern PFNGLRESUMETRANSFORMFEEDBACKPROC glResumeTransformFeedback;
extern PFNGLDRAWTRANSFORMFEEDBACKPROC glDrawTransformFeedback;

	// GL_ARB_transform_feedback3
extern PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC glDrawTransformFeedbackStream;
extern PFNGLBEGINQUERYINDEXEDPROC glBeginQueryIndexed;
extern PFNGLENDQUERYINDEXEDPROC glEndQueryIndexed;
extern PFNGLGETQUERYINDEXEDIVPROC glGetQueryIndexediv;

	// GL_ARB_get_program_binary
extern PFNGLGETPROGRAMBINARYPROC glGetProgramBinary;
extern PFNGLPROGRAMBINARYPROC glProgramBinary;
extern PFNGLPROGRAMPARAMETERIPROC glProgramParameteri;

	// GL_ARB_separate_shader_objects
extern PFNGLUSEPROGRAMSTAGESPROC glUseProgramStages;
extern PFNGLACTIVESHADERPROGRAMPROC glActiveShaderProgram;
extern PFNGLCREATESHADERPROGRAMVPROC glCreateShaderProgramv;
extern PFNGLBINDPROGRAMPIPELINEPROC glBindProgramPipeline;
extern PFNGLDELETEPROGRAMPIPELINESPROC glDeleteProgramPipelines;
extern PFNGLGENPROGRAMPIPELINESPROC glGenProgramPipelines;
extern PFNGLISPROGRAMPIPELINEPROC glIsProgramPipeline;
extern PFNGLGETPROGRAMPIPELINEIVPROC glGetProgramPipelineiv;
extern PFNGLPROGRAMUNIFORM1IPROC glProgramUniform1i;
extern PFNGLPROGRAMUNIFORM1IVPROC glProgramUniform1iv;
extern PFNGLPROGRAMUNIFORM1FPROC glProgramUniform1f;
extern PFNGLPROGRAMUNIFORM1FVPROC glProgramUniform1fv;
extern PFNGLPROGRAMUNIFORM1DPROC glProgramUniform1d;
extern PFNGLPROGRAMUNIFORM1DVPROC glProgramUniform1dv;
extern PFNGLPROGRAMUNIFORM1UIPROC glProgramUniform1ui;
extern PFNGLPROGRAMUNIFORM1UIVPROC glProgramUniform1uiv;
extern PFNGLPROGRAMUNIFORM2IPROC glProgramUniform2i;
extern PFNGLPROGRAMUNIFORM2IVPROC glProgramUniform2iv;
extern PFNGLPROGRAMUNIFORM2FPROC glProgramUniform2f;
extern PFNGLPROGRAMUNIFORM2FVPROC glProgramUniform2fv;
extern PFNGLPROGRAMUNIFORM2DPROC glProgramUniform2d;
extern PFNGLPROGRAMUNIFORM2DVPROC glProgramUniform2dv;
extern PFNGLPROGRAMUNIFORM2UIPROC glProgramUniform2ui;
extern PFNGLPROGRAMUNIFORM2UIVPROC glProgramUniform2uiv;
extern PFNGLPROGRAMUNIFORM3IPROC glProgramUniform3i;
extern PFNGLPROGRAMUNIFORM3IVPROC glProgramUniform3iv;
extern PFNGLPROGRAMUNIFORM3FPROC glProgramUniform3f;
extern PFNGLPROGRAMUNIFORM3FVPROC glProgramUniform3fv;
extern PFNGLPROGRAMUNIFORM3DPROC glProgramUniform3d;
extern PFNGLPROGRAMUNIFORM3DVPROC glProgramUniform3dv;
extern PFNGLPROGRAMUNIFORM3UIPROC glProgramUniform3ui;
extern PFNGLPROGRAMUNIFORM3UIVPROC glProgramUniform3uiv;
extern PFNGLPROGRAMUNIFORM4IPROC glProgramUniform4i;
extern PFNGLPROGRAMUNIFORM4IVPROC glProgramUniform4iv;
extern PFNGLPROGRAMUNIFORM4FPROC glProgramUniform4f;
extern PFNGLPROGRAMUNIFORM4FVPROC glProgramUniform4fv;
extern PFNGLPROGRAMUNIFORM4DPROC glProgramUniform4d;
extern PFNGLPROGRAMUNIFORM4DVPROC glProgramUniform4dv;
extern PFNGLPROGRAMUNIFORM4UIPROC glProgramUniform4ui;
extern PFNGLPROGRAMUNIFORM4UIVPROC glProgramUniform4uiv;
extern PFNGLPROGRAMUNIFORMMATRIX2FVPROC glProgramUniformMatrix2fv;
extern PFNGLPROGRAMUNIFORMMATRIX3FVPROC glProgramUniformMatrix3fv;
extern PFNGLPROGRAMUNIFORMMATRIX4FVPROC glProgramUniformMatrix4fv;
extern PFNGLPROGRAMUNIFORMMATRIX2DVPROC glProgramUniformMatrix2dv;
extern PFNGLPROGRAMUNIFORMMATRIX3DVPROC glProgramUniformMatrix3dv;
extern PFNGLPROGRAMUNIFORMMATRIX4DVPROC glProgramUniformMatrix4dv;
extern PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC glProgramUniformMatrix2x3fv;
extern PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC glProgramUniformMatrix3x2fv;
extern PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC glProgramUniformMatrix2x4fv;
extern PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC glProgramUniformMatrix4x2fv;
extern PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC glProgramUniformMatrix3x4fv;
extern PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC glProgramUniformMatrix4x3fv;
extern PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC glProgramUniformMatrix2x3dv;
extern PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC glProgramUniformMatrix3x2dv;
extern PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC glProgramUniformMatrix2x4dv;
extern PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC glProgramUniformMatrix4x2dv;
extern PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC glProgramUniformMatrix3x4dv;
extern PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC glProgramUniformMatrix4x3dv;
extern PFNGLVALIDATEPROGRAMPIPELINEPROC glValidateProgramPipeline;
extern PFNGLGETPROGRAMPIPELINEINFOLOGPROC glGetProgramPipelineInfoLog;

	// GL_ARB_vertex_attrib_64bit
extern PFNGLVERTEXATTRIBL1DPROC glVertexAttribL1d;
extern PFNGLVERTEXATTRIBL2DPROC glVertexAttribL2d;
extern PFNGLVERTEXATTRIBL3DPROC glVertexAttribL3d;
extern PFNGLVERTEXATTRIBL4DPROC glVertexAttribL4d;
extern PFNGLVERTEXATTRIBL1DVPROC glVertexAttribL1dv;
extern PFNGLVERTEXATTRIBL2DVPROC glVertexAttribL2dv;
extern PFNGLVERTEXATTRIBL3DVPROC glVertexAttribL3dv;
extern PFNGLVERTEXATTRIBL4DVPROC glVertexAttribL4dv;
extern PFNGLVERTEXATTRIBLPOINTERPROC glVertexAttribLPointer;
extern PFNGLGETVERTEXATTRIBLDVPROC glGetVertexAttribLdv;

	// GL_ARB_viewport_array
extern PFNGLVIEWPORTARRAYVPROC glViewportArrayv;
extern PFNGLVIEWPORTINDEXEDFPROC glViewportIndexedf;
extern PFNGLVIEWPORTINDEXEDFVPROC glViewportIndexedfv;
extern PFNGLSCISSORARRAYVPROC glScissorArrayv;
extern PFNGLSCISSORINDEXEDPROC glScissorIndexed;
extern PFNGLSCISSORINDEXEDVPROC glScissorIndexedv;
extern PFNGLDEPTHRANGEARRAYVPROC glDepthRangeArrayv;
extern PFNGLDEPTHRANGEINDEXEDPROC glDepthRangeIndexed;
extern PFNGLGETFLOATI_VPROC glGetFloati_v;
extern PFNGLGETDOUBLEI_VPROC glGetDoublei_v;

	// OpenGL 4.2
	// GL_ARB_texture_storage
extern PFNGLTEXSTORAGE1DPROC glTexStorage1D;
extern PFNGLTEXSTORAGE2DPROC glTexStorage2D;
extern PFNGLTEXSTORAGE3DPROC glTexStorage3D;

	// GL_ARB_base_instance
extern PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC glDrawArraysInstancedBaseInstance;
extern PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC glDrawElementsInstancedBaseInstance;
extern PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC glDrawElementsInstancedBaseVertexBaseInstance;

	// GL_ARB_shader_image_load_store
extern PFNGLBINDIMAGETEXTUREPROC glBindImageTexture;
extern PFNGLMEMORYBARRIERPROC glMemoryBarrier;

	// GL_ARB_internalformat_query
extern PFNGLGETINTERNALFORMATIVPROC glGetInternalformativ;

	// GL_ARB_transform_feedback_instanced
extern PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC glDrawTransformFeedbackInstanced;
extern PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC glDrawTransformFeedbackStreamInstanced;

	// OpenGL 4.3
	// GL_ARB_vertex_attrib_binding
	typedef void (APIENTRY * PFNGLVERTEXARRAYBINDVERTEXBUFFEREXTPROC) (GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
	typedef void (APIENTRY * PFNGLVERTEXARRAYBINDVERTEXATTRIBFORMATEXTPROC) (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
	typedef void (APIENTRY * PFNGLVERTEXARRAYBINDVERTEXATTRIBIFORMATEXTPROC) (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
	typedef void (APIENTRY * PFNGLVERTEXARRAYBINDVERTEXATTRIBLFORMATEXTPROC) (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
	typedef void (APIENTRY * PFNGLVERTEXARRAYBINDVERTEXATTRIBBINDINGEXTPROC) (GLuint vaobj, GLuint attribindex, GLuint bindingindex);
	typedef void (APIENTRY * PFNGLVERTEXARRAYBINDVERTEXBINDINGDIVISOREXTPROC) (GLuint vaobj, GLuint bindingindex, GLuint divisor);

extern PFNGLVERTEXARRAYBINDVERTEXBUFFEREXTPROC glVertexArrayBindVertexBufferEXT;
extern PFNGLVERTEXARRAYBINDVERTEXATTRIBFORMATEXTPROC glVertexArrayVertexAttribFormatEXT;
extern PFNGLVERTEXARRAYBINDVERTEXATTRIBIFORMATEXTPROC glVertexArrayVertexAttribIFormatEXT;
extern PFNGLVERTEXARRAYBINDVERTEXATTRIBLFORMATEXTPROC glVertexArrayVertexAttribLFormatEXT;
extern PFNGLVERTEXARRAYBINDVERTEXATTRIBBINDINGEXTPROC glVertexArrayVertexAttribBindingEXT;
extern PFNGLVERTEXARRAYBINDVERTEXBINDINGDIVISOREXTPROC glVertexArrayVertexBindingDivisorEXT;

	// GL_ARB_clear_buffer_object
extern PFNGLCLEARBUFFERDATAPROC glClearBufferData;
extern PFNGLCLEARBUFFERSUBDATAPROC glClearBufferSubData;
extern PFNGLCLEARNAMEDBUFFERDATAEXTPROC glClearNamedBufferDataEXT;
extern PFNGLCLEARNAMEDBUFFERSUBDATAEXTPROC glClearNamedBufferSubDataEXT;

	// GL_ARB_compute_shader
	#define GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS 0x90EB

extern PFNGLDISPATCHCOMPUTEPROC glDispatchCompute;
extern PFNGLDISPATCHCOMPUTEINDIRECTPROC glDispatchComputeIndirect;

	// GL_ARB_copy_image
extern PFNGLCOPYIMAGESUBDATAPROC glCopyImageSubData;

	// GL_ARB_multi_draw_indirect
extern PFNGLMULTIDRAWARRAYSINDIRECTPROC glMultiDrawArraysIndirect;
extern PFNGLMULTIDRAWELEMENTSINDIRECTPROC glMultiDrawElementsIndirect;

	// GL_ARB_program_interface_query
extern PFNGLGETPROGRAMINTERFACEIVPROC glGetProgramInterfaceiv;
extern PFNGLGETPROGRAMRESOURCEINDEXPROC glGetProgramResourceIndex;
extern PFNGLGETPROGRAMRESOURCENAMEPROC glGetProgramResourceName;
extern PFNGLGETPROGRAMRESOURCEIVPROC glGetProgramResourceiv;
extern PFNGLGETPROGRAMRESOURCELOCATIONPROC glGetProgramResourceLocation;
extern PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC glGetProgramResourceLocationIndex;

	// GL_ARB_texture_buffer_range
extern PFNGLTEXBUFFERRANGEPROC glTexBufferRange;
extern PFNGLTEXTUREBUFFERRANGEEXTPROC glTextureBufferRangeEXT;

	// GL_ARB_texture_storage_multisample
extern PFNGLTEXSTORAGE2DMULTISAMPLEPROC glTexStorage2DMultisample;
extern PFNGLTEXSTORAGE3DMULTISAMPLEPROC glTexStorage3DMultisample;
extern PFNGLTEXTURESTORAGE2DMULTISAMPLEEXTPROC glTextureStorage2DMultisampleEXT;
extern PFNGLTEXTURESTORAGE3DMULTISAMPLEEXTPROC glTextureStorage3DMultisampleEXT;

	// GL_ARB_texture_view
extern PFNGLTEXTUREVIEWPROC glTextureView;

	// GL_KHR_debug
extern PFNGLDEBUGMESSAGECONTROLPROC glDebugMessageControl;
extern PFNGLDEBUGMESSAGEINSERTPROC glDebugMessageInsert;
extern PFNGLDEBUGMESSAGECALLBACKPROC glDebugMessageCallback;
extern PFNGLGETDEBUGMESSAGELOGPROC glGetDebugMessageLog;
extern PFNGLPUSHDEBUGGROUPPROC glPushDebugGroup;
extern PFNGLPOPDEBUGGROUPPROC glPopDebugGroup;
extern PFNGLOBJECTLABELPROC glObjectLabel;
extern PFNGLGETOBJECTLABELPROC glGetObjectLabel;
extern PFNGLOBJECTPTRLABELPROC glObjectPtrLabel;
extern PFNGLGETOBJECTPTRLABELPROC glGetObjectPtrLabel;

	// GL_EXT_direct_state_access
	typedef void (APIENTRY * PFNGLBINDMULTITEXTUREEXTPROC) (GLenum texunit, GLenum target, GLuint texture);
	typedef GLenum (APIENTRY * PFNGLCHECKNAMEDFRAMEBUFFERSTATUSEXTPROC) (GLuint framebuffer, GLenum target);
	typedef void (APIENTRY * PFNGLCLIENTATTRIBDEFAULTEXTPROC) (GLbitfield mask);
	typedef void (APIENTRY * PFNGLCOMPRESSEDMULTITEXIMAGE1DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void* data);
	typedef void (APIENTRY * PFNGLCOMPRESSEDMULTITEXIMAGE2DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void* data);
	typedef void (APIENTRY * PFNGLCOMPRESSEDMULTITEXIMAGE3DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void* data);
	typedef void (APIENTRY * PFNGLCOMPRESSEDMULTITEXSUBIMAGE1DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* data);
	typedef void (APIENTRY * PFNGLCOMPRESSEDMULTITEXSUBIMAGE2DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data);
	typedef void (APIENTRY * PFNGLCOMPRESSEDMULTITEXSUBIMAGE3DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data);
	typedef void (APIENTRY * PFNGLCOMPRESSEDTEXTUREIMAGE1DEXTPROC) (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void* data);
	typedef void (APIENTRY * PFNGLCOMPRESSEDTEXTUREIMAGE2DEXTPROC) (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void* data);
	typedef void (APIENTRY * PFNGLCOMPRESSEDTEXTUREIMAGE3DEXTPROC) (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void* data);
	typedef void (APIENTRY * PFNGLCOMPRESSEDTEXTURESUBIMAGE1DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* data);
	typedef void (APIENTRY * PFNGLCOMPRESSEDTEXTURESUBIMAGE2DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data);
	typedef void (APIENTRY * PFNGLCOMPRESSEDTEXTURESUBIMAGE3DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data);
	typedef void (APIENTRY * PFNGLCOPYMULTITEXIMAGE1DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
	typedef void (APIENTRY * PFNGLCOPYMULTITEXIMAGE2DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
	typedef void (APIENTRY * PFNGLCOPYMULTITEXSUBIMAGE1DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
	typedef void (APIENTRY * PFNGLCOPYMULTITEXSUBIMAGE2DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
	typedef void (APIENTRY * PFNGLCOPYMULTITEXSUBIMAGE3DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
	typedef void (APIENTRY * PFNGLCOPYTEXTUREIMAGE1DEXTPROC) (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
	typedef void (APIENTRY * PFNGLCOPYTEXTUREIMAGE2DEXTPROC) (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
	typedef void (APIENTRY * PFNGLCOPYTEXTURESUBIMAGE1DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
	typedef void (APIENTRY * PFNGLCOPYTEXTURESUBIMAGE2DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
	typedef void (APIENTRY * PFNGLCOPYTEXTURESUBIMAGE3DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
	typedef void (APIENTRY * PFNGLDISABLECLIENTSTATEINDEXEDEXTPROC) (GLenum array, GLuint index);
	typedef void (APIENTRY * PFNGLDISABLECLIENTSTATEIEXTPROC) (GLenum array, GLuint index);
	typedef void (APIENTRY * PFNGLDISABLEVERTEXARRAYATTRIBEXTPROC) (GLuint vaobj, GLuint index);
	typedef void (APIENTRY * PFNGLDISABLEVERTEXARRAYEXTPROC) (GLuint vaobj, GLenum array);
	typedef void (APIENTRY * PFNGLENABLECLIENTSTATEINDEXEDEXTPROC) (GLenum array, GLuint index);
	typedef void (APIENTRY * PFNGLENABLECLIENTSTATEIEXTPROC) (GLenum array, GLuint index);
	typedef void (APIENTRY * PFNGLENABLEVERTEXARRAYATTRIBEXTPROC) (GLuint vaobj, GLuint index);
	typedef void (APIENTRY * PFNGLENABLEVERTEXARRAYEXTPROC) (GLuint vaobj, GLenum array);
	typedef void (APIENTRY * PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEEXTPROC) (GLuint buffer, GLintptr offset, GLsizeiptr length);
	typedef void (APIENTRY * PFNGLFRAMEBUFFERDRAWBUFFEREXTPROC) (GLuint framebuffer, GLenum mode);
	typedef void (APIENTRY * PFNGLFRAMEBUFFERDRAWBUFFERSEXTPROC) (GLuint framebuffer, GLsizei n, const GLenum* bufs);
	typedef void (APIENTRY * PFNGLFRAMEBUFFERREADBUFFEREXTPROC) (GLuint framebuffer, GLenum mode);
	typedef void (APIENTRY * PFNGLGENERATEMULTITEXMIPMAPEXTPROC) (GLenum texunit, GLenum target);
	typedef void (APIENTRY * PFNGLGENERATETEXTUREMIPMAPEXTPROC) (GLuint texture, GLenum target);
	typedef void (APIENTRY * PFNGLGETCOMPRESSEDMULTITEXIMAGEEXTPROC) (GLenum texunit, GLenum target, GLint level, void* img);
	typedef void (APIENTRY * PFNGLGETCOMPRESSEDTEXTUREIMAGEEXTPROC) (GLuint texture, GLenum target, GLint level, void* img);
	typedef void (APIENTRY * PFNGLGETDOUBLEINDEXEDVEXTPROC) (GLenum target, GLuint index, GLdouble* params);
	typedef void (APIENTRY * PFNGLGETDOUBLEI_VEXTPROC) (GLenum pname, GLuint index, GLdouble* params);
	typedef void (APIENTRY * PFNGLGETFLOATINDEXEDVEXTPROC) (GLenum target, GLuint index, GLfloat* params);
	typedef void (APIENTRY * PFNGLGETFLOATI_VEXTPROC) (GLenum pname, GLuint index, GLfloat* params);
	typedef void (APIENTRY * PFNGLGETFRAMEBUFFERPARAMETERIVEXTPROC) (GLuint framebuffer, GLenum pname, GLint* param);
	typedef void (APIENTRY * PFNGLGETMULTITEXENVFVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLfloat* params);
	typedef void (APIENTRY * PFNGLGETMULTITEXENVIVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLint* params);
	typedef void (APIENTRY * PFNGLGETMULTITEXGENDVEXTPROC) (GLenum texunit, GLenum coord, GLenum pname, GLdouble* params);
	typedef void (APIENTRY * PFNGLGETMULTITEXGENFVEXTPROC) (GLenum texunit, GLenum coord, GLenum pname, GLfloat* params);
	typedef void (APIENTRY * PFNGLGETMULTITEXGENIVEXTPROC) (GLenum texunit, GLenum coord, GLenum pname, GLint* params);
	typedef void (APIENTRY * PFNGLGETMULTITEXIMAGEEXTPROC) (GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, void* pixels);
	typedef void (APIENTRY * PFNGLGETMULTITEXLEVELPARAMETERFVEXTPROC) (GLenum texunit, GLenum target, GLint level, GLenum pname, GLfloat* params);
	typedef void (APIENTRY * PFNGLGETMULTITEXLEVELPARAMETERIVEXTPROC) (GLenum texunit, GLenum target, GLint level, GLenum pname, GLint* params);
	typedef void (APIENTRY * PFNGLGETMULTITEXPARAMETERIIVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLint* params);
	typedef void (APIENTRY * PFNGLGETMULTITEXPARAMETERIUIVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLuint* params);
	typedef void (APIENTRY * PFNGLGETMULTITEXPARAMETERFVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLfloat* params);
	typedef void (APIENTRY * PFNGLGETMULTITEXPARAMETERIVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLint* params);
	typedef void (APIENTRY * PFNGLGETNAMEDBUFFERPARAMETERIVEXTPROC) (GLuint buffer, GLenum pname, GLint* params);
	typedef void (APIENTRY * PFNGLGETNAMEDBUFFERPOINTERVEXTPROC) (GLuint buffer, GLenum pname, void** params);
	typedef void (APIENTRY * PFNGLGETNAMEDBUFFERSUBDATAEXTPROC) (GLuint buffer, GLintptr offset, GLsizeiptr size, void* data);
	typedef void (APIENTRY * PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC) (GLuint framebuffer, GLenum attachment, GLenum pname, GLint* params);
	typedef void (APIENTRY * PFNGLGETNAMEDPROGRAMLOCALPARAMETERIIVEXTPROC) (GLuint program, GLenum target, GLuint index, GLint* params);
	typedef void (APIENTRY * PFNGLGETNAMEDPROGRAMLOCALPARAMETERIUIVEXTPROC) (GLuint program, GLenum target, GLuint index, GLuint* params);
	typedef void (APIENTRY * PFNGLGETNAMEDPROGRAMLOCALPARAMETERDVEXTPROC) (GLuint program, GLenum target, GLuint index, GLdouble* params);
	typedef void (APIENTRY * PFNGLGETNAMEDPROGRAMLOCALPARAMETERFVEXTPROC) (GLuint program, GLenum target, GLuint index, GLfloat* params);
	typedef void (APIENTRY * PFNGLGETNAMEDPROGRAMSTRINGEXTPROC) (GLuint program, GLenum target, GLenum pname, void* string);
	typedef void (APIENTRY * PFNGLGETNAMEDPROGRAMIVEXTPROC) (GLuint program, GLenum target, GLenum pname, GLint* params);
	typedef void (APIENTRY * PFNGLGETNAMEDRENDERBUFFERPARAMETERIVEXTPROC) (GLuint renderbuffer, GLenum pname, GLint* params);
	typedef void (APIENTRY * PFNGLGETPOINTERINDEXEDVEXTPROC) (GLenum target, GLuint index, GLvoid** params);
	typedef void (APIENTRY * PFNGLGETPOINTERI_VEXTPROC) (GLenum pname, GLuint index, GLvoid** params);
	typedef void (APIENTRY * PFNGLGETTEXTUREIMAGEEXTPROC) (GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, void* pixels);
	typedef void (APIENTRY * PFNGLGETTEXTURELEVELPARAMETERFVEXTPROC) (GLuint texture, GLenum target, GLint level, GLenum pname, GLfloat* params);
	typedef void (APIENTRY * PFNGLGETTEXTURELEVELPARAMETERIVEXTPROC) (GLuint texture, GLenum target, GLint level, GLenum pname, GLint* params);
	typedef void (APIENTRY * PFNGLGETTEXTUREPARAMETERIIVEXTPROC) (GLuint texture, GLenum target, GLenum pname, GLint* params);
	typedef void (APIENTRY * PFNGLGETTEXTUREPARAMETERIUIVEXTPROC) (GLuint texture, GLenum target, GLenum pname, GLuint* params);
	typedef void (APIENTRY * PFNGLGETTEXTUREPARAMETERFVEXTPROC) (GLuint texture, GLenum target, GLenum pname, GLfloat* params);
	typedef void (APIENTRY * PFNGLGETTEXTUREPARAMETERIVEXTPROC) (GLuint texture, GLenum target, GLenum pname, GLint* params);
	typedef void (APIENTRY * PFNGLGETVERTEXARRAYINTEGERI_VEXTPROC) (GLuint vaobj, GLuint index, GLenum pname, GLint* param);
	typedef void (APIENTRY * PFNGLGETVERTEXARRAYINTEGERVEXTPROC) (GLuint vaobj, GLenum pname, GLint* param);
	typedef void (APIENTRY * PFNGLGETVERTEXARRAYPOINTERI_VEXTPROC) (GLuint vaobj, GLuint index, GLenum pname, GLvoid** param);
	typedef void (APIENTRY * PFNGLGETVERTEXARRAYPOINTERVEXTPROC) (GLuint vaobj, GLenum pname, GLvoid** param);
	typedef GLvoid * (APIENTRY * PFNGLMAPNAMEDBUFFEREXTPROC) (GLuint buffer, GLenum access);
	typedef GLvoid * (APIENTRY * PFNGLMAPNAMEDBUFFERRANGEEXTPROC) (GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
	typedef void (APIENTRY * PFNGLMATRIXFRUSTUMEXTPROC) (GLenum matrixMode, GLdouble l, GLdouble r, GLdouble b, GLdouble t, GLdouble n, GLdouble f);
	typedef void (APIENTRY * PFNGLMATRIXLOADIDENTITYEXTPROC) (GLenum matrixMode);
	typedef void (APIENTRY * PFNGLMATRIXLOADTRANSPOSEDEXTPROC) (GLenum matrixMode, const GLdouble* m);
	typedef void (APIENTRY * PFNGLMATRIXLOADTRANSPOSEFEXTPROC) (GLenum matrixMode, const GLfloat* m);
	typedef void (APIENTRY * PFNGLMATRIXLOADDEXTPROC) (GLenum matrixMode, const GLdouble* m);
	typedef void (APIENTRY * PFNGLMATRIXLOADFEXTPROC) (GLenum matrixMode, const GLfloat* m);
	typedef void (APIENTRY * PFNGLMATRIXMULTTRANSPOSEDEXTPROC) (GLenum matrixMode, const GLdouble* m);
	typedef void (APIENTRY * PFNGLMATRIXMULTTRANSPOSEFEXTPROC) (GLenum matrixMode, const GLfloat* m);
	typedef void (APIENTRY * PFNGLMATRIXMULTDEXTPROC) (GLenum matrixMode, const GLdouble* m);
	typedef void (APIENTRY * PFNGLMATRIXMULTFEXTPROC) (GLenum matrixMode, const GLfloat* m);
	typedef void (APIENTRY * PFNGLMATRIXORTHOEXTPROC) (GLenum matrixMode, GLdouble l, GLdouble r, GLdouble b, GLdouble t, GLdouble n, GLdouble f);
	typedef void (APIENTRY * PFNGLMATRIXPOPEXTPROC) (GLenum matrixMode);
	typedef void (APIENTRY * PFNGLMATRIXPUSHEXTPROC) (GLenum matrixMode);
	typedef void (APIENTRY * PFNGLMATRIXROTATEDEXTPROC) (GLenum matrixMode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
	typedef void (APIENTRY * PFNGLMATRIXROTATEFEXTPROC) (GLenum matrixMode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
	typedef void (APIENTRY * PFNGLMATRIXSCALEDEXTPROC) (GLenum matrixMode, GLdouble x, GLdouble y, GLdouble z);
	typedef void (APIENTRY * PFNGLMATRIXSCALEFEXTPROC) (GLenum matrixMode, GLfloat x, GLfloat y, GLfloat z);
	typedef void (APIENTRY * PFNGLMATRIXTRANSLATEDEXTPROC) (GLenum matrixMode, GLdouble x, GLdouble y, GLdouble z);
	typedef void (APIENTRY * PFNGLMATRIXTRANSLATEFEXTPROC) (GLenum matrixMode, GLfloat x, GLfloat y, GLfloat z);
	typedef void (APIENTRY * PFNGLMULTITEXBUFFEREXTPROC) (GLenum texunit, GLenum target, GLenum internalformat, GLuint buffer);
	typedef void (APIENTRY * PFNGLMULTITEXCOORDPOINTEREXTPROC) (GLenum texunit, GLint size, GLenum type, GLsizei stride, const void* pointer);
	typedef void (APIENTRY * PFNGLMULTITEXENVFEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLfloat param);
	typedef void (APIENTRY * PFNGLMULTITEXENVFVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, const GLfloat* params);
	typedef void (APIENTRY * PFNGLMULTITEXENVIEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLint param);
	typedef void (APIENTRY * PFNGLMULTITEXENVIVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, const GLint* params);
	typedef void (APIENTRY * PFNGLMULTITEXGENDEXTPROC) (GLenum texunit, GLenum coord, GLenum pname, GLdouble param);
	typedef void (APIENTRY * PFNGLMULTITEXGENDVEXTPROC) (GLenum texunit, GLenum coord, GLenum pname, const GLdouble* params);
	typedef void (APIENTRY * PFNGLMULTITEXGENFEXTPROC) (GLenum texunit, GLenum coord, GLenum pname, GLfloat param);
	typedef void (APIENTRY * PFNGLMULTITEXGENFVEXTPROC) (GLenum texunit, GLenum coord, GLenum pname, const GLfloat* params);
	typedef void (APIENTRY * PFNGLMULTITEXGENIEXTPROC) (GLenum texunit, GLenum coord, GLenum pname, GLint param);
	typedef void (APIENTRY * PFNGLMULTITEXGENIVEXTPROC) (GLenum texunit, GLenum coord, GLenum pname, const GLint* params);
	typedef void (APIENTRY * PFNGLMULTITEXIMAGE1DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void* pixels);
	typedef void (APIENTRY * PFNGLMULTITEXIMAGE2DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void* pixels);
	typedef void (APIENTRY * PFNGLMULTITEXIMAGE3DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void* pixels);
	typedef void (APIENTRY * PFNGLMULTITEXPARAMETERIIVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, const GLint* params);
	typedef void (APIENTRY * PFNGLMULTITEXPARAMETERIUIVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, const GLuint* params);
	typedef void (APIENTRY * PFNGLMULTITEXPARAMETERFEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLfloat param);
	typedef void (APIENTRY * PFNGLMULTITEXPARAMETERFVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, const GLfloat* param);
	typedef void (APIENTRY * PFNGLMULTITEXPARAMETERIEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLint param);
	typedef void (APIENTRY * PFNGLMULTITEXPARAMETERIVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, const GLint* param);
	typedef void (APIENTRY * PFNGLMULTITEXRENDERBUFFEREXTPROC) (GLenum texunit, GLenum target, GLuint renderbuffer);
	typedef void (APIENTRY * PFNGLMULTITEXSUBIMAGE1DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels);
	typedef void (APIENTRY * PFNGLMULTITEXSUBIMAGE2DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels);
	typedef void (APIENTRY * PFNGLMULTITEXSUBIMAGE3DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels);
	typedef void (APIENTRY * PFNGLNAMEDBUFFERDATAEXTPROC) (GLuint buffer, GLsizeiptr size, const void* data, GLenum usage);
	typedef void (APIENTRY * PFNGLNAMEDBUFFERSUBDATAEXTPROC) (GLuint buffer, GLintptr offset, GLsizeiptr size, const void* data);
	typedef void (APIENTRY * PFNGLNAMEDCOPYBUFFERSUBDATAEXTPROC) (GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
	typedef void (APIENTRY * PFNGLNAMEDFRAMEBUFFERRENDERBUFFEREXTPROC) (GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
	typedef void (APIENTRY * PFNGLNAMEDFRAMEBUFFERTEXTURE1DEXTPROC) (GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
	typedef void (APIENTRY * PFNGLNAMEDFRAMEBUFFERTEXTURE2DEXTPROC) (GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
	typedef void (APIENTRY * PFNGLNAMEDFRAMEBUFFERTEXTURE3DEXTPROC) (GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
	typedef void (APIENTRY * PFNGLNAMEDFRAMEBUFFERTEXTUREEXTPROC) (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
	typedef void (APIENTRY * PFNGLNAMEDFRAMEBUFFERTEXTUREFACEEXTPROC) (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLenum face);
	typedef void (APIENTRY * PFNGLNAMEDFRAMEBUFFERTEXTURELAYEREXTPROC) (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
	typedef void (APIENTRY * PFNGLNAMEDPROGRAMLOCALPARAMETER4DEXTPROC) (GLuint program, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	typedef void (APIENTRY * PFNGLNAMEDPROGRAMLOCALPARAMETER4DVEXTPROC) (GLuint program, GLenum target, GLuint index, const GLdouble* params);
	typedef void (APIENTRY * PFNGLNAMEDPROGRAMLOCALPARAMETER4FEXTPROC) (GLuint program, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	typedef void (APIENTRY * PFNGLNAMEDPROGRAMLOCALPARAMETER4FVEXTPROC) (GLuint program, GLenum target, GLuint index, const GLfloat* params);
	typedef void (APIENTRY * PFNGLNAMEDPROGRAMLOCALPARAMETERI4IEXTPROC) (GLuint program, GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
	typedef void (APIENTRY * PFNGLNAMEDPROGRAMLOCALPARAMETERI4IVEXTPROC) (GLuint program, GLenum target, GLuint index, const GLint* params);
	typedef void (APIENTRY * PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIEXTPROC) (GLuint program, GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
	typedef void (APIENTRY * PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIVEXTPROC) (GLuint program, GLenum target, GLuint index, const GLuint* params);
	typedef void (APIENTRY * PFNGLNAMEDPROGRAMLOCALPARAMETERS4FVEXTPROC) (GLuint program, GLenum target, GLuint index, GLsizei count, const GLfloat* params);
	typedef void (APIENTRY * PFNGLNAMEDPROGRAMLOCALPARAMETERSI4IVEXTPROC) (GLuint program, GLenum target, GLuint index, GLsizei count, const GLint* params);
	typedef void (APIENTRY * PFNGLNAMEDPROGRAMLOCALPARAMETERSI4UIVEXTPROC) (GLuint program, GLenum target, GLuint index, GLsizei count, const GLuint* params);
	typedef void (APIENTRY * PFNGLNAMEDPROGRAMSTRINGEXTPROC) (GLuint program, GLenum target, GLenum format, GLsizei len, const void* string);
	typedef void (APIENTRY * PFNGLNAMEDRENDERBUFFERSTORAGEEXTPROC) (GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
	typedef void (APIENTRY * PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLECOVERAGEEXTPROC) (GLuint renderbuffer, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height);
	typedef void (APIENTRY * PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC) (GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
	typedef void (APIENTRY * PFNGLPUSHCLIENTATTRIBDEFAULTEXTPROC) (GLbitfield mask);
	typedef void (APIENTRY * PFNGLTEXTUREBUFFEREXTPROC) (GLuint texture, GLenum target, GLenum internalformat, GLuint buffer);
	typedef void (APIENTRY * PFNGLTEXTUREIMAGE1DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void* pixels);
	typedef void (APIENTRY * PFNGLTEXTUREIMAGE2DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void* pixels);
	typedef void (APIENTRY * PFNGLTEXTUREIMAGE3DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void* pixels);
	typedef void (APIENTRY * PFNGLTEXTUREPARAMETERIIVEXTPROC) (GLuint texture, GLenum target, GLenum pname, const GLint* params);
	typedef void (APIENTRY * PFNGLTEXTUREPARAMETERIUIVEXTPROC) (GLuint texture, GLenum target, GLenum pname, const GLuint* params);
	typedef void (APIENTRY * PFNGLTEXTUREPARAMETERFEXTPROC) (GLuint texture, GLenum target, GLenum pname, GLfloat param);
	typedef void (APIENTRY * PFNGLTEXTUREPARAMETERFVEXTPROC) (GLuint texture, GLenum target, GLenum pname, const GLfloat* param);
	typedef void (APIENTRY * PFNGLTEXTUREPARAMETERIEXTPROC) (GLuint texture, GLenum target, GLenum pname, GLint param);
	typedef void (APIENTRY * PFNGLTEXTUREPARAMETERIVEXTPROC) (GLuint texture, GLenum target, GLenum pname, const GLint* param);
	typedef void (APIENTRY * PFNGLTEXTURERENDERBUFFEREXTPROC) (GLuint texture, GLenum target, GLuint renderbuffer);
	typedef void (APIENTRY * PFNGLTEXTURESUBIMAGE1DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels);
	typedef void (APIENTRY * PFNGLTEXTURESUBIMAGE2DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels);
	typedef void (APIENTRY * PFNGLTEXTURESUBIMAGE3DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels);
	typedef GLboolean (APIENTRY * PFNGLUNMAPNAMEDBUFFEREXTPROC) (GLuint buffer);
	typedef void (APIENTRY * PFNGLVERTEXARRAYVERTEXATTRIBIOFFSETEXTPROC) (GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset);
	typedef void (APIENTRY * PFNGLVERTEXARRAYVERTEXATTRIBOFFSETEXTPROC) (GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLintptr offset);
	typedef void (APIENTRY * PFNGLVERTEXARRAYVERTEXOFFSETEXTPROC) (GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);

extern PFNGLTEXTURESTORAGE1DEXTPROC glTextureStorage1DEXT;
extern PFNGLTEXTURESTORAGE2DEXTPROC glTextureStorage2DEXT;
extern PFNGLTEXTURESTORAGE3DEXTPROC glTextureStorage3DEXT;

extern PFNGLBINDMULTITEXTUREEXTPROC glBindMultiTextureEXT;
extern PFNGLCHECKNAMEDFRAMEBUFFERSTATUSEXTPROC glCheckNamedFramebufferStatusEXT;
extern PFNGLCLIENTATTRIBDEFAULTEXTPROC glClientAttribDefaultEXT;
extern PFNGLCOMPRESSEDTEXTUREIMAGE1DEXTPROC glCompressedTextureImage1DEXT;
extern PFNGLCOMPRESSEDTEXTUREIMAGE2DEXTPROC glCompressedTextureImage2DEXT;
extern PFNGLCOMPRESSEDTEXTUREIMAGE3DEXTPROC glCompressedTextureImage3DEXT;
extern PFNGLCOMPRESSEDTEXTURESUBIMAGE1DEXTPROC glCompressedTextureSubImage1DEXT;
extern PFNGLCOMPRESSEDTEXTURESUBIMAGE2DEXTPROC glCompressedTextureSubImage2DEXT;
extern PFNGLCOMPRESSEDTEXTURESUBIMAGE3DEXTPROC glCompressedTextureSubImage3DEXT;
extern PFNGLCOPYTEXTUREIMAGE1DEXTPROC glCopyTextureImage1DEXT;
extern PFNGLCOPYTEXTUREIMAGE2DEXTPROC glCopyTextureImage2DEXT;
extern PFNGLCOPYTEXTURESUBIMAGE1DEXTPROC glCopyTextureSubImage1DEXT;
extern PFNGLCOPYTEXTURESUBIMAGE2DEXTPROC glCopyTextureSubImage2DEXT;
extern PFNGLCOPYTEXTURESUBIMAGE3DEXTPROC glCopyTextureSubImage3DEXT;
extern PFNGLDISABLEVERTEXARRAYATTRIBEXTPROC glDisableVertexArrayAttribEXT;
extern PFNGLDISABLEVERTEXARRAYEXTPROC glDisableVertexArrayEXT;
extern PFNGLENABLEVERTEXARRAYATTRIBEXTPROC glEnableVertexArrayAttribEXT;
extern PFNGLENABLEVERTEXARRAYEXTPROC glEnableVertexArrayEXT;
extern PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEEXTPROC glFlushMappedNamedBufferRangeEXT;
extern PFNGLFRAMEBUFFERDRAWBUFFEREXTPROC glFramebufferDrawBufferEXT;
extern PFNGLFRAMEBUFFERDRAWBUFFERSEXTPROC glFramebufferDrawBuffersEXT;
extern PFNGLFRAMEBUFFERREADBUFFEREXTPROC glFramebufferReadBufferEXT;
extern PFNGLGENERATETEXTUREMIPMAPEXTPROC glGenerateTextureMipmapEXT;
extern PFNGLGETCOMPRESSEDTEXTUREIMAGEEXTPROC glGetCompressedTextureImageEXT;
extern PFNGLGETFRAMEBUFFERPARAMETERIVEXTPROC glGetFramebufferParameterivEXT;
extern PFNGLGETNAMEDBUFFERPARAMETERIVEXTPROC glGetNamedBufferParameterivEXT;
extern PFNGLGETNAMEDBUFFERPOINTERVEXTPROC glGetNamedBufferPointervEXT;
extern PFNGLGETNAMEDBUFFERSUBDATAEXTPROC glGetNamedBufferSubDataEXT;
extern PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC glGetNamedFramebufferAttachmentParameterivEXT;
extern PFNGLGETNAMEDPROGRAMSTRINGEXTPROC glGetNamedProgramStringEXT;
extern PFNGLGETNAMEDPROGRAMIVEXTPROC glGetNamedProgramivEXT;
extern PFNGLGETNAMEDRENDERBUFFERPARAMETERIVEXTPROC glGetNamedRenderbufferParameterivEXT;
extern PFNGLGETTEXTUREIMAGEEXTPROC glGetTextureImageEXT;
extern PFNGLGETTEXTURELEVELPARAMETERFVEXTPROC glGetTextureLevelParameterfvEXT;
extern PFNGLGETTEXTURELEVELPARAMETERIVEXTPROC glGetTextureLevelParameterivEXT;
extern PFNGLGETTEXTUREPARAMETERIIVEXTPROC glGetTextureParameterIivEXT;
extern PFNGLGETTEXTUREPARAMETERIUIVEXTPROC glGetTextureParameterIuivEXT;
extern PFNGLGETTEXTUREPARAMETERFVEXTPROC glGetTextureParameterfvEXT;
extern PFNGLGETTEXTUREPARAMETERIVEXTPROC glGetTextureParameterivEXT;
extern PFNGLGETVERTEXARRAYINTEGERI_VEXTPROC glGetVertexArrayIntegeri_vEXT;
extern PFNGLGETVERTEXARRAYINTEGERVEXTPROC glGetVertexArrayIntegervEXT;
extern PFNGLGETVERTEXARRAYPOINTERI_VEXTPROC glGetVertexArrayPointeri_vEXT;
extern PFNGLGETVERTEXARRAYPOINTERVEXTPROC glGetVertexArrayPointervEXT;
extern PFNGLMAPNAMEDBUFFEREXTPROC glMapNamedBufferEXT;
extern PFNGLMAPNAMEDBUFFERRANGEEXTPROC glMapNamedBufferRangeEXT;
extern PFNGLNAMEDBUFFERDATAEXTPROC glNamedBufferDataEXT;
extern PFNGLNAMEDBUFFERSUBDATAEXTPROC glNamedBufferSubDataEXT;
extern PFNGLNAMEDCOPYBUFFERSUBDATAEXTPROC glNamedCopyBufferSubDataEXT;
extern PFNGLNAMEDFRAMEBUFFERRENDERBUFFEREXTPROC glNamedFramebufferRenderbufferEXT;
extern PFNGLNAMEDFRAMEBUFFERTEXTURE1DEXTPROC glNamedFramebufferTexture1DEXT;
extern PFNGLNAMEDFRAMEBUFFERTEXTURE2DEXTPROC glNamedFramebufferTexture2DEXT;
extern PFNGLNAMEDFRAMEBUFFERTEXTURE3DEXTPROC glNamedFramebufferTexture3DEXT;
extern PFNGLNAMEDFRAMEBUFFERTEXTUREEXTPROC glNamedFramebufferTextureEXT;
extern PFNGLNAMEDFRAMEBUFFERTEXTUREFACEEXTPROC glNamedFramebufferTextureFaceEXT;
extern PFNGLNAMEDFRAMEBUFFERTEXTURELAYEREXTPROC glNamedFramebufferTextureLayerEXT;
extern PFNGLNAMEDPROGRAMSTRINGEXTPROC glNamedProgramStringEXT;
extern PFNGLNAMEDRENDERBUFFERSTORAGEEXTPROC glNamedRenderbufferStorageEXT;
extern PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLECOVERAGEEXTPROC glNamedRenderbufferStorageMultisampleCoverageEXT;
extern PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC glNamedRenderbufferStorageMultisampleEXT;
extern PFNGLTEXTUREBUFFEREXTPROC glTextureBufferEXT;
extern PFNGLTEXTUREIMAGE1DEXTPROC glTextureImage1DEXT;
extern PFNGLTEXTUREIMAGE2DEXTPROC glTextureImage2DEXT;
extern PFNGLTEXTUREIMAGE3DEXTPROC glTextureImage3DEXT;
extern PFNGLTEXTUREPARAMETERIIVEXTPROC glTextureParameterIivEXT;
extern PFNGLTEXTUREPARAMETERIUIVEXTPROC glTextureParameterIuivEXT;
extern PFNGLTEXTUREPARAMETERFEXTPROC glTextureParameterfEXT;
extern PFNGLTEXTUREPARAMETERFVEXTPROC glTextureParameterfvEXT;
extern PFNGLTEXTUREPARAMETERIEXTPROC glTextureParameteriEXT;
extern PFNGLTEXTUREPARAMETERIVEXTPROC glTextureParameterivEXT;
extern PFNGLTEXTURERENDERBUFFEREXTPROC glTextureRenderbufferEXT;
extern PFNGLTEXTURESUBIMAGE1DEXTPROC glTextureSubImage1DEXT;
extern PFNGLTEXTURESUBIMAGE2DEXTPROC glTextureSubImage2DEXT;
extern PFNGLTEXTURESUBIMAGE3DEXTPROC glTextureSubImage3DEXT;
extern PFNGLUNMAPNAMEDBUFFEREXTPROC glUnmapNamedBufferEXT;
	extern PFNGLVERTEXARRAYVERTEXATTRIBIOFFSETEXTPROC glVertexArrayVertexAttribIOffsetEXT;
	extern PFNGLVERTEXARRAYVERTEXATTRIBOFFSETEXTPROC glVertexArrayVertexAttribOffsetEXT;
	extern PFNGLVERTEXARRAYVERTEXOFFSETEXTPROC glVertexArrayVertexOffsetEXT;

	// GL_AMD_sample_positions
	#define GL_SUBSAMPLE_DISTANCE_AMD 0x883F

	typedef void (APIENTRY * PFNGLSETMULTISAMPLEFVAMDPROC) (GLenum pname, GLuint index, const GLfloat* val);

	extern PFNGLSETMULTISAMPLEFVAMDPROC glSetMultisamplefvAMD;

	// GL_EXT_texture_sRGB_decode

	#define GL_TEXTURE_SRGB_DECODE_EXT 0x8A48
	#define GL_DECODE_EXT 0x8A49
	#define GL_SKIP_DECODE_EXT 0x8A4A

	// GL_NV_shader_buffer_load
	#define GL_BUFFER_GPU_ADDRESS_NV 0x8F1D
	#define GL_GPU_ADDRESS_NV 0x8F34
	#define GL_MAX_SHADER_BUFFER_ADDRESS_NV 0x8F35

	typedef void (APIENTRY * PFNGLGETBUFFERPARAMETERUI64VNVPROC) (GLenum target, GLenum pname, GLuint64EXT* params);
	typedef void (APIENTRY * PFNGLGETINTEGERUI64VNVPROC) (GLenum value, GLuint64EXT* result);
	typedef void (APIENTRY * PFNGLGETNAMEDBUFFERPARAMETERUI64VNVPROC) (GLuint buffer, GLenum pname, GLuint64EXT* params);
	typedef GLboolean (APIENTRY * PFNGLISBUFFERRESIDENTNVPROC) (GLenum target);
	typedef GLboolean (APIENTRY * PFNGLISNAMEDBUFFERRESIDENTNVPROC) (GLuint buffer);
	typedef void (APIENTRY * PFNGLMAKEBUFFERNONRESIDENTNVPROC) (GLenum target);
	typedef void (APIENTRY * PFNGLMAKEBUFFERRESIDENTNVPROC) (GLenum target, GLenum access);
	typedef void (APIENTRY * PFNGLMAKENAMEDBUFFERNONRESIDENTNVPROC) (GLuint buffer);
	typedef void (APIENTRY * PFNGLMAKENAMEDBUFFERRESIDENTNVPROC) (GLuint buffer, GLenum access);
	typedef void (APIENTRY * PFNGLPROGRAMUNIFORMUI64NVPROC) (GLuint program, GLint location, GLuint64EXT value);
	typedef void (APIENTRY * PFNGLPROGRAMUNIFORMUI64VNVPROC) (GLuint program, GLint location, GLsizei count, const GLuint64EXT* value);
	typedef void (APIENTRY * PFNGLUNIFORMUI64NVPROC) (GLint location, GLuint64EXT value);
	typedef void (APIENTRY * PFNGLUNIFORMUI64VNVPROC) (GLint location, GLsizei count, const GLuint64EXT* value);

	extern PFNGLGETBUFFERPARAMETERUI64VNVPROC glGetBufferParameterui64vNV;
	extern PFNGLGETINTEGERUI64VNVPROC glGetIntegerui64vNV;
	extern PFNGLGETNAMEDBUFFERPARAMETERUI64VNVPROC glGetNamedBufferParameterui64vNV;
	extern PFNGLISBUFFERRESIDENTNVPROC glIsBufferResidentNV;
	extern PFNGLISNAMEDBUFFERRESIDENTNVPROC glIsNamedBufferResidentNV;
	extern PFNGLMAKEBUFFERNONRESIDENTNVPROC glMakeBufferNonResidentNV;
	extern PFNGLMAKEBUFFERRESIDENTNVPROC glMakeBufferResidentNV;
	extern PFNGLMAKENAMEDBUFFERNONRESIDENTNVPROC glMakeNamedBufferNonResidentNV;
	extern PFNGLMAKENAMEDBUFFERRESIDENTNVPROC glMakeNamedBufferResidentNV;
	extern PFNGLPROGRAMUNIFORMUI64NVPROC glProgramUniformui64NV;
	extern PFNGLPROGRAMUNIFORMUI64VNVPROC glProgramUniformui64vNV;
	extern PFNGLUNIFORMUI64NVPROC glUniformui64NV;
	extern PFNGLUNIFORMUI64VNVPROC glUniformui64vNV;

	// GL_NV_vertex_buffer_unified_memory
	typedef void (APIENTRY * PFNGLBUFFERADDRESSRANGENVPROC) (GLenum pname, GLuint index, GLuint64EXT address, GLsizeiptr length);
	typedef void (APIENTRY * PFNGLVERTEXATTRIBFORMATNVPROC) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride);
	typedef void (APIENTRY * PFNGLVERTEXATTRIBIFORMATNVPROC) (GLuint index, GLint size, GLenum type, GLsizei stride);
	typedef void (APIENTRY * PFNGLGETINTEGERUI64I_VNVPROC) (GLenum value, GLuint index, GLuint64EXT result[]);

	#define GL_VERTEX_ATTRIB_ARRAY_UNIFIED_NV 0x8F1E
	#define GL_ELEMENT_ARRAY_UNIFIED_NV 0x8F1F
	#define GL_VERTEX_ATTRIB_ARRAY_ADDRESS_NV 0x8F20
	#define GL_ELEMENT_ARRAY_ADDRESS_NV 0x8F29
	#define GL_VERTEX_ATTRIB_ARRAY_LENGTH_NV 0x8F2A
	#define GL_ELEMENT_ARRAY_LENGTH_NV 0x8F33
	#define GL_DRAW_INDIRECT_UNIFIED_NV 0x8F40
	#define GL_DRAW_INDIRECT_ADDRESS_NV 0x8F41
	#define GL_DRAW_INDIRECT_LENGTH_NV 0x8F42

	extern PFNGLBUFFERADDRESSRANGENVPROC glBufferAddressRangeNV;
	extern PFNGLVERTEXATTRIBFORMATNVPROC glVertexAttribFormatNV;
	extern PFNGLVERTEXATTRIBIFORMATNVPROC glVertexAttribIFormatNV;
	extern PFNGLGETINTEGERUI64I_VNVPROC glGetIntegerui64i_vNV;

	// GL_AMD_depth_clamp_separate
	#define GL_DEPTH_CLAMP_NEAR_AMD 0x901E
	#define GL_DEPTH_CLAMP_FAR_AMD 0x901F

	// GL_NV_texture_multisample
	typedef void (APIENTRY * PFNGLTEXIMAGE2DMULTISAMPLECOVERAGENVPROC) (GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations);
	typedef void (APIENTRY * PFNGLTEXIMAGE3DMULTISAMPLECOVERAGENVPROC) (GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations);
	typedef void (APIENTRY * PFNGLTEXTUREIMAGE2DMULTISAMPLECOVERAGENVPROC) (GLuint texture, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations);
	typedef void (APIENTRY * PFNGLTEXTUREIMAGE2DMULTISAMPLENVPROC) (GLuint texture, GLenum target, GLsizei samples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations);
	typedef void (APIENTRY * PFNGLTEXTUREIMAGE3DMULTISAMPLECOVERAGENVPROC) (GLuint texture, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations);
	typedef void (APIENTRY * PFNGLTEXTUREIMAGE3DMULTISAMPLENVPROC) (GLuint texture, GLenum target, GLsizei samples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations);

	extern PFNGLTEXIMAGE2DMULTISAMPLECOVERAGENVPROC glTexImage2DMultisampleCoverageNV;
	extern PFNGLTEXIMAGE3DMULTISAMPLECOVERAGENVPROC glTexImage3DMultisampleCoverageNV;
	extern PFNGLTEXTUREIMAGE2DMULTISAMPLECOVERAGENVPROC glTextureImage2DMultisampleCoverageNV;
	extern PFNGLTEXTUREIMAGE2DMULTISAMPLENVPROC glTextureImage2DMultisampleNV;
	extern PFNGLTEXTUREIMAGE3DMULTISAMPLECOVERAGENVPROC glTextureImage3DMultisampleCoverageNV;
	extern PFNGLTEXTUREIMAGE3DMULTISAMPLENVPROC glTextureImage3DMultisampleNV;

	// GL_NV_bindless_texture
	typedef GLuint64 (APIENTRY * PFNGLGETIMAGEHANDLENVPROC) (GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format);
	typedef GLuint64 (APIENTRY * PFNGLGETTEXTUREHANDLENVPROC) (GLuint texture);
	typedef GLuint64 (APIENTRY * PFNGLGETTEXTURESAMPLERHANDLENVPROC) (GLuint texture, GLuint sampler);
	typedef GLboolean (APIENTRY * PFNGLISIMAGEHANDLERESIDENTNVPROC) (GLuint64 handle);
	typedef GLboolean (APIENTRY * PFNGLISTEXTUREHANDLERESIDENTNVPROC) (GLuint64 handle);
	typedef void (APIENTRY * PFNGLMAKEIMAGEHANDLENONRESIDENTNVPROC) (GLuint64 handle);
	typedef void (APIENTRY * PFNGLMAKEIMAGEHANDLERESIDENTNVPROC) (GLuint64 handle, GLenum access);
	typedef void (APIENTRY * PFNGLMAKETEXTUREHANDLENONRESIDENTNVPROC) (GLuint64 handle);
	typedef void (APIENTRY * PFNGLMAKETEXTUREHANDLERESIDENTNVPROC) (GLuint64 handle);
	typedef void (APIENTRY * PFNGLPROGRAMUNIFORMHANDLEUI64NVPROC) (GLuint program, GLint location, GLuint64 value);
	typedef void (APIENTRY * PFNGLPROGRAMUNIFORMHANDLEUI64VNVPROC) (GLuint program, GLint location, GLsizei count, const GLuint64* values);
	typedef void (APIENTRY * PFNGLUNIFORMHANDLEUI64NVPROC) (GLint location, GLuint64 value);
	typedef void (APIENTRY * PFNGLUNIFORMHANDLEUI64VNVPROC) (GLint location, GLsizei count, const GLuint64* value);

	extern PFNGLGETIMAGEHANDLENVPROC glGetImageHandleNV;
	extern PFNGLGETTEXTUREHANDLENVPROC glGetTextureHandleNV;
	extern PFNGLGETTEXTURESAMPLERHANDLENVPROC glGetTextureSamplerHandleNV;
	extern PFNGLISIMAGEHANDLERESIDENTNVPROC glIsImageHandleResidentNV;
	extern PFNGLISTEXTUREHANDLERESIDENTNVPROC glIsTextureHandleResidentNV;
	extern PFNGLMAKEIMAGEHANDLENONRESIDENTNVPROC glMakeImageHandleNonResidentNV;
	extern PFNGLMAKEIMAGEHANDLERESIDENTNVPROC glMakeImageHandleResidentNV;
	extern PFNGLMAKETEXTUREHANDLENONRESIDENTNVPROC glMakeTextureHandleNonResidentNV;
	extern PFNGLMAKETEXTUREHANDLERESIDENTNVPROC glMakeTextureHandleResidentNV;
	extern PFNGLPROGRAMUNIFORMHANDLEUI64NVPROC glProgramUniformHandleui64NV;
	extern PFNGLPROGRAMUNIFORMHANDLEUI64VNVPROC glProgramUniformHandleui64vNV;
	extern PFNGLUNIFORMHANDLEUI64NVPROC glUniformHandleui64NV;
	extern PFNGLUNIFORMHANDLEUI64VNVPROC glUniformHandleui64vNV;

	// GL_EXT_texture_filter_anisotropic
	#define GL_TEXTURE_MAX_ANISOTROPY_EXT 0x84FE
	#define GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT 0x84FF

	// GL_NV_explicit_multisample
	typedef void (APIENTRY * PFNGLGETMULTISAMPLEFVNVPROC) (GLenum pname, GLuint index, GLfloat* val);
	typedef void (APIENTRY * PFNGLSAMPLEMASKINDEXEDNVPROC) (GLuint index, GLbitfield mask);
	typedef void (APIENTRY * PFNGLTEXRENDERBUFFERNVPROC) (GLenum target, GLuint renderbuffer);

	extern PFNGLGETMULTISAMPLEFVNVPROC glGetMultisamplefvNV;
	extern PFNGLSAMPLEMASKINDEXEDNVPROC glSampleMaskIndexedNV;
	extern PFNGLTEXRENDERBUFFERNVPROC glTexRenderbufferNV;

	#define GL_SAMPLE_POSITION_NV								0x8E50
	#define GL_SAMPLE_MASK_NV									0x8E51
	#define GL_SAMPLE_MASK_VALUE_NV								0x8E52
	#define GL_TEXTURE_BINDING_RENDERBUFFER_NV					0x8E53
	#define GL_TEXTURE_RENDERBUFFER_DATA_STORE_BINDING_NV		0x8E54
	#define GL_MAX_SAMPLE_MASK_WORDS_NV							0x8E59
	#define GL_TEXTURE_RENDERBUFFER_NV							0x8E55
	#define GL_SAMPLER_RENDERBUFFER_NV							0x8E56
	#define GL_INT_SAMPLER_RENDERBUFFER_NV						0x8E57
	#define GL_UNSIGNED_INT_SAMPLER_RENDERBUFFER_NV				0x8E58

	// GL_AMD_blend_minmax_factor
	#define GL_FACTOR_MIN_AMD 0x901C
	#define GL_FACTOR_MAX_AMD 0x901D

	// GL_AMD_sparse_texture
	#define GL_TEXTURE_STORAGE_SPARSE_BIT_AMD 0x00000001

	#define GL_VIRTUAL_PAGE_SIZE_X_AMD 0x9195
	#define GL_VIRTUAL_PAGE_SIZE_Y_AMD 0x9196
	#define GL_VIRTUAL_PAGE_SIZE_Z_AMD 0x9197

	#define GL_MAX_SPARSE_TEXTURE_SIZE_AMD 0x9198
	#define GL_MAX_SPARSE_3D_TEXTURE_SIZE_AMD 0x9199
	#define GL_MAX_SPARSE_ARRAY_TEXTURE_LAYERS_AMD 0x919A

	#define GL_MIN_SPARSE_LEVEL_AMD 0x919B
	#define GL_MIN_LOD_WARNING_AMD 0x919C

	typedef void (APIENTRY * PFNGLTEXSTORAGESPARSEAMDPROC) (GLenum target, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLsizei layers, GLbitfield flags);
	typedef void (APIENTRY * PFNGLTEXTURESTORAGESPARSEAMDPROC) (GLuint texture, GLenum target, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLsizei layers, GLbitfield flags);
	
	extern PFNGLTEXSTORAGESPARSEAMDPROC glTexStorageSparseAMD;
	extern PFNGLTEXTURESTORAGESPARSEAMDPROC glTextureStorageSparseAMD;

	// GL_ARB_debug_output
	extern PFNGLDEBUGMESSAGECONTROLARBPROC glDebugMessageControlARB;
	extern PFNGLDEBUGMESSAGEINSERTARBPROC glDebugMessageInsertARB;
	extern PFNGLDEBUGMESSAGECALLBACKARBPROC glDebugMessageCallbackARB;
	extern PFNGLGETDEBUGMESSAGELOGARBPROC glGetDebugMessageLogARB;

	// WGL_EXT_swap_control
#ifdef WIN32
	typedef BOOL (WINAPI * PFNWGLSWAPINTERVALEXTPROC) (int interval);
	typedef int (WINAPI * PFNWGLGETSWAPINTERVALEXTPROC) (void);

	extern PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT;
	extern PFNWGLGETSWAPINTERVALEXTPROC wglGetSwapIntervalEXT;
#endif

#ifndef GL_EXTERNAL_VIRTUAL_MEMORY_BUFFER_AMD
#define GL_EXTERNAL_VIRTUAL_MEMORY_BUFFER_AMD 0x9160
#endif

#ifndef WGL_CONTEXT_CORE_PROFILE_BIT_ARB
#define WGL_CONTEXT_CORE_PROFILE_BIT_ARB 0x00000001
#endif

#ifndef WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB
#define WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB 0x00000002
#endif

#ifndef WGL_CONTEXT_ES2_PROFILE_BIT_EXT
#define WGL_CONTEXT_ES2_PROFILE_BIT_EXT 0x00000004
#endif

#ifndef GLX_CONTEXT_CORE_PROFILE_BIT_ARB
#define GLX_CONTEXT_CORE_PROFILE_BIT_ARB 0x00000001
#endif

#ifndef GLX_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB
#define GLX_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB 0x00000002
#endif

#ifndef WGL_CONTEXT_ES2_PROFILE_BIT_EXT
#define WGL_CONTEXT_ES2_PROFILE_BIT_EXT 0x00000004
#endif

#endif//WIN32

#define GLO_BUFFER_OFFSET(i) ((char *)NULL + (i))
#define GLF_BUFFER_OFFSET(i) ((char *)NULL + (i))

namespace gl
{
	inline void init()
	{
#if (defined(WIN32))
		// OpenGL 1.0
		// glEnable = (PFNGLENABLEPROC)gloGetProcAddress("glEnable");
		// glViewport = (PFNGLVIEWPORTPROC)gloGetProcAddress("glViewport");
		
		// OpenGL 1.1
		// glGetIntegerv = (PFNGLGETINTEGERVPROC)gloGetProcAddress("glGetIntegerv");
		// glGetError = (PFNGLGETERRORPROC)gloGetProcAddress("glGetError");

		// OpenGL 1.2
		glBlendColor = (PFNGLBLENDCOLORPROC)gloGetProcAddress("glBlendColor");
		glBlendEquation = (PFNGLBLENDEQUATIONPROC)gloGetProcAddress("glBlendEquation");
		glDrawRangeElements = (PFNGLDRAWRANGEELEMENTSPROC)gloGetProcAddress("glDrawRangeElements");
		glTexImage3D = (PFNGLTEXIMAGE3DPROC)gloGetProcAddress("glTexImage3D");
		glTexSubImage3D = (PFNGLTEXSUBIMAGE3DPROC)gloGetProcAddress("glTexSubImage3D");
		glCopyTexSubImage3D = (PFNGLCOPYTEXSUBIMAGE3DPROC)gloGetProcAddress("glCopyTexSubImage3D");

		// OpenGL 1.3
		glActiveTexture = (PFNGLACTIVETEXTUREPROC)gloGetProcAddress("glActiveTexture");
		glSampleCoverage = (PFNGLSAMPLECOVERAGEPROC)gloGetProcAddress("glSampleCoverage");
		glCompressedTexImage3D = (PFNGLCOMPRESSEDTEXIMAGE3DPROC)gloGetProcAddress("glCompressedTexImage3D");
		glCompressedTexImage2D = (PFNGLCOMPRESSEDTEXIMAGE2DPROC)gloGetProcAddress("glCompressedTexImage2D");
		glCompressedTexImage1D = (PFNGLCOMPRESSEDTEXIMAGE1DPROC)gloGetProcAddress("glCompressedTexImage1D");
		glCompressedTexSubImage3D = (PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)gloGetProcAddress("glCompressedTexSubImage3D");
		glCompressedTexSubImage2D = (PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)gloGetProcAddress("glCompressedTexSubImage2D");
		glCompressedTexSubImage1D = (PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC)gloGetProcAddress("glCompressedTexSubImage1D");
		glGetCompressedTexImage = (PFNGLGETCOMPRESSEDTEXIMAGEPROC)gloGetProcAddress("glGetCompressedTexImage");

		// OpenGL 1.4
		glBlendFuncSeparate = (PFNGLBLENDFUNCSEPARATEPROC)gloGetProcAddress("glBlendFuncSeparate");
		glPointParameterf = (PFNGLPOINTPARAMETERFPROC)gloGetProcAddress("glPointParameterf");
		glPointParameterfv = (PFNGLPOINTPARAMETERFVPROC)gloGetProcAddress("glPointParameterfv");
		glPointParameteri = (PFNGLPOINTPARAMETERIPROC)gloGetProcAddress("glPointParameteri");
		glPointParameteriv = (PFNGLPOINTPARAMETERIVPROC)gloGetProcAddress("glPointParameteriv");

		// OpenGL 1.5
		glGenQueries = (PFNGLGENQUERIESPROC)gloGetProcAddress("glGenQueries");
		glDeleteQueries = (PFNGLDELETEQUERIESPROC)gloGetProcAddress("glDeleteQueries");
		glIsQuery = (PFNGLISQUERYPROC)gloGetProcAddress("glIsQuery");
		glBeginQuery = (PFNGLBEGINQUERYPROC)gloGetProcAddress("glBeginQuery");
		glEndQuery = (PFNGLENDQUERYPROC)gloGetProcAddress("glEndQuery");
		glGetQueryiv = (PFNGLGETQUERYIVPROC)gloGetProcAddress("glGetQueryiv");
		glGetQueryObjectiv = (PFNGLGETQUERYOBJECTIVPROC)gloGetProcAddress("glGetQueryObjectiv");
		glGetQueryObjectuiv = (PFNGLGETQUERYOBJECTUIVPROC)gloGetProcAddress("glGetQueryObjectuiv");

		// GL_ARB_vertex_buffer_object
		glBindBuffer = (PFNGLBINDBUFFERPROC)gloGetProcAddress("glBindBuffer");
		glDeleteBuffers = (PFNGLDELETEBUFFERSPROC)gloGetProcAddress("glDeleteBuffers");
		glGenBuffers = (PFNGLGENBUFFERSPROC)gloGetProcAddress("glGenBuffers");
		glIsBuffer = (PFNGLISBUFFERPROC)gloGetProcAddress("glIsBuffer");
		glBufferData = (PFNGLBUFFERDATAPROC)gloGetProcAddress("glBufferData");
		glBufferSubData = (PFNGLBUFFERSUBDATAPROC)gloGetProcAddress("glBufferSubData");
		glGetBufferSubData = (PFNGLGETBUFFERSUBDATAPROC)gloGetProcAddress("glGetBufferSubData");
		glUnmapBuffer = (PFNGLUNMAPBUFFERPROC)gloGetProcAddress("glUnmapBuffer");
		glGetBufferParameteriv = (PFNGLGETBUFFERPARAMETERIVPROC)gloGetProcAddress("glGetBufferParameteriv");
		glGetBufferPointerv = (PFNGLGETBUFFERPOINTERVPROC)gloGetProcAddress("glGetBufferPointerv");

		// OpenGL 2.0
		glBlendEquationSeparate = (PFNGLBLENDEQUATIONSEPARATEPROC)gloGetProcAddress("glBlendEquationSeparate");
		glDrawBuffers = (PFNGLDRAWBUFFERSPROC)gloGetProcAddress("glDrawBuffers");
		glStencilOpSeparate = (PFNGLSTENCILOPSEPARATEPROC)gloGetProcAddress("glStencilOpSeparate");
		glStencilFuncSeparate = (PFNGLSTENCILFUNCSEPARATEPROC)gloGetProcAddress("glStencilFuncSeparate");
		glStencilMaskSeparate = (PFNGLSTENCILMASKSEPARATEPROC)gloGetProcAddress("glStencilMaskSeparate");

		glCreateProgram = (PFNGLCREATEPROGRAMPROC)gloGetProcAddress("glCreateProgram");
		glCreateShader = (PFNGLCREATESHADERPROC)gloGetProcAddress("glCreateShader");
		glDeleteProgram = (PFNGLDELETEPROGRAMPROC)gloGetProcAddress("glDeleteProgram");
		glDeleteShader = (PFNGLDELETESHADERPROC)gloGetProcAddress("glDeleteShader");
		glShaderSource = (PFNGLSHADERSOURCEPROC)gloGetProcAddress("glShaderSource");
		glCompileShader = (PFNGLCOMPILESHADERPROC)gloGetProcAddress("glCompileShader");
		glGetShaderiv = (PFNGLGETSHADERIVPROC)gloGetProcAddress("glGetShaderiv");
		glValidateProgram = (PFNGLVALIDATEPROGRAMPROC)gloGetProcAddress("glValidateProgram");
		glGetProgramiv = (PFNGLGETPROGRAMIVPROC)gloGetProcAddress("glGetProgramiv");
		glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC)gloGetProcAddress("glGetProgramInfoLog");
		glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)gloGetProcAddress("glGetShaderInfoLog");
		glAttachShader = (PFNGLATTACHSHADERPROC)gloGetProcAddress("glAttachShader");
		glLinkProgram = (PFNGLLINKPROGRAMPROC)gloGetProcAddress("glLinkProgram");
		glUseProgram = (PFNGLUSEPROGRAMPROC)gloGetProcAddress("glUseProgram");
		glGetVertexAttribdv = (PFNGLGETVERTEXATTRIBDVPROC)gloGetProcAddress("glGetVertexAttribdv");
		glGetVertexAttribfv = (PFNGLGETVERTEXATTRIBFVPROC)gloGetProcAddress("glGetVertexAttribfv");
		glGetVertexAttribiv = (PFNGLGETVERTEXATTRIBIVPROC)gloGetProcAddress("glGetVertexAttribiv");
		glGetVertexAttribPointerv = (PFNGLGETVERTEXATTRIBPOINTERVPROC)gloGetProcAddress("glGetVertexAttribPointerv");
		glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)gloGetProcAddress("glVertexAttribPointer");
		glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)gloGetProcAddress("glEnableVertexAttribArray");
		glDisableVertexAttribArray = (PFNGLDISABLEVERTEXATTRIBARRAYPROC)gloGetProcAddress("glDisableVertexAttribArray");
		glBindAttribLocation = (PFNGLBINDATTRIBLOCATIONPROC)gloGetProcAddress("glBindAttribLocation");
		glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)gloGetProcAddress("glGetUniformLocation");
		glGetAttribLocation = (PFNGLGETATTRIBLOCATIONPROC)gloGetProcAddress("glGetAttribLocation");
		glUniform1f = (PFNGLUNIFORM1FPROC)gloGetProcAddress("glUniform1f");
		glUniform2f = (PFNGLUNIFORM2FPROC)gloGetProcAddress("glUniform2f");
		glUniform3f = (PFNGLUNIFORM3FPROC)gloGetProcAddress("glUniform3f");
		glUniform4f = (PFNGLUNIFORM4FPROC)gloGetProcAddress("glUniform4f");
		glUniform1i = (PFNGLUNIFORM1IPROC)gloGetProcAddress("glUniform1i");
		glUniform2i = (PFNGLUNIFORM2IPROC)gloGetProcAddress("glUniform2i");
		glUniform3i = (PFNGLUNIFORM3IPROC)gloGetProcAddress("glUniform3i");
		glUniform4i = (PFNGLUNIFORM4IPROC)gloGetProcAddress("glUniform4i");
		glUniform1fv = (PFNGLUNIFORM1FVPROC)gloGetProcAddress("glUniform1fv");
		glUniform2fv = (PFNGLUNIFORM2FVPROC)gloGetProcAddress("glUniform2fv");
		glUniform3fv = (PFNGLUNIFORM3FVPROC)gloGetProcAddress("glUniform3fv");
		glUniform4fv = (PFNGLUNIFORM4FVPROC)gloGetProcAddress("glUniform4fv");
		glUniform1iv = (PFNGLUNIFORM1IVPROC)gloGetProcAddress("glUniform1iv");
		glUniform2iv = (PFNGLUNIFORM2IVPROC)gloGetProcAddress("glUniform2iv");
		glUniform3iv = (PFNGLUNIFORM3IVPROC)gloGetProcAddress("glUniform3iv");
		glUniform4iv = (PFNGLUNIFORM4IVPROC)gloGetProcAddress("glUniform4iv");
		glUniformMatrix2fv = (PFNGLUNIFORMMATRIX2FVPROC)gloGetProcAddress("glUniformMatrix2fv");
		glUniformMatrix3fv = (PFNGLUNIFORMMATRIX3FVPROC)gloGetProcAddress("glUniformMatrix3fv");
		glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC)gloGetProcAddress("glUniformMatrix4fv");
		glGetActiveAttrib = (PFNGLGETACTIVEATTRIBPROC)gloGetProcAddress("glGetActiveAttrib");
		glGetActiveUniform = (PFNGLGETACTIVEUNIFORMPROC)gloGetProcAddress("glGetActiveUniform");

		glVertexAttrib1d = (PFNGLVERTEXATTRIB1DPROC)gloGetProcAddress("glVertexAttrib1d");
		glVertexAttrib1dv = (PFNGLVERTEXATTRIB1DVPROC)gloGetProcAddress("glVertexAttrib1dv");
		glVertexAttrib1f = (PFNGLVERTEXATTRIB1FPROC)gloGetProcAddress("glVertexAttrib1f");
		glVertexAttrib1fv = (PFNGLVERTEXATTRIB1FVPROC)gloGetProcAddress("glVertexAttrib1fv");
		glVertexAttrib1s = (PFNGLVERTEXATTRIB1SPROC)gloGetProcAddress("glVertexAttrib1s");
		glVertexAttrib1sv = (PFNGLVERTEXATTRIB1SVPROC)gloGetProcAddress("glVertexAttrib1sv");
		glVertexAttrib2d = (PFNGLVERTEXATTRIB2DPROC)gloGetProcAddress("glVertexAttrib2d");
		glVertexAttrib2dv = (PFNGLVERTEXATTRIB2DVPROC)gloGetProcAddress("glVertexAttrib2dv");
		glVertexAttrib2f = (PFNGLVERTEXATTRIB2FPROC)gloGetProcAddress("glVertexAttrib2f");
		glVertexAttrib2fv = (PFNGLVERTEXATTRIB2FVPROC)gloGetProcAddress("glVertexAttrib2fv");
		glVertexAttrib2s = (PFNGLVERTEXATTRIB2SPROC)gloGetProcAddress("glVertexAttrib2s");
		glVertexAttrib2sv = (PFNGLVERTEXATTRIB2SVPROC)gloGetProcAddress("glVertexAttrib2sv");
		glVertexAttrib3d = (PFNGLVERTEXATTRIB3DPROC)gloGetProcAddress("glVertexAttrib3d");
		glVertexAttrib3dv = (PFNGLVERTEXATTRIB3DVPROC)gloGetProcAddress("glVertexAttrib3dv");
		glVertexAttrib3f = (PFNGLVERTEXATTRIB3FPROC)gloGetProcAddress("glVertexAttrib3f");
		glVertexAttrib3fv = (PFNGLVERTEXATTRIB3FVPROC)gloGetProcAddress("glVertexAttrib3fv");
		glVertexAttrib3s = (PFNGLVERTEXATTRIB3SPROC)gloGetProcAddress("glVertexAttrib3s");
		glVertexAttrib3sv = (PFNGLVERTEXATTRIB3SVPROC)gloGetProcAddress("glVertexAttrib3sv");
		glVertexAttrib4d = (PFNGLVERTEXATTRIB4DPROC)gloGetProcAddress("glVertexAttrib4d");
		glVertexAttrib4dv = (PFNGLVERTEXATTRIB4DVPROC)gloGetProcAddress("glVertexAttrib4dv");
		glVertexAttrib4f = (PFNGLVERTEXATTRIB4FPROC)gloGetProcAddress("glVertexAttrib4f");
		glVertexAttrib4fv = (PFNGLVERTEXATTRIB4FVPROC)gloGetProcAddress("glVertexAttrib4fv");
		glVertexAttrib4s = (PFNGLVERTEXATTRIB4SPROC)gloGetProcAddress("glVertexAttrib4s");
		glVertexAttrib4sv = (PFNGLVERTEXATTRIB4SVPROC)gloGetProcAddress("glVertexAttrib4sv");
		glVertexAttrib4Nbv = (PFNGLVERTEXATTRIB4NBVPROC)gloGetProcAddress("glVertexAttrib4Nbv");
		glVertexAttrib4Niv = (PFNGLVERTEXATTRIB4NIVPROC)gloGetProcAddress("glVertexAttrib4Niv");
		glVertexAttrib4Nsv = (PFNGLVERTEXATTRIB4NSVPROC)gloGetProcAddress("glVertexAttrib4Nsv");
		glVertexAttrib4Nub = (PFNGLVERTEXATTRIB4NUBPROC)gloGetProcAddress("glVertexAttrib4Nub");
		glVertexAttrib4Nubv = (PFNGLVERTEXATTRIB4NUBVPROC)gloGetProcAddress("glVertexAttrib4Nubv");
		glVertexAttrib4Nuiv = (PFNGLVERTEXATTRIB4NUIVPROC)gloGetProcAddress("glVertexAttrib4Nuiv");
		glVertexAttrib4Nusv = (PFNGLVERTEXATTRIB4NUSVPROC)gloGetProcAddress("glVertexAttrib4Nusv");
		glVertexAttrib4bv = (PFNGLVERTEXATTRIB4BVPROC)gloGetProcAddress("glVertexAttrib4bv");
		glVertexAttrib4iv = (PFNGLVERTEXATTRIB4IVPROC)gloGetProcAddress("glVertexAttrib4iv");
		glVertexAttrib4ubv = (PFNGLVERTEXATTRIB4UBVPROC)gloGetProcAddress("glVertexAttrib4ubv");
		glVertexAttrib4uiv = (PFNGLVERTEXATTRIB4UIVPROC)gloGetProcAddress("glVertexAttrib4uiv");
		glVertexAttrib4usv = (PFNGLVERTEXATTRIB4USVPROC)gloGetProcAddress("glVertexAttrib4usv");

		// OpenGL 3.0
		glColorMaski = (PFNGLCOLORMASKIPROC)gloGetProcAddress("glColorMaski");
		glGetBooleani_v = (PFNGLGETBOOLEANI_VPROC)gloGetProcAddress("glGetBooleani_v");
		glGetIntegeri_v = (PFNGLGETINTEGERI_VPROC)gloGetProcAddress("glGetIntegeri_v");
		glEnablei = (PFNGLENABLEIPROC)gloGetProcAddress("glEnablei");
		glDisablei = (PFNGLDISABLEIPROC)gloGetProcAddress("glDisablei");
		glIsEnabledi = (PFNGLISENABLEDIPROC)gloGetProcAddress("glIsEnabledi");
		glBeginTransformFeedback = (PFNGLBEGINTRANSFORMFEEDBACKPROC)gloGetProcAddress("glBeginTransformFeedback");
		glEndTransformFeedback = (PFNGLENDTRANSFORMFEEDBACKPROC)gloGetProcAddress("glEndTransformFeedback");
		glBindBufferRange = (PFNGLBINDBUFFERRANGEPROC)gloGetProcAddress("glBindBufferRange");
		glBindBufferBase = (PFNGLBINDBUFFERBASEPROC)gloGetProcAddress("glBindBufferBase");
		glTransformFeedbackVaryings = (PFNGLTRANSFORMFEEDBACKVARYINGSPROC)gloGetProcAddress("glTransformFeedbackVaryings");
		glGetTransformFeedbackVarying = (PFNGLGETTRANSFORMFEEDBACKVARYINGPROC)gloGetProcAddress("glGetTransformFeedbackVarying");
		glClampColor = (PFNGLCLAMPCOLORPROC)gloGetProcAddress("glClampColor");
		glBeginConditionalRender = (PFNGLBEGINCONDITIONALRENDERPROC)gloGetProcAddress("glBeginConditionalRender");
		glEndConditionalRender = (PFNGLENDCONDITIONALRENDERPROC)gloGetProcAddress("glEndConditionalRender");
		glVertexAttribIPointer = (PFNGLVERTEXATTRIBIPOINTERPROC)gloGetProcAddress("glVertexAttribIPointer");
		glGetVertexAttribIiv = (PFNGLGETVERTEXATTRIBIIVPROC)gloGetProcAddress("glGetVertexAttribIiv");
		glGetVertexAttribIuiv = (PFNGLGETVERTEXATTRIBIUIVPROC)gloGetProcAddress("glGetVertexAttribIuiv");
		glVertexAttribI1i = (PFNGLVERTEXATTRIBI1IPROC)gloGetProcAddress("glVertexAttribI1i");
		glVertexAttribI2i = (PFNGLVERTEXATTRIBI2IPROC)gloGetProcAddress("glVertexAttribI2i");
		glVertexAttribI3i = (PFNGLVERTEXATTRIBI3IPROC)gloGetProcAddress("glVertexAttribI3i");
		glVertexAttribI4i = (PFNGLVERTEXATTRIBI4IPROC)gloGetProcAddress("glVertexAttribI4i");
		glVertexAttribI1ui = (PFNGLVERTEXATTRIBI1UIPROC)gloGetProcAddress("glVertexAttribI1ui");
		glVertexAttribI2ui = (PFNGLVERTEXATTRIBI2UIPROC)gloGetProcAddress("glVertexAttribI2ui");
		glVertexAttribI3ui = (PFNGLVERTEXATTRIBI3UIPROC)gloGetProcAddress("glVertexAttribI3ui");
		glVertexAttribI4ui = (PFNGLVERTEXATTRIBI4UIPROC)gloGetProcAddress("glVertexAttribI4ui");
		glVertexAttribI1iv = (PFNGLVERTEXATTRIBI1IVPROC)gloGetProcAddress("glVertexAttribI1iv");
		glVertexAttribI2iv = (PFNGLVERTEXATTRIBI2IVPROC)gloGetProcAddress("glVertexAttribI2iv");
		glVertexAttribI3iv = (PFNGLVERTEXATTRIBI3IVPROC)gloGetProcAddress("glVertexAttribI3iv");
		glVertexAttribI4iv = (PFNGLVERTEXATTRIBI4IVPROC)gloGetProcAddress("glVertexAttribI4iv");
		glVertexAttribI1uiv = (PFNGLVERTEXATTRIBI1UIVPROC)gloGetProcAddress("glVertexAttribI1uiv");
		glVertexAttribI2uiv = (PFNGLVERTEXATTRIBI2UIVPROC)gloGetProcAddress("glVertexAttribI2uiv");
		glVertexAttribI3uiv = (PFNGLVERTEXATTRIBI3UIVPROC)gloGetProcAddress("glVertexAttribI3uiv");
		glVertexAttribI4uiv = (PFNGLVERTEXATTRIBI4UIVPROC)gloGetProcAddress("glVertexAttribI4uiv");
		glVertexAttribI4bv = (PFNGLVERTEXATTRIBI4BVPROC)gloGetProcAddress("glVertexAttribI4bv");
		glVertexAttribI4sv = (PFNGLVERTEXATTRIBI4SVPROC)gloGetProcAddress("glVertexAttribI4sv");
		glVertexAttribI4ubv = (PFNGLVERTEXATTRIBI4UBVPROC)gloGetProcAddress("glVertexAttribI4ubv");
		glVertexAttribI4usv = (PFNGLVERTEXATTRIBI4USVPROC)gloGetProcAddress("glVertexAttribI4usv");
		glGetUniformuiv = (PFNGLGETUNIFORMUIVPROC)gloGetProcAddress("glGetUniformuiv");
		glBindFragDataLocation = (PFNGLBINDFRAGDATALOCATIONPROC)gloGetProcAddress("glBindFragDataLocation");
		glGetFragDataLocation = (PFNGLGETFRAGDATALOCATIONPROC)gloGetProcAddress("glGetFragDataLocation");
		glUniform1ui = (PFNGLUNIFORM1UIPROC)gloGetProcAddress("glUniform1ui");
		glUniform2ui = (PFNGLUNIFORM2UIPROC)gloGetProcAddress("glUniform2ui");
		glUniform3ui = (PFNGLUNIFORM3UIPROC)gloGetProcAddress("glUniform3ui");
		glUniform4ui = (PFNGLUNIFORM4UIPROC)gloGetProcAddress("glUniform4ui");
		glUniform1uiv = (PFNGLUNIFORM1UIVPROC)gloGetProcAddress("glUniform1uiv");
		glUniform2uiv = (PFNGLUNIFORM2UIVPROC)gloGetProcAddress("glUniform2uiv");
		glUniform3uiv = (PFNGLUNIFORM3UIVPROC)gloGetProcAddress("glUniform3uiv");
		glUniform4uiv = (PFNGLUNIFORM4UIVPROC)gloGetProcAddress("glUniform4uiv");
		glTexParameterIiv = (PFNGLTEXPARAMETERIIVPROC)gloGetProcAddress("glTexParameterIiv");
		glTexParameterIuiv = (PFNGLTEXPARAMETERIUIVPROC)gloGetProcAddress("glTexParameterIuiv");
		glGetTexParameterIiv = (PFNGLGETTEXPARAMETERIIVPROC)gloGetProcAddress("glGetTexParameterIiv");
		glGetTexParameterIuiv = (PFNGLGETTEXPARAMETERIUIVPROC)gloGetProcAddress("glGetTexParameterIuiv");
		glClearBufferiv = (PFNGLCLEARBUFFERIVPROC)gloGetProcAddress("glClearBufferiv");
		glClearBufferuiv = (PFNGLCLEARBUFFERUIVPROC)gloGetProcAddress("glClearBufferuiv");
		glClearBufferfv = (PFNGLCLEARBUFFERFVPROC)gloGetProcAddress("glClearBufferfv");
		glClearBufferfi = (PFNGLCLEARBUFFERFIPROC)gloGetProcAddress("glClearBufferfi");
		glGetStringi = (PFNGLGETSTRINGIPROC)gloGetProcAddress("glGetStringi");

		// GL_ARB_framebuffer_object
		glIsRenderbuffer = (PFNGLISRENDERBUFFERPROC)gloGetProcAddress("glIsRenderbuffer");
		glBindRenderbuffer = (PFNGLBINDRENDERBUFFERPROC)gloGetProcAddress("glBindRenderbuffer");
		glDeleteRenderbuffers = (PFNGLDELETERENDERBUFFERSPROC)gloGetProcAddress("glDeleteRenderbuffers");
		glGenRenderbuffers = (PFNGLGENRENDERBUFFERSPROC)gloGetProcAddress("glGenRenderbuffers");
		glRenderbufferStorage = (PFNGLRENDERBUFFERSTORAGEPROC)gloGetProcAddress("glRenderbufferStorage");
		glGetRenderbufferParameteriv = (PFNGLGETRENDERBUFFERPARAMETERIVPROC)gloGetProcAddress("glGetRenderbufferParameteriv");
		glIsFramebuffer = (PFNGLISFRAMEBUFFERPROC)gloGetProcAddress("glIsFramebuffer");
		glBindFramebuffer = (PFNGLBINDFRAMEBUFFERPROC)gloGetProcAddress("glBindFramebuffer");
		glDeleteFramebuffers = (PFNGLDELETEFRAMEBUFFERSPROC)gloGetProcAddress("glDeleteFramebuffers");
		glGenFramebuffers = (PFNGLGENFRAMEBUFFERSPROC)gloGetProcAddress("glGenFramebuffers");
		glCheckFramebufferStatus = (PFNGLCHECKFRAMEBUFFERSTATUSPROC)gloGetProcAddress("glCheckFramebufferStatus");
		glFramebufferTexture1D = (PFNGLFRAMEBUFFERTEXTURE1DPROC)gloGetProcAddress("glFramebufferTexture1D");
		glFramebufferTexture2D = (PFNGLFRAMEBUFFERTEXTURE2DPROC)gloGetProcAddress("glFramebufferTexture2D");
		glFramebufferTexture3D = (PFNGLFRAMEBUFFERTEXTURE3DPROC)gloGetProcAddress("glFramebufferTexture3D");
		glFramebufferRenderbuffer = (PFNGLFRAMEBUFFERRENDERBUFFERPROC)gloGetProcAddress("glFramebufferRenderbuffer");
		glGetFramebufferAttachmentParameteriv = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)gloGetProcAddress("glGetFramebufferAttachmentParameteriv");
		glGenerateMipmap = (PFNGLGENERATEMIPMAPPROC)gloGetProcAddress("glGenerateMipmap");
		glBlitFramebuffer = (PFNGLBLITFRAMEBUFFERPROC)gloGetProcAddress("glBlitFramebuffer");
		glRenderbufferStorageMultisample = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)gloGetProcAddress("glRenderbufferStorageMultisample");
		glFramebufferTextureLayer = (PFNGLFRAMEBUFFERTEXTURELAYERPROC)gloGetProcAddress("glFramebufferTextureLayer");

		// GL_ARB_provoking_vertex
		glProvokingVertex = (PFNGLPROVOKINGVERTEXPROC)gloGetProcAddress("glProvokingVertex");

		// GL_ARB_vertex_array_object
		glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)gloGetProcAddress("glBindVertexArray");
		glDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYSPROC)gloGetProcAddress("glDeleteVertexArrays");
		glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)gloGetProcAddress("glGenVertexArrays");
		glIsVertexArray = (PFNGLISVERTEXARRAYPROC)gloGetProcAddress("glIsVertexArray");

		// OpenGL 3.1
		glDrawArraysInstanced = (PFNGLDRAWARRAYSINSTANCEDPROC)gloGetProcAddress("glDrawArraysInstanced");
		glDrawElementsInstanced = (PFNGLDRAWELEMENTSINSTANCEDPROC)gloGetProcAddress("glDrawElementsInstanced");
		glTexBuffer = (PFNGLTEXBUFFERPROC)gloGetProcAddress("glTexBuffer");
		glPrimitiveRestartIndex = (PFNGLPRIMITIVERESTARTINDEXPROC)gloGetProcAddress("glPrimitiveRestartIndex");

		// GL_ARB_copy_buffer
		glCopyBufferSubData = (PFNGLCOPYBUFFERSUBDATAPROC)gloGetProcAddress("glCopyBufferSubData");

		// OpenGL 3.2
		glGetStringi = (PFNGLGETSTRINGIPROC)gloGetProcAddress("glGetStringi");
		glBindFragDataLocation = (PFNGLBINDFRAGDATALOCATIONPROC)gloGetProcAddress("glBindFragDataLocation");
		glGetInteger64i_v = (PFNGLGETINTEGER64I_VPROC)gloGetProcAddress("glGetInteger64i_v");
		glGetBufferParameteri64v = (PFNGLGETBUFFERPARAMETERI64VPROC)gloGetProcAddress("glGetBufferParameteri64v");
		glFramebufferTexture = (PFNGLFRAMEBUFFERTEXTUREPROC)gloGetProcAddress("glFramebufferTexture");

		// GL_ARB_map_buffer_range
		glMapBufferRange = (PFNGLMAPBUFFERRANGEPROC)gloGetProcAddress("glMapBufferRange");
		glFlushMappedBufferRange = (PFNGLFLUSHMAPPEDBUFFERRANGEPROC)gloGetProcAddress("glFlushMappedBufferRange");

		// GL_ARB_draw_elements_base_vertex
		glDrawElementsBaseVertex = (PFNGLDRAWELEMENTSBASEVERTEXPROC)gloGetProcAddress("glDrawElementsBaseVertex");
		glDrawRangeElementsBaseVertex = (PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC)gloGetProcAddress("glDrawRangeElementsBaseVertex");
		glDrawElementsInstancedBaseVertex = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)gloGetProcAddress("glDrawElementsInstancedBaseVertex");
		glMultiDrawElementsBaseVertex = (PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC)gloGetProcAddress("glMultiDrawElementsBaseVertex");

		// GL_ARB_uniform_buffer_object
		glGetUniformIndices = (PFNGLGETUNIFORMINDICESPROC)gloGetProcAddress("glGetUniformIndices");
		glGetActiveUniformsiv = (PFNGLGETACTIVEUNIFORMSIVPROC)gloGetProcAddress("glGetActiveUniformsiv");
		glGetActiveUniformName = (PFNGLGETACTIVEUNIFORMNAMEPROC)gloGetProcAddress("glGetActiveUniformName");
		glGetUniformBlockIndex = (PFNGLGETUNIFORMBLOCKINDEXPROC)gloGetProcAddress("glGetUniformBlockIndex");
		glGetActiveUniformBlockiv = (PFNGLGETACTIVEUNIFORMBLOCKIVPROC)gloGetProcAddress("glGetActiveUniformBlockiv");
		glGetActiveUniformBlockName = (PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)gloGetProcAddress("glGetActiveUniformBlockName");
		glUniformBlockBinding = (PFNGLUNIFORMBLOCKBINDINGPROC)gloGetProcAddress("glUniformBlockBinding");

		// GL_ARB_texture_multisample
		glTexImage2DMultisample = (PFNGLTEXIMAGE2DMULTISAMPLEPROC)gloGetProcAddress("glTexImage2DMultisample");
		glTexImage3DMultisample = (PFNGLTEXIMAGE3DMULTISAMPLEPROC)gloGetProcAddress("glTexImage3DMultisample");
		glGetMultisamplefv = (PFNGLGETMULTISAMPLEFVPROC)gloGetProcAddress("glGetMultisamplefv");
		glSampleMaski = (PFNGLSAMPLEMASKIPROC)gloGetProcAddress("glSampleMaski");

		// GL_ARB_sync
		glFenceSync = (PFNGLFENCESYNCPROC)gloGetProcAddress("glFenceSync");
		glIsSync = (PFNGLISSYNCPROC)gloGetProcAddress("glIsSync");
		glDeleteSync = (PFNGLDELETESYNCPROC)gloGetProcAddress("glDeleteSync");
		glClientWaitSync = (PFNGLCLIENTWAITSYNCPROC)gloGetProcAddress("glClientWaitSync");
		glWaitSync = (PFNGLWAITSYNCPROC)gloGetProcAddress("glWaitSync");
		glGetInteger64v = (PFNGLGETINTEGER64VPROC)gloGetProcAddress("glGetInteger64v");
		glGetSynciv = (PFNGLGETSYNCIVPROC)gloGetProcAddress("glGetSynciv");

		// OpenGL 3.3
		glVertexAttribDivisor = (PFNGLVERTEXATTRIBDIVISORPROC)gloGetProcAddress("glVertexAttribDivisor");

		// GL_ARB_sampler_objects
		glGenSamplers = (PFNGLGENSAMPLERSPROC)gloGetProcAddress("glGenSamplers");
		glDeleteSamplers = (PFNGLDELETESAMPLERSPROC)gloGetProcAddress("glDeleteSamplers");
		glIsSampler = (PFNGLISSAMPLERPROC)gloGetProcAddress("glIsSampler");
		glBindSampler = (PFNGLBINDSAMPLERPROC)gloGetProcAddress("glBindSampler");
		glSamplerParameteri = (PFNGLSAMPLERPARAMETERIPROC)gloGetProcAddress("glSamplerParameteri");
		glSamplerParameteriv = (PFNGLSAMPLERPARAMETERIVPROC)gloGetProcAddress("glSamplerParameteriv");
		glSamplerParameterf = (PFNGLSAMPLERPARAMETERFPROC)gloGetProcAddress("glSamplerParameterf");
		glSamplerParameterfv = (PFNGLSAMPLERPARAMETERFVPROC)gloGetProcAddress("glSamplerParameterfv");
		glSamplerParameterIiv = (PFNGLSAMPLERPARAMETERIIVPROC)gloGetProcAddress("glSamplerParameterIiv");
		glSamplerParameterIuiv = (PFNGLSAMPLERPARAMETERIUIVPROC)gloGetProcAddress("glSamplerParameterIuiv");
		glGetSamplerParameteriv = (PFNGLGETSAMPLERPARAMETERIVPROC)gloGetProcAddress("glGetSamplerParameteriv");
		glGetSamplerParameterIiv = (PFNGLGETSAMPLERPARAMETERIIVPROC)gloGetProcAddress("glGetSamplerParameterIiv");
		glGetSamplerParameterfv = (PFNGLGETSAMPLERPARAMETERFVPROC)gloGetProcAddress("glGetSamplerParameterfv");
		glGetSamplerParameterIuiv = (PFNGLGETSAMPLERPARAMETERIUIVPROC)gloGetProcAddress("glGetSamplerParameterIuiv");

		// OpenGL 4.0
		glMinSampleShading = (PFNGLMINSAMPLESHADINGPROC)gloGetProcAddress("glMinSampleShading");
		glBlendEquationi = (PFNGLBLENDEQUATIONIPROC)gloGetProcAddress("glBlendEquationi");
		glBlendEquationSeparatei = (PFNGLBLENDEQUATIONSEPARATEIPROC)gloGetProcAddress("glBlendEquationSeparatei");
		glBlendFunci = (PFNGLBLENDFUNCIPROC)gloGetProcAddress("glBlendFunci");
		glBlendFuncSeparatei = (PFNGLBLENDFUNCSEPARATEIPROC)gloGetProcAddress("glBlendFuncSeparatei");

		// GL_ARB_draw_indirect
		glDrawArraysIndirect = (PFNGLDRAWARRAYSINDIRECTPROC)gloGetProcAddress("glDrawArraysIndirect");
		glDrawElementsIndirect = (PFNGLDRAWELEMENTSINDIRECTPROC)gloGetProcAddress("glDrawElementsIndirect");

		// GL_ARB_gpu_shader_fp64
		glUniform1d = (PFNGLUNIFORM1DPROC)gloGetProcAddress("glUniform1d");
		glUniform2d = (PFNGLUNIFORM2DPROC)gloGetProcAddress("glUniform2d");
		glUniform3d = (PFNGLUNIFORM3DPROC)gloGetProcAddress("glUniform3d");
		glUniform4d = (PFNGLUNIFORM4DPROC)gloGetProcAddress("glUniform4d");
		glUniform1dv = (PFNGLUNIFORM1DVPROC)gloGetProcAddress("glUniform1dv");
		glUniform2dv = (PFNGLUNIFORM2DVPROC)gloGetProcAddress("glUniform2dv");
		glUniform3dv = (PFNGLUNIFORM3DVPROC)gloGetProcAddress("glUniform3dv");
		glUniform4dv = (PFNGLUNIFORM4DVPROC)gloGetProcAddress("glUniform4dv");
		glUniformMatrix2dv = (PFNGLUNIFORMMATRIX2DVPROC)gloGetProcAddress("glUniformMatrix2dv");
		glUniformMatrix3dv = (PFNGLUNIFORMMATRIX3DVPROC)gloGetProcAddress("glUniformMatrix3dv");
		glUniformMatrix4dv = (PFNGLUNIFORMMATRIX4DVPROC)gloGetProcAddress("glUniformMatrix4dv");
		glUniformMatrix2x3dv = (PFNGLUNIFORMMATRIX2X3DVPROC)gloGetProcAddress("glUniformMatrix2x3dv");
		glUniformMatrix2x4dv = (PFNGLUNIFORMMATRIX2X4DVPROC)gloGetProcAddress("glUniformMatrix2x4dv");
		glUniformMatrix3x2dv = (PFNGLUNIFORMMATRIX3X2DVPROC)gloGetProcAddress("glUniformMatrix3x2dv");
		glUniformMatrix3x4dv = (PFNGLUNIFORMMATRIX3X4DVPROC)gloGetProcAddress("glUniformMatrix3x4dv");
		glUniformMatrix4x2dv = (PFNGLUNIFORMMATRIX4X2DVPROC)gloGetProcAddress("glUniformMatrix4x2dv");
		glUniformMatrix4x3dv = (PFNGLUNIFORMMATRIX4X3DVPROC)gloGetProcAddress("glUniformMatrix4x3dv");
		glGetUniformdv = (PFNGLGETUNIFORMDVPROC)gloGetProcAddress("glGetUniformdv");

		// GL_ARB_shader_subroutine
		glGetSubroutineUniformLocation = (PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC)gloGetProcAddress("glGetSubroutineUniformLocation");
		glGetSubroutineIndex = (PFNGLGETSUBROUTINEINDEXPROC)gloGetProcAddress("glGetSubroutineIndex");
		glGetActiveSubroutineUniformiv = (PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC)gloGetProcAddress("glGetActiveSubroutineUniformiv");
		glGetActiveSubroutineUniformName = (PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC)gloGetProcAddress("glGetActiveSubroutineUniformName");
		glGetActiveSubroutineName = (PFNGLGETACTIVESUBROUTINENAMEPROC)gloGetProcAddress("glGetActiveSubroutineName");
		glUniformSubroutinesuiv = (PFNGLUNIFORMSUBROUTINESUIVPROC)gloGetProcAddress("glUniformSubroutinesuiv");
		glGetUniformSubroutineuiv = (PFNGLGETUNIFORMSUBROUTINEUIVPROC)gloGetProcAddress("glGetUniformSubroutineuiv");
		glGetProgramStageiv = (PFNGLGETPROGRAMSTAGEIVPROC)gloGetProcAddress("glGetProgramStageiv");

		// GL_ARB_tessellation_shader
		glPatchParameteri = (PFNGLPATCHPARAMETERIPROC)gloGetProcAddress("glPatchParameteri");
		glPatchParameterfv = (PFNGLPATCHPARAMETERFVPROC)gloGetProcAddress("glPatchParameterfv");

		// GL_ARB_transform_feedback2
		glBindTransformFeedback = (PFNGLBINDTRANSFORMFEEDBACKPROC)gloGetProcAddress("glBindTransformFeedback");
		glDeleteTransformFeedbacks = (PFNGLDELETETRANSFORMFEEDBACKSPROC)gloGetProcAddress("glDeleteTransformFeedbacks");
		glGenTransformFeedbacks = (PFNGLGENTRANSFORMFEEDBACKSPROC)gloGetProcAddress("glGenTransformFeedbacks");
		glIsTransformFeedback = (PFNGLISTRANSFORMFEEDBACKPROC)gloGetProcAddress("glIsTransformFeedback");
		glPauseTransformFeedback = (PFNGLPAUSETRANSFORMFEEDBACKPROC)gloGetProcAddress("glPauseTransformFeedback");
		glResumeTransformFeedback = (PFNGLRESUMETRANSFORMFEEDBACKPROC)gloGetProcAddress("glResumeTransformFeedback");
		glDrawTransformFeedback = (PFNGLDRAWTRANSFORMFEEDBACKPROC)gloGetProcAddress("glDrawTransformFeedback");

		// GL_ARB_transform_feedback3
		glDrawTransformFeedbackStream = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC)gloGetProcAddress("glDrawTransformFeedbackStream");
		glBeginQueryIndexed = (PFNGLBEGINQUERYINDEXEDPROC)gloGetProcAddress("glBeginQueryIndexed");
		glEndQueryIndexed = (PFNGLENDQUERYINDEXEDPROC)gloGetProcAddress("glEndQueryIndexed");
		glGetQueryIndexediv = (PFNGLGETQUERYINDEXEDIVPROC)gloGetProcAddress("glGetQueryIndexediv");

		// GL_ARB_separate_shader_objects
		glUseProgramStages = (PFNGLUSEPROGRAMSTAGESPROC)gloGetProcAddress("glUseProgramStages");
		glActiveShaderProgram = (PFNGLACTIVESHADERPROGRAMPROC)gloGetProcAddress("glActiveShaderProgram");
		glCreateShaderProgramv = (PFNGLCREATESHADERPROGRAMVPROC)gloGetProcAddress("glCreateShaderProgramv");
		glBindProgramPipeline = (PFNGLBINDPROGRAMPIPELINEPROC)gloGetProcAddress("glBindProgramPipeline");
		glDeleteProgramPipelines = (PFNGLDELETEPROGRAMPIPELINESPROC)gloGetProcAddress("glDeleteProgramPipelines");
		glGenProgramPipelines = (PFNGLGENPROGRAMPIPELINESPROC)gloGetProcAddress("glGenProgramPipelines");
		glIsProgramPipeline = (PFNGLISPROGRAMPIPELINEPROC)gloGetProcAddress("glIsProgramPipeline");
		glGetProgramPipelineiv = (PFNGLGETPROGRAMPIPELINEIVPROC)gloGetProcAddress("glGetProgramPipelineiv");
		glProgramUniform1i = (PFNGLPROGRAMUNIFORM1IPROC)gloGetProcAddress("glProgramUniform1i");
		glProgramUniform1iv = (PFNGLPROGRAMUNIFORM1IVPROC)gloGetProcAddress("glProgramUniform1iv");
		glProgramUniform1f = (PFNGLPROGRAMUNIFORM1FPROC)gloGetProcAddress("glProgramUniform1f");
		glProgramUniform1fv = (PFNGLPROGRAMUNIFORM1FVPROC)gloGetProcAddress("glProgramUniform1fv");
		glProgramUniform1d = (PFNGLPROGRAMUNIFORM1DPROC)gloGetProcAddress("glProgramUniform1d");
		glProgramUniform1dv = (PFNGLPROGRAMUNIFORM1DVPROC)gloGetProcAddress("glProgramUniform1dv");
		glProgramUniform1ui = (PFNGLPROGRAMUNIFORM1UIPROC)gloGetProcAddress("glProgramUniform1ui");
		glProgramUniform1uiv = (PFNGLPROGRAMUNIFORM1UIVPROC)gloGetProcAddress("glProgramUniform1uiv");
		glProgramUniform2i = (PFNGLPROGRAMUNIFORM2IPROC)gloGetProcAddress("glProgramUniform2i");
		glProgramUniform2iv = (PFNGLPROGRAMUNIFORM2IVPROC)gloGetProcAddress("glProgramUniform2iv");
		glProgramUniform2f = (PFNGLPROGRAMUNIFORM2FPROC)gloGetProcAddress("glProgramUniform2f");
		glProgramUniform2fv = (PFNGLPROGRAMUNIFORM2FVPROC)gloGetProcAddress("glProgramUniform2fv");
		glProgramUniform2d = (PFNGLPROGRAMUNIFORM2DPROC)gloGetProcAddress("glProgramUniform2d");
		glProgramUniform2dv = (PFNGLPROGRAMUNIFORM2DVPROC)gloGetProcAddress("glProgramUniform2dv");
		glProgramUniform2ui = (PFNGLPROGRAMUNIFORM2UIPROC)gloGetProcAddress("glProgramUniform2ui");
		glProgramUniform2uiv = (PFNGLPROGRAMUNIFORM2UIVPROC)gloGetProcAddress("glProgramUniform2uiv");
		glProgramUniform3i = (PFNGLPROGRAMUNIFORM3IPROC)gloGetProcAddress("glProgramUniform3i");
		glProgramUniform3iv = (PFNGLPROGRAMUNIFORM3IVPROC)gloGetProcAddress("glProgramUniform3iv");
		glProgramUniform3f = (PFNGLPROGRAMUNIFORM3FPROC)gloGetProcAddress("glProgramUniform3f");
		glProgramUniform3fv = (PFNGLPROGRAMUNIFORM3FVPROC)gloGetProcAddress("glProgramUniform3fv");
		glProgramUniform3d = (PFNGLPROGRAMUNIFORM3DPROC)gloGetProcAddress("glProgramUniform3d");
		glProgramUniform3dv = (PFNGLPROGRAMUNIFORM3DVPROC)gloGetProcAddress("glProgramUniform3dv");
		glProgramUniform3ui = (PFNGLPROGRAMUNIFORM3UIPROC)gloGetProcAddress("glProgramUniform3ui");
		glProgramUniform3uiv = (PFNGLPROGRAMUNIFORM3UIVPROC)gloGetProcAddress("glProgramUniform3uiv");
		glProgramUniform4i = (PFNGLPROGRAMUNIFORM4IPROC)gloGetProcAddress("glProgramUniform4i");
		glProgramUniform4iv = (PFNGLPROGRAMUNIFORM4IVPROC)gloGetProcAddress("glProgramUniform4iv");
		glProgramUniform4f = (PFNGLPROGRAMUNIFORM4FPROC)gloGetProcAddress("glProgramUniform4f");
		glProgramUniform4fv = (PFNGLPROGRAMUNIFORM4FVPROC)gloGetProcAddress("glProgramUniform4fv");
		glProgramUniform4d = (PFNGLPROGRAMUNIFORM4DPROC)gloGetProcAddress("glProgramUniform4d");
		glProgramUniform4dv = (PFNGLPROGRAMUNIFORM4DVPROC)gloGetProcAddress("glProgramUniform4dv");
		glProgramUniform4ui = (PFNGLPROGRAMUNIFORM4UIPROC)gloGetProcAddress("glProgramUniform4ui");
		glProgramUniform4uiv = (PFNGLPROGRAMUNIFORM4UIVPROC)gloGetProcAddress("glProgramUniform4uiv");
		glProgramUniformMatrix2fv = (PFNGLPROGRAMUNIFORMMATRIX2FVPROC)gloGetProcAddress("glProgramUniformMatrix2fv");
		glProgramUniformMatrix3fv = (PFNGLPROGRAMUNIFORMMATRIX3FVPROC)gloGetProcAddress("glProgramUniformMatrix3fv");
		glProgramUniformMatrix4fv = (PFNGLPROGRAMUNIFORMMATRIX4FVPROC)gloGetProcAddress("glProgramUniformMatrix4fv");
		glProgramUniformMatrix2dv = (PFNGLPROGRAMUNIFORMMATRIX2DVPROC)gloGetProcAddress("glProgramUniformMatrix2dv");
		glProgramUniformMatrix3dv = (PFNGLPROGRAMUNIFORMMATRIX3DVPROC)gloGetProcAddress("glProgramUniformMatrix3dv");
		glProgramUniformMatrix4dv = (PFNGLPROGRAMUNIFORMMATRIX4DVPROC)gloGetProcAddress("glProgramUniformMatrix4dv");
		glProgramUniformMatrix2x3fv = (PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC)gloGetProcAddress("glProgramUniformMatrix2x3fv");
		glProgramUniformMatrix3x2fv = (PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC)gloGetProcAddress("glProgramUniformMatrix3x2fv");
		glProgramUniformMatrix2x4fv = (PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC)gloGetProcAddress("glProgramUniformMatrix2x4fv");
		glProgramUniformMatrix4x2fv = (PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC)gloGetProcAddress("glProgramUniformMatrix4x2fv");
		glProgramUniformMatrix3x4fv = (PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC)gloGetProcAddress("glProgramUniformMatrix3x4fv");
		glProgramUniformMatrix4x3fv = (PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC)gloGetProcAddress("glProgramUniformMatrix4x3fv");
		glProgramUniformMatrix2x3dv = (PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC)gloGetProcAddress("glProgramUniformMatrix2x3dv");
		glProgramUniformMatrix3x2dv = (PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC)gloGetProcAddress("glProgramUniformMatrix3x2dv");
		glProgramUniformMatrix2x4dv = (PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC)gloGetProcAddress("glProgramUniformMatrix2x4dv");
		glProgramUniformMatrix4x2dv = (PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC)gloGetProcAddress("glProgramUniformMatrix4x2dv");
		glProgramUniformMatrix3x4dv = (PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC)gloGetProcAddress("glProgramUniformMatrix3x4dv");
		glProgramUniformMatrix4x3dv = (PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC)gloGetProcAddress("glProgramUniformMatrix4x3dv");
		glValidateProgramPipeline = (PFNGLVALIDATEPROGRAMPIPELINEPROC)gloGetProcAddress("glValidateProgramPipeline");
		glGetProgramPipelineInfoLog = (PFNGLGETPROGRAMPIPELINEINFOLOGPROC)gloGetProcAddress("glGetProgramPipelineInfoLog");

		// GL_ARB_get_program_binary
		glGetProgramBinary = (PFNGLGETPROGRAMBINARYPROC)gloGetProcAddress("glGetProgramBinary");
		glProgramBinary = (PFNGLPROGRAMBINARYPROC)gloGetProcAddress("glProgramBinary");
		glProgramParameteri = (PFNGLPROGRAMPARAMETERIPROC)gloGetProcAddress("glProgramParameteri");

		// GL_ARB_vertex_attrib_64bit
		glVertexAttribL1d = (PFNGLVERTEXATTRIBL1DPROC)gloGetProcAddress("glVertexAttribL1d");
		glVertexAttribL2d = (PFNGLVERTEXATTRIBL2DPROC)gloGetProcAddress("glVertexAttribL2d");
		glVertexAttribL3d = (PFNGLVERTEXATTRIBL3DPROC)gloGetProcAddress("glVertexAttribL3d");
		glVertexAttribL4d = (PFNGLVERTEXATTRIBL4DPROC)gloGetProcAddress("glVertexAttribL4d");
		glVertexAttribL1dv = (PFNGLVERTEXATTRIBL1DVPROC)gloGetProcAddress("glVertexAttribL1dv");
		glVertexAttribL2dv = (PFNGLVERTEXATTRIBL2DVPROC)gloGetProcAddress("glVertexAttribL2dv");
		glVertexAttribL3dv = (PFNGLVERTEXATTRIBL3DVPROC)gloGetProcAddress("glVertexAttribL3dv");
		glVertexAttribL4dv = (PFNGLVERTEXATTRIBL4DVPROC)gloGetProcAddress("glVertexAttribL4dv");
		glVertexAttribLPointer = (PFNGLVERTEXATTRIBLPOINTERPROC)gloGetProcAddress("glVertexAttribLPointer");
		glGetVertexAttribLdv = (PFNGLGETVERTEXATTRIBLDVPROC)gloGetProcAddress("glGetVertexAttribLdv");

		// GL_ARB_viewport_array
		glViewportArrayv = (PFNGLVIEWPORTARRAYVPROC)gloGetProcAddress("glViewportArrayv");
		glViewportIndexedf = (PFNGLVIEWPORTINDEXEDFPROC)gloGetProcAddress("glViewportIndexedf");
		glViewportIndexedfv = (PFNGLVIEWPORTINDEXEDFVPROC)gloGetProcAddress("glViewportIndexedfv");
		glScissorArrayv = (PFNGLSCISSORARRAYVPROC)gloGetProcAddress("glScissorArrayv");
		glScissorIndexed = (PFNGLSCISSORINDEXEDPROC)gloGetProcAddress("glScissorIndexed");
		glScissorIndexedv = (PFNGLSCISSORINDEXEDVPROC)gloGetProcAddress("glScissorIndexedv");
		glDepthRangeArrayv = (PFNGLDEPTHRANGEARRAYVPROC)gloGetProcAddress("glDepthRangeArrayv");
		glDepthRangeIndexed = (PFNGLDEPTHRANGEINDEXEDPROC)gloGetProcAddress("glDepthRangeIndexed");
		glGetFloati_v = (PFNGLGETFLOATI_VPROC)gloGetProcAddress("glGetFloati_v");
		glGetDoublei_v = (PFNGLGETDOUBLEI_VPROC)gloGetProcAddress("glGetDoublei_v");

		// OpenGL 4.2

		// GL_ARB_texture_storage
		glTexStorage1D = (PFNGLTEXSTORAGE1DPROC)gloGetProcAddress("glTexStorage1D");
		glTexStorage2D = (PFNGLTEXSTORAGE2DPROC)gloGetProcAddress("glTexStorage2D");
		glTexStorage3D = (PFNGLTEXSTORAGE3DPROC)gloGetProcAddress("glTexStorage3D");

		// GL_ARB_base_instance
		glDrawArraysInstancedBaseInstance = (PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC)gloGetProcAddress("glDrawArraysInstancedBaseInstance");
		glDrawElementsInstancedBaseInstance = (PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC)gloGetProcAddress("glDrawElementsInstancedBaseInstance");
		glDrawElementsInstancedBaseVertexBaseInstance = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC)gloGetProcAddress("glDrawElementsInstancedBaseVertexBaseInstance");

		// GL_ARB_shader_image_load_store
		glBindImageTexture = (PFNGLBINDIMAGETEXTUREPROC)gloGetProcAddress("glBindImageTexture");
		glMemoryBarrier = (PFNGLMEMORYBARRIERPROC)gloGetProcAddress("glMemoryBarrier");

		// GL_ARB_internalformat_query
		glGetInternalformativ = (PFNGLGETINTERNALFORMATIVPROC)gloGetProcAddress("glGetInternalformativ");

		// GL_ARB_transform_feedback_instanced
		glDrawTransformFeedbackInstanced = (PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC)gloGetProcAddress("glDrawTransformFeedbackInstanced");
		glDrawTransformFeedbackStreamInstanced = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC)gloGetProcAddress("glDrawTransformFeedbackStreamInstanced");

		// OpenGL 4.3

		// GL_ARB_compute_shader
		glDispatchCompute = (PFNGLDISPATCHCOMPUTEPROC)gloGetProcAddress("glDispatchCompute");
		glDispatchComputeIndirect = (PFNGLDISPATCHCOMPUTEINDIRECTPROC)gloGetProcAddress("glDispatchComputeIndirect");

		// GL_ARB_clear_buffer_object
		glClearBufferData = (PFNGLCLEARBUFFERDATAPROC)gloGetProcAddress("glClearBufferData");
		glClearBufferSubData = (PFNGLCLEARBUFFERSUBDATAPROC)gloGetProcAddress("glClearBufferSubData");
		glClearNamedBufferDataEXT = (PFNGLCLEARNAMEDBUFFERDATAEXTPROC)gloGetProcAddress("glClearNamedBufferDataEXT");
		glClearNamedBufferSubDataEXT = (PFNGLCLEARNAMEDBUFFERSUBDATAEXTPROC)gloGetProcAddress("glClearNamedBufferSubDataEXT");

		// GL_ARB_clear_buffer_object
		glClearBufferData = (PFNGLCLEARBUFFERDATAPROC)gloGetProcAddress("glClearBufferData");

		// GL_ARB_copy_image
		glCopyImageSubData = (PFNGLCOPYIMAGESUBDATAPROC)gloGetProcAddress("glCopyImageSubData");

		// GL_ARB_program_interface_query
		glGetProgramInterfaceiv = (PFNGLGETPROGRAMINTERFACEIVPROC)gloGetProcAddress("glGetProgramInterfaceiv");
		glGetProgramResourceIndex = (PFNGLGETPROGRAMRESOURCEINDEXPROC)gloGetProcAddress("glGetProgramResourceIndex");
		glGetProgramResourceName = (PFNGLGETPROGRAMRESOURCENAMEPROC)gloGetProcAddress("glGetProgramResourceName");
		glGetProgramResourceiv = (PFNGLGETPROGRAMRESOURCEIVPROC)gloGetProcAddress("glGetProgramResourceiv");
		glGetProgramResourceLocation = (PFNGLGETPROGRAMRESOURCELOCATIONPROC)gloGetProcAddress("glGetProgramResourceLocation");
		glGetProgramResourceLocationIndex = (PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC)gloGetProcAddress("glGetProgramResourceLocationIndex");

		// GL_ARB_texture_buffer_range
		glTexBufferRange = (PFNGLTEXBUFFERRANGEPROC)gloGetProcAddress("glTexBufferRange");
		glTextureBufferRangeEXT = (PFNGLTEXTUREBUFFERRANGEEXTPROC)gloGetProcAddress("glTextureBufferRangeEXT");

		// GL_ARB_texture_storage_multisample
		glTexStorage2DMultisample = (PFNGLTEXSTORAGE2DMULTISAMPLEPROC)gloGetProcAddress("glTexStorage2DMultisample");
		glTexStorage3DMultisample = (PFNGLTEXSTORAGE3DMULTISAMPLEPROC)gloGetProcAddress("glTexStorage3DMultisample");
		glTextureStorage2DMultisampleEXT = (PFNGLTEXTURESTORAGE2DMULTISAMPLEEXTPROC)gloGetProcAddress("glTextureStorage2DMultisampleEXT");
		glTextureStorage3DMultisampleEXT = (PFNGLTEXTURESTORAGE3DMULTISAMPLEEXTPROC)gloGetProcAddress("glTextureStorage3DMultisampleEXT");

		// GL_ARB_texture_view
		glTextureView = (PFNGLTEXTUREVIEWPROC)gloGetProcAddress("glTextureView");

		// GL_KHR_debug
		glDebugMessageControl = (PFNGLDEBUGMESSAGECONTROLPROC)gloGetProcAddress("glDebugMessageControl");
		glDebugMessageInsert = (PFNGLDEBUGMESSAGEINSERTPROC)gloGetProcAddress("glDebugMessageInsert");
		glDebugMessageCallback = (PFNGLDEBUGMESSAGECALLBACKPROC)gloGetProcAddress("glDebugMessageCallback");
		glGetDebugMessageLog = (PFNGLGETDEBUGMESSAGELOGPROC)gloGetProcAddress("glGetDebugMessageLog");
		glPushDebugGroup = (PFNGLPUSHDEBUGGROUPPROC)gloGetProcAddress("glPushDebugGroup");
		glPopDebugGroup = (PFNGLPOPDEBUGGROUPPROC)gloGetProcAddress("glPopDebugGroup");
		glObjectLabel = (PFNGLOBJECTLABELPROC)gloGetProcAddress("glObjectLabel");
		glGetObjectLabel = (PFNGLGETOBJECTLABELPROC)gloGetProcAddress("glGetObjectLabel");
		glObjectPtrLabel = (PFNGLOBJECTPTRLABELPROC)gloGetProcAddress("glObjectPtrLabel");
		glGetObjectPtrLabel = (PFNGLGETOBJECTPTRLABELPROC)gloGetProcAddress("glGetObjectPtrLabel");

		// GL_EXT_direct_state_access
		glBindMultiTextureEXT = (PFNGLBINDMULTITEXTUREEXTPROC)gloGetProcAddress("glBindMultiTextureEXT");
		glCheckNamedFramebufferStatusEXT = (PFNGLCHECKNAMEDFRAMEBUFFERSTATUSEXTPROC)gloGetProcAddress("glCheckNamedFramebufferStatusEXT");
		glClientAttribDefaultEXT = (PFNGLCLIENTATTRIBDEFAULTEXTPROC)gloGetProcAddress("glClientAttribDefaultEXT");
		glCompressedTextureImage1DEXT = (PFNGLCOMPRESSEDTEXTUREIMAGE1DEXTPROC)gloGetProcAddress("glCompressedTextureImage1DEXT");
		glCompressedTextureImage2DEXT = (PFNGLCOMPRESSEDTEXTUREIMAGE2DEXTPROC)gloGetProcAddress("glCompressedTextureImage2DEXT");
		glCompressedTextureImage3DEXT = (PFNGLCOMPRESSEDTEXTUREIMAGE3DEXTPROC)gloGetProcAddress("glCompressedTextureImage3DEXT");
		glCompressedTextureSubImage1DEXT = (PFNGLCOMPRESSEDTEXTURESUBIMAGE1DEXTPROC)gloGetProcAddress("glCompressedTextureSubImage1DEXT");
		glCompressedTextureSubImage2DEXT = (PFNGLCOMPRESSEDTEXTURESUBIMAGE2DEXTPROC)gloGetProcAddress("glCompressedTextureSubImage2DEXT");
		glCompressedTextureSubImage3DEXT = (PFNGLCOMPRESSEDTEXTURESUBIMAGE3DEXTPROC)gloGetProcAddress("glCompressedTextureSubImage3DEXT");
		glCopyTextureImage1DEXT = (PFNGLCOPYTEXTUREIMAGE1DEXTPROC)gloGetProcAddress("glCopyTextureImage1DEXT");
		glCopyTextureImage2DEXT = (PFNGLCOPYTEXTUREIMAGE2DEXTPROC)gloGetProcAddress("glCopyTextureImage2DEXT");
		glCopyTextureSubImage1DEXT = (PFNGLCOPYTEXTURESUBIMAGE1DEXTPROC)gloGetProcAddress("glCopyTextureSubImage1DEXT");
		glCopyTextureSubImage2DEXT = (PFNGLCOPYTEXTURESUBIMAGE2DEXTPROC)gloGetProcAddress("glCopyTextureSubImage2DEXT");
		glCopyTextureSubImage3DEXT = (PFNGLCOPYTEXTURESUBIMAGE3DEXTPROC)gloGetProcAddress("glCopyTextureSubImage3DEXT");
		glDisableVertexArrayAttribEXT = (PFNGLDISABLEVERTEXARRAYATTRIBEXTPROC)gloGetProcAddress("glDisableVertexArrayAttribEXT");
		glDisableVertexArrayEXT = (PFNGLDISABLEVERTEXARRAYEXTPROC)gloGetProcAddress("glDisableVertexArrayEXT");
		glEnableVertexArrayAttribEXT = (PFNGLENABLEVERTEXARRAYATTRIBEXTPROC)gloGetProcAddress("glEnableVertexArrayAttribEXT");
		glEnableVertexArrayEXT = (PFNGLENABLEVERTEXARRAYEXTPROC)gloGetProcAddress("glEnableVertexArrayEXT");
		glFlushMappedNamedBufferRangeEXT = (PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEEXTPROC)gloGetProcAddress("glFlushMappedNamedBufferRangeEXT");
		glFramebufferDrawBufferEXT = (PFNGLFRAMEBUFFERDRAWBUFFEREXTPROC)gloGetProcAddress("glFramebufferDrawBufferEXT");
		glFramebufferDrawBuffersEXT = (PFNGLFRAMEBUFFERDRAWBUFFERSEXTPROC)gloGetProcAddress("glFramebufferDrawBuffersEXT");
		glFramebufferReadBufferEXT = (PFNGLFRAMEBUFFERREADBUFFEREXTPROC)gloGetProcAddress("glFramebufferReadBufferEXT");
		glGenerateTextureMipmapEXT = (PFNGLGENERATETEXTUREMIPMAPEXTPROC)gloGetProcAddress("glGenerateTextureMipmapEXT");
		glGetCompressedTextureImageEXT = (PFNGLGETCOMPRESSEDTEXTUREIMAGEEXTPROC)gloGetProcAddress("glGetCompressedTextureImageEXT");
		glGetFramebufferParameterivEXT = (PFNGLGETFRAMEBUFFERPARAMETERIVEXTPROC)gloGetProcAddress("glGetFramebufferParameterivEXT");
		glGetNamedBufferParameterivEXT = (PFNGLGETNAMEDBUFFERPARAMETERIVEXTPROC)gloGetProcAddress("glGetNamedBufferParameterivEXT");
		glGetNamedBufferPointervEXT = (PFNGLGETNAMEDBUFFERPOINTERVEXTPROC)gloGetProcAddress("glGetNamedBufferPointervEXT");
		glGetNamedBufferSubDataEXT = (PFNGLGETNAMEDBUFFERSUBDATAEXTPROC)gloGetProcAddress("glGetNamedBufferSubDataEXT");
		glGetNamedFramebufferAttachmentParameterivEXT = (PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC)gloGetProcAddress("glGetNamedFramebufferAttachmentParameterivEXT");
		glGetNamedProgramStringEXT = (PFNGLGETNAMEDPROGRAMSTRINGEXTPROC)gloGetProcAddress("glGetNamedProgramStringEXT");
		glGetNamedProgramivEXT = (PFNGLGETNAMEDPROGRAMIVEXTPROC)gloGetProcAddress("glGetNamedProgramivEXT");
		glGetNamedRenderbufferParameterivEXT = (PFNGLGETNAMEDRENDERBUFFERPARAMETERIVEXTPROC)gloGetProcAddress("glGetNamedRenderbufferParameterivEXT");
		glGetTextureImageEXT = (PFNGLGETTEXTUREIMAGEEXTPROC)gloGetProcAddress("glGetTextureImageEXT");
		glGetTextureLevelParameterfvEXT = (PFNGLGETTEXTURELEVELPARAMETERFVEXTPROC)gloGetProcAddress("glGetTextureLevelParameterfvEXT");
		glGetTextureLevelParameterivEXT = (PFNGLGETTEXTURELEVELPARAMETERIVEXTPROC)gloGetProcAddress("glGetTextureLevelParameterivEXT");
		glGetTextureParameterIivEXT = (PFNGLGETTEXTUREPARAMETERIIVEXTPROC)gloGetProcAddress("glGetTextureParameterIivEXT");
		glGetTextureParameterIuivEXT = (PFNGLGETTEXTUREPARAMETERIUIVEXTPROC)gloGetProcAddress("glGetTextureParameterIuivEXT");
		glGetTextureParameterfvEXT = (PFNGLGETTEXTUREPARAMETERFVEXTPROC)gloGetProcAddress("glGetTextureParameterfvEXT");
		glGetTextureParameterivEXT = (PFNGLGETTEXTUREPARAMETERIVEXTPROC)gloGetProcAddress("glGetTextureParameterivEXT");
		glGetVertexArrayIntegeri_vEXT = (PFNGLGETVERTEXARRAYINTEGERI_VEXTPROC)gloGetProcAddress("glGetVertexArrayIntegeri_vEXT");
		glGetVertexArrayIntegervEXT = (PFNGLGETVERTEXARRAYINTEGERVEXTPROC)gloGetProcAddress("glGetVertexArrayIntegervEXT");
		glGetVertexArrayPointeri_vEXT = (PFNGLGETVERTEXARRAYPOINTERI_VEXTPROC)gloGetProcAddress("glGetVertexArrayPointeri_vEXT");
		glGetVertexArrayPointervEXT = (PFNGLGETVERTEXARRAYPOINTERVEXTPROC)gloGetProcAddress("glGetVertexArrayPointervEXT");
		glMapNamedBufferEXT = (PFNGLMAPNAMEDBUFFEREXTPROC)gloGetProcAddress("glMapNamedBufferEXT");
		glMapNamedBufferRangeEXT = (PFNGLMAPNAMEDBUFFERRANGEEXTPROC)gloGetProcAddress("glMapNamedBufferRangeEXT");
		glNamedBufferDataEXT = (PFNGLNAMEDBUFFERDATAEXTPROC)gloGetProcAddress("glNamedBufferDataEXT");
		glNamedBufferSubDataEXT = (PFNGLNAMEDBUFFERSUBDATAEXTPROC)gloGetProcAddress("glNamedBufferSubDataEXT");
		glNamedCopyBufferSubDataEXT = (PFNGLNAMEDCOPYBUFFERSUBDATAEXTPROC)gloGetProcAddress("glNamedCopyBufferSubDataEXT");

		glNamedFramebufferRenderbufferEXT = (PFNGLNAMEDFRAMEBUFFERRENDERBUFFEREXTPROC)gloGetProcAddress("glNamedFramebufferRenderbufferEXT");
		glNamedFramebufferTexture1DEXT = (PFNGLNAMEDFRAMEBUFFERTEXTURE1DEXTPROC)gloGetProcAddress("glNamedFramebufferTexture1DEXT");
		glNamedFramebufferTexture2DEXT = (PFNGLNAMEDFRAMEBUFFERTEXTURE2DEXTPROC)gloGetProcAddress("glNamedFramebufferTexture2DEXT");
		glNamedFramebufferTexture3DEXT = (PFNGLNAMEDFRAMEBUFFERTEXTURE3DEXTPROC)gloGetProcAddress("glNamedFramebufferTexture3DEXT");
		glNamedFramebufferTextureEXT = (PFNGLNAMEDFRAMEBUFFERTEXTUREEXTPROC)gloGetProcAddress("glNamedFramebufferTextureEXT");
		glNamedFramebufferTextureFaceEXT = (PFNGLNAMEDFRAMEBUFFERTEXTUREFACEEXTPROC)gloGetProcAddress("glNamedFramebufferTextureFaceEXT");
		glNamedFramebufferTextureLayerEXT = (PFNGLNAMEDFRAMEBUFFERTEXTURELAYEREXTPROC)gloGetProcAddress("glNamedFramebufferTextureLayerEXT");
		glNamedProgramStringEXT = (PFNGLNAMEDPROGRAMSTRINGEXTPROC)gloGetProcAddress("glNamedProgramStringEXT");
		glNamedRenderbufferStorageEXT = (PFNGLNAMEDRENDERBUFFERSTORAGEEXTPROC)gloGetProcAddress("glNamedRenderbufferStorageEXT");
		glNamedRenderbufferStorageMultisampleCoverageEXT = (PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLECOVERAGEEXTPROC)gloGetProcAddress("glNamedRenderbufferStorageMultisampleCoverageEXT");
		glNamedRenderbufferStorageMultisampleEXT = (PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC)gloGetProcAddress("glNamedRenderbufferStorageMultisampleEXT");
		glTextureBufferEXT = (PFNGLTEXTUREBUFFEREXTPROC)gloGetProcAddress("glTextureBufferEXT");
		glTextureImage1DEXT = (PFNGLTEXTUREIMAGE1DEXTPROC)gloGetProcAddress("glTextureImage1DEXT");
		glTextureImage2DEXT = (PFNGLTEXTUREIMAGE2DEXTPROC)gloGetProcAddress("glTextureImage2DEXT");
		glTextureImage3DEXT = (PFNGLTEXTUREIMAGE3DEXTPROC)gloGetProcAddress("glTextureImage3DEXT");
		glTextureParameterIivEXT = (PFNGLTEXTUREPARAMETERIIVEXTPROC)gloGetProcAddress("glTextureParameterIivEXT");
		glTextureParameterIuivEXT = (PFNGLTEXTUREPARAMETERIUIVEXTPROC)gloGetProcAddress("glTextureParameterIuivEXT");
		glTextureParameterfEXT = (PFNGLTEXTUREPARAMETERFEXTPROC)gloGetProcAddress("glTextureParameterfEXT");
		glTextureParameterfvEXT = (PFNGLTEXTUREPARAMETERFVEXTPROC)gloGetProcAddress("glTextureParameterfvEXT");
		glTextureParameteriEXT = (PFNGLTEXTUREPARAMETERIEXTPROC)gloGetProcAddress("glTextureParameteriEXT");
		glTextureParameterivEXT = (PFNGLTEXTUREPARAMETERIVEXTPROC)gloGetProcAddress("glTextureParameterivEXT");
		glTextureRenderbufferEXT = (PFNGLTEXTURERENDERBUFFEREXTPROC)gloGetProcAddress("glTextureRenderbufferEXT");
		glTextureSubImage1DEXT = (PFNGLTEXTURESUBIMAGE1DEXTPROC)gloGetProcAddress("glTextureSubImage1DEXT");
		glTextureSubImage2DEXT = (PFNGLTEXTURESUBIMAGE2DEXTPROC)gloGetProcAddress("glTextureSubImage2DEXT");
		glTextureSubImage3DEXT = (PFNGLTEXTURESUBIMAGE3DEXTPROC)gloGetProcAddress("glTextureSubImage3DEXT");
		glUnmapNamedBufferEXT = (PFNGLUNMAPNAMEDBUFFEREXTPROC)gloGetProcAddress("glUnmapNamedBufferEXT");
		glVertexArrayVertexAttribIOffsetEXT = (PFNGLVERTEXARRAYVERTEXATTRIBIOFFSETEXTPROC)gloGetProcAddress("glVertexArrayVertexAttribIOffsetEXT");
		glVertexArrayVertexAttribOffsetEXT = (PFNGLVERTEXARRAYVERTEXATTRIBOFFSETEXTPROC)gloGetProcAddress("glVertexArrayVertexAttribOffsetEXT");
		glVertexArrayVertexOffsetEXT = (PFNGLVERTEXARRAYVERTEXOFFSETEXTPROC)gloGetProcAddress("glVertexArrayVertexOffsetEXT");

		glVertexArrayBindVertexBufferEXT = (PFNGLVERTEXARRAYBINDVERTEXBUFFEREXTPROC)gloGetProcAddress("glVertexArrayBindVertexBufferEXT");
		glVertexArrayVertexAttribFormatEXT = (PFNGLVERTEXARRAYBINDVERTEXATTRIBFORMATEXTPROC)gloGetProcAddress("glVertexArrayVertexAttribFormatEXT");
		glVertexArrayVertexAttribIFormatEXT = (PFNGLVERTEXARRAYBINDVERTEXATTRIBIFORMATEXTPROC)gloGetProcAddress("glVertexArrayVertexAttribIFormatEXT");
		glVertexArrayVertexAttribLFormatEXT = (PFNGLVERTEXARRAYBINDVERTEXATTRIBLFORMATEXTPROC)gloGetProcAddress("glVertexArrayVertexAttribLFormatEXT");
		glVertexArrayVertexAttribBindingEXT = (PFNGLVERTEXARRAYBINDVERTEXATTRIBBINDINGEXTPROC)gloGetProcAddress("glVertexArrayVertexAttribBindingEXT");
		glVertexArrayVertexBindingDivisorEXT = (PFNGLVERTEXARRAYBINDVERTEXBINDINGDIVISOREXTPROC)gloGetProcAddress("glVertexArrayVertexBindingDivisorEXT");
		glTextureStorage1DEXT = (PFNGLTEXTURESTORAGE1DEXTPROC)gloGetProcAddress("glTextureStorage1DEXT");
		glTextureStorage2DEXT = (PFNGLTEXTURESTORAGE2DEXTPROC)gloGetProcAddress("glTextureStorage2DEXT");
		glTextureStorage3DEXT = (PFNGLTEXTURESTORAGE3DEXTPROC)gloGetProcAddress("glTextureStorage3DEXT");

		// GL_AMD_sample_positions
		glSetMultisamplefvAMD = (PFNGLSETMULTISAMPLEFVAMDPROC)gloGetProcAddress("glSetMultisamplefvAMD");

		// GL_NV_shader_buffer_load
		glGetBufferParameterui64vNV = (PFNGLGETBUFFERPARAMETERUI64VNVPROC)gloGetProcAddress("glGetBufferParameterui64vNV");
		glGetIntegerui64vNV = (PFNGLGETINTEGERUI64VNVPROC)gloGetProcAddress("glGetIntegerui64vNV");
		glGetNamedBufferParameterui64vNV = (PFNGLGETNAMEDBUFFERPARAMETERUI64VNVPROC)gloGetProcAddress("glGetNamedBufferParameterui64vNV");
		glIsBufferResidentNV = (PFNGLISBUFFERRESIDENTNVPROC)gloGetProcAddress("glIsBufferResidentNV");
		glIsNamedBufferResidentNV = (PFNGLISNAMEDBUFFERRESIDENTNVPROC)gloGetProcAddress("glIsNamedBufferResidentNV");
		glMakeBufferNonResidentNV = (PFNGLMAKEBUFFERNONRESIDENTNVPROC)gloGetProcAddress("glMakeBufferNonResidentNV");
		glMakeBufferResidentNV = (PFNGLMAKEBUFFERRESIDENTNVPROC)gloGetProcAddress("glMakeBufferResidentNV");
		glMakeNamedBufferNonResidentNV = (PFNGLMAKENAMEDBUFFERNONRESIDENTNVPROC)gloGetProcAddress("glMakeNamedBufferNonResidentNV");
		glMakeNamedBufferResidentNV = (PFNGLMAKENAMEDBUFFERRESIDENTNVPROC)gloGetProcAddress("glMakeNamedBufferResidentNV");
		glProgramUniformui64NV = (PFNGLPROGRAMUNIFORMUI64NVPROC)gloGetProcAddress("glProgramUniformui64NV");
		glProgramUniformui64vNV = (PFNGLPROGRAMUNIFORMUI64VNVPROC)gloGetProcAddress("glProgramUniformui64vNV");
		glUniformui64NV = (PFNGLUNIFORMUI64NVPROC)gloGetProcAddress("glUniformui64NV");
		glUniformui64vNV = (PFNGLUNIFORMUI64VNVPROC)gloGetProcAddress("glUniformui64vNV");

		// GL_NV_vertex_buffer_unified_memory
		glBufferAddressRangeNV = (PFNGLBUFFERADDRESSRANGENVPROC)gloGetProcAddress("glBufferAddressRangeNV");
		glVertexAttribFormatNV = (PFNGLVERTEXATTRIBFORMATNVPROC)gloGetProcAddress("glVertexAttribFormatNV");
		glVertexAttribIFormatNV = (PFNGLVERTEXATTRIBIFORMATNVPROC)gloGetProcAddress("glVertexAttribIFormatNV");
		glGetIntegerui64i_vNV = (PFNGLGETINTEGERUI64I_VNVPROC)gloGetProcAddress("glGetIntegerui64i_vNV");

		// GL_NV_texture_multisample
		glTexImage2DMultisampleCoverageNV = (PFNGLTEXIMAGE2DMULTISAMPLECOVERAGENVPROC)gloGetProcAddress("glTexImage2DMultisampleCoverageNV");
		glTexImage3DMultisampleCoverageNV = (PFNGLTEXIMAGE3DMULTISAMPLECOVERAGENVPROC)gloGetProcAddress("glTexImage3DMultisampleCoverageNV");
		glTextureImage2DMultisampleCoverageNV = (PFNGLTEXTUREIMAGE2DMULTISAMPLECOVERAGENVPROC)gloGetProcAddress("glTextureImage2DMultisampleCoverageNV");
		glTextureImage2DMultisampleNV = (PFNGLTEXTUREIMAGE2DMULTISAMPLENVPROC)gloGetProcAddress("glTextureImage2DMultisampleNV");
		glTextureImage3DMultisampleCoverageNV = (PFNGLTEXTUREIMAGE3DMULTISAMPLECOVERAGENVPROC)gloGetProcAddress("glTextureImage3DMultisampleCoverageNV");
		glTextureImage3DMultisampleNV = (PFNGLTEXTUREIMAGE3DMULTISAMPLENVPROC)gloGetProcAddress("glTextureImage3DMultisampleNV");

		// GL_NV_explicit_multisample
		glGetMultisamplefvNV = (PFNGLGETMULTISAMPLEFVNVPROC)gloGetProcAddress("glGetMultisamplefvNV");
		glSampleMaskIndexedNV = (PFNGLSAMPLEMASKINDEXEDNVPROC)gloGetProcAddress("glSampleMaskIndexedNV");
		glTexRenderbufferNV = (PFNGLTEXRENDERBUFFERNVPROC)gloGetProcAddress("glTexRenderbufferNV");

		// GL_NV_bindless_texture
		glGetImageHandleNV = (PFNGLGETIMAGEHANDLENVPROC)gloGetProcAddress("glGetImageHandleNV");
		glGetTextureHandleNV = (PFNGLGETTEXTUREHANDLENVPROC)gloGetProcAddress("glGetTextureHandleNV");
		glGetTextureSamplerHandleNV = (PFNGLGETTEXTURESAMPLERHANDLENVPROC)gloGetProcAddress("glGetTextureSamplerHandleNV");
		glIsImageHandleResidentNV = (PFNGLISIMAGEHANDLERESIDENTNVPROC)gloGetProcAddress("glIsImageHandleResidentNV");
		glIsTextureHandleResidentNV = (PFNGLISTEXTUREHANDLERESIDENTNVPROC)gloGetProcAddress("glIsTextureHandleResidentNV");
		glMakeImageHandleNonResidentNV = (PFNGLMAKEIMAGEHANDLENONRESIDENTNVPROC)gloGetProcAddress("glMakeImageHandleNonResidentNV");
		glMakeImageHandleResidentNV = (PFNGLMAKEIMAGEHANDLERESIDENTNVPROC)gloGetProcAddress("glMakeImageHandleResidentNV");
		glMakeTextureHandleNonResidentNV = (PFNGLMAKETEXTUREHANDLENONRESIDENTNVPROC)gloGetProcAddress("glMakeTextureHandleNonResidentNV");
		glMakeTextureHandleResidentNV = (PFNGLMAKETEXTUREHANDLERESIDENTNVPROC)gloGetProcAddress("glMakeTextureHandleResidentNV");
		glProgramUniformHandleui64NV = (PFNGLPROGRAMUNIFORMHANDLEUI64NVPROC)gloGetProcAddress("glProgramUniformHandleui64NV");
		glProgramUniformHandleui64vNV = (PFNGLPROGRAMUNIFORMHANDLEUI64VNVPROC)gloGetProcAddress("glProgramUniformHandleui64vNV");
		glUniformHandleui64NV = (PFNGLUNIFORMHANDLEUI64NVPROC)gloGetProcAddress("glUniformHandleui64NV");
		glUniformHandleui64vNV = (PFNGLUNIFORMHANDLEUI64VNVPROC)gloGetProcAddress("glUniformHandleui64vNV");

		// GL_EXT_texture_compression_s3tc
		#define GL_COMPRESSED_RGB_S3TC_DXT1_EXT			0x83F0
		#define GL_COMPRESSED_RGBA_S3TC_DXT1_EXT		0x83F1
		#define GL_COMPRESSED_RGBA_S3TC_DXT3_EXT		0x83F2
		#define GL_COMPRESSED_RGBA_S3TC_DXT5_EXT		0x83F3

		// GL_ARB_debug_output
		glDebugMessageControlARB = (PFNGLDEBUGMESSAGECONTROLPROC)gloGetProcAddress("glDebugMessageControlARB");
		glDebugMessageInsertARB = (PFNGLDEBUGMESSAGEINSERTARBPROC)gloGetProcAddress("glDebugMessageInsertARB");
		glDebugMessageCallbackARB = (PFNGLDEBUGMESSAGECALLBACKPROC)gloGetProcAddress("glDebugMessageCallbackARB");
		glGetDebugMessageLogARB = (PFNGLGETDEBUGMESSAGELOGARBPROC)gloGetProcAddress("glGetDebugMessageLogARB");

		// GL_AMD_sparse_texture
		glTexStorageSparseAMD = (PFNGLTEXSTORAGESPARSEAMDPROC)gloGetProcAddress("glTexStorageSparseAMD");
		glTextureStorageSparseAMD = (PFNGLTEXTURESTORAGESPARSEAMDPROC)gloGetProcAddress("glTextureStorageSparseAMD");

		//WGL_EXT_swap_control
		wglSwapIntervalEXT = (PFNWGLSWAPINTERVALEXTPROC)gloGetProcAddress("wglSwapIntervalEXT");
		wglGetSwapIntervalEXT = (PFNWGLGETSWAPINTERVALEXTPROC)gloGetProcAddress("wglGetSwapIntervalEXT");
#endif//WIN32
	}
}//namespace glo
