// �� MFC ���� �ҽ� �ڵ�� MFC Microsoft Office Fluent ����� �������̽�("Fluent UI")�� 
// ����ϴ� ����� ���� �ָ�, MFC C++ ���̺귯�� ����Ʈ��� ���Ե� 
// Microsoft Foundation Classes Reference �� ���� ���� ������ ���� 
// �߰������� �����Ǵ� �����Դϴ�.  
// Fluent UI�� ����, ��� �Ǵ� �����ϴ� �� ���� ��� ����� ������ �����˴ϴ�.  
// Fluent UI ���̼��� ���α׷��� ���� �ڼ��� ������ 
// http://go.microsoft.com/fwlink/?LinkId=238214.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

// SlidingPuzzleApp.h : SlidingPuzzle ���� ���α׷��� ���� �� ��� ����
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"	// �� ��ȣ�Դϴ�.


// CSlidingPuzzleApp:
// �� Ŭ������ ������ ���ؼ��� SlidingPuzzleApp.cpp�� �����Ͻʽÿ�.
//

class CSlidingPuzzleApp : public CWinAppEx
{
// �����Դϴ�.
public:
	CSlidingPuzzleApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;
	ULONG_PTR m_nGdiplusToken;	// https://msdn.microsoft.com/en-us/library/windows/desktop/aa383751(v=vs.85).aspx#ULONG_PTR

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSlidingPuzzleApp theApp;
