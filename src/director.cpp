#include "director.h"

Director &Director::getInstance() {
    static Director director;

    return director;
}

Director::Director()
{

}
