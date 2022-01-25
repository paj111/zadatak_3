#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct klub
{
    char name[50];
    int brB;
    int brdG;
    int brpG;
    int brU;
}klub;

void append();
void search();
void modif();
void ispis();
void ispis_min();
void ispis_max();
void sort();


void main(){


    FILE *file;
    int a=0;
    if (file = fopen("br.txt", "r")) 
    {
        fclose(file);
    }
    else
    {
        file=fopen("br.txt","w");
        fprintf(file, "%d", a); 
        fclose(file);
    }


    int i=0;
    file=fopen("br.txt","r");
    fscanf(file,"%d",&i);
    fclose(file);
    printf("broji %d\n",i);
     int izbor;

     do{

	 printf("\t\n\n==================Tabela sa klubovima==================\n\n");
	 printf("1. Unesite klub\n\n");
	 printf("2. Unesi rezultat\n\n");
	 printf("3. Ispis\n\n");
	 printf("4. Trazi\n\n");
	 printf("5. Zapamti i izadji\n\n");
	 printf("0. Exit\n\n");
 
printf("========================================================\n\n");

         printf("Tvoj izbor je: ");
         scanf("%d",&izbor);

         switch (izbor)
         {
         case 1:
            append(i);
            i++;
             break;
         case 2:
           modif(i);
             break;
         case 3:
            ispis(i);
             break;
         case 4:
            search(i);
             break;
         case 5:
            file=fopen("br.txt","w");
            fprintf(file, "%d", i); 
            fclose(file);
            printf("Kraj programa!\n");
            exit(1);
              break;
         default:
            printf("\nKraj!\t\n");
             break;
         }
     }while(izbor > 0 && izbor < 7);
}

//funkcija za dodavanje novog tima 
void append(int i){

    FILE *file;
    char name1[30];
    struct klub tabela[30];

    file=fopen("tabela.txt","r");

    fread(&tabela,sizeof(klub),30,file);
    fclose(file);
    
    file= fopen("tabela.txt", "w");

    printf("Upisi ime kluba: ");
    scanf("%s",name1);

    strcpy(tabela[i].name,name1);
    tabela[i].brB=0;
    tabela[i].brdG=0;
    tabela[i].brpG=0;
    tabela[i].brU=0;

    fwrite(&tabela, sizeof(klub), 30, file);
    fclose(file);
}
// funkcija koja provera za parametar x dok se gleda kao minimum <
void ispis_min(int a,int b){

    struct klub ispis[30];
    FILE *file;

    char name[]="Ime kluba";
    char brB[]="Broj bodova";
    char brDG[]="brDG";
    char brPG[]="brPG";
    char brU[]="Broj Utakmica";

    printf("%s\t\t %s\t %s:%s\t %s\t\n", name,brB, brDG, brPG, brU);

    file = fopen("tabela.txt","r");
    fread(&ispis,sizeof(klub),30,file);
    for(int i=0;i<b;i++){
            if(ispis[i].brB<=a){

               printf("%s\t\t\t %d\t\t %d:%d\t\t\t %d\t\n", ispis[i].name, ispis[i].brB, ispis[i].brdG, ispis[i].brpG, ispis[i].brU);
            }
    }
}
//isto ko prethodna samo kao max >
void ispis_max(int a,int b){

    struct klub ispis[30];
    FILE *file;

    char name[]="Ime kluba";
    char brB[]="Broj bodova";
    char brDG[]="brDG";
    char brPG[]="brPG";
    char brU[]="Broj Utakmica";

    printf("%s\t\t %s\t %s:%s\t %s\t\n", name,brB, brDG, brPG, brU);

    file = fopen("tabela.txt","r");
     fread(&ispis,sizeof(klub),30,file);
    for(int i=0;i<b;i++){
            if(ispis[i].brB>=a){

                printf("%s\t\t\t %d\t\t %d:%d\t\t\t %d\t\n", ispis[i].name, ispis[i].brB, ispis[i].brdG, ispis[i].brpG, ispis[i].brU);
            }
    }
}
//sort
void sort(int a){

    FILE *file;
    struct klub sort[30];
    struct klub temp;
    struct klub sortZamena[30];

    file=fopen("tabela.txt","r");
    fread(&sort,sizeof(klub),30,file);

    for(int i=0;i<a;i++){

        sortZamena[i]=sort[i];
    }
    
    fclose(file);

    int i,j;


    for (i = 0; i < a-1; i++){
        for (j = 0; j < (a-1-i); j++){
            if (sortZamena[j].brB < sortZamena[j + 1].brB){
                temp = sortZamena[j];
                sortZamena[j] = sortZamena[j + 1];
                sortZamena[j + 1] = temp;
            } 
        }
    }
    for (i = 0; i < a-1; i++){
        for (j = 0; j < (a-1-i); j++){
            if(sortZamena[j].brB == sortZamena[j+1].brB){
                if (sortZamena[j].brdG < sortZamena[j + 1].brdG){
                    temp = sortZamena[j];
                    sortZamena[j] = sortZamena[j + 1];
                    sortZamena[j + 1] = temp;
                }
            }
        }
    }

//sorting write
    file=fopen("tabela.txt","w");
    for(int k=0;k<a;k++){

        sort[k]=sortZamena[k];
    }
    fwrite(&sort,sizeof(klub),30,file);
    fclose(file);    
}

