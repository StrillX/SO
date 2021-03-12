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


    int fd = open("pessoas.bin",O_CREAT | O_APPEND | O_RDWR, 0666);

    if(fd < 0){
        perror("Open");
    }
    Pessoa pessoa1;
	strcpy(pessoa1.nome,name);
	pessoa1.idade =  age;

    if(write(fd,&pessoa1, sizeof(Pessoa))>0){
		perror("Write");
	}
    close(fd);
    return 0;
}

int person_change_age(char * nome, int age){

    int fd= open("pessoas.bin",O_RDWR,0666);

    

    Pessoa inserir;
    strcpy(inserir.nome,nome);
    inserir.idade = age;
    int end = lseek(fd,0,SEEK_END);
    printf("2\n");
    //Melhor mas nao sai do ciclo for some reason
    for(fd = lseek(fd,0,SEEK_SET); fd < end  ; fd +=sizeof(Pessoa) ){
        Pessoa procurada;
        printf("1\n");
        read(fd, &procurada, sizeof(Pessoa));
        
            if(strcmp(procurada.nome,nome)==0){
                printf("%s\n",procurada.nome);
                fd = lseek(fd, -sizeof(Pessoa),SEEK_CUR);
                write(fd,&inserir, sizeof(Pessoa));

		        
	             
                break;
            }

	    

    }
    lseek(fd, -sizeof(Pessoa), SEEK_CUR);
	
	Pessoa pessoa1_read;

	
	if( read(fd, &pessoa1_read, sizeof(Pessoa)) > 0){
		printf("ult_pessoa_read.nome: %s\n",pessoa1_read.nome);
		printf("ult_pessoa_read.idade: %d\n",pessoa1_read.idade);
	}
    close(fd);

    return 0;
}


int person_change_age_v2(char * nome, int age){



    return 0;
}