#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Ogrenci{

    char no[10];
    char ad[20];
    char soyad[20];
    int kayit_no;
    char ogr_tur[2];

};

int tekrar1(struct Ogrenci liste[],int n);
struct Ogrenci *tekrar2(struct Ogrenci liste[],int n);
void numara_atama(struct Ogrenci liste[],int boyut);
void esit_dagilim(struct Ogrenci ogr1[],int m,struct Ogrenci ogr2[],int p,int s,int sinif[]);
void en_az(struct Ogrenci ogr1[],int m,struct Ogrenci ogr2[],int p,int s,int sinif[]);

int main()
{
    int n=0;
    int boyut1;
    time_t start,end;
    time(&start);
    struct Ogrenci liste[1000];
    struct Ogrenci *liste1;

    FILE *dosya=fopen("ogrenci_kayit_bilgileri.txt","r");

    fseek(dosya,60,SEEK_SET);
    while(!feof(dosya)){
        fscanf(dosya,"%s %s %s %d %s",liste[n].no,liste[n].ad,liste[n].soyad,&liste[n].kayit_no,liste[n].ogr_tur);
        n++;
    }
    fclose(dosya);

    liste1=tekrar2(liste,n);
    boyut1=tekrar1(liste1,n);
   // remove("ogrenci_kayit_bilgileri.txt");
    numara_atama(liste1,boyut1);

    time(&end);
    printf("\nKod %.2lf saniye surdu\n",difftime(end,start));




    return 0;
}

int tekrar1(struct Ogrenci liste[],int n){

    int i,j,k=0,a,c,t=0;
    int kontrol=1;

    struct Ogrenci tekrar[100];

    for(i=0;i<n;i++){
        if(strcmp(liste[i].ad,liste[i+1].ad)==0 && strcmp(liste[i].soyad,liste[i+1].soyad)==0 && kontrol==1){

            strcpy(tekrar[t].no,liste[i].no);
            strcpy(tekrar[t].ad,liste[i].ad);
            strcpy(tekrar[t].soyad,liste[i].soyad);
            tekrar[t].kayit_no=liste[i].kayit_no;
            strcpy(tekrar[t].ogr_tur,liste[i].ogr_tur);
            t++;

            for(j=i;j<n;j++){
                strcpy(liste[j].no,liste[j+1].no);
                strcpy(liste[j].ad,liste[j+1].ad);
                strcpy(liste[j].soyad,liste[j+1].soyad);
                liste[j].kayit_no=liste[j+1].kayit_no;
                strcpy(liste[j].ogr_tur,liste[j+1].ogr_tur);

            }
            k++;

            kontrol=0;
        }
        else
            kontrol=1;
    }

    a=0;

    for(i=0;i<n-k-1;i++){
        if(strcmp(liste[i].ad,liste[i+1].ad)==0 && strcmp(liste[i].soyad,liste[i+1].soyad)==0 && kontrol==1){

            strcpy(tekrar[t].no,liste[i].no);
            strcpy(tekrar[t].ad,liste[i].ad);
            strcpy(tekrar[t].soyad,liste[i].soyad);
            tekrar[t].kayit_no=liste[i].kayit_no;
            strcpy(tekrar[t].ogr_tur,liste[i].ogr_tur);
            t++;

            for(j=i;j<n;j++){
                strcpy(liste[j].no,liste[j+1].no);
                strcpy(liste[j].ad,liste[j+1].ad);
                strcpy(liste[j].soyad,liste[j+1].soyad);
                liste[j].kayit_no=liste[j+1].kayit_no;
                strcpy(liste[j].ogr_tur,liste[j+1].ogr_tur);

            }
            a++;

            kontrol=0;
        }
        else
            kontrol=1;
    }

    c=0;

    for(i=0;i<n-(k+a)-1;i++){
        if(strcmp(liste[i].ad,liste[i+1].ad)==0 && strcmp(liste[i].soyad,liste[i+1].soyad)==0 && kontrol==1){

            strcpy(tekrar[t].no,liste[i].no);
            strcpy(tekrar[t].ad,liste[i].ad);
            strcpy(tekrar[t].soyad,liste[i].soyad);
            tekrar[t].kayit_no=liste[i].kayit_no;
            strcpy(tekrar[t].ogr_tur,liste[i].ogr_tur);
            t++;

            for(j=i;j<n;j++){
                strcpy(liste[j].no,liste[j+1].no);
                strcpy(liste[j].ad,liste[j+1].ad);
                strcpy(liste[j].soyad,liste[j+1].soyad);
                liste[j].kayit_no=liste[j+1].kayit_no;
                strcpy(liste[j].ogr_tur,liste[j+1].ogr_tur);
            }

            c++;
            kontrol=0;

        }
        else
            kontrol=1;
    }

    t=0;
    int boyut=0;
    for(i=0;i<n-(k+a+c);i++){
        if(strcmp(liste[i].ad,tekrar[t].ad)==0 && strcmp(liste[i].soyad,tekrar[t].soyad)==0 && liste[i].kayit_no>tekrar[t].kayit_no){
            liste[i].kayit_no=tekrar[t].kayit_no;
            t++;
        }
        boyut++;
    }

    return boyut;

}

struct Ogrenci *tekrar2(struct Ogrenci liste[],int n){

    int i,j,k=0,a,c,t=0;
    int kontrol=1;

    struct Ogrenci tekrar[100];
    printf("\n\tIKI KEZ YAZILANLAR!!\n");
    printf("-----------------------------------------\n");

    for(i=0;i<n;i++){
        if(strcmp(liste[i].ad,liste[i+1].ad)==0 && strcmp(liste[i].soyad,liste[i+1].soyad)==0 && kontrol==1){

            printf("%s\t %-12s%-12s\n",liste[i].no,liste[i].ad,liste[i].soyad);

            strcpy(tekrar[t].no,liste[i].no);
            strcpy(tekrar[t].ad,liste[i].ad);
            strcpy(tekrar[t].soyad,liste[i].soyad);
            tekrar[t].kayit_no=liste[i].kayit_no;
            strcpy(tekrar[t].ogr_tur,liste[i].ogr_tur);
            t++;

            for(j=i;j<n;j++){
                strcpy(liste[j].no,liste[j+1].no);
                strcpy(liste[j].ad,liste[j+1].ad);
                strcpy(liste[j].soyad,liste[j+1].soyad);
                liste[j].kayit_no=liste[j+1].kayit_no;
                strcpy(liste[j].ogr_tur,liste[j+1].ogr_tur);

            }
            k++;

            kontrol=0;
        }
        else
            kontrol=1;
    }

    printf("\tUC KEZ YAZILANLAR!!\n");
    printf("-----------------------------------------\n");
    a=0;

    for(i=0;i<n-k-1;i++){
        if(strcmp(liste[i].ad,liste[i+1].ad)==0 && strcmp(liste[i].soyad,liste[i+1].soyad)==0 && kontrol==1){

            printf("%s\t %-12s%-12s\n",liste[i].no,liste[i].ad,liste[i].soyad);

            strcpy(tekrar[t].no,liste[i].no);
            strcpy(tekrar[t].ad,liste[i].ad);
            strcpy(tekrar[t].soyad,liste[i].soyad);
            tekrar[t].kayit_no=liste[i].kayit_no;
            strcpy(tekrar[t].ogr_tur,liste[i].ogr_tur);
            t++;

            for(j=i;j<n;j++){
                strcpy(liste[j].no,liste[j+1].no);
                strcpy(liste[j].ad,liste[j+1].ad);
                strcpy(liste[j].soyad,liste[j+1].soyad);
                liste[j].kayit_no=liste[j+1].kayit_no;
                strcpy(liste[j].ogr_tur,liste[j+1].ogr_tur);
            }

            a++;
            kontrol=0;

        }
        else
            kontrol=1;
    }
    printf("\n\n\n");
    printf("\tDORT KEZ YAZILANLAR!!\n");
    printf("-----------------------------------------\n");
    c=0;

    for(i=0;i<n-(k+a)-1;i++){
        if(strcmp(liste[i].ad,liste[i+1].ad)==0 && strcmp(liste[i].soyad,liste[i+1].soyad)==0 && kontrol==1){

            printf("%s\t %-12s%-12s\n",liste[i].no,liste[i].ad,liste[i].soyad);

            strcpy(tekrar[t].no,liste[i].no);
            strcpy(tekrar[t].ad,liste[i].ad);
            strcpy(tekrar[t].soyad,liste[i].soyad);
            tekrar[t].kayit_no=liste[i].kayit_no;
            strcpy(tekrar[t].ogr_tur,liste[i].ogr_tur);
            t++;

            for(j=i;j<n;j++){
                strcpy(liste[j].no,liste[j+1].no);
                strcpy(liste[j].ad,liste[j+1].ad);
                strcpy(liste[j].soyad,liste[j+1].soyad);
                liste[j].kayit_no=liste[j+1].kayit_no;
                strcpy(liste[j].ogr_tur,liste[j+1].ogr_tur);
            }

            c++;
            kontrol=0;

        }
        else
            kontrol=1;
    }
    printf("\n\n\n");

    t=0;
    for(i=0;i<n;i++){
        if(strcmp(liste[i].ad,tekrar[t].ad)==0 && strcmp(liste[i].soyad,tekrar[t].soyad)==0 && liste[i].kayit_no>tekrar[t].kayit_no){
            liste[i].kayit_no=tekrar[t].kayit_no;
            t++;
        }
    }

