#include <stdio.h>

int main(void) {
	printf("Enter size:");
	int line = 0;
	scanf("%d", &line);
	int i = 0;
	int left = 0;
	int right = line - 1;
	int flag = 0;
	while (i < line) {
		int j = 0;
		while (j <= line/2) {
			if ((j-left)%4 == 0) {
				printf("*");
			}
			else {
				printf("-");
			}
			j++;
		}
		int k = line/2+1;
		while (k < line) {
			if ((right-k) % 4 == 0) {
				printf("*");
			}
			else {
				printf("-");
			}
			k++;
		}
		if (flag == 0) {
			left++;
			right--;
		}
		else {
			left--;
			right++;
		}
		if (left == right) {
			flag = 1;
		}
		printf("\n");
		i++;
	}
	return 0;
}