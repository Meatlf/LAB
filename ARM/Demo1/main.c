/*
 * main.c
 *
 *  Created on: 2019Äê4ÔÂ15ÈÕ
 *      Author: tztang
 */
#include<stdio.h>

extern int asm_add(int x, int y);

int main(){
	int a = 2;
	int b = 3;
	int asm_result;
	int check_result;

	check_result = a + b;

	asm_result = asm_add(a, b);

	if(asm_result != check_result)
		printf("ERROR!\n");
	else
		printf("PASS!\n");

	return 0;
}
