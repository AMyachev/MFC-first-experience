#pragma once

#include "mfc.h"

#define IDC_BUTTON_DEFAULT_MESSAGE 100
#define IDC_BUTTON_CLEAR_MESSAGE 101
#define IDC_BUTTON_SHOW_MESSAGE 102
#define IDC_BUTTON_RUN_PROGRAM 103
#define IDC_CHECK_BOX_ENABLE_MESSAGE 104
#define IDC_CHECK_BOX_ENABLE_PROGRAM 105
#define IDC_CHECK_BOX_SHOW_MESSAGE 106
#define IDC_CHECK_BOX_SHOW_PROGRAM 107
#define IDC_BUTTON_EXIT 108
#define IDC_EDIT_MESSAGE 109
#define IDC_LIST_BOX 110
#define IDC_GROUP_BOX_ENABLE 111
#define IDC_GROUP_BOX_SHOW 112


class CMainWnd : public CFrameWnd
{
public:
	CMainWnd();
	afx_msg void OnAllBtnsClick(unsigned int);
	void SetClientFont(CString Typeface,
		int Size, BOOL Bold, BOOL Italic);
	~CMainWnd();
private:
	CStatic* HeadStatic;
	CStatic* EnterMessageStatic;
	CStatic* RunProgramStatic;
	CButton* BttDefaultMessage;
	CButton* BttClearMessage;
	CButton* BttShowMessage;
	CButton* BttRunProgram;
	CButton* CheckBoxEnableMessage;
	CButton* CheckBoxEnableProgram;
	CButton* CheckBoxShowMessage;
	CButton* CheckBoxShowProgram;
	CButton* BttExit;
	CButton* GroupBoxEnable;
	CButton* GroupBoxShow;
	CEdit* Edit;
	CComboBox* ComboBox;
	CFont* m_pFont;
	DECLARE_MESSAGE_MAP();
};
