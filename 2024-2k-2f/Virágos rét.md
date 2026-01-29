# Alapötlet
https://njudge.hu/problemset/main/NT24_Viragosret/

Ha belegondolunk, nem számít az, hogy milyen sorrendben vannak a rétek, az számít, hogy mennyi van, mert csak lehetőségekről beszélünk. Így célszerű csak azokat a réteket számolni, ahol tudunk virágot szedni.

Megvan, hány virágos rétünk van, de hogyan tovább?

Az első ```k-1``` virágos rétre muszáj elmennünk, így őket nem tudjuk belevenni a lehetőségek közé.
A maradék rétet elképzelhetjük úgy, hogy annyi új lehetőséget ad, ahányadik maradék. Az első maradék 1, a második 2 (mert az 1.-ből elmegyünk ide, vagy kihagyjuk), a harmadik 3 (mert vagy csak az 1., az 1. és 2. vagy 1. és 2. és 3.-ba megyünk el) stb.

Mivel minden maradék rétre külön számoltuk meg az esetek számát, össze kell őket adnunk (vaggyal való összekötés).

```Csak 1+2+3...+n összege = Gauss-összegek = (n*(n+1))/2```

Kezelni a maradék eseteket, pl. ha minden rét 0, és k=4, akkor az összegünk (0-4+1*(0-4+2))/2=-3*-2/2=3, ami ugye nem lehet.
Ezért ha kevesebb rét van, mint ```k```, írjunk ki 0-t.
