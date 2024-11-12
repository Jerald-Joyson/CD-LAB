// w = a + b


int main(){
	FILE *file = fopen("input.txt","r");
	
	if(!file){
		printf("file not found! \n");
		return 1;
		}
	char target[3],operator[2],operandOne[2],operandTwo[2],equals[2];
	while(fscan(file,"%s %s %s %s %s",target,equals,operandOne,operator,operandTwo) != EOF){
		prinf("MOV AX, [%s]\n",operandOne);
		
		switch(operator[0]){
			case '+':
				printf("ADD AX, [%s]\n",operandTwo);
				break;
			case '-':
				printf("SUB AX, [%s]\n",operandTwo);
				break;
			case '*':
				printf("MOV BX, [%s]\nMUL BX\n",operandTwo);
				break;
			case '/':
				printf("ADD AX, [%s]\nDIV BX\n",operandTwo);
				break;	
			}
			printf("MOV [%s], AX\n",target);
		}
	}
