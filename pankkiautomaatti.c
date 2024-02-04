#include <stdio.h>
#include <string.h>


int kirjautuminen(void);
int otto();
void saldontarkistus();
int saldo = 1000;

int main(void)
{
    char tunnus;
    int syote;
    int valinta;
    int valinta2;

    syote = kirjautuminen();

    printf("\n\n1. Otto\n2.  Saldo\n\n");
    scanf("%d", &valinta);


                switch (valinta)
                {
                case 1:
                    otto(saldo);
                    break;

                case 2:
                    saldontarkistus(saldo);
                    break;

                }

                printf("\n\nHaluatko tehdä jotain muuta? 1=Kyllä ja 2=Ei\n\n");// 1=kyllä ja 2=ei
                scanf("%d", &valinta2);

                if (valinta2 == 1)
                {
                    printf("\n1. Otto\n2.  Saldo\n\n");
                    scanf("%d", &valinta);

                    switch (valinta)
                    {
                    case 1:
                         otto(saldo);
                         break;

                    case 2:
                         saldontarkistus(saldo);
                         break;
                    }

                }


                printf("\nKiitos käynnistä, tervetuloa uudelleen.\n");


    return 0;
}

int kirjautuminen(void){

    int ehto = 0;
    int ehto2 = 0;
    char tili[7];
    char pin1[5];
    char pin2[5];
    FILE * ptr;

    printf("Kirjoita tilinumerosi > ");
    scanf("%s", tili);

    tili[4] = '.'; tili[5] = 't'; tili[6] = 'i'; tili[7] = 'l'; tili[8] = 'i';

    while((ptr = fopen(tili, "r")) == NULL) {

        if(ehto2 == 2) {
            printf("\nSisäänkirjautuminen keskeytetty!\nSyötit väärän tilinumeron kolme kertaa!");
            return 0;
        }
        ehto2++;

        printf("\nVäärä tilinumero, yritä uudestaan, kiitos.\n\n");
        scanf("%s", tili);

        tili[4] = '.'; tili[5] = 't'; tili[6] = 'i'; tili[7] = 'l'; tili[8] = 'i';

    }

    printf("Syötä pinkoodisi > ");
    scanf("%s", pin2);

    fgets(pin1, 4, ptr);

    while(strcmp(pin1, pin2) && ehto < 2) {
        printf("\nAnnoit väärän pin-koodin");
        printf("\nSyötä pinkoodisi uudestaan! > ");
        scanf("%s", pin2);
        ehto++;
    }
    fclose(ptr);

    if(strcmp(pin1, pin2)){
        printf("\nSisäänkirjautuminen keskeytetty!\nVäärä pin-koodi syötetty väärin liian monta kertaa.");
        return 0;

    } else {
        printf("\nOikea pin-koodi syötetty. Tervetuloa!\n");
        return 1;
    }
}



int otto()
{
    int ottosumma;
    int setelit[2] = {50, 20};
    int i, temp;

    printf("\n\nVoit nostaa joko 20 euroa, 40 euroa tai enemmän, kymmenen euron välein.\nSuurin mahdollinen nostosumma on 1000 euroa.\n\nSyötä haluttu nostosumma > ");
    scanf("%d", &ottosumma);

    temp = ottosumma;
    saldo = saldo - ottosumma;

    if (ottosumma == 30 || ottosumma < 20){

       printf("\n\nEt syöttänyt nostosummaa annettujen ohjeiden mukaisesti.\n\n");
    }
    else {

       for(i = 0; i < 2; i++)
           {
        printf("\n%d seteleitä on = %d", setelit[i], temp / setelit[i]);
        temp = temp % setelit[i];
        }
    }

    return saldo;
}

void saldontarkistus()
{
    printf("Saldo: %d\n", saldo);
    return;
}



