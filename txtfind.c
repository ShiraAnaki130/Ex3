#include "txtfind.h"
#include <stdio.h>
#include <string.h>
#define LINE 256
#define WORD 30
int getLine(char s[]){
    char c= getc(stdin);
    int index=0;
    while(c!='\n'&&c!=EOF&&index<(LINE-1)){
        s[index]=c;
        index++;
        c= getc(stdin);
    }
    if(c==EOF) return -1;
    s[index]='\0';
    return strlen(s);
}
int getWord(char w[]){
    char c= getc(stdin);
    int index=0;
    while(c!='\n'&&c!='\t'&&c!=' '&&c!=EOF&&index<(WORD-1)){
        w[index]=c;
        index++;
        c= getc(stdin);
    }
    if(c==EOF) return -1;
    w[index]='\0';
    return strlen(w);
}
int substring(char* str1, char* str2){
    if(strstr(str1, str2) != NULL) return 1;
    return 0;
}
int similar(char *s, char *t, int n){
    if(strcmp(s,t)==0&&n==0) return 1;
    if(strlen(s)<strlen(t)) return 0;
    int count=0;
    int i,j;
    for(i=0,j=0;i<strlen(s);i++){
        if(*(s+i)==*(t+j)){j++;}
        else{
            if(*(s+i)!=*(t+j)){count++;}
            if(count>n) return 0;
        }
    }
    return 1;
}
void print_lines(char *str){
    char s[LINE];
    char *poniter_s=s;
    int numberOfChars=getLine(poniter_s);
    while(numberOfChars!=-1){ //as long as the the file did not end.
        if(substring(poniter_s,str)){printf("%s\n",s);}
        numberOfChars=getLine(poniter_s);
    }
}
void print_similar_words(char *str){
    char w[WORD];
    char *pointer_w=w;
    int numberOfChars=getWord(pointer_w);
    int n;
    while(numberOfChars!=-1){
        n=strlen(pointer_w)-strlen(str);
        if(n>=0){
            if(similar(pointer_w,str,1)){printf("%s\n",w);}
        }
        numberOfChars=getWord(pointer_w); 
    }
}
int main(){
    char word[WORD]={0};
    char typeOfFunction;
    int index=0;
    char c=getc(stdin);
    if(c==EOF){
        if(feof(stdin)){
            printf("stdin is empty.\n");
            return 0;
        }
        else{
            printf("error in stdin.\n");
            return 0;
        }
    }
    else{
        while(c!=' '){
            word[index]=c;
            index++;
            c=getc(stdin);
        }
        typeOfFunction=getc(stdin);
        switch(typeOfFunction){
            case 'a':
                print_lines(word);
                break;
            case 'b':
                print_similar_words(word);
                break;
        } 
    }
}
