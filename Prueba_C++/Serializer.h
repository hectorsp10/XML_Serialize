#include "tinyxml2.h"
#include "Data.h"
#include <iostream>
#include <list>
#include <string>

using namespace std;
using namespace tinyxml2;

#pragma once
class Serializer
{
public:

    void deSerializeData(const char* xmlPath) {
        XMLDocument doc;
        if (doc.LoadFile(xmlPath) == XML_SUCCESS) {
            XMLElement* raiz = doc.RootElement();
            cout << "success\n";
            if (raiz) {
                for (XMLElement* pizza = raiz->FirstChildElement("pizza"); pizza; pizza = pizza->NextSiblingElement("pizza")) {

                    const char* nombrePizza = pizza->Attribute("nombre");
                    const char* precioPizza = pizza->Attribute("precio");

                    if (nombrePizza && precioPizza) {
                        cout << "Pizza: " << nombrePizza << ", Precio: " << precioPizza << endl;

                        for (XMLElement* ingrediente = pizza->FirstChildElement("ingrediente"); ingrediente; ingrediente = ingrediente->NextSiblingElement("ingrediente")) {

                            const char* nombreIngrediente = ingrediente->Attribute("nombre");

                            if (nombreIngrediente) {
                                cout << "Ingrediente: " << nombreIngrediente << endl;
                            }
                            else {
                                cout << "Ingrediente no encontrado" << endl;
                            }
                        }
                    }
                    else {
                        cout << "Pizza no encontrada" << endl;
                    }
                }
            }
        }
    }
   
    void serializeData(const char* xmlPath, const char* name, const char* price, list<const char*> ingredients) {
        
        XMLDocument xml;
        
        XMLNode* raiz = xml.NewElement("Pizzas");
        xml.InsertFirstChild(raiz);

        XMLElement* pizza = xml.NewElement("Pizza");
        raiz->InsertEndChild(pizza);
       
        pizza->SetAttribute("Name", name);        
        pizza->SetAttribute("Price", price);

        for (const char* ingredient : ingredients) {
            XMLElement* ingred = xml.NewElement("Ingredient");
            pizza->InsertEndChild(ingred);
            
            ingred->SetAttribute("name", ingredient);
        }

        Data data;
        data.addPizza("carbonara", "5", { "comino", "nata", "bacon" });
        data.showData();
      
        xml.SaveFile(xmlPath);
        std::cout << "\nXML correctly saved at: " << xmlPath << std::endl;
        
    }

};

