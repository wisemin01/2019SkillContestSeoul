#include "DXUT.h"
#include "LineRenderer.h"

LineRenderer::LineRenderer(LineInfo info, ...)
{
	va_list ap;

	Vector2* list = new Vector2[info.lineCount];

	va_start(ap, info);

	for (int i = 0; i < info.lineCount; i++)
	{
		list[i] = va_arg(ap, Vector2);
	}

	va_end(ap);

	m_pLineArr = list;
	m_iCount = info.lineCount;
	m_iLineWidth = info.width;
	m_Color = info.color;
}

void LineRenderer::Initialize()
{
	m_RenderType = RenderType::UI;
	Super::Initialize();
}

void LineRenderer::Update()
{
	Super::Update();
}

void LineRenderer::Release()
{
	SAFE_DELETE_ARRAY(m_pLineArr);
	Super::Release();
}

void LineRenderer::Render()
{
	if (m_pLineArr)
	{
		RENDERMANAGER.SetTransformForSprite(&transform->GetWorldMatrix());
		RENDERMANAGER.DrawLine(m_pLineArr, m_iCount, m_iLineWidth, m_Color);
	}
}

void LineRenderer::Set(LineInfo info, ...)
{
	va_list ap;

	Vector2* list = new Vector2[info.lineCount];

	va_start(ap, info);

	for (int i = 0; i < info.lineCount; i++)
	{
		list[i] = va_arg(ap, Vector2);
	}

	va_end(ap);

	m_pLineArr = list;
	m_iCount = info.lineCount;
	m_iLineWidth = info.width;
	m_Color = info.color;
}