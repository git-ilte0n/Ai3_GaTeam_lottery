
#include<stdio.h>
#include <math.h>
#include<stdlib.h>
#include<time.h>

#define YYG_NUM 6  // ��÷�� ��ȣ ����
int YYG_lottonum[YYG_NUM]; //�ζ� ��ȣ�� ��� ���� ����
double YYG_arr[45];


double YYG_Lotto_History(int num);
double YYG_Average(double num[]);   // SSS 45���� ���� ��ձ��ϴ� �ռ�
double YYG_SD(double num[]);        // SSS ����� �̿��Ͽ� ǥ������^2 ���ϴ� �Լ�
void YYG_SSSFunction_Lotto();       // SSS ǥ�������� �̿��Ͽ� �ζ� �̴��Լ� 
void YYG_Function_Lotto();
void YYG_Function_Print();
void YJFucntion_Lotto();


int YYG_main() {

    int i = 0;

    while (i < 45) {          //SSS ��ȣ�� ��÷Ƚ�� �迭 ����
        YYG_arr[i] = YYG_Lotto_History(i + 1);
        i++;
    }

        switch (1) {
        case 1:
            printf("\nYJ�� ��ȣ�� �����մϴ�!\n\n");
            YJFucntion_Lotto();    // YJ�ڵ�
            YYG_Function_Print();       // ��ȣ ���

            break;

        case 2:
            YYG_Function_Lotto(); // 2 ���ý� �ζ� ��ȣ ��÷��
            YYG_Function_Print(); // ��÷�� ��ȣ ���

            break;
        case 3:
            exit(0);   //3 ���ý� ����
            break;
        default: printf("�ٽ� �������ּ���\n");


        }

    return 0;
}


void YYG_Function_Lotto() {
    // �ζ� ��ȣ �����Լ�
    srand((unsigned)time(NULL)); // rand �Լ��� �ʱ�ȭ. �ʱ�ȭ ���� ������ ���α׷� ����� ���� ���� ���� ����

    for (int i = 0; i < YYG_NUM; i++) {
        YYG_lottonum[i] = 1 + rand() % 45;

    }
}


void YJFucntion_Lotto() {    //������ �ڵ�
    int num = 0;
    srand((unsigned)time(NULL)); //rand �Լ� �ʱ�ȭ

    while (1) {
        num = 0;
        for (int i = 0; i < YYG_NUM; i++) {
            YYG_lottonum[i] = 1 + rand() % 45;
            if (YYG_lottonum[i] < 10) {
                num++;
            }
        }
        if (num != 6) {
            break;
        }
        printf("\n����!\n");
    }
}


void YYG_Function_Print() {
    //�ζ� ��ȣ ��� �Լ�
    printf("\n***��÷�� ��ȣ�� ");

    for (int i = 0; i < YYG_NUM; i++) {
        printf("%d ", YYG_lottonum[i]);
    }
    printf("�Դϴ�***\n");
}






double YYG_Average(double num[]) {  //SSS ��÷Ƚ���� ��� ���

    double result = 0.0;

    for (int i = 0; i < 45; i++)
        result += num[i];

    return result / 45.0;

}


double YYG_SD(double num[]) {   //SSS ��÷Ƚ���� ǥ������ ���

    double result = 0.0;

    for (int i = 0; i < 45; i++)

        result += num[i] * num[i];

    return (result / 45.0) - (YYG_Average(num) * YYG_Average(num));
}

void YYG_SSSFunction_Lotto() {      // SSS ���ο� ��ȣ��÷ �Լ�
    // �ζ� ��ȣ �����Լ�
    srand((unsigned)time(NULL));    // rand �Լ��� �ʱ�ȭ. �ʱ�ȭ ���� ������ ���α׷� ����� ���� ���� ���� ����

    for (int i = 0; i < YYG_NUM; i++) {
        YYG_lottonum[i] = 1 + rand() % 45;
        if ((YYG_Lotto_History(YYG_lottonum[i]) < (YYG_Average(YYG_arr) - sqrt(YYG_SD(YYG_arr))))) {    //SSS ���� ��ȣ�� ��÷�� Ƚ���� (���-ǥ������)���� ������ 
            if (rand() % 2) {                                                   //SSS 1/2Ȯ���� Ż���� ����
                printf("%d���� �ֱ� %.0lf�� ��÷! %lf ���� �������� Ż��! \n", YYG_lottonum[i], YYG_Lotto_History(YYG_lottonum[i]), (YYG_Average(YYG_arr) - sqrt(YYG_SD(YYG_arr))));
                i--;
            }
        }
    }
}

double YYG_Lotto_History(int num) {    //SSS ��ȣ�� �ζ� ��÷Ƚ�� 677~977ȸ ����
    switch (num) {
    case 1:
        return 44;
        break;
    case 2:
        return 52;
        break;
    case 3:
        return 49;
        break;
    case 4:
        return 49;
        break;
    case 5:
        return 40;
        break;
    case 6:
        return 49;
        break;
    case 7:
        return 43;
        break;
    case 8:
        return 33;
        break;
    case 9:
        return 43;
        break;
    case 10:
        return 57;
        break;
    case 11:
        return 47;
        break;
    case 12:
        return 62;
        break;
    case 13:
        return 49;
        break;
    case 14:
        return 44;
        break;
    case 15:
        return 46;
        break;
    case 16:
        return 51;
        break;
    case 17:
        return 49;
        break;
    case 18:
        return 54;
        break;
    case 19:
        return 47;
        break;
    case 20:
        return 34;
        break;
    case 21:
        return 54;
        break;
    case 22:
        return 40;
        break;
    case 23:
        return 38;
        break;
    case 24:
        return 51;
        break;
    case 25:
        return 37;
        break;
    case 26:
        return 43;
        break;
    case 27:
        return 40;
        break;
    case 28:
        return 48;
        break;
    case 29:
        return 41;
        break;
    case 30:
        return 52;
        break;
    case 31:
        return 44;
        break;
    case 32:
        return 42;
        break;
    case 33:
        return 53;
        break;
    case 34:
        return 54;
        break;
    case 35:
        return 45;
        break;
    case 36:
        return 52;
        break;
    case 37:
        return 40;
        break;
    case 38:
        return 55;
        break;
    case 39:
        return 54;
        break;
    case 40:
        return 37;
        break;
    case 41:
        return 44;
        break;
    case 42:
        return 51;
        break;
    case 43:
        return 58;
        break;
    case 44:
        return 43;
        break;
    case 45:
        return 49;
        break;
    default:
        return 0;
        break;

    }

}