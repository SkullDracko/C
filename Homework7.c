#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int fileExistsInCurrentDir(const char *fname) {
    FILE *file;
    if((file = fopen(fname,"r"))) {
        fclose(file);
        return 1;
    }
    return 0;
}

int createFile() {
    FILE *fPtr;

    fPtr = fopen("./employees.txt","w");
    if(fPtr == NULL) {
        printf("Unable to create file.\n");
        return 1;
    } 

    fgets("",0,fPtr);

    fputs("",fPtr);

    fclose(fPtr);
    return 1;
}

int match(char cmd[],char word[]) {
    for(int i = 0; i < sizeof(cmd); i++) {
        if(cmd[i] != word[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    while("" != NULL) {
        if(!fileExistsInCurrentDir("./employees.txt") == 1) {
            printf("no file... creating employees.txt\n");
            createFile();
        }
                
        FILE *fp;
        fp=fopen("./employees.txt","r");
        if(fp==NULL) {
            printf("file can not open\n");
        }
        char cmd[20];
        printf("What Command Would You Like To Use:\n- admin-panel\n- iniciar\n- salir\n> ");
        scanf(" %s",cmd);

        if(match(cmd,"admin-panel")) {
            char password[] = "supersecretpassword";
            char pass[sizeof(password)];
            printf("Enter panel password > ");
            scanf(" %s",pass);
            if(match(password,pass) == 1) {
                char cmd2[20];
                printf("What Admin Command Would You Like To Use:\n- new-user\n> ");
                scanf(" %s",cmd2);
                if(match(cmd2,"new-user")) {
                    char npin[2000];
                    char name[2000];
                    printf("What is their name? <join parts of name with '_' > > ");
                    scanf("%s",name);
                    printf("What will their pin be > ");
                    scanf("%s",npin);
                    int flag = 0;
                    char sline[200];
                    while(!feof(fp)) {
                        fgets(sline,2000,fp);
                        if(strstr(sline,npin) != NULL){
                            flag = 1;
                        }
                    }
                    if(flag == 1) {
                        printf("error: pin already exists\n");
                        fclose(fp);
                        return 0;
                    }
                    fclose(fp);
                    fp = fopen("./employees.txt","a");
                    if(fp == NULL) {
                        printf("file can not open\n");
                    }
                    fprintf(fp,"pin:%s,name:%s %s",npin,name,"\n");
                    printf("success\n");
                }
            } else {
                printf("wrong password\n");
                return 0;
            }
        } else if (match(cmd,"iniciar")) 
        {
            char pin[2000];
            printf("What Is Your Login Pin > ");
            scanf(" %s",&pin);
            int flag = 0;
            
            char sline[200];
            while(!feof(fp)) {
                fgets(sline,2000,fp);
                if(strstr(sline,pin) != NULL){
                    flag = 1;
                }
            }
            if(flag == 0) {
                printf("no pin matches!.");
                return 0;
            }

            fclose(fp);
            fp = fopen("./shifts.txt","a");
            if(fp == NULL) {
                printf("file can not open\n");
            }
            time_t rawtime;
            struct tm * timeinfo;
            time ( &rawtime );
            timeinfo = localtime ( &rawtime );
            fprintf(fp,"singed in: %s at %s %s",sline,asctime(timeinfo),"\n");
            fclose(fp);
            printf("logged in\n");
        } else if (match(cmd,"salir")) {
            char pin[2000];
            printf("What Is Your Login Pin > ");
            scanf(" %s",&pin);
            int flag = 0;
            
            char sline[200];
            while(!feof(fp)) {
                fgets(sline,2000,fp);
                if(strstr(sline,pin) != NULL){
                    flag = 1;
                }
            }
            if(flag == 0) {
                printf("no pin matches!.");
                return 0;
            }
            fclose(fp);
            fp = fopen("./shifts.txt","a");
            if(fp == NULL) {
                printf("file can not open\n");
            }
            time_t rawtime;
            struct tm * timeinfo;
            time ( &rawtime );
            timeinfo = localtime ( &rawtime );
            fprintf(fp,"signed out: %s at %s %s",sline,asctime(timeinfo),"\n");
            fclose(fp);
            printf("signed out\n");
        }
    }
    
    return 0;
}
