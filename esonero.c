#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char Mess[128], Chiave[128], Crip[128];
char aut[128];
int a;
int dim_ch;
int dim_mess;
int dim_aut;
int caso1(){
  printf("inserire una chiave lunga 128 caratteri.\n");
  fgets(Chiave,128,stdin);
  dim_ch = strlen(Chiave)-1;
  printf("la tua chiave è: %s\n",Chiave);
  printf("dimensine messaggio: %d\n",dim_ch);
  if ( dim_ch < dim_mess ) {
    printf("la chiave è picola!! Inserisci una più lunga\n");
  } else {
    printf("la chiave è giusta!\n");

    printf("C cifrato e visualizzato in hex:");
    for (int i=0;i < strlen(Mess)-1; i++) {
      Crip[i] = Mess[i] ^ Chiave[i];
      printf("%X",Crip[i]);
  }
  printf("\n");
}
  return 0;
}
int caso2(){
    time_t t;
    srand((unsigned) time(&t));
    for (int i=0;i < strlen(Mess); i++) {
      aut[i] = 33+rand()%96;
      printf("la chiave generata è:%s\n",aut);
    }
    dim_aut = strlen(aut)-1;
    printf("la chiave è lunga:%d\n",dim_aut);

    printf("C cifrato e visualizzato in hex:");
    for (int i=0;i < strlen(Mess)-1; i++) {
      Crip[i] = Mess[i] ^ aut[i];
      printf("%X",aut[i]);
  }
  printf("\n");
    return 0;
}


int main (void)
{

  printf("inserire un messagio lungo 128 caratteri, se inserirai piu caratteri non verrano presi.\n");
  fgets(Mess,128,stdin);
  dim_mess = strlen(Mess)-1;
  printf("il tuo messagio è: %s\n",Mess);
  printf("dimensine messaggio: %d\n",dim_mess); //da togliere
  //getchar();
  printf("adesso puoi scegliere tra (1) e  (2), con 1 inserisci la chiave, con 2 si genera una chiave casuale.\n");
  scanf("%d",&a);
  getchar();
  if (a==1) {
    caso1();
  } else if (a==2) {
    caso2();
  } else {
    printf("devi inserire 1 o 2\n");
  }
  return 0;
}
