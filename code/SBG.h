#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#define SBG_NUM 6		// ��÷�� ��ȣ ����
int SBGlottonum[SBG_NUM];	//�ζ� ��ȣ�� ��� ���� ����
int Seq = 0;


void SBG_function_lotto() {
	// �ζ� ��ȣ �����Լ�
	srand((unsigned)time(NULL));	// rand �Լ��� �ʱ�ȭ. �ʱ�ȭ ���� ������ ���α׷� ����� ���� ���� ���� ����

	for (int i = 0; i < SBG_NUM; i++) {
		SBGlottonum[i] = 1 + rand() % 45;
		for (int j = 0; j < i; j++) { //�ߺ�Ȯ��
			if (SBGlottonum[i] == SBGlottonum[j]) {
				i--; //�ߺ� �߻� �� i��° ���� �����
				break;
			}
		}
	}
	for (int k = 0; k < SBG_NUM; k++) //������������
	{
		for (int i = 0; i < SBG_NUM - 1; i++) {
			if (SBGlottonum[i] > SBGlottonum[i + 1]) {
				int tmp = SBGlottonum[i];
				SBGlottonum[i] = SBGlottonum[i + 1];
				SBGlottonum[i + 1] = tmp;
			}
		}
	}

}
void SBG_Count() // ���ӵ� ���� 3���̻� ���ö� �ٽ� ��÷
{
	for (int i = 1; i < SBG_NUM; i++)
	{

		if ((SBGlottonum[i + 1] - SBGlottonum[i]) - (SBGlottonum[i] - SBGlottonum[i - 1]) == 0)
			Seq++;
	}
}


void SBG_function_print() {
	//�ζ� ��ȣ ��� �Լ�
	printf("��÷�� ��ȣ�� ");

	for (int i = 0; i < SBG_NUM; i++) {
		printf("%d ", SBGlottonum[i]);
	}
	printf("�Դϴ�\n");
}
int SBG_main() {

	int modesel = 1;	// 1 �ζ� ����, 2 ���α׷� ����


	switch (modesel) {
	case 1:
		SBG_function_lotto();	// 1 ���ý� �ζ� ��ȣ ��÷��

		SBG_Count();
		if (Seq > 1) {
			SBG_function_lotto();
		}

		SBG_function_print();

		break;

	case 2:
		exit(0);
		break;
	default: printf("�ٽ� �������ּ���\n");


	}


	return 0;
}

