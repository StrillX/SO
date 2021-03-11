#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "pessoa.h"

typedef struct Pessoa{
	char nome[200];
	int idade;
}Pessoa;

int main (int argc , char * argv[]){
	int fd = open("pessoas.bin",O_CREAT | O_APPEND | O_RDWR, 0644);
	//check fd < 0
	


	Pessoa pessoa1;
	strcpy(pessoa1.nome,"Maria Mourinho");
	pessoa1.idade =  50;
	
	printf("pessoa1.nome: %s\n", pessoa1.nome);
	printf("pessoa1.idade: %d\n", pessoa1.idade);
	printf("sizeof(Pessoa) : %d\n", (int) sizeof(Pessoa));


	if(write(fd,&pessoa1, sizeof(Pessoa))>0){
		perror("Write");
	}

	lseek(fd, -sizeof(Pessoa), SEEK_CUR);


	Pessoa pessoa1_read;

	new_person("Ednaldo Pereira",55);
	if( read(fd, &pessoa1_read, sizeof(Pessoa)) > 0){
		printf("pessoa1_read.nome: %s\n",pessoa1_read.nome);
		printf("pessoa1_read.idade: %d\n",pessoa1_read.idade);
	
	
	}



	return 0;

}



