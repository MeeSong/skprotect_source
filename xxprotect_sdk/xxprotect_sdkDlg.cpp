﻿
// xxprotect_sdkDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "xxprotect_sdk.h"
#include "xxprotect_sdkDlg.h"
#include "afxdialogex.h"
#include "sdk.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CxxprotectsdkDlg 对话框


CProtect app_protect;
CxxprotectsdkDlg::CxxprotectsdkDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_XXPROTECT_SDK_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CxxprotectsdkDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CxxprotectsdkDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CxxprotectsdkDlg 消息处理程序

BOOL CxxprotectsdkDlg::OnInitDialog()
{
        //99.8 VM start
        if(!app_protect.protect_process()) {
          MessageBox(L"init protect error", nullptr, 0);
          ExitProcess(0);
        }
        //99.8 VM over
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CxxprotectsdkDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CxxprotectsdkDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



BOOL CxxprotectsdkDlg::DestroyWindow()
{
  // TODO: 在此添加专用代码和/或调用基类
  app_protect.unprotect_process();
  return CDialogEx::DestroyWindow();
}
