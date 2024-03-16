/*
В базе данных хранятся сведения о работе библиотеки: дата текущего года, фамилия
читателя, количество книг

Структура входного файла in.txt
23.10.2022 Винни-Пух 5
12.11.2022 Винни-Пух 3
15.10.2022 Пятачок 7

Определить количество книг, взятых каждым читателем за все время, упорядочив по
фамилии читателя

Структура выходного файла out.txt
Читатель Количество
Винни-Пух 8
Пятачок 7

Вагина Полина Алексеевна, 32ИС-21, 11.03.2024
*/

#include <stdio.h>
#include <string.h>

struct Reader {
    char name[20];
    int total_books;
};

int main()
{
    char *f1 = "in.txt";
    char *f2 = "out.txt";
    
    FILE *fp1 = fopen(f1, "r");
    FILE *fp2 = fopen(f2, "w");
    
    char date[20];
    char name[20];
    int books, n = 0;
    
    if (!fp1){
        printf("error");
        return 1;
    }
    
    if (!fp2){
        printf("error");
        return 1;
    }
    
    struct Reader readers[100]; 
    
    while (fscanf(fp1, "%s %s %d\n", date, name, &books) != EOF){
        int reader_found = 0;
        for (int i = 0; i < n; i++) {
            if (strcmp(readers[i].name, name) == 0) {
                readers[i].total_books += books;
                reader_found = 1;
                break;
            }
        }
        if (!reader_found) {
            strcpy(readers[n].name, name);
            readers[n].total_books = books;
            n++;
        }
    }
    
    fprintf(fp2, "Читатель\tКоличество\n");
    for (int i = 0; i < n; i++) {
        fprintf(fp2, "%10s\t\t%d\n", readers[i].name, readers[i].total_books);
    }
    
    fclose(fp1);
    fclose(fp2);
    
    return 0;

}
