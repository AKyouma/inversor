/* Data de submissao: 
 * Nome: Augusto Lourenço de Faria
 * RA: 194447
 */

#include <stdio.h>
#include <string.h>

const int tam_buffer=100;
#define TAM_PILHA 100

typedef struct {
	  char dados[TAM_PILHA];
	  int n;
} pilha, *Pilha;

void pilha_init(Pilha p) {
      p->n = 0;
}

void push(Pilha p, char c) {
/* Insere caractere c na pilha */
	  if (p->n < 100) {
		p->dados[p->n]=c;
		(p->n)++;
	  }
}

char pop(Pilha p) {
/* Remove caractere do topo da pilha */
	  char c;
	  if ((p->n)>0) {
		(p->n)--;
		c = p->dados[p->n];
	  }
	  return c;
}

int main() {
	
	char buffer[tam_buffer], buffer2[tam_buffer];
	char c;
	int tam, i, j, n;
	pilha p1;
	fgets(buffer, tam_buffer, stdin);

	pilha_init(&p1);
	
	tam=strlen(buffer) - 1;
	
	i=0;
	n=0;
	while(buffer[i] != '\0'){
		if(buffer[i] != ' '){
			if(buffer[i] != '\n')
				push(&p1,buffer[i]);
		}
		else{
			j=n;
			while((p1.n)>0){
				c=pop(&p1);
				buffer2[j]=c;
				j++;
			}
			n=j+1;
			buffer2[j]=' ';
		}
		i++;
	}
	j=n;
	while((p1.n)>0){
		c=pop(&p1);
		buffer2[j]=c;
		j++;
	}

	buffer2[j]='\0';

	printf("%s\n", buffer2);
	return 0;
}
