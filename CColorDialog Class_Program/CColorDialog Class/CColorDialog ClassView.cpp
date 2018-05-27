
// CColorDialog ClassView.cpp : CCColorDialogClassView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CCColorDialogClassView ����/����

CCColorDialogClassView::CCColorDialogClassView()
{
	// TODO: �ڴ˴���ӹ������

}

CCColorDialogClassView::~CCColorDialogClassView()
{
}

BOOL CCColorDialogClassView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}
	
// CCColorDialogClassView ����

void CCColorDialogClassView::OnDraw(CDC* pDC)
{
	CCColorDialogClassDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���

	//Ӧ��CColorDialog�࣬����һ��ֱ�ߡ���ɫΪ�û�����ѡ���Ҳ���Ϊ��ɫ��

	CPen newPen;//����CPen�����newPen��
	CMyColorDlg dlg;//����CMyColorDlg����dlg��
	COLORREF color;//����ѡ�����ɫ��

	dlg.m_cc.Flags |= CC_FULLOPEN | CC_RGBINIT;
	dlg.m_cc.rgbResult = RGB(255, 0, 0);//���öԻ���Ĵ򿪷�ʽ
	dlg.DoModal();//�򿪶Ի���
	dlg.OnColorOK();//��ֹ�û�ѡ���ɫ��
	color = dlg.GetColor();//��ȡ�û�ѡ�����ɫ��

	newPen.CreatePen(PS_SOLID, 10, color);//������Ӧ��ɫ�Ļ��ʡ�
	HGDIOBJ oldPen = pDC->SelectObject(newPen);//��¼ԭ�л��ʡ�
	pDC->SelectObject(newPen);
	pDC->MoveTo(100, 100);
	pDC->LineTo(600, 100);//��(100,100)��(600,100)���ߡ�
	pDC->SelectObject(oldPen);//�ָ�ԭ�л��ʡ�
}


// CCColorDialogClassView ��ӡ

BOOL CCColorDialogClassView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CCColorDialogClassView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CCColorDialogClassView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CCColorDialogClassView ���

#ifdef _DEBUG
void CCColorDialogClassView::AssertValid() const
{
	CView::AssertValid();
}

void CCColorDialogClassView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCColorDialogClassDoc* CCColorDialogClassView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCColorDialogClassDoc)));
	return (CCColorDialogClassDoc*)m_pDocument;
}
#endif //_DEBUG


// CCColorDialogClassView ��Ϣ�������
