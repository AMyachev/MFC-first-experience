#include "main_wnd.h"
#include "resource.h"
#include <string>


BEGIN_MESSAGE_MAP(CMainWnd, CFrameWnd)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BUTTON_DEFAULT_MESSAGE, IDC_BUTTON_EXIT, OnAllBtnsClick)
END_MESSAGE_MAP()

void CMainWnd::SetClientFont(CString Typeface,
	int Size, BOOL Bold, BOOL Italic)
{
	CWindowDC winDC(this);
	int pixelsPerInch = winDC.GetDeviceCaps(LOGPIXELSY);
	int fontHeight = -MulDiv(Size, pixelsPerInch, 72);
	int Weight = FW_NORMAL;
	if (Bold)
		Weight = FW_BOLD;
	delete m_pFont;
	m_pFont = new CFont;
	m_pFont->CreateFont(fontHeight, 0, 0, 0, Weight, Italic, 0, 0,
		DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, PROOF_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE, Typeface);
}

CMainWnd::CMainWnd()
{
	Create(NULL, L"Visual C++ Control", WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, CRect(CPoint(540, 270), CPoint(1380, 750)),
		NULL, NULL);// Create window
	this->SetClientFont("Times New Roman", 12, FALSE, FALSE);

	SetIcon(AfxGetApp()->LoadIcon(IDI_ICON1), TRUE);

	HeadStatic = new CStatic();
	if (HeadStatic != NULL) {
		HeadStatic->Create(L"This is an example of an Application using a number of controls", WS_CHILD | WS_VISIBLE | SS_CENTER,
			CRect(280, 10, 560, 50), this);
		HeadStatic->SetFont(m_pFont);
	}

	EnterMessageStatic = new CStatic();
	if (EnterMessageStatic != NULL) {
		EnterMessageStatic->Create(L"Enter a message: ", WS_CHILD | WS_VISIBLE | SS_CENTER,
			CRect(120, 70, 240, 100), this);
		EnterMessageStatic->SetFont(m_pFont);
	}

	RunProgramStatic = new CStatic();
	if (RunProgramStatic != NULL) {
		RunProgramStatic->Create(L"Run a program: ", WS_CHILD | WS_VISIBLE | SS_CENTER,
			CRect(100, 170, 220, 200), this);
		RunProgramStatic->SetFont(m_pFont);
	}

	BttDefaultMessage = new CButton();
	if (BttDefaultMessage != NULL) {
		BttDefaultMessage->Create(L"Default Message", WS_CHILD | WS_VISIBLE | SS_CENTER,
			CRect(250, 110, 400, 150), this, IDC_BUTTON_DEFAULT_MESSAGE);
		BttDefaultMessage->SetFont(m_pFont);
	}

	BttClearMessage = new CButton();
	if (BttClearMessage != NULL) {
		BttClearMessage->Create(L"Clear Message", WS_CHILD | WS_VISIBLE | SS_CENTER,
			CRect(410, 110, 560, 150), this, IDC_BUTTON_CLEAR_MESSAGE);
		BttClearMessage->SetFont(m_pFont);
	}

	BttShowMessage = new CButton();
	if (BttShowMessage != NULL) {
		BttShowMessage->Create(L"Show Message", WS_CHILD | WS_VISIBLE | SS_CENTER,
			CRect(620, 70, 720, 100), this, IDC_BUTTON_SHOW_MESSAGE);
		BttShowMessage->SetFont(m_pFont);
	}

	BttRunProgram = new CButton();
	if (BttRunProgram != NULL) {
		BttRunProgram->Create(L"Run Program", WS_CHILD | WS_VISIBLE | SS_CENTER,
			CRect(620, 170, 720, 200), this, IDC_BUTTON_RUN_PROGRAM);
		BttRunProgram->SetFont(m_pFont);
	}

	BttExit = new CButton();
	if (BttExit != NULL) {
		BttExit->Create(L"Exit", WS_CHILD | WS_VISIBLE | SS_CENTER,
			CRect(350, 370, 450, 400), this, IDC_BUTTON_EXIT);
		BttExit->SetFont(m_pFont);
	}

	Edit = new CEdit();
	if (Edit != NULL) {
		Edit->Create(WS_CHILD | WS_VISIBLE | WS_BORDER,
			CRect(250, 70, 560, 100), this, IDC_EDIT_MESSAGE);
		Edit->SetFont(m_pFont);
		Edit->SetWindowTextW(L"Place a message here.");
	}

	ComboBox = new CComboBox();
	if (ComboBox != NULL) {
		ComboBox->Create(CBS_DROPDOWN | CBS_NOINTEGRALHEIGHT | WS_CHILD | WS_VISIBLE | WS_BORDER,
			CRect(250, 170, 560, 250), this, IDC_LIST_BOX);
		ComboBox->AddString(L"calc");
		ComboBox->AddString(L"notepad");
		ComboBox->AddString(L"winmine");
	}

	CheckBoxEnableMessage = new CButton();
	if (CheckBoxEnableMessage != NULL) {
		CheckBoxEnableMessage->Create(L"Enable Message Action", WS_VISIBLE | BS_AUTOCHECKBOX | WS_CHILD,
			CRect(110, 280, 290, 300), this, IDC_CHECK_BOX_ENABLE_MESSAGE);
		CheckBoxEnableMessage->SetFont(m_pFont);
		CheckBoxEnableMessage->SetCheck(TRUE);
	}

	CheckBoxEnableProgram = new CButton();
	if (CheckBoxEnableProgram != NULL) {
		CheckBoxEnableProgram->Create(L"Enable Program Action", WS_VISIBLE | BS_AUTOCHECKBOX | WS_CHILD,
			CRect(110, 310, 290, 330), this, IDC_CHECK_BOX_ENABLE_PROGRAM);
		CheckBoxEnableProgram->SetFont(m_pFont);
		CheckBoxEnableProgram->SetCheck(TRUE);
	}

	GroupBoxEnable = new CButton();
	if (GroupBoxEnable != NULL) {
		GroupBoxEnable->Create(L"Enable actions", WS_VISIBLE | BS_GROUPBOX | WS_CHILD,
			CRect(100, 250, 300, 340), this, IDC_GROUP_BOX_ENABLE);
		GroupBoxEnable->SetFont(m_pFont);
	}

	CheckBoxShowMessage = new CButton();
	if (CheckBoxShowMessage != NULL) {
		CheckBoxShowMessage->Create(L"Show Message Action", WS_VISIBLE | BS_AUTOCHECKBOX | WS_CHILD,
			CRect(510, 280, 690, 300), this, IDC_CHECK_BOX_SHOW_MESSAGE);
		CheckBoxShowMessage->SetFont(m_pFont);
		CheckBoxShowMessage->SetCheck(TRUE);
	}

	CheckBoxShowProgram = new CButton();
	if (CheckBoxShowProgram != NULL) {
		CheckBoxShowProgram->Create(L"Show Program Action", WS_VISIBLE | BS_AUTOCHECKBOX | WS_CHILD,
			CRect(510, 310, 690, 330), this, IDC_CHECK_BOX_SHOW_PROGRAM);
		CheckBoxShowProgram->SetFont(m_pFont);
		CheckBoxShowProgram->SetCheck(TRUE);
	}

	GroupBoxShow = new CButton();
	if (GroupBoxShow != NULL) {
		GroupBoxShow->Create(L"Show actions", WS_VISIBLE | BS_GROUPBOX | WS_CHILD,
			CRect(500, 250, 700, 340), this, IDC_GROUP_BOX_SHOW);
		GroupBoxShow->SetFont(m_pFont);
	}
}

CMainWnd::~CMainWnd()
{
	if (HeadStatic != NULL) delete HeadStatic;
	if (EnterMessageStatic != NULL) delete EnterMessageStatic;
	if (RunProgramStatic != NULL) delete RunProgramStatic;
	if (BttDefaultMessage != NULL) delete BttDefaultMessage;
	if (Edit != NULL) delete Edit;
	if (BttClearMessage != NULL) delete BttClearMessage;
	if (BttShowMessage != NULL) delete BttShowMessage;
	if (BttRunProgram != NULL) delete BttRunProgram;
	if (BttExit != NULL) delete BttExit;
	if (ComboBox != NULL) delete ComboBox;
	if (GroupBoxEnable != NULL) delete GroupBoxEnable;
	if (GroupBoxShow != NULL) delete GroupBoxShow;
	if (CheckBoxEnableMessage != NULL) delete CheckBoxEnableMessage;
	if (CheckBoxEnableProgram != NULL) delete CheckBoxEnableProgram;
	if (CheckBoxShowMessage != NULL) delete CheckBoxShowMessage;
	if (CheckBoxShowProgram != NULL) delete CheckBoxShowProgram;
	if (m_pFont != NULL) delete m_pFont;
}

void CMainWnd::OnAllBtnsClick(unsigned int BttId) {
	CString temp_str;
	std::string str;
	switch (BttId) {
	case IDC_BUTTON_DEFAULT_MESSAGE:
		Edit->SetWindowTextW(L"Enter a message here.");
		break;
	case IDC_BUTTON_CLEAR_MESSAGE:
		Edit->SetWindowTextW(L"");
		break;
	case IDC_BUTTON_SHOW_MESSAGE:
		Edit->GetWindowTextW(temp_str);
		AfxMessageBox(temp_str);
		break;
	case IDC_BUTTON_RUN_PROGRAM:
		ComboBox->GetWindowTextW(temp_str);
		for (int i = 0; i < temp_str.GetLength(); ++i) {
			str.push_back(temp_str[i]);
		}
		WinExec(str.c_str(), 1);
		break;
	case IDC_CHECK_BOX_ENABLE_MESSAGE:
		if (CheckBoxEnableMessage->GetCheck() == TRUE) {
			EnterMessageStatic->EnableWindow(TRUE);
			BttClearMessage->EnableWindow(TRUE);
			BttDefaultMessage->EnableWindow(TRUE);
			BttShowMessage->EnableWindow(TRUE);
			Edit->EnableWindow(TRUE);
		}
		else {
			EnterMessageStatic->EnableWindow(FALSE);
			Edit->EnableWindow(FALSE);
			BttClearMessage->EnableWindow(FALSE);
			BttDefaultMessage->EnableWindow(FALSE);
			BttShowMessage->EnableWindow(FALSE);
		}
		break;
	case IDC_CHECK_BOX_ENABLE_PROGRAM:
		if (CheckBoxEnableProgram->GetCheck() == TRUE) {
			RunProgramStatic->EnableWindow(TRUE);
			ComboBox->EnableWindow(TRUE);
			BttRunProgram->EnableWindow(TRUE);
		}
		else {
			RunProgramStatic->EnableWindow(FALSE);
			ComboBox->EnableWindow(FALSE);
			BttRunProgram->EnableWindow(FALSE);
		}
		break;
	case IDC_CHECK_BOX_SHOW_MESSAGE:
		if (CheckBoxShowMessage->GetCheck() == TRUE) {
			EnterMessageStatic->ShowWindow(TRUE);
			BttClearMessage->ShowWindow(TRUE);
			BttDefaultMessage->ShowWindow(TRUE);
			BttShowMessage->ShowWindow(TRUE);
			Edit->ShowWindow(TRUE);
			CheckBoxEnableMessage->ShowWindow(TRUE);
		}
		else {
			EnterMessageStatic->ShowWindow(FALSE);
			BttClearMessage->ShowWindow(FALSE);
			BttDefaultMessage->ShowWindow(FALSE);
			BttShowMessage->ShowWindow(FALSE);
			Edit->ShowWindow(FALSE);
			CheckBoxEnableMessage->ShowWindow(FALSE);
		}
		break;
	case IDC_CHECK_BOX_SHOW_PROGRAM:
		if (CheckBoxShowProgram->GetCheck() == TRUE) {
			RunProgramStatic->ShowWindow(TRUE);
			ComboBox->ShowWindow(TRUE);
			BttRunProgram->ShowWindow(TRUE);
			CheckBoxEnableProgram->ShowWindow(TRUE);
		}
		else {
			RunProgramStatic->ShowWindow(FALSE);
			ComboBox->ShowWindow(FALSE);
			BttRunProgram->ShowWindow(FALSE);
			CheckBoxEnableProgram->ShowWindow(FALSE);
		}
		break;
	case IDC_BUTTON_EXIT:
		DestroyWindow();
	}
}