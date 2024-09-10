#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define max 100
typedef struct
{
    int CRjour;
    int CRmois;
    int CRans;
}dateCR;
typedef struct
{
    int jour;
    int mois;
    int ans;
} date;

typedef struct
{
    int id;
    char titre[20];
    char description[max];
    char statut[max];
    date deadline;
    dateCR CR_time;
} tache;

int dim = 0;//total des taches
tache T[max]; // tableau de structer
void ajouter_tache();//prototype
void ajouter_plusieurs_taches();
void afficher_tout();
void afficher_tri();
void rechercher();
void modifer();
void supprimer();
void Statistiques();
int main()
{
    int choix;
    do
    {
        printf("1 : ajouter_tache\n");
        printf("2 : ajouter_pluseur_tache\n");
        printf("3 : afficher_tout\n");
        printf("4 : afficher_tri\n");
        printf("5 : rechercher\n");
        printf("6 : modifer();\n");
        printf("7 : supprimer\n");
        printf("8 : statistique\n");
        printf("8 : exit");
        printf("entre le choix : ");
        scanf("%d", &choix);
        while (getchar() != '\n')// pour entre a la line
            ;
        switch (choix)
        {
        case 1:
            ajouter_tache();
            break;
        case 2:
            ajouter_plusieurs_taches();
            break;
        case 3:
            afficher_tout();
            break;
        case 4:
            afficher_tri();
            break;
        case 5:
            rechercher();
            break;
        case 6:
            modifer();
            break;
        case 7:
            supprimer();
            break;
        case 8:
            Statistiques();
            break;
        default:
            printf("---------------------\n");
            printf("le choix indisponible\n");
            printf("---------------------\n");
            break;
        }
    } while (choix != 10);//le numbre de exite
    return 0;
}
void ajouter_tache()
{
      int choix;
    printf("entre le titre : ");
    scanf(" %[^\n]", T[dim].titre);
    printf("entre le description : ");
    scanf(" %[^\n]", T[dim].description);
    printf("1 : statut à réaliser\n");
    printf("2 : statut en cours de réalisation\n");
    printf("3 : statut finalisée\n");
    printf("entre votre choix : ");
    scanf("%d",&choix);
    switch(choix)
    {
    case 1:
        strcpy(T[dim].statut,"e realiser");
        break;
    case 2:
         strcpy(T[dim].statut,"en cours de realisation");
         break;
    case 3:
          strcpy(T[dim].statut,"finalisee");
          break;
    default:
        printf("le choix indisponible");
    break;
    }
    printf("entre le date  sous laa forme jj/mm/yyyy : ");
    scanf("%d/%d/%d", &T[dim].deadline.jour, &T[dim].deadline.mois,&T[dim].deadline.ans);
    time_t time_CR = time(NULL);
    struct tm CR = *localtime(&time_CR);
    T[dim].CR_time.CRjour = CR.tm_mday;
    T[dim].CR_time.CRmois = CR.tm_mon+1;
    T[dim].CR_time.CRans = CR.tm_year+1900;
    printf("--------------------------------------\n");
    T[dim].id = dim + 1;
    dim++;
}
void ajouter_plusieurs_taches()
{
    int choix;
    int i, demo;
    int s;
    printf("-------------------------------------\n");
    printf("entre le numbre des elements : ");
    scanf("%d", &demo);
    printf("-------------------------------------\n");
    s = dim+demo;
    for (i = dim; i <s; i++)
    {
    printf("entre le titre : ");
    scanf(" %[^\n]", T[dim].titre);
    printf("entre le description : ");
    scanf(" %[^\n]", T[dim].description);
    printf("1 : statut à réaliser\n");
    printf("2 : statut en cours de réalisation\n");
    printf("3 : statut finalisée\n");
    printf("entre votre choix : ");
    scanf("%d",&choix);
    switch(choix)
    {
    case 1:
        strcpy(T[dim].statut,"a realiser");
        break;
    case 2:
         strcpy(T[dim].statut,"en cours de realisation");
         break;
    case 3:
          strcpy(T[dim].statut,"finalisee");
          break;
    default:
        printf("le choix indisponible");
    break;
    }
    printf("entre le date  sous laa forme jj/mm/yyyy : ");
    scanf("%d/%d/%d", &T[dim].deadline.jour, &T[dim].deadline.mois,&T[dim].deadline.ans);
    time_t time_CR = time(NULL);
    struct tm CR = *localtime(&time_CR);
    T[dim].CR_time.CRjour = CR.tm_mday;
    T[dim].CR_time.CRmois = CR.tm_mon;
    T[dim].CR_time.CRans = CR.tm_year;
    printf("--------------------------------------\n");
    T[dim].id = dim + 1;
    dim++;
    }
}
    void afficher_tout()
    {
        for(int i=0;i<dim;i++){
        printf("-------------------------------------\n");
        printf("1 : Id: %d\n", T[i].id);
        printf("2 : titre : %s\n", T[i].titre);
        printf("3 : desciption %s\n", T[i].description);
        printf("4 : stute %s\n", T[i].statut);
        printf("5 : deadline\n");
        printf("%d-%d-%d\n", T[i].deadline.jour, T[i].deadline.mois,T[i].deadline.ans);
        printf("6 : creation time\n");
        printf("%d-%d-%d\n",T[i].CR_time.CRans+1900,T[i].CR_time.CRmois+1,T[i].CR_time.CRjour);

        printf("-------------------------------------\n");
    }
}
void afficher_tri()
{
    int i, j;
    int choix;
    tache temp;
    printf("-------------------------------------\n");
    printf("1 : afficher par ordre alphabitique \n");
    printf("2 : afficher par deadline\n");
    printf("3 : afficher les tache done le deadline est dans 3jour ou moins\n");
    printf("-------------------------------------\n");
    printf("entre le choix : ");
    scanf("%d", &choix);
    if (choix == 1)
    {
            for (i = 0; i < dim - 1; i++)
            {
                for (j = i + 1; j < dim; j++)
                {
                    if (strcmp(T[i].titre, T[j].titre) > 0)
                    {
                        temp = T[i];
                        T[i] = T[j];
                        T[j] = temp;
                    }
                }
            }
            for(i=0;i<dim;i++)
            {
        printf("-------------------------------------\n");
        printf("1 : Id: %d\n", T[i].id);
        printf("2 : titre : %s\n", T[i].titre);
        printf("3 : desciption %s\n", T[i].description);
        printf("4 : stute %s\n", T[i].statut);
        printf("5 : deadline\n");
        printf("%d-%d-%d\n", T[i].deadline.jour, T[i].deadline.mois,T[i].deadline.ans);
        printf("6 : creation time\n");
        printf("%d-%d-%d\n",T[i].CR_time.CRans+1900,T[i].CR_time.CRmois+1,T[i].CR_time.CRjour);
        printf("-------------------------------------\n");
            }
        }
        if(choix==2)
        {
            for(int i=0;i<dim-1;i++)
            {
                for(int j=i+1;j<dim;j++)
                {
                    if (T[i].deadline.ans > T[j].deadline.ans ||
                    (T[i].deadline.ans == T[j].deadline.ans && T[i].deadline.mois > T[j].deadline.mois) ||
                    (T[i].deadline.ans == T[j].deadline.ans && T[i].deadline.mois == T[j].deadline.mois && T[i].deadline.jour > T[j].deadline.jour)){
                        temp = T[i];
                        T[i] = T[j];
                        T[j] = temp;
                    }
                }
            }
            for(i=0;i<dim;i++)
            {
        printf("-------------------------------------\n");
        printf("1 : Id: %d\n", T[i].id);
        printf("2 : titre : %s\n", T[i].titre);
        printf("3 : desciption %s\n", T[i].description);
        printf("4 : stute %s\n", T[i].statut);
        printf("5 : deadline\n");
        printf("%d-%d-%d\n", T[i].deadline.jour, T[i].deadline.mois,T[i].deadline.ans);
        printf("6 : creation time\n");
        printf("%d-%d-%d\n",T[i].CR_time.CRans+1900,T[i].CR_time.CRmois+1,T[i].CR_time.CRjour);
        printf("-------------------------------------\n");
            }
        }
      if(choix==3)
      {
          for(int i=0;i<dim;i++)
          {
              if((T[i].deadline.ans == T[i].CR_time.CRans) && (T[i].deadline.mois  - T[i].CR_time.CRmois)<=3 && (T[i].deadline.jour == T[i].CR_time.CRjour) )
              {
        printf("-------------------------------------\n");
        printf("1 : Id: %d\n", T[i].id);
        printf("2 : titre : %s\n", T[i].titre);
        printf("3 : desciption %s\n", T[i].description);
        printf("4 : stute %s\n", T[i].statut);
        printf("5 : deadline\n");
        printf("%d-%d-%d\n", T[i].deadline.jour, T[i].deadline.mois,T[i].deadline.ans);
        printf("6 : creation time\n");
        printf("%d-%d-%d\n",T[i].CR_time.CRans,T[i].CR_time.CRmois,T[i].CR_time.CRjour);
        printf("-------------------------------------\n");
              }
          }
      }

}
 void rechercher()
 {
    int choix;
    int id;
    char TITRE[100];
    printf("------------------------------------\n");
    printf("1 : rechercher par son ID\n");
    printf("2 : rechercher par son titre\n");
     printf("-----------------------------------\n");
      printf("entr le mode de rocherche : ");
     scanf("%d",&choix);
     if(choix==1)
     {
         printf("entre son ID : ");
         scanf("%d",&id);
         for(int i=0;i<dim;i++)
         {
             if(T[i].id==id)
             {
        printf("-------------------------------------\n");
        printf("----------je truver la tache---------\n");
        printf("-------------------------------------\n");
        printf("1 : Id: %d\n", T[i].id);
        printf("2 : titre : %s\n", T[i].titre);
        printf("3 : desciption %s\n", T[i].description);
        printf("4 : stute %s\n", T[i].statut);
        printf("5 : deadline\n");
        printf("%d-%d-%d\n", T[i].deadline.jour, T[i].deadline.mois,T[i].deadline.ans);
        printf("6 : creation time\n");
        printf("%d-%d-%d\n",T[i].CR_time.CRans+1900,T[i].CR_time.CRmois+1,T[i].CR_time.CRjour);
        printf("-------------------------------------\n");

             }
         }
     }
     if(choix==2)
     {
         printf("entrele titre de tache : ");
         scanf(" %[^\n]s",TITRE);
         for(int i=0;i<dim;i++)
         {
             if(strcmp(T[i].titre,TITRE)==0)
             {
        printf("-------------------------------------\n");
        printf("------------trouver la tach----------\n");
        printf("-------------------------------------\n");
        printf("1 : Id: %d\n", T[i].id);
        printf("2 : titre : %s\n", T[i].titre);
        printf("3 : desciption %s\n", T[i].description);
        printf("4 : stute %s\n", T[i].statut);
        printf("5 : deadline %d / %d / %d\n", T[i].deadline.jour, T[i].deadline.mois,T[i].deadline.ans);
        printf("-------------------------------------\n");
             }
         }
     }

 }
 void modifer()
 {
     int choix;
     char TITRE[100];
     char description[100];

     char statut[20];
     int jour,mois,ans;
     printf("----------------------------------------\n");
     printf("1 : modifier par description\n");
     printf("2 : modifier par statut\n");
     printf("3 : modifier par deadline\n");
     printf("entrer le choix : ");
     scanf("%d",&choix);
     printf("----------------------------------------\n");
     if(choix==1)
     {
         printf("entrer le titre de tache : ");
         scanf(" %[^\n]",TITRE);
         for(int i=0;i<dim;i++){
         if(strcmp(T[i].titre,TITRE)==0)
         {
             printf("je trouver la tache \n");
             printf("entre le nouvelle description : ");
             scanf(" %[^\n]",description);
            strcpy (T[i].description ,description);
             printf("le modification est suicce!");
         }
     }
 }
     if(choix==2)
     {
          printf("entrer le titre de tache : ");
         scanf(" %[^\n]",TITRE);
         for(int i=0;i<dim;i++){
         if(strcmp(T[i].titre,TITRE)==0)
         {
             printf("je trouver la tache \n");
             printf("entre le nouvelle statut : ");
             scanf(" %[^\n]",statut);
            strcpy(T[i].statut,statut);
             printf("le modification est suicce!");
     }
     if(choix==3)
     {

          printf("entrer le titre de tache : ");
         scanf(" %[^\n]",TITRE);
         for(i=0;i<dim;i++){
         if(strcmp(T[i].titre,TITRE)==0)
         {
             printf("je trouver la tache \n");
             printf("entre le vouvelle deadline jj/mm/yyyy : ");
             scanf("%d%d%d",&jour,&mois,&ans);
             T[i].deadline.jour = jour;
             T[i].deadline.mois = mois;
             T[i].deadline.ans  = ans;
             printf("le modification est suicce!");
     }
    }
   }
  }
 }
}
    void supprimer()
    {
        int i,id,j;
        int v =0;
        printf("entrer le ID : ");
        scanf("%d",&id);
        for(i=0;i<dim;i++)
        {
            if(T[i].id==id)
            {
                      {
        printf("-------------------------------------\n");
        printf("------------trouver la tach----------\n");
        printf("-------------------------------------\n");
        printf("1 : Id: %d\n", T[i].id);
        printf("2 : titre : %s\n", T[i].titre);
        printf("3 : desciption %s\n", T[i].description);
        printf("4 : stute %s\n", T[i].statut);
        printf("5 : deadline\n");
        printf("%d-%d-%d\n", T[i].deadline.jour, T[i].deadline.mois,T[i].deadline.ans);
        printf("6 : creation time\n");
        printf("%d-%d-%d\n",T[i].CR_time.CRans+1900,T[i].CR_time.CRmois+1,T[i].CR_time.CRjour);

             v=1;
             for(j=i;j<dim-1;j++)
             {
                 T[j] = T[j+1];
                 dim--;
             }
            }
        }
        if(v==0)
        {
            printf("error");
        }
    }
}
void statiq()
{
      int c,p,m;
            c=0;
            p=0;
            m=0;
            for(int i=0;i<dim;i++)
                {
            if(strcmp(T[i].statut, "a realiser")==0)
            {
                c++;
                break;
            }
            if(strcmp(T[i].statut, "en cours de realisation")==0)
            {
                p++;
                break;
            }
            if(strcmp(T[i].statut, "finalisee")==0)
            {
                m++;
                break;
            }
                }
                printf("le numbre des statut a realiser est %d\n",c);
                printf("le numbre des statut en cours de réalisation est %d\n",p);
                printf("le numbre des statut finalisée est %d\n",m);
}
   void staqjour()//statque les jour restants
   {
       int i ;
       time_t t = time(NULL);
struct tm dt = *localtime(&t);
   int j = dt.tm_mday;
   int m = dt.tm_mon+1;
   int a = dt.tm_year+1900;
   printf("Nombre de jours restants jusqu'au delai de chaque tache :\n");
   for(i=0 ;i<dim; i++){

     int jours = (T[i].deadline.ans- a)*365 + (T[i].deadline.mois - m)* 30 + (T[i].deadline.jour-j);
     printf("Identifiant: %d\n", T[i].id);
     printf("Titre: %s\n", T[i].titre);
     printf("Description: %s\n", T[i].description);
     printf("Deadline: %d/%d/%d\n",T[i].deadline.jour,T[i].deadline.mois,T[i].deadline.ans);
     printf("Date de Creation : %d/%d/%d\n",T[i].CR_time.CRjour,T[i].CR_time.CRmois,T[i].CR_time.CRans);
     printf("Jours restants: %d\n", jours);
     printf("Statut: %s\n", T[i].statut);
     printf("---------------------------------\n");
   }

       }

    void Statistiques()
    {
        int choix;
        printf("---------------------------------------\n");
        printf("1 : Afficher le numbre totale des tache\n");
        printf("2 : Afficher le nombre de tâches complètes et incomplètes\n");
        printf("3 : Afficher le nombre de jours restants jusqu'au délai de chaque tâche\n");
        printf("---------------------------------------\n");
        printf("entrer le choix : ");
        scanf("%d",&choix);
        switch(choix){
        case 1:
            printf("le numbre total des taches est %d\n",dim);
            break;
        case 2:
          statiq();
          break;
        case 3:
          staqjour();
          break;
    }
    }
