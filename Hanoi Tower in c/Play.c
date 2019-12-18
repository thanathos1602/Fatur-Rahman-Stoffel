#include<stdio.h>
#include<windows.h>
#include "Play.h"
#include <time.h>
int easy()
{	
// Isi Array 
	int A[3]={1,2,3}; // tiang ke 1
	int B[3]={0,0,0}; // tiang ke 2
	int C[3]={0,0,0}; // tiang ke 3
	int D[3]={1,2,3}; // array untuk mengecek apakah sudah selesai atau belum	
// variabel yang dipakai untuk Loop 	
	int f,k,t,i,j,selesai=0,s; 
	int step=0; // langkahnya berapa kali
	int nyawa=3; // nyawanya ada 3
	int counter; // untuk mengecek
	int IsiA=3; int IsiB=0; int IsiC=0;
	int score;

// loop menggunakan Do-While untuk gamenya 
	printf("\t\t\t\t\tMasukkan nama : ");
	scanf("%s", &name);fflush(stdin);
	printf("\n");	
	do{
// Loop menampilkan Tiang ke- n
	printf("\t\t\t\t\tTiang 1\t\t\t\tTiang 2\t\t\t\tTiang 3\n");
	for (i=0; i<3; i++)
	{
		// Array A
		printf("\t\t\t\t\t");
		for(k=0;k<3-A[i]; k++)
		{
			printf(" ");
		}
		for(j=0; j<2*A[i]-1; j++)
		{
			printf("*");
		}
		printf("\t\t\t\t");
		//Array B
		for(k=0;k<3-B[i]; k++)
		{
			printf(" ");
		}
		for(j=0; j<2*B[i]-1; j++)
		{
			printf("*");
		}
		//Array C
		printf("\t\t\t\t");
		for(k=0;k<3-C[i]; k++)
		{
			printf(" ");
		}
		for(j=0; j<2*C[i]-1; j++)
		{
			printf("*");
		}
		printf("\n");		
	}
	//menampikan nyawa dan langkah
	printf("\t\t\t\t\t\t\t\t\tNyawa = %d \n",nyawa);
	printf("\t\t\t\t\t\t\t\t\tStep= %d \n",step);	
	//meminta input User untuk memindahkan Disk teratas dari tiang awal ke tiang tujuan
	printf("\n\t\t\t\t\t\t\t\t\tPindahkan dari tiang ke - "); scanf("%d",&f) ;printf("\n\t\t\t\t\t\t\t\t\tKedalam tiang ke - "); scanf("%d",&t);
	//source code pemindahan nya
	if (f==1) // f adalah tiang awal
	{
		if (t==2) // t adalah tiang akhir
		{
			for(i=0; i<3;i++)
			{
				if (A[i]!=0) // pindahkan saat isi dari tiang teratas adalah bukan 0
				{
					if (B[2-IsiB]==0) // pindahkan ketiang terbawa dari tiang tujuan
					{
						B[2-IsiB]=A[i];
						A[i]=0;
						IsiB=IsiB+1; // isi dari tiang tujuan bertambah
						IsiA=IsiA-1; // sedangkan isi dari tiang awal berkurang
						for(j=0;j<3; j++) // loop untuk mengurangi nyawa jika disk besar diatas disk kecil 
						{
							if (j<2)
								{
									if (B[j]>B[j+1])
									{
										counter=0;	
										nyawa=nyawa-1;
										counter=1;
										if (counter=1)
										{
											j=3; // j=3 agar loop langsung berhenti.. karena cuma 1 kali cek per 1 kali langkah 
										}
									}
								}
							else
								{
									nyawa=nyawa; 
								}	
						}
						i=3; // i=3 untuk menghentikan loop 
						step=step+1;
					}
				}
			}
		}
		else if (t==3)
		{
			for(i=0; i<3;i++)
			{
				if (A[i]!=0)
				{
					if (C[2-IsiC]==0)
					{
						C[2-IsiC]=A[i];
						A[i]=0;
						IsiC=IsiC+1;
						IsiA=IsiA-1;
						for(j=0;j<3; j++)
						{
							if (j<2)
								{
									if (C[j]>C[j+1])
									{
										counter=0;	
										nyawa=nyawa-1;
										counter=1;
										if (counter=1)
										{
											j=3;
										}
									}
								}
							else
								{
									nyawa=nyawa;
								}	
						}
						i=3;
						step=step+1;
					// loop khusus untuk tiang ke -3 untuk mengecek apakah sudah sama selesai atau belum	
					for(s=0; s<3; s++)
					{
						if (C[s]==D[s])
							{
								selesai=selesai+1;			
							}	
					}
					if (selesai!=3)
						{
							selesai=0;
						} 																			
					}
				}
			}		
		}
		// error handling saat input tidak sesuai ketentuan seperti huruf,angka selain 1,2,3, atau angka yang sama dengan input tiang awal
		else
		{
			printf("\nInput tidak bisa sama ataupun selain angka 1 sampai 3");
		}	
	}
	else if (f==2)
	{
		if (t==1)
		{
			for(i=0; i<3;i++)
			{
				if (B[i]!=0)
				{
					if (A[2-IsiA]==0)
					{
						A[2-IsiA]=B[i];
						B[i]=0;
						IsiA=IsiA+1;
						IsiB=IsiB-1;
						for(j=0;j<3; j++)
						{
							if (j<2)
								{
									if (A[j]>A[j+1])
									{
										counter=0;	
										nyawa=nyawa-1;
										counter=1;
										if (counter=1)
										{
											j=3;
										}
									}
								}
							else
								{
									nyawa=nyawa;
								}							
						}						
						i=3;
						step=step+1;
					}
				}
			}
		}
		else if (t==3)
		{
			for(i=0; i<3;i++)
			{
				if (B[i]!=0)
				{
					if (C[2-IsiC]==0)
					{
						C[2-IsiC]=B[i];
						B[i]=0;
						IsiC=IsiC+1;
						IsiB=IsiB-1;
						for(j=0;j<3; j++)
						{
							if (j<2)
								{
									if (C[j]>C[j+1])
									{
										counter=0;	
										nyawa=nyawa-1;
										counter=1;
										if (counter=1)
										{
											j=3;
										}
									}
								}
							else
								{
									nyawa=nyawa;
								}							
						}						
						i=3;
						step=step+1;
					// loop khusus untuk tiang ke -3 untuk mengecek apakah sudah sama selesai atau belum	
					for(s=0; s<3; s++)
					{
						if (C[s]==D[s])
							{
								selesai=selesai+1;			
							}	
					}
					if (selesai!=3)
						{
							selesai=0;
						}
					}
				}
			}		
		}
		else
		{
			printf("\nInput tidak bisa sama ataupun selain angka 1 sampai 3");
		}			
	}
	else if (f==3)
	{
		if (t==1)
		{
			for(i=0; i<3;i++)
			{
				if (C[i]!=0)
				{
					if (A[2-IsiA]==0)
					{
						A[2-IsiA]=C[i];
						C[i]=0;
						IsiA=IsiA+1;
						IsiC=IsiC-1;
						for(j=0;j<3; j++)
						{
							if (j<2)
								{
									if (A[j]>A[j+1])
									{
										counter=0;	
										nyawa=nyawa-1;
										counter=1;
										if (counter=1)
										{
											j=3;
										}
									}
								}
							else
								{
									nyawa=nyawa;
								}	
						step=step+1;						
						}
						step=step+1;												
						i=3;
					}
				}
			}
		}
		else if (t==2)
		{
			for(i=0; i<3;i++)
			{
				if (C[i]!=0)
				{
					if (C[2-IsiC]==0)
					{
						B[2-IsiB]=C[i];
						C[i]=0;
						IsiB=IsiB+1;
						IsiC=IsiC-1;
						for(j=0;j<3; j++)
						{
							if (j<2)
								{
									if (B[j]>B[j+1])
									{
										counter=0;	
										nyawa=nyawa-1;
										counter=1;
										if (counter=1)
										{
											j=3;
										}
									}
								}
							else
								{
									nyawa=nyawa;
								}							
						}						
						step=step+1;						
						i=3;
					}
				}
			}		
		}
		else
		{
			printf("\nInput tidak bisa sama ataupun selain angka 1 sampai 3\n\n");
		}			
	}
system("pause");
system("cls");	




}while(nyawa>0 && selesai<3);

//printf("\n\nselesainya = %d",selesai);
    if (nyawa==1) {
		printf("\t\t\t\t\tSELAMAT KAMU BERHASIL MENYELESAIKAN GAME");
        score = 1*100;
		DisplayNyawaDanStep(nyawa,step);
        FILE *out=fopen("leaderboard.csv","a");
        fprintf(out,"%s,%d,EASY\n",name, score,step);
        fclose(out);
		}
        
        if(nyawa ==0){
			printf("\t\t\t\t\t\n\nNyawa Habis & Kamu Gagal");
        }
        
        if(nyawa==2){
		score = 2*100;
		printf("\t\t\t\t\tSELAMAT KAMU BERHASIL MENYELESAIKAN GAME");
		DisplayNyawaDanStep(nyawa,step);   
        FILE *out=fopen("leaderboard.csv","a");
        fprintf(out,"%s,%d,EASY\n",name, score,step);
        fclose(out);
        }
        
        if(nyawa==3){
		score =3*100;
		printf("\t\t\t\t\tSELAMAT KAMU BERHASIL MENYELESAIKAN GAME");

		DisplayNyawaDanStep(nyawa,step);    
        FILE *out=fopen("leaderboard.csv","a");
        fprintf(out,"%s,%d,EASY\n",name, score,step);
        fclose(out);	
        }
    

}

	
int medium()
{
	
	int A[5]={1,2,3,4,5};
	int B[5]={0,0,0,0,0};
	int C[5]={0,0,0,0,0};	
	int k,f,t,i,j,selesai=0,s;
	int D[5]={1,2,3,4,5};
	int step=0;
	int nyawa=3;
	int counter,score;
	

	int IsiA=5; int IsiB=0; int IsiC=0;
	printf(" Masukkan nama : ");
	scanf("%s", &name);fflush(stdin);	
	do{
	printf(" Tiang 1\t\t\t\tTiang 2\t\t\t\tTiang 3\n");
	for (i=0; i<5; i++)
	{
		// Array A
		for(k=0;k<5-A[i]; k++)
		{
			printf(" ");
		}
		for(j=0; j<2*A[i]-1; j++)
		{
			printf("*");
		}
		printf("\t\t\t\t");
		//Array B
		for(k=0;k<5-B[i]; k++)
		{
			printf(" ");
		}
		for(j=0; j<2*B[i]-1; j++)
		{
			printf("*");
		}
		//Array C
		printf("\t\t\t\t");
		for(k=0;k<5-C[i]; k++)
		{
			printf(" ");
		}
		for(j=0; j<2*C[i]-1; j++)
		{
			printf("*");
		}
		printf("\n");		
	}
	printf("\n\tNyawa = %d \n",nyawa);
	printf("\n\tStep= %d \n",step);		
	printf("\nPindahkan dari tiang ke - "); scanf("%d",&f) ;printf("\nKedalam tiang ke - "); scanf("%d",&t);
	if (f==1)
	{
		if (t==2)
		{
			for(i=0; i<5;i++)
			{
				if (A[i]!=0)
				{
					if (B[4-IsiB]==0)
					{
						B[4-IsiB]=A[i];
						A[i]=0;
						IsiB=IsiB+1;
						IsiA=IsiA-1;
						for(j=0;j<5; j++)
						{
							if (j<4)
								{
									if (B[j]>B[j+1])
									{
										counter=0;	
										nyawa=nyawa-1;
										counter=1;
										if (counter=1)
										{
											j=5;
										}
									}
								}
							else
								{
									nyawa=nyawa;
								}	
						}
						i=5;
						step=step+1;
					}
				}
			}
		}
		else if (t==3)
		{
			for(i=0; i<5;i++)
			{
				if (A[i]!=0)
				{
					if (C[4-IsiC]==0)
					{
						C[4-IsiC]=A[i];
						A[i]=0;
						IsiC=IsiC+1;
						IsiA=IsiA-1;
						for(j=0;j<5; j++)
						{
							if (j<4)
								{
									if (C[j]>C[j+1])
									{
										counter=0;	
										nyawa=nyawa-1;
										counter=1;
										if (counter=1)
										{
											j=5;
										}
									}
								}
							else
								{
									nyawa=nyawa;
								}	
						}
						i=5;
						step =step+1;
					// loop khusus untuk tiang ke -3 untuk mengecek apakah sudah sama selesai atau belum	
					for(s=0; s<5; s++)
					{
						if (C[s]==D[s])
							{
								selesai=selesai+1;			
							}	
					}
					if (selesai!=5)
						{
							selesai=0;
						} 									
					}
				}
			}		
		}
		else
		{
			printf("\nInput tidak bisa sama ataupun selain angka 1 sampai 3");
		}	
	}
	else if (f==2)
	{
		if (t==1)
		{
			for(i=0; i<5;i++)
			{
				if (B[i]!=0)
				{
					if (A[4-IsiA]==0)
					{
						A[2-IsiA]=B[i];
						B[i]=0;
						IsiA=IsiA+1;
						IsiB=IsiB-1;
						for(j=0;j<5; j++)
						{
							if (j<4)
								{
									if (A[j]>A[j+1])
									{
										counter=0;	
										nyawa=nyawa-1;
										counter=1;
										if (counter=1)
										{
											j=5;
										}
									}
								}
							else
								{
									nyawa=nyawa;
								}	
						}						
						i=5;
						step=step+1;
					}
				}
			}
		}
		else if (t==3)
		{
			for(i=0; i<5;i++)
			{
				if (B[i]!=0)
				{
					if (C[4-IsiC]==0)
					{
						C[4-IsiC]=B[i];
						B[i]=0;
						IsiC=IsiC+1;
						IsiB=IsiB-1;
						for(j=0;j<5; j++)
						{
							if (j<4)
								{
									if (C[j]>C[j+1])
									{
										counter=0;	
										nyawa=nyawa-1;
										counter=1;
										if (counter=1)
										{
											j=5;
										}
									}
								}
							else
								{
									nyawa=nyawa;
								}	
						}						
						i=5;
						step=step+1;
					// loop khusus untuk tiang ke -3 untuk mengecek apakah sudah sama selesai atau belum	
					for(s=0; s<5; s++)
					{
						if (C[s]==D[s])
							{
								selesai=selesai+1;			
							}	
					}
					if (selesai!=5)
						{
							selesai=0;
						} 			
					}
				}
			}		
		}
		else
		{
			printf("\nInput tidak bisa sama ataupun selain angka 1 sampai 3");
		}			
	}
	else if (f==3)
	{
		if (t==1)
		{
			for(i=0; i<5;i++)
			{
				if (C[i]!=0)
				{
					if (A[4-IsiA]==0)
					{
						A[4-IsiA]=C[i];
						C[i]=0;
						IsiA=IsiA+1;
						IsiC=IsiC-1;
						for(j=0;j<5; j++)
						{
							if (j<4)
								{
									if (A[j]>A[j+1])
									{
										counter=0;	
										nyawa=nyawa-1;
										counter=1;
										if (counter=1)
										{
											j=5;
										}
									}
								}
							else
								{
									nyawa=nyawa;
								}	
						}						
						i=5;
						step=step+1;
					}
				}
			}
		}
		else if (t==2)
		{
			for(i=0; i<5;i++)
			{
				if (C[i]!=0)
				{
					if (C[4-IsiC]==0)
					{
						B[4-IsiB]=C[i];
						C[i]=0;
						IsiB=IsiB+1;
						IsiC=IsiC-1;
						for(j=0;j<5; j++)
						{
							if (j<4)
								{
									if (B[j]>B[j+1])
									{
										counter=0;	
										nyawa=nyawa-1;
										counter=1;
										if (counter=1)
										{
											j=5;
										}
									}
								}
							else
								{
									nyawa=nyawa;
								}	
						}						
						i=5;
						step=step+1;
					}
				}
			}		
		}
		else
		{
			printf("\nInput tidak bisa sama ataupun selain angka 1 sampai 3\n\n");
		}			
	}
system("pause");
system("cls");	
}while(nyawa>0 && selesai<5);
//printf("\n\nselesainya = %d",selesai);
    if (nyawa==1) {
		printf("SELAMAT KAMU BERHASIL MENYELESAIKAN GAME");
        score = 1*100;
        printf("\t\t\t\t\t\t\t\t              ");
		DisplayNyawaDanStep(nyawa,step);
        FILE *out=fopen("leaderboard.csv","a");
        fprintf(out,"%s,%d,NORMAL\n",name, score,step);
        fclose(out);
		}
        
        if(nyawa ==0){
			printf("\n\nNyawa Habis");
        }
        
        if(nyawa==2){
		score = 2*100;
		printf("SELAMAT KAMU BERHASIL MENYELESAIKAN GAME");
        printf("\t\t\t\t\t\t\t\t              ");
		DisplayNyawaDanStep(nyawa,step);    
        FILE *out=fopen("leaderboard.csv","a");
        fprintf(out,"%s,%d,NORMAL\n",name, score,step);
        fclose(out);
        }
        
        if(nyawa==3){
		score =3*100;
		printf("SELAMAT KAMU BERHASIL MENYELESAIKAN GAME");
        printf("\t\t\t\t\t\t\t\t              ");
		DisplayNyawaDanStep(nyawa,step);      
        FILE *out=fopen("leaderboard.csv","a");
        fprintf(out,"%s,%d,NORMAL\n",name, score,step);
        fclose(out);	
        }
}

