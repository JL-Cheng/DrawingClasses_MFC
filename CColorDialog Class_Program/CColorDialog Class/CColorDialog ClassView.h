
// CColorDialog ClassView.h : CCColorDialogClassView 类的接口
//

#pragma once


class CCColorDialogClassView : public CView
{
protected: // 仅从序列化创建
	CCColorDialogClassView();
	DECLARE_DYNCREATE(CCColorDialogClassView)

// 特性
public:
	CCColorDialogClassDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CCColorDialogClassView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

class CMyColorDlg :public CColorDialog
{
public:
	CMyColorDlg() {}
	~CMyColorDlg() {}

	//OnColorOK函数覆盖输入到红色，绿色和蓝色编辑控件的颜色。
	//如果颜色是BLACK（即RGB（0,0,0）），
	//则强制当前颜色为创建对话框时最初选择的颜色。
	//颜色对话框不会关闭。
	//用户可以输入新的颜色。
	BOOL OnColorOK()
	{
		COLORREF clrref = GetColor();
		if (RGB(0, 0, 0) == clrref)
		{
			AfxMessageBox(_T("BLACK is not an acceptable color. ")
				_T("Please enter a color again"));

			// GetColor（）返回最初选择的颜色。
			SetCurrentColor(GetColor());

			//不会关闭颜色对话框。
			return TRUE;
		}

		//确定关闭颜色对话框。
		return FALSE;
	}

};

#ifndef _DEBUG  // CColorDialog ClassView.cpp 中的调试版本
inline CCColorDialogClassDoc* CCColorDialogClassView::GetDocument() const
   { return reinterpret_cast<CCColorDialogClassDoc*>(m_pDocument); }
#endif

