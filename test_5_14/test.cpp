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
//                printf("*"); //不需要控制台输出时不需要加上颜色控制符
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
//    printf("母亲节快乐！\n----lml");
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
    fp = fopen("output.txt", "w"); //打开一个名为output.txt的文件
    double x, y, a;

    // 在文件中添加HTML标签
    fprintf(fp, "<html>\n");
    fprintf(fp, "<body>\n");
    fprintf(fp, "<pre style=\"color:red\">\n"); //将输出内容变红色
    fprintf(fp, "<pre style=\"text-align:center\">\n"); //让输出内容居中
    for (y = 1.5; y > 0; y -= 0.1)
    {
        for (x = -1.5; x < 1.5; x += 0.05)
        {
            a = x * x + y * y - 1;
            if (a * a * a - x * x * y * y * y <= 0)
            {
                fprintf(fp, "*"); //不需要控制台输出时不需要加上颜色控制符
                //将输出写入文件中
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
                //将输出写入文件中
            }
            else
                fprintf(fp, " ");
        }
        fprintf(fp, "\n");
    }
    fprintf(fp, "<h2>母亲节快乐！\n----lml</h2>");

    // 在文件中添加HTML标签的闭合标签
    fprintf(fp, "</pre>\n");
    fprintf(fp, "</body>\n");
    fprintf(fp, "</html>\n");

    fclose(fp); //关闭文件
    return 0;
}

















