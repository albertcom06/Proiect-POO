//PROIECT : Sistem de gestiune pariuri sportive
//DESCRIERE PROBLEMA: Programul simuleaza o platforma de pariuri unde utilizatorii pot gestiona competitii,
//meciuri si pot simula plasarea biletelor(de un singur meci sau mai multe).
//DATELE DE INTRARE:
//Numele competitiei si Tara/Continent(daca este o cupa intercontinentala)
//Echipele gazda si echipele oaspete(siruri de caractere)
//Cotele pentru cele trei rezultate posibile
//Miza pariului si optiunea aleasa de parior
//ID si obiectul pariu
#include <iostream>
#include <cstring>
#include <vector>
class Competitie  {
   private:
      char* Nume;
      char* Tara;

   public:


  // Constructor
    //Il folosim pentru a initializa numele si tara competitiei
      Competitie( const char* Nume, const char* Tara)
  {
      this->Nume = new char[strlen(Nume)+1];
      std::strcpy(this->Nume,Nume);

      this->Tara = new char[strlen(Tara)+1];
      std::strcpy(this->Tara,Tara);

          std::cout<<"Constructor Competitie"<<std::endl;
  }

    // Constructor de copiere
    //Il utilizam pentru a realiza o copie pentru fiecare sir de caracter in parte.
    Competitie(const Competitie& nou)
    {
        this->Nume = new char[strlen(nou.Nume) + 1];
        std::strcpy(Nume, nou.Nume);

        this->Tara = new char[strlen(nou.Tara) + 1];
        std::strcpy(Tara, nou.Tara);

    }


    //Getter
    //Il utilizam pentru a permite accesul la valorile campului Nume
    char* getNume() const
    {
        char *numeReturnat = new char[strlen(Nume) + 1];
        std::strcpy(numeReturnat, Nume);
        return numeReturnat;
    }

    //Setter
    //Il utilizam pentru a putea modifica valoarea campului Nume prin
    //eliberearea spatiului vechi si alocarea unui spatiu nou pentru acualizarea tarii
    void setNume(const char* Nume)
    {
        delete[] this->Nume;
        this->Nume = new char[strlen(Nume) + 1];
        std::strcpy(this->Nume, Nume);
    }

    //Getter
    //Il utilizam pentru a permite accesul la valorile campului Tara
    char* getTara() const
    {
        char *taraReturnat = new char[strlen(Tara) + 1];
        std::strcpy(taraReturnat, Tara);
        return taraReturnat;
    }

    //Setter
    //Il utilizam pentru a putea modifica valoarea campului Tara prin
    //eliberearea spatiului vechi si alocarea unui spatiu nou pentru acualizarea tarii
    void setTara(const char* Tara)
    {
        delete[] this->Tara;
        this->Tara = new char[strlen(Tara) + 1];
        std::strcpy(this->Tara, Tara);
    }

   //Operatorul de atribuire
    //Gestioneaza copierea corecta a datelor intre obiectele existente
    Competitie& operator=(const Competitie& sursa)
    {
        if(this != &sursa)
        {
            delete[] Nume;
            delete[] Tara;

            Nume=new char[strlen(sursa.Nume)+1];
            strcpy(Nume,sursa.Nume);

            Tara=new char[strlen(sursa.Tara)+1];
            strcpy(Tara,sursa.Tara);
        }
        return *this;
    }

    //Afiseaza competitia si tara intr-un mod mai lizibil
    friend std::ostream& operator<<(std::ostream& os, const Competitie& c) {
     os <<"COMPETITIE: " <<c.Nume<< " (TARA: "<<c.Tara <<")";
     return os;
    }

   //Destructor
    //Elibereaza memoria ocupata de pointerii Nume si Tara
  ~Competitie()
    {
        std::cout << "~Competitie() " << Nume <<" "<< Tara <<std::endl;
        delete[] Nume;
        delete[] Tara;
    }

};




class Meciuri{
  private:
      char* EchipaGazda;
      char* EchipaOaspete;
      double cota1;
      double cotax;
      double cota2;


  public:

    //Constructor
    //Utilizat pentru initializarea echipelor si a celor trei cote pe care le putem alege
      Meciuri(const char* EchipaGazda, const char* EchipaOaspete, double cota1, double cotax, double cota2)
      {
          std::cout <<"Constructor Meciuri"<<" "<<std::endl;


          this->EchipaGazda = new char[strlen(EchipaGazda)+1];
          std::strcpy(this->EchipaGazda,EchipaGazda);

          this->EchipaOaspete = new char[strlen(EchipaOaspete)+1];
          std::strcpy(this->EchipaOaspete,EchipaOaspete);


          this->cota1=cota1;
          this->cotax=cotax;
          this->cota2=cota2;


      }


