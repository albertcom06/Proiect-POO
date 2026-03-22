#include <iostream>
#include <cstring>
class Competitie  {
   private:
      char* Nume;
      char* Tara;

   public:


  // Constructor
  Competitie( const char* Nume, const char* Tara)
  {
      this->Nume = new char[strlen(Nume)+1];
      std::strcpy(this->Nume,Nume);

      this->Tara = new char[strlen(Tara)+1];
      std::strcpy(this->Tara,Tara);
  }

    // Constructor de copiere
    Competitie(const Competitie& nou)
    {
        this->Nume = new char[strlen(nou.Nume) + 1];
        std::strcpy(Nume, nou.Nume);

        this->Tara = new char[strlen(nou.Tara) + 1];
        std::strcpy(Tara, nou.Tara);

    }


    //Getter
    char* getNume() const
    {
        char *numeReturnat = new char[strlen(Nume) + 1];
        std::strcpy(numeReturnat, Nume);
        return numeReturnat;
    }

    //Setter
    void setNume(const char* Nume)
    {
        delete[] this->Nume;
        this->Nume = new char[strlen(Nume) + 1];
        std::strcpy(this->Nume, Nume);
    }

    //Getter
    char* getTara() const
    {
        char *taraReturnat = new char[strlen(Tara) + 1];
        std::strcpy(taraReturnat, Tara);
        return taraReturnat;
    }

    //Setter
    void setTara(const char* Tara)
    {
        delete[] this->Tara;
        this->Tara = new char[strlen(Tara) + 1];
        std::strcpy(this->Tara, Tara);
    }


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


    friend std::ostream& operator<<(std::ostream& os, const Competitie& c) {
     os <<"COMPETITIE: " <<c.Nume<< " (TARA: "<<c.Tara <<")";
     return os;
    }

   //Destructor
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

      double getCota1() const {return this->cota1;}
      double getCotax() const {return this->cotax;}
      double getCota2() const {return this->cota2;}



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


    void ActualizeazaCote(double multiplicator){

      if(multiplicator>0)
      {
          this->cota1 *=multiplicator;
          this->cotax *=multiplicator;
          this->cota2 *=multiplicator;
          std::cout<<"Cote actualizate"<<std::endl;

      }


    }


      friend std::ostream& operator<<(std::ostream& os, const Meciuri& m)
      {
          os << m.EchipaGazda<<" vs "<<m.EchipaOaspete<<" [Cote: "<<m.cota1<<" | "<<m.cotax<<" | "<<m.cota2<<"]";
          return os;
      }



      //Destructor
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

 public:

    Pariuri(const double miza, const int optiune, const Meciuri* meciPariat)
    {
        std::cout<<"Constructor Pariuri"<<std::endl;

          this->miza=miza;

          this->optiune=optiune;

          this->meciPariat=meciPariat;

    }

    //Constructor de copiere
      Pariuri(const Pariuri &nou)
      {
          this->miza=nou.miza;

          this->optiune=nou.optiune;

          this->meciPariat=nou.meciPariat;

      }

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

      double calculCastig(double procentBonus)
      {
          double castigNormal=this->calculCastig();
          return castigNormal+(castigNormal*procentBonus/100);

      }


      friend std::ostream& operator<<(std::ostream& os, const Pariuri& p)
      {
          os<<"Pariu pe meciul: "<<*(p.meciPariat) <<" | Miza: "<<p.miza<<" RON ";
          return os;
      }

      //Destructor
     ~Pariuri()
      {
        std::cout << "~Pariuri() "<<std::endl;
      }

};




int main()
{

   Competitie comp1("Champions League","Europa");
   std::cout<<comp1<<std::endl;

   Meciuri bilet[3]={
      Meciuri{"Real Madrid","Manchester City",2.10,2.22,2.00},
      Meciuri{"PSG","FC Barcelona",2.00,2.30,3.00},
      Meciuri{"FCSB","Dinamo Bucuresti",1.50,3.00,2.50}
      };

    int alegeri[3]={1,2,3};

    double cotaBilet= Meciuri::calcMeciuriMultiple(bilet,3,alegeri);
    std::cout<<"Cota bilet acumulator: "<<cotaBilet<<std::endl;

    double SumaBiletMultiplu=25.00;

    std::cout<<"Castig potential bilet acumulat: "<<SumaBiletMultiplu*cotaBilet<<std::endl;

    Pariuri p1(100.0, 1, &bilet[0]);
    std::cout<<p1<<" | Castig standard: "<<p1.calculCastig()<<" lei"<<std::endl;
    std::cout<<p1<<" | Castig bonus: "<<p1.calculCastig(15.0)<<" lei"<<std::endl;

    bilet[0].ActualizeazaCote(1.1);
    std::cout<<"Cota actualizata: "<<bilet[0]<<std::endl;

    return 0;
}