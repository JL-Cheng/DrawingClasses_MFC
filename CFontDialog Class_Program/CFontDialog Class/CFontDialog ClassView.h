
// CFontDialog ClassView.h : CCFontDialogClassView ��Ľӿ�
//

#pragma once


class CCFontDialogClassView : public CView
{
protected: // �������л�����
	CCFontDialogClassView();
	DECLARE_DYNCREATE(CCFontDialogClassView)

// ����
public:
	CCFontDialogClassDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CCFontDialogClassView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // CFontDialog ClassView.cpp �еĵ��԰汾
inline CCFontDialogClassDoc* CCFontDialogClassView::GetDocument() const
   { return reinterpret_cast<CCFontDialogClassDoc*>(m_pDocument); }
#endif

