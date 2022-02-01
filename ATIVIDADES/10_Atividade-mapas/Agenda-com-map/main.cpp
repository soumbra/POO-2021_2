#include "fone.hpp"
#include "contact.hpp"
#include "agenda.hpp"

int main() 
{
    Agenda agenda;

    Contact Raimundao{"Raimundao"};
    Contact Larouci{"Larouci"};
    Contact Arouca{"Arouca"};
    Contact Arouca2{"Arouca"};
    Contact xablau{"Xablau"};

    Raimundao.addFone(Fone {"oi", "888"});
    Raimundao.addFone(Fone {"tchau", "8a12"});
    Raimundao.addFone(Fone {"tchau", "6654"});
    Larouci.addFone(Fone {"tim", "788"});
    Arouca.addFone(Fone {"vivis", "246"});
    Arouca2.addFone(Fone {"vivo", "54"});
    xablau.addFone(Fone {"toma", "34"});

    agenda.addContact(Raimundao);
    cout << agenda << '\n';
    agenda.addContact(Larouci);
    cout << agenda << '\n';

    agenda.addContact(Arouca);
    agenda.addContact(xablau);
    agenda.addContact(Arouca2);

    cout << agenda << '\n';

    agenda.rmContact("Raimundao");
    agenda.rmFone("Arouca", 1);

    cout << agenda << '\n';
    agenda.search("i");
}