void ispis(int i){

    sort(i);

    FILE *file;
    struct klub tabela[30];
    char poredak[]="Id";
    char name[]="Ime kluba";
    char brB[]="Broj bodova\t";
    char brDG[]="brDG";
    char brPG[]="brPG\t";
    char brU[]="Broj Utakmica\n";

    printf("%s\t %s\t %s\t %s:%s\t %s\t\n",poredak, name,brB, brDG, brPG, brU);
    
    file = fopen("tabela.txt", "r");
    fread(&tabela, sizeof(klub), 30, file);
    for(int j=0;j<i;j++){
            
            printf("%d\t %s\t\t\t %d\t\t %d:%d\t\t\t %d\t\n",j+1 ,tabela[j].name, tabela[j].brB, tabela[j].brdG, tabela[j].brpG, tabela[j].brU);
    }
    fclose(file);

}
//funkcija za trazenje u datoteci u zavisnosti od toga da li je x < ili >
void search(int i){

    char x[5];
    char x1='<';
    char x2='>';

    printf("\nUnesite x,< ili x,> za ispis klubova u zavisnosti od parametra x\n");
    printf("\nUnesi string: \n");
    scanf("%s",x);

    int a = x[0]-'0';
    char x123=x[2];

    if (x123==x1){

        printf("Ispis sa <x: \n");
        ispis_min(a,i);

    }
    else if(x123==x2){

        printf("Ispis sa >x: \n");
        ispis_max(a,i);

    }
    else{
        printf("Netacno unet string!\n");
    }
}

//funkcija za modifikaciju to jest unosenje rezultata 
void modif(int a){

  char domacin[30];
  char gost[30];
  char rezultat[5];
  int rezDomacin=0;
  int rezGost=0;

  printf("Unesi domaci tim: ");
  scanf("%s",domacin);
  printf("Unesi gostujuci tim: ");
  scanf("%s",gost);
  
  printf("\nRezultat utakmice je: ");
  scanf("%s",rezultat);

  char s=rezultat[0];
  char b=rezultat[2];

    rezDomacin = s-'0';
    rezGost = b-'0';
    
    int c=0;
    if(s<b){

        c=3;//gost pobedio
    }else if(b<s){

        c=1;//domacin pobedio
    }else if(b==s){

        c=2;//nereseno
    }

    FILE *file;
    struct klub tabela[30];

    int brpG;
    int brdG;
    int brB;
    int brU=0;

    file=fopen("tabela.txt","r");

    fread(&tabela, sizeof(klub), 30, file);
    for(int i=0;i<a;i++){
        
       int t = strcmp(domacin,tabela[i].name);
        if(t==0){

            brU = tabela[i].brU;
            brB = tabela[i].brB;
            brdG = tabela[i].brdG;
            brpG = tabela[i].brpG;
        }
    }
    fclose(file);

    file=fopen("tabela.txt","w");

        for(int i=0;i<a;i++){

        int t = strcmp(domacin,tabela[i].name);

        if(t==0){
            if(c==1){
                tabela[i].brB=brB+3;
            }else if(c==2){
                tabela[i].brB=brB+1;
            }
            tabela[i].brU=brU+1;
            tabela[i].brdG=brdG+rezDomacin;
            tabela[i].brpG=brpG+rezGost;
        }
    }
    fwrite(&tabela,sizeof(klub),30,file);
    fclose(file);
    
    // --GOST-- 
    
    int brB1;
    int brdG1;
    int brpG1;
    int brU1=0;
    file=fopen("tabela.txt","r");
    fread(&tabela,sizeof(klub),30,file);
    for(int i=0;i<a;i++){

        
        int t = strcmp(gost,tabela[i].name);

        if(t==0){

            brU1 = tabela[i].brU;
            brB1 = tabela[i].brB;
            brdG1 = tabela[i].brdG;
            brpG1 = tabela[i].brpG;
        }
    }
    fclose(file);

    file=fopen("tabela.txt","w");

        for(int i=0;i<a;i++){

        int t = strcmp(gost,tabela[i].name);
        if(t==0){
            if(c==3){
                tabela[i].brB=brB1+3;
            }else if(c==2){
                tabela[i].brB=brB1+1;
            }
            tabela[i].brU = brU1+1;
            tabela[i].brdG=brdG1+rezGost;
            tabela[i].brpG=brpG1+rezDomacin;
        }
    }
fwrite(&tabela,sizeof(klub),30,file);
fclose(file);
}

