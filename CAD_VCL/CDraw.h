#pragma once
#include <Windows.h>
#include "CVertex.h"

class CDraw
{
private:
	// •`‰æ—Ìˆæî•ñ
	HDC d_hdc;
	// “_‚Ì•`‰æ
	void DrawPoint(CVertex* vertex);
	// ü‚Ì•`‰æ
	void DrawLine(CVertex* start, CVertex* end);

public:
	// •`‰æƒƒCƒ“ŠÖ”
	void Draw(HDC hdc, CVertex* vertex_head);
};

