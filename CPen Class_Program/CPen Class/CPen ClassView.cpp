
// CPen ClassView.cpp : CCPenClassView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "CPen Class.h"
#endif

#include "CPen ClassDoc.h"
#include "CPen ClassView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCPenClassView

IMPLEMENT_DYNCREATE(CCPenClassView, CView)

BEGIN_MESSAGE_MAP(CCPenClassView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CCPenClassView 构造/析构

CCPenClassView::CCPenClassView()
{
	// TODO: 在此处添加构造代码

}

CCPenClassView::~CCPenClassView()
{
}

BOOL CCPenClassView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通sss过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CCPenClassView 绘制

void CCPenClassView::OnDraw(CDC* pDC)
{
	CCPenClassDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CPen newPen;
	newPen.CreatePen(PS_DASH, 1, RGB(255, 0, 0));
	HGDIOBJ oldPen = pDC->SelectObject(newPen);
	pDC->MoveTo(100, 100);
	pDC->LineTo(500, 100);
	pDC->SelectObject(oldPen);
}


// CCPenClassView 打印

BOOL CCPenClassView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CCPenClassView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CCPenClassView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CCPenClassView 诊断

#ifdef _DEBUG
void CCPenClassView::AssertValid() const
{
	CView::AssertValid();
}

void CCPenClassView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCPenClassDoc* CCPenClassView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCPenClassDoc)));
	return (CCPenClassDoc*)m_pDocument;
}
#endif //_DEBUG


// CCPenClassView 消息处理程序
