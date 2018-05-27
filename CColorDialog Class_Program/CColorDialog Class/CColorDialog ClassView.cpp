
// CColorDialog ClassView.cpp : CCColorDialogClassView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "CColorDialog Class.h"
#endif

#include "CColorDialog ClassDoc.h"
#include "CColorDialog ClassView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCColorDialogClassView

IMPLEMENT_DYNCREATE(CCColorDialogClassView, CView)

BEGIN_MESSAGE_MAP(CCColorDialogClassView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CCColorDialogClassView 构造/析构

CCColorDialogClassView::CCColorDialogClassView()
{
	// TODO: 在此处添加构造代码

}

CCColorDialogClassView::~CCColorDialogClassView()
{
}

BOOL CCColorDialogClassView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}
	
// CCColorDialogClassView 绘制

void CCColorDialogClassView::OnDraw(CDC* pDC)
{
	CCColorDialogClassDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码

	//应用CColorDialog类，绘制一条直线。颜色为用户自行选择，且不能为黑色。

	CPen newPen;//构造CPen类对象newPen。
	CMyColorDlg dlg;//构造CMyColorDlg对象dlg。
	COLORREF color;//画笔选择的颜色。

	dlg.m_cc.Flags |= CC_FULLOPEN | CC_RGBINIT;
	dlg.m_cc.rgbResult = RGB(255, 0, 0);//设置对话框的打开方式
	dlg.DoModal();//打开对话框。
	dlg.OnColorOK();//禁止用户选择黑色。
	color = dlg.GetColor();//获取用户选择的颜色。

	newPen.CreatePen(PS_SOLID, 10, color);//创造相应颜色的画笔。
	HGDIOBJ oldPen = pDC->SelectObject(newPen);//记录原有画笔。
	pDC->SelectObject(newPen);
	pDC->MoveTo(100, 100);
	pDC->LineTo(600, 100);//从(100,100)向(600,100)画线。
	pDC->SelectObject(oldPen);//恢复原有画笔。
}


// CCColorDialogClassView 打印

BOOL CCColorDialogClassView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CCColorDialogClassView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CCColorDialogClassView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CCColorDialogClassView 诊断

#ifdef _DEBUG
void CCColorDialogClassView::AssertValid() const
{
	CView::AssertValid();
}

void CCColorDialogClassView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCColorDialogClassDoc* CCColorDialogClassView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCColorDialogClassDoc)));
	return (CCColorDialogClassDoc*)m_pDocument;
}
#endif //_DEBUG


// CCColorDialogClassView 消息处理程序
