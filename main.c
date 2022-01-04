// Eduardo Rodriguez
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    int statusQ, statusP, statusR, statusI, statusM;
    int statusA, statusV, statusE, statusr, statusa;

    pid_t pid_Q, pid_P, pid_R, pid_I, pid_M;
    pid_t pid_A, pid_V, pid_E, pid_r, pid_a;

    if( (pid_Q = fork()) == 0){ // se crea Q
        if((pid_I=fork()) == 0){// I
            if((pid_P = fork()) == 0){
                printf("\t    P   %d   %d     \n", getpid(), getppid());
            }else{
                if((pid_R = fork()) == 0){
                    waitpid(pid_P, &statusP, 0);
                    printf("\t    R   %d   %d     \n", getpid(), getppid());
                }else{
                    waitpid(pid_R, &statusR, 0);
                    printf("\t    I   %d   %d     \n", getpid(), getppid());
                }
            }
        }
        else{// Q
            waitpid(pid_I, &statusI, 0);
            if((pid_A = fork()) == 0){ // se crea A
                if((pid_M = fork()) == 0){
                    printf("\t    M   %d   %d     \n", getpid(), getppid());
                }else{// A
                    waitpid(pid_M, &statusM, 0);
                    printf("\t    A   %d   %d     \n", getpid(), getppid());
                }
            }else{// Q
                waitpid(pid_A, &statusA, 0);
                if((pid_a = fork()) == 0){
                    if((pid_V = fork()) == 0){// se crea V
                        printf("\t    V   %d   %d     \n", getpid(), getppid());
                    }else{
                        waitpid(pid_V, &statusV, 0);
                        if((pid_r = fork()) == 0){
                            if((pid_E = fork()) == 0){
                                printf("\t    E   %d   %d     \n", getpid(), getppid());
                            }else{
                                waitpid(pid_E, &statusE, 0);
                                printf("\t    r   %d   %d     \n", getpid(), getppid());
                            }
                        }else{
                            waitpid(pid_r, &statusr, 0);
                            printf("\t    a   %d   %d     \n", getpid(), getppid());
                        }
                    }
                }else{
                    waitpid(pid_a, &statusa, 0);
                    printf("\t    @   %d   %d     \n", getpid(), getppid());
                }
            }
        }
    }else{
        printf("\n");
        printf("\033[0;47;30m");
        printf("\t                        \n");
        printf("\t    ID - PID - PPID     \n");
        printf("\t------------------------\n");
        waitpid(pid_Q, &statusQ, 0);
        printf("\t------------------------\n");
        printf("\t    Terminado           \n");
        printf("\t------------------------\n");
        printf("\n");
        printf("\033[0;30;40m");
    }
}