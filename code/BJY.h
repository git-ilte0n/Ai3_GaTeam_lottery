#define _CRT_SECURE_NO_WARNINGS

#define BJY_NUM 6
int BJY_isAllOdd = 0;
int BJY_isAllEven = 0;
int BJYlottonum[BJY_NUM];

void BJY_function_lotto()
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < BJY_NUM; i++) {
		BJYlottonum[i] = 1 + rand() % 45;
		for (int j = 0; j < i; j++) { //�ߺ�Ȯ��
			if (BJYlottonum[i] == BJYlottonum[j]) {
				i--; //�ߺ� �߻� �� i��° ���� �����
				break;
			}
		}

	}
	for (int k = 0; k < BJY_NUM; k++) //������������
	{
		for (int i = 0; i < BJY_NUM - 1; i++) {
			if (BJYlottonum[i] > BJYlottonum[i + 1]) {
				int tmp = BJYlottonum[i];
				BJYlottonum[i] = BJYlottonum[i + 1];
				BJYlottonum[i + 1] = tmp;
			}
		}
	}
}

void BJY_function_print()
{
	printf("��÷�� ��ȣ�� ");
	for (int i = 0; i < BJY_NUM; i++)
	{
		printf("%d ", BJYlottonum[i]);
	}
	printf("�Դϴ�.\n");
}
void BJY_function_checkOddEven() // ��ü ¦�� Ȥ�� Ȧ�� �Ǵ��Լ�
{
	for (int i = 0; i < BJY_NUM; i++)
	{
		BJYlottonum[i] = 1 + rand() % 45;
		if (BJYlottonum[i] % 2 == 1) // Ȧ����� isAllOdd�� 1����
			BJY_isAllOdd++;

		else if (BJYlottonum[i] % 2 == 0) // ¦����� isAllOdd�� 1����
			BJY_isAllEven++;
	}
}
int BJY_main()
{
	Sleep(1);
	int modesel = 1;
	switch (modesel) {
	case 1:
		BJY_function_lotto();
		BJY_function_checkOddEven();
		if (BJY_isAllOdd == 6 || BJY_isAllEven == 6)//isAllOdd�� 6�̵Ǹ� ��üȦ��, isAllEven�� 6�̶�� ��ü ¦��
		{
			BJY_function_lotto(); // ��ü Ȧ���ų� ¦���� �����
			printf("������Ǿ����ϴ�.\n");
			BJY_function_print();
		}
		else
			BJY_function_print();
		break;
	case 2:
		exit(0);
		break;
	default: printf("�ٽ� �������ּ���\n");

		BJYlottonum[0] == BJYlottonum[0];
	}
}