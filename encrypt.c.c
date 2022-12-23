/*EAS Dasar Pemrograman
  Nama  : Meylina Tesa Hapsari
  NRP   : 5025221149
  Kelas : Dasar Pemrograman C
*/

#include<stdio.h>
#include<conio.h>

int main()
{
    char fname[32], ch;

    FILE *fps, *fpt;

    printf("Enter Filename: ");
    scanf("%s", fname);

    fps = fopen(fname, "r");
    if(fps == NULL){
        return 0;
    }

    fpt = fopen("temp.txt", "w");
    if(fpt == NULL){
        return 0;
    }

    ch = fgetc(fps);
    while(ch != EOF){
            ch = ch + 49;
            if(ch <= 126){
                    printf("a");
                fputc(ch, fpt);
            }
            else if(ch > 126){
                ch = (ch % 126) + 32;
                printf("b");
                fputc(ch, fpt);
            }
        ch = fgetc(fps);
    }

    fclose(fps);
    fclose(fpt);

    fps = fopen(fname, "w");
    if(fps == NULL){
        return 0;
    }

    fpt = fopen("temp.txt", "r");
    if(fpt == NULL){
        return 0;
    }

    ch = fgetc(fpt);
    while(ch != EOF){
        ch = fputc(ch, fps);
        ch = fgetc(fpt);
    }

    fclose(fps);
    fclose(fpt);
    printf("\nFile %s Encrypted Successfully!", fname);
    getch();
    return 0;
}
