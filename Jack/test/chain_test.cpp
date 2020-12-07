#include "../main.h"
#include "doctest.h"

TEST_CASE("chain test"){
   
    Chain_Base *blue = new Chain<Blue>();
    
    CHECK(blue->getName() == "Blue");
    CHECK(blue->getLength() == 0);
    
    blue -> operator+=(new Blue());
    blue -> operator+=(new Blue());
    blue -> operator+=(new Blue());
    
    CHECK(blue->getLength() == 3);
    CHECK(blue->sell() == 8);
   
    
    

}

