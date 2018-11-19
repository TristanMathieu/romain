#include <stdio.h>
#include <stdlib.h>

/*
programme romain
//But : Faire un convertisseur décimal/romain en utilisannt la méthode soustractive.
//Entrée : Nb décimal ou Romain
//Sortie : Nb Romain ou décimal
// prendre en concidération la plage de valeur, on a un convertisseur sur le net pour vérifier si notre algo est conforme
// et sinon droit d'utiliser tout ce qu'on a vue en C
// en entete on join l'algo
// sera a rendre le code source compilable, et si on a fais ça sur des fichier séprarer

// --- PCD/FCT ---

-----------------------------------------------------------
Description : Convertit un nombre Décimal en chiffres Romain
Entrées : Nombre Décimal
Sorties : Chiffres Romain
-----------------------------------------------------------
PROCEDURE pcd()
	VAR
		nUser:ENTIER
		cRomain:TABLEAU [0..20] de CAR
		nCpt:ENTIER
	DEBUT
		REPETER
			ECRIRE "Entrez un entier entre 1 et 3999"
			LIRE nbUser
		JUSQU'A nbUser>nbUser<4000

		TANT QUE nbUser >= 1000 FAIRE
			SI nbUser >= 1000 ALORS
				cRomain[cpt] = 'M'
				nUser = nbUser-1000
				nCpt = cpt+1
			FINSI
		FIN TANT QUE

		SI nbUser >= 900 ALORS
			cRomain[cpt] = "CM"
			nUser = nbUser-900
			nCpt = cpt+1
		FINSI

		SI nbUser >= 500 ALORS
			cRomain[cpt] = "D"
			nUser = nbUser-500
			nCpt = cpt+1
		FINSI

		SI nbUser >= 400 ALORS
			cRomain[cpt] = "CD"
			nUser = nbUser-400
			nCpt = cpt+1
		FINSI

		TANT QUE nbUser >= 100 FAIRE
			SI nbUser >= 100 ALORS
				cRomain[cpt] = 'C'
				nUser = nbUser-100
				nCpt = cpt+1
			FINSI
		FIN TANT QUE

		SI nbUser >= 90 ALORS
			cRomain[cpt] = "XC"
			nUser = nbUser-90
			nCpt = cpt+1
		FINSI

		SI nbUser >= 50 ALORS
			cRomain[cpt] = "L"
			nUser = nbUser-50
			nCpt = cpt+1
		FINSI

		SI nbUser >= 40 ALORS
			cRomain[cpt] = "XL"
			nUser = nbUser-40
			nCpt = cpt+1
		FINSI

		TANT QUE nbUser >= 10 FAIRE
			SI nbUser >= 10 ALORS
				cRomain[cpt] = 'X'
				nUser = nbUser-10
				nCpt = cpt+1
			FINSI
		FIN TANT QUE

		SI nbUser >= 9 ALORS
			cRomain[cpt] = "IX"
			nUser = nbUser-9
			nCpt = cpt+1
		FINSI

		SI nbUser >= 5 ALORS
			cRomain[cpt] = "V"
			nUser = nbUser-5
			nCpt = cpt+1
		FINSI

		SI nbUser >= 4 ALORS
			cRomain[cpt] = "IV"
			nUser = nbUser-4
			nCpt = cpt+1
		FINSI

		TANT QUE nbUser >= 1 FAIRE
			SI nbUser >= 1 ALORS
				cRomain[cpt] = 'I'
				nUser = nbUser-1
				nCpt = cpt+1
			FINSI
		FIN TANT QUE

		romain[cpt] = '\0'

	FINPROCEDURE

PROCEDURE pcdRD()

-----------------------------------------------------------
Description : Convertit des chiffres Romain en nombre Décimal
Entrées : Chiffres Romain
Sorties : Nombre décimal
-----------------------------------------------------------
PROCEDURE RomDec()(
    var
    	cUser[0..20]
    	nCpt=0
    	nDec=0

    DEBUT
	    nCpt=0
	    nDec=0

	    ENTREZ ("Entrez votre nombre :\n")
	    LIRE (cUser)

	    TANT QUE  (cUser[nCpt]=='M'OUcUser[nCpt]=='m')(
	        nDec+=1000
	        nCpt++
	    )

	    SI (cUser[nCpt]=='C'OUcUser[nCpt]=='c')(
	        SI (cUser[nCpt+1]=='M')(
	            nDec+=900
	            nCpt+=2
	        )
	        SI (cUser[nCpt+1]=='D'OUcUser[nCpt]=='d')(
	            nDec+=400
	            nCpt+=2
	        )
	    )

	    SI (cUser[nCpt]=='D'OUcUser[nCpt]=='d')(
	        nDec+=500
	        nCpt++
	    )

	    TANT QUE  (cUser[nCpt]=='C'OUcUser[nCpt]=='c')(
	        nDec+=100
	        nCpt++
	    )

	    SI (cUser[nCpt]=='X'OUcUser[nCpt]=='x')(
	        SI (cUser[nCpt+1]=='C'OUcUser[nCpt]=='c')(
	            nDec+=90
	            nCpt+=2
	        )
	        SI (cUser[nCpt+1]=='L'OUcUser[nCpt]=='l')(
	            nDec+=40
	            nCpt+=2
	        )
	    )

	    SI (cUser[nCpt]=='L'OUcUser[nCpt]=='l')(
	        nDec+=50
	        nCpt++
	    )

	    TANT QUE  (cUser[nCpt]=='X'OUcUser[nCpt]=='x')(
	        nDec+=10
	        nCpt++
	    )

	    SI (cUser[nCpt]=='I'OUcUser[nCpt]=='i')(
	        SI (cUser[nCpt+1]=='X'OUcUser[nCpt]=='x')(
	            nDec+=9
	            nCpt+=2
	        )
	        SI (cUser[nCpt+1]=='V'OUcUser[nCpt]=='v')(
	            nDec+=4
	            nCpt+=2
	        )
	    )

	    SI (cUser[nCpt]=='V'OUcUser[nCpt]=='v')(
	        nDec+=5
	        nCpt++
	    )

	    TANT QUE  (cUser[nCpt]=='I'OUcUser[nCpt]=='i')(
	        nDec+=1
	        nCpt++
	    )

	    ENTREZ ("Résultat : ", nDec)
	)

	FINPROCEDURE


// PROGRAMME PRINCIPALE
VAR
	nMenu:ENTIER

DEBUT
	REPETER
		ECRIRE "1 : conv déc > romain" //de 1 à 3999 max
		ECRIRE "2 : conv romain > déc"
		ECRIRE "0 : quitter"
		LIRE nMenu
		CAS DE nMenu
		0 : ECRIRE "Sortie..."
		1 : pcdDR
		2 : pcdRD
		DEFAUT : ECRIRE "Mauvaise valeure"
	TANT QUE nMenu>0
FIN
*/

