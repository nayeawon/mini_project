#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "product.h"
#define SIZE 100
#define QUIT 0
#define READ 1
#define CREATE 2
#define UPDATE 3
#define DELETE 4

int main() {
    product *p[SIZE];
    int cmd, check=0, count=0, edited_count=0;
    do {
        cmd = menu();
        switch (cmd) {
            case READ:
                if (edited_count==0) {
                    printf("등록된 정보가 없습니다.\n");
                    break;
                }
                printf("\n제품 정보입니다. (총 %d개)\n", edited_count);
                check = listProduct(p, count);
                break;
            case CREATE:
                if (count == SIZE) {
                    printf("제품을 등록할 수 없습니다.\n");
                    break;
                }
                check = createProduct(p, count);
                if (check == 1) {
                    printf("추가되었습니다.\n");
                    count++;
                    edited_count++;
                }
                break;
            case UPDATE:
                if (edited_count==0) {
                    printf("등록된 정보가 없습니다.\n");
                    break;
                }
                check = updateProduct(p, count);
                if (check == 1) {
                    printf("수정되었습니다.\n");
                }
                break;
            case DELETE:
                if (edited_count==0) {
                    printf("등록된 정보가 없습니다.\n");
                    break;
                }
                check = deleteProduct(p, count);
                if (check == 1) {
                    printf("삭제되었습니다.\n");
                    edited_count--;
                }
                else if (check == 0) {
                    printf("취소되었습니다.\n");
                }
                break;
        }
    } while(cmd != QUIT);
    printf("종료되었습니다.\n");
    return 0;
}
int menu() {
    int m;
    printf("\n==========================================\n");
    printf("\n[1]목록 [2]추가 [3]수정 [4]삭제 [0]종료 >> ");
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
    int num;
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
    printf("%s / %d / %d / %d점 / %d개\n", p[num-1]->name, p[num-1]->weight, p[num-1]->price, p[num-1]->stars, p[num-1]->num_stars);
	printf("정말로 삭제하시겠습니까?(삭제 : 1) > ");
    scanf("%d", &n);
    if (n == 1) {
        p[num-1]->name[0] = 0;
        return 1;
    }
    return 0;
}
