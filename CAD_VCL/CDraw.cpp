#include "CDraw.h"

// •`‰æƒƒCƒ“ŠÖ”
void CDraw::Draw(HDC hdc, CVertex* vertex_head)
{
    if (vertex_head != NULL) {
        d_hdc = hdc;
        /* ‰Û‘è1 ƒŠƒXƒg‚Ì“à—e‚ð•`‰æ‚·‚é */
        for(CVertex* currentV = vertex_head;currentV != NULL;currentV = currentV->GetNext()) {
            /*’¸“_‚Ì•`‰æ*/
            DrawPoint(currentV);
            
            /*—Åü‚Ì•`‰æ*/
            if(currentV->GetNext() != NULL)
                DrawLine(currentV, currentV->GetNext());
        }
    }
}

// “_‚Ì•`‰æ
void CDraw::DrawPoint(CVertex* vertex)
{
    // “_‚Ì‘å‚«‚³
    int rad = 5;
    // F
    COLORREF col = RGB(0, 0, 0);

    // “h‚è‚Â‚Ô‚µ‚ÌÝ’è
    SelectObject(d_hdc, CreateSolidBrush(col));

    // “_‚Ì•`‰æ
    Ellipse(d_hdc, vertex->GetX() - rad, vertex->GetY() - rad, vertex->GetX() + rad, vertex->GetY() + rad);
}

// ü‚Ì•`‰æ
void CDraw::DrawLine(CVertex* start, CVertex* end)
{
    // ü‚Ì‘¾‚³
    int width = 2;
    // F
    COLORREF col = RGB(0, 0, 0);

    // ‘¾‚³‚Æü‚Ì‘Ž®Ý’è
    SelectObject(d_hdc, CreatePen(PS_SOLID, width, col));

    // Žn“_
    MoveToEx(d_hdc, start->GetX(), start->GetY(), NULL);
    
    // I“_
    LineTo(d_hdc, end->GetX(), end->GetY());
}