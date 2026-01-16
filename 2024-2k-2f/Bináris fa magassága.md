# Alapötlet
Ha megnézzük, a bináris fánk sorfolytonosan van számozva. Ez azt jelenti, hogy minden szülőnek a gyereke ```i*2```, és ```i*2+1```.

<img width="232" height="221" alt="image" src="https://github.com/user-attachments/assets/e7ec4597-49a7-499f-aa5a-e48b552e357e" />

Szóval felmerül a kérdés - kell-e tárolni? És nem, mert minden indexet ki tudunk számolni. Akkor mi kell?
```
magasság = legtávolabbi levél és 1. csúcs közti élek összege
```
Csak hogy ez folyamatosan változik, és kellene valami, amiben viszonylag gyorsan ki tudjuk számolni a dolgokat. Erre jön be a dp, ami a csúcsok magasságait fogja jelölni.

Minden csúcsra ki tudjuk számolni, milyen a magassága: 
```
A leveleknek 0, ők saját maguktól semennyi távra vannak.
Minden másnak élhossza a hosszabb gyerekével+a hosszabb gyerekének a magassága.
```
És ez így tök jó, mert ```dp[1]``` így tudja majd jelölni a magasságot (kihagytam a 0. indexet).
Ez azért tud még működni, mert N<=16, tehát M minden egyes bemenetére legfeljebb ennyi lépést kell csinálni, ami 16x50 000=8x10<sup>5</sup>, ami elvileg belefér az időlimitbe...
Szóval, tároljuk el az élhosszokat és egy dp-t, amibe tudunk számolni. Kezdetben minden élhossz=1.

# Kód
```
   const int MAXX= 1 << n;
```
Ez a max hossza a dp tömbünknek, vagyis a max csúcsszám+1.
A ```m << n``` operátor a balra bitshiftelés. Azt jelenti, hogy minden bitet eltol n-nel balra a bináris alakban m-ben, esszenciálisan __m__ x __2<sup>n</sup>__
(a 0. kettőhatványtól az n.-ig a kettőhatványok összege = 2<sup>n+1</sup>-1, ehhez adtam hozzá 1-et)

(illetve: "Egy N szintű teljes bináris fa első szintjén 1, a másodikon 2, a harmadikon 4, az N-ediken 2<sup>N-1</sup> elemet tartalmaz", így az előző képlet helyébe n=N-1)

```
vector <int> dp(MAXX,0);
vector <int> elhossz(MAXX,1);
    for (int i=MAXX/2-1; i>0; i--) {
        dp[i]=max(dp[i*2],dp[i*2+1])+1;
    }
```
Itt inicializálom az élhosszakat és dp-t, majd kiszámolom a kezdeti dp értékeket, amiket majd változtatunk.

```MAXX/2``` indextől ```MAXX``` indexig vannak a levelek, ezt a ```for```-ban teljesen kihagyom.

```
dp[i]=max(dp[i*2],dp[i*2+1])+1;
```
mivel minden élhossz=1, elég csak hozzáadni, kezdetben minden dp gyerek ugyanakkora, tulajdonképpen a ```max``` felesleges.

```
for (int a,hossz, i=0; i<m; i++) {
        cin >> a >> hossz;
        elhossz[a]=hossz;
        for (int j=a; j>0; j=j/2) {
            int bal=j*2, jobb=j*2+1;
            if (j*2<MAXX) {
                dp[j]=max(dp[bal]+elhossz[bal],
                      dp[jobb]+elhossz[jobb]);
            }
        }
        cout << dp[1] << "\n";
   }
```
Itt ```a```-tól kezdve megyek végig ```a``` szülein, amíg el nem érem az 1-et. Mindegyikre kiszámolom, a bal vagy a jobb gyereke a hosszabb, ezzel frissül ```dp[1]```. Szuper.

```if (j*2<MAXX)``` azért kell, mert nem akarjuk a gyerekek dp-jét változtatni.
