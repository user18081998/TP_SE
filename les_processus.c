#include <stdio.h> 
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h> 

int test0(){
    pid_t f1 = fork();
    printf("[son] pid %d from [parent] pid %d\n",getpid(),getppid());
    for(int i=1;i<51;i++){printf("%d",i);}
    pid_t f2 = fork();
    printf("[son] pid %d from [parent] pid %d\n",getpid(),getppid());
    for(int i=51;i<101;i++){
        printf("%d",i);
    }
    return 0;
}

int test1(){
    printf("main 1st printf executing with pid %d\n\n",getpid());
    pid_t pid1;
        pid1=fork();
        if(pid1<0){
            fprintf(stderr,"Fork Echec");
            return 1;}
        else if(pid1==0){
            for(int i=1;i<51;i++){printf("%d",i);}
            printf("\nFinished for loop with pid %d\n\n",getpid());
            exit(0);}
        else {}
        
    printf("main 2nd printf executing with pid %d\n\n",getpid());
    
    pid_t pid2;
        pid2=fork();
        if(pid2<0){fprintf(stderr,"Fork Echec"); return 1;}
        else if(pid2==0){
            for(int i=51;i<101;i++){printf("%d",i);}
            printf("\nFinished for loop with pid %d\n\n",getpid());
            exit(0);}
        else {}   

    printf("main 3rd printf executing with pid %d\n\n",getpid());
    return 0;
}

int ex1(){
    pid_t pid1;
        pid1=fork();
        if(pid1<0){fprintf(stderr,"Fork Echec"); return 1;}
        else if(pid1==0){
            for(int i=1;i<51;i++){printf("%d ",i);}
            printf("\nFinished for loop with pid %d\n\n",getpid());
            exit(0);}
        else {}
    
    pid_t pid2;
        pid2=fork();
        if(pid2<0){fprintf(stderr,"Fork Echec"); return 1;}
        else if(pid2==0){
            for(int i=51;i<101;i++){printf("%d ",i);} 
            printf("\nFinished for loop with pid %d\n\n",getpid());
            exit(0);}
        else {}   

    return 0;
}

int ex2(){
    pid_t pid1;
        pid1=fork();
        if(pid1<0){fprintf(stderr,"Fork Echec"); return 1;}
        else if(pid1==0){
            for(int i=1;i<51;i++){printf("%d ",i);}
            exit(0);}
        else {}
    
    pid_t pid2;
        pid2=fork();
        if(pid2<0){fprintf(stderr,"Fork Echec"); return 1;}
        else if(pid2==0){
            for(int i=51;i<101;i++){printf("%d ",i);} 
            exit(0);}
        else {}   

    printf("\n");
    return 0;
}

int ex3(int argc, char* argv[]){
    /* must include multi string commands in "..." to pass it as a single string
    otherwise i'd need to convert char** into char*??? .*/
    pid_t pid;
    pid=fork();
    if(pid<0){fprintf(stderr, "Fork Failure"); return 1;}
    else if(pid==0){printf("\n");system(argv[1]);exit(0);}
    else{}
}

int ex4(){
    /* not sure about this one since my laptop BSOD'ed both times I tried running this */
    pid_t create_process(){
        pid_t pid = fork();
        if(pid==0){printf("process %d",getpid());}
        return 1;
    }
    while(create_process()){
    }
    return 0;
}

int main(int argc, char* argv[]){
    ex1();
}