int hard()
{
	
	int A[7]={1,2,3,4,5,6,7};
	int B[7]={0,0,0,0,0,0,0};
	int C[7]={0,0,0,0,0,0,0};
	int D[7]={1,2,3,4,5,6,7};	
	int f,t,i,j,k,selesai=0,s;
	int step=0;
	int nyawa=3;
	int counter;
	int IsiA=7; int IsiB=0; int IsiC=0;
	int score;

// loop menggunakan Do-While untuk gamenya 
	printf(" Masukkan nama : ");
	scanf("%s", &name);fflush(stdin);		
	do{
	printf("  Tiang 1\t\t\t\tTiang 2\t\t\t\tTiang 3\n");
	for (i=0; i<7; i++)
	{
		// Array A
		for(k=0;k<7-A[i]; k++)
		{
			printf(" ");
		}
		for(j=0; j<2*A[i]-1; j++)
		{
			printf("*");
		}
		printf("\t\t\t\t");
		//Array B
		for(k=0;k<7-B[i]; k++)
		{
			printf(" ");
		}
		for(j=0; j<2*B[i]-1; j++)
		{
			printf("*");
		}
		//Array C
		printf("\t\t\t\t");
		for(k=0;k<7-C[i]; k++)
		{
			printf(" ");
		}
		for(j=0; j<2*C[i]-1; j++)
		{
			printf("*");
		}
		printf("\n");		
	}
	printf("\n\tNyawa = %d \n",nyawa);
	printf("\n\tStep= %d \n",step);	
	printf("\nPindahkan dari tiang ke - "); scanf("%d",&f) ;printf("\nKedalam tiang ke - "); scanf("%d",&t);
	if (f==1)
	{
		if (t==2)
		{
			for(i=0; i<7;i++)
			{
				if (A[i]!=0)
				{
					if (B[6-IsiB]==0)
					{
						B[6-IsiB]=A[i];
						A[i]=0;
						IsiB=IsiB+1;
						IsiA=IsiA-1;
						for(j=0;j<7; j++)
						{
							if (j<6)
								{
									if (B[j]>B[j+1])
									{
										counter=0;	
										nyawa=nyawa-1;
										counter=1;
										if (counter=1)
										{
											j=7;
										}
									}
								}
							else
								{
									nyawa=nyawa;
								}	
						}
						i=7;
						step=step+1;
					}
				}
			}
		}
		else if (t==3)
		{
			for(i=0; i<7;i++)
			{
				if (A[i]!=0)
				{
					if (C[6-IsiC]==0)
					{
						C[6-IsiC]=A[i];
						A[i]=0;
						IsiC=IsiC+1;
						IsiA=IsiA-1;
						for(j=0;j<7; j++)
						{
							if (j<6)
								{
									if (C[j]>C[j+1])
									{
										counter=0;	
										nyawa=nyawa-1;
										counter=1;
										if (counter=1)
										{
											j=7;
										}
									}
								}
							else
								{
									nyawa=nyawa;
								}	
						}
						i=7;
						step=step+1;
					// loop khusus untuk tiang ke -3 untuk mengecek apakah sudah sama selesai atau belum	
					for(s=0; s<7; s++)
					{
						if (C[s]==D[s])
							{
								selesai=selesai+1;			
							}	
					}
					if (selesai!=7)
						{
							selesai=0;
						} 									
					}
					}
				}
			}		
		
		else
		{
			printf("\nInput tidak bisa sama ataupun selain angka 1 sampai 3");
		}	
	}
	else if (f==2)
	{
		if (t==1)
		{
			for(i=0; i<7;i++)
			{
				if (B[i]!=0)
				{
					if (A[6-IsiA]==0)
					{
						A[6-IsiA]=B[i];
						B[i]=0;
						IsiA=IsiA+1;
						IsiB=IsiB-1;
						for(j=0;j<7; j++)
						{
							if (j<6)
								{
									if (A[j]>A[j+1])
									{
										counter=0;	
										nyawa=nyawa-1;
										counter=1;
										if (counter=1)
										{
											j=7;
										}
									}
								}
							else
								{
									nyawa=nyawa;
								}	
						}						
						i=7;
						step=step+1;
					}
				}
			}
		}
		else if (t==3)
		{
			for(i=0; i<7;i++)
			{
				if (B[i]!=0)
				{
					if (C[6-IsiC]==0)
					{
						C[6-IsiC]=B[i];
						B[i]=0;
						IsiC=IsiC+1;
						IsiB=IsiB-1;
						for(j=0;j<7; j++)
						{
							if (j<5)
								{
									if (C[j]>C[j+1])
									{
										counter=0;	
										nyawa=nyawa-1;
										counter=1;
										if (counter=1)
										{
											j=7;
										}
									}
								}
							else
								{
									nyawa=nyawa;
								}	
						}						
						i=7;
						step=step+1;
					// loop khusus untuk tiang ke -3 untuk mengecek apakah sudah sama selesai atau belum	
					for(s=0; s<7; s++)
					{
						if (C[s]==D[s])
							{
								selesai=selesai+1;			
							}	
					}
					if (selesai!=7)
						{
							selesai=0;
						} 									
					}						
					}
				}
		}		
		else
		{
			printf("\nInput tidak bisa sama ataupun selain angka 1 sampai 3");
		}			
	}
	else if (f==3)
	{
		if (t==1)
		{
			for(i=0; i<7;i++)
			{
				if (C[i]!=0)
				{
					if (A[6-IsiA]==0)
					{
						A[6-IsiA]=C[i];
						C[i]=0;
						IsiA=IsiA+1;
						IsiC=IsiC-1;
						for(j=0;j<7; j++)
						{
							if (j<6)
								{
									if (A[j]>A[j+1])
									{
										counter=0;	
										nyawa=nyawa-1;
										counter=1;
										if (counter=1)
										{
											j=7;
										}
									}
								}
							else
								{
									nyawa=nyawa;
								}	
						}						
						i=7;
						step=step+1;
					}
				}
			}
		}
		else if (t==2)
		{
			for(i=0; i<7;i++)
			{
				if (C[i]!=0)
				{
					if (C[6-IsiC]==0)
					{
						B[6-IsiB]=C[i];
						C[i]=0;
						IsiB=IsiB+1;
						IsiC=IsiC-1;
						for(j=0;j<7; j++)
						{
							if (j<6)
								{
									if (B[j]>B[j+1])
									{
										counter=0;	
										nyawa=nyawa-1;
										counter=1;
										if (counter=1)
										{
											j=7;
										}
									}
								}
							else
								{
									nyawa=nyawa;
								}	
						}						
						i=7;
						step=step+1;
					}
				}
			}		
		}
		else
		{
			printf("\nInput tidak bisa sama ataupun selain angka 1 sampai 3\n\n");
		}			
	}
system("pause");
system("cls");	
}while(nyawa>0 && selesai<7);
   if (nyawa==1) {
		printf("SELAMAT KAMU BERHASIL MENYELESAIKAN GAME");
        score = 1*100;
        printf("\t\t\t\t\t\t\t\t              ");
		DisplayNyawaDanStep(nyawa,step);
        FILE *out=fopen("leaderboard.csv","a");
        fprintf(out,"%s,%d,HARD\n",name, score,step);
        fclose(out);
		}
        
        if(nyawa ==0){
			printf("\n\nNyawa Habis");
        }
        
        if(nyawa==2){
		score = 2*100;
		printf("SELAMAT KAMU BERHASIL MENYELESAIKAN GAME");
        printf("\t\t\t\t\t\t\t\t              ");
		DisplayNyawaDanStep(nyawa,step);        
        FILE *out=fopen("leaderboard.csv","a");
        fprintf(out,"%s,%d,HARD\n",name, score,step);
        fclose(out);
        }
        
        if(nyawa==3){
		score =3*100;
		printf("SELAMAT KAMU BERHASIL MENYELESAIKAN GAME");
        printf("\t\t\t\t\t\t\t\t              ");
		DisplayNyawaDanStep(nyawa,step);     
        FILE *out=fopen("leaderboard.csv","a");
        fprintf(out,"%s,%d,HARD\n",name, score,step);
        fclose(out);	
        }
}

