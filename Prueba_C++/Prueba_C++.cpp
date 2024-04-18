#include "tinyxml2.h"
#include "Data.h"
#include <iostream>
#include "Serializer.h"

using namespace tinyxml2;

//converts XML data to normal text

int main()
{
    const char* xmlPath = "ejemplo.xml";
    const char* xml2Path = "serialized.xml";
    
    Serializer serializer;
    serializer.deSerializeData(xmlPath);

    Serializer serializer2;
    serializer2.serializeData(xml2Path, "carbonara", "5", { "comino", "nata", "bacon" });

    return 0;
}


    