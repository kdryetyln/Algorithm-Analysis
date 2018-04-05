#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

struct Dugum{
  int veri;
  struct Dugum *onceki,*sonraki;
};

struct Dugum *DugumEkle(struct Dugum *kok,int veri){
    if(kok==NULL){
        struct Dugum *yedek = (struct Dugum*)malloc(sizeof(struct Dugum));
        yedek->veri = veri;
        yedek->onceki = NULL;
        yedek->sonraki = NULL;
        return yedek;
    }
    if(kok->veri < veri){
        kok->sonraki = DugumEkle(kok->sonraki,veri);
    }else{
       kok->onceki = DugumEkle(kok->onceki,veri);
    }
    return kok;
}

void yazdir(struct Dugum *kok){
    if(kok){
        printf("%d ",kok->veri);
        yazdir(kok->onceki);
        yazdir(kok->sonraki);
    }
}

int min(struct Dugum *kok){
  if(kok->onceki == NULL){
    return kok->veri;
  }
  return min(kok->onceki);
}

int max(struct Dugum *kok){
  if(kok->sonraki == NULL){
    return kok->veri;
  }
  return max(kok->sonraki);
}

int DugumNo(struct Dugum *kok){
    if(kok==NULL) return 0;
    return 1+DugumNo(kok->onceki)+DugumNo(kok->sonraki);
}

int derinlik(struct Dugum * kok){
    if(kok==NULL) return 0;
    else{
        int onceki_yukseklik=0, sonraki_yukseklik=0;
        onceki_yukseklik=derinlik(kok->onceki);
        onceki_yukseklik=derinlik(kok->sonraki);
        if(onceki_yukseklik>onceki_yukseklik){
            return onceki_yukseklik+1;
        }
        else{
            return onceki_yukseklik+1;
        }
    }
}

int toplamderinlik(struct Dugum * kok){
    if(kok==NULL) return 0;
    int derinlik_deger= derinlik(kok)-1;
    int i, toplam=0;
    for(i=derinlik_deger; i>=0; i--){
        toplam += i;
    }
    return toplam;
}

int main(){

  struct Dugum *kok=NULL;

  int randm;
  srand(time(NULL));

  int i, no;
  printf("\n\tDugum degeri giriniz: ");
  scanf("%d", &no);

  for(i=0; i<no; i++){
    randm=1+rand()%100;
    kok = DugumEkle(kok,randm);
  }

  printf("\n");
  yazdir(kok);
  printf("\nMinimum  : %d",min(kok));
  printf("\nMaximum  : %d",max(kok));
  printf("\nDugum No : %d",DugumNo(kok));
  printf("\nDerinlik : %d",derinlik(kok)-1);
  printf("\nToplam derinlik : %d\n",toplamderinlik(kok));
  getch();
  return 0;
}