void DecRom();
void RomDec();

int main()
{
	int nMenu;
	printf("Bienvenue dans le programme de conversion.\n");
	do{
        printf("\n---------------------------------\n");
        printf("Menu principal :\n");
		printf("1 : conversion Decimal vers Romain.\n");
		printf("2 : conversion Romain vers Decimal.\n");
		printf("0 : Sorit du programme.\n");
		scanf("%d", &nMenu);

		switch(nMenu){
        case 0 :
            printf("\nSortit du programme...\n");
            break;

        case 1 :
            printf("\nEntree dans la conversion Decimal vers Romain.\n");
            DecRom();
            break;

        case 2 :
            printf("\nEntree dans la conversion Romain vers Decimal.\n");
            RomDec();
            break;

        default :
            printf("\nMauvaise variable.\n");
		}
    }while (nMenu>0);
    printf("Fin du programme.\n");
}

void DecRom(){
    int nUser=0;
    int nCpt=0;
    char cRomain[20];

    do{
        printf("Entrez un entier entre 1 et 3999 :\n");
        scanf("%d", &nUser);
    }while((nUser>4000)||(nUser<=0));

    printf("Romain : ");

    while (nUser>=1000){
        cRomain[nCpt]='M';
        printf("%c", cRomain[nCpt]);
        nCpt++;
        nUser-=1000;
    }

    if (nUser>=900){
        cRomain[nCpt]='C';
        printf("%c", cRomain[nCpt]);
        nCpt++;
        cRomain[nCpt]='M';
        printf("%c", cRomain[nCpt]);
        nCpt++;
        nUser-=900;
    }

    if (nUser>=500){
        cRomain[nCpt]='D';
        printf("%c", cRomain[nCpt]);
        nCpt++;
        nUser-=500;
    }

    if (nUser>=400){
        cRomain[nCpt]='C';
        printf("%c", cRomain[nCpt]);
        nCpt++;
        cRomain[nCpt]='D';
        printf("%c", cRomain[nCpt]);
        nCpt++;
        nUser-=400;
    }

    while (nUser>=100){
        cRomain[nCpt]='C';
        printf("%c", cRomain[nCpt]);
        nCpt++;
        nUser-=100;
    }

    if (nUser>=90){
        cRomain[nCpt]='X';
        printf("%c", cRomain[nCpt]);
        nCpt++;
        cRomain[nCpt]='C';
        printf("%c", cRomain[nCpt]);
        nCpt++;
        nUser-=90;
    }

    if (nUser>=50){
        cRomain[nCpt]='L';
        printf("%c", cRomain[nCpt]);
        nCpt++;
        nUser-=50;
    }

    if (nUser>=40){
        cRomain[nCpt]='X';
        printf("%c", cRomain[nCpt]);
        nCpt++;
        cRomain[nCpt]='L';
        printf("%c", cRomain[nCpt]);
        nCpt++;
        nUser-=40;
    }

    while (nUser>=10){
        cRomain[nCpt]='X';
        printf("%c", cRomain[nCpt]);
        nCpt++;
        nUser-=10;
    }

    if (nUser>=9){
        cRomain[nCpt]='I';
        printf("%c", cRomain[nCpt]);
        nCpt++;
        cRomain[nCpt]='X';
        printf("%c", cRomain[nCpt]);
        nCpt++;
        nUser-=9;
    }

    if (nUser>=5){
        cRomain[nCpt]='V';
        printf("%c", cRomain[nCpt]);
        nCpt++;
        nUser-=5;
    }

    if (nUser>=4){
        cRomain[nCpt]='I';
        printf("%c", cRomain[nCpt]);
        nCpt++;
        cRomain[nCpt]='V';
        printf("%c", cRomain[nCpt]);
        nCpt++;
        nUser-=4;
    }

    while (nUser>=1){
        cRomain[nCpt]='I';
        printf("%c", cRomain[nCpt]);
        nCpt++;
        nUser-=1;
    }
    printf("\nRetour au menu principal.\n");
}

