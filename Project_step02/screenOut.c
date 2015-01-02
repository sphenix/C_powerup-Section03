/* Name : screenOut.c	ver 1.1
 * Content : 콘솔 출력을 위한 함수들의 정의
 * Implementation : YSW
 *
 * Last modified 2015/01/02
 */
#include "common.h"
#include "cusInfo.h"
#include "dvdInfo.h"

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
	printf(" 5. 종 료 \n");
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

	switch(pDVD->genre)
	{
	case ACTION:
		puts("| => 쟝르 : 액션");
	  	break;
	
	case COMIC:
	  	puts("| => 쟝르 : 코믹");
	  	break;
	
	case SF:
	  	puts("| => 쟝르 : SF");
	  	break;
	
	case ROMANTIC:
	  	puts("| => 쟝르 : 로맨틱");
	  	break;
	
	default:
		break;
	}
	printf("+--------------------------- \n\n");

	getchar();
}


/* end of file */

