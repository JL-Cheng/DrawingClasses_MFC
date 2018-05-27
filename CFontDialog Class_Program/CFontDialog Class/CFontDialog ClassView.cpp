
// CFontDialog ClassView.cpp : CCFontDialogClassView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CCFontDialogClassView ����/����

CCFontDialogClassView::CCFontDialogClassView()
{
	// TODO: �ڴ˴���ӹ������

}

CCFontDialogClassView::~CCFontDialogClassView()
{
}

BOOL CCFontDialogClassView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CCFontDialogClassView ����

void CCFontDialogClassView::OnDraw(CDC* pDC)
{
	CCFontDialogClassDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���

	//Ӧ��CFontDialog�࣬���û�����ѡ��һ�����壬�����Good programmers have sailed!����
	CFontDialog dlg;//����CFontDialog�����
	CFont font;//����CFont�����
	LOGFONT lf;//������������ṹ
	dlg.DoModal();//�򿪶Ի���
	memset(&lf, 0, sizeof(LOGFONT));//��lf�ṹ����
	dlg.GetCurrentFont(&lf);//��ȡ�û�ѡ����������
	VERIFY(font.CreateFontIndirect(&lf));//���������

	CClientDC dc(this);
	CFont* def_font = dc.SelectObject(&font);//ѡȡ������
	dc.TextOut(5, 5, _T("Good programmers have sailed!"));
	dc.SelectObject(def_font);

	font.DeleteObject();//���ٸ�����
}


// CCFontDialogClassView ��ӡ

BOOL CCFontDialogClassView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CCFontDialogClassView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CCFontDialogClassView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CCFontDialogClassView ���

#ifdef _DEBUG
void CCFontDialogClassView::AssertValid() const
{
	CView::AssertValid();
}

void CCFontDialogClassView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCFontDialogClassDoc* CCFontDialogClassView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCFontDialogClassDoc)));
	return (CCFontDialogClassDoc*)m_pDocument;
}
#endif //_DEBUG


// CCFontDialogClassView ��Ϣ�������
