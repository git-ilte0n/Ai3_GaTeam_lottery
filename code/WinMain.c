#define _CRT_SECURE_NO_WARNINGS  
#include <windows.h>
#include <stdio.h>
#include <time.h>
#include "resource.h"
#include<stdlib.h>
//������ �����
#include "BJY.h"
#include "SBG.h"
#include "YYG.h"
#include "SSS.h"
#include "AUT.h"


//�Լ������� 125��������

//��¹��� 180�������� �ֽ��ϴ�

//���� �ϰ����� ���� ������ �ּ���



/******************************************************************************
*����		:���� �Ǵ� A��
���α׷���	:Ai3_GaTeam_lottery
*����		:�ζ� ��ȣ�� �����ϴ� ���α׷��Դϴ�.
*�ּ��ۼ���	:����ȯ
*����		:0.9
*������		:����ȯ ������ �ۼ��� �ź��� ������
*��������	:2021-8-23 18:00
*�ϼ�����	:��������
*
* WinMain.c	:
		�ۼ���	:	����ȯ
		���	:winapi�� ������� ���μҽ��Դϴ�.
*				 �� ����κ��� �˰����� �޾ƿ�
				 ȭ�鿡 ����ϴ� �ҽ��Դϴ�.

*BJY.h
		�ۼ���	:	������
		���	:�������� ��µ� ��ȣ�� ¦���̰ų� Ȧ���϶�
*				 ������ϴ� �˰����� ���� �ڵ��Դϴ�.
*
*SBG.h
		�ۼ���	:	�ź���
				���:�������� ����� �Ǵ��� �������� ����3��
*				 �̻��϶� ������� ���ִ� �˰����Դϴ�.
*
*SSS.h
		�ۼ���	:	�ۼ���
		���	:��÷�̷��� ���� ��ȣ�� �����ͺ��̽��� ���
*				 �������� ����Ҷ� �ش� ��ȣ�� �����ϴ� �˰�
*				 ���� �ڵ� �Դϴ�.
*
*YYG.h
		�ۼ���	:	������
		���	:��µ� ���ǹ�ȣ�߿� �����ڸ��� �� (1~9)��
*				 �������� �����ÿ� �ش� ��ȣ�� ����� �ٽ�
*				 ������ִ� �˰����Դϴ�.
*
* AUTO.h
		:�ۼ��� :https://blog.naver.com/hhhighhh/220742413075
*		:���	:���� ���ǿ����ҽ��� ���� �ڵ��̸� ���ڵ带 �����Ͽ�
*				 �˰����� �����Ͽ����ϴ�.
*******************************************************************************/


/*******************************************************************************
* ó������ ����� �; ���ϰ� ������ gui���α׷��Դϴ�.
* �Ⱦ��̴� �ڵ�,����,����ȭ,���İ�Ƽ��� ,�������� �����ϴ�.
* �������� ���� ���ϴ� �˰����� ����� �������� �ɼ� ��µ��� �����Ͽ��µ�
* �����Ҷ� ���� ���� �����ü��ۿ� ���� ���α׷��ۿ� ������ �ƽ����ϴ�.*
 *******************************************************************************/





LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("Ai3_A�� ���� ���α׷�");

//ȭ�� �߾������Լ�
void PlaceInCenterOfScreen(HWND window, DWORD style, DWORD exStyle)
{
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);

	RECT clientRect;
	GetClientRect(window, &clientRect);

	int clientWidth = clientRect.right - clientRect.left;
	int clientHeight = clientRect.bottom - clientRect.top;

	SetWindowPos(window, NULL,
		screenWidth / 2 - clientWidth / 2,
		screenHeight / 2 - clientHeight / 2,
		clientWidth, clientHeight, 0
	);
}//ȭ�� �߾�����


//win32 �����Լ�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance
	, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;

	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;


	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(hInstance, IDI_ICON2);//����� ������
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = (WNDPROC)WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MY_MENU);
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	hWnd = CreateWindow(
		lpszClass,
		lpszClass,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		(HMENU)NULL,
		hInstance,
		NULL);
	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, 0, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	int answer = 0;//����
	OPENFILENAME SFN;
	HDC hdc, MemDC;
	PAINTSTRUCT ps;
	HBITMAP MyBitmap, OldBitmap;
	CHOOSEFONT		FONT;
	static COLORREF fColor;
	HFONT			hFont, OldFont;
	static LOGFONT	LogFont;


	//��ŷ�� ���� ���� �����ϴ°�--start
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	int AUTO_NUM = 6;

	//BJY-start
	BJY_main();
	int BJY_[6];
	for (int i = 0; i < 6; i++) {
		BJY_[i] = BJYlottonum[i];
	}
	//BJY-endl
	//SBG-start
	SBG_main();
	int SBG_[6];
	for (int i = 0; i < 6; i++) {
		SBG_[i] = SBGlottonum[i];
	}
	//SBG-endl
	//YYG-start
	YYG_main();
	int YYG_[6];
	for (int i = 0; i < 6; i++) {
		YYG_[i] = YYG_lottonum[i];
	}
	//YYG-endl
	//SSS
	SSS_main();
	int SSS_[6];
	for (int i = 0; i < 6; i++) {
		SSS_[i] = YYG_lottonum[i];
	}
	//SSS
	//AUTO

	//AUTTO_main();
	//int AUT_[6];
	//for (int i = 0; i < 6; i++) {
	//	AUT_[i] = AUT_lottonum[i];
	//}

	/*
	for (int i=0; AUT_[i]||SSS_[i]||YYG_[i]||SBG_[i]||BJY_[i];i++)
	{
			BJY_main();
			BJY_[i] = BJYlottonum[i];

			SBG_main();
			SBG_[i] = SBGlottonum[i];

			YYG_main();
			YYG_[i] = YYG_lottonum[i];
			SSS_main();
			SSS_[i] = YYG_lottonum[i];
			AUTTO_main();
			AUT_[i] = AUT_lottonum[i];
			if (i == 4)i = 0;
	}
	*/
	//AUTO


	//��ŷ�� ���� ���� �����ϴ°�--end
	AddFontResource("NanumGothicLight.ttf");
	LOGFONT logFont;
	static HFONT s_hFont = (HFONT)NULL;
	NONCLIENTMETRICS nonClientMetrics;



	ZeroMemory(&nonClientMetrics, sizeof(NONCLIENTMETRICS));
	switch (iMessage) {
	case WM_CREATE:
		PlaceInCenterOfScreen(hWnd, WS_OVERLAPPEDWINDOW, WS_EX_APPWINDOW | WS_EX_WINDOWEDGE);


		break;

	case WM_GETMINMAXINFO:
		((MINMAXINFO*)lParam)->ptMaxTrackSize.x = 480;
		((MINMAXINFO*)lParam)->ptMaxTrackSize.y = 720;
		((MINMAXINFO*)lParam)->ptMinTrackSize.x = 480;
		((MINMAXINFO*)lParam)->ptMinTrackSize.y = 720;
		return FALSE;
	case WM_PAINT:
		ZeroMemory(&logFont, sizeof(LOGFONT));
		hdc = BeginPaint(hWnd, &ps);
		logFont.lfHeight = -MulDiv(20, GetDeviceCaps(hdc, LOGPIXELSY), 72);
		logFont.lfWeight = FW_NORMAL;

		MemDC = CreateCompatibleDC(hdc);

		MyBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP1));

		OldBitmap = (HBITMAP)SelectObject(MemDC, MyBitmap);

		BitBlt(hdc, 0, 0, 480, 720, MemDC, 0, 0, SRCCOPY);

		hFont = CreateFontIndirect(&LogFont);
		OldFont = (HFONT)SelectObject(hdc, hFont);
		SetTextColor(hdc, fColor);

		//��¥
		LPTSTR TTIME[40];
		wsprintf(TTIME, TEXT("%d / %d "), tm.tm_mon + 1, tm.tm_mday);
		TextOut(hdc, 240, 190, TTIME, lstrlen(TTIME));
		switch (tm.tm_wday) {
		case 0://��
			TextOut(hdc, 290, 240, TEXT("(��)"), lstrlen(TEXT("(��)")));
			TextOut(hdc, 110, 260, TEXT("6���� ������÷�� ���۵˴ϴ�"), lstrlen(TEXT("6���� ������÷�� ���۵˴ϴ�")));
			break;
		case 1://��
			TextOut(hdc, 290, 240, TEXT("(��)"), lstrlen(TEXT("(��)")));
			TextOut(hdc, 110, 260, TEXT("5���� ������÷�� ���۵˴ϴ�"), lstrlen(TEXT("6���� ������÷�� ���۵˴ϴ�")));
			break;
		case 2://ȭ
			TextOut(hdc, 290, 240, TEXT("(ȭ)"), lstrlen(TEXT("(��)")));
			TextOut(hdc, 110, 260, TEXT("4���� ������÷�� ���۵˴ϴ�"), lstrlen(TEXT("6���� ������÷�� ���۵˴ϴ�")));
			break;
		case 3://��
			TextOut(hdc, 290, 240, TEXT("(��)"), lstrlen(TEXT("(��)")));
			TextOut(hdc, 110, 260, TEXT("3���� ������÷�� ���۵˴ϴ�! "), lstrlen(TEXT("6���� ������÷�� ���۵˴ϴ�!")));
			break;
		case 4://��
			TextOut(hdc, 290, 240, TEXT("(��)"), lstrlen(TEXT("(��)")));
			TextOut(hdc, 110, 260, TEXT("2���� ������÷�� ���۵˴ϴ�!!"), lstrlen(TEXT("6���� ������÷�� ���۵˴ϴ�!!!")));
			break;
		case 5://��
			TextOut(hdc, 290, 240, TEXT("(��)"), lstrlen(TEXT("(��)")));
			TextOut(hdc, 110, 260, TEXT("���� ������÷�� ���۵˴ϴ�!!!  �󸪻缼��!"), lstrlen(TEXT("1���� ������÷�� ���۵˴ϴ�!!!  �󸪻缼��!")));
			break;
		case 6://��
			TextOut(hdc, 290, 240, TEXT("(��)"), lstrlen(TEXT("(��)")));
			TextOut(hdc, 110, 260, TEXT("���� ������÷�� �����մϴ�!!!!"), lstrlen(TEXT("���� ������÷�� �����մϴ�!!!!")));
			break;
		}


		//������
		LPTSTR TTTTIME[40];
		wsprintf(TTTTIME, TEXT("������: %3d . %3d . %3d   %3d:%3d"), tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min);
		TextOut(hdc, 110, 240, TTTTIME, lstrlen(TTTTIME));

		TextOut(hdc, 30, 290, TEXT(" - - - - - - -- - - - - - -- - - - - - -- - - - - - -- - - - - - -- - - - - - -- - - - - - -- - - - - - -"), 105);
		TextOut(hdc, 30, 310, TEXT("����/�̸�                                ��÷��ȣ "), 46);

		//BJY BJY BJY
		TextOut(hdc, 40, 330, TEXT("A"), lstrlen(TEXT("A")));
		TextOut(hdc, 70, 330, TEXT("BJY"), lstrlen(TEXT("BJY")));

		LPTSTR BJY[40];//�ִ� ����
		wsprintf(BJY, TEXT("%6d  %6d  %6d  %6d  %6d  %6d"), BJY_[0], BJY_[3], BJY_[4], BJY_[1], BJY_[2], BJY_[5]);//�������Լ�
		TextOut(hdc, 130, 330, BJY, lstrlen(BJY));


		//YYG YYG YYG
		TextOut(hdc, 40, 360, TEXT("B"), lstrlen(TEXT("A")));
		TextOut(hdc, 70, 360, TEXT("YYG"), lstrlen(TEXT("YYG")));

		LPTSTR YYG[40];//�ִ� ����
		wsprintf(YYG, TEXT("%6d  %6d  %6d  %6d  %6d  %6d"), YYG_[1], YYG_[2], YYG_[5], YYG_[0], YYG_[3], YYG_[4]);//�������Լ�
		TextOut(hdc, 130, 360, YYG, lstrlen(YYG));



		//SBG SBG SBG
		TextOut(hdc, 40, 390, TEXT("C"), lstrlen(TEXT("A")));
		TextOut(hdc, 70, 390, TEXT("SBG"), lstrlen(TEXT("SBG")));

		LPTSTR SBG[40];//�ִ� ����
		wsprintf(SBG, TEXT("%6d  %6d  %6d  %6d  %6d  %6d"), SBG_[2], SBG_[1], SBG_[0], SBG_[5], SBG_[4], SBG_[3]);//�������Լ�
		TextOut(hdc, 130, 390, SBG, lstrlen(SBG));



		//SSS SSS SSS
		TextOut(hdc, 40, 420, TEXT("D"), lstrlen(TEXT("A")));
		TextOut(hdc, 70, 420, TEXT("SSS"), lstrlen(TEXT("SSS")));

		LPTSTR SSS[40];//�ִ� ����
		wsprintf(SSS, TEXT("%6d  %6d  %6d  %6d  %6d  %6d"), SSS_[3], SSS_[0], SSS_[1], SSS_[4], SSS_[5], SSS_[2]);//�������Լ�
		TextOut(hdc, 130, 420, SSS, lstrlen(SSS));


		//AUTO AUTO AUTO
		//TextOut(hdc, 40, 450, TEXT("E"), lstrlen(TEXT("A")));
		//TextOut(hdc, 70, 450, TEXT("AUTO"), lstrlen(TEXT("AUTO")));

		//LPTSTR JGH[30];//�ִ� ����
		//wsprintf(JGH, TEXT("%6d  %6d  %6d  %6d  %6d  %6d"), AUT_[4], AUT_[5], AUT_[2], AUT_[3], AUT_[0], AUT_[1]);//�������Լ�
		//TextOut(hdc, 130, 450, JGH, lstrlen(JGH));


		TextOut(hdc, 30, 480, TEXT(" - - - - - - -- - - - - - -- - - - - - -- - - - - - -- - - - - - -- - - - - - -- - - - - - -- - - - - - -"), 105);
		TextOut(hdc, 140, 510, TEXT("�徲�� �˰��� �����"), 12);
		TextOut(hdc, 35, 530, TEXT("A:Ȧ¦  B:�����ڸ� �� C:���ӵ� ��  D:��÷�̷�  E:���� "), lstrlen(TEXT("A:Ȧ¦  B:����  C:���ӵ� ��  D:��÷�̷�  E:�����ڸ� ��")));


		//InvalidateRect(hWnd, NULL, TRUE);//1�ʸ��� ȭ�鰻��->����
		SelectObject(hdc, OldFont);
		DeleteObject(hFont);
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_SAVE:
			break;
		case ID_EXIT:
			MessageBox(hWnd,
				TEXT("���� �Ͻðڽ��ϱ�?"),
				TEXT("��¥ ����"),
				MB_YESNOCANCEL);
			if (answer == IDYES || answer == IDNO)
				PostQuitMessage(0);
			return 0;
			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}