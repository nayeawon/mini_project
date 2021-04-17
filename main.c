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
#define SEARCH 5
#define SAVE 6

int main() {
    product *p[SIZE];
    int cmd, check=0, count=0, edited_count=0;
    count = loadProduct(p, count);
    edited_count = count;
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
            case SEARCH:
                if (edited_count==0) {
                    printf("등록된 정보가 없습니다.\n");
                    break;
                }
                searchProduct(p, count);
                break;
            case SAVE:
                check = saveProduct(p, count);
                if (check == 1) {
                    printf("제품정보를 저장하였습니다.\n");
                }
                break;
            default:
                break;
        }
    } while(cmd != QUIT);
    printf("종료되었습니다.\n");
    return 0;
}
