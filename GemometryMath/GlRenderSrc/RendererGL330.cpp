#include "stdafx.h"
#include "RendererGL330.h"

#if defined( WIN32)
#ifdef RENDERAPI_GL330
#include"RenderContextWin32.h"
#else
#endif
#endif
#define test


// Index to bind the attributes to vertex shaders
const int VERTEX_ARRAY = 0;
const int NORMAL_ARRAY = 1;
const int TEXCOORD_ARRAY = 2;
// Size of the texture we create
#define TEX_SIZE		128

RendererGL* GetRenderer()
{
	return static_cast<RendererGL*>(m_EngineEnvironment->pRenderer);
}

RendererGL::RendererGL()
{
}

HWND RendererGL::Init(ISystemInitInfo& sii)
{
	m_pDeviceContext = new DeviceRenderContext;

	m_hWnd = m_pDeviceContext->InitDevice(sii);

	if (m_hWnd == NULL)
	{
		return NULL;
	}

#ifdef RENDERAPI_GLES2
#endif
#ifdef RENDERAPI_GL330
	gl::init();
#endif

	glGetIntegerv(GL_FRAMEBUFFER_BINDING, &m_backBufferFBO);

	glGenRenderbuffers(1, &m_rtFBO);
	glGenFramebuffers(1, &m_drtFBO);

	SetCurrContent(m_hWnd, 0, 0, sii.fWidth, sii.fHeight);

	LogWarning(_T("device loaded."));

	// sets the clear color;

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	//glEnable(GL_DEPTH_TEST);
	//glDepthFunc(GL_LEQUAL);
	//glClearDepth(1.0f);


#ifdef test

	// test 
	const char *vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";
	const char *fragmentShaderSource = "#version 330 core\n"
		"out vec4 fragColor;\n"
		"void main()\n"
		"{\n"
		"   fragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
		"}\n\0";

	int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	// check for shader compile errors
	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		//std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	// fragment shader
	int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	// check for shader compile errors
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		//std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	// link shaders
	 shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	// check for linking errors
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		//std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	float vertices[] = {
		-0.2f, -0.2f, 0.0f, // left  
		0.2f, -0.2f, 0.0f, // right 
		0.0f, 0.2f, 0.0f  // top   
	};

	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	glBindVertexArray(0);
#endif
	return m_hWnd;

}

RendererGL::~RendererGL()
{
}

void RendererGL::Destroy()
{

}
IRenderSequence* RendererGL::SwapRenderSequence()
{
	return NULL;
}
IRenderSequence* RendererGL::GetRenderSequence()
{
	return NULL;
}
void RendererGL::CleanRenderSequence()
{

}
bool  RendererGL::StartRender()
{
#ifdef test
	glClearColor(0.0f, 0.0f, 0.0f, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(shaderProgram);
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 3);
#endif
	m_pDeviceContext->SwapBuffer();
	return false;
}
bool  RendererGL::EndRender()
{
	return false;
}
void RendererGL::SkipOnFrame(int frameCount)
{

}
void RendererGL::SetSunDir(const KunSen::Vec3f& lightDir)
{
	
}
uint32 RendererGL::GetScreenHeight(bool forceOrigin)
{
	return	 0;
}
uint32 RendererGL::GetScreenWidth(bool forceOrigin)
{
	return	0;
}
void RendererGL::SetCurrContent(HWND hWnd, uint32 posX, uint32 posY, uint32 width, uint32 height, bool fullScreen)
{}
HWND RendererGL::GetWindowHwnd()
{
	return	NULL;
}
ERenderAPI RendererGL::GetRenderAPI()
{
	return OPENGL;
}
bool RendererGL::FullScreenMode()
{
	return	 true;
}
