#include "DXUT.h"
#include "TextRenderer.h"

#include "../ResourceTypes/Font.h"

void TextRendererW::Initialize()
{
	Super::m_RenderType = RenderType::UI;
	Super::Initialize();
}

void TextRendererW::Update()
{
	Super::Update();
}

void TextRendererW::Release()
{
	Super::Release();
}

void TextRendererW::Render()
{
	RENDERMANAGER.SetTransformForSprite(&transform->GetWorldMatrix());
	RENDERMANAGER.Draw(m_pFont, m_sContext, m_Color);
}

void TextRendererW::Set(const string& fontKey, int fontSize, const std::wstring& context, Color color)
{
	m_pFont		= Font::Load(fontKey, fontSize);
	m_sContext	= context;
	m_Color		= color;
}

void TextRendererW::SetContext(const std::wstring& context)
{
	m_sContext = context;
}

void TextRendererA::Initialize()
{
	Super::m_RenderType = RenderType::UI;
	Super::Initialize();
}

void TextRendererA::Update()
{
	Super::Update();
}

void TextRendererA::Release()
{
	Super::Release();
}

void TextRendererA::Render()
{
	RENDERMANAGER.SetTransformForSprite(&transform->GetWorldMatrix());
	RENDERMANAGER.Draw(m_pFont, m_sContext, m_Color);
}

void TextRendererA::Set(const string& fontKey, int fontSize, const std::string& context, Color color)
{
	m_pFont = Font::Load(fontKey, fontSize);
	m_sContext = context;
	m_Color = color;
}

void TextRendererA::SetContext(const std::string& context)
{
	m_sContext = context;
}
