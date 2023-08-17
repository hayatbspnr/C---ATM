#include<stdio.h>
#include<stdlib.h>

int main(){
	/*
	isim soyad girisi 
	þifre giriþi
	1-bakiye görüntüle
	2-para yatýr
	3-para çek
	4-fatura öde
    -internet
	-elektirik
   	- su
   	5-çýkýþ
   	*/
   	
   	char ad[20];
   	char soyad[20];
   	int secim,para=10000,miktar,eski_bakiye,secim2,j,i=0; // ayný deðiþken birden fazla tanýmlanmýþ
   	int PSWRD=1234; // yorumda býrakýlmýþ açýk kalmalý
   	float hata; // bu deðiþken hiç eklenmemiþ
   	int istenilecekPSWRD; // bu deðiþken belirli olmalý
   	printf("Lutfen adinizi giriniz:");
   	scanf("%s", &ad);
   	
   	printf("Lutfen soyadinizi giriniz:");
   	scanf("%s", &soyad);
   	
   	
   	for(i=0;i<2;i++) // birden fazla iþlem (arttýrmak,azaltmak) yapýlamaz. 
   	{
   	  hata++;  // hata arttýrýmý for içerisinde yapýlabilir.
   	  printf("1-Bakiye Goruntule\n");
   	  printf("2-Para yatýr\n");
   	  printf("3-Para Cek\n");
   	  printf("4-Fatura Ode\n");
   	  scanf("%d" , &secim);
   	 
   	  if (secim>4) {   // yanlýþ seçim sonrasý 1 kez de olsa sistemden atmasý gerekli. Diðer türlü program kendini devam ettiriyor.
   	  	printf ("Yalnis secim yaptiniz tekrar giris yapiniz");
   	  	scanf("%d" , &secim);

   	  	return 0;
		 }
   	  	do{
   		printf("Merhaba bankamiza hosgeldiniz\nLutfen sifrenizi giriniz:");
   		scanf("%d" , &istenilecekPSWRD);
   		hata++;
      }
		 while(hata<=3 &&(PSWRD!=istenilecekPSWRD)); // ANLAMSIZ
   	   
		  if(PSWRD==istenilecekPSWRD){ 
		  printf("PSWRD dogrudur\n\n"); 
		}  
		else  {
			printf("\n\n3 ve 3den fazla hatali sifre girdiniz cikisiniz yapildi...");
			return 0; // PROGRAM KENDINI 0'a döndürerek çýkýþý saðlamalý.
		}
   	  
   	  switch(secim)
   	  {
   	  	case 1:
		    	 printf("Bakiyeniz: %d TL\n\n",para);
		    	 i=0; /* for döngünün kapanmasýný   istemediðimiz için,
				 döngü  sonsuza kadar devam edecek*/
   	  	break;
   	  	
		case 2:
				printf("Yatýrmak istediginiz miktari giriniz:");
		   	    scanf("%d", &miktar);
		   	    eski_bakiye=para;
		   	    para=para+miktar;
		   	    system("CLS");
                printf("\n\n-----------------\n\n");
		   	    printf("Eski bakiyeniz = %d\n",eski_bakiye);
		   	    printf("Yatirdihiniz tutar= %d ",para);
		   	    printf("Guncel bakiyeniz = %d",para);
		   	     printf("\n\n-----------------\n\n");
		   	    i=0;
		break;
		
		case 3:
				printf("cekmek istediginiz tutar: ");
				scanf("%d", &miktar);
				eski_bakiye=para;
			    para=para-miktar;
			    printf("\n\n-----------------\n\n");
			    printf("Eski bakiyeniz = %d\n",eski_bakiye);
			    printf("Çektiginiz tutar tutar= %d ",para);
			    printf("Guncel bakiyeniz = %d",para);
			    printf("\n\n-----------------\n\n");
   	  	        i=0;
   	  	break;
   	  	
   	  	case 4 :
   	  		for(j=0;j<2;j++) 
			{
				 	
				
	   	        printf("1-Internet  faturasi\n");
	   	  	    printf("2-Elektirik  faturasi\n");
	   	  	    printf("3-Su faturasi\n");
	   	  	    printf("4-Geri Don\n");
	   	  	    printf("Odemek istediðiniz fatura :");
	   	  	    scanf("%d" ,&secim2);
	   	  	    switch(secim2)
		   	  	    {
		   	  	        case 1: 
							 para= para- 200;
							 printf("Faturaniz odendi \nGuncel bakiyeniz: %d \n\n",para); // degiskenler parametre olarak string gösterim içerisine girilmemis.
							 j=4;/* para ödendiði zaman döngü bitsin çýkýþ yapýýlsýn*/
							 break;
					    case 2:
						     para=para-300;
						     printf("Faturaniz odendi \nGuncel bakiyeniz: %d \n\n",para); // degiskenler parametre olarak string gösterim içerisine girilmemis
						     j=4;
							 break;
				    	case 3:
				    	     para=para-250;
							 printf("Faturaniz odendi \nGuncel bakiyeniz: %d \n\n",para); // degiskenler parametre olarak string gösterim içerisine girilmemis
							 j=4;
							 break;
						case 4: j=4;
						default:
							printf("yanlis giris yaptiniz\n");
							j=0;
							break;	
			        }
			        
                    	}
             	break;
   	  
   	  	 default:
		   	  		 printf("\n\n-----------------\n\n");
					 printf("\n\n yanlis secim yaptiniz\n\n");
					 printf("\n\n-----------------\n\n");
					 i=0;
   	  	break;
   	  	}
   	  }
	
	
	system("pause");
	return 0;
	}