int bonus()
{
	
	int A[10]={1,2,3,4,5,6,7,8,9,10};
	int B[10]={0,0,0,0,0,0,0,0,0,0,0};
	int C[10]={0,0,0,0,0,0,0,0,0,0,0};
	int D[10]={1,2,3,4,5,6,7,8,9,10};	
	int f,t,i,j,selesai=0,k,ye,s;
	int step=0;
	int nyawa=3;
	int counter;
	int IsiA=10; int IsiB=0; int IsiC=0;
	int score;

// loop menggunakan Do-While untuk gamenya 
	printf(" Masukkan nama : ");
	scanf("%s", &name);fflush(stdin);	
	srand((time(NULL)));
	for(i=0;i<10;i++)
	{
		j= (rand()%9)+1;
		ye = A[i];
		A[i]= A[j];
		A[j]=ye;
	}	
	do{
	printf("       Tiang 1\t\t\t\tTiang 2\t\t\t\tTiang 3\n");
	for (i=0; i<10; i++)
	{
		{
		// Array A
		for(k=0;k<10-A[i]; k++)
		{
			printf(" ");
		}
		if (i %2 ==0)
		{
		for(j=0; j<2*A[i]-1; j++)
		{
				printf("*");
		}			
		}
		else
		{
		for(j=0; j<2*A[i]-1; j++)
		{
				printf("#");
		}			
		}
		printf("\t\t\t\t");
		//Array B
		for(k=0;k<10-B[i]; k++)
		{
			printf(" ");
		}
		if (i %2 ==0)
		{
		for(j=0; j<2*B[i]-1; j++)
		{
				printf("*");
		}			
		}
		else
		{
		for(j=0; j<2*B[i]-1; j++)
		{
				printf("#");
		}			
		}
		//Array C
		printf("\t\t\t\t");
		for(k=0;k<10-C[i]; k++)
		{
			printf(" ");
		}
		if (i %2 ==0)
		{
		for(j=0; j<2*C[i]-1; j++)
		{
				printf("*");
		}			
		}
		else
		{
		for(j=0; j<2*C[i]-1; j++)
		{
				printf("#");
		}			
		}			
		printf("\n");		
	}
	}
	//printf("\n\tNyawa = %d \n",nyawa);
	printf("\n\tStep= %d \n",step);	
	printf("\nPindahkan dari tiang ke - "); scanf("%d",&f) ;printf("\nKedalam tiang ke - "); scanf("%d",&t);
	if (f==1)
	{
		if (t==2)
		{
			for(i=0; i<10;i++)
			{
				if (A[i]!=0)
				{
					if (B[9-IsiB]==0)
					{
						B[9-IsiB]=A[i];
						A[i]=0;
						IsiB=IsiB+1;
						IsiA=IsiA-1;
						for(j=0;j<10; j++)
						{
							if (j<9)
								{
									if (B[j]>B[j+1])
									{
										counter=0;	
										nyawa=nyawa-1;
										counter=1;
										if (counter=1)
										{
											j=10;
										}
									}
								}
							else
								{
									nyawa=nyawa;
								}	
						}
						i=10;
						step=step+1;						
					}
				}
			}
		}
		else if (t==3)
		{
			for(i=0; i<10;i++)
			{
				if (A[i]!=0)
				{
					if (C[9-IsiC]==0)
					{
						C[9-IsiC]=A[i];
						A[i]=0;
						IsiC=IsiC+1;
						IsiA=IsiA-1;
						for(j=0;j<10; j++)
						{
							if (j<9)
								{
									if (C[j]>C[j+1])
									{
										counter=0;	
										nyawa=nyawa-1;
										counter=1;
										if (counter=1)
										{
											j=10;
										}
									}
								}
							else
								{
									nyawa=nyawa;
								}	
						}
						i=10;
						step=step+1;
					for(s=0; s<10; s++)
					{
						if (C[s]==D[s])
							{
								selesai=selesai+1;			
							}	
					}
					if (selesai!=10)
						{
							selesai=0;
						} 
					}
				}
			}		
		}
		else
		{
			printf("\nInput tidak bisa sama ataupun selain angka 1 sampai 3");
		}	
	}
	else if (f==2)
	{
		if (t==1)
		{
			for(i=0; i<10;i++)
			{
				if (B[i]!=0)
				{
					if (A[9-IsiA]==0)
					{
						A[9-IsiA]=B[i];
						B[i]=0;
						IsiA=IsiA+1;
						IsiB=IsiB-1;
						for(j=0;j<10; j++)
						{
							if (j<9)
								{
									if (A[j]>A[j+1])
									{
										counter=0;	
										nyawa=nyawa-1;
										counter=1;
										if (counter=1)
										{
											j=10;
										}
									}
								}
							else
								{
									nyawa=nyawa;
								}	
						}						
						i=10;
						step=step+1;						
					}
				}
			}
		}
		else if (t==3)
		{
			for(i=0; i<10;i++)
			{
				if (B[i]!=0)
				{
					if (C[9-IsiC]==0)
					{
						C[9-IsiC]=B[i];
						B[i]=0;
						IsiC=IsiC+1;
						IsiB=IsiB-1;
						for(j=0;j<10; j++)
						{
							if (j<9)
								{
									if (C[j]>C[j+1])
									{
										counter=0;	
										nyawa=nyawa-1;
										counter=1;
										if (counter=1)
										{
											j=10;
										}
									}
								}
							else
								{
									nyawa=nyawa;
								}	
						}						
						i=10;
						step=step+1;
					for(s=0; s<10; s++)
					{
						if (C[s]==D[s])
							{
								selesai=selesai+1;			
							}	
					}
					if (selesai!=10)
						{
							selesai=0;
						} 						
					}
				}
			}		
		}
		else
		{
			printf("\nInput tidak bisa sama ataupun selain angka 1 sampai 3");
		}			
	}
	else if (f==3)
	{
		if (t==1)
		{
			for(i=0; i<10;i++)
			{
				if (C[i]!=0)
				{
					if (A[9-IsiA]==0)
					{
						A[9-IsiA]=C[i];
						C[i]=0;
						IsiA=IsiA+1;
						IsiC=IsiC-1;
						for(j=0;j<10; j++)
						{
							if (j<9)
								{
									if (A[j]>A[j+1])
									{
										counter=0;	
										nyawa=nyawa-1;
										counter=1;
										if (counter=1)
										{
											j=10;
										}
									}
								}
							else
								{
									nyawa=nyawa;
								}	
						}						
						i=10;
					}
				}
			}
		}
		else if (t==2)
		{
			for(i=0; i<10;i++)
			{
				if (C[i]!=0)
				{
					if (C[9-IsiC]==0)
					{
						B[9-IsiB]=C[i];
						C[i]=0;
						IsiB=IsiB+1;
						IsiC=IsiC-1;
						for(j=0;j<10; j++)
						{
							if (j<9)
								{
									if (B[j]>B[j+1])
									{
										counter=0;	
										nyawa=nyawa-1;
										counter=1;
										if (counter=1)
										{
											j=10;
										}
									}
								}
							else
								{
									nyawa=nyawa;
								}	
						}						
						i=10;
					}
				}
			}		
		}
		else
		{
			printf("\nInput tidak bisa sama ataupun selain angka 1 sampai 3\n\n");
		}			
	}
system("pause");
system("cls");	

}while(selesai<10);
 
{
	printf("\nKamu Berhasil \n");
//	printf("Nyawa Tersisa = %d\n",nyawa);
		DisplayNyawaDanStep(nyawa,step);
	FILE *out=fopen("leaderboard.csv","a");	
    fprintf(out,"%s,%d,BONUS\n",name, step);
	fclose(out);        
			
}

}

int DisplayNyawaDanStep(int nyawa, int step)
{
    printf("\t\t\t\t\t# Nyawa: %d #\n\n", nyawa);
    printf("\t\t\t\t\t# Step: %d #\n\n", step);      
}
