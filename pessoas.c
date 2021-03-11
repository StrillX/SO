#include "pessoa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>


typedef struct Pessoa{
	char nome[200];
	int idade;
}Pessoa;

int main (int argc , char * argv[]){


	new_person("Ednaldo Pereira",55);
	int fd = open("pessoas.bin",O_CREAT | O_APPEND | O_RDWR, 0644);
	//check fd < 0
	


	
	lseek(fd, -sizeof(Pessoa), SEEK_END);
	


	Pessoa pessoa1_read;

	
	if( read(fd, &pessoa1_read, sizeof(Pessoa)) > 0){
		printf("ult_pessoa_read.nome: %s\n",pessoa1_read.nome);
		printf("ult_pessoa_read.idade: %d\n",pessoa1_read.idade);
	
	
	}



	return 0;

}



