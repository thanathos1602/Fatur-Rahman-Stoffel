#include <stdio.h>
#include <windows.h>
#include "gameheader.h"
#include "Play.h"

void Fullscreen()
{
	keybd_event(VK_MENU,0x38,0,0);
	keybd_event(VK_RETURN,0x1c,0,0);
	keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
	keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}


int main(){
	Fullscreen();	
	printf("\n");
    printf("\t\t\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	printf("\t\t\t\t\t||                   SELAMAT DATANG DI GAME MENARA HANOI                                   ||\n");
	printf("\t\t\t\t\t||                            Oleh: FATUR RAHMAN STOFFEL - (1806148675)                    ||\n");
	printf("\t\t\t\t\t||                                  JOSEF ERIC     -       (1806148725)                    ||\n");
	printf("\t\t\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n");



	system("pause");
	system("cls");
	goto menu;
	menu:
	
	printf("\t\t\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	printf("\t\t\t\t\t||                            HANOI TOWER                                    ||\n");
	printf("\t\t\t\t\t||---------------------------------------------------------------------------||\n");
	printf("\t\t\t\t\t||---------------------------------------------------------------------------||\n");
	printf("\t\t\t\t\t||1. MULAI GAME                                                              ||\n");
	printf("\t\t\t\t\t||2. PETUNJUK CARA BERMAIN                                                   ||\n");
	printf("\t\t\t\t\t||3. LEADERBOARD                                                             ||\n");
	printf("\t\t\t\t\t||4. EXIT                                                                    ||\n");
	printf("\t\t\t\t\t||---------------------------------------------------------------------------||\n");
	printf("\t\t\t\t\t||                     MASUKKAN INPUT BILANGAN BULAT                         ||\n");
	printf("\t\t\t\t\t||---------------------------------------------------------------------------||\n");
	printf("\t\t\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	printf("\t\t\t\t\tPilihan Anda:");
	menu = (getch()-'0');
	system("cls");
	
	
		switch (menu)
		{
			case 1 :
			game();
			break;
			
			case 2 :
			petunjuk();
			break;
			
			case 3 :
			leaderboard();
			break;
			
			case 4 :
			return 0;
			
			default :
			handling();
			goto menu;
		}
	
	
	
	
} 


int petunjuk ()// menu petunjuk cara bermain 
{
	how:
	printf("\n");	
	printf("\t\t\t\t\t-------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\t||                        PETUNJUK CARA BERMAIN                              ||\n");
	printf("\t\t\t\t\t||---------------------------------------------------------------------------||\n");
	printf("\t\t\t\t\t|| - Dalam satu waktu hanya boleh memindahkan satu piringan                  ||\n");
	printf("\t\t\t\t\t||                                                                           ||\n");
	printf("\t\t\t\t\t|| - Memindahkan piringan paling atas dari satu tiang dan memasukkannya      ||\n");
	printf("\t\t\t\t\t||   ke tiang yang lain                                                      ||\n");
	printf("\t\t\t\t\t||                                                                           ||\n");
	printf("\t\t\t\t\t|| - Tidak boleh meletakkan piringan diatas piringan lain yang lebih kecil   ||\n");
	printf("\t\t\t\t\t||   ukurannya                                                               ||\n");
	printf("\t\t\t\t\t||                                                                           ||\n");
	printf("\t\t\t\t\t|| - Terdapat tiga level difficulty yaitu easy, normal dan hard              ||\n");
	printf("\t\t\t\t\t||   > Easy   : ada 3 piringan yang harus disusun                            ||\n");
	printf("\t\t\t\t\t||   > Normal : ada 5 piringan yang harus disusun                            ||\n");
	printf("\t\t\t\t\t||   > Hard   : ada 7 piringan yang harus disusun                            ||\n");
	printf("\t\t\t\t\t||---------------------------------------------------------------------------||\n");
	printf("\t\t\t\t\t||  1. KEMBALI KE MENU AWAL                                                  ||\n");
	printf("\t\t\t\t\t||  2. MENUJU PERMAINAN                                                      ||\n");
	printf("\t\t\t\t\t||---------------------------------------------------------------------------||\n");
	printf("\n Pilihan:");
	menu = (getch()-'0');
	system("cls");
	
	
		switch (menu)
		{
			case 1 :
			return main();
			break;
			
			case 2 :
			game();
			break;
			
			
			default :
			handling();
			goto how;
		}

}

int handling()
{
		printf("\n");
	printf("\t\t\t\t\tAnda hanya boleh memilih angka yang tertera!!!");
	fflush(stdin);
	system ("pause");
	system("cls");	
}

int game()
{
	input :
			printf("\n");
	printf("\t\t\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	printf("\t\t\t\t\t||                            HANOI TOWER                                    ||\n");
	printf("\t\t\t\t\t||---------------------------------------------------------------------------||\n");
	printf("\t\t\t\t\t||                           DIFFICULTY LEVEL                                ||\n");
	printf("\t\t\t\t\t||---------------------------------------------------------------------------||\n");
	printf("\t\t\t\t\t||1.  EASY                                                                   ||\n");
	printf("\t\t\t\t\t||2.  NORMAL                                                                 ||\n");
	printf("\t\t\t\t\t||3.  HARD                                                                   ||\n");
	printf("\t\t\t\t\t||4.  BONUS                                                                  ||\n");
	printf("\t\t\t\t\t||5.  KEMBALI                                                                ||\n");			
	printf("\t\t\t\t\t||---------------------------------------------------------------------------||\n");
	printf("\t\t\t\t\t||                     MASUKKAN INPUT BILANGAN BULAT                         ||\n");
	printf("\t\t\t\t\t||---------------------------------------------------------------------------||\n");
	printf("\t\t\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	printf("\t\t\t\t\tPilihan Anda:");
	menu = (getch()-'0');
	system("cls");
	
	
		switch (menu)
		{
			case 1 :
			easy();
			break;
			
			case 2 :
			medium();
			break;
			
			case 3 :
			hard() ;
			break;
			
			case 4:
			bonus() ;
			break;
			
			case 5:
			return main();
			break;
			
			default :
			handling();
			goto input;
		}
		
}
int leaderboard()
{
	system("cls");
		printf("\n");
	printf("\t\t\t\t\tDaftar Leaderboard\n\n");
	char buffer[1024] ;
    char *record,*line;
    int i=0,j=0;
    int mat[100][100];
    FILE *fstream = fopen("leaderboard.csv","r");

	if(fstream == NULL)   {
    printf("\t\t\t\t\t<<======================================================>>\n");
	printf("\t\t\t\t\tBelum ada yang Mencetak Skor");
    printf("\t\t\t\t\t<<======================================================>>\n\n");
    system ("pause");
    main();
    }

	while((line=fgets(buffer,sizeof(buffer),fstream))!=NULL)
    {
		record = strtok(line,";");
		while(record != NULL)
			{
			 printf("\t\t\t\t\tData : %s",record) ;
//here you can put the record into the array as per your requirement.
			 mat[i][j++] = atoi(record) ;
			 record = strtok(NULL,";");
			}
		++i ;
	}
printf("\n");
system ("Pause");
system("cls");
main();
}

