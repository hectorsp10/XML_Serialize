#include "tinyxml2.h"
#include <iostream>
#include "Serializer.h"

using namespace tinyxml2;

class datos {

};


//converts XML data to normal text

int main()
{
    const char* xmlPath = "ejemplo.xml";
    const char* xml2Path = "serialized.xml";
    
    Serializer serializer;
    serializer.deSerializeData(xmlPath);

    Serializer serializer2;
    serializer2.serializeData(xml2Path, "coche", "rueda");

    return 0;
}


