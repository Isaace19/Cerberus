#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome (const char str[]) {
	int i = 0;
	int j = strlen(str) - 1;

	while (i < j) {
		if (str[i] != str[j]) {
			return false;
		}

		i++;
		j--;
	}
	return true;
}
 
// alternative solution


int isPalindrome (char* str) {

	int l = 0;
	int h = strlen(str) - 1;

	if (str[l++] != str[h--]) {
		return 0;
	}

	return 1;
}
