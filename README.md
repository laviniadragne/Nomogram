Semnificatia variabilelor:

t=numarul de puzzle-uri de verificat
n=numar linii
m=numar coloane
nr_bloc_linie[]=vectorul cu numarul de blocuri,citite de la tastatura, de pe fiecare linie
nr_bloc_coloana[]=vectorul cu numarul de blocuri,citite de la tastatura, de pe fiecare coloana
a[][]=matricea data spre verificare, grid-ul lui Gigel
i,j=contoare
k=contor ce numara la al catelea puzzle verificat sunt
matr_linie[]=matricea ce contine valorile citite de la tastatura pentru dimensiunea fiecarui bloc de 1 de pe fiecare linie
matr_col[]=matricea ce contine valorile citite de la tastatura pentru dimensiunea fiecarui bloc de 1
de pe fiecare coloana
ok=o variabila de tip intrerupator(switch) care arata daca gridul este sau nu corect
lung_secv=lungimea unui bloc de 1 din matricea data spre verificare
matr_linie_constr[][]=matricea ce contine dimensiunea fiecarui bloc de valori de 1 de pe fiecare
 linie din grid-ul completat de Gigel
matr_col_constr[][]=matricea ce contine dimensiunea fiecarui bloc de valori de 1 de pe fiecare
 coloana din grid-ul completat de Gigel
nr_bloc_linie_constr[]=vectorul cu numarul de blocuri de pe fiecare linie din grid-ul completat de
 Gigel
nr_bloc_col_constr[]=vectorul cu numarul de blocuri de pe fiecare coloana din grid-ul completat de
 Gigel
inceput=o variabila ce memoreaza la fiecare bloc de 1, al catalea este in matricile nou construite
v_afis[]=vector ce memoreaza valori de 0 respectiv 1 pentru fiecare puzzle in parte, 0 semnificand
 "Eroare" si 1 "Corect"

Algoritmul:

Functia "citirea" citeste de la tastatura valorile unei matrici si le stocheaza in memorie. Functia
"citirelinii" primeste ca parametri un vector, o matrice si un numar n. In interiorul ei se citesc si
se stocheaza in memorie un vector v[] cu n elemente si o matrice b[][] cu n linii si v[i] coloane.
Functia "citirecoloane" primeste ca parametri un vector, o matrice si un numar n. In interiorul ei se
citesc si se stocheaza in memorie un vector v[] cu n elemente si o matrice b[][] cu v[i] linii si n
coloane. Functia "umplere" umple o matrice, primita ca parametru, cu valori de "0". Functia "afisare"
afiseaza mesaje corespunzatoare "Eroare", respectiv "Corect" in functie de elementele vectorului primit ca si parametru.
Se citeste de la tastatura numarul de grid-uri. Se executa toate prelucrarile, pentru fiecare puzzle
in parte, intr-o structura repetitiva, de tip while, pana cand nu mai sunt puzzle-uri. Se citesc
dimensiunile matricei, se memoreaza in cate un vector numar de blocuri de 1 de pe fiecare linie,
respectiv coloana, iar in cate o matrice dimensiunele fiecarui bloc de 1 de pe fiecare linie,
respectiv coloana. Aceste 2 matrici si 2 vectori vor fi sablon. Peste ei vom suprapune matricile si
vectorii construiti pe baza valorilor din grid-ul lui Gigel. Daca suprapunerea are loc cu succes, si
toate valorile sunt identice, inseamna ca grid-ul a fost completat corect, daca nu, se va afisa
mesajul "Eroare". 
Pentru fiecare linie din matricea data, prin valorile citite de la tastatura, se calculeaza lungimea
fiecarei secvente de 1. O secventa este bloc de 1, daca vecinul din stanga(daca exista) al
elementului curent a fost tot 1 sau daca toata linia a fost 1. Ori de cate ori se incepe o secventa
noua, lung_secv se reinitializeaza cu 0. Daca la finalul liniei lung_secv nu este 0, inseamna ca
intreaga linie este cu elemente egale cu 1. Dimensiunile fiecarui bloc de pe fiecare linie este
stocat intr-o matrice(matr_linie_constr[][]), iar numarul de blocuri de pe fiecare linie este marit
dupa fiecare noua secventa gasita si memorate valorile intr-un vector(nr_bloc_linie_constr[]).
Acelasi procedeu se executa si pentru toate coloanele, obtinandu-se un vector cu numarul de blocuri
de pe fiecare coloana(nr_bloc_col_constr[]) si o matrice cu dimensiunea fiecarui bloc de pe fiecare
coloana(matr_col_constr[]). Variabila "inceput" are rolul de contor, pentru a putea tine cont pe ce
pozitie pun dimensiunile blocurilor in matricile nou construite.
Se compara vectorii de dimensiuni de blocuri de 1, obtinuti de pe urma matricei grid a lui Gigel, cu
vectorii de dimensiuni de blocuri de 1, obtinuti pe baza datelor de intrare-de tip restrictie.  Daca
acestia au valorile egale, se trece la compararea matricilor sablon, obtinute din dimensiunile
blocurilor de 1, din urma restrictiilor, cu matricile nou construite, pe baza gridu-lui lui Gigel. Se
procedeaza la fel si pentru matricile de tip linie, si pentru cele ce stocheaza dimensiunile
blocurilor de 1 de pe coloane. In final, daca suprapunerea este reusita, iar valorile sunt identice,
ok-ul va avea valoarea 1, ramanand neschimbat pe parcursul compararii. El este stocat intr-un
vector(v_afis[]) pe o pozitie k. La inceputul verificarii unui nou puzzle este egalat din nou cu 1.
La final, cu ajutorul functiei "afisare", se vor afisa mesajele corespunzatoare fiecarui puzzle
primit. Daca ok-ul are valoare 0, mesajul va fi "Eroare", respectiv daca are valoarea 1, "Corect".
