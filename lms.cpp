#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Livre{

private:
    string titre, auteur;
    int ISBN;
    bool status_emprunt;

public:

    Livre(string t =" ", string a="", int i=0, bool s= false){
        titre= t;
        auteur = a;
        ISBN = i;
        status_emprunt = s;
    }

    Livre(const Livre& a){

        titre = a.titre;
        auteur = a.auteur;
        ISBN = a.ISBN;
        status_emprunt = a.status_emprunt;


    }

    string getTitre(){
        return titre;
    }

    string getAuteur(){
        return auteur;
    }

    int getISBN(){
        return ISBN;
    }

    bool getEmprunt(){
        return status_emprunt;
    }

    void setTitre(string s){ titre = s;}
    void setAuteur(string a){ auteur = a;}
    void setISBN(int i){ISBN = i;}
    void setEmprunt(bool i){ status_emprunt = i;}


    void AfficherLivre(){
        cout<<"Titre: "<<titre<<endl;
        cout<<"Auteur: "<<auteur<<endl;
        cout<<"ISBN: "<<ISBN<<endl;
        cout<<"Status: "<<status_emprunt<<endl;
    }

    bool verifierLivre(){
        return getEmprunt();
    }

    Livre EmprunterParUtilisateur(Livre a){
        a.setEmprunt(true);
        return a;
    }

    void RetournerParUtilisateur(Livre a){
        a.setEmprunt(false);

    }



};



class Utilisateur{
private:
    string nom, prenom;
    int ID;
    vector <Livre> listeLivres;

public:
    Utilisateur(string n=" ", string p=" ", int i=0){
        nom = n;
        prenom = p;
        ID = i;
    }

    string getNom(){
        return nom;
    }

    string getPrenom(){
        return prenom;
    }

    int getID(){
        return ID;
    }

    void getListeLivres(){
        Livre a;

        if(listeLivres.size() == 0){

            cout <<" La liste est vide"<<endl;
            return;
        }

        else{

                for(int i = 0; i < listeLivres.size() ; i++){
                    a = listeLivres[i];
                    a.AfficherLivre();
                }

        }

    }

    void afficherUtilisateur(){
        cout<<"Nom: "<<nom<<endl;
        cout<<"Prenom: "<<prenom<<endl;
        cout<<"ID: "<<ID<<endl;
    }

    void emprunterLivre(Livre a){

        a = a.EmprunterParUtilisateur(a);
        listeLivres.push_back(a);

        cout<<"Livre ajoute"<<endl;
    }

    void rendreLivre(Livre a){
        int c = 0;
        a.RetournerParUtilisateur(a);


        for(int i = 0; i < listeLivres.size(); i++){
            Livre b = listeLivres[i];
            if(b.getISBN() == a.getISBN() && b.getTitre() == a.getTitre()){

                listeLivres.erase((listeLivres.begin()+i));

                c++;

            }
        }


        if(c == 1)
            cout<<"Livre rendu"<<endl;
        else
            cout << "Erreur"<<endl;
    }

};


class Bibliotheque{
private:
    string nom;
    vector <Utilisateur> usersInscrit;
    vector <Livre> livresDispo;

public:
    Bibliotheque(string n=""){
        nom = n;
    }

    void AfficherLivresDispo(){
        Livre a;
        for(int i = 0; i < livresDispo.size(); i++){
            a = livresDispo[i];
            a.AfficherLivre();
        }
    }



    void AfficherUsers(){
        Utilisateur a;
        for(int i = 0; i < usersInscrit.size(); i++){
            a = usersInscrit[i];
            a.afficherUtilisateur();
        }
    }

    void ajouterLivreBiblio(Livre a){
        livresDispo.push_back(a);
        cout<<"Le livre bien ajouté"<<endl;
    }

    void inscritUser(Utilisateur a){
        usersInscrit.push_back(a);
        cout<<"L'utilisateur bien ajouté"<<endl;
    }

    string getNom(){
        return nom;
    }

};


int main(){
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<" Ce TP fait par Marouane El Hizabri"<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;

    Livre l1("Al Quds", "Bla", 11111, 0);
    Livre l2("The Prince of Mathematics", "Gauss", 2222, 0);

    Utilisateur u1 ("Marouane", "Elhizabri", 1);
    Utilisateur u2 ("Mar", "blalal", 2);

    cout<<"Livre 1"<<endl;

    l1.AfficherLivre();

    cout<<"=============================="<<endl;

    cout<<"Livre 2"<<endl;

    l2.AfficherLivre();

    cout<<"=============================="<<endl;
    cout<<"=============================="<<endl;

    cout<<"User 1"<<endl;

    u1.afficherUtilisateur();

    cout<<"=============================="<<endl;

    cout<<"User 2"<<endl;

    u2.afficherUtilisateur();

    cout<<"=============================="<<endl;

    Bibliotheque b1("Palestine Library");

    cout<< "Bibliotheque: "<<b1.getNom()<<endl;

    cout<<"=============================="<<endl;

    cout<<"Ajout des livres a la bibliotheque "<<endl;
    b1.ajouterLivreBiblio(l1);
    b1.ajouterLivreBiblio(l2);
    cout<<"=============================="<<endl;
    cout<<"=============================="<<endl;
    cout<<"Ajout des users a la bibliotheque "<<endl;
    b1.inscritUser(u1);
    b1.inscritUser(u2);
    cout<<"=============================="<<endl;
    cout<<"=============================="<<endl;

    u1.emprunterLivre(l2);
    cout<<"Apres l'emprunt de livre 2 par User 1: La liste est: "<<endl;
    u1.getListeLivres();
    cout<<"=============================="<<endl;

    cout<<"=============================="<<endl;
    cout<<"Apres la retour de livre par User 1: La liste est: "<<endl;

    u1.rendreLivre(l2);

    u1.getListeLivres();



    return 0;


}

