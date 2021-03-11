#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct Pessoa{
	char nome[200];
	int idade;
}Pessoa;

int new_person(char * name, int age){

    
    int fd = open("pessoas.bin",O_CREAT | O_APPEND | O_RDWR, 0644);

    if(fd < 0){
        perror("Open");
    }
    Pessoa pessoa1;
	strcpy(pessoa1.nome,name);
	pessoa1.idade =  age;

    if(write(fd,&pessoa1, sizeof(Pessoa))>0){
		perror("Write");
	}

    return 0;
}

int person_change_age(char * nome, int age){



    return 0;
}


int person_change_age_v2(char * nome, int age){



    return 0;
}