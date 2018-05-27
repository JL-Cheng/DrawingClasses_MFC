
// CColorDialog ClassView.h : CCColorDialogClassView ��Ľӿ�
//

#pragma once


class CCColorDialogClassView : public CView
{
protected: // �������л�����
	CCColorDialogClassView();
	DECLARE_DYNCREATE(CCColorDialogClassView)

// ����
public:
	CCColorDialogClassDoc* GetDocument() const;

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
	virtual ~CCColorDialogClassView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

class CMyColorDlg :public CColorDialog
{
public:
	CMyColorDlg() {}
	~CMyColorDlg() {}

	//OnColorOK�����������뵽��ɫ����ɫ����ɫ�༭�ؼ�����ɫ��
	//�����ɫ��BLACK����RGB��0,0,0������
	//��ǿ�Ƶ�ǰ��ɫΪ�����Ի���ʱ���ѡ�����ɫ��
	//��ɫ�Ի��򲻻�رա�
	//�û����������µ���ɫ��
	BOOL OnColorOK()
	{
		COLORREF clrref = GetColor();
		if (RGB(0, 0, 0) == clrref)
		{
			AfxMessageBox(_T("BLACK is not an acceptable color. ")
				_T("Please enter a color again"));

			// GetColor�����������ѡ�����ɫ��
			SetCurrentColor(GetColor());

			//����ر���ɫ�Ի���
			return TRUE;
		}

		//ȷ���ر���ɫ�Ի���
		return FALSE;
	}

};

#ifndef _DEBUG  // CColorDialog ClassView.cpp �еĵ��԰汾
inline CCColorDialogClassDoc* CCColorDialogClassView::GetDocument() const
   { return reinterpret_cast<CCColorDialogClassDoc*>(m_pDocument); }
#endif

