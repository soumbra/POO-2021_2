#include "fone.hpp"
#include "contact.hpp"
#include "agenda.hpp"
//#include <sstream>

int main() 
{
    Agenda agenda;

    Contact Raimundao{"Raimundao"};
    Contact Larouci{"Larouci"};
    Contact Arouca{"Arouca"};

    Raimundao.addFone(Fone {"oi", "888"});
    Raimundao.addFone(Fone {"tchau", "8a12"});
    Raimundao.addFone(Fone {"tchau", "6654"});
    Larouci.addFone(Fone {"tim", "788"});
    Arouca.addFone(Fone {"vivis", "246"});

    agenda.addContact(Raimundao);
    agenda.addContact(Larouci);
    agenda.addContact(Arouca);

    cout << agenda << '\n';

    //Removendo um numero do contato
    agenda.rmContact("Raimundao", 1);
    //Removendo o contato por completo
    agenda.rmContact("Raimundao");

    //procurando por palavras chaves
    agenda.search("88");
    agenda.search("ro");
    
    //Ordenando os contatos
    agenda.ordenarContatos();
    cout << agenda << '\n';

}