/* Name : main.c	ver 1.2
 * Content : DVD 대여 관리 프로그램 main
 * Implementation : YSW
 *
 * Last modified 2015/02/25
 */

#include "common.h"
#include "blManager.h"
#include "cusInfoAccess.h"
#include "screenOut.h"

enum {CUS_REGIST=1, CUS_SEARCH, DVD_REGIST, DVD_SEARCH, DVD_RENT, DVD_RETURN, DVD_RENT_ALLCUS, DVD_CUS_ALLRENT, QUIT};

int main(void)
{
	int inputMenu = 0;

    initDATA();

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

		case DVD_RENT:
			RentDVD();
			break;

		case DVD_RETURN:
			ReturnDVD();
			break;

        case DVD_RENT_ALLCUS:
            ShowDVDRentAllCusInfo();
            break;

		case DVD_CUS_ALLRENT:
			ShowDVDCusAllRentInfo();
			break;
		
		}

		if (inputMenu == QUIT)
		{
			endDATA();
            puts("이용해 주셔서 고마워요~");
			break;
		}
	}
	return 0;
}

/* end of file */
