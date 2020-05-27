#include <iostream>
#include "symbolTable.h"
#include <string>

using namespace std;

int main()
{
    SymbolTable st;
    string check;
    cout << "**** SYMBOL_TABLE ****\n";

    // insert 'if'
    if (st.insert("if", "local", "keyword", 4))
        cout << " -successfully";
    else
        cout << "\nFailed to insert.\n";

    // insert 'number'
    if (st.insert("number", "global", "variable", 2))
        cout << " -successfully\n\n";
    else
        cout << "\nFailed to insert\n";

    // find 'if'
    check = st.find("if");
    if (check != "-1")
        cout << "Identifier Is present\n";
    else
        cout << "\nIdentifier Not Present\n";

    // delete 'if'
    if (st.deleteRecord("if"))
        cout << "if Identifier is deleted\n";
    else
        cout << "\nFailed to delete\n";

    // modify 'number'
    if (st.modify("number", "global", "variable", 3))
        cout << "\nNumber Identifier updated\n";

    // find and print 'number'
    check = st.find("number");
    if (check != "-1")
        cout << "Identifier Is present\n";
    else
        cout << "\nIdentifier Not Present";

    return 0;
}
