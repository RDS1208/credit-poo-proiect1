# Sistem de Gestiune Bancara

Program care gestioneaza credite bancare, clienti si operatii bancare simple.

## Clasele Proiectului

### Clasa Credit

Reprezinta un credit bancar cu tip, valoare, durata si dobanda.

**Operatii principale:**
- Obtine/seteaza informatiile creditului
- Calculeaza costul total (valoare + dobanda)
- Verifica daca creditul este platit

### Clasa Client

Reprezinta un client bancar cu credite.

**Operatii principale:**
- Obtine/seteaza informatiile clientului (nume, ID, venit)
- Calculeaza suma totala a creditelor
- Calculeaza plata lunara totala
- Verifica daca clientul este eligibil pentru un credit nou
- Adauga credite noi
- Efectueaza plati
- Elimina creditele complet platite

### Clasa Banca

Gestioneaza clientii si creditele bancii.

**Operatii principale:**
- Obtine/seteaza informatiile bancii
- Adauga clienti noi
- Afiseaza lista clientilor
- Acorda credite clientilor
- Afiseaza creditele unui client
- Calculeaza venitul total al clientilor

## Ce Poti Face

 Creezi credite cu parametri personalizati
 Creezi clienti cu informatii personale
 Adaugi credite clientilor
 Verifi daca un client poate lua un credit nou (pe baza venitului)
 Efectuezi plati la credite
 Elimini creditele platite
 Vezi informatiile complete ale creditelor si clientilor
 Gestionezi mai multi clienti dintr-o banca





## Note


- Eligibilitatea pentru credit se calculeaza pe baza: venitul * 24 luni >= creditele existente + creditul dorit

