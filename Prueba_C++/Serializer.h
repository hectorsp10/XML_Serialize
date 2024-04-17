#include "tinyxml2.h"
#include <iostream>

using namespace tinyxml2;

#pragma once
class Serializer
{
public:

    void deSerializeData(const char* xmlPath) {
        XMLDocument doc;
        if (doc.LoadFile(xmlPath) == XML_SUCCESS) {
            XMLElement* raiz = doc.RootElement();
            std::cout << "success\n";
            if (raiz) {
                for (XMLElement* pizza = raiz->FirstChildElement("pizza"); pizza; pizza = pizza->NextSiblingElement("pizza")) {

                    const char* nombrePizza = pizza->Attribute("nombre");
                    const char* precioPizza = pizza->Attribute("precio");

                    if (nombrePizza && precioPizza) {
                        std::cout << "Pizza: " << nombrePizza << ", Precio: " << precioPizza << std::endl;

                        for (XMLElement* ingrediente = pizza->FirstChildElement("ingrediente"); ingrediente; ingrediente = ingrediente->NextSiblingElement("ingrediente")) {

                            const char* nombreIngrediente = ingrediente->Attribute("nombre");

                            if (nombreIngrediente) {
                                std::cout << "Ingrediente: " << nombreIngrediente << std::endl;
                            }
                            else {
                                std::cout << "Ingrediente no encontrado" << std::endl;
                            }
                        }
                    }
                    else {
                        std::cout << "Pizza no encontrada" << std::endl;
                    }
                }
            }
        }
    }

    void serializeData(const char* xmlPath, const char* root, const char* element) {
        
        XMLDocument xml;
        if (root){
            XMLNode* raiz = xml.NewElement(root);
            xml.InsertFirstChild(raiz);

            if (element) {
                XMLElement* elem = xml.NewElement(element);
                raiz->InsertEndChild(elem);
            }

        }
        
        xml.SaveFile(xmlPath);
        std::cout << "XML guardado con exito" << std::endl;
        
    }

};

