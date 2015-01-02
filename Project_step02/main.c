/* Name : main.c	ver 1.0
 * Content : DVD 대여 관리 프로그램 main
 * Implementation : YSW
 *
 * Last modified 2014/12/26
 */

#include "common.h"
#include "cusManager.h"
#include "dvdManager.h"
#include "screenOut.h"

enum {CUS_REGIST=1, CUS_SEARCH, DVD_REGIST, DVD_SEARCH, QUIT};

int main(void)
{
	int inputMenu = 0;

	while (1)
	{
		ShowMenu();
		scanf("%d", &inputMenu);
		while (getchar() != '\n');

		switch (inputMenu)
		{
		case CUS_REGIST:
			RegistCustomer();
			break;

		case CUS_SEARCH:
			SearchCusInfo();
			break;

		case DVD_REGIST:
			RegistDVD();
			break;

		case DVD_SEARCH:
			SearchDVDInfo();
			break;
		}

		if (inputMenu == QUIT)
		{
			puts("이용해 주셔서 고마워요~");
			break;
		}
	}
	return 0;
}

/* end of file */
