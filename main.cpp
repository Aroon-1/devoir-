#include <iostream>

// Prototypes des fonctions
size_t LongueurChaine(const char* chaine);
void CopierChaine(char* destination, const char* source);
void ConcatenerChaines(char* destination, const char* source);
char* TrouverCaractere(const char* chaine, char caractere);
size_t CompterOccurrences(const char* chaine, char caractere);
void CopierMemoire(void* destination, const void* source, size_t taille);
void InitialiserMemoire(void* zone, unsigned char valeur, size_t taille);
void ExtraireSousChaine(char* destination, const char* source, 
                       size_t debut, size_t longueur);
size_t DiviserChaine(const char* chaine, char separateur, 
                    char resultat[][100], size_t max_resultats);
int ComparerChaines(const char* chaine1, const char* chaine2);
void ConvertirMinuscules(char* chaine);
bool EstChaineNumerique(const char* chaine);

int main() {
    std::cout << "=== TEST DES FONCTIONS DE MANIPULATION DE CHAINES STYLE C ===" << std::endl;
    std::cout << "Compilé avec C++ et CLang++" << std::endl << std::endl;
    
    // Test 1: Longueur de chaîne
    char message[] = "Bonjour le monde";
    std::cout << "1. Longueur de '" << message << "': " << LongueurChaine(message) << std::endl;
    
    // Test 2: Copie de chaîne
    char copie[50];
    CopierChaine(copie, message);
    std::cout << "2. Copie: '" << copie << "'" << std::endl;
    
    // Test 3: Concaténation
    char salutation[100] = "Hello ";
    ConcatenerChaines(salutation, "World!");
    std::cout << "3. Concaténation: '" << salutation << "'" << std::endl;
    
    // Test 4: Recherche de caractère
    char* position = TrouverCaractere(message, 'j');
    if (position != nullptr) {
        std::cout << "4. Caractère 'j' trouvé à la position: " << (position - message) << std::endl;
    } else {
        std::cout << "4. Caractère 'j' non trouvé" << std::endl;
    }
    
    // Test 5: Comptage d'occurrences
    std::cout << "5. Occurrences de 'o' dans '" << message << "': " 
              << CompterOccurrences(message, 'o') << std::endl;
    
    // Test 6: Extraction de sous-chaîne
    char sous_chaine[20];
    ExtraireSousChaine(sous_chaine, message, 3, 5);
    std::cout << "6. Sous-chaîne (pos 3, longueur 5): '" << sous_chaine << "'" << std::endl;
    
    // Test 7: Division de chaîne
    char phrase[] = "pomme,orange,banane,kiwi";
    char fruits[10][100];
    size_t nb_fruits = DiviserChaine(phrase, ',', fruits, 10);
    
    std::cout << "7. Division de '" << phrase << "':" << std::endl;
    for (size_t i = 0; i < nb_fruits; i++) {
        std::cout << "   [" << i << "] " << fruits[i] << std::endl;
    }
    
    // Test 8: Fonctions mémoire
    char zone1[10] = "ABCDEFGHI";
    char zone2[10];
    CopierMemoire(zone2, zone1, 5);
    zone2[5] = '\0';
    std::cout << "8. Copie mémoire (5 octets): '" << zone2 << "'" << std::endl;
    
    char zone3[10];
    InitialiserMemoire(zone3, 'X', 5);
    zone3[5] = '\0';
    std::cout << "9. Initialisation mémoire: '" << zone3 << "'" << std::endl;
    
    // Test 10: Comparaison de chaînes
    char chaineA[] = "apple";
    char chaineB[] = "banana";
    int resultat_comparaison = ComparerChaines(chaineA, chaineB);
    std::cout << "10. Comparaison '" << chaineA << "' vs '" << chaineB << "': " 
              << resultat_comparaison << std::endl;
    
    // Test 11: Conversion minuscules
    char mixte[] = "Hello World!";
    std::cout << "11. Avant conversion: '" << mixte << "'" << std::endl;
    ConvertirMinuscules(mixte);
    std::cout << "    Après conversion: '" << mixte << "'" << std::endl;
    
    // Test 12: Vérification numérique
    char numerique[] = "12345";
    char non_numerique[] = "12a45";
    std::cout << "12. '" << numerique << "' est numérique: " 
              << (EstChaineNumerique(numerique) ? "OUI" : "NON") << std::endl;
    std::cout << "    '" << non_numerique << "' est numérique: " 
              << (EstChaineNumerique(non_numerique) ? "OUI" : "NON") << std::endl;
    
    return 0;
}

