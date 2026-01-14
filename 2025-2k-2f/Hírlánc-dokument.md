# Alapötlet
Ez egy gráfos probléma, viszont ez egy különleges gráf.
<img width="737" height="165" alt="image" src="https://github.com/user-attachments/assets/27a6aa0e-57a4-4f68-8a93-c35342b4f028" />

Ha megnézzük, minden komponens egy fagráf lenne, amíg bele nem fut egy körbe. Beláthatjuk, hogy a komponensekben mindig lesz kör, mert az összes diáknak kell küldenie üzenetet
(n csúcsú összefüggő min. éleinek száma n-1, de muszáj n élnek lennie -> kör)

Szóval van egy ilyen csodánk. Feladat: nézzük meg, melyik csúcsból hány másik csúcs érhető el, és adjuk meg a max.-ot

Két fajta csúcsunk van, ezekre máshogy számoljuk az elérhető élek számát:
- körben lévő csúcs: annyi, mint a kör hossza
- nem körben lévő csúcs: annyi, mint a gyerekének a hossza+1

Szóval, meg kell találnunk a köröket, kiszámolni a hosszukat, és abból kiszámolni a többi hosszt, eltárolni, maximumkiválasztás, kiírás. Szuper.

# Kód magyarázata
mondom, ez NEM fix, hogy a leghatékonyabb! Részeit a hivatalos megoldásból inspiráltattam.

```
struct Graph {
	int len[N];
	int parent[N];
	int next[N];
	bool bennE[N];
} g;
```

ez egy ```g``` nevű globális ```Graph``` változó, ```Graph``` pedig egy struktúra, amiben:
```
len: a csúcsokhoz tartozó hosszok
parent: csúcsok szülője
next: csúcsok gyereke
bennE: az éppen most történő bejárásban találkoztunk már ezzel a csúccsal. true ha igen, false ha nem.
```
```int dfs(int u)``` bonyi, több részre bontom, kis elmélet. Visszaadja az ```u``` csúcsból elérhető csúcsok hosszát.
```
g.bennE[u]=1;
	if (g.len[u]!=-1) {
		g.bennE[u]=0;
		return g.len[u];
	}
```
dfs elején megjelöljük, hogy ennél a csúcsnál már jártunk.
HA viszont kiszámoltuk már a csúcsát (ez van az ifben... a ```main```ben a default értéket -1-re állítom)
akkor szimplán ```return```. Juhú.

Ha nincs ekkora szerencsénk, megnézzük, ```u``` gyerekénél (```v```) voltunk-e. Ha igen, akkor találtunk egy kört! Ideje kiszámolni, mekkora ez a kör, és az összes körcsúcsra beállítani ezt a hosszt.
```
int v=g.next[u];

	if (g.bennE[v]) { //voltunk-e már itt
		int circle=0; //kör hosszát néző változó
		for (int w=u; ; w=g.parent[w]) { // addig menjünk, amíg újra el nem érünk v-ig. ha elértük, kilépünk.
			circle++;
			if (w==v) break;
		}
		for (int w=u; ; w=g.parent[w]) {
			g.len[w]=circle; // az összes körben szereplő csúcs hosszának beállítása
			if (w==v) break;
		}
		g.bennE[u]=0; //már nem kell ezzel a csúccsal foglalkoznunk
		return g.len[u];
	}
```
elvileg meg lehet csinálni a körhossz-számolást hátul tesztelős ```do {} while()```-lal, de a hivatalos megoldásban ez van

Ha nem találtunk kört, akkor még keressük, meghívjuk a gyerekre a csodafüggvényt. Ha a rekurzív hívás alatt megvan ```g.len[u]```, akkor nem kell semmi. Ha nem, a gyereke hossza+1.
```
g.parent[v]=u;
	int help=dfs(v);
	
	if (g.len[u]==-1) {
		g.len[u]=help+1;
	}
	g.bennE[u]=0;
	return g.len[u];
```
```memset(g.len, -1, sizeof g.len);``` itt inicializálom ```g.len``` értékeit, erről volt szó pár sorral feljebb.

Ez meg már csak egy max. kiválasztás. Ha eddig értetted, ezt már nem kell magyaráznom.
```
int megold=0, legtobb=0;
	for (int i=1; i<=n; i++) {
		int tmp=dfs(i);
		if (tmp>legtobb) {
			legtobb=tmp;
			megold=i;
		}
	}
	cout << megold << " " << legtobb;
```
# Plusz gondolatok, amiket ChatGPT ajánlott, miután megkérdeztem, mit gondol a fentiekről:
„Minden csúcs értékét legfeljebb egyszer számoljuk ki, ezért az algoritmus időkomplexitása O(N), memóriaigénye O(N).” (látható, amikor a legelején megnézzük, -1-e a csúcs hossza, hogy nem számolunk kétszer. Lehetne elegánsabban, de így is jó.)

„A parent tömb a DFS-fa visszafelé bejárásához kell, hogy a kör csúcsait végig tudjuk járni.” Mivel folyamatosan hivatkozunk rá, amikor a köröket számolgatjuk.

Rekurzióról: „A DFS mélysége legfeljebb N, ami a feladat korlátain belül biztonságos.”


