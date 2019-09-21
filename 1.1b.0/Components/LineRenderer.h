#pragma once
#include "Renderer.h"

struct LineInfo;

class LineRenderer :
	public Renderer
{
	COMPONENT_HEAD(LineRenderer, Renderer, false)
private:
	Vector2*	m_pLineArr = nullptr;
	Color		m_Color = Color::White;
	int			m_iCount = 0;
	int			m_iLineWidth = 10;
public:
	LineRenderer() {}
	LineRenderer(LineInfo info, ...);

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Release() override;

	virtual void Render();

	void Set(LineInfo info, ...);
};

struct LineInfo
{
	int width = 0;
	int lineCount = 0;
	Color color = Color::White;

	LineInfo(int width, int count, Color color = Color::White)
		: width(width), lineCount(count), color(color) {}
};