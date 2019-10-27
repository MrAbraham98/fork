//
//  main.c
//  fork
//
//  Created by ibrahim bucaklı on 28.10.2019.
//  Copyright © 2019 ibrahim bucaklı. All rights reserved.
//

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void parentProcess(void);
int childProcess(int sayi);

int main(void)
{
    int sayi;
    pid_t pid;
    printf("Pozitif bir sayı giriniz \n");
    scanf("%d", &sayi);
    pid =fork();
    if(pid == 0){
        childProcess(sayi);
    }
   else{
        wait(NULL);
        parentProcess();
    }
}
int childProcess(int sayi){
    while (1) {
        int mod = sayi % 2;
        if(mod == 0){
            sayi = sayi / 2;
            printf("Child Process : %d\n",sayi);
        }
        if(mod == 1){
            sayi = sayi * 3 + 1;
            printf("Child Process : %d\n",sayi);
        }
        if(sayi == 1){
            break;
        }
    }
    return 0;
}
void parentProcess(void){
    printf("Parent process\n");
}
