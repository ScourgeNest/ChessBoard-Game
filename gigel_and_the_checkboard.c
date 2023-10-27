//Niculici Mihai-Daniel 315CA - gigel_and_the_checkboard
//Sper ca e bine, doamne ajuta.
#include <stdio.h>
#define ll long long
#define ull unsigned long long
//Functia e folosita ca sa calculez
//pe ce patratel cade piesa de sah in momentul in care
//iese de pe tabla de sah
ll convertor(ll i, int N)
{
	if (i > 0)
		return i % N;
	else
		return ((i % N) + N) % N;
}

//Verific daca piesa de sah iese de pe tabla sau nu
int verif(ll x, int N)
{
	if (x < 0 || x > N)
		return 0;
	return 1;
}

//Functia e apelata atunci cand patratelul alb pica pe i + j impar
void patratel_alb_impar(ll tabla_sah[][1000], ll i, ll *j, ull *pd, int N)
{
	//Verific daca e mai mare decat 0
	//pentru a aduna la distanta
	if (tabla_sah[i][*j] > 0)
		*pd += tabla_sah[i][*j];
	else
		*pd -= tabla_sah[i][*j];
	//Tin minte pozitia lui j ca sa am acces la biletelul
	// care se afla pe coordonatele i si j
	ll poz = *j;
	//Verific daca ies de pe tabla de sah
	if (verif(*j + tabla_sah[i][*j], N) == 0)
		//Si mut piesa de sah cu atatea patratele cat
		//scrie pe numarul de pe biletel
		*j = convertor((*j) + tabla_sah[i][*j], N);
	else
		*j += tabla_sah[i][*j];
	//Elimin numarul de pe biletelul pe care l-am folosit
	tabla_sah[i][poz] = 0;
}

//Functia e apelata atunci cand patratelul alb pica pe i + j par
void patratel_alb_par(ll tabla_sah[][1000], ll i, ll *j, ull *pd, int N)
{
	//Verific daca e mai mare decat 0
	//pentru a aduna la distanta
	if (tabla_sah[i][*j] > 0)
		*pd += tabla_sah[i][*j];
	else
		*pd -= tabla_sah[i][*j];
	//Tin minte pozitia lui j ca sa am acces la biletelul
	// care se afla pe coordonatele i si j
	ll poz = *j;
	//Verific daca ies de pe tabla de sah
	if (verif(*j + tabla_sah[i][*j], N) == 0)
	//Si mut piesa de sah cu atatea patratele cat scrie pe numarul de pe biletel
		*j = convertor(*j + tabla_sah[i][*j], N);
	else
		*j += tabla_sah[i][*j];
	//Elimin numarul de pe biletelul pe care l-am folosit
	tabla_sah[i][poz] = 0;
}

//Functia e apelata atunci cand patratelul negru pica pe i + j par
void patratel_negru_par(ll tabla_sah[][1000], ll *i, ll j, ull *pd, int N)
{
	//Verific daca e mai mare decat 0
	//pentru a aduna la distanta
	if (tabla_sah[*i][j] > 0)
		*pd += tabla_sah[*i][j];
	else
		*pd -= tabla_sah[*i][j];
	//Tin minte pozitia lui i ca sa am acces la biletelul
	// care se afla pe coordonatele i si j
	ll poz = *i;
	//Verific daca ies de pe tabla de sah
	if (verif(*i - tabla_sah[*i][j], N) == 0)
	//Si mut piesa de sah cu atatea patratele cat scrie pe numarul de pe biletel
		*i = convertor(*i - tabla_sah[*i][j], N);
	else
		*i -= tabla_sah[*i][j];
	//Elimin numarul de pe biletelul pe care l-am folosit
	tabla_sah[poz][j] = 0;
}

//Functia e apelata atunci cand patratelul negru pica pe i + j impar
void patratel_negru_impar(ll tabla_sah[][1000], ll *i, ll j, ull *pd, int N)
{
	//Verific daca e mai mare decat 0
	//pentru a aduna la distanta
	if (tabla_sah[*i][j] > 0)
		*pd += tabla_sah[*i][j];
	else
		*pd -= tabla_sah[*i][j];
	//Tin minte pozitia lui i ca sa am acces la biletelul
	// care se afla pe coordonatele i si j
	ll poz = *i;
	//Verific daca ies de pe tabla de sah
	if (verif(*i - tabla_sah[*i][j], N) == 0)
	//Si mut piesa de sah cu atatea patratele cat scrie pe numarul de pe biletel
		*i = convertor(*i - tabla_sah[*i][j], N);
	else
		*i -= tabla_sah[*i][j];
		//Elimin numarul de pe biletelul pe care l-am folosit
	tabla_sah[poz][j] = 0;
}

void poz_caract(int j)
{
	//Verific daca j-ul meu se afiseaza cu 1, 2 sau 3 caractere.
	//Apoi calculez ce coordonate ar trebui sa afisez pentru
	// fiecare situatie in parte
	if (j < 26) {
		printf("%c", 65 + j);
	} else if (j >= 26 && j < 677) {
		int a, b;
		a = j / 26;
		b = j % 26 + 1;
		printf("%c%c", 65 + a - 1, 65 + b - 1);
	}
	if (j > 676 && j < 1000) {
		int a, b, c;
		a = j / 26 / 26;
		b = j / 26 % 26 + 1;
		c = j % 26;
		printf("%c%c%c", 65 + a - 1, 65 + b - 1, 65 + c - 1);
	}
}

int alb_sau_negru(int N)
{
	//Verific daca patratelul alb pica pe impar sau par
	if (N % 2 == 0)
		return 1;
	return 0;
}

void citire_tabla_sah(int N, ll tabla_sah[][1000])
{
	//Citesc tabla de sah intr-un mod mai ciudat ca sa imi fie
	// mai usor sa rezolv problema (cel putin eu asa cred :) )
	for (int i = N - 1; i >= 0; i--)
		for (int j = 0; j < N; j++)
			scanf("%llu", &tabla_sah[i][j]);
}

int main(void)
{
	//Toate variabilele sunt explicate in README
	int N, alb_impar;
	ll tabla_sah[1000][1000], i, j;
	ll *pi = &i, *pj = &j;
	ull distanta = 0;
	ull *pd = &distanta;
	scanf("%d", &N);
	citire_tabla_sah(N, tabla_sah);
	//Verific unde pica patralele albe si negre
	alb_impar = alb_sau_negru(N);
	//Ma duc in coltul stanga sus
	i = N - 1;
	j = 0;
	//Si incep sa ma plimb cu piesa de sah
	while (tabla_sah[i][j] != 0) {
		//In functie de unde sunt patratelele am 2
		//cai pe unde pot sa ma duc
		if (alb_impar == 1) {
			if ((i + j) % 2 == 1)
				patratel_alb_impar(tabla_sah, i, pj, pd, N);
			else if ((i + j) % 2 == 0)
				patratel_negru_par(tabla_sah, pi, j, pd, N);
		} else {
			if ((i + j) % 2 == 0)
				patratel_alb_par(tabla_sah, i, pj, pd, N);
			else if ((i + j) % 2 == 1)
				patratel_negru_impar(tabla_sah, pi, j, pd, N);
		}
	}
	//Am facut asta pentru a evita cazul in care i = N-1
	//Iar cand ii dau ++, as iesi din tabla de sah si as afisa prost
	//coordonatele unde se afla piesa de sah.
	i = i % N;
	//Afisez distanta parcursa si cele 2 coordonate
	printf("%llu\n", distanta);
	printf("%lld ", i + 1);
	poz_caract(j);
	printf("\n");
	return 0;
}
