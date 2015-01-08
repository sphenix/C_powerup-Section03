/* Name : screenOut.c	ver 1.2
 * Content : 콘솔 출력을 위한 함수들의 정의
 * Implementation : YSW
 *
 * Last modified 2015/01/05
 */
#include "common.h"
#include "cusInfo.h"
#include "dvdInfo.h"
#include "screenOut.h"

/* 프로그램 사용을 위한 메뉴 */
void ShowMenu(void)
{
	system("clear");	// stdlib.h

	printf("---------- 메 뉴 ----------- \n");
	printf(" 1. 신규가입 \n");
	printf(" 2. 고객검색 \n");
	printf("---------------------------- \n");
	printf(" 3. DVD 등록 \n");
	printf(" 4. DVD 검색 \n");
	printf("---------------------------- \n");
	printf(" 5. DVD 대여 \n");
	printf(" 6. DVD 반납 \n");
	printf("---------------------------- \n");
	printf(" 7. DVD 대여고객 전체 조회 \n");
	printf(" 8. 종 료 \n");
	printf("---------------------------- \n");
	printf("선택>> ");
}

/* 고객 개인의 기본 정보 출력 */
void ShowCustomerInfo(cusInfo *pCus)
{
	system("clear");	// stdlib.h

	printf("+--------------------------- \n");
	printf("| => ID : %s \n", pCus->ID);
	printf("| => 이름 : %s \n", pCus->name);
	printf("| => 전화번호 : %s \n", pCus->phoneNum);
	printf("+--------------------------- \n\n");

	getchar();
}

/* DVD 기본 정보 출력 */
void ShowDVDInfo(dvdInfo *pDVD)
{
	system("clear");	// stdlib.h

	printf("+--------------------------- \n");
	printf("| => ISBN : %s \n", pDVD->ISBN);
	printf("| => 타이틀 : %s \n", pDVD->title);
	printf("| => 쟝르 : "), ShowGenre(pDVD->genre), puts("");
	printf("+--------------------------- \n\n");

	getchar();
}

void ShowGenre(int genre)
{
	switch(genre)
	{
	case ACTION:
		fputs("액션", stdout);
		break;
	case COMIC:
		fputs("코믹", stdout);
		break;
	case SF:
		fputs("SF", stdout);
		break;
	case ROMANTIC:
		fputs("로맨스", stdout);
		break;
	}
}

void ShowDVDRentList()
{
	
}
/* end of file */

