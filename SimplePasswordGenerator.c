#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef char string[50];

void tampilMenu();
char randomSymbol (int index);
void createPassword(char pass[], int inputPanjang);


int uppercase, symbol, number;

int main(){
	int inputPanjang;
	char menu;
	do{
		printf("\n\tMasukkan Panjang Password yang Ingin diBuat (5-100): "); scanf("%d", &inputPanjang);
		if(inputPanjang < 5 || inputPanjang > 100){
			puts("\n\t[!] Input Melebihi atau Kurang dari Batas yang Sudah Ditentukan");
		}
	} while(inputPanjang < 5 || inputPanjang > 100);
	
	char pass[inputPanjang];
	do {
		system("cls");
		tampilMenu(); menu = getche();
		switch(menu){
			case '1':
				createPassword(pass, inputPanjang);
				printf("\n\tPassword : %s", pass);
				getch();
				break;
			case '2':
				if(uppercase == 1){
					uppercase = 0;
				} else {
					uppercase = 1;
				}
				break;
			case '3':
				if(number == 1){
					number = 0;
				} else {
					number = 1;
				}
				break;
			case '4':
				if(symbol == 1){
					symbol = 0;
				} else {
					symbol = 1;
				}
				break;
			case '0':
				break;
			default:
				puts("\t[!] Fitur tidak tersedia");
				break;
		}
	} while(menu!=0);
}

void tampilMenu(){
	puts("\n\t===== [Password Generator] =====");
	puts("\t[1] Create Password");
	if(uppercase == 1){
		puts("\t[2] Disable Uppercase");
	} else {
		puts("\t[2] Enable Uppercase");
	}
	if(number == 1){
		puts("\t[3] Disable Number");
	} else {
		puts("\t[3] Enable Number");
	}
	if(symbol == 1){
		puts("\t[4] Disable Symbol");
	} else {
		puts("\t[4] Enable Symbol");
	}
	printf("\t>>> ");
	
}

char randomSymbol(int index){
	char symbolset[] = "!@#$%^&*()_+-=[];:{};/?|";
	return symbolset[index];
}

void createPassword(char pass[], int inputPanjang){
	srand(time(NULL));
	int random, i, index;
	for(i=0; i<inputPanjang; i++){
		if(uppercase == 1){
			if(number == 1){
				if(symbol == 1){
					random = rand() % 4 + 1;
					if(random == 1){
						pass[i] = rand() % 26 + 'a';
					} else if(random == 2){
						pass[i] = rand() % 26 + 'A';
					} else if(random == 3){
						pass[i] = rand() % 10 + '0';
					} else {
						index = rand() % 24;
						pass[i] = randomSymbol(index);
					}
				} else {
					random = rand() % 3 + 1;
					if(random == 1){
						pass[i] = rand() % 26 + 'a';
					} else if(random == 2){
						pass[i] = rand() % 26 + 'A';
					} else {
						pass[i] = rand() % 10 + '0';
					}
				}
			} else {
				if(symbol == 1){
					random = rand() % 3 + 1;
					if(random == 1){
						pass[i] = rand() % 26 + 'a';
					} else if(random == 2){
						pass[i] = rand() % 26 + 'A';
					} else {
						index = rand() % 24;
						pass[i] = randomSymbol(index);
					}
				} else {
					random = rand() % 2 + 1;
					if(random == 1){
						pass[i] = rand() % 26 + 'a';
					} else {
						pass[i] = rand() % 26 + 'A';
					}
				}
			}
		} else {
			if(number == 1){
				if(symbol == 1){
					random = rand() % 3 + 1;
					if(random == 1){
						pass[i] = rand() % 26 + 'a';
					} else if(random == 2){
						pass[i] = rand() % 10 + '0';
					} else {
						index = rand() % 24;
						pass[i] = randomSymbol(index);
					}
				} else {
					random = rand() % 2 + 1;
					if(random == 1){
						pass[i] = rand() % 26 + 'a';
					} else {
						pass[i] = rand() % 10 + '0';
					}
				}
			} else {
				if(symbol == 1){
					random = rand() % 2 + 1;
					if(random == 1){
						pass[i] = rand() % 26 + 'a';
					} else {
						index = rand() % 24;
						pass[i] = randomSymbol(index);
					}
				} else {
					pass[i] = rand() % 26 + 'a';
				}
			}
		}
		
	}
}