    return liste;

}

void numara_atama(struct Ogrenci liste[],int boyut){

    int i,j,b,m,p;

    struct Ogrenci ogr1[500];
    struct Ogrenci ogr2[500];
    struct Ogrenci eski[20];
    char ogr_1[] = "I";
    char ogr_2[] = "II";
    char no[]="-";

    FILE *yeni=fopen("yeni.txt","w");

    m=0;
    p=0;
    b=0;
    for(i=0;i<boyut;i++){
        if(strcmp(liste[i].no,no)!=0){
            strcpy(eski[b].no,liste[i].no);
            strcpy(eski[b].ad,liste[i].ad);
            strcpy(eski[b].soyad,liste[i].soyad);
            eski[b].kayit_no=liste[i].kayit_no;
            strcpy(eski[b].ogr_tur,liste[i].ogr_tur);
            b++;

        }
        else if(strcmp(liste[i].no,no)==0 && strcmp(liste[i].ogr_tur,ogr_1)==0){
            strcpy(ogr1[m].no,liste[i].no);
            strcpy(ogr1[m].ad,liste[i].ad);
            strcpy(ogr1[m].soyad,liste[i].soyad);
            ogr1[m].kayit_no=liste[i].kayit_no;
            strcpy(ogr1[m].ogr_tur,liste[i].ogr_tur);
            m++;
        }
        else if(strcmp(liste[i].no,no)==0 && strcmp(liste[i].ogr_tur,ogr_2)==0){
            strcpy(ogr2[p].no,liste[i].no);
            strcpy(ogr2[p].ad,liste[i].ad);
            strcpy(ogr2[p].soyad,liste[i].soyad);
            ogr2[p].kayit_no=liste[i].kayit_no;
            strcpy(ogr2[p].ogr_tur,liste[i].ogr_tur);
            p++;
        }
    }

    struct Ogrenci yedek;

    long int q,r;

    for(i=0;i<b-1;i++){
        sscanf(eski[i].no,"%ld",&q);
        for(j=0;j<b-1;j++){
            sscanf(eski[j].no,"%ld",&r);

            if(r>q){
                strcpy(yedek.no,eski[i].no);
                strcpy(yedek.ad,eski[i].ad);
                strcpy(yedek.soyad,eski[i].soyad);
                yedek.kayit_no=eski[i].kayit_no;
                strcpy(yedek.ogr_tur,eski[i].ogr_tur);

                strcpy(eski[i].no,eski[j].no);
                strcpy(eski[i].ad,eski[j].ad);
                strcpy(eski[i].soyad,eski[j].soyad);
                eski[i].kayit_no=eski[j].kayit_no;
                strcpy(eski[i].ogr_tur,eski[j].ogr_tur);

                strcpy(eski[j].no,yedek.no);
                strcpy(eski[j].ad,yedek.ad);
                strcpy(eski[j].soyad,yedek.soyad);
                eski[j].kayit_no=yedek.kayit_no;
                strcpy(eski[j].ogr_tur,yedek.ogr_tur);
            }

        }
    }


    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            if(ogr1[i].kayit_no<ogr1[j].kayit_no){
                strcpy(yedek.no,ogr1[i].no);
                strcpy(yedek.ad,ogr1[i].ad);
                strcpy(yedek.soyad,ogr1[i].soyad);
                yedek.kayit_no=ogr1[i].kayit_no;
                strcpy(yedek.ogr_tur,ogr1[i].ogr_tur);

                strcpy(ogr1[i].no,ogr1[j].no);
                strcpy(ogr1[i].ad,ogr1[j].ad);
                strcpy(ogr1[i].soyad,ogr1[j].soyad);
                ogr1[i].kayit_no=ogr1[j].kayit_no;
                strcpy(ogr1[i].ogr_tur,ogr1[j].ogr_tur);

                strcpy(ogr1[j].no,yedek.no);
                strcpy(ogr1[j].ad,yedek.ad);
                strcpy(ogr1[j].soyad,yedek.soyad);
                ogr1[j].kayit_no=yedek.kayit_no;
                strcpy(ogr1[j].ogr_tur,yedek.ogr_tur);
            }
        }
    }

    for(i=0;i<p;i++){
        for(j=0;j<p;j++){
            if(ogr2[i].kayit_no<ogr2[j].kayit_no){
                strcpy(yedek.no,ogr2[i].no);
                strcpy(yedek.ad,ogr2[i].ad);
                strcpy(yedek.soyad,ogr2[i].soyad);
                yedek.kayit_no=ogr2[i].kayit_no;
                strcpy(yedek.ogr_tur,ogr2[i].ogr_tur);

                strcpy(ogr2[i].no,ogr2[j].no);
                strcpy(ogr2[i].ad,ogr2[j].ad);
                strcpy(ogr2[i].soyad,ogr2[j].soyad);
                ogr2[i].kayit_no=ogr2[j].kayit_no;
                strcpy(ogr2[i].ogr_tur,ogr2[j].ogr_tur);

                strcpy(ogr2[j].no,yedek.no);
                strcpy(ogr2[j].ad,yedek.ad);
                strcpy(ogr2[j].soyad,yedek.soyad);
                ogr2[j].kayit_no=yedek.kayit_no;
                strcpy(ogr2[j].ogr_tur,yedek.ogr_tur);
            }
        }
    }

    long int x=1701001;
    long int y=1702001;

    printf("\n\n");

    for(i=0;i<b-1;i++){
       // printf("%s\t %-12s%-12s%4d\t%s\n",eski[i].no,eski[i].ad,eski[i].soyad,eski[i].kayit_no,eski[i].ogr_tur);
        fprintf(yeni,"%s\t %-12s%-12s%4d\t%s\n",eski[i].no,eski[i].ad,eski[i].soyad,eski[i].kayit_no,eski[i].ogr_tur);
    }


    for(i=0;i<m;i++){
        sprintf(ogr1[i].no,"%ld",x);
       // printf("%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
        fprintf(yeni,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
        x++;
    }
    for(i=0;i<p;i++){
        sprintf(ogr2[i].no,"%ld",y);
        //printf("%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
        fprintf(yeni,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
        y++;
    }


    for(i=0;i<b;i++){
        if(strcmp(eski[i].ogr_tur,ogr_1)==0){

            strcpy(ogr1[m].no,eski[i].no);
            strcpy(ogr1[m].ad,eski[i].ad);
            strcpy(ogr1[m].soyad,eski[i].soyad);
            ogr1[m].kayit_no=eski[i].kayit_no;
            strcpy(ogr1[m].ogr_tur,eski[i].ogr_tur);
            m++;

        }
        else if(strcmp(eski[i].ogr_tur,ogr_2)==0){

            strcpy(ogr2[p].no,eski[i].no);
            strcpy(ogr2[p].ad,eski[i].ad);
            strcpy(ogr2[p].soyad,eski[i].soyad);
            ogr2[p].kayit_no=eski[i].kayit_no;
            strcpy(ogr2[p].ogr_tur,eski[i].ogr_tur);
            p++;
        }
    }


     printf("Kayit siralari duzenlenmistir!!\n");

    int s;
    printf("\nSinif sayisini giriniz :");
    scanf("%d",&s);

    int sinif[s];
    printf("Sinif kapasitelerini giriniz  :");
    for(i=0;i<s;i++){
        scanf("%d",&sinif[i]);
    }

    printf("\nDersi alan ogrenci sayisi   1.Ogretim:%d \t 2.Ogretim:%d\n",m,p);

    fclose(yeni);

 //   rename("yeni.txt","ogrenci_kayit_bilgileri.txt");

    esit_dagilim(ogr1,m,ogr2,p,s,sinif);
    en_az(ogr1,m,ogr2,p,s,sinif);

}

void esit_dagilim(struct Ogrenci ogr1[],int m,struct Ogrenci ogr2[],int p,int s,int sinif[]){

    int i;
    int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0;

    if(s==1){
        FILE *sinif1=fopen("C:/Users/uset/Desktop/Proje/proje2/esit_dagilim/sinif1ogr1.txt","w");
        FILE *sinif2=fopen("C:/Users/uset/Desktop/Proje/proje2/esit_dagilim/sinif1ogr2.txt","w");
        if(sinif[0]>=m){
            for(i=0;i<m;i++){
                fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
            }
        }
        else
            printf("------------------------------\nSinif kapasitesi yetersiz!!\n");

        if(sinif[0]>=p){
            for(i=0;i<p;i++){
                fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
            }
        }

        else
            printf("------------------------------\nSinif kapasitesi yetersiz!!\n");

        fclose(sinif1);
        fclose(sinif2);
    }
    else if(s==2){
        FILE *sinif1=fopen("C:/Users/uset/Desktop/Proje/proje2/esit_dagilim/sinif1ogr1.txt","w");
        FILE *sinif2=fopen("C:/Users/uset/Desktop/Proje/proje2/esit_dagilim/sinif2ogr1.txt","w");
        FILE *sinif3=fopen("C:/Users/uset/Desktop/Proje/proje2/esit_dagilim/sinif1ogr2.txt","w");
        FILE *sinif4=fopen("C:/Users/uset/Desktop/Proje/proje2/esit_dagilim/sinif2ogr2.txt","w");

        if(sinif[0]>=(m/2) && sinif[1]>=(m/2)){
            for(i=0;i<m/2;i++){
                fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                a++;
            }
            for(i=m/2;i<m;i++){
                fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                b++;
            }
        }
        else
           printf("------------------------------\nSinif kapasitesi yetersiz!!\n");

        if(sinif[0]>=(p/2) && sinif[1]>=(p/2)){
            for(i=0;i<p/2;i++){
                fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                c++;
            }
            for(i=p/2;i<p;i++){
                fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                d++;
            }
        }
        else
           printf("------------------------------\nSinif kapasitesi yetersiz!!\n");


        printf("\nEsit dagilim  1. Ogretim   :%d %d \t 2.Ogretim  :%d %d\n",a,b,c,d);

        fclose(sinif1);
        fclose(sinif2);
        fclose(sinif3);
        fclose(sinif4);
    }
    else if(s==3){
        FILE *sinif1=fopen("C:/Users/uset/Desktop/Proje/proje2/esit_dagilim/sinif1ogr1.txt","w");
        FILE *sinif2=fopen("C:/Users/uset/Desktop/Proje/proje2/esit_dagilim/sinif2ogr1.txt","w");
        FILE *sinif3=fopen("C:/Users/uset/Desktop/Proje/proje2/esit_dagilim/sinif3ogr1.txt","w");
        FILE *sinif4=fopen("C:/Users/uset/Desktop/Proje/proje2/esit_dagilim/sinif1ogr2.txt","w");
        FILE *sinif5=fopen("C:/Users/uset/Desktop/Proje/proje2/esit_dagilim/sinif2ogr2.txt","w");
        FILE *sinif6=fopen("C:/Users/uset/Desktop/Proje/proje2/esit_dagilim/sinif3ogr2.txt","w");

        if(sinif[0]>=m/3 && sinif[1]>=m/3 && sinif[2]>=m/3){

            for(i=0;i<m/3;i++){
                fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                a++;
            }
            for(i=m/3;i<2*m/3;i++){
                fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                b++;
            }
            for(i=2*m/3;i<m;i++){
                fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                c++;
            }
        }
        else if(sinif[0]<m/3 && sinif[1]>=(m-sinif[0])/2 && sinif[2]>=(m-sinif[0])/2){

            for(i=0;i<sinif[0];i++){
                fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                a++;
            }
            for(i=0;i<(m-sinif[0])/2;i++){
                fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i+sinif[0]].no,ogr1[i+sinif[0]].ad,ogr1[i+sinif[0]].soyad,ogr1[i+sinif[0]].kayit_no,ogr1[i+sinif[0]].ogr_tur);
                b++;
            }
            for(i=(m-sinif[0])/2;i<m-sinif[0];i++){
                fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i+sinif[0]].no,ogr1[i+sinif[0]].ad,ogr1[i+sinif[0]].soyad,ogr1[i+sinif[0]].kayit_no,ogr1[i+sinif[0]].ogr_tur);
                c++;
            }
        }
        else if(sinif[0]>=(m-sinif[1])/2 && sinif[1]<m/3 && sinif[2]>(m-sinif[1])/2){

            for(i=0;i<sinif[1];i++){
                fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                b++;
            }
            for(i=0;i<(m-sinif[1])/2;i++){
                fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i+sinif[1]].no,ogr1[i+sinif[1]].ad,ogr1[i+sinif[1]].soyad,ogr1[i+sinif[1]].kayit_no,ogr1[i+sinif[1]].ogr_tur);
                a++;
            }
            for(i=((m-sinif[1])/2);i<(m-sinif[1]);i++){
                fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i+sinif[1]].no,ogr1[i+sinif[1]].ad,ogr1[i+sinif[1]].soyad,ogr1[i+sinif[1]].kayit_no,ogr1[i+sinif[1]].ogr_tur);
                c++;
            }

        }
        else if(sinif[0]>=(m-sinif[2])/2 && sinif[1]>=(m-sinif[2])/2 && sinif[2]<m/3){

            for(i=0;i<sinif[2];i++){
                fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                c++;
            }
            for(i=0;i<((m-sinif[2])/2);i++){
                fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i+sinif[2]].no,ogr1[i+sinif[2]].ad,ogr1[i+sinif[2]].soyad,ogr1[i+sinif[2]].kayit_no,ogr1[i+sinif[2]].ogr_tur);
                a++;
            }
            for(i=((m-sinif[2])/2);i<(m-sinif[2]);i++){
                fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i+sinif[2]].no,ogr1[i+sinif[2]].ad,ogr1[i+sinif[2]].soyad,ogr1[i+sinif[2]].kayit_no,ogr1[i+sinif[2]].ogr_tur);
                b++;
            }


        }
        else
            printf("\nSinif kapasiteleri yetersiz!!");

        if(sinif[0]>=p/3 && sinif[1]>=p/3 && sinif[2]>=p/3){

            for(i=0;i<p/3;i++){
                fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                d++;
            }
            for(i=p/3;i<2*p/3;i++){
                fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                e++;
            }
            for(i=2*p/3;i<p;i++){
                fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                f++;
            }
        }
        else if(sinif[0]<p/3 && sinif[1]>=(p-sinif[0])/2 && sinif[2]>=(p-sinif[0])/2){

            for(i=0;i<sinif[0];i++){
                fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                d++;
            }
            for(i=0;i<(p-sinif[0])/2;i++){
                fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i+sinif[0]].no,ogr2[i+sinif[0]].ad,ogr2[i+sinif[0]].soyad,ogr2[i+sinif[0]].kayit_no,ogr2[i+sinif[0]].ogr_tur);
                e++;
            }
            for(i=(p-sinif[0])/2;i<p-sinif[0];i++){
                fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i+sinif[0]].no,ogr2[i+sinif[0]].ad,ogr2[i+sinif[0]].soyad,ogr2[i+sinif[0]].kayit_no,ogr2[i+sinif[0]].ogr_tur);
                f++;
            }
        }
        else if(sinif[0]>=(p-sinif[1])/2 && sinif[1]<p/3 && sinif[2]>=(p-sinif[1])/2){

            for(i=0;i<sinif[1];i++){
                fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                e++;
            }
            for(i=0;i<(p-sinif[1])/2;i++){
                fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i+sinif[1]].no,ogr2[i+sinif[1]].ad,ogr2[i+sinif[1]].soyad,ogr2[i+sinif[1]].kayit_no,ogr2[i+sinif[1]].ogr_tur);
                d++;
            }
            for(i=((p-sinif[1])/2);i<(p-sinif[1]);i++){
                fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i+sinif[1]].no,ogr2[i+sinif[1]].ad,ogr2[i+sinif[1]].soyad,ogr2[i+sinif[1]].kayit_no,ogr2[i+sinif[1]].ogr_tur);
                f++;
            }

        }
        else if(sinif[0]>=(p-sinif[2])/2 && sinif[1]>=(p-sinif[2])/2 && sinif[2]<p/3){

            for(i=0;i<sinif[2];i++){
                fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                f++;
            }
            for(i=0;i<((p-sinif[2])/2);i++){
                fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i+sinif[2]].no,ogr2[i+sinif[2]].ad,ogr2[i+sinif[2]].soyad,ogr2[i+sinif[2]].kayit_no,ogr2[i+sinif[2]].ogr_tur);
                d++;
            }
            for(i=((m-sinif[2])/2);i<(m-sinif[2]);i++){
                fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i+sinif[2]].no,ogr2[i+sinif[2]].ad,ogr2[i+sinif[2]].soyad,ogr2[i+sinif[2]].kayit_no,ogr2[i+sinif[2]].ogr_tur);
                e++;
            }


        }
        else
            printf("\nSinif kapasiteleri yetersiz!!");

        printf("\nEsit dagilim  1. Ogretim   :%d %d %d \t 2.Ogretim  :%d %d %d\n",a,b,c,d,e,f);

        fclose(sinif1);
        fclose(sinif2);
        fclose(sinif3);
        fclose(sinif4);
        fclose(sinif5);
        fclose(sinif6);

    }
    else if(s==4){
        FILE *sinif1=fopen("C:/Users/uset/Desktop/Proje/proje2/esit_dagilim/sinif1ogr1.txt","w");
        FILE *sinif2=fopen("C:/Users/uset/Desktop/Proje/proje2/esit_dagilim/sinif2ogr1.txt","w");
        FILE *sinif3=fopen("C:/Users/uset/Desktop/Proje/proje2/esit_dagilim/sinif3ogr1.txt","w");
        FILE *sinif4=fopen("C:/Users/uset/Desktop/Proje/proje2/esit_dagilim/sinif4ogr1.txt","w");
        FILE *sinif5=fopen("C:/Users/uset/Desktop/Proje/proje2/esit_dagilim/sinif1ogr2.txt","w");
        FILE *sinif6=fopen("C:/Users/uset/Desktop/Proje/proje2/esit_dagilim/sinif2ogr2.txt","w");
        FILE *sinif7=fopen("C:/Users/uset/Desktop/Proje/proje2/esit_dagilim/sinif3ogr2.txt","w");
        FILE *sinif8=fopen("C:/Users/uset/Desktop/Proje/proje2/esit_dagilim/sinif4ogr2.txt","w");

        if(sinif[0]>=m/4 && sinif[1]>=m/4 && sinif[2]>=m/4 && sinif[3]>=m/4){

            for(i=0;i<m/4;i++){
                fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                a++;
            }
            for(i=m/4;i<2*m/4;i++){
                fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                b++;
            }
            for(i=2*m/4;i<3*m/4;i++){
                fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                c++;
            }
            for(i=3*m/4;i<m;i++){
                fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                d++;
            }
        }
        else if(sinif[0]<m/4 && sinif[1]>=(m-sinif[0])/3 && sinif[2]>=(m-sinif[0])/3 && sinif[3]>=(m-sinif[0])/3){
            for(i=0;i<sinif[0];i++){
                fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                a++;
            }
            for(i=0;i<(m-sinif[0])/3;i++){
                fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i+sinif[0]].no,ogr1[i+sinif[0]].ad,ogr1[i+sinif[0]].soyad,ogr1[i+sinif[0]].kayit_no,ogr1[i+sinif[0]].ogr_tur);
                b++;
            }
            for(i=(m-sinif[0])/3;i<2*(m-sinif[0])/3;i++){
                fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i+sinif[0]].no,ogr1[i+sinif[0]].ad,ogr1[i+sinif[0]].soyad,ogr1[i+sinif[0]].kayit_no,ogr1[i+sinif[0]].ogr_tur);
                c++;
            }
            for(i=2*(m-sinif[0])/3;i<(m-sinif[0]);i++){
                fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i+sinif[0]].no,ogr1[i+sinif[0]].ad,ogr1[i+sinif[0]].soyad,ogr1[i+sinif[0]].kayit_no,ogr1[i+sinif[0]].ogr_tur);
                d++;
            }
        }

        else if(sinif[1]<m/4 && sinif[0]>=(m-sinif[1])/3 && sinif[1]>=(m-sinif[1])/3 && sinif[3]>=(m-sinif[1])/3){
            for(i=0;i<sinif[1];i++){
                fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                b++;
            }
            for(i=0;i<(m-sinif[1])/3;i++){
                fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i+sinif[1]].no,ogr1[i+sinif[1]].ad,ogr1[i+sinif[1]].soyad,ogr1[i+sinif[1]].kayit_no,ogr1[i+sinif[1]].ogr_tur);
                a++;
            }
            for(i=(m-sinif[1])/3;i<2*(m-sinif[1])/3;i++){
                fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i+sinif[1]].no,ogr1[i+sinif[1]].ad,ogr1[i+sinif[1]].soyad,ogr1[i+sinif[1]].kayit_no,ogr1[i+sinif[1]].ogr_tur);
                c++;
            }
            for(i=2*(m-sinif[1])/3;i<(m-sinif[1]);i++){
                fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i+sinif[1]].no,ogr1[i+sinif[1]].ad,ogr1[i+sinif[1]].soyad,ogr1[i+sinif[1]].kayit_no,ogr1[i+sinif[1]].ogr_tur);
                d++;
            }

        }

        else if(sinif[2]<m/4 && sinif[1]>=(m-sinif[2])/3 && sinif[0]>=(m-sinif[2])/3 && sinif[3]>=(m-sinif[2])/3){
            for(i=0;i<sinif[2];i++){
                fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                c++;
            }
            for(i=0;i<(m-sinif[2])/3;i++){
                fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i+sinif[2]].no,ogr1[i+sinif[2]].ad,ogr1[i+sinif[2]].soyad,ogr1[i+sinif[2]].kayit_no,ogr1[i+sinif[2]].ogr_tur);
                a++;
            }
            for(i=(m-sinif[2])/3;i<2*(m-sinif[2])/3;i++){
                fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i+sinif[2]].no,ogr1[i+sinif[2]].ad,ogr1[i+sinif[2]].soyad,ogr1[i+sinif[2]].kayit_no,ogr1[i+sinif[2]].ogr_tur);
                b++;
            }
            for(i=2*(m-sinif[2])/3;i<(m-sinif[2]);i++){
                fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i+sinif[2]].no,ogr1[i+sinif[2]].ad,ogr1[i+sinif[2]].soyad,ogr1[i+sinif[2]].kayit_no,ogr1[i+sinif[2]].ogr_tur);
                d++;
            }
        }

        else if(sinif[3]<m/4 && sinif[1]>=(m-sinif[3])/3 && sinif[2]>=(m-sinif[3])/3 && sinif[0]>=(m-sinif[3])/3){
            for(i=0;i<sinif[3];i++){
                fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                d++;
            }
            for(i=0;i<(m-sinif[3])/3;i++){
                fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i+sinif[3]].no,ogr1[i+sinif[3]].ad,ogr1[i+sinif[3]].soyad,ogr1[i+sinif[3]].kayit_no,ogr1[i+sinif[3]].ogr_tur);
                a++;
            }
            for(i=(m-sinif[3])/3;i<2*(m-sinif[3])/3;i++){
                fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i+sinif[3]].no,ogr1[i+sinif[3]].ad,ogr1[i+sinif[3]].soyad,ogr1[i+sinif[3]].kayit_no,ogr1[i+sinif[3]].ogr_tur);
                b++;
            }
            for(i=2*(m-sinif[3])/3;i<(m-sinif[3]);i++){
                fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i+sinif[3]].no,ogr1[i+sinif[3]].ad,ogr1[i+sinif[3]].soyad,ogr1[i+sinif[3]].kayit_no,ogr1[i+sinif[3]].ogr_tur);
                c++;
            }
        }

        if(sinif[0]>=p/4 && sinif[1]>=p/4 && sinif[2]>=p/4 && sinif[3]>=p/4){

            for(i=0;i<p/4;i++){
                fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                e++;
            }
            for(i=p/4;i<2*p/4;i++){
                fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                f++;
            }
            for(i=2*p/4;i<3*p/4;i++){
                fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                g++;
            }
            for(i=3*p/4;i<p;i++){
                fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                h++;
            }
        }

        else if(sinif[0]<p/4 && sinif[1]>=(p-sinif[0])/3 && sinif[2]>=(p-sinif[0])/3 && sinif[3]>=(p-sinif[0])/3){
            for(i=0;i<sinif[0];i++){
                fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                e++;
            }
            for(i=0;i<(p-sinif[0])/3;i++){
                fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i+sinif[0]].no,ogr2[i+sinif[0]].ad,ogr2[i+sinif[0]].soyad,ogr2[i+sinif[0]].kayit_no,ogr2[i+sinif[0]].ogr_tur);
                f++;
            }
            for(i=(p-sinif[0])/3;i<2*(p-sinif[0])/3;i++){
                fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i+sinif[0]].no,ogr2[i+sinif[0]].ad,ogr2[i+sinif[0]].soyad,ogr2[i+sinif[0]].kayit_no,ogr2[i+sinif[0]].ogr_tur);
                g++;
            }
            for(i=2*(p-sinif[0])/3;i<(p-sinif[0]);i++){
                fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i+sinif[0]].no,ogr2[i+sinif[0]].ad,ogr2[i+sinif[0]].soyad,ogr2[i+sinif[0]].kayit_no,ogr2[i+sinif[0]].ogr_tur);
                h++;
            }
        }

        else if(sinif[1]<p/4 && sinif[0]>=(p-sinif[1])/3 && sinif[2]>=(p-sinif[1])/3 && sinif[3]>=(p-sinif[1])/3){
            for(i=0;i<sinif[1];i++){
                fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                f++;
            }
            for(i=0;i<(p-sinif[1])/3;i++){
                fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i+sinif[1]].no,ogr2[i+sinif[1]].ad,ogr2[i+sinif[1]].soyad,ogr2[i+sinif[1]].kayit_no,ogr2[i+sinif[1]].ogr_tur);
                e++;
            }
            for(i=(p-sinif[1])/3;i<2*(p-sinif[1])/3;i++){
                fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i+sinif[1]].no,ogr2[i+sinif[1]].ad,ogr2[i+sinif[1]].soyad,ogr2[i+sinif[1]].kayit_no,ogr2[i+sinif[1]].ogr_tur);
                g++;
            }
            for(i=2*(p-sinif[1])/3;i<(p-sinif[1]);i++){
                fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i+sinif[1]].no,ogr2[i+sinif[1]].ad,ogr2[i+sinif[1]].soyad,ogr2[i+sinif[1]].kayit_no,ogr2[i+sinif[1]].ogr_tur);
                h++;
            }
        }

        else if(sinif[2]<p/4 && sinif[1]>=(p-sinif[2])/3 && sinif[0]>=(p-sinif[2])/3 && sinif[3]>=(p-sinif[2])/3){
            for(i=0;i<sinif[2];i++){
                fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                g++;
            }
            for(i=0;i<(p-sinif[2])/3;i++){
                fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i+sinif[2]].no,ogr2[i+sinif[2]].ad,ogr2[i+sinif[2]].soyad,ogr2[i+sinif[2]].kayit_no,ogr2[i+sinif[2]].ogr_tur);
                e++;
            }
            for(i=(p-sinif[2])/3;i<2*(p-sinif[2])/3;i++){
                fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i+sinif[2]].no,ogr2[i+sinif[2]].ad,ogr2[i+sinif[2]].soyad,ogr2[i+sinif[2]].kayit_no,ogr2[i+sinif[2]].ogr_tur);
                f++;
            }
            for(i=2*(p-sinif[2])/3;i<(p-sinif[2]);i++){
                fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i+sinif[2]].no,ogr2[i+sinif[2]].ad,ogr2[i+sinif[2]].soyad,ogr2[i+sinif[2]].kayit_no,ogr2[i+sinif[2]].ogr_tur);
                h++;
            }
        }

        else if(sinif[3]<p/4 && sinif[1]>=(p-sinif[3])/3 && sinif[2]>=(p-sinif[3])/3 && sinif[0]>=(p-sinif[3])/3){
            for(i=0;i<sinif[3];i++){
                fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                h++;
            }
            for(i=0;i<(p-sinif[3])/3;i++){
                fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i+sinif[3]].no,ogr2[i+sinif[3]].ad,ogr2[i+sinif[3]].soyad,ogr2[i+sinif[3]].kayit_no,ogr2[i+sinif[3]].ogr_tur);
                e++;
            }
            for(i=(p-sinif[3])/3;i<2*(p-sinif[3])/3;i++){
                fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i+sinif[3]].no,ogr2[i+sinif[3]].ad,ogr2[i+sinif[3]].soyad,ogr2[i+sinif[3]].kayit_no,ogr2[i+sinif[3]].ogr_tur);
                f++;
            }
            for(i=2*(p-sinif[3])/3;i<(p-sinif[3]);i++){
                fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i+sinif[3]].no,ogr2[i+sinif[3]].ad,ogr2[i+sinif[3]].soyad,ogr2[i+sinif[3]].kayit_no,ogr2[i+sinif[3]].ogr_tur);
                g++;
            }
        }

        printf("\nEsit dagilim  1. Ogretim   :%d %d %d %d\t 2.Ogretim  :%d %d %d %d\n",a,b,c,d,e,f,g,h);

        fclose(sinif1);
        fclose(sinif2);
        fclose(sinif3);
        fclose(sinif4);
        fclose(sinif5);
        fclose(sinif6);
        fclose(sinif7);
        fclose(sinif8);

    }

}

