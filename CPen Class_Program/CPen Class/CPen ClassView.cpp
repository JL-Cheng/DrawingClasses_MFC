
// CPen ClassView.cpp : CCPenClassView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CCPenClassView ����/����

CCPenClassView::CCPenClassView()
{
	// TODO: �ڴ˴���ӹ������

}

CCPenClassView::~CCPenClassView()
{
}

BOOL CCPenClassView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨsss���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CCPenClassView ����

void CCPenClassView::OnDraw(CDC* pDC)
{
	CCPenClassDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CPen newPen;
	newPen.CreatePen(PS_DASH, 1, RGB(255, 0, 0));
	HGDIOBJ oldPen = pDC->SelectObject(newPen);
	pDC->MoveTo(100, 100);
	pDC->LineTo(500, 100);
	pDC->SelectObject(oldPen);
}


// CCPenClassView ��ӡ

BOOL CCPenClassView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CCPenClassView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CCPenClassView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CCPenClassView ���

#ifdef _DEBUG
void CCPenClassView::AssertValid() const
{
	CView::AssertValid();
}

void CCPenClassView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCPenClassDoc* CCPenClassView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCPenClassDoc)));
	return (CCPenClassDoc*)m_pDocument;
}
#endif //_DEBUG


// CCPenClassView ��Ϣ�������
