
// CFontDialog ClassView.cpp : CCFontDialogClassView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "CFontDialog Class.h"
#endif

#include "CFontDialog ClassDoc.h"
#include "CFontDialog ClassView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCFontDialogClassView

IMPLEMENT_DYNCREATE(CCFontDialogClassView, CView)

BEGIN_MESSAGE_MAP(CCFontDialogClassView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CCFontDialogClassView 构造/析构

CCFontDialogClassView::CCFontDialogClassView()
{
	// TODO: 在此处添加构造代码

}

CCFontDialogClassView::~CCFontDialogClassView()
{
}

BOOL CCFontDialogClassView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CCFontDialogClassView 绘制

void CCFontDialogClassView::OnDraw(CDC* pDC)
{
	CCFontDialogClassDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码

	//应用CFontDialog类，让用户自行选择一种字体，输出“Good programmers have sailed!”。
	CFontDialog dlg;//构造CFontDialog类对象
	CFont font;//构造CFont类对象
	LOGFONT lf;//构造字体参数结构
	dlg.DoModal();//打开对话框
	memset(&lf, 0, sizeof(LOGFONT));//将lf结构归零
	dlg.GetCurrentFont(&lf);//获取用户选择的字体参数
	VERIFY(font.CreateFontIndirect(&lf));//创造该字体

	CClientDC dc(this);
	CFont* def_font = dc.SelectObject(&font);//选取该字体
	dc.TextOut(5, 5, _T("Good programmers have sailed!"));
	dc.SelectObject(def_font);

	font.DeleteObject();//销毁该字体
}


// CCFontDialogClassView 打印

BOOL CCFontDialogClassView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CCFontDialogClassView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CCFontDialogClassView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CCFontDialogClassView 诊断

#ifdef _DEBUG
void CCFontDialogClassView::AssertValid() const
{
	CView::AssertValid();
}

void CCFontDialogClassView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCFontDialogClassDoc* CCFontDialogClassView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCFontDialogClassDoc)));
	return (CCFontDialogClassDoc*)m_pDocument;
}
#endif //_DEBUG


// CCFontDialogClassView 消息处理程序