void RomDec(){
    char cUser[20];
    int nCpt=0;
    int nDec=0;

    printf("Entrez votre nombre :\n");
    scanf("%s", cUser);

    while (cUser[nCpt]=='M'||cUser[nCpt]=='m'){
        nDec+=1000;
        nCpt++;
    }

    if (cUser[nCpt]=='C'||cUser[nCpt]=='c'){
        if (cUser[nCpt+1]=='M'){
            nDec+=900;
            nCpt+=2;
        }
        if (cUser[nCpt+1]=='D'||cUser[nCpt]=='d'){
            nDec+=400;
            nCpt+=2;
        }
    }

    if (cUser[nCpt]=='D'||cUser[nCpt]=='d'){
        nDec+=500;
        nCpt++;
    }

    while (cUser[nCpt]=='C'||cUser[nCpt]=='c'){
        nDec+=100;
        nCpt++;
    }

    if (cUser[nCpt]=='X'||cUser[nCpt]=='x'){
        if (cUser[nCpt+1]=='C'||cUser[nCpt]=='c'){
            nDec+=90;
            nCpt+=2;
        }
        if (cUser[nCpt+1]=='L'||cUser[nCpt]=='l'){
            nDec+=40;
            nCpt+=2;
        }
    }

    if (cUser[nCpt]=='L'||cUser[nCpt]=='l'){
        nDec+=50;
        nCpt++;
    }

    while (cUser[nCpt]=='X'||cUser[nCpt]=='x'){
        nDec+=10;
        nCpt++;
    }

    if (cUser[nCpt]=='I'||cUser[nCpt]=='i'){
        if (cUser[nCpt+1]=='X'||cUser[nCpt]=='x'){
            nDec+=9;
            nCpt+=2;
        }
        if (cUser[nCpt+1]=='V'||cUser[nCpt]=='v'){
            nDec+=4;
            nCpt+=2;
        }
    }

    if (cUser[nCpt]=='V'||cUser[nCpt]=='v'){
        nDec+=5;
        nCpt++;
    }

    while (cUser[nCpt]=='I'||cUser[nCpt]=='i'){
        nDec+=1;
        nCpt++;
    }

    printf("fin : %d", nDec);
}

