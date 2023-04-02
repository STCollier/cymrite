#include "entity.h"

struct Entity init() {
    struct Entity self;
    
    self.ID = &self.ID;

    return self;
}