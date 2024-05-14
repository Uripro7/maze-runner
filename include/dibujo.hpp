#include <ftxui/dom/elements.hpp>
#include <fstream>
#include <string>

using namespace std;
using namespace ftxui;

class dibujo
{
private:
    ifstream archivo;
    Element contenido;

public:
    dibujo(string path)
    {

        archivo.open(path);

        Elements elementos;
        string linea;

        while (getline(archivo, linea))
        {
            elementos.emplace_back(text(linea));
        }
        contenido = vbox(elementos);
        archivo.close();
    }
    Element GetElement(){
        return this->contenido;
    }
    ~dibujo() {}
};