      //Constructor de copiere
    //Il utilizam pentru a copia datele unui meci intr-un obiect nou
      Meciuri(const Meciuri &nou)
      {
          this->EchipaGazda=new char[strlen(nou.EchipaGazda)+1];
          strcpy(this->EchipaGazda,nou.EchipaGazda);

          this->EchipaOaspete=new char[strlen(nou.EchipaOaspete)+1];
          strcpy(this->EchipaOaspete,nou.EchipaOaspete);

          this->cota1=nou.cota1;
          this->cotax=nou.cotax;
          this->cota2=nou.cota2;

      }


      //Getter
    //Toti getteri ofera acces la datele meciului
      char* getEchipaGazda() const
      {
        char *EGReturnat = new char[strlen(EchipaGazda) + 1];
        std::strcpy(EGReturnat, EchipaGazda);
        return EGReturnat;
      }

      //Getter
      char* getEchipaOaspete() const
      {
        char *EOReturnat = new char[strlen(EchipaOaspete) + 1];
        std::strcpy(EOReturnat, EchipaOaspete);
        return EOReturnat;
      }

      //Getteri
      double getCota1() const {return this->cota1;}
      double getCotax() const {return this->cotax;}
      double getCota2() const {return this->cota2;}


    //Operatorul de atribuire
    //Permite reatribuirea datelor unui meci
      Meciuri& operator=(const Meciuri& sursa)
    {
        if(this != &sursa)
        {
            delete[] EchipaGazda;
            delete[] EchipaOaspete;

            EchipaGazda=new char[strlen(sursa.EchipaGazda)+1];
            strcpy(EchipaGazda,sursa.EchipaGazda);

            EchipaOaspete=new char[strlen(sursa.EchipaOaspete)+1];
            strcpy(EchipaOaspete,sursa.EchipaOaspete);

            cota1=sursa.cota1;
            cotax=sursa.cotax;
            cota2=sursa.cota2;
        }
        return *this;
    }

    //Calculeaza cota totala a unui bilet in care sunt plasate mai multe meciuri prin inmultirea cotelor
    //selectate
    static double calcMeciuriMultiple(Meciuri* meciuri, int nrMeciuri,int* optiuni)
    {
        if(nrMeciuri<0) return 0;

        double cotaFinala=1.00;

        for(int i=0; i<nrMeciuri; i++)
            if(optiuni[i]==1)
        {
            cotaFinala *=meciuri[i].getCota1();
        }
        else
            if(optiuni[i]==2)
        {
            cotaFinala *=meciuri[i].getCotax();
        }
        else
            if(optiuni[i]==3)
        {
            cotaFinala *=meciuri[i].getCota2();
        }
        else
            {
            std::cout<<"Optiune invalida"<<std::endl;
        }

        return cotaFinala;
    }

    //O functie care actualizeaza toate cotele unui meci
    void ActualizeazaCote(double multiplicator){

      if(multiplicator>0)
      {
          this->cota1 *=multiplicator;
          this->cotax *=multiplicator;
          this->cota2 *=multiplicator;
          std::cout<<"Cote actualizate"<<std::endl;

      }


    }

      //Afiseaza echipele si cotele intr-un mod mai lizibil
      friend std::ostream& operator<<(std::ostream& os, const Meciuri& m)
      {
          os << m.EchipaGazda<<" vs "<<m.EchipaOaspete<<" [Cote: "<<m.cota1<<" | "<<m.cotax<<" | "<<m.cota2<<"]";
          return os;
      }



      //Destructor
    //Curata memoria alocata pentru cele 2 echipe
     ~Meciuri()
      {
        std::cout << "Destructor ~Meciuri() " << EchipaGazda <<" "<< EchipaOaspete <<std::endl;
        delete[] EchipaGazda;
        delete[] EchipaOaspete;
      }

};



class Pariuri{
 private:
    double miza;
    int optiune;
    const Meciuri* meciPariat;

    double valideazaMiza(double m) {
        if (m<0) return 1.0;
        return m;

    }

 public:


    Pariuri(){}
    //Constructor
    //Leaga o miza si o optiune de pariu de un meci existent
    Pariuri(const double miza, const int optiune, const Meciuri* meciPariat)
    {
        std::cout<<"Constructor Pariuri"<<std::endl;

          this->miza=valideazaMiza(miza);

          this->optiune=optiune;

          this->meciPariat=meciPariat;

    }

    //Constructor de copiere
    //Copiam miza si referinta catre meciul pariat
      Pariuri(const Pariuri &nou)
      {
          this->miza=nou.miza;

          this->optiune=nou.optiune;

          this->meciPariat=nou.meciPariat;

      }

    //Inmulteste miza cu cota corespunzatoare optiunii alese
      double calculCastig()
      {
          if(optiune==1)
            return miza * meciPariat->getCota1();

          if(optiune==2)
            return miza * meciPariat->getCotax();

          if(optiune==3)
            return miza * meciPariat->getCota2();

            return 0;
      }

