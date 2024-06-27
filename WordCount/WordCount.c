#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 计算字符数
int countCharacters(const char *filePath)
{
    FILE *file = fopen(filePath, "r");
    if (file == NULL)
    {
        printf("无法打开文件\n");
        return -1;
    }

    int count = 0;
    int ch;
    while ((ch = fgetc(file)) != EOF)
    {
        count++;
    }
    fclose(file);
    return count;
}

// 计算单词数
int countWords(const char *filePath)
{
    FILE *file = fopen(filePath, "r");
    if (file == NULL)
    {
        printf("无法打开文件\n");
        return -1;
    }

    int count = 0;
    char word[100];
    while (fscanf(file, "%s", word) != EOF)
    {
        count++;
    }
    fclose(file);
    return count;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("使用方式: 程序名 -c/-w 文件名\n");
        return 1;
    }

    const char *parameter = argv[1];
    const char *filePath = argv[2];

    if (strcmp(parameter, "-c") == 0)
    {
        int characterCount = countCharacters(filePath);
        printf("字符数：%d\n", characterCount);
    }
    else if (strcmp(parameter, "-w") == 0)
    {
        int wordCount = countWords(filePath);
        printf("单词数：%d\n", wordCount);
    }
    else
    {
        printf("无效的参数，请输入 '-c' 或 '-w'\n");
    }

    return 0;
}