void en_az(struct Ogrenci ogr1[],int m,struct Ogrenci ogr2[],int p,int s,int sinif[]){

    int i,j,enb1,enb2,enb3,enk;
    int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0;


    if(s==1){
        FILE *sinif1=fopen("C:/Users/uset/Desktop/Proje/proje2/en_az/sinif1ogr1.txt","w");
        FILE *sinif2=fopen("C:/Users/uset/Desktop/Proje/proje2/en_az/sinif1ogr2.txt","w");

        if(sinif[0]>=m){
            for(i=0;i<m;i++){
                fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                a++;
            }
        }
        else
            printf("\n--------------------------------------\nSinif kapasitesi yetersiz!!\n");

        if(sinif[0]>=p){
            for(i=0;i<p;i++){
                fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                b++;
            }
        }
        else
            printf("\n--------------------------------------\nSinif kapasitesi yetersiz!!\n");

        printf("En az sinif dagilimi 1.Ogretim :%d \t 2.Ogretim :%d\n",a,b);

        fclose(sinif1);
        fclose(sinif2);
    }
    else if(s==2){
        FILE *sinif1=fopen("C:/Users/uset/Desktop/Proje/proje2/en_az/sinif1ogr1.txt","w");
        FILE *sinif2=fopen("C:/Users/uset/Desktop/Proje/proje2/en_az/sinif2ogr1.txt","w");
        FILE *sinif3=fopen("C:/Users/uset/Desktop/Proje/proje2/en_az/sinif1ogr2.txt","w");
        FILE *sinif4=fopen("C:/Users/uset/Desktop/Proje/proje2/en_az/sinif2ogr2.txt","w");

        enb1=sinif[0];

            for(i=0;i<s;i++){
                for(j=0;j<s;j++){
                    if(sinif[j]>sinif[i]){
                        enb1=sinif[j];
                    }
                }
            }

        if(sinif[0]+sinif[1]>=m){

            if(enb1==sinif[0]){
                for(i=0;i<enb1;i++){
                    fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                    a++;
                }
                for(i=enb1;i<m;i++){
                    fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                    b++;
                }
            }
            else if(enb1==sinif[1]){
                for(i=0;i<enb1;i++){
                    fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                    b++;
                }
                for(i=enb1;i<m;i++){
                    fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                    a++;
                }
            }
        }

        if(sinif[0]+sinif[1]>=p){

            if(enb1==sinif[0]){
                for(i=0;i<enb1;i++){
                    fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                    c++;
                }
                for(i=enb1;i<p;i++){
                    fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                    d++;
                }
            }
            else if(enb1==sinif[1]){
                for(i=0;i<enb1;i++){
                    fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                    d++;
                }
                for(i=enb1;i<p;i++){
                    fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                    c++;
                }
            }
        }

       printf("En az sinif dagilimi 1.Ogretim :%d %d \t 2.Ogretim :%d %d\n",a,b,c,d);

        fclose(sinif1);
        fclose(sinif2);
        fclose(sinif3);
        fclose(sinif4);
    }
    else if(s==3){
        FILE *sinif1=fopen("C:/Users/uset/Desktop/Proje/proje2/en_az/sinif1ogr1.txt","w");
        FILE *sinif2=fopen("C:/Users/uset/Desktop/Proje/proje2/en_az/sinif2ogr1.txt","w");
        FILE *sinif3=fopen("C:/Users/uset/Desktop/Proje/proje2/en_az/sinif3ogr1.txt","w");
        FILE *sinif4=fopen("C:/Users/uset/Desktop/Proje/proje2/en_az/sinif1ogr2.txt","w");
        FILE *sinif5=fopen("C:/Users/uset/Desktop/Proje/proje2/en_az/sinif2ogr2.txt","w");
        FILE *sinif6=fopen("C:/Users/uset/Desktop/Proje/proje2/en_az/sinif3ogr2.txt","w");


        enb1=sinif[0];
        enb2=sinif[0];


        for(i=0;i<3;i++){
            if(sinif[i]>enb1){
                enb2=enb1;
                enb1=sinif[i];
            }
            else if(sinif[i]>enb2){
                enb2=sinif[i];
            }
        }



        printf("\nEnb1=%d, enb2=%d\n",enb1,enb2);

        if(sinif[0]+sinif[1]+sinif[2]>=m){

            if(sinif[0]==enb1 && sinif[1]==enb2){

                if((m-enb1)>enb2){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                    for(i=(enb1+enb2);i<m;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                }
                else if((m-enb1)<=enb2){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                }
            }

            else if(sinif[0]==enb1 && sinif[2]==enb2){
                if((m-enb1)>enb2){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                    for(i=(enb1+enb2);i<m;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                }
                else if((m-enb1)<=enb2){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                }
            }

            else if(sinif[1]==enb1 && sinif[0]==enb2){
                if((m-enb1)>enb2){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                    for(i=(enb1+enb2);i<m;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                }
                else if((m-enb1)<=enb2){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                }
            }
            else if(sinif[1]==enb1 && sinif[2]==enb2){
                if((m-enb1)>enb2){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                    for(i=(enb1+enb2);i<m;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                }
                else if((m-enb1)<=enb2){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                }
            }

            else if(sinif[2]==enb1 && sinif[0]==enb2){
                if((m-enb1)>enb2){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                    for(i=(enb1+enb2);i<m;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                }
                else if((m-enb1)<=enb2){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                }
            }

            else if(sinif[2]==enb1 && sinif[1]==enb2){
                if((m-enb1)>enb2){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                    for(i=(enb1+enb2);i<m;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                }
                else if((m-enb1)<=enb2){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                }
            }
        }
        else
            printf("\n---------------------------------------\nSinif kapasiteleri yetersiz!!\n");

        if(sinif[0]+sinif[1]+sinif[2]>=p){

            if(sinif[0]==enb1 && sinif[1]==enb2){

                if((p-enb1)>enb2){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        d++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                    for(i=(enb1+enb2);i<p;i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                }
                else if((p-enb1)<=enb2){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        d++;
                    }
                    for(i=enb1;i<p;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                }
            }

            else if(sinif[0]==enb1 && sinif[2]==enb2){
                if((p-enb1)>enb2){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        d++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                    for(i=(enb1+enb2);i<p;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                }
                else if((p-enb1)<=enb2){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        d++;
                    }
                    for(i=enb1;i<p;i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                }
            }

            else if(sinif[1]==enb1 && sinif[0]==enb2){
                if((p-enb1)>enb2){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        d++;
                    }
                    for(i=(enb1+enb2);i<p;i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                }
                else if((p-enb1)<=enb2){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                    for(i=enb1;i<p;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        d++;
                    }
                }
            }
            else if(sinif[1]==enb1 && sinif[2]==enb2){
                if((p-enb1)>enb2){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                    for(i=(enb1+enb2);i<p;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        d++;
                    }
                }
                else if((p-enb1)<=enb2){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                    for(i=enb1;i<p;i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                }
            }

            else if(sinif[2]==enb1 && sinif[0]==enb2){
                if((p-enb1)>enb2){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        d++;
                    }
                    for(i=(enb1+enb2);i<p;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                }
                else if((p-enb1)<=enb2){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                    for(i=enb1;i<p;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        d++;
                    }
                }
            }

            else if(sinif[2]==enb1 && sinif[1]==enb2){
                if((p-enb1)>enb2){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                    for(i=(enb1+enb2);i<p;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        d++;
                    }
                }
                else if((p-enb1)<=enb2){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                    for(i=enb1;i<p;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                }
            }
        }
        else
            printf("\n---------------------------------------\nSinif kapasiteleri yetersiz!!\n");

        printf("En az sinif dagilimi 1.Ogretim :%d %d %d \t 2.Ogretim :%d %d %d\n",a,b,c,d,e,f);

        fclose(sinif1);
        fclose(sinif2);
        fclose(sinif3);
        fclose(sinif4);
        fclose(sinif5);
        fclose(sinif6);
    }
    else if(s==4){
        FILE *sinif1=fopen("C:/Users/uset/Desktop/Proje/proje2/en_az/sinif1ogr1.txt","w");
        FILE *sinif2=fopen("C:/Users/uset/Desktop/Proje/proje2/en_az/sinif2ogr1.txt","w");
        FILE *sinif3=fopen("C:/Users/uset/Desktop/Proje/proje2/en_az/sinif3ogr1.txt","w");
        FILE *sinif4=fopen("C:/Users/uset/Desktop/Proje/proje2/en_az/sinif4ogr1.txt","w");
        FILE *sinif5=fopen("C:/Users/uset/Desktop/Proje/proje2/en_az/sinif1ogr2.txt","w");
        FILE *sinif6=fopen("C:/Users/uset/Desktop/Proje/proje2/en_az/sinif2ogr2.txt","w");
        FILE *sinif7=fopen("C:/Users/uset/Desktop/Proje/proje2/en_az/sinif3ogr2.txt","w");
        FILE *sinif8=fopen("C:/Users/uset/Desktop/Proje/proje2/en_az/sinif4ogr2.txt","w");

        enb1=sinif[0];
        enb2=sinif[1];
        enb3=sinif[1];
        enk=sinif[0];

        for(i=1;i<4;i++){
            if(sinif[i]>enb1){
                enb2=enb1;
                enb1=sinif[i];
            }
            else if(sinif[i]>enb2){
                enb2=sinif[i];
            }
        }

        for(i=1;i<4;i++){
            if(sinif[i]<enk){
                enb3=enk;
                enk=sinif[i];
            }
            else if(sinif[i]<enb3){
                enb3=sinif[i];
            }
        }

        if(sinif[0]+sinif[1]+sinif[2]+sinif[3]>=m){
            if(sinif[0]==enb1 && sinif[1]==enb2 && sinif[2]==enb3){
                if(m>(enb1+enb2+enb3)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                    for(i=(enb1+enb2);i<(enb1+enb2+enb3);i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                    for(i=(enb1+enb2+enb3);i<m;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                }
                else if(m>(enb1+enb2)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                    for(i=(enb1+enb2);i<m;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                }
                else if(m>enb1){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                }
                else if(m<=enb1){
                    for(i=0;i<m;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                }
            }
            else if(sinif[0]==enb1 && sinif[1]==enb2 && sinif[3]==enb3){
                if(m>(enb1+enb2+enb3)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                    for(i=(enb1+enb2);i<(enb1+enb2+enb3);i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                    for(i=(enb1+enb2+enb3);i<m;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                }
                else if(m>(enb1+enb2)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                    for(i=(enb1+enb2);i<m;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                }
                else if(m>enb1){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                }
                else if(m<=enb1){
                    for(i=0;i<m;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                }
            }
            else if(sinif[0]==enb1 && sinif[2]==enb2 && sinif[1]==enb3){
                if(m>(enb1+enb2+enb3)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                    for(i=(enb1+enb2);i<(enb1+enb2+enb3);i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                    for(i=(enb1+enb2+enb3);i<m;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                }
                else if(m>(enb1+enb2)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                    for(i=(enb1+enb2);i<m;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                }
                else if(m>enb1){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                }
                else if(m<=enb1){
                    for(i=0;i<m;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                }
            }
            else if(sinif[0]==enb1 && sinif[2]==enb2 && sinif[3]==enb3){
               if(m>(enb1+enb2+enb3)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                    for(i=(enb1+enb2);i<(enb1+enb2+enb3);i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                    for(i=(enb1+enb2+enb3);i<m;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                }
                else if(m>(enb1+enb2)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                    for(i=(enb1+enb2);i<m;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                }
                else if(m>enb1){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                }
                else if(m<=enb1){
                    for(i=0;i<m;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                }
            }
            else if(sinif[0]==enb1 && sinif[3]==enb2 && sinif[1]==enb3){
                if(m>(enb1+enb2+enb3)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                    for(i=(enb1+enb2);i<(enb1+enb2+enb3);i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                    for(i=(enb1+enb2+enb3);i<m;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                }
                else if(m>(enb1+enb2)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                    for(i=(enb1+enb2);i<m;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                }
                else if(m>enb1){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                }
                else if(m<=enb1){
                    for(i=0;i<m;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                }
            }
            else if(sinif[0]==enb1 && sinif[3]==enb2 && sinif[2]==enb3){
                if(m>(enb1+enb2+enb3)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                    for(i=(enb1+enb2);i<(enb1+enb2+enb3);i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                    for(i=(enb1+enb2+enb3);i<m;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                }
                else if(m>(enb1+enb2)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                    for(i=(enb1+enb2);i<m;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                }
                else if(m>enb1){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                }
                else if(m<=enb1){
                    for(i=0;i<m;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                }
            }
            else if(sinif[1]==enb1 && sinif[0]==enb2 && sinif[2]==enb3){
               if(m>(enb1+enb2+enb3)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                    for(i=(enb1+enb2);i<(enb1+enb2+enb3);i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                    for(i=(enb1+enb2+enb3);i<m;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                }
                else if(m>(enb1+enb2)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                    for(i=(enb1+enb2);i<m;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                }
                else if(m>enb1){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                }
                else if(m<=enb1){
                    for(i=0;i<m;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                }
            }
            else if(sinif[1]==enb1 && sinif[0]==enb2 && sinif[3]==enb3){
                if(m>(enb1+enb2+enb3)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                    for(i=(enb1+enb2);i<(enb1+enb2+enb3);i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                    for(i=(enb1+enb2+enb3);i<m;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                }
                else if(m>(enb1+enb2)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                    for(i=(enb1+enb2);i<m;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                }
                else if(m>enb1){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                }
                else if(m<=enb1){
                    for(i=0;i<m;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                }
            }
            else if(sinif[1]==enb1 && sinif[2]==enb2 && sinif[0]==enb3){
                if(m>(enb1+enb2+enb3)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                    for(i=(enb1+enb2);i<(enb1+enb2+enb3);i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                    for(i=(enb1+enb2+enb3);i<m;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                }
                else if(m>(enb1+enb2)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                    for(i=(enb1+enb2);i<m;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                }
                else if(m>enb1){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                }
                else if(m<=enb1){
                    for(i=0;i<m;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                }
            }
            else if(sinif[1]==enb1 && sinif[2]==enb2 && sinif[3]==enb3){
                if(m>(enb1+enb2+enb3)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                    for(i=(enb1+enb2);i<(enb1+enb2+enb3);i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                    for(i=(enb1+enb2+enb3);i<m;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                }
                else if(m>(enb1+enb2)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                    for(i=(enb1+enb2);i<m;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                }
                else if(m>enb1){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                }
                else if(m<=enb1){
                    for(i=0;i<m;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                }
            }
            else if(sinif[1]==enb1 && sinif[3]==enb2 && sinif[0]==enb3){
                if(m>(enb1+enb2+enb3)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                    for(i=(enb1+enb2);i<(enb1+enb2+enb3);i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                    for(i=(enb1+enb2+enb3);i<m;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                }
                else if(m>(enb1+enb2)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                    for(i=(enb1+enb2);i<m;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                }
                else if(m>enb1){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                }
                else if(m<=enb1){
                    for(i=0;i<m;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                }
            }
            else if(sinif[1]==enb1 && sinif[3]==enb2 && sinif[2]==enb3){
                if(m>(enb1+enb2+enb3)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                    for(i=(enb1+enb2);i<(enb1+enb2+enb3);i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                    for(i=(enb1+enb2+enb3);i<m;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                }
                else if(m>(enb1+enb2)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                    for(i=(enb1+enb2);i<m;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                }
                else if(m>enb1){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                }
                else if(m<=enb1){
                    for(i=0;i<m;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                }
            }
            else if(sinif[2]==enb1 && sinif[0]==enb2 && sinif[1]==enb3){
                if(m>(enb1+enb2+enb3)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                    for(i=(enb1+enb2);i<(enb1+enb2+enb3);i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                    for(i=(enb1+enb2+enb3);i<m;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                }
                else if(m>(enb1+enb2)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                    for(i=(enb1+enb2);i<m;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                }
                else if(m>enb1){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                }
                else if(m<=enb1){
                    for(i=0;i<m;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                }
            }
            else if(sinif[2]==enb1 && sinif[0]==enb2 && sinif[3]==enb3){
                if(m>(enb1+enb2+enb3)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                    for(i=(enb1+enb2);i<(enb1+enb2+enb3);i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                    for(i=(enb1+enb2+enb3);i<m;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                }
                else if(m>(enb1+enb2)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                    for(i=(enb1+enb2);i<m;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                }
                else if(m>enb1){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                }
                else if(m<=enb1){
                    for(i=0;i<m;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                }
            }
            else if(sinif[2]==enb1 && sinif[1]==enb1 && sinif[0]==enb3){
                if(m>(enb1+enb2+enb3)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                    for(i=(enb1+enb2);i<(enb1+enb2+enb3);i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                    for(i=(enb1+enb2+enb3);i<m;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                }
                else if(m>(enb1+enb2)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                    for(i=(enb1+enb2);i<m;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                }
                else if(m>enb1){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                }
                else if(m<=enb1){
                    for(i=0;i<m;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                }
            }
            else if(sinif[2]==enb1 && sinif[1]==enb2 && sinif[3]==enb3){
                if(m>(enb1+enb2+enb3)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                    for(i=(enb1+enb2);i<(enb1+enb2+enb3);i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                    for(i=(enb1+enb2+enb3);i<m;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                }
                else if(m>(enb1+enb2)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                    for(i=(enb1+enb2);i<m;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                }
                else if(m>enb1){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                }
                else if(m<=enb1){
                    for(i=0;i<m;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                }
            }
            else if(sinif[2]==enb1 && sinif[3]==enb2 && sinif[0]==enb3){
                if(m>(enb1+enb2+enb3)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                    for(i=(enb1+enb2);i<(enb1+enb2+enb3);i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                    for(i=(enb1+enb2+enb3);i<m;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                }
                else if(m>(enb1+enb2)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                    for(i=(enb1+enb2);i<m;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                }
                else if(m>enb1){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                }
                else if(m<=enb1){
                    for(i=0;i<m;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                }
            }
            else if(sinif[2]==enb1 && sinif[3]==enb2 && sinif[1]==enb3){
                if(m>(enb1+enb2+enb3)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                    for(i=(enb1+enb2);i<(enb1+enb2+enb3);i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                    for(i=(enb1+enb2+enb3);i<m;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                }
                else if(m>(enb1+enb2)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                    for(i=(enb1+enb2);i<m;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                }
                else if(m>enb1){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                }
                else if(m<=enb1){
                    for(i=0;i<m;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                }
            }
            else if(sinif[3]==enb1 && sinif[0]==enb2 && sinif[1]==enb3){
                if(m>(enb1+enb2+enb3)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                    for(i=(enb1+enb2);i<(enb1+enb2+enb3);i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                    for(i=(enb1+enb2+enb3);i<m;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                }
                else if(m>(enb1+enb2)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                    for(i=(enb1+enb2);i<m;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                }
                else if(m>enb1){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                }
                else if(m<=enb1){
                    for(i=0;i<m;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                }
            }
            else if(sinif[3]==enb1 && sinif[0]==enb2 && sinif[2]==enb3){
                if(m>(enb1+enb2+enb3)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                    for(i=(enb1+enb2);i<(enb1+enb2+enb3);i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                    for(i=(enb1+enb2+enb3);i<m;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                }
                else if(m>(enb1+enb2)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                    for(i=(enb1+enb2);i<m;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                }
                else if(m>enb1){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                }
                else if(m<=enb1){
                    for(i=0;i<m;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                }
            }
            else if(sinif[3]==enb1 && sinif[1]==enb2 && sinif[0]==enb3){
                if(m>(enb1+enb2+enb3)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                    for(i=(enb1+enb2);i<(enb1+enb2+enb3);i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                    for(i=(enb1+enb2+enb3);i<m;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                }
                else if(m>(enb1+enb2)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                    for(i=(enb1+enb2);i<m;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                }
                else if(m>enb1){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                }
                else if(m<=enb1){
                    for(i=0;i<m;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                }
            }
            else if(sinif[3]==enb1 && sinif[1]==enb2 && sinif[2]==enb3){
                if(m>(enb1+enb2+enb3)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                    for(i=(enb1+enb2);i<(enb1+enb2+enb3);i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                    for(i=(enb1+enb2+enb3);i<m;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                }
                else if(m>(enb1+enb2)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                    for(i=(enb1+enb2);i<m;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                }
                else if(m>enb1){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                }
                else if(m<=enb1){
                    for(i=0;i<m;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                }
            }
            else if(sinif[3]==enb1 && sinif[2]==enb2 && sinif[0]){
                if(m>(enb1+enb2+enb3)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                    for(i=(enb1+enb2);i<(enb1+enb2+enb3);i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                    for(i=(enb1+enb2+enb3);i<m;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                }
                else if(m>(enb1+enb2)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                    for(i=(enb1+enb2);i<m;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                }
                else if(m>enb1){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                }
                else if(m<=enb1){
                    for(i=0;i<m;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                }
            }
            else if(sinif[3]==enb1 && sinif[2]==enb2 && sinif[1]==enb1){
                if(m>(enb1+enb2+enb3)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                    for(i=(enb1+enb2);i<(enb1+enb2+enb3);i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                    for(i=(enb1+enb2+enb3);i<m;i++){
                        fprintf(sinif1,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        a++;
                    }
                }
                else if(m>(enb1+enb2)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                    for(i=(enb1+enb2);i<m;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        b++;
                    }
                }
                else if(m>enb1){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif3,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        c++;
                    }
                }
                else if(m<=enb1){
                    for(i=0;i<m;i++){
                        fprintf(sinif4,"%s\t %-12s%-12s%4d\t%s\n",ogr1[i].no,ogr1[i].ad,ogr1[i].soyad,ogr1[i].kayit_no,ogr1[i].ogr_tur);
                        d++;
                    }
                }
            }
        }
        else
            printf("-------------------------------\nSinif kapasiteleri yetersiz!!");

        if(sinif[0]+sinif[1]+sinif[2]+sinif[3]>=p){
            if(sinif[0]==enb1 && sinif[1]==enb2 && sinif[2]==enb3){
                if(p>(enb1+enb2+enb3)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                    for(i=(enb1+enb2);i<(enb1+enb2+enb3);i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                    for(i=(enb1+enb2+enb3);i<p;i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                }
                else if(p>(enb1+enb2)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                    for(i=(enb1+enb2);i<p;i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                }
                else if(p>enb1){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                }
                else if(p<=enb1){
                    for(i=0;i<p;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                }
            }
            else if(sinif[0]==enb1 && sinif[1]==enb2 && sinif[3]==enb3){
                if(p>(enb1+enb2+enb3)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                    for(i=(enb1+enb2);i<(enb1+enb2+enb3);i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                    for(i=(enb1+enb2+enb3);i<p;i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                }
                else if(p>(enb1+enb2)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                    for(i=(enb1+enb2);i<p;i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                }
                else if(p>enb1){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                }
                else if(p<=enb1){
                    for(i=0;i<p;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                }
            }
            else if(sinif[0]==enb1 && sinif[2]==enb2 && sinif[1]==enb3){
                if(p>(enb1+enb2+enb3)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                    for(i=(enb1+enb2);i<(enb1+enb2+enb3);i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                    for(i=(enb1+enb2+enb3);i<p;i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                }
                else if(p>(enb1+enb2)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                    for(i=(enb1+enb2);i<p;i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                }
                else if(p>enb1){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                }
                else if(p<=enb1){
                    for(i=0;i<p;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                }
            }
            else if(sinif[0]==enb1 && sinif[2]==enb2 && sinif[3]==enb3){
               if(p>(enb1+enb2+enb3)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                    for(i=(enb1+enb2);i<(enb1+enb2+enb3);i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                    for(i=(enb1+enb2+enb3);i<p;i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                }
                else if(p>(enb1+enb2)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                    for(i=(enb1+enb2);i<p;i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                }
                else if(p>enb1){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                }
                else if(p<=enb1){
                    for(i=0;i<p;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                }
            }
            else if(sinif[0]==enb1 && sinif[3]==enb2 && sinif[1]==enb3){
               if(p>(enb1+enb2+enb3)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                    for(i=(enb1+enb2);i<(enb1+enb2+enb3);i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                    for(i=(enb1+enb2+enb3);i<p;i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                }
                else if(p>(enb1+enb2)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                    for(i=(enb1+enb2);i<p;i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                }
                else if(p>enb1){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                }
                else if(p<=enb1){
                    for(i=0;i<p;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                }
            }
            else if(sinif[0]==enb1 && sinif[3]==enb2 && sinif[2]==enb3){
                if(p>(enb1+enb2+enb3)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                    for(i=(enb1+enb2);i<(enb1+enb2+enb3);i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                    for(i=(enb1+enb2+enb3);i<p;i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                }
                else if(p>(enb1+enb2)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                    for(i=(enb1+enb2);i<p;i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                }
                else if(p>enb1){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                }
                else if(p<=enb1){
                    for(i=0;i<p;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                }
            }
            else if(sinif[1]==enb1 && sinif[0]==enb2 && sinif[2]==enb3){
               if(p>(enb1+enb2+enb3)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                    for(i=(enb1+enb2);i<(enb1+enb2+enb3);i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                    for(i=(enb1+enb2+enb3);i<p;i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                }
                else if(p>(enb1+enb2)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                    for(i=(enb1+enb2);i<p;i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                }
                else if(p>enb1){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                }
                else if(p<=enb1){
                    for(i=0;i<p;i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                }
            }
            else if(sinif[1]==enb1 && sinif[0]==enb2 && sinif[3]==enb3){
                if(p>(enb1+enb2+enb3)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                    for(i=(enb1+enb2);i<(enb1+enb2+enb3);i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                    for(i=(enb1+enb2+enb3);i<p;i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                }
                else if(p>(enb1+enb2)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                    for(i=(enb1+enb2);i<p;i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                }
                else if(p>enb1){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                }
                else if(p<=enb1){
                    for(i=0;i<p;i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                }
            }
            else if(sinif[1]==enb1 && sinif[2]==enb2 && sinif[0]==enb3){
                if(p>(enb1+enb2+enb3)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                    for(i=(enb1+enb2);i<(enb1+enb2+enb3);i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                    for(i=(enb1+enb2+enb3);i<p;i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                }
                else if(p>(enb1+enb2)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                    for(i=(enb1+enb2);i<p;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                }
                else if(p>enb1){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                }
                else if(p<=enb1){
                    for(i=0;i<p;i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                }
            }
            else if(sinif[1]==enb1 && sinif[2]==enb2 && sinif[3]==enb3){
                if(p>(enb1+enb2+enb3)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                    for(i=(enb1+enb2);i<(enb1+enb2+enb3);i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                    for(i=(enb1+enb2+enb3);i<p;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                }
                else if(p>(enb1+enb2)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                    for(i=(enb1+enb2);i<p;i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                }
                else if(p>enb1){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                }
                else if(p<=enb1){
                    for(i=0;i<p;i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                }
            }
            else if(sinif[1]==enb1 && sinif[3]==enb2 && sinif[0]==enb3){
                if(p>(enb1+enb2+enb3)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                    for(i=(enb1+enb2);i<(enb1+enb2+enb3);i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                    for(i=(enb1+enb2+enb3);i<p;i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                }
                else if(p>(enb1+enb2)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                    for(i=(enb1+enb2);i<p;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                }
                else if(p>enb1){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                }
                else if(p<=enb1){
                    for(i=0;i<p;i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                }
            }
            else if(sinif[1]==enb1 && sinif[3]==enb2 && sinif[2]==enb3){
                if(p>(enb1+enb2+enb3)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                    for(i=(enb1+enb2);i<(enb1+enb2+enb3);i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                    for(i=(enb1+enb2+enb3);i<p;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                }
                else if(p>(enb1+enb2)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                    for(i=(enb1+enb2);i<p;i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                }
                else if(p>enb1){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                }
                else if(p<=enb1){
                    for(i=0;i<p;i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                }
            }
            else if(sinif[2]==enb1 && sinif[0]==enb2 && sinif[1]==enb3){
                if(p>(enb1+enb2+enb3)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                    for(i=(enb1+enb2);i<(enb1+enb2+enb3);i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                    for(i=(enb1+enb2+enb3);i<p;i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                }
                else if(p>(enb1+enb2)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                    for(i=(enb1+enb2);i<p;i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                }
                else if(p>enb1){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                }
                else if(p<=enb1){
                    for(i=0;i<p;i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                }
            }
            else if(sinif[2]==enb1 && sinif[0]==enb2 && sinif[3]==enb3){
                if(p>(enb1+enb2+enb3)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                    for(i=(enb1+enb2);i<(enb1+enb2+enb3);i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                    for(i=(enb1+enb2+enb3);i<p;i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                }
                else if(p>(enb1+enb2)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                    for(i=(enb1+enb2);i<p;i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                }
                else if(p>enb1){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                }
                else if(p<=enb1){
                    for(i=0;i<p;i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                }
            }
            else if(sinif[2]==enb1 && sinif[1]==enb1 && sinif[0]==enb3){
                if(p>(enb1+enb2+enb3)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                    for(i=(enb1+enb2);i<(enb1+enb2+enb3);i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                    for(i=(enb1+enb2+enb3);i<p;i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                }
                else if(p>(enb1+enb2)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                    for(i=(enb1+enb2);i<p;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                }
                else if(p>enb1){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                }
                else if(p<=enb1){
                    for(i=0;i<p;i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                }
            }
            else if(sinif[2]==enb1 && sinif[1]==enb2 && sinif[3]==enb3){
                if(p>(enb1+enb2+enb3)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                    for(i=(enb1+enb2);i<(enb1+enb2+enb3);i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                    for(i=(enb1+enb2+enb3);i<p;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                }
                else if(p>(enb1+enb2)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                    for(i=(enb1+enb2);i<p;i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                }
                else if(p>enb1){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                }
                else if(p<=enb1){
                    for(i=0;i<p;i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                }
            }
            else if(sinif[2]==enb1 && sinif[3]==enb2 && sinif[0]==enb3){
                if(p>(enb1+enb2+enb3)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                    for(i=(enb1+enb2);i<(enb1+enb2+enb3);i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                    for(i=(enb1+enb2+enb3);i<p;i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                }
                else if(p>(enb1+enb2)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                    for(i=(enb1+enb2);i<p;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                }
                else if(p>enb1){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                }
                else if(p<=enb1){
                    for(i=0;i<p;i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                }
            }
            else if(sinif[2]==enb1 && sinif[3]==enb2 && sinif[1]==enb3){
                if(p>(enb1+enb2+enb3)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                    for(i=(enb1+enb2);i<(enb1+enb2+enb3);i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                    for(i=(enb1+enb2+enb3);i<p;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                }
                else if(p>(enb1+enb2)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                    for(i=(enb1+enb2);i<p;i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                }
                else if(p>enb1){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                }
                else if(p<=enb1){
                    for(i=0;i<p;i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                }
            }
            else if(sinif[3]==enb1 && sinif[0]==enb2 && sinif[1]==enb3){
                if(p>(enb1+enb2+enb3)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                    for(i=(enb1+enb2);i<(enb1+enb2+enb3);i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                    for(i=(enb1+enb2+enb3);i<p;i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                }
                else if(p>(enb1+enb2)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                    for(i=(enb1+enb2);i<p;i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                }
                else if(p>enb1){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                }
                else if(p<=enb1){
                    for(i=0;i<p;i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                }
            }
            else if(sinif[3]==enb1 && sinif[0]==enb2 && sinif[2]==enb3){
                if(p>(enb1+enb2+enb3)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                    for(i=(enb1+enb2);i<(enb1+enb2+enb3);i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                    for(i=(enb1+enb2+enb3);i<p;i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                }
                else if(p>(enb1+enb2)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                    for(i=(enb1+enb2);i<p;i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                }
                else if(p>enb1){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                }
                else if(p<=enb1){
                    for(i=0;i<p;i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                }
            }
            else if(sinif[3]==enb1 && sinif[1]==enb2 && sinif[0]==enb3){
                if(p>(enb1+enb2+enb3)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                    for(i=(enb1+enb2);i<(enb1+enb2+enb3);i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                    for(i=(enb1+enb2+enb3);i<p;i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                }
                else if(p>(enb1+enb2)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                    for(i=(enb1+enb2);i<p;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                }
                else if(p>enb1){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif2,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                }
                else if(p<=enb1){
                    for(i=0;i<p;i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                }
            }
            else if(sinif[3]==enb1 && sinif[1]==enb2 && sinif[2]==enb3){
                if(p>(enb1+enb2+enb3)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                    for(i=(enb1+enb2);i<(enb1+enb2+enb3);i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                    for(i=(enb1+enb2+enb3);i<p;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                }
                else if(p>(enb1+enb2)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                    for(i=(enb1+enb2);i<p;i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                }
                else if(p>enb1){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                }
                else if(p<=enb1){
                    for(i=0;i<p;i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                }
            }
            else if(sinif[3]==enb1 && sinif[2]==enb2 && sinif[0]==enb3){
                if(p>(enb1+enb2+enb3)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                    for(i=(enb1+enb2);i<(enb1+enb2+enb3);i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                    for(i=(enb1+enb2+enb3);i<p;i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                }
                else if(p>(enb1+enb2)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                    for(i=(enb1+enb2);i<p;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                }
                else if(p>enb1){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                }
                else if(p<=enb1){
                    for(i=0;i<p;i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                }
            }
            else if(sinif[3]==enb1 && sinif[2]==enb2 && sinif[1]==enb1){
                if(p>(enb1+enb2+enb3)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                    for(i=(enb1+enb2);i<(enb1+enb2+enb3);i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                    for(i=(enb1+enb2+enb3);i<p;i++){
                        fprintf(sinif5,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        e++;
                    }
                }
                else if(p>(enb1+enb2)){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                    for(i=enb1;i<(enb1+enb2);i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                    for(i=(enb1+enb2);i<p;i++){
                        fprintf(sinif6,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        f++;
                    }
                }
                else if(p>enb1){
                    for(i=0;i<enb1;i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                    for(i=enb1;i<m;i++){
                        fprintf(sinif7,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        g++;
                    }
                }
                else if(p<=enb1){
                    for(i=0;i<p;i++){
                        fprintf(sinif8,"%s\t %-12s%-12s%4d\t%s\n",ogr2[i].no,ogr2[i].ad,ogr2[i].soyad,ogr2[i].kayit_no,ogr2[i].ogr_tur);
                        h++;
                    }
                }
            }
        }
        printf("En az sinif dagilimi 1.Ogretim :%d %d %d %d \t 2.Ogretim :%d %d %d %d\n",a,b,c,d,e,f,g,h);

        fclose(sinif1);
        fclose(sinif2);
        fclose(sinif3);
        fclose(sinif4);
        fclose(sinif5);
        fclose(sinif6);
        fclose(sinif7);
        fclose(sinif8);
    }
}