    //Inmulteste miza cu cota corespunzatoare optiunii alese adaugand un bonus procentual suplimentar
      double calculCastig(double procentBonus)
      {
          double castigNormal=this->calculCastig();
          return castigNormal+(castigNormal*procentBonus/100);

      }

      //Afisam detaliile pariului
      friend std::ostream& operator<<(std::ostream& os, const Pariuri& p)
      {
          os<<"Pariu pe meciul: "<<*(p.meciPariat) <<" | Miza: "<<p.miza<<" RON ";
          return os;
      }

      //Destructor
    //Afisam distrugerea obiectului
     ~Pariuri()
      {
        std::cout << "~Pariuri() "<<std::endl;
      }

};

class Bilet {

    int idBilet;
    std::vector<Pariuri> pariuri;

public:

    //Constructor
    Bilet( int idBilet)
    {
        this->idBilet = idBilet;

        std::cout<<"Constructor idBilet"<<std::endl;
    }

    //Functie pentru a adauga un pariu pe bilet
    void adaugaPariu(const Pariuri& p) {
        pariuri.push_back(p);
    }

    //Functie pentru a calcula castigul total al biletului
    double CalculCastigTotal()
    {
    double total=0.0;
        for (int i=0;i < pariuri.size();i++) {
            total+=pariuri[i].calculCastig();
        }
        return total;

    }

    //Supraincarcarea operatorului +=
    Bilet& operator+=(const Pariuri& p) {
        this->pariuri.push_back(p);
        return *this;
    }
    // Operator << care apeleaza operatorul << al clasei Pariuri
    friend std::ostream& operator<<(std::ostream& os, const Bilet& b) {
        os << "Bilet ID: " << b.idBilet<<std::endl;
        for (int i=0; i<b.pariuri.size();i++) {
            const Pariuri& p=b.pariuri[i];
            os << "-"<<p<<" "<<std::endl;
        }

        return os;
    }

    //Destructor
    ~Bilet() {
        std::cout << "~Bilet() distrus" << std::endl;
    }
};


int main()
{

   Competitie comp1("Champions League","Europa");

   Meciuri bilet[3]={
      Meciuri{"Real Madrid","Manchester City",2.10,2.22,2.00},
      Meciuri{"PSG","FC Barcelona",2.00,2.30,3.00},
      Meciuri{"FCSB","Dinamo Bucuresti",1.50,3.00,2.50}
      };

    std::cout<<comp1<<std::endl;


    int alegeri[3]={1,2,3};

    double cotaBilet= Meciuri::calcMeciuriMultiple(bilet,3,alegeri);
    double SumaBiletMultiplu=25.00;

    std::cout<<"Cota bilet acumulator: "<<cotaBilet<<std::endl;
    std::cout<<"Castig potential bilet acumulat: "<<SumaBiletMultiplu*cotaBilet<<std::endl;


    Bilet b1(10);
    Pariuri p1(25, 1, &bilet[0]);
    Pariuri p2(30, 2, &bilet[1]);
    Pariuri p3(40, 3, &bilet[2]);
    b1+=p1;
    b1+=p2;
    b1+=p3;
    std::cout<<b1<<std::endl;
    std::cout<<"Calcul castig potential bilet1:"<<b1.CalculCastigTotal()<<" "<<" RON "<<std::endl;


    Bilet b2(12);
    Pariuri p4(10, 3, &bilet[0]);
    Pariuri p5(15, 1, &bilet[1]);
    b2+=p4;
    b2+=p5;
    std::cout<<b2<<std::endl;
    std::cout<<"Calcul castig potential bilet2:"<<b2.CalculCastigTotal()<<" "<<" RON "<<std::endl;

    Bilet b3=b2;
    std::cout<<"b3: "<<b3<<"  "<<"Calcul castig b3: "<<b3.CalculCastigTotal()<<" "<<" RON "<<std::endl;
    bilet[0].ActualizeazaCote(2.1);
    std::cout<<"Calcul castig b3: "<<b3.CalculCastigTotal()<<" "<<" RON "<<std::endl;



    std::cout<<"Detalii bilet: "<<std::endl;
    std::cout<<b1<<std::endl;
    std::cout<<p1<<" | Castig standard: "<<p1.calculCastig()<<" RON"<<std::endl;
    std::cout<<p1<<" | Castig bonus: "<<p1.calculCastig(15.0)<<" RON"<<std::endl;

    bilet[0].ActualizeazaCote(1.1);
    std::cout<<"Cota actualizata: "<<bilet[0]<<std::endl;

    Competitie comp2 = comp1;
    comp2.setNume("Europa League");
    std::cout << "Comp2 modificata: " << comp2 << std::endl;

    return 0;
}