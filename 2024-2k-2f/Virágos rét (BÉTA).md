# Alapötlet
https://njudge.hu/problemset/main/NT24_Viragosret/

Ha belegondolunk, nem számít az, hogy milyen sorrendben vannak a rétek, az számít, hogy mennyi van, mert csak lehetőségekről beszélünk. Így célszerű csak azokat a réteket számolni, ahol tudunk virágot szedni.

Megvan, hány virágos rétünk van, de hogyan tovább?

Az első ```k-1``` virágos rétre muszáj elmennünk, így őket nem tudjuk belevenni a lehetőségek közé.
A maradék rétet elképzelhetjük úgy, hogy annyi új lehetőséget ad, ahányadik maradék. Az első maradék 1, a második 2 (mert az 1.-ből elmegyünk ide, vagy kihagyjuk az elsőt), a harmadik 3 stb.

Vaggyal való összekötés = összegek = Gauss-összegek n*(n+1)/2), de kezelni a maradék eseteket, pl. ha minden rét 0, ezért ha kevesebb mint k, akkor nincs megoldás 
