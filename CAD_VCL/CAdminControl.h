#pragma once
#include "resource.h"
#include "CDraw.h"
#include "CVertex.h"
#include <math.h>

#define MAX_LOADSTRING 100

class CAdminControl
{
public:
	CAdminControl(HINSTANCE hInstance);
	~CAdminControl();
private:
	// 描画クラス内の関数を使用するための変数
	CDraw draw;
	// 頂点リストのヘッド
	CVertex* vertex_head;
protected:
	// 現在のインターフェイス
	HINSTANCE hInst;
public:
	// ウィンドウの定義する関数
	void MyRegisterClass();
	// ウィンドウの生成する関数
	BOOL CreateWindowClass(int);
	// タブやキー入力などのアクションを処理する関数
	LRESULT WndProc(HWND, UINT, WPARAM, LPARAM);

	/* 課題2 AddVertex関数の作成*/
	void AddVertex(float x,float y);

	/* 課題3 DeleteVertex関数の作成*/
	void DeleteVertex();

	/* 課題ex-1 近い頂点を削除 */
	void DeleteVertex_close(int x,int y);

	/// <summary>
	/// 2頂点間の距離を算出
	/// </summary>
	/// <param name="v1">頂点1</param>
	/// <param name="v2">頂点2</param>
	/// <returns>[double]頂点間の距離</returns>
	double calcDistance(CVertex* v1, CVertex* v2);
};