// ajouter les code a implementer ci dessous

#include <iostream>

size_t LongueurChaine(const char* chaine)
{
     const char* debut = chaine;
     while (*chaine != '\0')
    {
        chaine++;
    }
    return chaine - debut;
}

void CopierChaine(char* destination, const char* source)
{
    while (true)
    {
        *destination= *source;
        if(*source=='\0') break;
        destination++;
        source++;
    }
    
}

void ConcatenerChaines(char* destination, const char* source)
{
    while(*destination !='\0' ) {
        destination++;  } 
    /* parcours la chaine jusqu'a '\0', 
    en sortie de boucle destination sera sur '\0'*/
        if(*destination=='\0') // cette boucle copie source dans destination a partir de '\0'
        {
            while(true)
                {
                    *destination= *source;
                    if(*source=='\0') break;
                    destination++;
                    source++;
                   }
        }
}

char* TrouverCaractere(const char* chaine, char caractere)
{
        while(*chaine!= caractere)
        {
           if(*chaine == '\0') return nullptr;
           chaine++;
        } 
    return nullptr;
}

size_t CompterOccurrences(const char* chaine, char caractere)
{
    int i=0;
    while(*chaine!='\0')
    {
      if(*chaine==caractere)  i++;
      chaine++;
    }
return i;

}
void CopierMemoire(void* destination, const void* source, size_t taille)
{

    unsigned char* dest = (unsigned char*)destination;
    const unsigned char* src = (unsigned char*)source;

    for( size_t i=0; i<taille; i++ )
        {
            *(dest+i)=*(src+i);
        }
}

void InitialiserMemoire(void* zone, unsigned char valeur, size_t taille)
{
    unsigned char* z =(unsigned char*)zone;
    for(size_t i=0; i<taille; i++ )
    {
        *(z+i)= valeur;
    }
}

void ExtraireSousChaine(char* destination, const char* source,  size_t debut, size_t longueur) {
    size_t i=0;
    while(*source !='\0') // on compte le caractere de source
     {
        i++;
        source++;
     }
    if (debut>=i) // on verifie si debut est valide
     {
        *destination='\0';
     }
    if(debut<i)
    {
        for( size_t j=debut; j<longueur-debut; j++)
        {
            *(destination+j)=*(source+j);
                if(*source=='\0')
                {
                    *(destination+j)='\0';
                    break;
                }
        }
    }
}

size_t DiviserChaine(const char* chaine, char separateur, char resultat[][100], size_t max_resultats)
{
    size_t a=0; // compteur_resultats
    size_t b=0; // index_courant

    for(size_t i=0; *chaine !='\0'; i++)
    {
     if( chaine[i] ==separateur) {
        resultat[a][b]='\0';
        a++;
        b=0; }
    if (a>max_resultats) break;
    else{
        resultat[a][b]=chaine[i];
        b++;
     }
    }
    resultat[a][b]='\0';
    return a+1;
}

int ComparerChaines(const char* chaine1, const char* chaine2)
{
        size_t i=0;
    while( *chaine1 !='\0' && *chaine2 !='\0')
    {
        if(*chaine1 != *chaine2) 
        { 
            return chaine1[i]-chaine2[i];
        }
        i++;
    }
        return chaine1[i]- chaine2[i];
}

void ConvertirMinuscules(char* chaine)
{
    for(size_t i=0; chaine[i] !='\0'; i++)
    {
        if( chaine[i] >='A' && chaine[i]<='Z' )
        {
            chaine[i]+=32;
        }
    }
}

bool EstChaineNumerique(const char* chaine)
{
    if(chaine[0]=='-')
        {
            chaine++;
        }
    if(*chaine =='\0') return false;
    for(int i=0; chaine[i] !='\0'; i++ )
        {
            if (chaine[i] < '0' || chaine[i] > '9') return false;
        }
    return true;
}