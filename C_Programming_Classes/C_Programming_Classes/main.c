#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

struct Employee {
	char name[21];
	int age;
	double ranking;
};

void input();
void chkRanking();
void displayRanking(double ranking);

void main() {
	input();
	chkRanking();
}

void input() {
	struct Employee emp;
	FILE* file = fopen("employee.txt", "w");
	if (!file) {
		printf("Open file error...\n");
		exit(-1);
	}
	printf("Enter employee name (XXX to stop): ");
	rewind(stdin);
	gets(emp.name);
	while (strcmp(emp.name, "XXX") != 0) {
		printf("Enter age: ");
		scanf("%d", &emp.age);

		printf("Enter ranking: ");
		scanf("%lf", &emp.ranking);

		printf("\n");
		fprintf(file, "%s|%d|%f\n", emp.name, emp.age, emp.ranking);

		printf("Enter employee name (XXX to stop): ");
		rewind(stdin);
		gets(emp.name);
	}
	printf("\n\n");
	fclose(file);
}

void chkRanking() {
	struct Employee emp;
	FILE* file = fopen("employee.txt", "r");
	printf("Listing of Employess (Ranking above 3)\n");
	printf("--------------------------------------\n");
	while (fscanf(file, "%[^|]|%d|%lf\n", emp.name, &emp.age, &emp.ranking) != EOF) {
		if (emp.ranking > 3.0) {
			printf("Name: %s\n", emp.name);
			printf("Age: %d\n", emp.age);
			displayRanking(emp.ranking);
			printf("\n\n");
		}
	}
}

void displayRanking(double ranking) {
	printf("Ranking: %.2f\n", ranking);
}