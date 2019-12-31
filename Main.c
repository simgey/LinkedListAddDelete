

#include <stdio.h>
#include<stdlib.h>
typedef struct List
{
    int deger;
    struct List *sonraki;
    
}list;

list *kok=NULL;
void EkleSon(int gelen)//sona ekler
{
    list *yeni=malloc(sizeof(list));
    yeni->deger=gelen;
    yeni->sonraki=NULL;
    
    if(kok==NULL)
    {
        kok=yeni;
    }
    else
    {
        list *d=kok;
        while(d->sonraki!=NULL)
        {
            d=d->sonraki;
        }
        d->sonraki=yeni;
        
    }
    
   
}
void EkleBas(int gelen )//basa ekler
{
    list *yeni=malloc(sizeof(list));
    yeni->deger=gelen;
    
    
    if(kok==NULL)
    {
        kok=yeni;
        kok->sonraki=NULL;

    }
    else
    {
        yeni->sonraki=kok;
        kok=yeni;
    }
}
void ArayaEkle(int nereye,int gelen)
{
    list *yeni=malloc(sizeof(list));
    yeni->deger=gelen;
    list *d=kok;
    if(kok==NULL)
    {
        kok=yeni;
        yeni->sonraki=NULL;
    }
    else
    {
        while(d->deger!=nereye)
        {
            d=d->sonraki;
        }
        yeni->sonraki=d->sonraki;
        d->sonraki=yeni;
    }
}
void SiraliEkleBuyuktenKucuge(int gelen)
{
    list *yeni=malloc(sizeof(list));
    yeni->deger=gelen;
    list *d=kok;
    if(kok==NULL)
    {
        kok=yeni;
        yeni->sonraki=NULL;
    }
    else if(d->sonraki==NULL)
    {
        if(d->deger<gelen)
        {
            yeni->sonraki=d;
            kok=yeni;
            
        }
        else
        {
            d->sonraki=yeni;
            yeni->sonraki=NULL;
        }
    }
    else
    {   list *k=kok;
        list * temp=kok;
        if(gelen<temp->deger)
        {
            while(temp->deger>gelen&&temp->sonraki!=NULL)
                 {
                     temp=temp->sonraki;
                 }
                 if(temp->sonraki==NULL)
                 {
                     temp->sonraki=yeni;
                     yeni->sonraki=NULL;
                 }
                 else
                 {
                     while(k->sonraki!=temp&&k->sonraki!=NULL)
                           {
                               k=k->sonraki;
                           }
                           yeni->sonraki=temp;
                           k->sonraki=yeni;
                 }
            
                 
               
        }
        else
        {
            yeni->sonraki=kok;
            kok=yeni;
        }
     
       
        
    }
    
    
}
void SiraliEkleKucuktenBuyuge(int gelen)
{
    list *temp=kok;
    list *yeni=malloc(sizeof(list));
    yeni->deger=gelen;
    if(kok==NULL)//listede hiç eleman yoksa
    {
        kok=yeni;
        yeni->sonraki=NULL;
    }
    else if(kok->sonraki==NULL)//listede tek eleman varsa
    {
        if(kok->deger>gelen)
        {
            yeni->sonraki=kok;
            kok=yeni;
        }
        else
        {
            kok->sonraki=yeni;
            yeni->sonraki=NULL;
        }
    }
    else//listede birden fazla eleman varsa
    {
        list *k=kok;
        if(temp->deger<gelen)
        {
            while(temp->deger<gelen &&temp->sonraki!=NULL)
            {
                temp=temp->sonraki;
            }
           if(temp->sonraki==NULL&&temp->deger<gelen)
           {
               temp->sonraki=yeni;
               yeni->sonraki=NULL;
           }
            else
            {
                while(k->sonraki!=temp&&k->sonraki!=NULL)
                 {
                    k=k->sonraki;
                  }
                            
                   yeni->sonraki=temp;
                   k->sonraki=yeni;
                          
            }
          
        }
        else
        {
            yeni->sonraki=kok;
            kok=yeni;
        }
    }
}
void silBastan( )
{
   if(kok==NULL)
   {
       printf("Liste zaten bos!");
       
   }
    else
    {
        kok=kok->sonraki;
    }
}
void silSondan()
{
    if(kok==NULL)
    {
        printf("Liste Boss!!");
        
    }
    else
    {  list *temp=kok;
        if(temp->sonraki==NULL)//tek eleman varsa
        {
            kok=NULL;
        }
        else
        {
            while(temp->sonraki->sonraki!=NULL)
                  {
                      temp=temp->sonraki;
                  }
                  temp->sonraki=NULL;
        }
      
    }
}
void Ara(int x)//ARAMA YAPAN FONKSİYON
{   list *d=kok;
    
    while(d->deger!=x && d->sonraki!=NULL)
    {
        d=d->sonraki;
    }
    if(d->deger !=x)
    {
        printf("\n%d Sayisi Listede Bulunamadi\n",x);
        
    }
    else
    {
        printf("\n%d Sayisi Listede Var\n",x);
    }
}
void goster()
{
    list *d=kok;
    if(d==NULL)
    {
        printf("Liste boş");

    }
    while(d!=NULL)
    {
        printf("%d\n",d->deger);
        d=d->sonraki;
    }
}
int main(int argc, const char * argv[]) {
   
    SiraliEkleKucuktenBuyuge(11);
    SiraliEkleKucuktenBuyuge(20);
    SiraliEkleKucuktenBuyuge(3);
    SiraliEkleKucuktenBuyuge(8);
    SiraliEkleKucuktenBuyuge(14);
    SiraliEkleKucuktenBuyuge(40);
    Ara(11);
    Ara(45);
    silBastan();
    silSondan();
    goster();
   
  
  
  
  
}
