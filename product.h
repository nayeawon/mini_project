typedef struct {
    char name[30]; // 제품명
    int weight; // 중량
    int price; // 판매가격
    int stars; // 별점 1~5까지 숫자
    int num_stars;  //  별점개수
} product;

int menu();

int createProduct(product *p[], int count); // create
/*
제품명, 제품중량, 제품 판매가격, 별점, 별점개수 입력받기
p->포인터배열 변수
count -> 현재까지 저장되어 있는 제품의 개수
*/
int listProduct(product *p[], int count);  //  read
/*
포인터배열에 저장되어있는 정보 반복문 사용하여 결과값 출력
p->포인터배열 변수
count -> 현재까지 저장되어 있는 제품의 개수
*/
int updateProduct(product *p[], int count);  //  update
/*
수정하고자 하는 물품의 이름을 입력받아 해당 제품의 정보를 포인터를 이용하여 update
p->포인터배열 변수
*/
int deleteProduct(product *p[], int count); //  delete
/*
제품명을 NULL로 변환하여 제품이 삭제되었다는 기능 구현
p->포인터배열 변수
count -> 현재까지 저장되어 있는 제품의 개수
*/

void searchProduct(product *p[], int count);    //  제품 검색

void searchNameProduct(product *p[], int count);    //  제품 이름 검색
/*
찾고자 하는 제품의 이름을 입력받아
strcmp를 이용하여 검색 후 결과출력
p->포인터배열 변수
count -> 현재까지 저장되어 있는 제품의 개수
*/
void searchPriceProduct(product *p[], int count); // 제품 가격 검색
/*
원하는 가격 대를 입력하여
반복문 사용 -> 원하는 가격 대 범위 안에 있으면 결과 출력
p->포인터배열 변수
count -> 현재까지 저장되어 있는 제품의 개수
*/
void searchStarsProduct(product *p[], int count); // 제품 별개수 검색
/*
원하는 제품 별개수를 입력받아
입력받은 별 개수와 같은 개수가 저장되어있는 제품의 정보 출력
p->포인터배열 변수
count -> 현재까지 저장되어 있는 제품의 개수
*/

int saveProduct(product *p[], int count, int num_count);
int loadProduct(product *p[], int count);   //  제품 정보 불러오기
