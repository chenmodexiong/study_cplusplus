//#include<stdio.h>
//#include<windows.h>
//int main()
//{
//    double x, y, a;
//    for (y = 1.5; y > 0; y -= 0.1)
//    {
//        for (x = -1.5; x < 1.5; x += 0.05)
//        {
//            a = x * x + y * y - 1;
//            if (a * a * a - x * x * y * y * y <= 0)
//            {
//                printf("*"); //����Ҫ����̨���ʱ����Ҫ������ɫ���Ʒ�
//            }
//            else
//                printf(" ");
//        }
//        printf("\n");
//    }
//    for (y = 0; y > -1.5; y -= 0.1)
//    {
//        for (x = -1.5; x < 1.5; x += 0.05)
//        {
//            a = x * x + y * y - 1;
//            if (a * a * a - x * x * y * y * y <= 0)
//            {
//                printf("*");
//            }
//            else
//                printf(" ");
//        }
//        printf("\n");
//    }
//    printf("ĸ�׽ڿ��֣�\n----lml");
//    return  0;
//}



#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string>
#include <fstream>
#include<windows.h>

int main()
{
    FILE* fp;
    fp = fopen("output.txt", "w"); //��һ����Ϊoutput.txt���ļ�
    double x, y, a;

    // ���ļ������HTML��ǩ
    fprintf(fp, "<html>\n");
    fprintf(fp, "<body>\n");
    fprintf(fp, "<pre style=\"color:red\">\n"); //��������ݱ��ɫ
    fprintf(fp, "<pre style=\"text-align:center\">\n"); //��������ݾ���
    for (y = 1.5; y > 0; y -= 0.1)
    {
        for (x = -1.5; x < 1.5; x += 0.05)
        {
            a = x * x + y * y - 1;
            if (a * a * a - x * x * y * y * y <= 0)
            {
                fprintf(fp, "*"); //����Ҫ����̨���ʱ����Ҫ������ɫ���Ʒ�
                //�����д���ļ���
            }
            else
                fprintf(fp, " ");
        }
        fprintf(fp, "\n");
    }
    for (y = 0; y > -1.5; y -= 0.1)
    {
        for (x = -1.5; x < 1.5; x += 0.05)
        {
            a = x * x + y * y - 1;
            if (a * a * a - x * x * y * y * y <= 0)
            {
                fprintf(fp, "*");
                //�����д���ļ���
            }
            else
                fprintf(fp, " ");
        }
        fprintf(fp, "\n");
    }
    fprintf(fp, "<h2>ĸ�׽ڿ��֣�\n----lml</h2>");

    // ���ļ������HTML��ǩ�ıպϱ�ǩ
    fprintf(fp, "</pre>\n");
    fprintf(fp, "</body>\n");
    fprintf(fp, "</html>\n");

    fclose(fp); //�ر��ļ�
    return 0;
}

















