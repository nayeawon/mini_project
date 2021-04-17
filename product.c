#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "product.h"

int menu() {
    int m;
    printf("\n==========================================================\n");
    printf("\n[1]목록 [2]추가 [3]수정 [4]삭제 [5]검색 [6]저장 [0]종료 >> ");
    scanf("%d", &m);
    return m;
}

int createProduct(product *p[], int count) {
    p[count] = (product *)malloc(sizeof(product));
    char blank[10];
    printf("제품명 > ");
    fgets(blank, 10, stdin);
    fgets(p[count]->name, 30, stdin);
    p[count]->name[strlen(p[count]->name)-1]='\0';
    printf("중량 > ");
    scanf("%d", &p[count]->weight);
    printf("판매가격 > ");
    scanf("%d", &p[count]->price);
    printf("별점(1~5) > ");
    scanf("%d", &p[count]->stars);
    printf("별점개수 > ");
    scanf("%d", &p[count]->num_stars);
    return 1;
}

int listProduct(product *p[], int count) {
    printf("\n번호 / 제품명 / 중량 / 판매가격 / 별점(1~5) / 별점개수\n");

    for (int i=0; i<count; i++) {
        if (p[i]->name[0]==0) continue;
        printf("%2d / ", i+1);
		printf("%s / ", p[i]->name);
		printf("%dg / ", p[i]->weight);
		printf("%d원 / ", p[i]->price);
		printf("%d점 / ", p[i]->stars);
		printf("%d개\n", p[i]->num_stars);
    }
    return 1;
}

int updateProduct(product *p[], int count) {
    listProduct(p, count);
    int num, check;
    printf("정보를 수정하려는 제품 번호 > ");
    scanf("%d", &num);
    if (num<=0 || num > count) {
        printf("올바른 제품 번호가 아닙니다.\n");
        return 0;
    }
    return createProduct(p, num-1);
}

int deleteProduct(product *p[], int count) {
    listProduct(p, count);
    int num;    //  삭제하려는 제품 번호
    int n;  //  삭제 여부 확인 체크
    printf("삭제하려는 제품 번호 > ");
    scanf("%d", &num);
    printf("%d / %s / %d / %d / %d점 / %d개\n", num, p[num-1]->name, p[num-1]->weight, p[num-1]->price, p[num-1]->stars, p[num-1]->num_stars);
	printf("정말로 삭제하시겠습니까?(삭제 : 1) > ");
    scanf("%d", &n);
    if (n == 1) {
        p[num-1]->name[0] = 0;
        return 1;
    }
    return 0;
}

void searchProduct(product *p[], int count) {
    int cmd;
    printf("제품검색 방법은? ( 1:제품명 2:가격 3:별개수 ) > ");
    scanf("%d", &cmd);
    switch (cmd) {
        case 1:
            searchNameProduct(p, count);
            break;
        case 2:
            searchPriceProduct(p, count);
            break;
        case 3:
            searchStarsProduct(p, count);
            break;
        default:
            printf("취소되었습니다.\n");
            break;
    }
}

void searchNameProduct(product *p[], int count) {
    int num, check=0;
    char blank[10];
    char str[100];
    printf("제품명 일부를 입력하세요 > ");
    fgets(blank, 10, stdin);
    fgets(str, 100, stdin);
    str[strlen(str)-1]='\0';
    printf("\n번호 / 제품명 / 중량 / 판매가격 / 별점(1~5) / 별점개수\n");
    for (int i=0; i<count; i++) {
        if (strstr(p[i]->name, str)) {
            printf("%d / %s / %d / %d / %d점 / %d개\n", i+1, p[i]->name, p[i]->weight, p[i]->price, p[i]->stars, p[i]->num_stars);
            check++;
        }
    }
    printf("총 %d개의 제품이 검색되었습니다.\n", check);
}

void searchPriceProduct(product *p[], int count) {
    int price, check=0;
    printf("원하는 가격대를 입력하세요(~원 이하) > ");
    scanf("%d", &price);
    printf("\n번호 / 제품명 / 중량 / 판매가격 / 별점(1~5) / 별점개수\n");
    for (int i=0; i<count; i++) {
        if (p[i]->price <= price) {
            printf("%d / %s / %d / %d / %d점 / %d개\n", i+1, p[i]->name, p[i]->weight, p[i]->price, p[i]->stars, p[i]->num_stars);
            check++;
        }
    }
    printf("총 %d개의 제품이 검색되었습니다.\n", check);
}

void searchStarsProduct(product *p[], int count) {
    int num, check=0;
    printf("원하는 별 개수를 입력하세요(~개 이상) > ");
    scanf("%d", &num);
    printf("\n번호 / 제품명 / 중량 / 판매가격 / 별점(1~5) / 별점개수\n");
    for (int i=0; i<count; i++) {
        if (p[i]->stars >= num) {
            printf("%d / %s / %d / %d / %d점 / %d개\n", i+1, p[i]->name, p[i]->weight, p[i]->price, p[i]->stars, p[i]->num_stars);
            check++;
        }
    }
    printf("총 %d개의 제품이 검색되었습니다.\n", check);
}

int saveProduct(product *p[], int count, int num_count) {
    FILE *file;
    file = fopen("save.txt", "w");
    fprintf(file, "제품 정보 (총 %d개)\n\n", num_count);
    fprintf(file, "번호 / 제품명 / 중량 / 판매가격 / 별점(1~5) / 별점개수\n");
    for (int i=0; i<count; i++) {
        if (p[i]->name[0] == 0) continue;
        fprintf(file, "%d / %s / %d / %d / %d점 / %d개\n", i+1, p[i]->name, p[i]->weight, p[i]->price, p[i]->stars, p[i]->num_stars);
    }
    fclose(file);
    return 1;
}

int loadProduct(product *p[], int count) {
    FILE *file;
	char name[100];
	char line[100];
	file = fopen("product.txt","r");
	while(!feof(file)){
		if(!fgets(name, 100, file)) break;
		p[count]=(product*)malloc(sizeof(product));
		name[strlen(name)-1]='\0';
		strcpy(p[count]->name, name);
		fgets(line, 100, file);
		sscanf(line,"%d %d %d %d",&(p[count]->weight),&(p[count]->price), &(p[count]->stars), &(p[count]->num_stars));
		count++;
	}
	fclose(file);
	printf("%d개의 제품 정보를 읽었습니다.\n",count);
	return count;
}
