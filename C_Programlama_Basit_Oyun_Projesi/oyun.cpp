#include <stdio.h>                                  //1.level	 3  digit  /         1'section    5s                 2'section   3s            3'section  2s
#include <time.h>                       			//2.level	 6  digit  /         1'section    7s       	         2'section   5s            3'section  3s
#include <stdlib.h>									//3.level 	10  digit  /         1'section    12s                2'section   8s            3'section  4s
#include <windows.h>
#include <conio.h>

int main() {
	
	int interval;                   // digit zorluðunu ayarlýyor
	int level;                      // digitlerin içerisindeki levelleri degistiriyor
	unsigned long long number;      // programýn sordugu sorular
	int entry;                      // girdigimiz deger    number ile kontrol icin kullanýlýyor
    int key;                        //programda yazmaya baslamadan önce bir tusa basmamýzý istiyor hazýr oldugumuzda basmamýz icin.  
    int TIMEOUT;                    // kronometre zamani    ayarlayabiliyoruz
    time_t mark;                    // millisteki son zamana esitliyoruz belli bir zamana ayarlanýyor
    time_t now;                     // if yapýsý icerisinde sürekli kalan zamaný ayarladýgýmýz zaman degiskenine göre kontrol etmek icin kullanýlýyor
	
	game:                                                                                    // oyunu bitirdigimizde bizi en basa atýyor
	printf("   Welcome the Random Number Writing Challenge\n\n");
	printf("You must write the given numbers as quickly as possible.\n");
	levell:                                                                                 // levellerin sonunda yanlýs yazdýgýmýzda bizi aralýk secmeye yolluyor
	printf("\nWhat is your interval ?? (1)[3 DIGIT] (2)[6 DIGIT] (3)[9 DIGIT]\n\n");
	scanf("\t\t\t%d",&interval);
	                                                                                    
	
	switch(interval){  
	                                    
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////1.zorluk	 
	
	case 1:
	
	printf("\n");	
	printf("What is your level 1-3 (basic-hard)\n");
	scanf("%d",&level);
	
	
	switch(level){
		
	case 1:                                                  //1/1

	printf("\nYou have 5 seconds. If you are ready Press any button\n");
	getch();                    //hazýr oldugumuzda tusa basmamýzý bekliyor 
			
	TIMEOUT=5;                  //her levelde sabýt olarak ayarlanmýs kronometre degeri       
	mark = time(NULL);          // sistemin baslangýc zamanýný isaretliyor kronometre degeri icin
    srand(mark);                // random kumeleri icerisinden zamanda göre esitledigimiz mark degerine göre esitleniyor.
    number = rand();            // rakamý random fonksiyonu üzerinden seciyor
    
    numberr1:                                      // her bolumde bu kod var eger rakam buyuk yada kucukse bu kýsýma tekrar yollayýp baska rakam seciyor
	srand(time(NULL));	                           // random kümelerini simdiki zamana göre seciyor böylelikle her zaman farklý küme secmis oluyor.
	number= ((unsigned long long)(rand()%1000));
		if(number>1000){
		goto numberr1;                             //rakam buyukse tekrardan baslýyor
	}	
	
		if(number<100){
			number=number*11;
		}
    printf("The code is %d\n", number);
    printf("Enter the code\n");
    entry = 0;

    while (entry < number) {                          //arduino millis fonksiyonu gibi calýsýyor 
        while (!_kbhit()) {
            now = time(NULL);                           //son zamaný simdiki zamana esitliyor
            if (now - mark > TIMEOUT) {                 //kronometre zmaanýný  kontrol ediyor
                printf("\nTimeout failure!\n"); 
                goto levell;                            //eger zaman bittiyse basa atýyor
            }
        }
        key = _getche();
        entry = entry * 10 + key - '0';                    
    }

    if (entry == number){                                //girilen deger numara ile esitse tebrik ediyor ve level kýsmýna atýyor
    
        printf("\nNice! You're good\n");
        goto levell;
    }
    else{
	 
        printf("\nIncorrect code\n");                     // yanlýs kod ise bu sefer yine basa atýyor ve tekrar bolum sectiriyor
		goto levell;
	}
	
	break;
	
	///////////////////////////////////////////////////////////////////////// 1/2
	case 2:

	printf("\nYou have 3 seconds. If you are ready Press any button\n");
	getch();
			
	TIMEOUT=3;
	mark = time(NULL);
    srand(mark);
    number = rand();
    
    numberr2:
	srand(time(NULL));	
	number= ((unsigned long long)(rand()%1000));
		if(number>1000){
		goto numberr2;
	}	
    printf("The code is %d\n", number);
    printf("Enter the code\n");
    entry = 0;

    while (entry < number) {
        while (!_kbhit()) {
            now = time(NULL);
            if (now - mark > TIMEOUT) {
                printf("\nTimeout failure!\n");
                goto levell;
            }
        }
        key = _getche();
        entry = entry * 10 + key - '0';
    }

    if (entry == number){
        printf("\nNice! You're succesful\n");
        goto levell;
    }
    else{
	    printf("\nIncorrect code\n");
		goto levell;
	}
	
	break;
	
	///////////////////////////////////////////////////////////////////////// 1/3
 
	case 3:

	printf("\nYou have 2 seconds. If you are ready Press any button\n");
	getch();
			
	TIMEOUT=2;
	mark = time(NULL);
    srand(mark);
    number = rand();
    
    numberr3:
	srand(time(NULL));	
	number= ((unsigned long long)(rand()%1000));
		if(number>1000){
		goto numberr3;
	}	
    printf("The code is %d\n", number);
    printf("Enter the code\n");
    entry = 0;

    while (entry < number) {
        while (!_kbhit()) {
            now = time(NULL);
            if (now - mark > TIMEOUT) {
                printf("\nTimeout failure!\n");
                goto game;
            }
        }
        key = _getche();
        entry = entry * 10 + key - '0';
    }

    if (entry == number){
        printf("\nNice! You're very succesful\n\n\n");
        goto game;
    }
    else{
		printf("\nIncorrect code\n");
		goto levell;
	}
	
	break;
}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////2.zorluk	
	
	case 2:                                                  
	
	printf("\n");	
	printf("What is your level 1-3 (basic-hard)\n");
	scanf("%d",&level);
	
	
	switch(level){
		
	case 1:                                                  //2/1

	printf("\nYou have 7 seconds. If you are ready Press any button\n");
	getch();
			
	TIMEOUT=7;
	mark = time(NULL);
    srand(mark);
    number = rand();
    
    numberr4:
	srand(time(NULL));	
	number= ((unsigned long long)(rand()*158));
		if(number>1000000){
			
			number=number/10;
			if(number>1000000){	
		goto numberr4;
	}
	}
    printf("The code is %d\n", number);
    printf("Enter the code\n");
    entry = 0;

    while (entry < number) {
        while (!_kbhit()) {
            now = time(NULL);
            if (now - mark > TIMEOUT) {
                printf("\nTimeout failure!\n");
                goto levell;
            }
        }
        key = _getche();
        entry = entry * 10 + key - '0';
    }

    if (entry == number){
        printf("\nNice! You're good\n");
        goto levell;
    }
    else{
	
        printf("\nIncorrect code\n");
		goto levell;
	}
	
	break;
	
	///////////////////////////////////////////////////////////////////////// 2/2
	case 2:

	printf("\nYou have 5 seconds. If you are ready Press any button\n");
	getch();
			
	TIMEOUT=5;
	mark = time(NULL);
    srand(mark);
    number = rand();
    
    numberr5:
	srand(time(NULL));	
	number= ((unsigned long long)(rand()*158));
		if(number>1000000){
			
			number=number/10;
			if(number>1000000){	
		goto numberr5;
	}
	}	
    printf("The code is %d\n", number);
    printf("Enter the code\n");
    entry = 0;

    while (entry < number) {
        while (!_kbhit()) {
            now = time(NULL);
            if (now - mark > TIMEOUT) {
                printf("\nTimeout failure!\n");
                goto levell;
            }
        }
        key = _getche();
        entry = entry * 10 + key - '0';
    }

    if (entry == number){
        printf("\nNice! You're succesful\n");
        goto levell;
    }
    else{
		printf("\nIncorrect code\n");
		goto levell;
	}
	
	break;
	
	///////////////////////////////////////////////////////////////////////// 2/3
 
	case 3:

	printf("\nYou have 3 seconds. If you are ready Press any button\n");
	getch();
			
	TIMEOUT=3;
	mark = time(NULL);
    srand(mark);
    number = rand();
    
    numberr6:
	srand(time(NULL));	
	number= ((unsigned long long)(rand()*158));
		if(number>1000000){
			
			number=number/10;
			if(number>1000000){	
		goto numberr6;
	}
	}	
    printf("The code is %d\n", number);
    printf("Enter the code\n");
    entry = 0;

    while (entry < number) {
        while (!_kbhit()) {
            now = time(NULL);
            if (now - mark > TIMEOUT) {
                printf("\nTimeout failure!\n");
                goto levell;
            }
        }
        key = _getche();
        entry = entry * 10 + key - '0';
    }

    if (entry == number){
        printf("\nNice! You're very succesful\n\n\n");
        goto game;
    }
    else{
        printf("\nIncorrect code\n");
		goto levell;
	}
	
	break;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////3.zorluk
	
	case 3:                                                  
	
	printf("\n");	
	printf("What is your level 1-3 (basic-hard)\n");
	scanf("%d",&level);
	
	
	switch(level){
		
	case 1:                                                  //3/1
 
	printf("\nYou have 12 seconds. If you are ready Press any button\n");
	getch();
			
	TIMEOUT=12;
	mark = time(NULL);
    srand(mark);
    number = rand();
    number=number*237;
    
    numberr7:
	srand(time(NULL));	
	number= ((unsigned long long)rand()%10000000);
		if(number<10000000){
		number=number*11;
		if(number<100000000){
		number=number*13;
		}
		if(number<1000000000){
		number=number*12;
		}
		}
		if(number>10000000000){
		number=number/10;
		if(number>10000000000){
		number=number/10;	
		goto numberr7;
	}
	}
	number=number*10;
    printf("The code is %d\n",number);
    printf("Enter the code\n");
    entry = 0;

    while (entry < number) {
        while (!_kbhit()) {
            now = time(NULL);
            if (now - mark > TIMEOUT) {
                printf("\nTimeout failure!\n");
                goto levell;
        }
        }
        key = _getche();
        entry = entry * 10 + key - '0';
    }

    if (entry == number){
        printf("\nNice! You're good\n");
        goto levell;
    }
    else{
	
        printf("\nIncorrect code\n");
		goto levell;
	}
	
	break;
	
	///////////////////////////////////////////////////////////////////////// 3/2
	case 2:

	printf("\nYou have 8 seconds. If you are ready Press any button\n");
	getch();
			
	TIMEOUT=8;
	mark = time(NULL);
    srand(mark);
    number = rand();
    number=number*237;
    
    numberr8:
	srand(time(NULL));	
	number= ((unsigned long long)rand()%10000000);
		if(number<10000000){
		number=number*11;
		if(number<100000000){
		number=number*13;
		}
		if(number<1000000000){
		number=number*12;
		}
		}
		if(number>10000000000){
		number=number/10;
		if(number>10000000000){
		number=number/10;	
		goto numberr8;
	}
	}
	number=number*10;	
    printf("The code is %d\n", number);
    printf("Enter the code\n");
    entry = 0;

    while (entry < number) {
        while (!_kbhit()) {
            now = time(NULL);
            if (now - mark > TIMEOUT) {
                printf("\nTimeout failure!\n");
                goto levell;
            }
        }
        key = _getche();
        entry = entry * 10 + key - '0';
    }

    if (entry == number){
        printf("\nNice! You're succesful\n");
        goto levell;
    }
    else{
	
        printf("\nIncorrect code\n");
		goto levell;
	}
	
	break;
	
	///////////////////////////////////////////////////////////////////////// 3/3
 
	case 3:

	printf("\nYou have 4 seconds. If you are ready Press any button\n");
	getch();
			
	TIMEOUT=4;
	mark = time(NULL);
    srand(mark);
    number = rand();
    number=number*237;
    
    numberr9:
	srand(time(NULL));	
	number= ((unsigned long long)rand()%10000000);
		if(number<10000000){
		number=number*13;
		if(number<100000000){
		number=number*13;
		}
		if(number<1000000000){
		number=number*12;
		}
		}
		if(number>10000000000){
		number=number/10;
		if(number>100000000000){
		number=number/10;	
		goto numberr9;
	}
	}	
    printf("The code is %d\n", number);
    printf("Enter the code\n");
    entry = 0;

    while (entry < number) {
        while (!_kbhit()) {
            now = time(NULL);
            if (now - mark > TIMEOUT) {
                printf("\nTimeout failure!\n");
                goto levell;
            }
        }
        key = _getche();
        entry = entry * 10 + key - '0';
    }

    if (entry == number){
        printf("\nPerfect !! You're Best player in this game\n\n\n");
        goto game;
        
    }
    else{
	
        printf("\nIncorrect code\n");
		goto levell;
	}
	break;
}
}
	return 0;
}

