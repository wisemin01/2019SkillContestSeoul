#pragma once
#include "Renderer.h"

class Font;

class TextRendererW :
	public Renderer
{
	COMPONENT_HEAD(TextRendererW, Renderer, false)
private:
	std::wstring m_sContext;
	Color m_Color = Color::White;

	Font* m_pFont = nullptr;
public:

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Release() override;

	virtual void Render();

	void Set(const string& fontKey, int fontSize, const std::wstring& context, Color color = Color::White);
	void SetContext(const std::wstring& context);

	void SetColor(const Color& color) { m_Color = color; }
};


class TextRendererA :
	public Renderer
{
	COMPONENT_HEAD(TextRendererA, Renderer, false)

private:
	std::string m_sContext;
	Color m_Color = Color::White;

	Font* m_pFont = nullptr;
public:

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Release() override;

	virtual void Render();

	void Set(const string& fontKey, int fontSize, const std::string& context, Color color = Color::White);
	void SetContext(const std::string& context);

	void SetColor(const Color& color) { m_Color = color; }
};

#ifdef UNICODE
using TextRenderer = TextRendererW;
#else
using TextRenderer = TextRendererA;
#endif